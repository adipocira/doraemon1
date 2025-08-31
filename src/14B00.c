#include "global.h"

typedef struct D_801BAA80_struct{
    u16 unk0[4];
}D_801BAA80_struct;

typedef struct D_800F5FB0_struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    f32 unk14;
    f32 unk18;
    u16 unk1C[17];
    D_801BAA80_struct* unk40;
    u8 unk44;
    void* unk48;
}D_800F5FB0_struct;

extern D_800F5FB0_struct D_800F5FB0;
extern D_801BAA80_struct D_801BAA80;

void func_80013F00(D_800F5FB0_struct* arg0, void* arg1, D_801BAA80_struct* arg2){
    s32 i;
    
    arg0->unk48 = arg1;
    arg0->unk0 = 0;
    arg0->unk40 = arg2;

    for(i = 0; i < 16; i++){
        arg0->unk1C[i+1] = arg2->unk0[i];
    }

    if(arg0->unk1 == 0 || arg0->unk1 == 0x14){
        arg0->unk1 = 0x14;
        arg0->unk1C[0] = 1;
    } 
    else if(arg0->unk1 == 0xA){
        arg0->unk1C[0] = -1;
    }

    if(arg0->unk2 == 0 || arg0->unk2 == 1){
        arg0->unk2 = 1;
        arg0->unk44 = 0;
    }
    else{
        arg0->unk2 = 2;
        arg0->unk44 = 0xFF;        
    }

    if(arg0->unk8 == 0){
        arg0->unk8 = 1;
    }

    if(arg0->unkC == 0){
        arg0->unkC = 0x3c;
    }

    arg0->unk4 = 0;
    arg0->unk3 = 0;
}

void func_80013FE4(D_800F5FB0_struct* arg0){
    s32 i;
    s32 j;

    if(arg0->unk0 == 0){
        return;
    }
    
    if(arg0->unk0 != 3){
        if(arg0->unk0 == 1){
            if(arg0->unk2 == 1){
                if(arg0->unk1 == 0x32){
                    arg0->unk18 = arg0->unk12;
                }
                else{
                    arg0->unk18 = 255.0f;
                }
            }
            else{
                arg0->unk18 = 0.0f;
            }
            
            arg0->unk4 = 0;
            if(arg0->unk1 == 0x32){
                arg0->unk14 = (f32)arg0->unk12 / arg0->unkC;
            }
            else{
                arg0->unk14 = 255.0f / arg0->unkC;            
            }

            for(i = 0; i < 0x4; i++){
                for(j = 0; j < 4; j++){
                    u16* temp = arg0->unk40[i].unk0;

                    
                    arg0->unk40[i].unk0[j] = arg0->unk1C[0];
                }
                
            }
            arg0->unk0 = 2;
                
        }
        else{
            if(arg0->unk2 == 1){
                if((arg0->unk4+1 == arg0->unkC) || arg0->unk18 <= 0.0){
                    arg0->unk18 = 0.0f;
                }
                else {
                    arg0->unk18 -=arg0->unk14; 
                }
            }
            else if(arg0->unk1 == 0x32){
                if(arg0->unk4+1 == arg0->unkC || arg0->unk18 >= arg0->unk12){
                    arg0->unk18 = arg0->unk12;
                }
                else{
                    arg0->unk18 += arg0->unk14;
                }
            } else if((arg0->unk4+1 == arg0->unkC) || arg0->unk18 >= 255.0f){
                arg0->unk18 = 255.0f;
            } else {
                arg0->unk18 += arg0->unk14;
            }
            arg0->unk44 = arg0->unk18;
            
            if(arg0->unk4 >= arg0->unkC){
                arg0->unk4 = 0;
                
                if(arg0->unk2 == 2){
                    arg0->unk0 = 3;
                }
                else{
                    arg0->unk0 = 0;
                } 
            }

            arg0->unk4 += 1;
        }
        
    }
}

void func_80014358(Gfx** gfxPtr, D_800F5FB0_struct* arg1){
    
    if(arg1->unk0 != 0){
        gDPPipeSync(gfxPtr[0]++);
        gDPSetPrimColor(gfxPtr[0]++, 0, 0, 255, 255,255,arg1->unk44); 

        if (arg1->unk0 == 3 && arg1->unk1 != 0x32 && arg1->unk2 == 2) {
            gDPSetRenderMode(gfxPtr[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
        }
        else{
            gDPSetRenderMode(gfxPtr[0]++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        }
        gSPDisplayList(gfxPtr[0]++, arg1->unk48);
    }
}
