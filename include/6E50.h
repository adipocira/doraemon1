#ifndef _6E50_H
#define _6E50_H

#include "ultra64.h"

typedef struct _80006250_arg1 {
    f32 fovy;
    f32 aspect;
    f32 near;
    f32 far;
    f32 scale;
    f32 unk14;
} _80006250_arg1;

typedef struct _80006250_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
} _80006250_arg2;

void func_80006250(Gfx** gfxPtr, _80006250_arg1* arg1, _80006250_arg2* arg2, Mtx* persp, Mtx* lookAt, u16* norm);

#endif
