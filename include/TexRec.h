#ifndef TEXREC_H
#define TEXREC_H

#include "ultra64.h"

typedef struct D_801BABB0_struct {
    u16 width;
    u16 height;
    u16 posX;
    u16 posY; 
    u16 unk8;
    u16 unkA;
    s32 texBit;
    Gfx* gfx;
    u16* pal;
    s32* unk18;
	u8 unk1C[0x8];
	u8 alpha;
	u8 rotateMode;
	u8 unk26[0x2];
	u8 unk28;
	u8 gfxFlags;
	u8 unk2A;
}D_801BABB0_struct;

typedef struct TexRec {
    u16 num;
    u16 amount;
    u32 unk4;
    D_801BABB0_struct** unk8;
    u8* unkC;
} TexRec;

extern TexRec texRec;

#define texRecAccessPtr(iterator) (texRec->unk8[texRec->unkC[(iterator)]])
#define texRecAccess(iterator) (texRec.unk8[texRec.unkC[(iterator)]])


#endif
