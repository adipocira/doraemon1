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
    s16 unk4;
    s16 unk6;
    ALSndId soundId;
    u8 unkA[0x2];
    s32 unkC;
    s16 vol;
    ALPan pan;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16[0x2];
    f32 unk18;
    f32 soundPosX;
    f32 soundPosY;
    f32 soundPosZ;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
} SoundContext; 

extern SeqContext seqContexts[2];
extern OSMesgQueue D_800F08A0[2];
extern ALSeqFile* D_800F08D0;
extern ALBank* D_800F08D4;
extern ALInstrument* D_800F08D8;
extern ALSound* D_800F08DC;
extern SoundContext soundContexts[6];

void alEvtqPrintAllocEvts(ALEventQueue *evtq);
s16 func_80006924(void);
char* MidiStatus2Str (char status, char *str);


#endif
