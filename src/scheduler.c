#include "scheduler.h"
#include "schedule.h"
#include "thread.h"

extern s16 D_803B5000;
extern s16 D_80297800;

typedef struct D_800E6A20_struct {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} D_800E6A20_struct;

typedef struct D_800F5FB0_struct {
    s8 unk0;
    s8 unk1;
    u8 unk2[0x3E];
    void* unk40;
    s32 unk44;
    void* unk48;
} D_800F5FB0_struct;  // size >= 0x48

void* D_801BAA80;
void* D_801BAAA0;

D_800F5FB0_struct D_800F5FB0;

D_800E6A20_struct D_800E6A20[256];

OSMesgQueue piMesgQueue;
OSMesg piMsg[200];

OSMesgQueue D_800E3F18;
OSMesg D_800E3F30;

OSMesgQueue D_800EDDD0;
OSMesg D_800EDDE8;


typedef struct D_800E6270_unk1C4_struct {
    s32 unk0;
    u8 unk4[0x4];
    s32 unk8;
} D_800E6270_unk1C4_struct;

D_800E6270_unk1C4_struct* D_800F3944;

typedef struct D_800F38A0_struct {
    u8 unk0[0x46];
    u16 unk46;
} D_800F38A0_struct;

D_800F38A0_struct D_800F38A0; 

extern u8 DoraFileHandle;
extern const char DoraVersion[] = "DORA_0221_MRV10";
extern u64 DoraItem;

extern u32 DoraRamSize;
extern u32 DoraRomSize;

extern u16 DoraTexrecNum;


void func_80000800() {
    D_800E6A20_struct *ptr;

    s32 i;
    s32 idx;
    func_80003710();

    for (i = 0; i < 0x25800; i++) {
        D_803B5000 = 0;
    }

    for (i = 0; i < 0x12C00; i++) {
        D_80297800 = 0;
    }

    func_80013CF0(D_800E6A20, 16);

    idx = func_80013DDC(D_800E6A20, 16);

    D_800E6A20[idx].unk8 = 1;
    D_800E6A20[idx].unk2 = 1;
    D_800E6A20[idx].unk1 = 2;
    D_800E6A20[idx].unkC = 0;

    idx = func_80013DDC(D_800E6A20, 16);

    D_800E6A20[idx].unk8 = 60;
    D_800E6A20[idx].unk2 = 1;
    D_800E6A20[idx].unk1 = 2;
    D_800E6A20[idx].unkC = 0;

    idx = func_80013DDC(D_800E6A20, 16);

    D_800E6A20[idx].unk8 = 60;
    D_800E6A20[idx].unk2 = -1;
    D_800E6A20[idx].unkC = 3600;
    D_800E6A20[idx].unk1 = 3;

    func_80013DDC(D_800E6A20, 16);
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    D_800F5FB0.unk1 = 0x14;
    osCreatePiManager(OS_PRIORITY_PIMGR, &piMesgQueue, piMsg, ARRAY_COUNT(piMsg));
    osCreateMesgQueue(&D_800E3F18, &D_800E3F30, 1);
    osCreateMesgQueue(&D_800EDDD0, &D_800EDDE8, 1);
}

void createScheduler(InternalScheduler *sched, void *stack, OSPri priority, u8 mode, u8 numFields) {
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

    osCreateThread(&sched->sc.thread, DORA_THREAD_SCHED_ID, __scMain, (void *)sched, stack, priority);
    osStartThread(&sched->sc.thread);
}

void osScAddClient(InternalScheduler *sched, OSScClient *c, OSMesgQueue *msgQ) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    c->msgQ = msgQ;
    c->next = sched->sc.clientList;
    sched->sc.clientList = c;

    osSetIntMask(mask);
}

