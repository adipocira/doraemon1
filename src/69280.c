#include "69280.h"
#include "actor.h"
#include "global.h"
#include "23B20.h"
#include "segments.h"
#include "11DF0.h"
#include "386E0.h"
#include "89D30.h"
#include "73660.h"
#include "7FC0.h"
#include "13940.h"
#include "9320.h"

#include "55270.h"

#define D_800E6B20_2022_sets(arg1, arg2) D_800E6B20.unk20 = (arg1);\
D_800E6B20.unk22 = (arg2)\

typedef struct D_801414A0_ptr_struct{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA[0x2];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    s32 unk48;
    s32 unk4C;
    u16 unk50;
    u16 unk52;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 unk60[0x80];
    Mtx mtx;
    u8 unk120[0x200];
    u8 unk320;
    u8 unk321;
    u8 unk322;
    u8 unk323;
    u8 unk324[0xC];
    f32 unk330;
    f32 unk334;
    f32 unk338;
    f32 unk33C;
    f32 unk340;
    f32 unk344;
    f32 unk348;
    f32 unk34C;
    f32 unk350;
}D_801414A0_ptr_struct;
extern D_801414A0_ptr_struct* D_801414A0[];

typedef struct D_800E6B20_struct {
    s16 unk0;
    s32 unk4;
    u8 unk8[0xE];
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B[0x5];
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26[0x3];
    u8 unk29;
    u8 unk2A[0x655D];
    u8 unk6587;
} D_800E6B20_struct;

extern D_800E6B20_struct D_800E6B20;

typedef struct D_800F9B08_struct{
    u8 unk0[0x4B8];
    u16 unk4B8;
    u8 unk4BA[0x382];
    u16 unk83C;
    u8 unk83E[0x292];
    u16 unkAD0;
    u8 unkAD2[0x3A];
    u16 unkB0C;
}D_800F9B08_struct; 

extern D_800F9B08_struct D_800F9B08;

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

extern s16 D_800FB340;

void func_80068680(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->flags |= 0x10;
            break;
        case 1:
            if(dist < 120.0f){
                func_80038F4C();
                D_800E6B20_2022_sets(0x20, 0xB0);
                func_800894B8(0x1E, 0xAE);

                if(func_80076FA0(0x47) != 0){
                    actor->status = 100;
                }
                else{
                    func_800073C0(0x37, 1);
                    actor->status = 101;
                }
            }
            break;
        case 100:
            if(dist < 60.0f && func_80012D40(0xA, 7, 0) == 0){
                func_80089A4C();
                actor2->flags &= ~0x4000;
                func_80038FA8();
                actor->status = 110;
            }
            break;
        case 101:
            if(func_80012D40(0xA, 8, 0) == 0){
                func_80089A4C();
                func_80038FA8();
                actor2->flags &= ~0x4000;
                actor->status = 111;
            }
            break;
        case 110:
            if(dist > 1600.0f){
                actor->status = 1;
            }
            break;
        case 111:
            break;
    }
}

