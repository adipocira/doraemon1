#include "audiomgr.h"

typedef union {

    struct {
        short type;
    } gen;

    struct {
        short type;
        struct AudioInfo_s* info;
    } done;

    OSScMsg app; 

} AudioMsg;

typedef struct AudioInfo_s {
    short* data;        /* Output data pointer */
    short frameSamples; /* # of samples synthesized in this frame */
    OSScTask task;      /* scheduler structure */
    u8 pad[0x8];
    AudioMsg msg; /* completion message */
} AudioInfo;

typedef struct {
    Acmd* ACMDList[NUM_ACMD_LISTS];
    AudioInfo* audioInfo[NUM_OUTPUT_BUFFERS];
    OSThread thread;
    OSMesgQueue audioFrameMsgQ;
    OSMesg audioFrameMsgBuf[MAX_MESGS];
    OSMesgQueue audioReplyMsgQ;
    OSMesg audioReplyMsgBuf[MAX_MESGS];
    ALGlobals g;
} AMAudioMgr;

typedef struct {
    ALLink node;
    u32 startAddr;
    u32 lastFrame;
    char* ptr;
} AMDMABuffer;

typedef struct {
    u8 initialized;
    AMDMABuffer* firstUsed;
    AMDMABuffer* firstFree;
} AMDMAState;

extern OSSched sc;
extern OSMesgQueue* sched_cmdQ;

AMAudioMgr __am;
static u64 audioStack[AUDIO_STACKSIZE / sizeof(u64)];

AMDMAState dmaState;
AMDMABuffer dmaBuffs[NUM_DMA_BUFFERS];
u32 audFrameCt = 0;
u32 nextDMA = 0;
u32 curAcmdList = 0;

u32 minFrameSize;
u32 frameSize;
u32 maxFrameSize;
u32 maxRSPCmds;
  
OSIoMesg audDMAIOMesgBuf[NUM_DMA_MESSAGES]; 
OSMesgQueue audDMAMessageQ;
OSMesg audDMAMessageBuf[NUM_DMA_MESSAGES];
 
void __amMain(void *arg);
s32  __amDMA(s32 addr, s32 len, void *state);
ALDMAproc __amDmaNew(AMDMAState **state);
u32  __amHandleFrameMsg(AudioInfo *, AudioInfo *);
void __amHandleDoneMsg(AudioInfo *);
void __clearAudioDMA(void);

void amCreateAudioMgr(ALSynConfig* c, OSPri pri, amConfig* amc) {
    u32 i;
    f32 fsize;

    c->dmaproc = __amDmaNew;
    c->outputRate = osAiSetFrequency(amc->outputRate);

    fsize = (f32)amc->framesPerField * c->outputRate / (f32)60;
    frameSize = (s32)fsize;

    if (frameSize < fsize) {
        frameSize++;
    }

    if (frameSize & 0xf) {
        frameSize = (frameSize & ~0xf) + 0x10;
    }

    minFrameSize = frameSize - 16;
    maxFrameSize = frameSize + EXTRA_SAMPLES + 16;

    alInit(&__am.g, c);

    dmaBuffs[0].node.prev = 0;
    dmaBuffs[0].node.next = 0;

    for (i = 0; i < NUM_DMA_BUFFERS - 1; i++) {
        alLink((ALLink*)&dmaBuffs[i + 1], (ALLink*)&dmaBuffs[i]);
        dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, DMA_BUFFER_LENGTH);
    }

    dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, DMA_BUFFER_LENGTH);

    for (i = 0; i < NUM_ACMD_LISTS; i++) {
        __am.ACMDList[i] = (Acmd*)alHeapAlloc(c->heap, 1, amc->maxACMDSize * sizeof(Acmd));
    }

    maxRSPCmds = amc->maxACMDSize;

    for (i = 0; i < NUM_OUTPUT_BUFFERS; i++) {
        __am.audioInfo[i] = (AudioInfo*)alHeapAlloc(c->heap, 1, sizeof(AudioInfo));
        __am.audioInfo[i]->msg.done.type = OS_SC_DONE_MSG;
        __am.audioInfo[i]->msg.done.info = __am.audioInfo[i];
        __am.audioInfo[i]->data = alHeapAlloc(c->heap, 1, 4 * maxFrameSize);
    }

    osCreateMesgQueue(&__am.audioReplyMsgQ, __am.audioReplyMsgBuf, MAX_MESGS);
    osCreateMesgQueue(&__am.audioFrameMsgQ, __am.audioFrameMsgBuf, MAX_MESGS);
    osCreateMesgQueue(&audDMAMessageQ, audDMAMessageBuf, NUM_DMA_MESSAGES);

    osCreateThread(&__am.thread, 3, __amMain, 0, (void*)(audioStack + AUDIO_STACKSIZE / sizeof(u64)), pri);
    osStartThread(&__am.thread);
}

void __amMain(void* arg) {
    u32 validTask;
    u32 done = 0;
    AudioMsg* msg = NULL;
    AudioInfo* lastInfo = 0;
    OSScClient client;

    osScAddClient(&sc, &client, &__am.audioFrameMsgQ);

    while (!done) {
        (void)osRecvMesg(&__am.audioFrameMsgQ, (OSMesg*)&msg, OS_MESG_BLOCK);

        switch (msg->gen.type) {

            case (OS_SC_RETRACE_MSG):
                validTask = __amHandleFrameMsg(__am.audioInfo[audFrameCt % 3], lastInfo);
                if (validTask) {
                    osRecvMesg(&__am.audioReplyMsgQ, (OSMesg*)&msg, OS_MESG_BLOCK);
                    __amHandleDoneMsg(msg->done.info);
                    lastInfo = msg->done.info;
                }
                break;

            case (OS_SC_PRE_NMI_MSG): 
                break;

            case (QUIT_MSG):
                done = 1;
                break;

            default:
                break;
        }
    }

    alClose(&__am.g);
}

