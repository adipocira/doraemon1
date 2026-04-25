#include "52E50.h"
#include "23B20.h"
#include "9320.h"
#include "11F10.h"
#include "29980.h"
#include "13940.h"
#include "15F60.h"
#include "73660.h"
#include "4D980.h"
#include "libc/math.h"
#include "common.h"

extern f32 D_80142BD0;
extern f32 D_8014DF90;

extern f32 D_80159170;

void func_80052250(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0); 
    s16 i;
    s16 id;
    f32 t1;
    f32 t2;
    f32 t3;
    s16 temp1 = D_80159178->unk48[cdata.unk41].unk0;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 temp4 = GET_ACTOR_PTR(idx)->status;

    (void)"hit point =%d\n";

    switch(temp4){
        case 0: 
            actor->actorVars.varD0.integer = cdata.unk46[cdata.nextstg] >> 0xE;
            cdata.unk46[cdata.nextstg] |= 0x8000;
            actor->unk4E = 2;
            actor->unk6C = 0xA;
            actor->unk8 = 0x100;

            func_80022F48(idx, 2);
            actor->actorVars.varCC.integer = actor->unk74;

            actor->actorVars.varB4.integer = 0;
            actor->actorVars.varB0.integer = 0;
            if (!(&actor->pos));
            actor->status = 50;
            break;
        case 50:
            func_80022F48(idx, 2);
            actor->status = 51;
            break;
        case 51:
            break;
        case 100:
            actor->unk8 = 0x53F;
            func_80022F48(idx, 3); 
            actor->actorVars.varB4.integer = 30;
            func_80008C6C(0xE8, 3);

            actor->actorVars.varA0.integer = 40;
            actor->actorVars.varA4.fp = 5.0f;
            
            actor->actorVars.varA8.fp = actor->pos.y + 200.0f;
            actor->actorVars.varAC.fp = actor->pos.y + 200.0f;

            actor->status = 101;
            D_800F0588.unk30 = 1;
            break;
        case 101:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA4.fp *= 0.9;

                if(actor->actorVars.varA4.fp < 0.1){
                   actor->actorVars.varA0.integer = 120; 
                    actor->status = 600;
                }
            }
            if(actor->pos.y < actor->actorVars.varA8.fp && actor->actorVars.varA8.fp - 100.0f < actor->pos.y){
                func_80008C6C(0x23, 2);
                func_800090B0(3);

                for(i = 0; i < 5; i++){
                    t1 = (func_80011528(0) % 100U) - 50.0f;
                    t2 = (func_80011528(0) % 100U) - 50.0f;

                    id = func_80023644(6, 0x183, actor->pos.x + t1, actor->pos.y, actor->pos.z + t2, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002C0BC);
                    }
                }
            }

            func_80025454(actor, actor2, 4.0f);
            func_80024FC8(idx, 0.0f, actor->actorVars.varA4.fp);
            func_800545DC(actor);

            D_800F0588.unk30 = 1;
            break;
        case 600:
            D_800E6B20_2022_sets(0x1C, 0xB4);
            actor->status = 601;
            D_800F0588.unk30 = 1;
            break;
        case 601:
            D_800F0588.unk30 = 1;

            if(!func_80012D40(0xB, actor->actorVars.varD0.integer, 1)){
                D_800E6B20_sets2(0x4B, 0xB7, cdata.unk6A, 1, 0xB, 4, 5);
                D_800F0588.unk30 = 0;
                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                D_800F9B08.unk788 &= (u16)~0x1;
                D_800F9B08.unk7C4 &= (u16)~0x1;
                D_800F9B08.unk800 &= (u16)~0x1;
                D_800F9B08.unk83C &= (u16)~0x1;
                D_800F9B08.unk878 &= (u16)~0x1;
                D_800F9B08.unk8B4 &= (u16)~0x1;
                actor->status = 102;
            }
            break;
        case 102:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB0.integer = 1;
                actor->status = 50;
            }
            break;
        case 150:
            actor->unk8 = 0x100;
            func_80008C6C(0xD1, 2);
            func_80022F48(idx, 3);
            actor->actorVars.varB4.integer = 30;
            func_80024FC8(idx, 0.0f, 0.0f);
            actor->status = 151;
            actor->actorVars.varA8.fp = actor->actorVars.varAC.fp + 110.0f;
            break;
        case 151:
            func_80025454(actor, actor2, 16.0f);

            if(actor->actorVars.varA8.fp < actor->pos.y){
                actor->dir.y *= 0.9;

                if(actor->dir.y < 0.1){
                    actor->status = 152;
                }
            }
            else{
                func_800259B4(actor, actor->actorVars.varA8.fp, 2.0f, 0.5f);
            }

            func_800545DC(actor);
            
            func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            actor->pos.x = D_800F9910.unkC;
            actor->pos.y = D_800F9910.unk10;
            actor->pos.z = D_800F9910.unk14;            
            break;
        case 152:
            t1 = actor2->pos.x - actor->pos.x;
            t3 = actor2->pos.z - actor->pos.z;

            if(sqrtf(SQ(t1) + SQ(t3)) < 150.0f){
                actor->status = 400;
            }
            else if(actor->actorVars.varAC.fp + 100.0f < actor2->pos.y){
                actor->status = 250;
            }
            else{
                actor->status = 200;
            }
            break;
        case 200:
            func_80008C6C(0x44, 2);
            actor->actorVars.varA4.fp = 0.0f;
            actor->actorVars.varA8.fp = actor2->pos.y;
            actor->status = 201;
            
            break;
        case 201:
            t1 = func_80074E68(actor->rot.y, func_800253B0(idx, temp1));
            
            if(actor->actorVars.varA4.fp < 6.0f){
                actor->actorVars.varA4.fp += 0.1;
            }
            if(actor->actorVars.varA8.fp + 50.0f < actor->pos.y){
                func_800259B4(actor, actor->actorVars.varA8.fp, 4.0f, 0.5f);
            }
            else{
                actor->dir.y *= 0.9;
            }
            if(t1 > 90.0f || t1 < -90.0f){
                if((func_80011528(0) & 0x64U) > 50){
                    actor->actorVars.varA0.integer = 90;
                    actor->status = 203;
                }
                else{
                    actor->status = 202;
                }
            }
            if(D_80141CB0[idx].unk0 != -1){
                func_80008C6C(7, 2);
            }

            func_80024F20(idx, actor->actorVars.varA4.fp);
            func_800545DC(actor);
            break;
        case 202:
            actor->unk8 = 0x100;

            if(actor->dir.x < 0.1 && actor->dir.z < 0.1 && actor->dir.y < 0.1){
                actor->status = 350;
            }

            actor->dir.y *= 0.9;
            actor->dir.x *= 0.98;
            actor->dir.z *= 0.98;

            func_80025454(actor, actor2, 16.0f);
            func_800545DC(actor);
            break;
        case 203:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 202;
            }

            actor->dir.y *= 0.9;
            func_80025454(actor, actor2, 32.0f);
            func_80024F20(idx, actor->actorVars.varA4.fp);
            func_800545DC(actor);
            break;
        case 250:
            actor->actorVars.varA8.fp = actor2->pos.y;  
            
            func_80022F48(idx, 3);
            actor->actorVars.varB4.integer = 30;
            
            actor->actorVars.varA0.integer = 240;
            actor->actorVars.varA4.fp = 0.0f;
            
            actor->status = 251;
            break;
        case 251:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 50;
            }
            if(actor->pos.y < actor->actorVars.varA8.fp){
                func_800259B4(actor, actor->actorVars.varA8.fp, 5.0f, 0.4f);
            }
            else{
                actor->dir.y *= 0.95;

                if(actor->dir.y < 0.1 && actor->actorVars.varA4.fp < -1.0f){
                    actor->status = 252;
                }
            }
            if(temp > 200.0f){
                if(actor->actorVars.varA4.fp < 4.0f){
                    actor->actorVars.varA4.fp += 0.1;
                }
            }
            else if(actor->actorVars.varA4.fp > -2.0f){
                actor->actorVars.varA4.fp -= 0.2;
            }    

            func_80025454(actor, actor2, 16.0f);
            func_80024F20(idx, actor->actorVars.varA4.fp);
            func_800545DC(actor);
            break;
        case 252:
            actor->status = 300;
            break;
        case 300:
            func_80022F48(idx, 0);
            actor->unk8 = 0x100;
            actor->actorVars.varB0.integer = 0;
            actor->actorVars.varA0.integer = 136;
            actor->status = 301;
            break;
        case 301:
            
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB0.integer = 1;
                actor->unk8 = 0x100;
                actor->status = 50;
            }
            if(actor->actorVars.varA0.integer > 100){
                func_80025454(actor, actor2, 8.0f);
                func_80024FC8(idx, 0.1f, 0.05f);
            }
            else if(actor->actorVars.varA0.integer > 86){
                func_80024FC8(idx, 8.0f, -12.0f);
            }
            else if(actor->actorVars.varA0.integer > 72){
                func_80024FC8(idx, -1.0f, 1.0f);
            }
            if(actor->actorVars.varA0.integer == 100){
                func_80008C6C(0x17, 2);
            }

            func_800545DC(actor);
            break;
        case 350:
            func_80022F48(idx, 1);
            actor->actorVars.varB0.integer = 0;
            actor->actorVars.varA0.integer = 18;
            actor->status = 351;
            break;
        case 351:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB0.integer = 1;
                actor->status = 50;
            }
            if(actor->actorVars.varA0.integer == 8){
                func_80008C6C(0x16, 2);

                for(i = 0; i < 2; i++){
                    id = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_80054070);
                        func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y + 120.0f + (i*120), 30.0f, 40.0f);
                        GET_ACTOR_PTR(id)->actorVars.varAC.fp = actor->actorVars.varAC.fp + 40.0f;
                    }
                }
            }
            break;
        case 400:
            func_80022F48(idx, 1);
            actor->actorVars.varB0.integer = 0;
            actor->actorVars.varA0.integer = 18;
            actor->status = 401;
            break;
        case 401:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB0.integer = 01;
                actor->status = 250;
            }
            if(actor->actorVars.varA0.integer == 8){
                func_80008C6C(0x16, 2);

                for(i = 0; i < 4; i++){
                    id = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y - 90.0f + (i * 60), 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_800543A4);
                        func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y + 120.0f + (i*120), 30.0f, 40.0f);
                        func_80024FC8(id, 1.0f, -0.5f);
                    }
                }
            }
            break;
        case 450:
            func_80022F48(idx, 4);
            func_80023644(6, 0x161, actor->pos.x, actor->pos.y + 30.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
            func_80008C6C(0xD, 2);

            actor->unk8 = 0x53F;
            actor->actorVars.varB0.integer = 0;
            actor->actorVars.varA0.integer = 45;
            actor->status = 451;
            actor->actorVars.varA4.fp = -1.0f;
            break;
        case 451:
            func_80024FC8(idx, actor->actorVars.varA4.fp, 0.0f);
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80022F48(idx, 3);
                actor->actorVars.varB0.integer = 1;
                actor->actorVars.varB4.integer = 30;
                func_80024FC8(idx, 16.0f, 0.0f);
                func_800545DC(actor);
                actor->actorVars.varA0.integer = 30;
                actor->status = 452;
            }

            actor->actorVars.varA4.fp *= 0.95;
            func_800545DC(actor);
            break;
        case 452:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 453;
            }

            func_80025454(actor, actor2, 6.0f);
            actor->dir.y += 0.05;
            func_800545DC(actor);
            break;
        case 453:
            if(actor->dir.x < 0.1 && actor->dir.y < 0.1 && actor->dir.z < 0.1){
                actor->unk8 = 0x100;
                actor->status = 50;
            }

            actor->dir.x *= 0.95;
            actor->dir.y *= 0.95;
            actor->dir.z *= 0.95;
            func_800545DC(actor);
            break;
        case 500:
            func_80022F48(idx, 3);
            actor->actorVars.varB4.integer = 30;
            actor->status = 501;
            break;
        case 501:
            if(actor->pos.y < actor2->pos.y + 300.0f){
                actor->status = 502;
            }

            func_8002592C(actor, actor2, 8.0f, 0.5f);
            func_80025454(actor, actor2, 16.0f);
            func_800545DC(actor);
            break;
        case 502:
            if(actor->dir.y < 0.1){
                actor->status = 50;
            }

            actor->dir.y *= 0.97;
            func_80025454(actor, actor2, 16.0f);
            func_800545DC(actor);
            break;
        case 900:
            cdata.unk46[cdata.nextstg] |= 0x4000;
            D_800E69C0.unkD &= ~0x1;
            func_80022F48(idx, 4);
            func_80008C6C(0xD, 2);

            actor->actorVars.varB0.integer = 0;
            actor->flags |= 0x10;
            actor->actorVars.varA0.integer = 45;
            actor->status = 901;
            actor->actorVars.varA4.fp = -1.0f;
            break;
        case 901:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80022F48(idx, 3);
                actor->actorVars.varB0.integer = 1;
                actor->actorVars.varB4.integer = 30;
                actor->actorVars.varA0.integer = 120;
                actor->status = 902;
            } 

            func_80024FC8(idx, actor->actorVars.varA4.fp, 0.0f);
            actor->actorVars.varA4.fp *= 0.95;
            func_800545DC(actor);
            break;
        case 902:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA4.fp = 4.0f;
                
                actor->status = 903;
            }
            break;
        case 903:
            if(actor->actorVars.varA4.fp < 0.1){
                func_80022F48(idx, 5);
                func_80008C6C(8, 2);
                actor->actorVars.varB0.integer = 0;
                actor->status = 904;
            }

            func_80024FC8(idx, 0.0f, actor->actorVars.varA4.fp);
            func_800545DC(actor);
            actor->actorVars.varA4.fp *= 0.97;
            break;
        case 904:
            actor->dir.y -= D_80159170/4;
            func_800545DC(actor);

            if(D_800F9910.unk1 != 0){
                func_80008C6C(0xC, 2);
                func_80022F48(idx, 6);

                D_80142BD0 = 0.0f;
                D_8014DF90 = 0.0f;

                id = func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8004F0B0);
                    GET_ACTOR_PTR(id)->flags = 0x20000;
                }

                actor->actorVars.varA0.integer = 200;
                actor->status = 905;
            }
            if(actor->pos.y < actor->actorVars.varAC.fp - 800.0f){
                func_80023644(1, 0x15, 1808.0f, 401.0f, 836.0f, 0.0f, 0.0f, 0.0f);

                if(!func_80076FA0(0x30)){
                    id = func_80023644(1, 0x42, 1808.0f, 471.0f, 836.0f, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002D07C);
                    }
                }
                else{
                    id = func_80023644(1, 0x30, 1808.0f, 471.0f, 836.0f, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002D07C);
                    }
                }

                actor->status = 1100;
            }
            break;
        case 905:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 120;
                actor->status = 1000;
            }
            for(i = 0; i < 1; i++){
                t1 = (func_80011528(0) % 100U) - 50.0f;
                t2 = (func_80011528(0) % 100U) - 50.0f;

                id = func_80023644(6, 0x183, actor->pos.x + t1, actor->pos.y, actor->pos.z + t2, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002C0BC);

                    if(func_80011528(0) & (0,actor->actorVars.varA0.integer < 100)){
                        func_800242F0(id, 0, 2);
                        func_80008C6C(4, 2);
                    }
                    else{
                        func_80008C6C(0xC, 2);
                    }
                }
                
            }
            break;

        case 1000:
            if(func_80077548() != 0){
                D_800E6B20_2022_sets(0x1C, 0xB4);
                actor->status = 1001;
            }
            break;
        case 1001:
            if(!func_80012D40(0xB, actor->actorVars.varD0.integer % 2U + 4, 1)){
                D_800E69C0.unkD &= ~0x1;
                D_800E6B20_sets2(0x4B, 0xB7, cdata.unk6A, 1, 0xB, 4, 5);
                actor2->flags &= ~0x4000;
                D_800F0588.unk30 = 0;
                actor->status = 906;
            }
            break;
        case 906:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(0xDB, 2);
                func_80023644(1, 0x15, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                if(!func_80076FA0(0x30)){
                    id = func_80023644(1, 0x42, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002D07C);
                    }
                }
                else{
                    id = func_80023644(1, 0x30, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002D07C);
                    }
                }
                for(i = 0; i < 32; i++){
                    t1 = (func_80011528(0) % 100U) - 50.0f;
                    t2 = func_80011528(0) % 100U;
                    t3 = (func_80011528(0) % 100U) - 50.0f;

                    id = func_80023644(6, 0x189, actor->pos.x + t1, actor->pos.y + t2, actor->pos.z + t3, 0.0f, 0.0f, 0.0f);
                }

                func_80023FCC(idx);
                D_800E69C0.unkD |= 1;
            }
            if(actor->actorVars.varA0.integer == 2){
                func_80008C6C(0xDB, 3);
            }
            break;
        case 1100:
            if(func_80077548()){
                D_800E6B20_2022_sets(0x1C, 0xB4);
                actor->status = 1101;
            } 
            break;
        case 1101:
            if(!func_80012D40(0xB, 6, 1)){
                D_800E6B20_sets2(0x4B, 0xB7, cdata.unk6A, 1, 0xB, 4, 5);
                actor2->flags &= ~0x4000;
                D_800F0588.unk30 = 0;
                func_80023FCC(idx);
                D_800E69C0.unkD |= 1;
            }
            break;
    }
    switch(actor->actorVars.varC0.integer){
        case 2:
            break;
        case 0:
            if(actor->status == 51){
                actor->status = 100;
                actor->actorVars.varC0.integer = 1;
            }
            break;
        case 1:
            if(actor->status == 51){
                if(actor2->pos.y + 300.0f < actor->pos.y){
                    actor->status = 500;
                }
                else{
                    actor->status = 150;
                }

                actor->actorVars.varC0.integer = 1;
            }
            break;
    }
    if(actor->actorVars.varCC.integer != actor->unk74){
        actor->status = 450;
    }
    if(actor->unk74 <= 0){
        actor->unk74 = 0;
        actor->actorVars.varCC.integer = 0;

        if(actor->status < 900){
            actor->status = 900;
        }
    }
    actor->actorVars.varCC.integer = actor->unk74;
    temp4 = actor->actorVars.varB4.integer-- ^ 30;
    
    if(temp4 == 0){
        if(actor->actorVars.varB0.integer){
            func_80008E10(0x16, 3, idx);
        }
    }
    else if(actor->actorVars.varB4.integer < -1){
        actor->actorVars.varB4.integer = 30;
    }
}

