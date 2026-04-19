#include "55270.h"
#include "52E50.h"
#include "4D980.h"
#include "2DE50.h"
#include "29980.h"
#include "23B20.h"
#include "1D870.h"
#include "13940.h"
#include "9320.h"
#include "684A0.h"
#include "73660.h"
#include "11F10.h"
#include "15F60.h"
#include "1D870.h"
#include "common.h"
 
extern f32 D_80154614;
extern f32 D_80154618;
extern f32 D_8015461C;
extern f32 D_80154620;
extern f32 D_80154624;
 
extern f32 D_80159170;

extern f32 D_801545FC;
extern f32 D_80154600;
extern f32 D_80154604;

void func_80054670(s16 idx){
    s32 pad;
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0); 
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    f32 temp3;
    f32 temp4;
    Actor* actor3;
    f32 temp5;
    s16 id;
    s16 temp1 = D_80159178->unk48[cdata.unk41].unk0;
    f32 temp = func_80024E0C(idx, temp1);

    (void)"shadow = %d\n";
    
    D_80154618 = func_800253B0(temp1, idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varD0.integer = cdata.unk46[cdata.nextstg] >> 0xE;
            cdata.unk46[cdata.nextstg] |= 0x8000;

            actor->unk4E = 2;
            actor->unk6C = 0xB;
            actor->unk8 = 0x53F;
            actor->a = 0;

            func_80022F48(idx, 9);
            
            actor->actorVars.varC8.integer = 0;
            actor->actorVars.varCC.integer = actor->unk74;
            
            actor->actorVars.varB0.fp = -10000.0f;
            actor->actorVars.varB4.integer = -0x64;
            
            D_80154614 = D_80154618;
            D_8015461C = 50.0f;
            D_80154620 = 60.0f;
            
            actor->status = 100;
            break;
        case 50:
            actor->unk8 = 0x53F;
            func_80022F48(idx, 0);

            actor->actorVars.varC8.integer++;

            if(actor->actorVars.varC8.integer > 65535){
                actor->actorVars.varC8.integer = 0;
            }
            
            actor->status = 51;
            break;
        case 51:
            break;
        case 100:
            D_800F05B8 = 1;
            func_80022F48(idx, 9);
            
            actor->actorVars.varA0.integer = 255;
            actor->status = 101;
            break;
        case 101:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 145;
                actor->status = 102;
            }

            if(actor->actorVars.varA0.integer % 2U){
                actor->a++;
            }
            break;
        case 102:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                for(i = 0; i < 2; i++){
                    id = func_80023644(5, 0x18A, actor->pos.x - 60.0f + (i*120), actor->pos.y + 30.0f, actor->pos.z, 0.0f, i*180, 0.0f);

                    if(id != -1){
                        func_80024874(id, 0.4f);
                        func_80022F20(id, func_800567A0);
                        func_80024FC8(id, 3.0f, i*60 - 30);

                        GET_ACTOR_PTR(id)->flags |= 0x20;
                        GET_ACTOR_PTR(id)->actorVars.varA0.integer = idx;
                        GET_ACTOR_PTR(id)->actorVars.varA4.integer = i+1;
                        GET_ACTOR_PTR(id)->actorVars.varA8.fp = i;
                        actor->actorVars.rawVars[i+6].integer = id;
                    }
                }
            }
            else{
                break;
            }

            func_80022528(1, 2, actor->pos.x, actor->pos.y, actor->pos.z, 255.0f, 160.0f, 50.0f);
            func_80022528(2, 2, actor->pos.x, actor->pos.y, actor->pos.z, 50.0f, 160.0f, 255.0f);

            actor->a = 255;

            func_80022F48(idx, 8);
            actor->actorVars.varA0.integer = 1;

            actor->status = 1000;
            break;
        case 1000:
            D_800E6B20_2022_sets(0x1C, 0xB4);
            actor->status = 1001;
            break;
        case 1001:
            if(!func_80012D40(9, actor->actorVars.varD0.integer, 1)){
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;\
                
                actor2->flags &= ~0x4000;
                actor->status = 103;
            }
            break;
        case 103:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80022F48(idx, 4);
                actor->actorVars.varB4.integer = 0xE;
                actor->actorVars.varA0.integer = 92;
                actor->status = 104;
            }
            break;
        case 104:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(8, 2);
                actor->status = 105;
                actor->actorVars.varA4.fp = 0.0f;
            }
            break;
        case 105:
            actor->actorVars.varA4.fp += 0.1;
            func_800256CC(actor, 135.0f, -1402.0f, 16.0f);
            func_80024FC8(idx, actor->actorVars.varA4.fp, -1.0f);
            func_80056894(actor);

            if(D_800F9910.unk1 == 0){
                actor->status = 106;
            }
            break;
        case 106:
            actor->dir.y -= D_80159170/4;
            func_80056894(actor);
            
            if(D_800F9910.unk1 != 0){
                func_80008C6C(7, 2);
                actor->dir.y *= -0.5;
                actor->dir.x *= 0.75;
                actor->dir.z *= 0.75;
            }
            if(actor->dir.x < 0.1){
                actor->status = 107;
            }
            break;
        case 107:
            actor->actorVars.varB4.integer = -0x64;
            func_80022F48(idx, 0);
            actor->status = 108;
            actor->actorVars.varB0.fp = actor->pos.y - 20.0f;
            break;
        case 108:
            if(temp < 300.0f){
                actor->status = 1050;
            }

            func_80025454(actor, actor2, 16.0f);
            break;
        case 1050:
            D_800E6B20_2022_sets(0x1C, 0xB4);
            actor->status = 1051;
            break;
        case 1051:
            if(!func_80012D40(9, actor->actorVars.varD0.integer+4, 1)){
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;\
                
                actor2->flags &= ~0x4000;
                actor->status = 50;
            }
            break;
        case 150:
            actor->unk8 = 0x100;
            func_80022F48(idx, 4);
            actor->actorVars.varB4.integer = 0xE;
            actor->actorVars.varA0.integer = 92;
            
            if(actor->actorVars.varC8.integer < 0xA){
                actor->actorVars.varA8.integer = 1;
            }
            else if(actor->actorVars.varC8.integer < 0x14){
                actor->actorVars.varA8.integer = 2;
            }
            else if(actor->actorVars.varC8.integer < 0x1E){
                actor->actorVars.varA8.integer = 3;
            }
            else if(actor->actorVars.varA8.integer < 0x28){
                actor->actorVars.varA8.integer = 4;
            }
            else{
                actor->actorVars.varA8.integer = 5;
            }

            actor->actorVars.varAC.integer = 1;

            actor->status = 151;
            
            break;
        case 151:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB4.integer = -0x64;
                actor->unk8 = 0x53F;
                func_80022F48(idx, 1);
                actor->actorVars.varA0.integer = 72;
                actor->status = 152;
            }

            func_80025454(actor, actor2, 8.0f);
            break;
        case 152:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA8.integer--;

                if(actor->actorVars.varA8.integer <= 0){
                    actor->status = 50;
                }
                else{
                   func_80022F48(idx, 1);
                    actor->actorVars.varA0.integer = 72;
                }
            }
            if(actor->actorVars.varA0.integer >= 45){
                func_80025454(actor, actor2, 8.0f);
            }
            if(actor->actorVars.varA0.integer == 44 && actor->actorVars.varAC.integer == 1){
                id = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y, 0.0f);

                if(id != -1){
                    func_80008C6C(0x12, 2);
                    func_80022F20(id, func_800543A4);
                    func_80025638(GET_ACTOR_PTR(id), actor, 330.0f, 30.0f, 40.0f);
                    func_80024FC8(id, 1.0f, 0.0f);
                }
                if(1);
            }
            if(actor->actorVars.varA0.integer == 40 && actor->actorVars.varA8.integer >= 2){
                actor->actorVars.varA0.integer = 1;
            }
            break;
        case 200:
            func_80022F48(idx, 0);
            func_80008C6C(8, 2);

            for(i = 0; i < 20; i++){
                id = func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8004ED68);
                }
            }

            actor->a = 90;
            actor->actorVars.varA0.integer = 90;
            actor->status = 201;
            break;
        case 201:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80022F48(idx, 4);
                actor->actorVars.varB4.integer = 0xE;
                actor->actorVars.varA0.integer = 240;
                actor->status = 202;
            }
            break;
        case 202:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 120;
                actor->status = 203;
            }

            func_80025A44(actor, actor2, 0.1f, 30.0f);
            func_80025B90(actor, 7.0f, 7.0f, 7.0f);
            func_80025454(actor, actor2, 16.0f);
            func_80056894(actor);
            break;
        case 203:
            if(actor->a > 0){
                actor->a--;
            }

            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB4.integer = -0x64;
                func_80008C6C(8, 2);
                func_80022F48(idx, 0);
                actor->unk8 = 0x100;
                actor->actorVars.varA0.integer = 120;
                actor->status = 204;
            }

            func_80025A44(actor, actor2, 0.1f, 30.0f);
            func_80025B90(actor, 7.0f, 7.0f, 7.0f);
            func_80025454(actor, actor2, 16.0f);
            func_80056894(actor);
            break;
        case 204:
            actor->dir.x *= 0.9;
            actor->dir.z *= 0.9;
            actor->dir.y -= D_80159170 * 0.25;

            func_80056894(actor);

            if(actor->a < 255){
                actor->a++;
            }

            if(D_800F9910.unk1 != 0 && actor->a == 255){
                actor->status = 50;
            }
            break;
        case 250:
            func_80022F48(idx, 5);
            actor->actorVars.varA0.integer = 300;
            actor->actorVars.varA8.integer = 0;
            actor->unk6D = 0x80;
            actor->status = 251;
            break;
        case 251:
            actor->actorVars.varA8.integer = actor->unk6D;
            actor->actorVars.varA0.integer--;
                
            if(actor->actorVars.varA0.integer <= 0 || D_80141CB0[idx].unk0 != -1){
                actor->unk8 = 0x100;
                func_80022F48(idx, 4);
                actor->actorVars.varB4.integer = 0xE;
                actor->actorVars.varA0.integer = 72;
                actor->status = 252;
            }
            if(temp < 200.0f){
                actor->unk6D = 0x100;
                actor->actorVars.varA4.fp = 4.0f;
            }
            else if(temp < 250.0f){
                actor->unk6D = 1;
                actor->actorVars.varA4.fp = 0.0f;
            }
            else if(temp < 400.0f){
                actor->unk6D = 0x96;
                actor->actorVars.varA4.fp = 2.0f;
            }
            else{
                actor->actorVars.varA4.fp = 1.6f;
                actor->unk6D = 0x80;
            }
            if(actor->actorVars.varA8.integer != actor->unk6D){
                actor->unk52 = 0;
            }
            if(actor->actorVars.varA4.fp > 0.0f){
                func_80025454(actor, actor2, 8.0f);
                func_80024FC8(idx, actor->actorVars.varA4.fp, -1.0f);
                func_80056894(actor);
            }
            break;
        case 252:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varB4.integer = -0x64;
                actor->unk8 = 0x53F;
                actor->status = 50;
            }
            break;
        case 300:
            func_80022F48(idx, 2);
            actor->actorVars.varA0.integer = 49;
            actor->actorVars.varAC.integer = -1;
            actor->actorVars.varA8.integer = 0;
            actor->status = 301;
            break;
        case 301:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 302;
            }
            if(actor->actorVars.varA0.integer < 12){
                if(actor->actorVars.varAC.integer == -1){
                    id = func_80023644(5, 0x12C, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                    actor->actorVars.varAC.integer = id;

                    if(id != -1){
                        func_80008C6C(0x11, 2);
                        actor3 = GET_ACTOR_PTR(actor->actorVars.varAC.integer);

                        if(actor3->unk38 != 0xFFFF){
                            func_80024874(actor3->unk70, 1.0f);
                            actor3->unk4A = 7;
                            actor3->flags = 0x420;
                            actor3->unk72 = 1;
                            actor3->r = 255;
                            actor3->g = 255;
                            actor3->b = 255;
                            actor3->a = 255;
                            actor3->unk4C = actor3->unk72;

                            D_801414A0[actor3->unk38]->unk6 = 0x4E;
                            D_801414A0[actor3->unk38]->unk8 = D_801414A0[actor3->unk38]->unk6;

                            D_801414A0[actor3->unk38]->unk50 = 2;
                            D_801414A0[actor3->unk38]->unk54 = 35.0f;
                            D_801414A0[actor3->unk38]->unk58 = 30.0f;

                            func_80024874(actor->actorVars.varAC.integer, 1.0f);
                            func_80022F20(actor->actorVars.varAC.integer, NULL);
                            func_80025638(GET_ACTOR_PTR(actor->actorVars.varAC.integer), actor, actor->rot.y -10.0f, 50.0f, 42.0f);
                            func_800242F0(idx, 0xE, 0xFFFF);

                            D_801414A0[actor3->unk38]->unk30 = 0.0f;
                            D_801414A0[actor3->unk38]->unk34 = 0.0f;
                            D_801414A0[actor3->unk38]->unk38 = 0.0f;

                            actor3->rot.x = 270.0f;
                            actor3->rot.y = actor->rot.y;
                            actor3->rot.z = 0.0f;
                        }
                        else{
                            func_80022F48(idx, 3);
                            func_80023FCC(actor->actorVars.varAC.integer);
                            func_80024348(idx, 0xE);
                            actor->actorVars.varA0.integer = 59;
                            actor->status = 304;
                        }
                    }
                }
                
                if(actor->actorVars.varAC.integer != -1){
                    actor3 = GET_ACTOR_PTR(actor->actorVars.varAC.integer);
                    func_80024FC8(actor->actorVars.varAC.integer, 8.0f, 0.0f);
                    func_80056894(actor3);

                    actor->actorVars.varA8.integer++;
                    
                    if(D_800F9910.unk1 != 0){
                        for(i = 0; i < 30; i++){
                            func_80068264(actor3, 50.0f, 0.0f);
                        }

                        func_80008C6C(0x11, 2);
                        actor->status = 303;
                    }

                    func_8006846C(actor3, 15.0f, 0.0f, actor3->rot.y + 180.0f, 1.0f, 0.0f);
                }
            }
            else{
                func_80025454(actor, actor2, 8.0f);
            }
            break;
        case 302:
            actor3 = GET_ACTOR_PTR(actor->actorVars.varAC.integer);
            
            func_80024FC8(actor->actorVars.varAC.integer, 8.0f, 0.0f);
            func_80056894(actor3);

            actor->actorVars.varA8.integer++;

            if(actor->actorVars.varA8.integer > 60 || D_800F9910.unk1 != 0){
                for(i = 0; i < 30; i++){
                    func_80068264(actor3, 50.0f, 0.0f);
                }

                func_80008C6C(0x11, 2);
                actor->status = 303;
            }

            func_8006846C(actor3, 15.0f, 0.0f, actor3->rot.y + 180.0f, 1.0f, 0.0f);
            break;
        case 303:
            func_80024FC8(actor->actorVars.varAC.integer, -8.0f, 0.0f);
            func_8002507C(actor->actorVars.varAC.integer);

            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer <= 0){
                func_80022F48(idx, 3);
                func_80023FCC(actor->actorVars.varAC.integer);
                func_80024348(idx, 0xE);
                actor->actorVars.varA0.integer = 59;
                actor->status = 304;
            }
            break;
        case 304:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 50;
            }
            break;
        case 350:
            func_80023644(6, 0x161, actor->pos.x, actor->pos.y + 30.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
            func_80008C6C(0xD, 2);
            
            actor->unk8 = 0x53F;
            actor->a = 255;

            func_80022F48(idx, 6);
            actor->actorVars.varA0.integer = 58;
            actor->actorVars.varB4.integer = -0x64;
            actor->status = 351;
            break;
        case 351:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 50;
            }
            break;
        case 900:
            cdata.unk46[cdata.nextstg] |= 0x4000;
            D_800E69C0.unkD &= ~0x1;
            func_80008C6C(0x44, 3);
            func_80023644(6, 0x161, actor->pos.x, actor->pos.y + 30.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
            func_80008C6C(0xD, 2);
            actor->a = 255;
            actor->unk4E = 0;

            func_8002263C(1);
            func_8002263C(2);
            func_80023FCC(actor->actorVars.varB8.integer);
            func_80023FCC(actor->actorVars.varBC.integer);

            actor->flags |= 0x10;
            actor->actorVars.varB4.integer = -0x64;
            actor->actorVars.varA0.integer = 60;
            actor->status = 901;
            break;
        case 901:
            if(func_80077548() != 0){
                func_80025FE8(temp1, idx, 10.0f, 70.0f, -10.0f, 50.0f, 50.0f, 10.0f, 90.0f);
                D_800F05B8 = 0;
                D_800E6B20_2022_sets(0x1C, 0xB4);
                actor->actorVars.varA0.integer = 90;
                actor->status = 902;
            }
            break;
        case 902:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 903;
            }

            func_80026380();
            break;
        case 903:
            if(!func_80012D40(9, (actor->actorVars.varD0.integer % 2U) + 8, 1)){
                D_800E69C0.unkD &= ~0x1;
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;
                

                func_80025FE8(temp1, idx, 200.0f, 600.0f, -20.0f, 50.0f, 50.0f, 20.0f, 40.0f);
                actor2->flags |= 0x4000;
                actor->actorVars.varA0.integer = 40;
                actor->status = 904;
            }
            break;
        case 904:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 500;
                actor->status = 905;
            }

            D_801545FC *= 0.98;
            D_80154600 *= 0.98;
            D_80154604 *= 0.98;
            func_80026380();
            break;
        case 905:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->actorVars.varA0.integer = 120;
                actor->status = 906;
            }
            if((actor->actorVars.varA0.integer+1) % 8U == 0){
                func_8005691C(actor, 0);
                func_80008C6C(4, 2);
            }
            else{
                func_8002263C(1);
            }
            if(actor->actorVars.varA0.integer < 380 && !((actor->actorVars.varA0.integer+3) % 8U)){
                func_8005691C(actor, 1);
                func_80008C6C(0xC, 3);
            }
            else{
                func_8002263C(2);
            }
            if(actor->actorVars.varA0.integer < 260 && !((actor->actorVars.varA0.integer+5) % 8U)){
                func_8005691C(actor, 2);
                func_80008C6C(0xD, 2);
            }
            else{
                func_8002263C(3);
            }
            if(actor->actorVars.varA0.integer < 200 && !(actor->actorVars.varA0.integer % 8U)){
                temp3 = ((func_80011528(0) % 300U) - 150.0f);
                temp4 = (func_80011528(0) % 150U);
                temp5 = ((func_80011528(0) % 300U) - 150.0f);
                
                func_80023644(6, 0x189, actor->pos.x + temp3, actor->pos.y + temp4, actor->pos.z + temp5, 0.0f, 0.0f, 0.0f);
                func_80008C6C(0x5D, 3);
            }
            break;
        case 906:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 907;
                func_80023FCC(idx);
                D_800F05B8 = 0;
                func_80022F20(idx, func_8002D7AC);

                if(func_80076FA0(0x2E) == 0){
                    func_80022528(1, 2, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 180.0f, 80.0f, 50.0f);
                    id = func_80023644(1, 0x42, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002D07C);
                    }
                }
                else{
                    func_80022528(1, 2, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 50.0f, 80.0f, 180.0f);
                    func_80023644(1, 0x2E, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
                }

                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                D_800E69C0.unkD |= 1;
                return;
            }
            else{
                if(actor->actorVars.varA0.integer == 2 || actor->actorVars.varA0.integer == 7){
                    id = func_80023644(6, 0x161, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8004F0B0);

                        if(actor->actorVars.varA0.integer == 2){
                            func_80008C6C(0xD, 2);
                        }
                        else{
                            func_80008C6C(0xD, 3);
                        }
                    }
                }
            }
            break;
    }

    switch(actor->actorVars.varC0.integer){
        case 0:
            if(actor->status == 51){
                actor->unk8 = 0x101;
                actor->status = 150;
                actor->actorVars.varC0.integer = 1;
            }
            break;
        case 1:
            if(actor->status == 51){
                actor->status = 150;
                actor->actorVars.varC0.integer = 2;
            }
            break;
        case 2:
            if(actor->status == 51){
                actor->status = 200;
                actor->actorVars.varC0.integer = 3;
            }
            break;
        case 3:
            if(actor->status == 51){
                actor->status = 250;
                actor->actorVars.varC0.integer = 4;
            }
            break;
        case 4:
            if(actor->status == 51){
                actor->status = 300;
                actor->actorVars.varC0.integer = 1;
            }
            break;
    }

    if(actor->actorVars.varCC.integer != actor->unk74){
        actor->status = 350;
    }
    if(actor->unk74 <= 0){
        actor->unk74 = 0;
        actor->actorVars.varCC.integer = 0;

        if(actor->status < 900){
            actor->status = 900;
        }
    }

    actor->actorVars.varCC.integer = actor->unk74;
    
    if(actor->pos.y < actor->actorVars.varB0.fp){
        actor->pos.x = (func_80011528(0) % 500U) + 24.0f - 250.0f;
        actor->pos.y = 700.0f;
        actor->pos.z = (func_80011528(0) % 500U) + -977.0f - 250.0f;        
    }
    if(actor2->pos.y < actor->actorVars.varB0.fp){
        actor2->pos.x = (func_80011528(0) % 500U) + 24.0f - 250.0f;
        actor2->pos.y = 700.0f;
        actor2->pos.z = (func_80011528(0) % 500U) + -977.0f - 250.0f;
        D_800F0548.unk0 = (func_80011528(0) % 500U) + 24.0f - 250.0f;
        D_800F0548.unk4 = 700.0f; 
        D_800F0548.unk8 = (func_80011528(0) % 500U) + -977.0f - 250.0f;
        D_800F0548.unkC = (func_80011528(0) % 500U) + 24.0f - 250.0f;
        D_800F0548.unk10 = 700.0f; 
        D_800F0548.unk14 = (func_80011528(0) % 500U) + -977.0f - 250.0f;
    } 

    if(actor->actorVars.varB4.integer >= -0x63){
        actor->actorVars.varB4.integer--;
        
        if(actor->actorVars.varB4.integer <= 0){
            actor->actorVars.varB4.integer = 0xE;
            func_80008E10(0x13, 3, idx);
        }
    }

    D_800F05B8 = 1;

    if(actor->status < 902){
        func_8002646C(temp1, idx, 15.0f);
    }
    if(actor2->unk74 <= 0){
        D_800F05B8 = 0;
    }
}

