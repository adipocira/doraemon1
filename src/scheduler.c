#include "scheduler.h"
#include "thread.h"
#include "common.h"
#include "controller.h"
#include "3A30.h"
#include "147B0.h"
#include "14B00.h"
#include "zzDebug.h"
#include "zzTeller.h"
#include "TexRec.h"
#include "global.h"

extern u16 D_8015A392;

extern u32 D_800F0514;
extern u32 D_800F0518;

extern u8 D_800EEFB0[];

extern char D_800A82F0[];

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

#define OS_SC_DP                0x0001  /* set if still needs dp        */
#define OS_SC_SP                0x0002  /* set if still needs sp        */
#define OS_SC_YIELD             0x0010  /* set if yield requested       */
#define OS_SC_YIELDED           0x0020  /* set if yield completed       */

#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)

static int dp_busy = 0;
static int dpCount = 0;
    

void createScheduler(InternalScheduler* sched, void* stack, OSPri priority, u8 mode, u8 numFields) {
    sched->sc.curRSPTask = 0;
    sched->sc.curRDPTask = 0;
    sched->sc.clientList = 0;
    sched->sc.frameCount = 0;
    sched->sc.audioListHead = 0;
    sched->sc.gfxListHead = 0;
    sched->sc.audioListTail = 0;
    sched->sc.gfxListTail = 0;
    sched->sc.retraceMsg.type = OS_SC_RETRACE_MSG;
    sched->sc.prenmiMsg.type = 5;

    osCreateMesgQueue(&sched->sc.interruptQ, sched->sc.intBuf, OS_SC_MAX_MESGS);
    osCreateMesgQueue(&sched->sc.cmdQ, sched->sc.cmdMsgBuf, OS_SC_MAX_MESGS);

    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[mode]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &sched->sc.interruptQ, (OSMesg)RSP_DONE_MSG);
    osSetEventMesg(OS_EVENT_DP, &sched->sc.interruptQ, (OSMesg)RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &sched->sc.interruptQ, (OSMesg)PRE_NMI_MSG);

    osViSetEvent(&sched->sc.interruptQ, (OSMesg)VIDEO_MSG, numFields);

    sched->sc.unk284 = 0;
    sched->unk290 = 0;
    sched->unk298 = 0;

    osCreateThread(&sched->sc.thread, THREAD_ID_SCHED, __scMain, (void*)sched, stack, priority);
    osStartThread(&sched->sc.thread);
}

void osScAddClient(InternalScheduler* sched, OSScClient* c, OSMesgQueue* msgQ) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    c->msgQ = msgQ;
    c->next = sched->sc.clientList;
    sched->sc.clientList = c;

    osSetIntMask(mask);
}

void osScRemoveClient(InternalScheduler* sched, OSScClient* c) {
    OSScClient* client = sched->sc.clientList;
    OSScClient* prev = 0;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    while (client != 0) {
        if (client == c) {
            if (prev)
                prev->next = c->next;
            else
                sched->sc.clientList = c->next;
            break;
        }
        prev = client;
        client = client->next;
    }

    osSetIntMask(mask);
}

OSMesgQueue* osScGetCmdQ(InternalScheduler* sched) {
    return &sched->sc.cmdQ;
}

void __scMain(void* arg) {
    OSMesg msg;
    InternalScheduler* sched = (InternalScheduler*)arg;
    OSScClient* client;
    u32 fb;

    while (TRUE) {
        osRecvMesg(&sched->sc.interruptQ, (OSMesg*)&msg, OS_MESG_BLOCK);

        switch ((int)msg) {
            case (VIDEO_MSG):
                sched->unk298 = osGetTime() - sched->unk290;
                sched->unk290 = osGetTime();
                sched->sc.unk284++;
                
                ((&D_800E69C0))->unk10 = sched->sc.unk284;
                func_80013BB0(D_800E6A20, 16);
                fb = osViGetCurrentFramebuffer();

                if (fb != 0) {
                    func_80012B80(&D_800E6B20, fb);
                }
                func_80013FE4(&D_800F5FB0);
                __scHandleRetrace(sched);
                break;

            case (RSP_DONE_MSG):
                __scHandleRSP(sched);
                break;

            case (RDP_DONE_MSG):
                __scHandleRDP(sched);
                break;

            case (PRE_NMI_MSG):
                for (client = sched->sc.clientList; client != 0; client = client->next) {
                    osSendMesg(client->msgQ, (OSMesg)&sched->sc.prenmiMsg, OS_MESG_NOBLOCK);
                }
                break;
        }
    }
}

