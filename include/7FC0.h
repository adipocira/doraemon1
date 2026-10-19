#ifndef _7FC0_H
#define _7FC0_H

#include "ultra64.h"

#define EVT_COUNT 128
#define MAX_CHANNELS 16

void zzAudioSeqPlaySeq(s16 seq, u8 seqIdx);
void zzAudioSeqSetPan(u8 seqIdx);
void zzAudioSeqSetPanMono(u8 seqIdx);
void func_80007520(u16 arg0, u8 seqIdx);
void func_800075A0(s16 seq, u16 arg1, u8 seqIdx);
void func_80007648(u8 seqIdx);
void func_8000767C(u8 seqIdx);
void func_800076B0(u8 seqIdx);
void zzAudioSeqSetVol(s16 seqVol, u8 seqIdx);
void zzAudioSeqInitSeq(void);
void zzAudioSeqLoadSeq(u8 seqIdx);
void zzAudioSeqProc(void);
f32 _depth2Cents(u8 depth);
ALMicroTime initsOsc(void** oscState,f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);
ALMicroTime updateOsc(void* oscState, f32* updateVal);
void stopOsc(void* oscState);


#endif
