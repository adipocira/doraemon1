#include "1400.h"
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

void func_80000800() {
    D_800E6A20_struct* ptr;

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

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669

void createScheduler(InternalScheduler *sched, void *stack, OSPri priority,
                       u8 mode, u8 numFields)
{
    sched->sc.curRSPTask      = 0;
    sched->sc.curRDPTask      = 0;
    sched->sc.clientList      = 0;
    sched->sc.frameCount      = 0;
    sched->sc.audioListHead   = 0;
    sched->sc.gfxListHead     = 0;
    sched->sc.audioListTail   = 0;
    sched->sc.gfxListTail     = 0;
    sched->sc.retraceMsg.type = OS_SC_RETRACE_MSG;
    sched->sc.prenmiMsg.type  = 5;
    
    osCreateMesgQueue(&sched->sc.interruptQ, sched->sc.intBuf, OS_SC_MAX_MESGS);
    osCreateMesgQueue(&sched->sc.cmdQ, sched->sc.cmdMsgBuf, OS_SC_MAX_MESGS);

    osCreateViManager(OS_PRIORITY_VIMGR);    
    osViSetMode(&osViModeTable[mode]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &sched->sc.interruptQ, (OSMesg)RSP_DONE_MSG);
    osSetEventMesg(OS_EVENT_DP, &sched->sc.interruptQ, (OSMesg)RDP_DONE_MSG);    
    osSetEventMesg(OS_EVENT_PRENMI, &sched->sc.interruptQ, (OSMesg)PRE_NMI_MSG);    

    osViSetEvent(&sched->sc.interruptQ, (OSMesg)VIDEO_MSG, numFields);    

    sched->unk284 = 0;
    sched->unk290 = 0;

    osCreateThread(&sched->sc.thread, DORA_THREAD_SCHED_ID , func_80000BC0, (void *)sched, stack, priority);
    osStartThread(&sched->sc.thread);
}
