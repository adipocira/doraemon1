#include "66EB0.h"
#include "global.h"
#include "actor.h"
#include "23B20.h"
#include "73660.h"

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

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

#define D_800E6B20_2022_sets(arg1, arg2) D_800E6B20.unk20 = (arg1);\
D_800E6B20.unk22 = (arg2)\

void func_800662B0(s16 idx){
    Actor* actor;
    Actor* actor2;
    f32 dist;
    s16 id;

    actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    actor = GET_ACTOR_PTR(idx);

    (void)" KAIZOKU NEZUMI SLEEP\n";
    (void)" KAIZOKU NEZUMI CHASE\n";
    (void)" KAIZOKU NEZUMI IN THE HOME\n";
    (void)" KAIZOKU NEZUMI NO ITEM\n";
     
    switch(actor->status){
        case 0:
            actor->pos.x = 43.0f;
            actor->pos.y = 201.0f;
            actor->pos.z = 1693.0f;

            id = func_80023644(8 , 0x81, 3511.0f, 531.0f, -3690.0f, 0.0f, 356.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->unk68 = 0x44;
            }

            actor->actorVars.varA0.integer = 0;

            if(func_80076FA0(0x17) == 0){
                GET_ACTOR_PTR(idx)->status = 200;
            }
            else{
                if(func_80076FA0(0x29) == 0){
                    GET_ACTOR_PTR(idx)->status = 150;
                }
                else{
                    if(func_80076FA0(0x44) == 0){
                        GET_ACTOR_PTR(idx)->status = 100;
                    }
                    else{
                        GET_ACTOR_PTR(idx)->status = 50;
                    }
                }
            }
            break;
        case 50:
            id = func_80023644(8, 0x62, 3689.0f, 501.0f, -3452.0f, 0.0f, 317.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 8;
            }
            
            GET_ACTOR_PTR(idx)->status = 51;
            break;
        case 51:
            if(func_80076FA0(0x44) == 0){
                GET_ACTOR_PTR(idx)->status = 100;
            }
            if(actor->actorVars.varA0.integer == 1){
                D_800E6B20_2022_sets(0x4B, 0xB7);

                GET_ACTOR_PTR(idx)->status = 52;
            }
            break;
        case 52:
            if(func_80012D40(4, 0, 1) == 0){
                actor2->flags &= ~0x4000;
                GET_ACTOR_PTR(idx)->status = 51;
            }
            break;
        case 100:
            id = func_80023644(2, 0x60, 770.0f, 106.0f, 1374.0f, 0.0f, 315.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 1;
            }

            GET_ACTOR_PTR(idx)->status = 101;
            break;
        case 101:
            if(actor->actorVars.varA0.integer == 1){
                D_800E6B20_2022_sets(0x4B, 0xB7);

                GET_ACTOR_PTR(idx)->status = 102;
            }
            break;
        case 102:
            if(func_80012D40(4, 2, 1) == 0){
                actor2->flags &= ~0x4000;
                GET_ACTOR_PTR(idx)->status = 103;
            }
            break;
        case 103:
            if(func_80024CA0(4, idx, 100.0f) != -1){
                D_800F9B08.unkAD0 &= ~1;
                GET_ACTOR_PTR(idx)->status = 104;
            }
            break;
        case 104:
            break;
        case 150:
            id = func_80023644(2, 0x60, 3725.0f, 526.0f, -3678.0f, 0.0f, 321.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 2;
            }

            GET_ACTOR_PTR(idx)->status = 151;
            
            break;
        case 151:
            break;
        case 200:
            id = func_80023644(8, 0x81, 3372.0f, 501.0f, -3716.0f, 0.0f, 3.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->unk68 = 0x17;
            }

            id = func_80023644(2, 0x60, 3725.0f, 526.0f, -3678.0f, 0.0f, 321.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 3;
            }

            GET_ACTOR_PTR(idx)->status = 201;
            break;
        case 201:
            break;
    }

    if(dist < 30.0f){
        actor->actorVars.varA0.integer++;

        if(actor->actorVars.varA0.integer > 2){
            actor->actorVars.varA0.integer = 2;
        }
    }
    else{
        actor->actorVars.varA0.integer = 0;
    }
}

void func_80066850(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->status = 1;
            break;
        case 1:
            break;
    }
}

