#include "80550.h"

#include "zzSprite.h"
#include "actor.h"
#include "zzDebug.h"

#include "common.h"

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

extern s32 D_800B6500;

extern u16* D_800B657C[];
extern u8 D_800F0630;

extern u16 D_8015A392;

void func_8007F950() {

}

void func_8007F958(Gfx** gfxPtr){
    Gfx* gfx = *gfxPtr;
    
    func_80080F4C(&D_801D113C, 0, 5, *D_800B6584);

    if(!(cdata.unk44 & 0x20)){
        func_8007FE6C();
        D_801D1138 = &(&D_801D2270)[D_800F395B];
        zzSprite_drawSprite(&gfx, &D_801D113C);
    }
    
    func_80080F4C(&D_801D1170, 0, 5, *D_800B6584);

    if(!(cdata.unk44 & 0x40)){
        func_800810EC(&D_801D1170, D_800B651C, 0, 0, cdata.bells);

        if(cdata.bells < 10){
            zzSprite_distCalc(&D_801D1170, D_800B6570, 3, 0);
        }
        else if(cdata.bells < 100){
            zzSprite_distCalc(&D_801D1170, D_800B6570, 2, 0);
        }
        else{
            zzSprite_distCalc(&D_801D1170, D_800B6570, 1, 0);
        }

        D_801D116C = &(&D_801D2800)[D_800F395B];

        zzSprite_drawSprite(&gfx, &D_801D1170);
    }

    func_80080F4C(&D_801D11A4, 0, 5, *D_800B6584);
    
    if(!(cdata.unk44 & 0x80)){
        func_800810EC(&D_801D11A4, D_800B651C, 0, 0, cdata.lives);

        if(cdata.lives < 10){
            zzSprite_distCalc(&D_801D11A4, D_800B6574, 3, 0);
        }
        else if(cdata.lives < 100){
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

    if(!(cdata.unk44 & 0x100) && D_800B6500 != 0){
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

    if(cdata.unk40 == 1 && D_800F3940[cdata.unk41]->unk0.unk0[13] != 0 && D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_MG)){
        func_80010F48(&gfx);
    }

    if(D_800F3940[2]->unk0.unk0[13] != 0 && D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_MG)){
        func_80080F4C(&D_801D120C, NULL, 0x28, *D_800B6584);
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
    s32 health = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->health;
    s8 i = 0;
    s8 j = 0;

    if(health < 0){
        GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->health = 0;
        health = 0;
    }

    if (health >= 251) {
        health = 250;
    }

    func_80080F4C(&D_801D113C, 0, 5, *D_800B6558.unk14);

    while(health > 0){
        zzSprite_distCalc(&D_801D113C, D_800B6558.unk0, i, 0);
        health -= 50;  
        i++;
    }

    if(health != 0){
        health += 50;
        
        while(health > 0){
            health -= 10;
            j++;
        }

        zzSprite_distCalc(&D_801D113C, (&D_800B656C)[0-j], i-1, 0);
    }
}