void func_80068890(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;
    s16 i;
    Actor* actor2;
    
    if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 500.0F){
        if(actor->actorVars.varC0.integer == 0){
            actor->actorVars.varC0.integer = 1;
        }
    }

    switch(actor->status){
        case 1:
            break;
        case 0:
            id = func_80023498(8, 0x1C9, 1978.0f, 450.0f, -2502.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_80068680);
            }

            id = func_80023644(8, 0x69, -75.0f, -330.0f, 2431.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 3;
            }

            GET_ACTOR_PTR(idx)->actorVars.varC0.integer = 0;

            ROMCOPY(D_3B32F0, D_8020C820);

            GET_ACTOR_PTR(idx)->status = 1;
            break;
    }

    switch(D_800FB340){        
        default:
            {
                s16 temp = 0;
            }
            break;
        case 1:
            {
                
            s16 temp = 0;
                
            for(i = 0; i < 0x100; i++){
                actor2 = GET_ACTOR_PTR(i);

                if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x7E){
                    temp = 1; 
                    break;
                }
            }

            if(temp == 0){
                D_800F9B08.unkB0C &= ~0x1;
            }
            break;
            }
        case 4:
            {
            s16 temp = 0;
                
            for(i = 0; i < 0x100; i++){
                actor2 = GET_ACTOR_PTR(i);

                if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x7C){
                    temp = 1; 
                    break;
                }
            }

            if(temp == 0){
                D_800F9B08.unkAD0 &= ~0x1;
            }
            break;
            }


    }

    switch(actor->actorVars.varC0.integer){
        case 1:
            id = func_80023644(2, 0x1BD, 3319.0f, 451.0f, -2499.0f, 0.0f, 270.0f, 0.0f);
            actor->actorVars.varC8.integer = id;

            if(id != -1){
                id = func_80023644(2, 0x80, 3319.0f, 451.0f, -2620.0f, 0.0f, 270.0f, 0.0f);
                actor->actorVars.varCC.integer = id;

                if(actor->actorVars.varCC.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varCC.integer)->flags |= 0x10;
                }
                
                id = func_80023644(2, 0x80, 3314.0f, 451.0f, -2378.0f, 0.0f, 270.0f, 0.0f);
                actor->actorVars.varD0.integer = id;

                if(actor->actorVars.varD0.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varD0.integer)->flags |= 0x10;
                }

                id = func_80023644(2, 0x80, 3065.0f, 451.0f, -2504.0f, 0.0f, 270.0f, 0.0f);
                actor->actorVars.varD4.integer = id;

                if(actor->actorVars.varD4.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varD4.integer)->flags |= 0x10;
                }

                GET_ACTOR_PTR(actor->actorVars.varC8.integer)->unkF8 = idx;
                actor->actorVars.varC0.integer = 2;
            }
            break;
        case 0:
        case 3:
            break;
        case 2:
            if(cdata.unk38 == 0xE || cdata.unk38 == 0xF){
                if(actor->actorVars.varCC.integer != 1){
                    func_80023FCC(actor->actorVars.varCC.integer);
                }
                if(actor->actorVars.varD0.integer != 1){
                    func_80023FCC(actor->actorVars.varD0.integer);
                }
                if(actor->actorVars.varD4.integer != 1){
                    func_80023FCC(actor->actorVars.varD4.integer);
                }
                if(actor->actorVars.varC8.integer != 1){
                    func_80023FCC(actor->actorVars.varC8.integer);
                }

                actor->actorVars.varC0.integer = 0;
            }
            if(GET_ACTOR_PTR(actor->actorVars.varC8.integer)->actorVars.varC4.integer == 1){
                if(actor->actorVars.varCC.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varCC.integer)->flags &= ~0x10;
                    func_80022F20(actor->actorVars.varCC.integer, func_8005848C);
                }
                if(actor->actorVars.varD0.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varD0.integer)->flags &= ~0x10;
                    func_80022F20(actor->actorVars.varD0.integer, func_8005848C);
                }
                if(actor->actorVars.varD4.integer != -1){
                    GET_ACTOR_PTR(actor->actorVars.varD4.integer)->flags &= ~0x10;
                    func_80022F20(actor->actorVars.varD4.integer, func_8005848C);
                }

                actor->actorVars.varC0.integer = 3;
            }
            break;
    }
}
void func_80068F14(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s16 pad2;
    s16 temp = D_80159178->unk48[cdata.unk41].unk0;

    switch(actor->status){
        case 0:
            D_801414A0[actor->unk38 + 1]->unk30 = 300.0f; 
            D_801414A0[actor->unk38 + 2]->unk30 = 253.0f;

            if(actor->actorVars.varDC.integer != 0){
                func_800242F0(idx, 1, 0xFFFF);
                actor->unk72 = 0xF;
                actor->unk4C = actor->unk72;
            }
            else{
                actor->unk72 = 1;
                actor->unk4C = actor->unk72;
                func_800242F0(idx, 2, 0xFFFF);
                func_800242F0(idx, 3, 0xFFFF);
            }

            actor->status = 1;
            break;
        case 1:
            if(func_80024E0C(idx, temp) < 1600.0f && GET_ACTOR_PTR(temp)->pos.y > 40.0f){
                if(actor->actorVars.varDC.integer != 0){
                    func_80008E10(0xEB, 5, idx);
                }

                actor->status = 2;
            }
            break;
        case 2:
            actor->status = 3;
            actor->actorVars.varA0.fp = 300.0f;
            break;
        case 3:
            D_801414A0[actor->unk38 + 1]->unk30 = 360.0f - (actor->actorVars.varA0.fp * 60.0f) / 300.0f;
            D_801414A0[actor->unk38 + 2]->unk30 = actor->actorVars.varA0.fp * 28.0f / 300.0f + 225.0f;

            actor->actorVars.varA0.fp -= 1.0f;

            if(actor->actorVars.varA0.fp < 1.0f){
                actor->status = 4;
            }
            break;
        case 4:
            if(actor->actorVars.varDC.integer != 0){
                func_80008E10(0x63, 5, idx);
            }
            D_801414A0[actor->unk38 + 1]->unk30 = 0.0f;
            D_801414A0[actor->unk38 + 2]->unk30 = 225.0f;

            actor->status = 5;
            break;
        case 5:
            break;
    }
}
