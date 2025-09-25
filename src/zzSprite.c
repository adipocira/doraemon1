#include "zzSprite.h"


void zzSprite_drawSprite(Gfx** gfxPtr, InternalSprite* sp){
    u32 info = sp->info;
    Gfx* gfx = *gfxPtr;
    
    zzSprite_drawSpriteImpl(&gfx, info);

    *gfxPtr = gfx;
}

void func_80080F4C(InternalSprite* sp, u16 arg1, u16 arg2, u16 arg3){
    u16 i;
    InternalSpriteInfo* info = sp->info;

    for(i = arg1; i < arg1+arg2; i++){
        info->bm[i] = sp->unk8[arg3];
    }
}

void zzSprite_distCalc(InternalSprite* sp, u16* arg1, u16 arg2, u16 arg3){
    InternalSpriteInfo* info = sp->info;
    Sprite* sprite = info->sp;
    u16 i = 0;
    u16 t1 = arg2;
    u16 t2 = arg3;
    
    while (arg1[i] != 0xFFFF) {
        if (t1 >= sp->unk0) {
            t2++;
            t1 = 0;
        }
        if (arg1[i] == 0xFFFE) {
            t1 = 0;
            t2++;
        } else {        
            info->bm[t1 + t2 * (info->w / sprite->bmheight)] = sp->unk8[arg1[i]];
            t1++;
        }
        i++;
    }

}

void func_800810EC(InternalSprite* sp, u16* arg1, u16 arg2, u16 arg3, u16 arg4) {
    u16 sp44[5] = {0x2710,0x03E8, 0x64, 0x0A, 0x01};
    u16 sp38[6];
    s32 i;


    sp38[5] = -1;

    for (i = 0; i < 5; i++) {
        sp38[i] = arg1[arg4 / sp44[i]];
        arg4 -= sp44[i] * (arg4 / sp44[i]);
    }

    i = 0;
    if (sp38[i] == *arg1) {
        for (; i < 4; i++) {
            sp38[i] = 0;
            if (sp38[i + 1] != *arg1) {
                break;
            }
        }
    }

    zzSprite_distCalc(sp, sp38, arg2, arg3);
}

void zzSprite_drawSpriteImpl(Gfx** gfxPtr, InternalSpriteInfo* info){
    Sprite* sp = info->sp;
    Gfx* gfx;
    Gfx* dl;

    gfx = *gfxPtr;
    
    spInit(&gfx);

    sp->bitmap = info->bm;

    sp->rsp_dl = info->dl;
    sp->rsp_dl_next = sp->rsp_dl;
    
    sp->attr = info->attr;

    sp->width = info->w;
    sp->height = info->h;

    sp->x = ( (info->unk6 - info->unkC) - (info->unkC * (info->scaleX - 1.0f)) - ((info->expX * (sp->width / sp->bmheight)) / 2));
    sp->y = ( (info->unk8 - info->unkE) - (info->unkE * (info->scaleY - 1.0f)) - ((info->expY * (sp->height / sp->bmheight)) / 2));

    sp->zdepth = info->depth;
    
    sp->scalex = info->scaleX;
    sp->scaley = info->scaleY;
    
    sp->expx = info->expX;
    sp->expy = info->expY;

    sp->nbitmaps = (info->h / sp->bitmap->actualHeight) * (info->w / sp->bitmap->width);
    sp->ndisplist = ((info->h / sp->bitmap->actualHeight) * (info->w /  sp->bitmap->width) * 0xC) + 0x18;
    
    dl = spDraw(sp);

    gSPDisplayList(gfx++, dl);

    spFinish(&gfx);
    gfx--;
    
    *gfxPtr = gfx;
    
}

void zzSprite_setAttr(InternalSpriteInfo* info, u16 attr) {
    info->attr = attr;
}

void zzSprite_setWH(InternalSpriteInfo* info, s16 w, s16 h) {
    info->w = w;
    info->h = h;
}

void zzSprite_setDepth_68(InternalSpriteInfo* info, s16 arg1, s16 arg2, s16 depth) {
    info->unk6 = arg1;
    info->unk8 = arg2;
    info->depth = depth;
}

void zzSprite_setCE(InternalSpriteInfo* info, s16 arg1, s16 arg2) {
    info->unkC = arg1;
    info->unkE = arg2;
}

void zzSprite_setScales(InternalSpriteInfo* info, f32 scaleX, f32 scaleY) {
    info->scaleX = scaleX;
    info->scaleY = scaleY;
}

void zzSprite_setExp(InternalSpriteInfo* info, s16 expX, s16 expY) {
    info->expX = expX;
    info->expY = expY;
}

void zzSprite_setSprite(InternalSpriteInfo* info, Sprite* sp) {
    info->sp = sp;
}

void zzSprite_setBitmap(InternalSpriteInfo* info, Bitmap* bm) {
    info->bm = bm;
}

