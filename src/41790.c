#include "41790.h"

#include "11F10.h"
#include "73660.h"
#include "23B20.h"
#include "55270.h"
#include "9320.h"
#include "29980.h"
#include "15F60.h"
#include "2DE50.h"
#include "B4E0.h"
#include "1D870.h"

#include "libc/math.h"
#include "actor.h"
 
typedef struct D_800F9910_struct {
    u8 unk0;
    u8 unk1;
    u16 unk2; 
    u16 unk4;
    f32 unk8; 
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    
    /* todo more*/
}D_800F9910_struct;

extern D_800F9910_struct D_800F9910;

typedef struct func_80040BD8_struct_actor{
    u8 unk0[0x34];
    f32 unk34;
    s32 unk38;
    f32 unk3C;
    f32 unk40;
}func_80040BD8_struct_actor;

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

typedef struct D_801414A0_struct{
    u8 unk0[0x8];
    void* unk8;
    void* unkC;
    void* unk10;
}D_801414A0_struct;

extern D_801414A0_ptr_struct* D_801414A0[];

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x6];
    s16 unk8;
    u8 unkA[0x3];
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
}D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

extern f32 D_80159170;

void func_80040B90(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->status = 1;
            break;
        case 1:
            break;
    }
}

void func_80040BD8(s16 idx){
    s16 temp;
    f32 temp4;
    f32 temp8;
    f32 temp7;
    f32 temp6;
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp2;
    f32 temp5;
    f32 temp3;

    if(actor->unk38 != 0xFFFF){
        D_801414A0_ptr_struct **tmp = &D_801414A0[actor->unk38];
        actor->actorVars.varBC.ptr = tmp[2];\
        actor->actorVars.varC0.ptr = tmp[3];\
        actor->actorVars.varC4.ptr = tmp[4];\
        
        switch(actor->status){
            case 0:
                actor->a = 100;
                actor->actorVars.varD8.fp = actor->actorVars.varB4.integer;
                actor->actorVars.varDC.fp = -(f32)actor->actorVars.varB8.integer * 0.05;
                actor->actorVars.varC8.fp = func_80011528(0) % 360U;
                actor->actorVars.varCC.fp = 0.0f;
                actor->actorVars.varD0.integer = 0xC8;
                actor->actorVars.varD4.integer = -1;

                if(actor->actorVars.varD8.fp == 0.0f){
                    actor->actorVars.varD8.fp = 2.0f;
                }

                if(actor->actorVars.varDC.fp == 0.0f){
                    actor->actorVars.varDC.fp = -0.3f;
                }
            
                actor->status = 1;
                break;
            case 1:
                temp3 = 0.0f;
                temp = func_80024CA0(0, idx, 200.0f);
            
                if(temp != -1){
                    temp2 = func_80074E68(actor->rot.y, func_800253B0(idx, temp)) / 60.0f;

                    actor->rot.y += temp2;

                NORM_ANGLE(actor->rot.y);
                    
                if(temp2 < 1.0f && -0.1 < temp2 && actor->actorVars.varCC.fp > 0.0f){
                        temp3 = 1.0f;
                    }
                }

                actor->actorVars.varC8.fp += 3.0f;

                NORM_ANGLE(actor->actorVars.varC8.fp);

                temp4 = sinf(actor->actorVars.varC8.fp * 6.28 / 180.0) ;
                temp8 = sinf((actor->actorVars.varC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp7 = sinf(actor->actorVars.varC8.fp * 3.14 / 180.0) ;
                temp6 = sinf((actor->actorVars.varC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp5 = (1.0f - temp4) * 0.04 + 1.0;

                func_800248A4(idx, temp5, temp5, temp5);

                ((func_80040BD8_struct_actor*)(actor->actorVars.varBC.ptr))->unk3C = temp4 * 0.05 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC0.ptr))->unk3C = temp4 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC0.ptr))->unk40 = temp7 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC0.ptr))->unk34 = temp4 * 5.0f;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC4.ptr))->unk3C = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC4.ptr))->unk40 = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->actorVars.varC4.ptr))->unk34 = temp6 * 5.0f;
                
                actor->actorVars.varD0.integer += actor->actorVars.varD4.integer;

                if(actor->actorVars.varCC.fp > 0.0f){
                    actor->actorVars.varCC.fp *= 0.95;

                    if(actor->actorVars.varCC.fp < 0.1){
                        actor->actorVars.varCC.fp = 0.0f;
                    }
                }
                else{
                    actor->actorVars.varCC.fp -= 0.01;

                    if(actor->actorVars.varCC.fp < actor->actorVars.varDC.fp){
                        actor->actorVars.varCC.fp = actor->actorVars.varDC.fp;
                    }
                }

                if(actor->actorVars.varD0.integer <= 0){
                    actor->actorVars.varD0.integer = func_80011528(0) % 120U + 0x78;
                    actor->actorVars.varCC.fp = actor->actorVars.varD8.fp;
                }

                func_80024FC8(idx, temp3, actor->actorVars.varCC.fp);
                func_8002507C(idx);
                func_8002513C(actor);

                switch(actor->actorVars.varB4.integer & 7U){
                    case 1:
                        actor->pos.x -= actor->dir.x;
                        actor->pos.z -= actor->dir.z;
                        break;
                    case 4:
                        actor->actorVars.varD0.integer = 0;
                        actor->actorVars.varD4.integer = -1;
                        actor->actorVars.varCC.fp = actor->actorVars.varD8.fp;
                        
                        break;
                    case 2:
                        actor->actorVars.varCC.fp = 0.0f;
                        actor->actorVars.varD0.integer = func_80011528(0) % 120U + 0x78;
                        actor->actorVars.varD4.integer = 0;
                        break;
                }
                break; 
        }
    }
}

