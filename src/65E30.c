#include "65E30.h"
#include "global.h"
#include "actor.h"
#include "9320.h"
#include "11F10.h"

extern u16 D_800F3950;
extern u16 D_800F3952;

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

void func_80065230(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    static s32 D_801590C0;
    static s32 D_801590C4;
    static s32 D_801590C8;
    static s32 D_801590CC;

    (void)"PATH1 = %d\n";
    (void)"PATH2 = %d\n";

    switch(actor->status){
        case 0:
            D_801590C4 = 0;
            D_801590C0 = 0;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(actor2->pos.y < -200.0f){
                D_800F5FB0.unk1C[0] = 0xFFFF;
                D_800F5FB0_sets(0x14,2,1);
                GET_ACTOR_PTR(idx)->status = 2;
            }
            switch(D_801590C0){
                case 0:
                    func_80008C6C(2, 4);
                    D_801590C0 = func_80011528(0) % 8U;
                    D_801590C8 = 0;
                    break;
                case 1:
                    if(D_801590C8 > 400){
                        D_801590C0 = 0;
                    }
                    else{
                        D_801590C8++;
                    }
                    break;
                case 2:
                    if(D_801590C8 > 350){
                        D_801590C0 = 0;
                    }
                    else{
                        D_801590C8++;
                    }
                    break;
                case 3:
                    if(D_801590C8 > 320){
                        D_801590C0 = 0;
                    }
                    else{
                        D_801590C8++;
                    }
                    break;
                case 4:
                    if(D_801590C8 > 300){
                        D_801590C0 = 0;
                    }
                    else{
                        D_801590C8++;
                    }
                    break;
                default:
                    if(D_801590C8 > 430){
                        D_801590C0 = 0;
                    }
                    else{
                        D_801590C8++;
                    }
                    break;
            }            
            switch(D_801590C4){
                case 0:
                    func_80008C6C(2, 5);
                    D_801590C4 = func_80011528(0) % 8U;
                    D_801590CC = 0;
                    break;
                case 1:
                    if(D_801590CC > 400){
                        D_801590C4 = 0;
                    }
                    else{
                        D_801590CC++;
                    }
                    break;
                case 2:
                    if(D_801590CC > 350){
                        D_801590C4 = 0;
                    }
                    else{
                        D_801590CC++;
                    }
                    break;
                case 3:
                    if(D_801590CC > 320){
                        D_801590C4 = 0;
                    }
                    else{
                        D_801590CC++;
                    }
                    break;
                case 4:
                    if(D_801590CC > 300){
                        D_801590C4 = 0;
                    }
                    else{
                        D_801590CC++;
                    }
                    break;
                default:
                    if(D_801590CC > 350){
                        D_801590C4 = 0;
                    }
                    else{
                        D_801590CC++;
                    }
                    break;
            }
            break;
        case 2:
            if (D_800F5FB0.unk0 == 3) {
                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;
                cdata.unk42 = 0;
                D_800F3950 = 0xD;
                D_800F3952 = 1;
                GET_ACTOR_PTR(idx)->status = 3;
            }            
            break;
        case 3:
            break;
    }
}

