#include "3DD30.h"

#include "23B20.h"
#include "11F10.h"
#include "9320.h"
#include "15F60.h"
#include "73660.h"
#include "4D980.h"

#include "actor.h"
#include "libc/math.h"

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

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

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x6];
    s16 unk8;
    u8 unkA[0x3];
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

void func_8003D130(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 =  GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);  
    s32 temp;
    s32 temp2;
    f32 temp1;

    if(actor->unk38 != 0xFFFF){
        switch(actor->status){
            case 0:
                if(actor->unkA0.fp < 1.0f){
                    actor->unkA0.fp = 400.0f;
                }

                actor->unkB4.integer = 4;
                actor->unkBC.integer = 4;
                actor->unk4E = 2;

                actor->unkA4.fp = actor->pos.x;
                actor->unkA8.fp = actor->pos.y;
                actor->unkAC.fp = actor->pos.z;
                actor->pos.y -= 30.0f;
                actor->unk6C = 15;
                
                func_80022F48(idx, 0);
                actor->status = 1;
                break;
            case 1:
                if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < actor->unkA0.fp * 4.0f){
                    actor->status = 2;
                    actor->unkB0.integer = func_80011528(0) % 20U;
                }
                break;
            case 2:
                actor->unkB0.integer--;

                if(actor->unkB0.integer <= 0){
                    actor->status = 3;

                    temp = func_80011528(0);
                    actor->pos.x = (actor->unkA4.fp + (temp % (u32)(s32)(actor->unkA0.fp * 2))) - actor->unkA0.fp;
                    temp2 = func_80011528(0);
                    actor->pos.z = (actor->unkAC.fp + (temp2 % (u32)(s32)(actor->unkA0.fp * 2))) - actor->unkA0.fp;
                    actor->pos.y = actor->unkA8.fp;

                    actor->unkB8.fp = func_800253B0(idx,  D_80159178->unk48[cdata.unk41].unk0);
                    actor->unkC8.integer = 0;
                    actor->rot.x = 0.0f;
                }
                break;
            case 3:
                if(actor->unkC8.integer <= 0){
                    func_80008E10(0x43, 3, idx);
                    actor->unkC8.integer = 0xA;
                }
                else{
                    actor->unkC8.integer--;
                }

                actor->unkBC.integer--;
                actor->rot.y = actor->unkB4.integer + actor->unkB8.fp;

                if(actor->unkBC.integer <= 0){
                    actor->unkB4.integer = -actor->unkB4.integer;
                    actor->unkBC.integer = 4;
                }

                NORM_ANGLE(actor->rot.y);

                actor->pos.y += 0.2;

                func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y + 9.0f, actor->pos.z, -50.0f);

                if(D_800F9910.unk1 != 0){
                    actor->pos.y = D_800F9910.unk10 - 9.0f;
                    actor->status = 4;
                    func_80008E10(0x45, 2, idx);
                    actor->unkCC.integer = 0;
                    actor->unkC0.fp = 5.0f;
                    func_80022F48(idx, 3);
                }
                break;
            case 4:
                actor->unkCC.integer++;

                if(actor->unkCC.integer >= 0x29){
                    if(actor->unkCC.integer < 0x36){
                        actor->pos.y += 0.15;
                    }
                    else{
                        func_80024FC8(idx, 2.0f, actor->unkC0.fp);
                        actor->unkC0.fp -= 0.2;
                        D_801414A0[actor->unk38]->unk30 += 12.0f;
                        func_80016EB8(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);
                        
                        if (D_800F9910.unk0 != 0) {
                            actor->status = 5;
                            actor->unkB0.integer = 0x3C;
                            D_801414A0[actor->unk38]->unk30 += 12.0f;
                        }
                        actor->pos.x = D_800F9910.unkC;
                        actor->pos.y = D_800F9910.unk10;
                        actor->pos.z = D_800F9910.unk14;
                    }
                }
                break;
            case 5:
                actor->unkBC.integer--;

                if(actor->unkBC.integer <= 0){
                    actor->unkB4.integer = -actor->unkB4.integer;
                    actor->unkBC.integer = 4;
                }

                NORM_ANGLE(actor->rot.y);
                
                actor->unkB0.integer--;

                if(actor->unkB0.integer <= 0){
                    actor->status = 6;
                    actor->unkB0.integer = func_80011528(0) % 150U + 0x96;
                    actor->unkC4.fp = 0.0f;
                    func_80022F48(idx, 2);
                }
                break;
            case 6:
                temp1 = func_80025C48(actor1->pos.z - actor->pos.z, actor1->pos.x - actor->pos.x);

                actor->rot.y += func_80074E68(actor->rot.y, temp1) / 90.0f;
                
                NORM_ANGLE(actor->rot.y);
                
                if(actor->unkC4.fp < 1.0f){
                    actor->unkC4.fp += 0.025;
                }

                func_80024FC8(idx, actor->unkC4.fp, -1.0f);
                
                func_80016EB8(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);

                if(actor->pos.x + actor->unk58 < (actor->unkA0.fp + actor->unkA4.fp) && (actor->unkA4.fp - actor->unkA0.fp) < actor->pos.x + actor->unk58){
                    if(actor->pos.z + actor->unk60 < (actor->unkA0.fp + actor->unkAC.fp) && (actor->unkAC.fp - actor->unkA0.fp) < actor->pos.z + actor->unk60){
                        actor->pos.x = D_800F9910.unkC;
                        actor->pos.y = D_800F9910.unk10;
                        actor->pos.z = D_800F9910.unk14;                    
                    }

                }
                
                actor->unkB0.integer--;
                
                if(actor->unkB0.integer <= 0){
                    actor->status = 7;
                    actor->unkB0.integer = 0x78;
                    actor->unkB8.fp = actor->rot.y;
                    func_80022F48(idx, 1);
                }
                
                break;
            case 7:
                actor->unkBC.integer--;
                actor->rot.y = actor->unkB4.integer + actor->unkB8.fp;
                
                if(actor->unkBC.integer <= 0){
                    actor->unkB4.integer = -actor->unkB4.integer;
                    actor->unkBC.integer = 4;
                }

                NORM_ANGLE(actor->rot.y);

                actor->pos.y -= 0.2;

                if(actor->rot.x < 90.0f){
                    actor->rot.x += 5.0f;
                }
                else if(actor->rot.x < 120.0f){
                    actor->rot.x += 2.0f;
                }
                else if(actor->rot.x < 160.0f){
                    actor->rot.x += 1.0f;
                }

                actor->unkB0.integer--;

                if(actor->unkB0.integer <= 0){
                    actor->status = 1;
                    actor->pos.x = actor->unkA4.fp;
                    actor->pos.y = actor->unkA8.fp;
                    actor->pos.z = actor->unkAC.fp;
                }
                
                break;
        }
    }
}

