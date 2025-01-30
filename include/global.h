#ifndef GLOBAL_H
#define GLOBAL_H

#include "ultra64.h"

typedef struct  D_800E69C0_struct {
    u8 unk0[0x4];
    u8 unk4[0x4];
    volatile u16 unk8;
    volatile u16 unkA;
    u8 unkD;
    u8 unkE;
    volatile s32 unk10;
    u8 unk14[4];
    u8 unk18[0x5];
    u8 unk1D[0x8];
} D_800E69C0_struct;

extern D_800E69C0_struct D_800E69C0;


#endif