void __scHandleRetrace(InternalScheduler* sched) {
    OSScTask* rspTask;
    OSScClient* client;
    s32 i;
    s32 state;
    OSScTask* sp = 0;
    OSScTask* dp = 0;

    sched->sc.frameCount++;

    while (osRecvMesg(&sched->sc.cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) != -1) {
        __scAppendList(sched, rspTask);
    }

    if (sched->sc.doAudio && sched->sc.curRSPTask) {
        __scYield(sched);
    } else {
        state = ((sched->sc.curRSPTask == 0) << 1) | (sched->sc.curRDPTask == 0);
        if (__scSchedule(sched, &sp, &dp, state) != state)
            __scExec(sched, sp, dp);
    }

    for (client = sched->sc.clientList; client != 0; client = client->next) {
        osSendMesg(client->msgQ, (OSMesg)&sched->sc.retraceMsg, OS_MESG_NOBLOCK);
    }
}

void __scHandleRSP(InternalScheduler* sched) {
    OSScTask* t;
    OSScTask* sp = 0;
    OSScTask* dp = 0;
    s32 state;

    t = sched->sc.curRSPTask;
    sched->sc.curRSPTask = 0;

    if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
        t->state |= OS_SC_YIELDED;

        if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
            t->next = sched->sc.gfxListHead;
            sched->sc.gfxListHead = t;
            if (sched->sc.gfxListTail == 0)
                sched->sc.gfxListTail = t;
        }

    } else {
        t->state &= ~OS_SC_NEEDS_RSP;
        __scTaskComplete(sched, t);
    }

    state = ((sched->sc.curRSPTask == 0) << 1) | (sched->sc.curRDPTask == 0);
    if ((__scSchedule(sched, &sp, &dp, state)) != state)
        __scExec(sched, sp, dp);
}

void __scHandleRDP(InternalScheduler* sched) {
    OSScTask* t;
    OSScTask* sp = 0;
    OSScTask* dp = 0;
    s32 state;

    t = sched->sc.curRDPTask;
    sched->sc.curRDPTask = 0;

    if (t->unk58 != sched->sc.unk284 != 0) {
        sched->unk288 = sched->sc.unk284 - t->unk58;
    } else {
        sched->unk288 = -(sched->sc.unk284 - t->unk58);
    } 

    t->state &= ~OS_SC_NEEDS_RDP;

    __scTaskComplete(sched, t);

    state = ((sched->sc.curRSPTask == 0) << 1) | (sched->sc.curRDPTask == 0);
    if ((__scSchedule(sched, &sp, &dp, state)) != state)
        __scExec(sched, sp, dp);
}

OSScTask* __scTaskReady(OSScTask* t) {
    int rv = 0;
    void* a;
    void* b;

    if (t) {
        if ((a = osViGetCurrentFramebuffer()) != (b = osViGetNextFramebuffer())) {
            return 0;
        }

        return t;
    }

    return 0;
}

s32 __scTaskComplete(InternalScheduler *sched, OSScTask *t){
    u16* fb;
    int rv;
    static int firsttime = 1;
    s32 i;
    char buf[40];
    s32 s2;

    if ((t->state & OS_SC_RCP_MASK) == 0) { /* none of the needs bits set */
        rv = osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);

	    if (t->list.t.type == M_GFXTASK) {
            // !@FAKE
            s2 = t->flags;
            
            if ((t->flags & OS_SC_SWAPBUFFER) && (s2 & OS_SC_LAST_TASK)){
	    	    if (firsttime) {
    		        osViBlack(FALSE);
		            firsttime = 0;
		        }
                
                if(D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_INFO)){
                    fb = t->framebuffer;
                    
                    sprintf(buf, "Version. %s", D_800A82F0);
                    func_80003364(fb, 0x10, 0xC, buf);

                    if(controllers[1]->unk0.buttonTimers[ZZ_TIMER_D_CBUTTON] != 0){
                         
                        sprintf(buf, "File Handle : %d", D_800EEFB0[0]);
                        func_80003364(fb, 0x10, 0x1C, buf);
                        
                        sprintf(buf, "Item : 0x%llx", cdata.item);
                        func_80003364(fb, 0x10, 0x1C, buf);

                        func_80003364(fb, 0x10, 0x24, "Event :");
                        
                        for(i = 0, s2 = 0x2C; i < 18; i++, s2 +=8){
                            sprintf(buf, "[%d] : 0x%x", i, cdata.events[i]);
                            func_80003364(fb, 0x20, s2, buf);
                            
                        }
                        
                    }
                    else if(controllers[1]->unk0.buttonTimers[ZZ_TIMER_R_CBUTTON] != 0){ 
                        sprintf(buf, "RAM SIZE : 0x%lx (%d)", D_800F0514, D_800F0514);
                        func_80003364(fb, 0x10, 0x1C, buf);
                        
                        sprintf(buf, "ROM SIZE : 0x%lx (%d)", D_800F0518, D_800F0518);
                        func_80003364(fb, 0x10, 0x24, buf);
                    }
                    else{
                        sprintf(buf, "TexRec num : %d", texRec.num);
                        func_80003364(fb, 0x10, 0x1C, buf);
                        
                        sprintf(buf, "CFB render : 0x%x", D_800E69C0.cfb_render);
                        func_80003364(fb, 0x10, 0x24, buf);
                        
                        sprintf(buf, "SYS CALL : 0x%x", D_800E69C0.syscalls);
                        func_80003364(fb, 0x10, 0x2C, buf);
                    }
                }
                
                osViSwapBuffer(t->framebuffer);
            }
	    }
        
        return 1;
    }
    
    return 0;    
}

