#ifndef ZZSPRITE_H
#define ZZSPRITE_H

#include "ultra64.h"

typedef struct InternalSpriteInfo{
    u16 attr;
    s16 w;
    s16 h;
    s16 unk6;
    s16 unk8;
    s16 depth;
    s16 unkC;
    s16 unkE;  
    f32 scaleX;
    f32 scaleY;
    s16 expX;
    s16 expY;
    Sprite* sp;
    Bitmap* bm;
    Gfx* dl;
}InternalSpriteInfo;


typedef struct InternalSprite{
    u16 unk0;
    u16 unk2;
    InternalSpriteInfo* info;
    Bitmap* unk8;
}InternalSprite;

void zzSprite_drawSprite(Gfx** gfxPtr, InternalSprite* sp);
void func_80080F4C(InternalSprite* sp, u16 arg1, u16 arg2, u16 arg3);
void zzSprite_distCalc(InternalSprite* sp, u16* arg1, u16 arg2, u16 arg3);
void func_800810EC(InternalSprite* sp, u16* arg1, u16 arg2, u16 arg3, u16 arg4);
void zzSprite_drawSpriteImpl(Gfx** gfxPtr, InternalSpriteInfo* info);
void zzSprite_setAttr(InternalSpriteInfo* info, u16 attr);
void zzSprite_setWH(InternalSpriteInfo* info, s16 w, s16 h);
void zzSprite_setDepth_68(InternalSpriteInfo* info, s16 arg1, s16 arg2, s16 depth);
void zzSprite_setCE(InternalSpriteInfo* info, s16 arg1, s16 arg2);
void zzSprite_setScales(InternalSpriteInfo* info, f32 scaleX, f32 scaleY);
void zzSprite_setExp(InternalSpriteInfo* info, s16 expX, s16 expY);
void zzSprite_setSprite(InternalSpriteInfo* info, Sprite* sp);
void zzSprite_setBitmap(InternalSpriteInfo* info, Bitmap* bm);

#endif
