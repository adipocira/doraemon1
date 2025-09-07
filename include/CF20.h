#ifndef _CF20_H
#define _CF20_H

#include "ultra64.h"

void func_8000C320( Gfx** gfxPtr, s32 arg1, void* arg2, Gfx* dl1, Gfx* dl2);
void func_8000C444(Gfx** gfxPtr);
void func_8000C478(Gfx** gfxPtr, void* depthImgAddr, void* colourImageAddr);
void func_8000C60C(Gfx** gfxPtr, void* imgAddr);
void func_8000C71C(Gfx** gfxPtr, void* imgAddr, u16 colour);
void func_8000C830(Gfx** gfxPtr, s32 near, s32 far, s32 r, s32 g, s32 b, s32 a);

#endif
