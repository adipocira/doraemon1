#ifndef _7310_H
#define _7310_H

#include "ultra64.h"

typedef struct SeqContext {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    ALCSPlayer* seqPlayer; // alloc 0x7C;
    ALCSeq* currentSequence; // alloc 0xF8;
    void* dmaDataBuf; // alloc 0x2710;
    s16 maxSeqLength;
    ALPan pan;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u16 unk1A;
    u16 unk1C;
    u8 unk20[0xEC];
    void* dmaMsgBuf; // alloc 0x18
} SeqContext;

typedef struct SoundContext {
    ALSndPlayer* soundPlayer;
    u8 unk4[0x2C];
} SoundContext;

extern SeqContext seqContexts[2];
extern SoundContext soundContexts[6];

void alEvtqPrintAllocEvts(ALEventQueue *evtq);
s16 func_80006924(void);
char* MidiStatus2Str (char status, char *str);


#endif
