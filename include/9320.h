#ifndef _9320_H
#define _9320_H

#include "ultra64.h"

void func_80008720(f32 x, f32 y, f32 z, s32 arg3, s32 arg4, u8* panPtr, s16* volPtr);
s32 func_80008A30(s16 soundId, u8 soundCtxId);
void func_80008C6C(s16 soundId, u8 soundCtxId);
void func_80008D24(s16 soundId, u8 soundCtxId, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);
void func_80008E10(s16 soundId, u8 soundCtxId, s16 actorIdx);
void func_80008EFC(void);
void func_80008F40(void);
void func_80008FC4(s16 arg0, u8 soundCtxId);
void func_80008FEC(s16 arg0, u8 soundCtxId);
void func_80009014(s16 arg0, u8 soundCtxId);
void func_8000903C(f32 arg0, u8 soundCtxId);
void func_80009060(s8 pan, u8 soundCtxId);
void func_80009088(s16 vol, u8 soundCtxId);
void func_800090B0(u8 soundCtxId);
void func_800090E4(void);
void func_80009240(void);

#endif