void func_80041268(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    
    s16 id;


    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x1F;
            func_80022F48(idx, 1);
            actor->status = 1;
            break;
        case 1:
            func_80022F48(idx, 1);
            actor->actorVars.varA0.integer = 0x64;
            actor->actorVars.varA8.fp = func_80011528(0) & 360U;
            actor->dir.x = 0.0f;
            actor->status = 2;
            actor->dir.y = 0.0f;
            actor->dir.z = 0.0f;
            actor->actorVars.varA4.fp = 0.0f;
            break;
        case 2:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA0.integer <= 0){
                actor->actorVars.varA8.fp = func_80011528(0) & 360U;            
                actor->actorVars.varA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(actor, actor->actorVars.varA8.fp, 40.0f);
            
            actor->actorVars.varA4.fp += 0.04;

            if(actor->actorVars.varA4.fp > 1.0f){
                actor->status = 3;
            }

            func_80024F20(idx, -0.5f);
            actor->dir.y = actor->actorVars.varA4.fp;
            func_80059760(actor);
            break;
        case 3:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA0.integer <= 0){
                actor->actorVars.varA8.fp = func_80011528(0) & 360U;            
                actor->actorVars.varA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(actor, actor->actorVars.varA8.fp, 40.0f);
            
            actor->actorVars.varA4.fp -= 0.04;

            if(actor->actorVars.varA4.fp < -1.0f){
                actor->status = 2;
            }

            func_80024F20(idx, -0.5f);
            actor->dir.y = actor->actorVars.varA4.fp;
            func_80059760(actor);
            break;
        case 10:
            actor->actorVars.varA0.integer = 0x1E;
            actor->status = 11;
            break;
        case 11:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA0.integer <= 0){
                func_80008E10(0x51, 2, idx);
                actor->actorVars.varA0.integer = 0x20;
                actor->status = 12;
            }

            func_80025454(actor, actor1, 16.0f);
            break;
        case 12:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--; 

            if(GET_ACTOR_PTR(idx)->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 0x1F4;
                actor->status = 13;
            }
            func_80025454(actor, actor1, 16.0f);
            func_80024FC8(idx, -1.0f, 0.0f);
            func_80059760(actor);

            if(actor->actorVars.varA0.integer & 1){
                id = func_80023644(6, 0x183, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->flags |= 0x1000;
                    func_80022F20(id, func_8002C3AC);
                    func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y, 30.0f, 5.0f);
                    func_80024874(id, 0.2f);
                }
            }
        case 13:
            func_80022F48(idx, 1);

            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA0.integer <= 0){
                actor->status = 1;
                actor->actorVars.varA4.fp = 0.0f;
            }

            func_80025454(actor, actor1, 16.0f);
            func_80024FC8(idx, -actor->actorVars.varA4.fp, 0.0f);
            func_80059760(actor);

            if(temp < 300.0f){
                actor->actorVars.varA4.fp = 5.0f;
            }

            if(actor->actorVars.varA4.fp > 0.0f){
                actor->actorVars.varA4.fp -= 0.01;
            }
        break;
        
    }

    if(temp < 300.0f){
        if(actor->status > 0 && actor->status < 3){
            actor->status = 10;
        }
    }


}