u32 __amHandleFrameMsg(AudioInfo* info, AudioInfo* lastInfo) {
    s16* audioPtr;
    Acmd* cmdp;
    s32 cmdLen;
    int samplesLeft = 0;
    OSScTask* t;

    __clearAudioDMA();

    audioPtr = (s16*)osVirtualToPhysical(info->data);

    if (lastInfo) {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);
    }

    samplesLeft = osAiGetLength() >> 2;

    info->frameSamples = 16 + (frameSize - samplesLeft + EXTRA_SAMPLES) & ~0xf;

    if (info->frameSamples < minFrameSize)
        info->frameSamples = minFrameSize;

    cmdp = alAudioFrame(__am.ACMDList[curAcmdList], &cmdLen, audioPtr, info->frameSamples);

    if (cmdLen == 0) {
        return 0;
    }

    t = &info->task;

    t->next = 0;
    t->msgQ = &__am.audioReplyMsgQ;
    t->msg = (OSMesg)&info->msg;
    t->flags = OS_SC_NEEDS_RSP;

    t->list.t.data_ptr = (u64*)__am.ACMDList[curAcmdList];
    t->list.t.data_size = (cmdp - __am.ACMDList[curAcmdList]) * sizeof(Acmd);
    t->list.t.type = M_AUDTASK;
    t->list.t.ucode_boot = (u64*)rspbootTextStart;
    t->list.t.ucode_boot_size = ((int)rspbootTextEnd - (int)rspbootTextStart);
    t->list.t.flags = OS_TASK_DP_WAIT;
    t->list.t.ucode = (u64*)aspMainTextStart;
    t->list.t.ucode_data = (u64*)aspMainDataStart;
    t->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;

    osSendMesg(sched_cmdQ, (OSMesg)t, OS_MESG_BLOCK);

    curAcmdList ^= 1;

    return 1;
}

void __amHandleDoneMsg(AudioInfo* info) {
    s32 samplesLeft;
    static int firstTime = 1;

    samplesLeft = osAiGetLength() >> 2;

    if (samplesLeft == 0 && !firstTime) {
        firstTime = 0;
    }
}

u32 D_800ABCF0 = 0;
u32 D_800ABCF4 = 0;

s32 __amDMA(s32 addr, s32 len, void* state) {
    void* foundBuffer;
    s32 delta, addrEnd, buffEnd;
    AMDMABuffer *dmaPtr, *lastDmaPtr;

    lastDmaPtr = 0;
    dmaPtr = dmaState.firstUsed;
    addrEnd = addr + len;

    while (dmaPtr) {
        buffEnd = dmaPtr->startAddr + DMA_BUFFER_LENGTH;
        if (dmaPtr->startAddr > addr)
        {
            break;
        }                    
        else if (addrEnd <= buffEnd)
        {
            dmaPtr->lastFrame = audFrameCt;
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return (int)osVirtualToPhysical(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (AMDMABuffer*)dmaPtr->node.next;
    }

    dmaPtr = dmaState.firstFree;

    if (!dmaPtr)
        return osVirtualToPhysical(dmaState.firstUsed);

    dmaState.firstFree = (AMDMABuffer*)dmaPtr->node.next;
    alUnlink((ALLink*)dmaPtr);

    if (lastDmaPtr) {
        alLink((ALLink*)dmaPtr, (ALLink*)lastDmaPtr);
    } else if (dmaState.firstUsed) {
        lastDmaPtr = dmaState.firstUsed;
        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = (ALLink*)lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink*)dmaPtr;
    } else {
        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 0x1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = audFrameCt;

    osPiStartDma(&audDMAIOMesgBuf[nextDMA++], OS_MESG_PRI_HIGH, OS_READ, addr, foundBuffer, DMA_BUFFER_LENGTH,
                 &audDMAMessageQ);

    return (int)osVirtualToPhysical(foundBuffer) + delta;
}

ALDMAproc __amDmaNew(AMDMAState** state) {
    int i;

    if (!dmaState.initialized) {
        dmaState.firstUsed = 0;
        dmaState.firstFree = &dmaBuffs[0];
        dmaState.initialized = 1;
    }

    *state = &dmaState;

    return __amDMA;
}

void __clearAudioDMA(void) {
    u32 i;
    OSIoMesg* iomsg = NULL;
    AMDMABuffer *dmaPtr, *nextPtr;

    for (i = 0; i < nextDMA; i++) {
        if (osRecvMesg(&audDMAMessageQ, (OSMesg*)&iomsg, OS_MESG_NOBLOCK) == -1)
            ;
    }

    dmaPtr = dmaState.firstUsed;

    while (dmaPtr) {
        nextPtr = (AMDMABuffer*)dmaPtr->node.next;

        if (dmaPtr->lastFrame + FRAME_LAG < audFrameCt) {
            if (dmaState.firstUsed == dmaPtr)
                dmaState.firstUsed = (AMDMABuffer*)dmaPtr->node.next;
            alUnlink((ALLink*)dmaPtr);
            if (dmaState.firstFree)
                alLink((ALLink*)dmaPtr, (ALLink*)dmaState.firstFree);
            else {
                dmaState.firstFree = dmaPtr;
                dmaPtr->node.next = 0;
                dmaPtr->node.prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }

    nextDMA = 0;
    audFrameCt++;
}