void func_8003DC20(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp;
    
    NORM_ANGLE(actor->rot.y);

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->unkC0.fp = 0.0f;
            actor->unkA8.integer = actor->pos.x;
            actor->unkAC.integer = actor->pos.y;
            actor->unkB0.integer = actor->pos.z;
            
            break;
        case 1:

            if(func_80024CA0(0, idx, 300.0f) == -1){
                actor->status = 2;
                actor->unkA0.integer = 0x168;
                actor->unkA4.integer = 5;
            }
            else{
                actor->status = 6;
                func_8002524C(idx, 0.0f, 0.0f, 0.0f);
                actor->unkB4.fp = 0.0f;
                actor->unkB8.fp = 0.0f;
                actor->unkBC.fp = 0.0f;
                
            }
            break;
        case 2:
            actor->rot.y += 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 3;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 4; 
                actor->unkA0.integer = 0x168;
            }
            break;
        case 3:
            actor->rot.y += 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 2;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 4;
                actor->unkA0.integer = 0x168;
            }
            break;
        case 4:
            actor->rot.y -= 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 5;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 2; 
                actor->unkA0.integer = 0x168;
            }
            break;
        case 5:
            actor->rot.y -= 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 4;
            }
            else if(actor->unkA0.integer < 0){ 
                actor->status = 1; 
                actor->pos.x = actor->unkA8.integer;
                actor->pos.z = actor->unkB0.integer;
            }
            break;
        case 6:
            actor->unkB4.fp += 0.5;
            actor->unkBC.fp += actor->unkB4.fp;

            if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) < 0){
                actor->rot.y += 4.0f;

                 while (actor->rot.y >= 360.0f) {
                    actor->rot.y -= 360.0f;
                }
            }
            else {
                actor->rot.y -= 4.0f;

                 while (actor->rot.y < 0.0f) { 
                    actor->rot.y += 360.0f;
                }
                
            }

            if(actor->pos.y - actor->unkBC.fp < GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->pos.y){
                actor->status = 7;
                func_80008E10(0x44, 2, idx);
                actor->unkB8.fp = actor->unkB4.fp;
            }
            break;
        case 7:
            func_80024FC8(idx, 2.0f, -actor->unkB4.fp);
            func_8002507C(idx);

            actor->unkB4.fp -= 0.5;

            if(actor->unkB4.fp == 0.0f){
                actor->status = 8;
            }
            break;
        case 8:
            func_80024FC8(idx, 2.0f, actor->unkB4.fp);
            func_8002507C(idx);
            
            actor->unkB4.fp += 0.5;

            if(actor->unkB8.fp < actor->unkB4.fp){
                actor->status = 1;
                actor->unkA8.integer = actor->pos.x;
                actor->pos.y = actor->unkAC.integer;
                actor->unkB0.integer = actor->pos.z;

            }
            break;
    }
    actor->unkC0.fp += 30.0f;

    NORM_ANGLE(actor->unkC0.fp);

    temp = sinf(actor->unkC0.fp * 3.14 / 180.0);

    if(actor->unk38 != 0xFFFF){
        D_801414A0[actor->unk38 + 3]->unk34 = temp * 40.0f;
        D_801414A0[actor->unk38 + 4]->unk34 = -temp * 40.0f;        
    }
}

