#ifndef _7310_H
#define _7310_H

#include "ultra64.h"

typedef struct SeqContext {
    s16 seqIdx;
    s16 unk2;
    s32 status;
    ALCSPlayer* seqPlayer; // alloc 0x7C;
    ALCSeq* currentSequence; // alloc 0xF8;
    void* dmaDataBuf; // alloc 0x2710;
    s16 seqVol;
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
    s16 sound;
    s16 unk6;
    ALSndId soundId;
    s32 status;
    s16 vol;
    ALPan pan;
    u8 baseMix;
    u8 unk14;
    f32 pitch;
    f32 soundPosX;
    f32 soundPosY;
    f32 soundPosZ;
    s16 maxVol;
    s16 actorId;
    s16 maxDist;
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
