#include "80550.h"

#include "zzSprite.h"
#include "global.h"

extern InternalSprite D_801D113C;
extern InternalSprite D_801D1170;
extern InternalSprite D_801D11A4;
extern InternalSprite D_801D11D8;
extern InternalSprite D_801D120C;
extern InternalSprite D_801D113C;

extern u16* D_800B6584;
extern u16* D_800B651C;
extern u16* D_800B65BC;
extern u16* D_800B6570;
extern u16* D_800B6574;
extern u16* D_800B656C;

extern u16 D_800F38E4;
extern u16 D_800F38C2;
extern u16 D_800F38C4;
extern u16 D_800B50C0;

extern u8* D_801D2270[0xA8];
extern u8* D_801D1138;
extern u8* D_801D116C;
extern u8* D_801D2800[0xA8];
extern u8* D_801D11A0;
extern u8* D_801D2D90[0xA8];
extern u8* D_801D3320[0xA8];
extern u8* D_801D11D4;

extern u8* D_801D3AE0[0x3F0];
extern u8* D_801D1208;

extern u8 D_800F395B; 

extern u8 D_800F38E1;

extern s32 D_800B6500;

extern u16* D_800B657C[];
extern u8 D_800F0630;

extern u16 D_8015A392;

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_800B6558_struct{
    s32 unk0;
    u8 unk4[0x10];
    u16* unk14;
}D_800B6558_struct;

extern D_800B6558_struct D_800B6558;

typedef struct D_800F3948_struct{
    u8 unk0[0x34];
    u32 unk34;
}D_800F3948_struct;

extern D_800F3948_struct* D_800F3948;

void func_8007F950() {

}

void func_8007F958(Gfx** gfxPtr){
    Gfx* gfx = *gfxPtr;
    
    func_80080F4C(&D_801D113C, 0, 5, *D_800B6584);

    if(!(D_800F38E4 & 0x20)){
        func_8007FE6C();
        D_801D1138 = &(&D_801D2270)[D_800F395B];
        zzSprite_drawSprite(&gfx, &D_801D113C);
    }
    
    func_80080F4C(&D_801D1170, 0, 5, *D_800B6584);

    if(!(D_800F38E4 & 0x40)){
        func_800810EC(&D_801D1170, D_800B651C, 0, 0, D_800F38C2);

        if(D_800F38C2 < 0xA){
            zzSprite_distCalc(&D_801D1170, D_800B6570, 3, 0);
        }
        else if(D_800F38C2 < 0x64){
            zzSprite_distCalc(&D_801D1170, D_800B6570, 2, 0);
        }
        else{
            zzSprite_distCalc(&D_801D1170, D_800B6570, 1, 0);
        }
        D_801D116C = &(&D_801D2800)[D_800F395B];

        zzSprite_drawSprite(&gfx, &D_801D1170);
    }

    func_80080F4C(&D_801D11A4, 0, 5, *D_800B6584);
    
    if(!(D_800F38E4 & 0x80)){
        func_800810EC(&D_801D11A4, D_800B651C, 0, 0, D_800F38C4);

        if(D_800F38C4 < 0xA){
            zzSprite_distCalc(&D_801D11A4, D_800B6574, 3, 0);
        }
        else if(D_800F38C4 < 0x64){
            zzSprite_distCalc(&D_801D11A4, D_800B6574, 2, 0);
        }
        else{
            zzSprite_distCalc(&D_801D11A4, D_800B6574, 1, 0);
        }
        D_801D11A0 = &(&D_801D2D90)[D_800F395B];

        zzSprite_drawSprite(&gfx, &D_801D11A4);
    }

    if(D_800B6500 > 0){
        D_800B6500--;
    }

    if(!(D_800F38E4 & 0x100) && D_800B6500 != 0){
        func_80080F4C(&D_801D11D8, 0, 5, *D_800B6584);
        zzSprite_distCalc(&D_801D11D8, D_800B657C[D_800F0630 % 2], 0, 0);
        D_801D11D4 = &(&D_801D3320)[D_800F395B];
        zzSprite_drawSprite(&gfx, &D_801D11D8);
    }

    *gfxPtr = gfx;
}

void func_8007FD00(Gfx** gfxPtr){
    Gfx* gfx = *gfxPtr;

    if(!(cdata.unk44 & 1)){
        func_8007F958(&gfx);
    }

    if(cdata.unk40 == 1 && (&D_800F3940)[cdata.unk41]->unk34 != 0 && D_8015A392 & 8){
        func_80010F48(&gfx);
    }

    if(D_800F3948->unk34 != 0 && D_8015A392 & 8){
        func_80080F4C(&D_801D120C, 0, 0x28, *D_800B6584);
        func_800810EC(&D_801D120C, D_800B651C, 0, 7, D_800B50C0);
        zzSprite_distCalc(&D_801D120C, D_800B65BC, 1, 7);
        D_801D1208 = &(&D_801D3AE0)[D_800F395B];
        zzSprite_drawSprite(&gfx, &D_801D120C);
        
    }

    *gfxPtr = gfx;
}

s32 func_8007FE60(s32* arg0) {
    *arg0 = *arg0;

    return *arg0;
}

void func_8007FE6C(){
    s32 unk74 = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->unk74;
    s8 i = 0;
    s8 j = 0;

    if(unk74 < 0){
        GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->unk74 = 0;
        unk74 = 0;
    }

    if (unk74 >= 0xFB) {
        unk74 = 0xFA;
    }

    func_80080F4C(&D_801D113C, 0, 5, *D_800B6558.unk14);



    while(unk74 > 0){
        zzSprite_distCalc(&D_801D113C, D_800B6558.unk0, i, 0);
        unk74 -= 0x32;  
        i++;
    }

    if(unk74 != 0){
        unk74 += 0x32;
        
        while(unk74 > 0){
            unk74 -= 0xA;
            j++;
        }
        zzSprite_distCalc(&D_801D113C, (&D_800B656C)[0-j], i-1, 0);

    }
}
