#ifndef TEXREC_H
#define TEXREC_H

#include "ultra64.h"

typedef struct D_801BABB0_struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6; 
    u16 unk8;
    u16 unkA;
    u8 unkC[0x4];
    Gfx* unk10;
    s16* unk14;
    u8 unk18;
    u8 unk19[0xB];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
}D_801BABB0_struct;

typedef struct TexRec {
    u16 num;
    u16 amount;
    u32 unk4;
    s32* unk8;
    u8* unkC;
} TexRec;

extern TexRec texRec;

#define texRecAccessPtr(iterator) ((D_801BABB0_struct*)texRec->unk8[texRec->unkC[(iterator)]])
#define texRecAccess(iterator) ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[(iterator)]])


#endif