void func_80041790(s16 idx){
    s32 pad;
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x20;
            func_80022F48(idx, 0);
            actor->status = 1;
            break;
        case 1:
            break;
    }
}

void func_80041808(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1;
    f32 temp;
    s16 temp3;
    
    NORM_ANGLE(actor->rot.y);

    func_8002513C(actor);

    switch(actor->status){
        case 0:
            actor->actorVars.varBC.integer = 0;
            actor->actorVars.varC0.integer = 0;
            actor->actorVars.varC4.fp = 0.0f;
            actor->actorVars.varC8.fp = 0.0f;
            actor->actorVars.varCC.fp = func_80011528(0) % 360U;
            actor->actorVars.varD0.integer = func_80011528(0) % 400U + 0x1F4;
            actor->status = 1;
            
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(actor->actorVars.varDC.integer == 0){
                actor->actorVars.varD4.integer = func_80024CA0(0, idx, 300.0f);

                if(actor->actorVars.varD4.integer != -1){
                    actor1 = GET_ACTOR_PTR(actor->actorVars.varD4.integer);
                    
                    if(actor->pos.y - 20.0f < actor1->pos.y && actor1->pos.y < actor->pos.y + 50.0f){
                        actor->status = 2;
                        actor->actorVars.varDC.integer = 0x1F4;
                    }
                }
            }
            temp3 = (func_80011528(0) % 12U - 6);
            
            if(temp3 > 0){
                actor->actorVars.varBC.integer++;
            }

            if(actor->actorVars.varBC.integer >= 0x5B){
                actor->actorVars.varBC.integer = 0;
                actor->actorVars.varC0.integer = 0x5A;
                actor->actorVars.varC4.fp = 1.0f;
            }

            if(actor->actorVars.varC0.integer != 0){
                temp = actor->actorVars.varC4.fp;
                actor->actorVars.varC0.integer--;
            }
            else {
                temp = actor->actorVars.varC4.fp;
                if(actor->actorVars.varC4.fp > 0.0f) {
                    actor->actorVars.varC4.fp -= -0.002;
                }
            }
            
            temp -= 0.05;
            func_80024FC8(idx, temp, 0.0f);
                
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, 0.0f, actor->dir.z);

            if(D_800F9910.unk1 != 0){
                if(actor->actorVars.varC8.fp == 0.0f){
                    actor->actorVars.varB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->actorVars.varA8.fp - actor->pos.z, actor->actorVars.varA0.fp - actor->pos.x));
                    actor->actorVars.varC8.fp = actor->actorVars.varB8.fp / (func_80011528(0) % 5U + 1);
                }

                actor->pos.x = D_800F9910.unkC;
                actor->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
            }
            
            break;
        case 2:
            temp = func_80074E68(actor->rot.y, func_800253B0(idx, actor->actorVars.varD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                actor->status = 3;
                actor->actorVars.varD8.integer = 0x32;
            }

            actor->rot.y += temp * 0.1;
            actor->actorVars.varC4.fp *= 0.9;
            break;
        case 3:
            actor->actorVars.varD8.integer--;

            if(actor->actorVars.varD8.integer <= 0){
                actor->actorVars.varBC.integer = 0;
                actor->actorVars.varC0.integer = 0xA;
                actor->actorVars.varC4.fp = 3.0f;
                func_80008E10(0x53, 2, idx);
                actor->status = 1;
            }
            break;
        
    }

    if(actor->actorVars.varDC.integer != 0){
        actor->actorVars.varDC.integer--;
    }

    actor->actorVars.varD0.integer--;

    if(actor->actorVars.varD0.integer <= 0){
        actor->actorVars.varD0.integer = (func_80011528(0) % 400U) + 0x1F4;

        if(actor->actorVars.varC8.fp == 0.0f){
            actor->actorVars.varC8.fp = func_80011528(0) % 180U;
        }
    }

    actor->actorVars.varCC.fp += 3.0f;

    NORM_ANGLE(actor->actorVars.varCC.fp);

    if(actor->actorVars.varC8.fp != 0.0f){
        actor->actorVars.varC8.fp = func_80025374(idx, actor->actorVars.varC8.fp, 0.05);

        if(actor->actorVars.varC8.fp < 10.0f && actor->actorVars.varC8.fp > -10.0f){
            actor->actorVars.varC8.fp = 0.0f;
        }
    }
    else{
        actor->rot.y += sinf((actor->actorVars.varCC.fp * 3.14) / 180.0)  * 0.3;
    }

    actor->pos.y += cosf((actor->actorVars.varCC.fp * 3.14) / 180.0)  * 0.2;
 
    switch(actor->actorVars.varB4.integer & 7){
        case 1:
            if(actor->actorVars.varC8.fp == 0.0f){
               actor->actorVars.varC8.fp = actor->actorVars.varB8.fp / (func_80011528(0) % 5U + 1);
            }
            break;
        case 2:
        case 4: 
            break; 
    }
}