void __scAppendList(InternalScheduler* sched, OSScTask* t) {
    long type = t->list.t.type;

    if (type == M_AUDTASK) {
        if (sched->sc.audioListTail)
            sched->sc.audioListTail->next = t;
        else
            sched->sc.audioListHead = t;

        sched->sc.audioListTail = t;
        sched->sc.doAudio = 1;
    } else {
        if (sched->sc.gfxListTail)
            sched->sc.gfxListTail->next = t;
        else
            sched->sc.gfxListHead = t;

        sched->sc.gfxListTail = t;
    }

    t->next = NULL;
    t->unk58 = 0;
    t->state = t->flags & OS_SC_RCP_MASK;
}


void __scExec(InternalScheduler* sched, OSScTask* sp, OSScTask* dp) {
    int rv;

    if (sp) {
        if (sp->list.t.type == M_AUDTASK) {
            osWritebackDCacheAll();
        } else {
            sp->unk58 = sched->sc.unk284;
        }

        sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);
        osSpTaskLoad(&sp->list);
        osSpTaskStartGo(&sp->list);
        sched->sc.curRSPTask = sp;
        if (sp == dp)
            sched->sc.curRDPTask = dp;
    }

    if (dp && (dp != sp)) {
        rv = osDpSetNextBuffer(dp->list.t.output_buff, *dp->list.t.output_buff_size);

        dp_busy = 1;
        dpCount = 0;

        sched->sc.curRDPTask = dp;
    }
}

void __scYield(InternalScheduler* sched) {
    if (sched->sc.curRSPTask->list.t.type == M_GFXTASK) {

        sched->sc.curRSPTask->state |= OS_SC_YIELD;

        osSpTaskYield();
    } else {
    }
}

s32 __scSchedule(InternalScheduler* sched, OSScTask** sp, OSScTask** dp, s32 availRCP) {
    s32 avail = availRCP;
    OSScTask* gfx = sched->sc.gfxListHead;
    OSScTask* audio = sched->sc.audioListHead;


    if (sched->sc.doAudio && (avail & OS_SC_SP)) {
        if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK)) {
            *sp = gfx;
            avail &= ~OS_SC_SP;
        } else {
            *sp = audio;
            avail &= ~OS_SC_SP;
            sched->sc.doAudio = 0;
            sched->sc.audioListHead = sched->sc.audioListHead->next;
            if (sched->sc.audioListHead == NULL)
                sched->sc.audioListTail = NULL;
        }
    } else {
        if (__scTaskReady(gfx)) {
            switch (gfx->flags & OS_SC_TYPE_MASK) {
                case (OS_SC_XBUS):
                    if (gfx->state & OS_SC_YIELDED) {

                        if (avail & OS_SC_SP) {
                            *sp = gfx;
                            avail &= ~OS_SC_SP;

                            if (gfx->state & OS_SC_DP) {
                                *dp = gfx;
                                avail &= ~OS_SC_DP;

                                if (avail & OS_SC_DP == 0) {}
                            }

                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL)
                                sched->sc.gfxListTail = NULL;
                        }
                    } else {
                        if (avail == (OS_SC_SP | OS_SC_DP)) {
                            *sp = *dp = gfx;
                            avail &= ~(OS_SC_SP | OS_SC_DP);
                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL)
                                sched->sc.gfxListTail = NULL;
                        }
                    }

                    break;

                case (OS_SC_DRAM):
                case (OS_SC_DP_DRAM):
                case (OS_SC_DP_XBUS):
                    if (gfx->state & OS_SC_SP) {
                        if (avail & OS_SC_SP) {
                            *sp = gfx;
                            avail &= ~OS_SC_SP;
                        }
                    } else if (gfx->state & OS_SC_DP) {
                        if (avail & OS_SC_DP) {
                            *dp = gfx;
                            avail &= ~OS_SC_DP;
                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL)
                                sched->sc.gfxListTail = NULL;
                        }
                    }
                    break;

                case (OS_SC_SP_DRAM):
                case (OS_SC_SP_XBUS):
                default:
                    break;
            }
        }
    }

    if (avail != availRCP)
        avail = __scSchedule(sched, sp, dp, avail);

    return avail;
}