void func_800567A0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(actor->actorVars.varA0.integer);
    f32 v0;
    
    func_80068264(actor, 30.0f, 0.0f);
    func_80025A44(actor, actor2, 0.15f, 40.0f);
    
    v0 = actor->actorVars.varA8.fp + 5.0f;
    func_80025B90(actor, v0, v0, v0);
    func_8002507C(idx);

    D_80142BB8[actor->actorVars.varA4.integer].unk0.x = actor->pos.x;
    D_80142BB8[actor->actorVars.varA4.integer].unk0.y = actor->pos.y;
    D_80142BB8[actor->actorVars.varA4.integer].unk0.z = actor->pos.z;
}

void func_80056894(Actor* actor){
    func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
    actor->pos.x = D_800F9910.unkC;
    actor->pos.y = D_800F9910.unk10;
    actor->pos.z = D_800F9910.unk14;
}

void func_8005691C(Actor* actor, s16 arg1){
    s16 id;
    s16 sp44;
    s16 sp42;
    s16 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    
    id = func_80023644(6, 0x18A, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y + 20.0f + (arg1 * 120) , 0.0f);

    if(id != -1){
        sp3C = (func_80011528(0) % 50U) - 25.0f;
        sp38 = (func_80011528(0) % 50U);
        sp34 = (func_80011528(0) % 50U) - 25.0f;

        switch(arg1){
            case 0:
                sp44 = (func_80011528(0) % 64U) + 0xBF;
                sp40 = 0;
                sp42 = 0;
                break;
            case 1:
                sp44 = 0;
                sp40 = (func_80011528(0) % 64U) + 0xBF;
                sp42 = 0;
                break;
            case 2:
                sp44 = 0;
                sp40 = 0;
                sp42 = (func_80011528(0) % 64U) + 0xBF;
                break;            
        }

        func_80022F20(id, func_8002CC70);
        func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y + 20.0f + (arg1 * 120), 30.0f, 80.0f);
        func_80024874(id, 0.7f);
        func_80024FC8(id, 7.0f, 8.0f);
        func_80022528(arg1+1, 2, GET_ACTOR_PTR(id)->dir.x * 30.0f + actor->pos.x + sp3C, GET_ACTOR_PTR(id)->dir.y * 10.0f + actor->pos.y + sp38, GET_ACTOR_PTR(id)->dir.z * 30.0f + actor->pos.z + sp34, sp44, sp40, sp42);
    }
    else{
        func_8002263C(arg1+1);
    }
}