void func_80042040(s16 idx){
    
    switch(GET_ACTOR_PTR(idx)->actorVars.varA0.integer){
        case 0:
            func_80022F20(idx, func_800420A4);
            func_800420A4(idx); 
            break;
        case 1:
            break;
    }
}

void func_800420A4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    switch(actor->status){
        case 0:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                actor->actorVars.varB0.fp *= 0.1;
                actor->actorVars.varB4.fp *= 0.1;
                actor->status = 1;
            }

            actor->actorVars.varB8.integer = 0;
            actor->flags |= 0x2000;
            break;
        case 1:
            actor->actorVars.varB8.integer += 8;

            if(actor->actorVars.varB8.integer >= 0x100){
                actor->actorVars.varB8.integer = 0xFF;
                actor->status = 2;
            }
            break;
        case 2:
            GET_ACTOR_PTR(idx)->actorVars.varA8.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA8.integer <= 0){
                GET_ACTOR_PTR(idx)->actorVars.varA8.integer = 0x78;
                actor->status = 3;
            }

            func_80024FC8(idx, actor->actorVars.varAC.fp, 0.0f);
            func_8002507C(idx);
            
            break;
        case 3:
            GET_ACTOR_PTR(idx)->actorVars.varA8.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA8.integer <= 0){
                GET_ACTOR_PTR(idx)->actorVars.varA8.integer = 0x12C;
                actor->status = 4;
            }

            func_80025454(actor, actor1, 8.0f);

            actor->dir.x *= 0.98;
            actor->dir.z *= 0.98;
            actor->pos.x += actor->dir.x;
            actor->pos.z += actor->dir.z;
            
            
            break;
        case 4:
            GET_ACTOR_PTR(idx)->actorVars.varA8.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varA8.integer <= 0){
                actor->status = 5;
            }
            func_80025454(actor, actor1, 16.0f);
            func_8002592C(actor, actor1, actor->actorVars.varB0.fp, actor->actorVars.varB4.fp);
            func_80024F20(idx, actor->actorVars.varAC.fp);
            func_8002507C(idx);
            break;
        case 5:
            actor->actorVars.varB8.integer -= 8;

            if(actor->actorVars.varB8.integer < 0){
                actor->actorVars.varB8.integer = 0;
                func_80023FCC(idx);
                return;
            }
            else{
                func_8002507C(idx);
            }
            break;
    }

    actor->a = actor->actorVars.varB8.integer;
    D_801414A0[actor->unk38 + 2]->unk38 += 30.0f;

    NORM_ANGLE(D_801414A0[actor->unk38 + 2]->unk38);
}

void func_80042418(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            actor->unk8 = 0x53F;
            actor->unk4E = 2;
            actor->unk6C = 0x23;
            func_80022F48(idx, 0);
            actor->actorVars.varA4.integer = 10;

            if(actor->pos.x < 0.0f){
                actor->actorVars.varAC.fp = -((s32)actor->pos.x % 600);
            }
            else{
                actor->actorVars.varAC.fp = ((s32)actor->pos.x % 600);
            }

            actor->status = 10;
            
            break;
        case 10:
            if(temp < 100.0f){
                actor->actorVars.varA8.fp = 4.0f;
                actor->actorVars.varA4.integer = 0x3C;
                func_80008E10(0x55, 2, idx);
                actor->status = 11;
            }

            actor->actorVars.varAC.fp += 1.0f;

            if(actor->actorVars.varAC.fp > 500.0f){
                actor->actorVars.varA4.integer = 0x64;
                actor->unk8 = 0;
                actor->actorVars.varAC.fp = 0.0f;
                func_80022F48(idx, 2);
                actor->status = 14;
            }
            break;
        case 11:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                actor->unk8 = 0;
                func_80022F48(idx, 1);
                actor->status = 12;
            }
            func_80025454(actor, actor1, 24.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, actor->actorVars.varA8.fp);
            actor->actorVars.varA8.fp -= D_80159170 * 0.666;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                actor->actorVars.varA4.integer = 0x3C;
                func_80022F48(idx, 0);
                actor->status = 13;
            }
            break;
        case 13:
            actor->unk8 = 0x53F;
            actor->actorVars.varA4.integer--;
             

            if(actor->actorVars.varA4.integer <= 0){
                actor->status = 10;
            }
            break;
        case 14:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                func_80022F48(idx, 0);
                actor->unk8 = 0x53F;
                actor->status = 10;
            }
            break;

    }
}