void func_8003E410(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp;
    
    NORM_ANGLE(actor->rot.y);

    switch(actor->unkA0.integer){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            func_80016EB8(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, -10.0f, 0.0f);

            if(D_800F9910.unk0 != 0){
                actor->unkA0.integer = 1;
                actor->unkA8.integer = 1;
                actor->unk4E = 2;
                actor->unk6C = 0x11;
                
                func_80022F48(idx, 0);
            }
            actor->pos.y = D_800F9910.unk10;
            
            break;
        case 1:
            if(func_80024CA0(0, idx, 200.0f) == -1){
                actor->unkA0.integer = 2;
                actor->unkA4.integer = 0x43;
            }
            else{
                actor->unkA0.integer = 3;
            }
            break;
        case 2:
            if(actor->unkA4.integer > 0){
                actor->rot.y -= (actor->unkA8.integer * 4);
                actor->unkA4.integer--;
            }
            else{
                actor->unkA0.integer = 1;
                actor->unkA8.integer = -actor->unkA8.integer;
            }
            break;
        case 3:
            actor->unkA0.integer = 4;
            actor->unkA8.integer = func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0);
            actor->unkB0.integer = 9;
            actor->unkB4.integer = 2;
            break;
        case 4:
            actor->rot.y -= (actor->unkA8.integer * actor->unkB0.integer);

            if(actor->unkA8.integer > 0){
                if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) < 0){
                    actor->unkB0.integer--;

                    if(actor->unkB0.integer == 0){
                        actor->unkB4.integer--;

                        if(actor->unkB4.integer != 0){
                            actor->unkA8.integer = func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0);
                            actor->unkB0.integer = 9;
                        }
                        else{
                            actor->unkA0.integer = 5;
                            actor->unkAC.integer = func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0);                            
                            actor->unkA8.integer = func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0);     
                        }
                    }
                }
            }
            else{
                if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) > 0){
                    actor->unkB0.integer--;

                    if(actor->unkB0.integer == 0){
                        actor->unkB4.integer--;

                        if(actor->unkB4.integer != 0){
                            actor->unkA8.integer = func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0);
                            actor->unkB0.integer = 9;
                        }
                        else{
                            actor->unkA0.integer = 5;
                            actor->unkAC.integer = func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0);                            
                            actor->unkA8.integer = func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0);     
                        }
                    }
                }
            }
            break;
        case 5:
            if(actor->unkA8.integer > 0){
                actor->rot.y -= 10.0f;

                if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) < 0){
                    actor->rot.y = actor->unkAC.integer;
                    func_80008E10(0x45, 2, idx);
                    actor->unkA0.integer = 6;
                    actor->unkAC.integer = 7;
                    func_80022F48(idx, 1);
                }
            }
            else{
                actor->rot.y += 10.0f;

                if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) > 0){
                    actor->rot.y = actor->unkAC.integer;
                    func_80008E10(0x45, 2, idx);
                    actor->unkA0.integer = 6;
                    actor->unkAC.integer = 7;
                    func_80022F48(idx, 1);
                }
            }
            break;
        case 6:
            func_80024FC8(idx, 5.0f, --actor->unkAC.integer);
            func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);

            if(D_800F9910.unk0 != 0){
                actor->unkA0.integer = 7;
                actor->unkA8.integer = 0x64;
                func_80022F48(idx, 2);
            }

            actor->pos.x = D_800F9910.unkC;
            actor->pos.y = D_800F9910.unk10;
            actor->pos.z = D_800F9910.unk14;
            break;
        case 7:
            actor->unkA8.integer--;

            if(actor->unkA8.integer <= 0){
                actor->unkA0.integer = 1;
                actor->unkA8.integer = 1;
            }

            if(actor->unkA8.integer == 0x49){
                func_80022F48(idx, 0);
            }
            break;
    }
}