void osScRemoveClient(InternalScheduler *sched, OSScClient *c) {
    OSScClient *client = sched->sc.clientList;
    OSScClient *prev = 0;
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

OSMesgQueue *osScGetCmdQ(InternalScheduler *sched) { return &sched->sc.cmdQ; }

void __scMain(void *arg) {
    OSMesg msg;
    InternalScheduler *sched = (InternalScheduler *)arg;
    OSScClient *client;
    u32 mode;

    while (1) {
        osRecvMesg(&sched->sc.interruptQ, (OSMesg *)&msg, OS_MESG_BLOCK);

        switch ((int)msg) {
            case (VIDEO_MSG):
                sched->unk298 = osGetTime() - sched->unk290;
                sched->unk290 = osGetTime();
                sched->sc.unk284++;
                D_800E69C0.unk10 = sched->sc.unk284;
                func_80013BB0(D_800E6A20, 16);
                mode = osViGetCurrentMode();

                if (mode != 0) {
                    func_80012B80(&D_800E6B20, mode);
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

static int dp_busy = 0;
static int dpCount = 0;

void __scHandleRetrace(InternalScheduler* sched) {
    OSScTask *rspTask;
    OSScClient *client;
    s32 i;
    s32 state;
    OSScTask *sp = 0;
    OSScTask *dp = 0;

    sched->sc.frameCount++;

    while (osRecvMesg(&sched->sc.cmdQ, (OSMesg *)&rspTask, OS_MESG_NOBLOCK) != -1) {
        __scAppendList(sched, rspTask);
    }

    if (sched->sc.doAudio && sched->sc.curRSPTask) {
        __scYield(sched);
    } else {
        state = ((sched->sc.curRSPTask == 0) << 1) | (sched->sc.curRDPTask == 0);
        if (__scSchedule(sched, &sp, &dp, state) != state) __scExec(sched, sp, dp);
    }

    for (client = sched->sc.clientList; client != 0; client = client->next) {
        osSendMesg(client->msgQ, (OSMesg)&sched->sc.retraceMsg, OS_MESG_NOBLOCK);
    }
}

void __scHandleRSP(InternalScheduler* sched)
{
    OSScTask *t, *sp = 0, *dp = 0;
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
    if ( (__scSchedule (sched, &sp, &dp, state)) != state)
        __scExec(sched, sp, dp);
}

void __scHandleRDP(InternalScheduler* sched) {
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;

    t = sched->sc.curRDPTask;
    sched->sc.curRDPTask = 0;

    if(sched->sc.unk284 != t->unk58){
        sched->unk288 = sched->sc.unk284 - t->unk58;
    }
    else{
        sched->unk288 = -(sched->sc.unk284 - t->unk58);
        
    }


    t->state &= ~OS_SC_NEEDS_RDP;

    __scTaskComplete(sched, t);

    state = ((sched->sc.curRSPTask == 0) << 1) | (sched->sc.curRDPTask == 0);
    if ((__scSchedule(sched, &sp, &dp, state)) != state) __scExec(sched, sp, dp);
}

OSScTask *__scTaskReady(OSScTask *t) 
{
    int rv = 0;
    void *a;
    void *b;    

    if (t) {    
        if ((a=osViGetCurrentFramebuffer()) != (b=osViGetNextFramebuffer())) {
            return 0;
        }

        return t;
    }

    return 0;
}

s32 __scTaskComplete(InternalScheduler *sched, OSScTask *t) {
    int rv;
    static int firsttime = 1;

    if ((t->state & OS_SC_RCP_MASK) == 0) {

        rv = osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);

        if (t->list.t.type == M_GFXTASK) {
            if ((t->flags & OS_SC_SWAPBUFFER) && (t->flags & OS_SC_LAST_TASK)) {
                if (firsttime) {
                    osViBlack(FALSE);
                    firsttime = 0;
                }
                if(D_8015A392 & 2){
                    s32 i;
                    
                    u16* ptr;
                    s32 ts2;
                    char buf[34];
                    
                    void* fb = t->framebuffer;
                    
                    sprintf(buf, "Version. %s", DoraVersion);
                    func_80003364(fb,16,12,buf);
                    if(D_800F3944->unk8 != 0){
                        sprintf(buf, "File Handle : %d",DoraFileHandle);
                        func_80003364(fb,16,28,buf);
                        sprintf(buf, "Item : 0x%llx", DoraItem);
                        func_80003364(fb,16,28,buf);
                        func_80003364(fb,16,36,"Event :");
                        
                        ptr = (u16*)&D_800F38A0;
                        for(i = 0,ts2 = 44; i < 18; i++){
                            sprintf(buf, "[%d] : 0x%x", i, ((D_800F38A0_struct*)ptr)->unk46);
                            func_80003364(fb, 0x20, ts2, buf);
                            ptr++;
                            ts2 += 8;
                        }
                    }
                    else if(D_800F3944->unk0 != 0){
                        sprintf(buf,"RAM SIZE : 0x%lx (%d)", DoraRamSize, DoraRamSize);
                        func_80003364(fb,16,28,buf);
                        sprintf(buf,"ROM SIZE : 0x%lx (%d)", DoraRomSize, DoraRomSize);
                        func_80003364(fb,16,36,buf);
                    }
                    else{
                        sprintf(buf, "TexRec num : %d",DoraTexrecNum);
                        func_80003364(fb,16,28,buf);
                        sprintf(buf, "CFB render : 0x%x", D_800E69C0.unkE);
                        func_80003364(fb,16,36,buf);
                        
                        sprintf(buf, "SYS CALL : 0x%x", D_800E69C0.unkD);
                        func_80003364(fb,16,44,buf);
                        
                        
                    }
                }
                osViSwapBuffer(t->framebuffer); 
            }
        }
        return 1;
    }

    return 0;
}


/*
 * Place task on either the audio or graphics queue
 */
void __scAppendList(InternalScheduler *sched, OSScTask *t) {
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

void __scExec(InternalScheduler *sched, OSScTask *sp, OSScTask *dp) {
    int rv;
    if (sp) {
        if (sp->list.t.type == M_AUDTASK) {
            osWritebackDCacheAll(); /* flush the cache */
        }
        else{
            sp->unk58 = sched->sc.unk284;
        }

        sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);
        osSpTaskLoad(&sp->list);
        osSpTaskStartGo(&sp->list);
        sched->sc.curRSPTask = sp;
        if (sp == dp) sched->sc.curRDPTask = dp;
    }

    if (dp && (dp != sp)) {
        rv = osDpSetNextBuffer(dp->list.t.output_buff, *dp->list.t.output_buff_size);

        dp_busy = 1;
        dpCount = 0;

        sched->sc.curRDPTask = dp;
    }
}

void __scYield(InternalScheduler *sched) {
    if (sched->sc.curRSPTask->list.t.type == M_GFXTASK) {

        sched->sc.curRSPTask->state |= OS_SC_YIELD;

        osSpTaskYield();
    } else {
    }
}

s32 __scSchedule(InternalScheduler* sched, OSScTask **sp, OSScTask **dp, s32 availRCP) {
    s32 avail = availRCP;
    OSScTask *gfx = sched->sc.gfxListHead;
    OSScTask *audio = sched->sc.audioListHead;

    if (sched->sc.doAudio && (avail & OS_SC_SP)) {
        if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK)) {
            *sp = gfx;
            avail &= ~OS_SC_SP;
        } else {
            *sp = audio;
            avail &= ~OS_SC_SP;
            sched->sc.doAudio = 0;
            sched->sc.audioListHead = sched->sc.audioListHead->next;
            if (sched->sc.audioListHead == NULL) sched->sc.audioListTail = NULL;
        }
    } else {
        if (__scTaskReady(gfx)) {
            switch (gfx->flags & OS_SC_TYPE_MASK) {
                case (OS_SC_XBUS):
                    if (gfx->state & OS_SC_YIELDED) {
                        /* can hit this if RDP finishes at yield req */
                        /* assert(gfx->state & OS_SC_DP); */

                        if (avail & OS_SC_SP) { /* if SP is available */
                            *sp = gfx;
                            avail &= ~OS_SC_SP;

                            if (gfx->state & OS_SC_DP) { /* if it needs DP */
                                *dp = gfx;
                                avail &= ~OS_SC_DP;

                                if (avail & OS_SC_DP == 0){}
                            }

                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL) sched->sc.gfxListTail = NULL;
                        }
                    } else {
                        if (avail == (OS_SC_SP | OS_SC_DP)) {
                            *sp = *dp = gfx;
                            avail &= ~(OS_SC_SP | OS_SC_DP);
                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL) sched->sc.gfxListTail = NULL;
                        }
                    }

                    break;

                case (OS_SC_DRAM):
                case (OS_SC_DP_DRAM):
                case (OS_SC_DP_XBUS):
                    if (gfx->state & OS_SC_SP) { /* if needs SP */
                        if (avail & OS_SC_SP) {  /* if SP is available */
                            *sp = gfx;
                            avail &= ~OS_SC_SP;
                        }
                    } else if (gfx->state & OS_SC_DP) { /* if needs DP */
                        if (avail & OS_SC_DP) {         /* if DP available */
                            *dp = gfx;
                            avail &= ~OS_SC_DP;
                            sched->sc.gfxListHead = sched->sc.gfxListHead->next;
                            if (sched->sc.gfxListHead == NULL) sched->sc.gfxListTail = NULL;
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

    if (avail != availRCP) avail = __scSchedule(sched, sp, dp, avail);

    return avail;
}