void func_80042758(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(actor->status){
        case 0:
            actor->actorVars.varD4.fp = actor->actorVars.varB4.fp;
            actor->actorVars.varD8.fp = actor->actorVars.varB8.fp;
            actor->actorVars.varDC.fp = actor->actorVars.varBC.fp;
            actor->actorVars.varC0.fp = 1.0f;
            actor->actorVars.varC4.fp = 0.9f;
            actor->actorVars.varC8.fp = 0.05f;
            actor->actorVars.varCC.fp = 32.0f;
            actor->actorVars.varD0.fp = 200.0f;
            actor->actorVars.varE0.fp = actor->scale.x;
            actor->actorVars.varE4.integer = 0x1E;
            actor->status = 1; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(func_80024CA0(0, idx, 50.0f) != -1){
                actor->actorVars.varE4.integer = 0xF;
                actor->status = 2;
            }
            func_80021B90(idx);
            break;
        case 2:
            actor->actorVars.varE4.integer--;

            if(actor->actorVars.varE4.integer >= 2){
                actor->scale.x += 0.4;
                actor->scale.z += 0.4;
                actor->scale.y += 0.4;
            }
            else{
                actor->status = 3;
            }
            break;
        case 3:
            if(func_80024CA0(0, idx, 100.0f) != -1){
                func_80021B90(idx);
            }
            else{
                func_80008E10(0x59, 2, idx);
                actor->actorVars.varE4.integer = 0x14;
                actor->status = 4;
            }
            break;
        case 4:
            actor->actorVars.varE4.integer--;

            if(actor->actorVars.varE4.integer >= 2){
                actor->scale.x -= 0.2;
                actor->scale.z -= +0.2;
                actor->scale.y -= 0.2;
            }
            else{
                actor->status = 1;

                actor->scale.x = actor->actorVars.varE0.fp;
                actor->scale.z = actor->actorVars.varE0.fp;
                actor->scale.y = actor->actorVars.varE0.fp;
            } 
            break;
    }
}

