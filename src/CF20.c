#include "6C20.h"

#include "global.h"

void func_8000C320( Gfx** gfxPtr, s32 arg1, void* arg2, Gfx* dl1, Gfx* dl2){    
    gSPSegment(gfxPtr[0]++, G_MWO_SEGMENT_0, 0); 

    gSPSegment(gfxPtr[0]++, G_MWO_SEGMENT_2, osVirtualToPhysical(arg2));

    gSPDisplayList(gfxPtr[0]++, dl1);
    gSPDisplayList(gfxPtr[0]++, dl2);
    
    gSPClipRatio(gfxPtr[0]++, FRUSTRATIO_2);   
}

void func_8000C444(Gfx** gfxPtr){
    gDPFullSync(gfxPtr[0]++);
    
    gSPEndDisplayList(gfxPtr[0]++);

}

void func_8000C478(Gfx** gfxPtr, void* depthImgAddr, void* colourImageAddr){
    gDPSetDepthImage(gfxPtr[0]++, osVirtualToPhysical(depthImgAddr));
    
    gDPPipeSync(gfxPtr[0]++);

    gDPSetCycleType(gfxPtr[0]++, G_CYC_FILL);
    gDPSetColorImage(gfxPtr[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(depthImgAddr));
    gDPSetRenderMode(gfxPtr[0]++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gfxPtr[0]++, (GPACK_RGBA5551(255, 255, 240, 0) << 16) | GPACK_RGBA5551(255, 255, 240, 0));
    gDPFillRectangle(gfxPtr[0]++, 0, 0, 319, 239);

    gDPPipeSync(gfxPtr[0]++);

    gDPSetColorImage(gfxPtr[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320,  osVirtualToPhysical(colourImageAddr));
    gDPSetFillColor(gfxPtr[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(gfxPtr[0]++, 0, 0, 319, 239);
}

void func_8000C60C(Gfx** gfxPtr, void* imgAddr){
    gDPSetDepthImage(gfxPtr[0]++, osVirtualToPhysical(imgAddr));

    gDPPipeSync(gfxPtr[0]++);

    gDPSetCycleType(gfxPtr[0]++, G_CYC_FILL);
    gDPSetColorImage(gfxPtr[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(imgAddr));
    gDPSetRenderMode(gfxPtr[0]++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gfxPtr[0]++, (GPACK_RGBA5551(255, 255, 240, 0) << 16) | GPACK_RGBA5551(255, 255, 240, 0));
    gDPFillRectangle(gfxPtr[0]++, 0, 0, 319, 239);
}

void func_8000C71C(Gfx** gfxPtr, void* imgAddr, u16 colour){
    gDPPipeSync(gfxPtr[0]++);
    
    gDPSetColorImage(gfxPtr[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(imgAddr));


    if(D_800E69C0.unkE & 1){
        gDPSetFillColor(gfxPtr[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfxPtr[0]++, 0, 0, 319, 239);
        if(D_800E69C0.unkE & 2){
            gDPSetFillColor(gfxPtr[0]++, colour << 16 | colour);
            gDPFillRectangle(gfxPtr[0]++, 16, 12, 302, 226);
        }
    }
}

#ifdef NON_MATCHING
void func_8000C830(Gfx** gfxPtr, s32 near, s32 far, s32 r, s32 g, s32 b, s32 a){
    gSPFogFactor(gfxPtr[0]++, 128000 / (far - near), (-near * 256 + 128000) / (far - near));
    
    gDPSetFogColor(gfxPtr[0]++, r,g,b,a);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/CF20/func_8000C830.s")
#endif