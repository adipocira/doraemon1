#include "6E50.h"

void func_80006250(Gfx** gfxPtr, _80006250_arg1* arg1, _80006250_arg2* arg2, Mtx* persp, Mtx* lookAt, u16* norm){
    Gfx* gfx = *gfxPtr;

    guPerspective(persp, norm, arg1->fovy, arg1->aspect, arg1->near, arg1->far, arg1->scale);
    guLookAt(lookAt, arg2->unk0 + arg2->unk24, arg2->unk4 + arg2->unk28, 
        arg2->unk8 + arg2->unk2C, arg2->unkC + arg2->unk30, arg2->unk10 + arg2->unk34,
        arg2->unk14 + arg2->unk38, arg2->unk18, arg2->unk1C, arg2->unk20);
    
    gSPMatrix(gfx++, OS_PHYSICAL_TO_K0(persp), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPMatrix(gfx++, OS_PHYSICAL_TO_K0(lookAt), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    gSPPerspNormalize(gfx++, *norm);

    *gfxPtr = gfx++;
}