void func_80042A38(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;
    f32 temp1;

    switch(actor->status){
        case 0:
            switch(actor->actorVars.varA0.integer){
                case 0:
                    func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y + 5.0f, actor->pos.z, -300.0f);

                    if(D_800F9910.unk0 != 0){
                        actor->pos.y = D_800F9910.unk10 + 0.5;
                        actor->rot.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->rot.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->actorVars.varBC.fp = D_800F9910.unk18;
                        actor->actorVars.varC0.fp = D_800F9910.unk1C;
                        actor->actorVars.varC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        actor->actorVars.varBC.fp = 0.0f;
                        actor->actorVars.varC0.fp = 1.0f;
                        actor->actorVars.varC4.fp = 0.0f;
                        
                    }
                    break;
                case 1:
                    func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y - 5.0f, actor->pos.z, 300.0f);
                    
                    if(D_800F9910.unk0 != 0){
                        actor->pos.y = D_800F9910.unk10 - 0.5;
                        actor->rot.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->rot.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?

                        actor->actorVars.varBC.fp = D_800F9910.unk18;
                        actor->actorVars.varC0.fp = D_800F9910.unk1C;
                        actor->actorVars.varC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        actor->actorVars.varBC.fp = 0.0f;
                        actor->actorVars.varC0.fp = -1.0f;
                        actor->actorVars.varC4.fp = 0.0f;
                        
                    }                    
                    break;
            }

            actor->actorVars.varC8.fp = func_80011528(0) % 360U;
            actor->actorVars.varA4.fp = actor->scale.x;
            actor->actorVars.varB4.integer = 0;
            
            actor->status = 1;
            
            break;
        case 1:
            actor->actorVars.varC8.fp += 5.0f;

            NORM_ANGLE(actor->actorVars.varC8.fp);

            actor->scale.x = sinf((actor->actorVars.varC8.fp * 6.28) / 180.0) * 0.05 + (f64)actor->actorVars.varA4.fp;
            actor->scale.z = sinf((actor->actorVars.varC8.fp * 6.28) / 180.0) * 0.05 + (f64)actor->actorVars.varA4.fp; 
            actor->scale.y = cosf((actor->actorVars.varC8.fp * 3.14) / 180.0) * 0.08 + (f64)actor->actorVars.varA4.fp; 
 
            if(actor->actorVars.varB4.integer != 0){
                actor->actorVars.varB4.integer--;
            }

            if(actor->actorVars.varB4.integer == 0){
                actor->actorVars.varA8.integer = func_80024CA0(0, idx, 300.0f);

                if(actor->actorVars.varA8.integer != -1){
                    actor->actorVars.varAC.fp = 0.0f;
                    actor->actorVars.varB0.fp = 0.0f;
                    actor->actorVars.varB8.fp = 0.05f;
                    actor->status = 2;
                     
                }
            }
            
            break;
        case 2:
            actor->actorVars.varAC.fp += actor->actorVars.varB8.fp;
            actor->actorVars.varB8.fp -= 0.001;

            if(actor->actorVars.varAC.fp > 1.0f){
                actor->actorVars.varB0.fp = actor->actorVars.varAC.fp; 

                id = func_80023644(2, 0x70, actor->actorVars.varBC.fp * 10.0f + actor->pos.x, actor->actorVars.varC0.fp * 10.0f + actor->pos.y, actor->actorVars.varC4.fp * 10.0f + actor->pos.z, 0.0f, 0.0f, 0.0f); 
                func_80008E10(0x54, 2, idx);
                
                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA4.fp = actor->actorVars.varBC.fp;
                    GET_ACTOR_PTR(id)->actorVars.varA8.fp = actor->actorVars.varC0.fp;
                    GET_ACTOR_PTR(id)->actorVars.varAC.fp = actor->actorVars.varC4.fp;
                    
                }
                actor->status = 3;

            } 
            func_800248A4(idx, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp, actor->actorVars.varB0.fp + actor->actorVars.varA4.fp, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp);
            
            break;
        case 3: 
            actor->actorVars.varAC.fp-= 0.02;

            if(actor->actorVars.varAC.fp < 0.03){
                actor->status = 4;
            }

            func_800248A4(idx, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp, actor->actorVars.varB0.fp + actor->actorVars.varA4.fp, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp);
            break;
        case 4:
            actor->actorVars.varB0.fp -= 0.012;
    
            if(actor->actorVars.varB0.fp < 0.03){
                actor->actorVars.varB4.integer = 0x1F4;
                actor->status = 1;
            } 
            
            func_800248A4(idx, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp, actor->actorVars.varB0.fp + actor->actorVars.varA4.fp, actor->actorVars.varAC.fp + actor->actorVars.varA4.fp);
            
            break;
    }
} 


