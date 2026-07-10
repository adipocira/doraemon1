#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ultra64.h"
#include "common.h"

typedef struct D_800E6468_struct{
    u8 unk0[0x48];
    D_800F3940_struct unk48;
    u8 unkFC;
    s16 unkFE;
    s16 unk100;
    s16 unk102;
    s16 unk104;
    s16 unk106;
    s32 unk108;
    s32 unk10C;
}D_800E6468_struct;
 
typedef struct D_800E6270_struct{
    s32 unk0;
    u8 unk4;
    u8 unk5[4];
    u8 unk9;
    OSContStatus status[4];
    u8 unk1A;
    u8 unk1B[4];
    u8 unk1F[4];
    OSPfs pfs[4];
    D_800E6468_struct* unk1C4;
    OSMesgQueue* msgQueue;
    void* unk1CC;
    s16 unk1D0;
    u16 pad1D2;
    u8 unk1D4[0x1C];
    u32 unk1F0;
    u8 unk1F4;
    u8 unk1F5;
}D_800E6270_struct;

void func_800016D0(D_800E6270_struct* arg0);
void func_80001BF8(OSMesgQueue* queue);
void func_80001C18(OSMesgQueue* queue, D_800E6270_struct* arg1);
s32 func_80001C38(OSMesgQueue* queue, OSMesg* msg, s32 count, void* arg3, D_800E6270_struct* arg4, D_800E6468_struct* arg5, u8 arg6, u8 arg7);

extern D_800E6468_struct D_800E6468;
extern D_800E6270_struct D_800E6270;

#endif