void func_8003EB68(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1;
    f32 temp1;
    f32 temp2;
    u32 temp;

    switch (actor->status) {     
        case 0:
            actor->status = 1;
            actor->unkA0.fp = actor->pos.x;
            actor->unkA4.fp = actor->pos.z;
            break;
        case 1:
            temp = func_80011528(0) % 100U;
            actor->unkA8.fp = (temp + actor->unkA0.fp) - 50.0f;
            
            temp = func_80011528(0) % 100U;
            actor->unkAC.fp = (temp + actor->unkA4.fp) - 50.0f;
            
            actor->status = 2;
            break;
        case 2:
            actor->rot.y += func_80074E68(actor->rot.y, func_80025C48((s32) (actor->unkAC.fp - actor->pos.z), (s32) (actor->unkA8.fp - actor->pos.x))) / 60.0f;
        
            NORM_ANGLE(actor->rot.y);
            
            func_80024FC8(idx, 1.0f, -30.0f);
            func_800180F0(&D_800F9910, cdata.nextstg, 10.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);
            
            if (D_800F9910.unk1 != 0) {
                actor->pos.x = D_800F9910.unkC;
                actor->pos.y = D_800F9910.unk10;
                actor->pos.z = D_800F9910.unk14;
            } else {
                func_8002507C(idx);
            }
            
            temp1 = actor->unkAC.fp - actor->pos.z;
            temp2 = actor->unkA8.fp - actor->pos.x;
            
            if (sqrtf(SQ(temp1) + SQ(temp2)) < 40.0f) {
                actor->status = 1;
            }
            
            break;
        case 4:
            actor1 = GET_ACTOR_PTR(actor->unkB0.integer);
            
            if (actor1->unk0 != 0) {
                actor->rot.y += func_80074E68(actor->rot.y,func_80025C48((actor->pos.z - actor1->pos.z),(actor->pos.x - actor1->pos.x))) / 30.0f;
                
                NORM_ANGLE(actor->rot.y);
                
                if (func_80024CA0(4, idx, 120.0f) != -1) {
                    func_80024FC8(idx, 8.0f, -30.0f);
                } else {
                    func_80024FC8(idx, 4.0f, -30.0f);
                }
                
                func_800180F0(&D_800F9910, cdata.nextstg, 10.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->unk58, actor->unk5C, actor->unk60);
                
                if (D_800F9910.unk1 != 0) {
                    actor->pos.x = D_800F9910.unkC;
                    actor->pos.y = D_800F9910.unk10;
                    actor->pos.z = D_800F9910.unk14;
                } else {
                    func_8002507C(idx);
                }
                
                actor->unkB0.integer = func_80024CA0(4, idx, 250.0f);
                
                if (actor->unkB0.integer != -1) {
                    actor->status = 1;
                }
            } else {
                actor->status = 1;
            }
            break;
    } 
    actor->unkB0.integer = func_80024CA0(4, idx, 200.0f);
    
    if (actor->unkB0.integer != -1) {
        func_80008E10(0x46, 2, idx);
        actor->status = 4;
    }
}

