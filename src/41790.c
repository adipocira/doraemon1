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
    u8 unk0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
}D_801414A0_ptr_struct; 

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
    u8 unk8[0x24];
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
        actor->unkBC.ptr = tmp[2];\
        actor->unkC0.ptr = tmp[3];\
        actor->unkC4.ptr = tmp[4];\
        
        switch(actor->status){
            case 0:
                actor->unk8B = 0x64;
                actor->unkD8.fp = actor->unkB4.integer;
                actor->unkDC.fp = -(f32)actor->unkB8.integer * 0.05;
                actor->unkC8.fp = func_80011528(0) % 360U;
                actor->unkCC.fp = 0.0f;
                actor->unkD0.integer = 0xC8;
                actor->unkD4.integer = -1;

                if(actor->unkD8.fp == 0.0f){
                    actor->unkD8.fp = 2.0f;
                }

                if(actor->unkDC.fp == 0.0f){
                    actor->unkDC.fp = -0.3f;
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
                    
                if(temp2 < 1.0f && -0.1 < temp2 && actor->unkCC.fp > 0.0f){
                        temp3 = 1.0f;
                    }
                }

                actor->unkC8.fp += 3.0f;

                NORM_ANGLE(actor->unkC8.fp);

                temp4 = sinf(actor->unkC8.fp * 6.28 / 180.0) ;
                temp8 = sinf((actor->unkC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp7 = sinf(actor->unkC8.fp * 3.14 / 180.0) ;
                temp6 = sinf((actor->unkC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp5 = (1.0f - temp4) * 0.04 + 1.0;

                func_800248A4(idx, temp5, temp5, temp5);

                ((func_80040BD8_struct_actor*)(actor->unkBC.ptr))->unk3C = temp4 * 0.05 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->unkC0.ptr))->unk3C = temp4 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->unkC0.ptr))->unk40 = temp7 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->unkC0.ptr))->unk34 = temp4 * 5.0f;
                ((func_80040BD8_struct_actor*)(actor->unkC4.ptr))->unk3C = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->unkC4.ptr))->unk40 = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_actor*)(actor->unkC4.ptr))->unk34 = temp6 * 5.0f;
                
                actor->unkD0.integer += actor->unkD4.integer;

                if(actor->unkCC.fp > 0.0f){
                    actor->unkCC.fp *= 0.95;

                    if(actor->unkCC.fp < 0.1){
                        actor->unkCC.fp = 0.0f;
                    }
                }
                else{
                    actor->unkCC.fp -= 0.01;

                    if(actor->unkCC.fp < actor->unkDC.fp){
                        actor->unkCC.fp = actor->unkDC.fp;
                    }
                }

                if(actor->unkD0.integer <= 0){
                    actor->unkD0.integer = func_80011528(0) % 120U + 0x78;
                    actor->unkCC.fp = actor->unkD8.fp;
                }

                func_80024FC8(idx, temp3, actor->unkCC.fp);
                func_8002507C(idx);
                func_8002513C(actor);

                switch(actor->unkB4.integer & 7U){
                    case 1:
                        actor->pos.x -= actor->unk58;
                        actor->pos.z -= actor->unk60;
                        break;
                    case 4:
                        actor->unkD0.integer = 0;
                        actor->unkD4.integer = -1;
                        actor->unkCC.fp = actor->unkD8.fp;
                        
                        break;
                    case 2:
                        actor->unkCC.fp = 0.0f;
                        actor->unkD0.integer = func_80011528(0) % 120U + 0x78;
                        actor->unkD4.integer = 0;
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
            actor->unkA0.integer = 0x64;
            actor->unkA8.fp = func_80011528(0) & 360U;
            actor->unk58 = 0.0f;
            actor->status = 2;
            actor->unk5C = 0.0f;
            actor->unk60 = 0.0f;
            actor->unkA4.fp = 0.0f;
            break;
        case 2:
            GET_ACTOR_PTR(idx)->unkA0.integer--;

            if(GET_ACTOR_PTR(idx)->unkA0.integer <= 0){
                actor->unkA8.fp = func_80011528(0) & 360U;            
                actor->unkA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(actor, actor->unkA8.fp, 40.0f);
            
            actor->unkA4.fp += 0.04;

            if(actor->unkA4.fp > 1.0f){
                actor->status = 3;
            }

            func_80024F20(idx, -0.5f);
            actor->unk5C = actor->unkA4.fp;
            func_80059760(actor);
            break;
        case 3:
            GET_ACTOR_PTR(idx)->unkA0.integer--;

            if(GET_ACTOR_PTR(idx)->unkA0.integer <= 0){
                actor->unkA8.fp = func_80011528(0) & 360U;            
                actor->unkA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(actor, actor->unkA8.fp, 40.0f);
            
            actor->unkA4.fp -= 0.04;

            if(actor->unkA4.fp < -1.0f){
                actor->status = 2;
            }

            func_80024F20(idx, -0.5f);
            actor->unk5C = actor->unkA4.fp;
            func_80059760(actor);
            break;
        case 10:
            actor->unkA0.integer = 0x1E;
            actor->status = 11;
            break;
        case 11:
            GET_ACTOR_PTR(idx)->unkA0.integer--;

            if(GET_ACTOR_PTR(idx)->unkA0.integer <= 0){
                func_80008E10(0x51, 2, idx);
                actor->unkA0.integer = 0x20;
                actor->status = 12;
            }

            func_80025454(actor, actor1, 16.0f);
            break;
        case 12:
            GET_ACTOR_PTR(idx)->unkA0.integer--; 

            if(GET_ACTOR_PTR(idx)->unkA0.integer <= 0){
                actor->unkA0.integer = 0x1F4;
                actor->status = 13;
            }
            func_80025454(actor, actor1, 16.0f);
            func_80024FC8(idx, -1.0f, 0.0f);
            func_80059760(actor);

            if(actor->unkA0.integer & 1){
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

            GET_ACTOR_PTR(idx)->unkA0.integer--;

            if(GET_ACTOR_PTR(idx)->unkA0.integer <= 0){
                actor->status = 1;
                actor->unkA4.fp = 0.0f;
            }

            func_80025454(actor, actor1, 16.0f);
            func_80024FC8(idx, -actor->unkA4.fp, 0.0f);
            func_80059760(actor);

            if(temp < 300.0f){
                actor->unkA4.fp = 5.0f;
            }

            if(actor->unkA4.fp > 0.0f){
                actor->unkA4.fp -= 0.01;
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
            actor->unkBC.integer = 0;
            actor->unkC0.integer = 0;
            actor->unkC4.fp = 0.0f;
            actor->unkC8.fp = 0.0f;
            actor->unkCC.fp = func_80011528(0) % 360U;
            actor->unkD0.integer = func_80011528(0) % 400U + 0x1F4;
            actor->status = 1;
            
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(actor->unkDC.integer == 0){
                actor->unkD4.integer = func_80024CA0(0, idx, 300.0f);

                if(actor->unkD4.integer != -1){
                    actor1 = GET_ACTOR_PTR(actor->unkD4.integer);
                    
                    if(actor->pos.y - 20.0f < actor1->pos.y && actor1->pos.y < actor->pos.y + 50.0f){
                        actor->status = 2;
                        actor->unkDC.integer = 0x1F4;
                    }
                }
            }
            temp3 = (func_80011528(0) % 12U - 6);
            
            if(temp3 > 0){
                actor->unkBC.integer++;
            }

            if(actor->unkBC.integer >= 0x5B){
                actor->unkBC.integer = 0;
                actor->unkC0.integer = 0x5A;
                actor->unkC4.fp = 1.0f;
            }

            if(actor->unkC0.integer != 0){
                temp = actor->unkC4.fp;
                actor->unkC0.integer--;
            }
            else {
                temp = actor->unkC4.fp;
                if(actor->unkC4.fp > 0.0f) {
                    actor->unkC4.fp -= -0.002;
                }
            }
            
            temp -= 0.05;
            func_80024FC8(idx, temp, 0.0f);
                
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, 0.0f, actor->unk60);

            if(D_800F9910.unk1 != 0){
                if(actor->unkC8.fp == 0.0f){
                    actor->unkB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->unkA8.fp - actor->pos.z, actor->unkA0.fp - actor->pos.x));
                    actor->unkC8.fp = actor->unkB8.fp / (func_80011528(0) % 5U + 1);
                }

                actor->pos.x = D_800F9910.unkC;
                actor->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
            }
            
            break;
        case 2:
            temp = func_80074E68(actor->rot.y, func_800253B0(idx, actor->unkD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                actor->status = 3;
                actor->unkD8.integer = 0x32;
            }

            actor->rot.y += temp * 0.1;
            actor->unkC4.fp *= 0.9;
            break;
        case 3:
            actor->unkD8.integer--;

            if(actor->unkD8.integer <= 0){
                actor->unkBC.integer = 0;
                actor->unkC0.integer = 0xA;
                actor->unkC4.fp = 3.0f;
                func_80008E10(0x53, 2, idx);
                actor->status = 1;
            }
            break;
        
    }

    if(actor->unkDC.integer != 0){
        actor->unkDC.integer--;
    }

    actor->unkD0.integer--;

    if(actor->unkD0.integer <= 0){
        actor->unkD0.integer = (func_80011528(0) % 400U) + 0x1F4;

        if(actor->unkC8.fp == 0.0f){
            actor->unkC8.fp = func_80011528(0) % 180U;
        }
    }

    actor->unkCC.fp += 3.0f;

    NORM_ANGLE(actor->unkCC.fp);

    if(actor->unkC8.fp != 0.0f){
        actor->unkC8.fp = func_80025374(idx, actor->unkC8.fp, 0.05);

        if(actor->unkC8.fp < 10.0f && actor->unkC8.fp > -10.0f){
            actor->unkC8.fp = 0.0f;
        }
    }
    else{
        actor->rot.y += sinf((actor->unkCC.fp * 3.14) / 180.0)  * 0.3;
    }

    actor->pos.y += cosf((actor->unkCC.fp * 3.14) / 180.0)  * 0.2;
 
    switch(actor->unkB4.integer & 7){
        case 1:
            if(actor->unkC8.fp == 0.0f){
               actor->unkC8.fp = actor->unkB8.fp / (func_80011528(0) % 5U + 1);
            }
            break;
        case 2:
        case 4: 
            break; 
    }
}

void func_80042040(s16 idx){
    
    switch(GET_ACTOR_PTR(idx)->unkA0.integer){
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
            actor->unkA4.integer--;

            if(actor->unkA4.integer <= 0){
                actor->unkB0.fp *= 0.1;
                actor->unkB4.fp *= 0.1;
                actor->status = 1;
            }

            actor->unkB8.integer = 0;
            actor->flags |= 0x2000;
            break;
        case 1:
            actor->unkB8.integer += 8;

            if(actor->unkB8.integer >= 0x100){
                actor->unkB8.integer = 0xFF;
                actor->status = 2;
            }
            break;
        case 2:
            GET_ACTOR_PTR(idx)->unkA8.integer--;

            if(GET_ACTOR_PTR(idx)->unkA8.integer <= 0){
                GET_ACTOR_PTR(idx)->unkA8.integer = 0x78;
                actor->status = 3;
            }

            func_80024FC8(idx, actor->unkAC.fp, 0.0f);
            func_8002507C(idx);
            
            break;
        case 3:
            GET_ACTOR_PTR(idx)->unkA8.integer--;

            if(GET_ACTOR_PTR(idx)->unkA8.integer <= 0){
                GET_ACTOR_PTR(idx)->unkA8.integer = 0x12C;
                actor->status = 4;
            }

            func_80025454(actor, actor1, 8.0f);

            actor->unk58 *= 0.98;
            actor->unk60 *= 0.98;
            actor->pos.x += actor->unk58;
            actor->pos.z += actor->unk60;
            
            
            break;
        case 4:
            GET_ACTOR_PTR(idx)->unkA8.integer--;

            if(GET_ACTOR_PTR(idx)->unkA8.integer <= 0){
                actor->status = 5;
            }
            func_80025454(actor, actor1, 16.0f);
            func_8002592C(actor, actor1, actor->unkB0.fp, actor->unkB4.fp);
            func_80024F20(idx, actor->unkAC.fp);
            func_8002507C(idx);
            break;
        case 5:
            actor->unkB8.integer -= 8;

            if(actor->unkB8.integer < 0){
                actor->unkB8.integer = 0;
                func_80023FCC(idx);
                return;
            }
            else{
                func_8002507C(idx);
            }
            break;
    }

    actor->unk8B = actor->unkB8.integer;
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
            actor->unkA4.integer = 10;

            if(actor->pos.x < 0.0f){
                actor->unkAC.fp = -((s32)actor->pos.x % 600);
            }
            else{
                actor->unkAC.fp = ((s32)actor->pos.x % 600);
            }

            actor->status = 10;
            
            break;
        case 10:
            if(temp < 100.0f){
                actor->unkA8.fp = 4.0f;
                actor->unkA4.integer = 0x3C;
                func_80008E10(0x55, 2, idx);
                actor->status = 11;
            }

            actor->unkAC.fp += 1.0f;

            if(actor->unkAC.fp > 500.0f){
                actor->unkA4.integer = 0x64;
                actor->unk8 = 0;
                actor->unkAC.fp = 0.0f;
                func_80022F48(idx, 2);
                actor->status = 14;
            }
            break;
        case 11:
            actor->unkA4.integer--;

            if(actor->unkA4.integer <= 0){
                actor->unk8 = 0;
                func_80022F48(idx, 1);
                actor->status = 12;
            }
            func_80025454(actor, actor1, 24.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, actor->unkA8.fp);
            actor->unkA8.fp -= D_80159170 * 0.666;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                actor->unkA4.integer = 0x3C;
                func_80022F48(idx, 0);
                actor->status = 13;
            }
            break;
        case 13:
            actor->unk8 = 0x53F;
            actor->unkA4.integer--;
             

            if(actor->unkA4.integer <= 0){
                actor->status = 10;
            }
            break;
        case 14:
            actor->unkA4.integer--;

            if(actor->unkA4.integer <= 0){
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
            actor->unkD4.fp = actor->unkB4.fp;
            actor->unkD8.fp = actor->unkB8.fp;
            actor->unkDC.fp = actor->unkBC.fp;
            actor->unkC0.fp = 1.0f;
            actor->unkC4.fp = 0.9f;
            actor->unkC8.fp = 0.05f;
            actor->unkCC.fp = 32.0f;
            actor->unkD0.fp = 200.0f;
            actor->unkE0.fp = actor->unk90.x;
            actor->unkE4.integer = 0x1E;
            actor->status = 1; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(func_80024CA0(0, idx, 50.0f) != -1){
                actor->unkE4.integer = 0xF;
                actor->status = 2;
            }
            func_80021B90(idx);
            break;
        case 2:
            actor->unkE4.integer--;

            if(actor->unkE4.integer >= 2){
                actor->unk90.x += 0.4;
                actor->unk90.z += 0.4;
                actor->unk90.y += 0.4;
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
                actor->unkE4.integer = 0x14;
                actor->status = 4;
            }
            break;
        case 4:
            actor->unkE4.integer--;

            if(actor->unkE4.integer >= 2){
                actor->unk90.x -= 0.2;
                actor->unk90.z -= +0.2;
                actor->unk90.y -= 0.2;
            }
            else{
                actor->status = 1;

                actor->unk90.x = actor->unkE0.fp;
                actor->unk90.z = actor->unkE0.fp;
                actor->unk90.y = actor->unkE0.fp;
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
            switch(actor->unkA0.integer){
                case 0:
                    func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y + 5.0f, actor->pos.z, -300.0f);

                    if(D_800F9910.unk0 != 0){
                        actor->pos.y = D_800F9910.unk10 + 0.5;
                        actor->rot.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->rot.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->unkBC.fp = D_800F9910.unk18;
                        actor->unkC0.fp = D_800F9910.unk1C;
                        actor->unkC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        actor->unkBC.fp = 0.0f;
                        actor->unkC0.fp = 1.0f;
                        actor->unkC4.fp = 0.0f;
                        
                    }
                    break;
                case 1:
                    func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y - 5.0f, actor->pos.z, 300.0f);
                    
                    if(D_800F9910.unk0 != 0){
                        actor->pos.y = D_800F9910.unk10 - 0.5;
                        actor->rot.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        actor->rot.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?

                        actor->unkBC.fp = D_800F9910.unk18;
                        actor->unkC0.fp = D_800F9910.unk1C;
                        actor->unkC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        actor->unkBC.fp = 0.0f;
                        actor->unkC0.fp = -1.0f;
                        actor->unkC4.fp = 0.0f;
                        
                    }                    
                    break;
            }

            actor->unkC8.fp = func_80011528(0) % 360U;
            actor->unkA4.fp = actor->unk90.x;
            actor->unkB4.integer = 0;
            
            actor->status = 1;
            
            break;
        case 1:
            actor->unkC8.fp += 5.0f;

            NORM_ANGLE(actor->unkC8.fp);

            actor->unk90.x = sinf((actor->unkC8.fp * 6.28) / 180.0) * 0.05 + (f64)actor->unkA4.fp;
            actor->unk90.z = sinf((actor->unkC8.fp * 6.28) / 180.0) * 0.05 + (f64)actor->unkA4.fp; 
            actor->unk90.y = cosf((actor->unkC8.fp * 3.14) / 180.0) * 0.08 + (f64)actor->unkA4.fp; 
 
            if(actor->unkB4.integer != 0){
                actor->unkB4.integer--;
            }

            if(actor->unkB4.integer == 0){
                actor->unkA8.integer = func_80024CA0(0, idx, 300.0f);

                if(actor->unkA8.integer != -1){
                    actor->unkAC.fp = 0.0f;
                    actor->unkB0.fp = 0.0f;
                    actor->unkB8.fp = 0.05f;
                    actor->status = 2;
                     
                }
            }
            
            break;
        case 2:
            actor->unkAC.fp += actor->unkB8.fp;
            actor->unkB8.fp -= 0.001;

            if(actor->unkAC.fp > 1.0f){
                actor->unkB0.fp = actor->unkAC.fp; 

                id = func_80023644(2, 0x70, actor->unkBC.fp * 10.0f + actor->pos.x, actor->unkC0.fp * 10.0f + actor->pos.y, actor->unkC4.fp * 10.0f + actor->pos.z, 0.0f, 0.0f, 0.0f); 
                func_80008E10(0x54, 2, idx);
                
                if(id != -1){
                    GET_ACTOR_PTR(id)->unkA4.fp = actor->unkBC.fp;
                    GET_ACTOR_PTR(id)->unkA8.fp = actor->unkC0.fp;
                    GET_ACTOR_PTR(id)->unkAC.fp = actor->unkC4.fp;
                    
                }
                actor->status = 3;

            } 
            func_800248A4(idx, actor->unkAC.fp + actor->unkA4.fp, actor->unkB0.fp + actor->unkA4.fp, actor->unkAC.fp + actor->unkA4.fp);
            
            break;
        case 3: 
            actor->unkAC.fp-= 0.02;

            if(actor->unkAC.fp < 0.03){
                actor->status = 4;
            }

            func_800248A4(idx, actor->unkAC.fp + actor->unkA4.fp, actor->unkB0.fp + actor->unkA4.fp, actor->unkAC.fp + actor->unkA4.fp);
            break;
        case 4:
            actor->unkB0.fp -= 0.012;
    
            if(actor->unkB0.fp < 0.03){
                actor->unkB4.integer = 0x1F4;
                actor->status = 1;
            } 
            
            func_800248A4(idx, actor->unkAC.fp + actor->unkA4.fp, actor->unkB0.fp + actor->unkA4.fp, actor->unkAC.fp + actor->unkA4.fp);
            
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
            actor->unkA0.integer = 0x1F4;
            actor->rot.z = -(DEG2RAD(90) - func_8000AE70(actor->unkA8.fp / sqrtf(1.0f - SQ(actor->unkA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            actor->rot.y = -func_8000B038(actor->unkAC.fp, actor->unkA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            func_8002524C(idx, actor->unkA4.fp, actor->unkA8.fp, actor->unkAC.fp); 
            actor->status = 1;
            break;
        case 1:
            actor->unkB0.integer = func_80024CA0(0, idx, 300.0f);

            if(actor->unkB0.integer != -1){
                actor->unkB4.integer = 0x78;
                actor->unkB8.ptr = GET_ACTOR_PTR(actor->unkB0.integer);
                actor->status = 2;                     
            }         
            func_8002507C(idx);
             
            break;
        case 2:
            GET_ACTOR_PTR(idx)->unkB4.integer--;

            if(GET_ACTOR_PTR(idx)->unkB4.integer == 0){
                actor->status = 3;
            }
            
            func_8002507C(idx);
            break;
        case 3:
            actor->unkA0.integer--;

            if(actor->unkA0.integer != 0){
                if(actor->pos.x < ((Actor*)(actor->unkB8.ptr))->pos.x){
                    actor->unkA4.fp += 0.3;
                }
                else{
                    actor->unkA4.fp -= 0.3;
                }
                
                if(actor->pos.y < ((Actor*)(actor->unkB8.ptr))->pos.y + 25.0f){
                    actor->unkA8.fp += 0.3;
                }
                else{
                    actor->unkA8.fp -= 0.3;
                }
                if(actor->pos.z < ((Actor*)(actor->unkB8.ptr))->pos.z){
                    actor->unkAC.fp += 0.3;
                }
                else{
                    actor->unkAC.fp -= 0.3; 
                }  

                func_80025E14(&actor->unkA4.fp, &actor->unkA8.fp, &actor->unkAC.fp); 
                actor->rot.z = -(DEG2RAD(90) - func_8000AE70(actor->unkA8.fp / sqrtf(1.0f - SQ(actor->unkA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                actor->rot.y = -func_8000B038(actor->unkAC.fp, actor->unkA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                func_8002524C(idx, actor->unkA4.fp, actor->unkA8.fp, actor->unkAC.fp); 
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
            actor->unkBC.integer = 0;
            actor->unkC0.integer = 0;
            actor->unkC4.fp = 0.0f;
            actor->unkC8.fp = 0.0f;
            actor->unkCC.fp = func_80011528(0) % 360U;
            actor->unkD0.integer = func_80011528(0) % 400U + 0x1F4;
            
            actor->unkE0.fp = 0.01f;
            actor->unkE4.integer = func_80011528(0) % 400U + 0x64;
            actor->status = 1;
            actor->unkE8.fp = 0.0f; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y + 100.0f){
                actor->pos.y -= 1.0f;
            }

            if(actor->unkDC.integer == 0){
                actor->unkD4.integer = func_80024CA0(0, idx, 400.0f);
                
                
                if(actor->unkD4.integer != -1){
                    actor1 = GET_ACTOR_PTR(actor->unkD4.integer);
                    if(actor->pos.y - 50.0f < actor1->pos.y && actor1->pos.y < (actor->pos.y + 80.0f)){
                        actor->status = 2;
                        actor->unkDC.integer = 0x190;
                    }
                }
            }

            actor->unkE4.integer--;

            if(actor->unkE4.integer <= 0){
                actor->unkE4.integer = func_80011528(0) % 400U + 0x64;
                actor->unkE0.fp *= -1.0f;
            }

            actor->unkE8.fp += actor->unkE0.fp;

            if(actor->unkE8.fp > 0.5){
                actor->unkE8.fp = 0.5;
            }
            if(actor->unkE8.fp < -0.5){
                actor->unkE8.fp = -0.5;
            }

            temp2 = func_80011528(0) % 12U - 6;
            
            if(temp2 > 0){
                actor->unkBC.integer++;
            }            

            if(actor->unkBC.integer >= 0x5B){
                actor->unkBC.integer = 0;
                actor->unkC0.integer = 0x5A;
                actor->unkC4.fp = 2.0f;
            }

            if(actor->unkC0.integer != 0){
                temp3 = actor->unkC4.fp;
                actor->unkC0.integer--;
            }
            else {
                temp3 = actor->unkC4.fp;
                if((actor->unkC4.fp) > 0.0f) {
                    actor->unkC4.fp -= -0.002; 
                }
            }

             
            temp3 -= 0.05;
            func_80024FC8(idx, temp3, actor->unkE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);
            if(D_800F9910.unk1 != 0){
                if(actor->unkC8.fp == 0.0f){
                    actor->unkB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->unkA8.fp - actor->pos.z, actor->unkA0.fp - actor->pos.x));
                    actor->unkC8.fp = actor->unkB8.fp / (func_80011528(0) % 5U + 1);
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
            temp = func_80074E68(actor->rot.y, func_800253B0(idx, actor->unkD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                actor->status = 3;
                actor->unkD8.integer = 0xA;
            }

            actor->rot.y += temp * 0.2;
            temp3 = actor->unkC4.fp;
            func_80024FC8(idx, temp3, actor->unkE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);
            if(D_800F9910.unk1 != 0){
                if(actor->unkC8.fp == 0.0f){
                    actor->unkB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->unkA8.fp - actor->pos.z, actor->unkA0.fp - actor->pos.x));
                    actor->unkC8.fp = actor->unkB8.fp / (func_80011528(0) % 5U + 1);
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
            actor->unkD8.integer--;
            
            if(actor->unkD8.integer <= 0){
                actor->unkBC.integer = 0;
                actor->unkC0.integer = 0xA;
                actor->unkC4.fp = 4.0f;

                if(GET_ACTOR(actor->unkD4.integer).pos.y + 25.0f < actor->pos.y + 34.0f){
                    actor->unkE0.fp = -0.01;
                    actor->unkE8.fp *= 0.5;
                }
                else if(actor->pos.y < GET_ACTOR(actor->unkD4.integer).pos.y + 25.0f ){
                    actor->unkE0.fp = 0.01;
                    actor->unkE8.fp *= 0.5;                    
                }

                actor->status = 1;
            }
            
            break;
    }

        if(actor->unkB4.integer & 6){
            if(actor->unkB0.fp + actor->unkA4.fp < actor->pos.y){
                actor->pos.y = actor->unkB0.fp + actor->unkA4.fp;
            }

            if(actor->pos.y < actor->unkA4.fp){
                actor->pos.y = actor->unkA4.fp;
            }
        }

        if(actor->unkDC.integer != 0){
            actor->unkDC.integer--;
        }

        actor->unkD0.integer--;

        if(actor->unkD0.integer <= 0){
            actor->unkD0.integer = func_80011528(0) % 400U + 0x1F4;

            if(actor->unkC8.fp == 0.0f){
                actor->unkC8.fp = func_80011528(0) % 180U;
            }
        }

        actor->unkCC.fp += 3.0f;

        NORM_ANGLE(actor->unkCC.fp);

        if(actor->unkC8.fp != 0.0f){
            actor->unkC8.fp = func_80025374(idx, actor->unkC8.fp, 0.05f);

            if(actor->unkC8.fp < 10.0f && actor->unkC8.fp > -10.0f){
                actor->unkC8.fp = 0.0f;
            }
        }

        switch(actor->unkB4.integer & 7){
            case 1:
                if(actor->unkC8.fp == 0.0f){
                    actor->unkC8.fp = actor->unkB8.fp / (f32)(func_80011528(0) % 5U + 1);
                }
                break;
            case 2:
                if(actor->unkE8.fp > 0.0f){
                    actor->unkE8.fp *= 0.5;
                    actor->unkE0.fp = -0.01;
                }
                break;
            case 4:
                
                if(actor->unkE8.fp < 0.0f){
                    actor->unkE8.fp *= 0.5;
                    actor->unkE0.fp = 0.01;
                }
                break;
        
    }
}
