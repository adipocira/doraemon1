#ifndef _9320_H
#define _9320_H

#include "ultra64.h"

#define ZZ_SEQ_PROPS_EFFECTS 0 // Reverb
#define ZZ_SEQ_PROPS_DATA 1 // Includes volume, pitch, priority

#define ZZ_SEQ_PROPS_VOL 0x7
#define ZZ_SEQ_PROPS_PITCH 0x8
#define ZZ_SEQ_PROPS_PRIORITY 0xF0

#define ZZ_SEQ_PROPS_PRIORITY_SET(x) ((x) << 0x4)

// 0xFFF gets added to the volume
typedef enum AudioSoundVolProp{
	ZZ_AUDIO_SOUND_VOL_PROP_0,
	ZZ_AUDIO_SOUND_VOL_PROP_1,
	ZZ_AUDIO_SOUND_VOL_PROP_2,
	ZZ_AUDIO_SOUND_VOL_PROP_3,
	ZZ_AUDIO_SOUND_VOL_PROP_4,
	ZZ_AUDIO_SOUND_VOL_PROP_5,
	ZZ_AUDIO_SOUND_VOL_PROP_6,
	ZZ_AUDIO_SOUND_VOL_PROP_7,
	ZZ_AUDIO_SOUND_VOL_PROP_MAX = ZZ_AUDIO_SOUND_VOL_PROP_7,
}ZZAudioSoundVolProp;

//Higher, plays first
typedef enum AudioSoundPriorityProp{
	ZZ_AUDIO_SOUND_PRIORITY_PROP_0,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_1,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_2,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_3,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_4,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_5,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_6,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_7,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_8,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_9,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_10,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_11,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_12,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_13,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_14,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_15,
	ZZ_AUDIO_SOUND_PRIORITY_PROP_MAX = ZZ_AUDIO_SOUND_PRIORITY_PROP_15,
}ZZAudioSoundPriorityProp;

void zzAudioSoundCalcValues(f32 x, f32 y, f32 z, s32 maxDist, s32 maxVol, ALPan* panPtr, s16* volPtr);
s32 zzAudioSoundPlaySoundImpl(s16 soundId, u8 soundCtxId);
void zzAudioSoundPlaySound(s16 soundId, u8 soundCtxId);
void zzAudioSoundPlaySoundAt(s16 soundId, u8 soundCtxId, s32 maxDist, s32 maxVol, f32 x, f32 y, f32 z);
void zzAudioSoundPlaySoundActor(s16 soundId, u8 soundCtxId, s16 actorIdx);
void zzAudioSoundSetVolZero(void);
void zzAudioSoundSetVolFromProps(void);
void zzAudioSoundSetMaxVol0(s16 arg0, u8 soundCtxId);
void zzAudioSoundSetMaxVol1(s16 arg0, u8 soundCtxId);
void zzAudioSoundSetMix(s16 arg0, u8 soundCtxId);
void zzAudioSoundSetPitch(f32 arg0, u8 soundCtxId);
void zzAudioSoundSetPan(s8 pan, u8 soundCtxId);
void zzAudioSoundSetVol(s16 vol, u8 soundCtxId);
void func_800090B0(u8 soundCtxId);
void zzAudioSoundInitSound(void);
void zzAudioSoundProc(void);

#endif