void func_8003F09C(s16 idx){
    s32 pad;
    Actor* actor = GET_ACTOR_PTR(idx);

    if (actor->unkA0.integer == 0) {
        actor->unk4E = 2;
        actor->unk6C = 0x13;

        func_80022F48(idx, 0);
        actor->unkA4.integer = func_800249E4(0x14, 0x5E, idx, 50.0f);
        if (actor->unkA4.integer != -1){
            func_80022F20(idx, func_8003F190);
            func_8003F190(idx);
        } else{
            func_80022F20(idx, func_8003F990);
            func_8003F990(idx);
        }
    }
}

void func_8003F190(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp1;
    f32 temp2;
    
    switch (actor->status) {
        case 0:
            actor->flags |= 0x10;
            GET_ACTOR(actor->unkA4.integer).unkA8.integer = 1;
            actor->status = 1;
            actor->unkB0.ptr = GET_ACTOR_PTR(actor->unkA4.integer);
            actor->unkAC.fp = actor->rot.y;
            break;
        case 1:
            if (actor->unkA8.integer > 0) {
                GET_ACTOR(actor->unkA4.integer).unkA8.integer = 2;
                actor->status = 2;
            }
            break;
        case 2:
            if (actor->unkA8.integer >= 2) {
                actor->unkA8.integer = 0;
                actor->unkB4.integer = 0xC8;
                
                if (idx < actor->unkA4.integer) {
                    actor->unkA0.integer = 0;
                    actor->status = 100;
                } else {
                    actor->unkA0.integer = 1;
                    actor->status = 200;
                }
            }
            break;
        case 100:
            if (actor->unkA8.integer == 3) {
                actor->unkB4.integer = 0xA;
                actor->status = 101;
            }
            break;
        case 101:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 5;
                GET_ACTOR(actor->unkA4.integer).unkA8.integer = 3;
                func_80022F48(idx, 1);
                actor->status = 102;
            }
            func_80025454(actor, actor->unkB0.ptr, 16.0f);
            break;
        case 102:
            if (actor->unkA8.integer == 4) {
                actor->unkB4.integer = 0x1E;
                func_80022F48(idx, 0);
                actor->status = 103;
            }
            break;
        case 103:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 0xC8;
                actor->unkA8.integer = 0;
                actor->status = 100;
            }
            
            temp2 = actor->unkAC.fp;
            temp1 = actor->rot.y;
            actor->rot.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(actor->rot.y);
            break;
        case 200:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 5;
                actor->status = 201;
            }
        case 201:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = (func_80011528(0) % 400U) + 0x1F4;
                GET_ACTOR(actor->unkA4.integer).unkA8.integer = 3;
                
                func_80022F48(idx, 1);
                actor->status = 202;
            }
            func_80025454(actor, actor->unkB0.ptr, 16.0f);
            break;
        case 202:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 0x1E;
                func_80022F48(idx, 0);
                actor->status = 203;
            }
            break;
        case 203:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 0xC8;
                GET_ACTOR(actor->unkA4.integer).unkA8.integer = 4;
                actor->unkA8.integer = 0;
                actor->status = 200;
            }
            
            temp2 = actor->unkAC.fp;
            temp1 = actor->rot.y;
            actor->rot.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(actor->rot.y);
            break;
        case 300:
            if (actor->unkA0.integer == 1) {
                actor->unkB8.fp = actor->rot.y;
                GET_ACTOR(actor->unkA4.integer).unkB8.fp = actor->rot.y;
                actor->unkB4.integer = 0x1E;
            } else {
                actor->unkB4.integer = 0xA;
            }
            
            actor->unkBC.fp = 4.0f;
            func_80022F48(idx, 4);
            actor->status = 301;
            break;
        case 301:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->unkB4.integer = 0x78;
                actor->status = 302;
            }
        case 302:
            actor->unkB4.integer--;
            
            if (actor->unkB4.integer <= 0) {
                actor->flags |= 0x1000;
                func_80022F48(idx, 2);
                actor->status = 303;
            }
            
            if (actor->unkBC.fp > 0.1) {
                actor->unkBC.fp -= 0.25;
            } else {
                actor->unkBC.fp = 0.0f;
            }
            
            func_80024FC8(idx, 0.0f, actor->unkBC.fp);
            func_8002507C(idx);
            
            if (!(actor->unkB4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 303:
            temp2 = actor->unkB8.fp;
            temp1 = actor->rot.y;
            actor->rot.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(actor->rot.y);
            
            if (actor->unkBC.fp < 4.0f) {
                actor->unkBC.fp += 0.05;
            }
            
            func_80024FC8(idx, 2.0f, actor->unkBC.fp);
            func_8002507C(idx);
            
            if (!(actor->unkB4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
    }
    
    if (actor->status < 300) {
        if (func_80024CA0(4, idx, 100.0f) != -1 || func_80024CA0(0, idx, 70.0f) != -1) {
            actor->status = 300;
        }
    }
}

void func_8003F990(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);  
    Actor* p2;
    f32 temp1;
    f32 y;
    f32 diff;
    f32 dist;
    s32 pad;
    f32 z;
    f32 fact;

    switch (actor->status) {
        case 0:
            actor->status = 10;
            actor->unkB0.fp = actor->pos.x;
            actor->unkB4.fp = actor->pos.y;
            actor->unkB8.fp = actor->pos.z;
            actor->unkBC.fp = actor->rot.y;
            break;
        case 10:
            actor->unkA4.integer = 0x32;
            actor->status = 11;
            break;
        case 11:
            actor->unkA4.integer--;
            
            if (actor->unkA4.integer <= 0) {
                actor->status = 15;
            }
            break;
        case 15:
            if ((actor->unk70 != -1) && ((func_80024CA0(0, idx, 200.0f) != -1) || (func_80024CA0(4, idx, 200.0f) != -1))) {
                func_80022F48(idx, 4);
                actor->unkA4.integer = 0x78;
                actor->status = 20;
                actor->unkA0.fp = 0.5f;
            }
            break;
        case 20:
            actor->unkA4.integer--;
            if (actor->unkA4.integer <= 0) {
                actor->unkA4.integer = 0;
                actor->status = 30;
            }
            func_80024FC8(idx, -0.25f, actor->unkA0.fp);
            func_8002507C(idx);
            break;
        case 30:
            actor->unkA4.integer++;
            actor->unkA0.fp -= 0.05;
            
            if (actor->unkA0.fp < 0.1) {
                func_80022F48(idx, 2);
                actor->unkA4.integer = 0x21C;
                actor->status = 40;
            }
            
            func_80024FC8(idx, -0.05f, actor->unkA0.fp);
            func_8002507C(idx);
            
            if (!(actor->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 40:
            actor->unkA4.integer--;
            
            if ((actor->unkA4.integer <= 0) || (D_80141CB0[idx].unk0 != -1)) {
                func_80022F48(idx, 4);
                actor->status = 100;
            }
            
            p2 = GET_ACTOR_PTR(actor->unk70);
            
            if (!(p2->flags & 8)) {
                diff = actor->pos.y - p2->pos.y;
                
                if (diff < 20.0f) {
                    actor->unkA0.fp = actor->unk5C;
                    func_80022F48(idx, 4);
                    actor->status = 41;
                } else if (diff < 40.0f) {
                    actor->unkA8.fp = 0.3f;
                    actor->unkAC.fp = 0.1f;
                } else {
                    if (diff < 60.0f) {
                        actor->unkA8.fp = 0.6f;
                        actor->unkAC.fp = 0.1f;
                    } else if (diff < 80.0f) {
                        actor->unkA8.fp = 0.9f;
                        actor->unkAC.fp = 0.1f;
                    } else if (diff < 100.0f) {
                        actor->unkA8.fp = 1.2f;
                        actor->unkAC.fp = 0.1f;
                    } else {
                        actor->unkA8.fp = 1.5f;
                        actor->unkAC.fp = 0.1f;
                    }
                }
            }
            
            func_80025454(actor, actor1, 16.0f);
            func_80024F20(idx, 2.0f);
            func_8002592C(actor, actor1, actor->unkA8.fp, actor->unkAC.fp);
            func_8002507C(idx);
            
            if (!(actor->unkA4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 41:
            actor->unkA4.integer--;
            
            if ((actor->unkA4.integer <= 0) || (D_80141CB0[idx].unk0 != -1)) {
                actor->unkA4.integer = 0;
                actor->status = 100;
            }
            
            p2 = GET_ACTOR_PTR(actor->unk70);
            diff = actor->pos.y - p2->pos.y;
            
            if (p2->flags & 8) {
                actor->status = 40;
            }
            if (diff > 100.0f) {
                actor->unk5C = actor->unk5C * 0.93;
            } else {
                actor->unk5C = actor->unk5C + 0.01;
            }
            if (diff > 240.0f) {
                actor->status = 40;
            }
            
            actor->unk58 = actor->unk58 * 0.98;
            actor->unk60 = actor->unk60 * 0.98;
            
            func_80025454(actor, actor1, 16.0f);
            func_8002507C(idx);
            
            if (!(actor->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 100:
            actor->unkA4.integer++;
            
            if (actor->unk5C > 0.1) {
                actor->unk5C *= 0.95;
                actor->unk58 *= 0.95;
                actor->unk60 *= 0.95;
            } else {
                func_80022F48(idx, 2);
                actor->status = 101;
            }
            if (!(actor->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            
            func_8002507C(idx);
            break;
        case 101:
            actor->unkA4.integer++;
            
            diff = actor->unkB0.fp - actor->pos.x;
            y = (actor->unkB4.fp + 30.0f) - actor->pos.y;
            z = actor->unkB8.fp - actor->pos.z;
            
            dist = sqrtf(SQ(diff) + SQ(z));
            
            if (dist == 0.0f) {
                dist = 1.0f;
            }
            
            actor->unk5C = (y / dist) * 0.5 * 1.02;
            temp1 = func_80025C48(actor->unkB8.fp - actor->pos.z, actor->unkB0.fp - actor->pos.x);
            
            if (dist < 50.0f) {
                fact = 0.5f;
            } else if (dist < 100.0f) {
                fact = 0.3f;
            } else {
                fact = 0.1f;
            }
            
            actor->rot.y += func_80074E68(actor->rot.y, temp1) * fact;
            
            NORM_ANGLE(actor->rot.y);
            
            func_80024F20(idx, 2.0f);
            func_8002507C(idx);
            
            if ((dist < 5.0f) && (actor->unkB4.fp < actor->pos.y)) {
                func_80022F48(idx, 4);
                actor->status = 102;
            }
            if (!(actor->unkA4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 102:
            actor->unkA4.integer++;
            
            actor->unk58 = actor->unk58 * 0.5;
            actor->unk60 = actor->unk60 * 0.5;
            actor->unk5C = actor->unk5C - 0.01;
            
            if (actor->unk5C < -1.0f) {
                actor->unk5C = -1.0f;
            }
            
            func_8002507C(idx);
            
            if (actor->pos.y < actor->unkB4.fp) {
                actor->pos.y = actor->unkB4.fp;
                func_80022F48(idx, 0);
                actor->status = 10;
            }
            if (!(actor->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 900:
            actor->flags |= 0x1000;
            func_80024FC8(idx, 2.0f, 2.0f);
            func_8002507C(idx);
            break;
        }
    
    if ((GET_ACTOR_PTR(actor->unk70)->unk0 == 0) && (actor->status < 0x384)) {
        actor->status = 900;
    }
}

void func_80040404(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 diffZ;
    f32 diffX;
    f32 diffY;
    s32 pad[2];
    f32 x;
    f32 y;
    f32 z;
    s32 pad2[3];
    f32 dist;
    
    switch (actor->unkB8.integer) { 
        case 0:
            x = actor->unkA0.fp;
            y = actor->unkA4.fp;
            z = actor->unkA8.fp;
            break;
        case 1:
            x = actor->unkAC.fp;
            y = actor->unkB0.fp;
            z = actor->unkB4.fp;
            break;
    }
    
    diffX = x - actor->pos.x;
    diffY = y - actor->pos.y;
    diffZ = z - actor->pos.z;
    
    dist = sqrtf(SQ(diffX) + SQ(diffY) + SQ(diffZ));
    
    switch (actor->status) {
        case 0:
            actor->unkB8.integer = 0;
            actor->unk5C = 0.0f;
            actor->unkE8.fp = 10.0f;
            actor->unk4E = 2;
            actor->unk6C = 0x16;
            
            func_80022F48(idx, 0);
            actor->status = 1;
            break;
        case 1:
            if (y < actor->pos.y) {
                actor->unk5C -= 0.05;
                if (actor->unk5C < -3.0f) {
                    actor->unk5C = -3.0f;
                }
            } else if (actor->pos.y < y) {
                actor->unk5C += 0.05;
                if (actor->unk5C > 3.0f) {
                    actor->unk5C = 3.0f;
                }
            }
            
            diffZ = func_80025C48(z - actor->pos.z, x - actor->pos.x);
            diffZ = func_80074E68(actor->rot.y, diffZ) * 0.03125;
            
            actor->rot.y += diffZ;
            
            NORM_ANGLE(actor->rot.y);
            
            func_80024F20(idx, actor->unkE8.fp);
            func_8002507C(idx);
            break;
    }
    
    if (dist < 100.0f) {
        actor->unkB8.integer = 1 - actor->unkB8.integer;
        actor->unkE8.fp = 10.0f;
    } else if (dist < 200.0f) {
        actor->unkE8.fp = 2.0f;
    } else if (dist < 300.0f) {
        actor->unkE8.fp = 4.5f;
    } else if (dist < 400.0f) {
        actor->unkE8.fp = 6.5f;
    } else if (dist < 500.0f) {
        actor->unkE8.fp = 8.0f;
    }
}

void func_800407FC(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s32 id;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch (actor->status) {
        case 0:
            if (actor->unkA0.integer == 1) {
                actor->unk74 = 0xA;
                actor->unk90.x = 3.0f;
                actor->unk90.y = 3.0f;
                actor->unk90.z = 3.0f;
            }

            actor->unk4E = 2;
            actor->unk6C = 0x29;
            func_80022F48(idx, 2);
            actor->unkA4.integer = 0xA;
            actor->status = 10;
        default:
            break;
        case 10:
            if (temp < 100.0f) {
                actor->unkA8.fp = 4.0f;
                actor->unkA4.integer = 0x3C;
                func_80008E10(0x55, 2, idx);
                actor->status = 11;
                return;
            }
            break;
        case 11:
            actor->unkA4.integer--;

            if (actor->unkA4.integer <= 0) {
                func_80022F48(idx, 0);
                actor->unkA4.integer = 0x28;
                actor->status = 12;
            }

            func_80025454(actor, actor1, 24.0f);
            return;
        case 12:
            actor->unkA4.integer--;

            if (actor->unkA4.integer <= 0) {
                func_80008E10(0x17, 2, idx);
                actor->unkA4.integer = 0x3C;
                func_80022F48(idx, 2);
                actor->status = 13;
            }
            if (actor->unkA4.integer == 5) {
                id = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y + 50.0f, 0.0f);

                if (id != -1) {
                    func_800242F0(id, 0, 0xFFFFU);
                    func_80022F20(id, func_8004EAC4);
                    func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y + 50.0f, 20.0f, 10.0f);
                    return;
                }
            }
            break;
        case 13:
            actor->unkA4.integer--;

            if (actor->unkA4.integer <= 0) {
                actor->status = 10;
            }
            break;
    }
}

void func_80040AB8(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch (actor->status) {
        case 0:
            actor->unkD4.fp = actor->unkB4.fp;
            actor->unkD8.fp = actor->unkB8.fp;
            actor->unkDC.fp = actor->unkBC.fp;

            actor->unkC0.fp = 2.0f;
            actor->unkC4.fp = 0.9f;
            actor->unkC8.fp = 0.05f;
            actor->unkCC.fp = 32.0f;
            actor->unkD0.fp = 200.0f;
            
            actor->status = 1;
            actor->unk4E = 2;
            actor->unk6C = 0x2B;
            func_80022F48(idx, 0);
            break;
        case 1:
            func_80021B90(idx);
            break;
    }
}