void func_8004312C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    

    if(D_80141CB0[idx].unk8 != -1){
        func_80022F20(idx, func_8002D7AC); 
        func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

        return;
    }

    if(D_80141CB0[idx].unk0 != -1){
        func_80023FCC(idx);
        func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

        return;
    }


    switch(actor->status){ 
        case 0:
            actor->actorVars.varA0.integer = 0x1F4;
            actor->rot.z = -(DEG2RAD(90) - func_8000AE70(actor->actorVars.varA8.fp / sqrtf(1.0f - SQ(actor->actorVars.varA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            actor->rot.y = -func_8000B038(actor->actorVars.varAC.fp, actor->actorVars.varA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            func_8002524C(idx, actor->actorVars.varA4.fp, actor->actorVars.varA8.fp, actor->actorVars.varAC.fp); 
            actor->status = 1;
            break;
        case 1:
            actor->actorVars.varB0.integer = func_80024CA0(0, idx, 300.0f);

            if(actor->actorVars.varB0.integer != -1){
                actor->actorVars.varB4.integer = 0x78;
                actor->actorVars.varB8.ptr = GET_ACTOR_PTR(actor->actorVars.varB0.integer);
                actor->status = 2;                     
            }         
            func_8002507C(idx);
             
            break;
        case 2:
            GET_ACTOR_PTR(idx)->actorVars.varB4.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varB4.integer == 0){
                actor->status = 3;
            }
            
            func_8002507C(idx);
            break;
        case 3:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer != 0){
                if(actor->pos.x < ((Actor*)(actor->actorVars.varB8.ptr))->pos.x){
                    actor->actorVars.varA4.fp += 0.3;
                }
                else{
                    actor->actorVars.varA4.fp -= 0.3;
                }
                
                if(actor->pos.y < ((Actor*)(actor->actorVars.varB8.ptr))->pos.y + 25.0f){
                    actor->actorVars.varA8.fp += 0.3;
                }
                else{
                    actor->actorVars.varA8.fp -= 0.3;
                }
                if(actor->pos.z < ((Actor*)(actor->actorVars.varB8.ptr))->pos.z){
                    actor->actorVars.varAC.fp += 0.3;
                }
                else{
                    actor->actorVars.varAC.fp -= 0.3; 
                }  

                func_80025E14(&actor->actorVars.varA4.fp, &actor->actorVars.varA8.fp, &actor->actorVars.varAC.fp); 
                actor->rot.z = -(DEG2RAD(90) - func_8000AE70(actor->actorVars.varA8.fp / sqrtf(1.0f - SQ(actor->actorVars.varA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                actor->rot.y = -func_8000B038(actor->actorVars.varAC.fp, actor->actorVars.varA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                func_8002524C(idx, actor->actorVars.varA4.fp, actor->actorVars.varA8.fp, actor->actorVars.varAC.fp); 
                func_8002507C(idx);
            }
            else{
                func_80023FCC(idx);
                func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

            }
            break;
    }
}


void func_800435A0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1;
    f32 temp;
    f32 temp3;
    s16 temp2; 
    
    NORM_ANGLE(actor->rot.y);

    switch(actor->status){
        case 0:
            actor->actorVars.varBC.integer = 0;
            actor->actorVars.varC0.integer = 0;
            actor->actorVars.varC4.fp = 0.0f;
            actor->actorVars.varC8.fp = 0.0f;
            actor->actorVars.varCC.fp = func_80011528(0) % 360U;
            actor->actorVars.varD0.integer = func_80011528(0) % 400U + 0x1F4;
            
            actor->actorVars.varE0.fp = 0.01f;
            actor->actorVars.varE4.integer = func_80011528(0) % 400U + 0x64;
            actor->status = 1;
            actor->actorVars.varE8.fp = 0.0f; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(actor->actorVars.varDC.integer == 0){
                actor->actorVars.varD4.integer = func_80024CA0(0, idx, 400.0f);
                
                
                if(actor->actorVars.varD4.integer != -1){
                    actor1 = GET_ACTOR_PTR(actor->actorVars.varD4.integer);
                    if(actor->pos.y - 50.0f < actor1->pos.y && actor1->pos.y < (actor->pos.y + 80.0f)){
                        actor->status = 2;
                        actor->actorVars.varDC.integer = 0x190;
                    }
                }
            }

            actor->actorVars.varE4.integer--;

            if(actor->actorVars.varE4.integer <= 0){
                actor->actorVars.varE4.integer = func_80011528(0) % 400U + 0x64;
                actor->actorVars.varE0.fp *= -1.0f;
            }

            actor->actorVars.varE8.fp += actor->actorVars.varE0.fp;

            if(actor->actorVars.varE8.fp > 0.5){
                actor->actorVars.varE8.fp = 0.5;
            }
            if(actor->actorVars.varE8.fp < -0.5){
                actor->actorVars.varE8.fp = -0.5;
            }

            temp2 = func_80011528(0) % 12U - 6;
            
            if(temp2 > 0){
                actor->actorVars.varBC.integer++;
            }            

            if(actor->actorVars.varBC.integer >= 0x5B){
                actor->actorVars.varBC.integer = 0;
                actor->actorVars.varC0.integer = 0x5A;
                actor->actorVars.varC4.fp = 2.0f;
            }

            if(actor->actorVars.varC0.integer != 0){
                temp3 = actor->actorVars.varC4.fp;
                actor->actorVars.varC0.integer--;
            }
            else {
                temp3 = actor->actorVars.varC4.fp;
                if((actor->actorVars.varC4.fp) > 0.0f) {
                    actor->actorVars.varC4.fp -= -0.002; 
                }
            }

             
            temp3 -= 0.05;
            func_80024FC8(idx, temp3, actor->actorVars.varE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            if(D_800F9910.unk1 != 0){
                if(actor->actorVars.varC8.fp == 0.0f){
                    actor->actorVars.varB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->actorVars.varA8.fp - actor->pos.z, actor->actorVars.varA0.fp - actor->pos.x));
                    actor->actorVars.varC8.fp = actor->actorVars.varB8.fp / (func_80011528(0) % 5U + 1);
                }

                actor->pos.x = D_800F9910.unkC; 
                actor->pos.y = D_800F9910.unk10;
                actor->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
                func_8002513C(actor);
            }
            break;
        case 2:
            temp = func_80074E68(actor->rot.y, func_800253B0(idx, actor->actorVars.varD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                actor->status = 3;
                actor->actorVars.varD8.integer = 0xA;
            }

            actor->rot.y += temp * 0.2;
            temp3 = actor->actorVars.varC4.fp;
            func_80024FC8(idx, temp3, actor->actorVars.varE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            if(D_800F9910.unk1 != 0){
                if(actor->actorVars.varC8.fp == 0.0f){
                    actor->actorVars.varB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->actorVars.varA8.fp - actor->pos.z, actor->actorVars.varA0.fp - actor->pos.x));
                    actor->actorVars.varC8.fp = actor->actorVars.varB8.fp / (func_80011528(0) % 5U + 1);
                }

                actor->pos.x = D_800F9910.unkC; 
                actor->pos.y = D_800F9910.unk10;
                actor->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
                func_8002513C(actor);
            }
            break;
        case 3:
            actor->actorVars.varD8.integer--;
            
            if(actor->actorVars.varD8.integer <= 0){
                actor->actorVars.varBC.integer = 0;
                actor->actorVars.varC0.integer = 0xA;
                actor->actorVars.varC4.fp = 4.0f;

                if(GET_ACTOR(actor->actorVars.varD4.integer).pos.y + 25.0f < actor->pos.y + 34.0f){
                    actor->actorVars.varE0.fp = -0.01;
                    actor->actorVars.varE8.fp *= 0.5;
                }
                else if(actor->pos.y < GET_ACTOR(actor->actorVars.varD4.integer).pos.y + 25.0f ){
                    actor->actorVars.varE0.fp = 0.01;
                    actor->actorVars.varE8.fp *= 0.5;                    
                }

                actor->status = 1;
            }
            
            break;
    }

        if(actor->actorVars.varB4.integer & 6){
            if(actor->actorVars.varB0.fp + actor->actorVars.varA4.fp < actor->pos.y){
                actor->pos.y = actor->actorVars.varB0.fp + actor->actorVars.varA4.fp;
            }

            if(actor->pos.y < actor->actorVars.varA4.fp){
                actor->pos.y = actor->actorVars.varA4.fp;
            }
        }

        if(actor->actorVars.varDC.integer != 0){
            actor->actorVars.varDC.integer--;
        }

        actor->actorVars.varD0.integer--;

        if(actor->actorVars.varD0.integer <= 0){
            actor->actorVars.varD0.integer = func_80011528(0) % 400U + 0x1F4;

            if(actor->actorVars.varC8.fp == 0.0f){
                actor->actorVars.varC8.fp = func_80011528(0) % 180U;
            }
        }

        actor->actorVars.varCC.fp += 3.0f;

        NORM_ANGLE(actor->actorVars.varCC.fp);

        if(actor->actorVars.varC8.fp != 0.0f){
            actor->actorVars.varC8.fp = func_80025374(idx, actor->actorVars.varC8.fp, 0.05f);

            if(actor->actorVars.varC8.fp < 10.0f && actor->actorVars.varC8.fp > -10.0f){
                actor->actorVars.varC8.fp = 0.0f;
            }
        }

        switch(actor->actorVars.varB4.integer & 7){
            case 1:
                if(actor->actorVars.varC8.fp == 0.0f){
                    actor->actorVars.varC8.fp = actor->actorVars.varB8.fp / (f32)(func_80011528(0) % 5U + 1);
                }
                break;
            case 2:
                if(actor->actorVars.varE8.fp > 0.0f){
                    actor->actorVars.varE8.fp *= 0.5;
                    actor->actorVars.varE0.fp = -0.01;
                }
                break;
            case 4:
                
                if(actor->actorVars.varE8.fp < 0.0f){
                    actor->actorVars.varE8.fp *= 0.5;
                    actor->actorVars.varE0.fp = 0.01;
                }
                break;
        
    }
}
