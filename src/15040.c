#include "15040.h"

#include "TexRec.h"

#pragma GLOBAL_ASM("asm/nonmatchings/15040/func_80014440.s")

void func_800144D4(Gfx** gfxPtr, Gfx* dl1, Gfx* dl2, u16* pal, s32 arg4, s32 w, s32 h, s32 x, s32 y, s32 pad,s32 pad2, u8 alpha,u8 arg12, u8 arg13){
    if(dl1!=NULL){
        gSPDisplayList(gfxPtr[0]++, dl1);
    }
    gDPSetPrimColor(gfxPtr[0]++, 0,0,255,255,255,alpha);

    if(arg4 == 0x14){
        if(arg13 & 0x10){
            gDPLoadTLUT_pal256(gfxPtr[0]++, pal);
            gDPSetTextureLUT(gfxPtr[0]++, G_TT_RGBA16);
        }
        if(arg13 & 1){
            gDPLoadTextureBlock(gfxPtr[0]++, dl2, G_IM_FMT_CI, G_IM_SIZ_8b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP,G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
    }
    else if(arg4 == 0x1E){
        if(arg13 & 0x10){
            gDPLoadTLUT_pal16(gfxPtr[0]++, 0, pal);
            gDPSetTextureLUT(gfxPtr[0]++, G_TT_RGBA16);
        }
        if(arg13 & 1){
            gDPLoadTextureBlock_4b(gfxPtr[0]++, dl2, G_IM_FMT_CI, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP,G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);            
        }
    }
    else if(arg13 & 1){
        gDPSetTextureLUT(gfxPtr[0]++, G_TT_NONE);

        gDPLoadTextureBlock(gfxPtr[0]++, dl2, G_IM_FMT_RGBA, G_IM_SIZ_16b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP,G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }
    if(arg12 & 2){
        gSPTextureRectangle(gfxPtr[0]++, x << 2, y << 2, (x + w) << 2, (y + h) << 2, 0, 0, (h-1) << 5, 1 << 10, -(1 << 10));
    }
    else if(arg12 & 1){
        gSPTextureRectangle(gfxPtr[0]++, x << 2, y << 2, (x + w) << 2, (y + h) << 2, 0, (w-1) << 5, 0, -(1 << 10), 1 << 10);

    }
    else if(arg12 & 4){
        gSPTextureRectangle(gfxPtr[0]++, x << 2, y << 2, (x + w) << 2, (y + h) << 2, 0, (w-1) << 5, (h-1) << 5, -(1 << 10), -(1 << 10));
    }
    else{
        gSPTextureRectangle(gfxPtr[0]++, x << 2, y << 2, (x + w) << 2, (y + h) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/15040/func_80014ECC.s")

void func_800151B4(TexRec* texRec, u8* arg1, u8* arg2, u16 amount){
    s32 i; 
    
    texRec->num = 0;
    texRec->amount = amount;
    texRec->unk4 = 0;
    texRec->unk8 = arg1;
    texRec->unkC = arg2;

    for(i = 0; i < texRec->amount; i++){
        texRec->unkC[i] = i;
    }
}

s16 func_80015200(TexRec* texRec, void** arg1){
    if(texRec->num == texRec->amount){
        return -1;
    }

    texRec->unk8[texRec->unkC[texRec->num]] = arg1;

    texRec->num++;

    return texRec->unkC[texRec->num-1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/15040/func_80015258.s")