void func_80054070(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 id;

    switch(actor->status){
        case 0:
            actor->actorVars.varA0.fp = 0.0f;
            actor->actorVars.varA8.fp = 0.4f;
            func_80024874(idx, 0.4f);
            actor->status = 1;
            break;
        case 1:
            actor->actorVars.varA8.fp *= 0.99;
            func_80024874(idx, actor->actorVars.varA8.fp);

            if(actor->actorVars.varA8.fp < 0.06){
                func_80023FCC(idx);
            }
            else{
                actor->actorVars.varA0.fp += 10.0f;
                
                NORM_ANGLE(actor->actorVars.varA0.fp);
            
                func_80024FC8(idx, (0.41 - actor->actorVars.varA8.fp) * 10.0f, 0.0f);
                func_800259B4(actor, actor->actorVars.varAC.fp, 4.0f, 0.3f);
                func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            
                if(D_800F9910.unk1 != 0){
                    func_80023FCC(idx);
                }

                func_8002507C(idx);

                for(i = 0; i < 3; i++){
                    id = func_80023644(6, 0x141, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, actor->actorVars.varA0.fp + (i*120), 0.0f);
                    actor->actorVars.varA4.integer = id;

                    if(id != -1){
                        func_80022F20(actor->actorVars.varA4.integer, func_8002C20C);
                        func_80024874(actor->actorVars.varA4.integer, actor->actorVars.varA8.fp);
                        func_80024F20(actor->actorVars.varA4.integer, 6.0f);
                    }
                }
            }
            
            break;
    }
}
void func_800543A4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 =  GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s16 id;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.fp = 0.4f;
            func_80024874(idx, 0.4f);
            actor->status = 1;
            break;
        case 1:
            func_80025A44(actor, actor2, 0.15f, 30.0f);
            func_80025B90(actor, 5.0f, 3.0f, 5.0f);
            actor->actorVars.varA0.fp *= 0.99;
            if(idx);
            
            func_80024874(idx, actor->actorVars.varA0.fp);

            if(actor->actorVars.varA0.fp < 0.06){
                func_80023FCC(idx);
            }
            else{
                func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);

                if(D_800F9910.unk1 != 0 || D_80141CB0[idx].unk0 != -1){
                    func_80023FCC(idx);
                }

                func_8002507C(idx);
                id = func_80023644(6, 0x141, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
                actor->actorVars.varA4.integer = id;

                if(id != -1){
                    func_80022F20(actor->actorVars.varA4.integer, func_8002C20C);
                    func_80024874(actor->actorVars.varA4.integer, actor->actorVars.varA0.fp);
                    func_80024F20(actor->actorVars.varA4.integer, 0.0f);
                    
                }
            }
            break;
    }
}
void func_800545DC(Actor* actor){
    func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
    actor->pos.x = D_800F9910.unkC;
    actor->pos.y = D_800F9910.unk10;
    actor->pos.z = D_800F9910.unk14;
}
