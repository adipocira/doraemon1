#include "789F0.h"
#include "global.h"
#include "actor.h"
#include "73660.h"
#include "78DE0.h"
#include "B4E0.h"
#include "23B20.h"
#include "9320.h"

typedef struct D_801591C0_struct_unk4{
    u8 unk0[0x8];
    s16 unk8;
    u8 unkA[0x4];
    s16 unkE;
}D_801591C0_struct_unk4;

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[2];
    D_801591C0_struct_unk4* unk4;
    u8 unk8[0x60];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

extern s16 D_800F062A;

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x2];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC;
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

typedef struct D_802BD4A8_struct{
    f32 unk0;
    u8 unk4[0x18];
}D_802BD4A8_struct;

extern D_802BD4A8_struct D_802BD4A8[];

extern s16 D_802BD67A[];

void func_80077DF0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    func_80073B80((&D_800F3940)[(s16)actor->unkC4.integer], &D_80159178->unk48[(s16)actor->unkC4.integer].unk4);
    func_80078064(idx);

    switch(actor->unkB8.shorts[0]){
        case 0:
            func_800784C8(actor);
            func_80074EE0(actor, idx);
            break;
        case 8:
            func_800784C8(actor);
            func_80075BD8(actor, idx);
            break;
        case 7:
            func_800784C8(actor);
            func_80075BD8(actor, idx);
            break;
        case 10:
            func_80078554(actor);
            break;
        case 11:
            func_8007835C(actor);
            break;
        case 15:
            if(actor->unkC4.shorts[0] == 0){
                func_80078F78(actor);

                if(actor->rot.x != 0.0f){
                    actor->rot.x = func_8000ADE0(actor->rot.x + 2.0f);
                }
            }

            func_800781E0(actor);
            break;
        case 12:
            if(func_80078F78(actor)){
                actor->unkB8.shorts[0] = 0xD;
                GET_ACTOR_PTR(GET_ACTOR(D_800F062A).unkA0.integer)->unkC8.integer |= 2;
            }
            else{
                if(actor->rot.x != 0.0f){
                    actor->rot.x = func_8000ADE0(actor->rot.x + 2.0f);
                }

                actor->rot.y = func_800253B0(idx, GET_ACTOR_PTR(D_800F062A)->unkA0.integer);
            }
            break;
    }

    func_800785CC(actor);
    func_80072FB0(actor);

    cdata.unk10 = actor->pos.x;
    cdata.unk14 = actor->pos.y;
    cdata.unk18 = actor->pos.z;
    
    if(actor->unkB8.shorts[0] != 0xD && actor->unkB8.shorts[0] != 0xC && actor->unkB8.shorts[0] != 0xF){
        actor->unkB4.fp = 0.0f;
        actor->unkB0.fp = 0.0f;
        actor->unkAC.fp = 0.0f;
    }

}

void func_80078064(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 v1;
    f32 f3;
    f32 ftemp;
    s32 pad[2];
    
    if(actor->unkB8.shorts[0] != 0xB && actor->unkB8.shorts[0] != 0xF && actor->unkB8.shorts[0] != 0xC && actor->unkB8.shorts[0] != 0xD
       &&  (actor->unkC0.shorts[1] == 0 || --actor->unkC0.shorts[1] == 0)){

        if(actor);
        
        v1 = D_80141CB0[idx].unk4;

        if(v1 == -1){
            v1 = D_80141CB0[idx].unkA;
        }
        if(v1 != -1){
            f3 = (D_802BD4A8)[actor->unk48].unk0;
            
            if(actor->unk74 != 0){
                ftemp = (f32)GET_ACTOR_PTR(v1)->unk66;
                actor->unk74 -= (GET_ACTOR_PTR(v1)->unk66 * f3);
            }
            if(actor->unk74 > 0){
                func_80008C6C(D_802BD67A[actor->unk48], 1);
                actor->unk52 = 0;
                actor->unk50 = actor->unk52;
                actor->unk6A = 0xA;
                actor->unkB8.shorts[0] = 0xA;
                actor->unkE8.shorts[0] = 3;
                actor->unkC0.shorts[1] = 0x46;
            }
            else{
                actor->unk74 = 0;
                actor->unkB8.shorts[0] = 0xB;
            }
        }
    }
}

