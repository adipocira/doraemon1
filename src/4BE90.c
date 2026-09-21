#include "4BE90.h"

#include "4BE0.h"
#include "9320.h"
#include "11F10.h"
#include "13940.h"
#include "15F60.h"
#include "23B20.h"
#include "29980.h" 
#include "73660.h"
#include "global.h"
#include "common.h"

extern s16 D_80144264;
extern s16 D_801458DC;

extern f32 D_80142BCC;
extern f32 D_80144248;
extern f32 D_8014DF8C;

extern f32 D_80154614;
extern f32 D_80154618;
extern f32 D_8015461C;
extern f32 D_80154620;
extern f32 D_801458D0;
extern f32 D_801458D4;
extern f32 D_801458D8;

extern Vec3f D_80144230;
extern Vec3f D_801458A8;

void func_8004B290(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(actor->actorVars.varBC.integer);
    f32 dist;
    Actor* actor3;
    f32 temp;
    f32 x; 
    f32 y;
    f32 z;
    s16 id;
    s16 a0;
    s16 id2;
    D_801414A4_struct* sp4C;
    
    (void)"(";
    (void)" sound\n";
    (void)")";

    id2 = D_80159178->unk48[cdata.unk41].unk0;
    sp4C = D_801414A4[actor->unk38];
    dist = func_80024E0C(idx, actor->actorVars.varBC.integer);
    D_80154618 = func_800253B0(id2, idx);
    id = D_80141CB0[idx].unk8;
    
    if(id != -1){
        actor3 = GET_ACTOR_PTR(id);

        y = func_80074E68(actor->rot.y, actor3->rot.y);

        if((y > 135.0f || y < -135.0f) && GET_ACTOR_PTR(idx)->status < 500){
            D_80142BB8[1].unk34 = 3;
            actor->actorVars.varB4.integer = 5;
            
            if(actor->health-- <= 0 && GET_ACTOR_PTR(idx)->status != 900){
                func_80008C6C(0xC, 2);
                GET_ACTOR_PTR(idx)->status = 700;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 520;
            }

            D_80144230.x = actor->pos.x + (actor2->pos.x - actor->pos.x) * 0.5;
            D_80144230.y = actor->pos.y + (actor2->pos.y - actor->pos.y) * 0.5;
            D_80144230.z = actor->pos.z + (actor2->pos.z - actor->pos.z) * 0.5;
            
            D_80142BB8[1].unk20 = dist + 10.0f;
            D_80142BB8[1].unk24 = 0.6375f;

            func_80023644(6, 0x161, actor3->pos.x, actor3->pos.y, actor3->pos.z, 0.0f, 0.0f, 0.0f);

            switch(GET_ACTOR_PTR(actor3->actorVars.varA4.integer)->unk48){
                case 2:
                case 4:
                    break;
                case 0:
                case 1:
                case 3:
                    func_80023FCC(id);
                    break;
            }

            func_80008C6C(0xD, 2);
        }
        else{
            switch(GET_ACTOR_PTR(actor3->actorVars.varA4.integer)->unk48){
                case 2:
                    break;
                case 1:
                    a0 = func_80023644(4, 0x12C, GET_ACTOR_PTR(id)->pos.x, GET_ACTOR_PTR(id)->pos.y, GET_ACTOR_PTR(id)->pos.z, 0.0f, random(0) % 60U + 150.0f + actor3->rot.y, 0.0f);
                    func_80023FCC(id);

                    NORM_ANGLE2(GET_ACTOR_PTR(a0)->rot.y);

                    func_80024F20(a0, 10.0f);
                    func_8002507C(a0);
                    break;
                case 0:
                    a0 = func_80023644(4, 0x131, GET_ACTOR_PTR(id)->pos.x, GET_ACTOR_PTR(id)->pos.y, GET_ACTOR_PTR(id)->pos.z, 0.0f, random(0) % 60U + 150.0f + actor3->rot.y, 0.0f);
                    func_80023FCC(id);

                    NORM_ANGLE2(GET_ACTOR_PTR(a0)->rot.y);

                    func_80024F20(a0, 10.0f);
                    func_8002507C(a0);
                    break;
                case 3:
                case 4:
                     func_80023FCC(id);
                    break;
            }
        }
    }
    if(GET_ACTOR_PTR(idx)->status >= 10 && func_80024CA0(4, idx, 300.0f) != -1 && dist > 240.0f){
        if(GET_ACTOR_PTR(idx)->status < 500 && GET_ACTOR_PTR(idx)->status != 0){
            GET_ACTOR_PTR(idx)->status = 510;
        }
    }
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_800E69C0.syscalls &= ~0x1;

            if(func_80077548() != 0){
                actor->unk66 = 0x14;
                actor->unkF0 = cdata.events[cdata.nextstg] >> 0xE;
                cdata.events[cdata.nextstg] |= 0x8000;
                
                if(!(cdata.events[cdata.nextstg] & 0x4000)){
                    func_800242F0(idx, 0xB, 0xFFFF);
                }

                func_80008C6C(8, 2);

                D_80154614 = D_80154618;
                D_8015461C = 50.0f;
                D_80154620 = 60.0f;

                GET_ACTOR_PTR(idx)->status = 1;
            }
        case 1:
            func_80016EB8(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, -10.0f, 0.0f);    
            D_80142BCC = 190.0f;
            D_8014DF8C = 190.0f;

            actor->unk8 |= 0x301;

            func_80025454(actor, actor2, 2.0f);

            if(D_800F9910.unk1 != 0){
                func_80005FC4(0x3C, 0x28, 0xF0);
                func_80008C6C(7, 2);

                GET_ACTOR_PTR(idx)->status = 600;

                actor->actorVars.varA8.integer = 2;
                actor->actorVars.varAC.integer = 20;
                
                actor->actorVars.varB0.fp = 0.0f;
                actor->actorVars.varB4.integer = 0;
                
                actor->actorVars.varBC.integer = func_80024CA0(0, idx, 10000.0f);
                
                D_80142BB8[1].unk18 = 0.0f;
                D_80142BB8[1].unk14 = 0.0f;
                D_80142BB8[1].unk28 = 255.0f;
                D_80142BB8[2].unk18 = 255.0f;
                D_80142BB8[2].unk14 = 255.0f;

                
                actor->actorVars.varC0.fp = actor->pos.x;
                actor->actorVars.varC4.fp = actor->pos.z;
                D_80142BB8[1].unk2C = 40.0f;
                
                D_80142BB8[1].unk30 = 10.0f;
                
                actor->actorVars.varB8.integer = actor->health;
                
            }
            else{
                actor->pos.y = D_800F9910.unk10;
            }
            break;
        case 600:
            actor->unk4E = 2;
            actor->unk6C = 5;

            func_80022F48(idx, 0);

            D_800E6B20_2022_sets(0x1C, 0xB4);

            GET_ACTOR_PTR(idx)->status = 601;
            break;
        case 601:
            if(!func_80012D40(3, actor->unkF0, 1)){
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;

                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                GET_ACTOR_PTR(idx)->status = 10;
            }

            func_80022F48(idx, 0);
            break;
        case 10:
            if(actor->actorVars.varAC.integer > 0){
                actor->actorVars.varAC.integer--;
            }

            actor->unk4E = 2;
            actor->unk6C = 5;
            
            func_80022F48(idx, 0);

            GET_ACTOR_PTR(idx)->status = 11;
            actor->actorVars.varA0.integer = actor->actorVars.varAC.integer * 5 + 20;
            break;
        case 11:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                if(dist > 240.0f){
                    GET_ACTOR_PTR(idx)->status = 40;
                }
                else if(dist > 100.0f){
                    GET_ACTOR_PTR(idx)->status = 30;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 20;
                }
            }
            break;
        case 20:
            func_80022F48(idx, 4);
            GET_ACTOR_PTR(idx)->status = 21;
            actor->actorVars.varA0.integer = 60;
            actor->actorVars.varB0.fp = -1.0f;
            break;
        case 21:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 22;
                actor->actorVars.varB0.fp = 3.0f;
            }
            else{
                func_80025454(actor, actor2, 15.0f);
                func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
                func_8004CCC4(idx, actor);
            }
            break;
        case 22:
            func_80022F48(idx, 0xC);
            func_80008C6C(9, 2);
            GET_ACTOR_PTR(idx)->status = 23;
            actor->actorVars.varA0.integer = 30;
            func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
            func_8004CCC4(idx, actor);
            break;
        case 23:
            if(actor->actorVars.varA0.integer < 15){
                sp4C->unk54 = 120.0f;
            }

            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                sp4C->unk54 = 50.0f;
                GET_ACTOR_PTR(idx)->status = 24;
                func_80022F48(idx, 0);
            }
            else{
                func_8004CCC4(idx, actor);
            }
            break;
        case 24:
            if(actor->actorVars.varB0.fp >= 0.0f){
                func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
                func_8004CCC4(idx, actor);
                actor->actorVars.varB0.fp -= 0.1;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 10;   
            }
            break;
        case 30:
            func_80022F48(idx, 3);
            GET_ACTOR_PTR(idx)->status = 31;
            
            actor->actorVars.varA0.integer = 4;
            actor->actorVars.varA4.integer = 30;
            actor->actorVars.varB0.fp = 1.0f;
            break;
        case 31:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                actor->actorVars.varA4.integer = 30;
                actor->actorVars.varA0.integer--;

                if(actor->actorVars.varA0.integer <= 0){
                    GET_ACTOR_PTR(idx)->status = 32;
                }
            }
            if(actor->actorVars.varA4.integer == 15){
                func_80008C6C(9, 2);
            }
            if(actor->actorVars.varA4.integer < 15){
                sp4C->unk54 = 135.0f;
            }
            else{
                sp4C->unk54 = 50.0f;
            }

            func_80025454(actor, actor2, 15.0f);
            func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
            func_8004CCC4(idx, actor);
            break;
        case 32:
            func_80022F48(idx, 0xE);
            GET_ACTOR_PTR(idx)->status = 33;
            actor->actorVars.varA0.integer = 30;
            actor->actorVars.varB0.fp = 3.0f;
            break;
        case 33:
            if(actor->actorVars.varA4.integer == 15){
                func_80008C6C(9, 2);
            }
            if(actor->actorVars.varA0.integer < 15){
                sp4C->unk54 = 160.0f;
            }

            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                sp4C->unk54 = 50.0f;
                GET_ACTOR_PTR(idx)->status = 10;
            }

            func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
            func_8004CCC4(idx, actor);
            break;
        case 40:
            if(actor->actorVars.varA8.integer <= 0){
                actor->actorVars.varA8.integer = 2;
                GET_ACTOR_PTR(idx)->status = 50;   
            }
            else{
                GET_ACTOR_PTR(idx)->status = 41;  
                actor->actorVars.varA0.integer = 60;
                actor->actorVars.varB0.fp = 0.0f;
            }
            break;
        case 41:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 42;  
            }
            else{
                func_80025454(actor, actor2, 15.0f);
            }
            break;
        case 42:
            func_80022F48(idx, 0xD);
            func_80008C6C(0xB, 2);
            GET_ACTOR_PTR(idx)->status = 43;  
            actor->actorVars.varA0.integer = 120;
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            break;
        case 43:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(0xB, 2);
                actor->actorVars.varA8.integer--;
                GET_ACTOR_PTR(idx)->status = 10;  
            }
            break;
        case 50:
            func_80022F48(idx, 2);
            GET_ACTOR_PTR(idx)->status = 53;  
            actor->actorVars.varA0.integer = 15;
            actor->actorVars.varB0.fp = 0.0f;
            func_80024FC8(idx, 0.0f, -10.0f);
            break;
        case 53:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(0xC0, 2);
                actor->actorVars.varA0.integer = 15;
            }
            if(actor->actorVars.varB0.fp < 3.0f){
                actor->actorVars.varB0.fp += 0.1;
            }
            if(dist < 100.0f){
                GET_ACTOR_PTR(idx)->status = 22;
                actor->actorVars.varA4.fp = 4.0f;
            }
            else{
                func_80025454(actor, actor2, 15.0f);
                func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
                func_8004CCC4(idx, actor);
            }
            break;
        case 500:
            func_80022F48(idx, 8);

            actor->actorVars.varA0.integer = 60;
            actor->actorVars.varB0.fp = 0.0f;
            GET_ACTOR_PTR(idx)->status = 501;
            break;
        case 501:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 502;
            }
            else{
                dist = func_80025C48(actor->actorVars.varC4.fp - actor->pos.z,actor->actorVars.varC0.fp - actor->pos.x);
                temp = func_80074E68(actor->rot.y, dist);
                actor->rot.y += temp / 2;
                
                NORM_ANGLE(actor->rot.y);
            }
            break;
        case 502:
            func_80022F48(idx, 0xB);
            func_80008C6C(0x76, 2);
            actor->actorVars.varA0.integer = 90;
            
            actor->actorVars.varA4.fp = 6.0f;
            actor->actorVars.varB0.fp = 2.5f;
            
            GET_ACTOR_PTR(idx)->status = 531;
            
            break;
        case 503:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(7, 2);
                GET_ACTOR_PTR(idx)->status = 10;
            }
            else{
                func_80024FC8(idx, actor->actorVars.varB0.fp, actor->actorVars.varA4.fp);
                func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);

                actor->pos.x = D_800F9910.unkC;
                actor->pos.y = D_800F9910.unk10;
                actor->pos.z = D_800F9910.unk14;

                actor->actorVars.varA4.fp -= 0.2;

                if(D_800F9910.unk0 == 0 && actor->actorVars.varA0.integer < 2){
                    actor->actorVars.varA0.integer = 2;
                }
            }
            break;
        case 510:
            func_80022F48(idx, 0xA);
            GET_ACTOR_PTR(idx)->status = 511;
            actor->actorVars.varA0.integer = 120;
            break;
        case 511:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 530;
            }
            if(actor->actorVars.varB0.fp >= 0.0f){
                actor->actorVars.varB0.fp -= 0.1;
            }
            if(actor->actorVars.varB0.fp < 0.0f){
                actor->actorVars.varB0.fp += 0.1;
            }

            func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
            func_8004CCC4(idx, actor);

            if(func_80024CA0(4, idx, 300.0f) == -1){
                GET_ACTOR_PTR(idx)->status = 530;
            }
            break;
        case 520:
            if(actor->health < actor->actorVars.varB8.integer){
                func_80022F48(idx, 6);
            }
            else{
                func_80022F48(idx, 7);
            }
            GET_ACTOR_PTR(idx)->status = 521;

            actor->actorVars.varA0.integer = 30;
            actor->actorVars.varB0.fp = -1.0f;
            
            break;
        case 521:
            func_80024FC8(idx, actor->actorVars.varB0.fp, -10.0f);
            func_8004CCC4(idx, actor);

            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                if(func_80024CA0(4, idx, 300.0f) != -1){
                    GET_ACTOR_PTR(idx)->status = 510;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 10;
                }
            }
            break;
        case 530:
            func_80022F48(idx, 0xB);
            actor->actorVars.varA0.integer = 90;
            actor->actorVars.varA4.fp = 6.0f;
            
            
            actor->actorVars.varB0.fp = func_80024E0C(idx, actor->actorVars.varBC.integer) / 90.0f;
            GET_ACTOR_PTR(idx)->status = 531;

            actor->rot.y = func_800253B0(idx, actor->actorVars.varBC.integer);

            break;
        case 531:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                func_80008C6C(7, 2);
                GET_ACTOR_PTR(idx)->status = 10;
            }
            else{
                func_80024FC8(idx, actor->actorVars.varB0.fp, actor->actorVars.varA4.fp);
                func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
                
                actor->pos.x = D_800F9910.unkC;
                actor->pos.y = D_800F9910.unk10;
                actor->pos.z = D_800F9910.unk14;

                actor->actorVars.varA4.fp -= 0.2;

                if(D_800F9910.unk0 == 0 && actor->actorVars.varA0.integer < 2){
                    actor->actorVars.varA0.integer = 2;
                }
            }
            break;
        case 700:
            if(func_80077548() != 0){
                actor->unk4E = 2;
                actor->unk6C = 5;

                func_80022F48(idx, 0);

                D_800E6B20_2022_sets(0x1C, 0xB4);

                GET_ACTOR_PTR(idx)->status = 701;
            }
            break;
        case 701:
            if(func_80012D40(3, actor->unkF0 % 2U + 4, 1) == 0){
                actor2->flags |= 0x4000;
                
                D_800E69C0.syscalls &= ~0x1;
                
                D_800E6B20_2022_sets(0x4B, 0xB7);
                D_800E6B20.unk19 = cdata.unk6A;
                
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;

                GET_ACTOR_PTR(idx)->status = 900;
            }

            func_80022F48(idx, 0);
            break;
        case 900:
            cdata.events[cdata.nextstg] |= 0x4000;
            actor->flags |= 0x10;
            actor->unk4E = 0;
            actor->actorVars.varCC.integer = 1;
            
            GET_ACTOR_PTR(idx)->status = 901;
            break;
        case 901:
            actor->actorVars.varC8.integer = 120;
            GET_ACTOR_PTR(idx)->status = 902;
            break;
        case 902:
            actor->actorVars.varC8.integer--;

            if(actor->actorVars.varC8.integer <= 0){
                actor->actorVars.varC8.integer = 300;
                actor->actorVars.varD0.integer = 5;
                
                D_80142BCC = 30.0f;
                D_8014DF8C = 30.0f;
                
                GET_ACTOR_PTR(idx)->status = 903;
            }
            break;
        case 903:
            actor->actorVars.varC8.integer--;

            if(actor->actorVars.varC8.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 909;
            }
            if(random(0) % 100U <= 90){
                if(actor->actorVars.varD0.integer != 0){
                    actor->actorVars.varD0.integer--;

                    if(actor->actorVars.varD0.integer <= 0){
                        actor->actorVars.varD0.integer = 5;
                        
                        actor->actorVars.varCC.integer = 1 - actor->actorVars.varCC.integer;

                        switch(actor->actorVars.varCC.integer){
                            case 0:
                                func_80008C6C(0xC, 3);
                                break;
                            case 1:
                                func_80008C6C(0xC, 3);
                                break;
                        }
                    }
                }

                x = random(0) % 160U - 80.0f;
                y = random(0) % 80U;
                z = random(0) % 160U - 80.0f;

                id = func_80023644(6, 0x189, actor->pos.x + x, actor->pos.y + y, actor->pos.z + z, 0.0f, 0.0f, 0.0f);

                D_80142BB8[2].unk34 = 3;
                
                D_801458A8.x = actor->pos.x + x;
                D_801458A8.y = actor->pos.y + y;
                D_801458A8.z = actor->pos.z + z;

                D_80142BB8[2].unk20 = 2000.0f;
                D_80142BB8[2].unk24 = 0.6375f;

                D_801458D0 = (random(0) & 0x3F) + 190.0f;
                D_801458D4 = (random(0) & 0x3F) + 64.0f;
                D_801458D8 = (random(0) & 0x3F);
            }
            break;
        case 909:
            if(func_80076FA0(0x28) == 0){
                id = func_80023644(1, 0x42, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
                
                if(id != -1){
                    func_80022F20(id, func_8002D07C);
                }
            }
            else{
                func_80023644(1, 0x28, actor->pos.x, actor->pos.y + 70.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);
            }

            D_801458DC = 0;
            func_80023FCC(idx);
            
            D_80142BCC = 255.0f;
            D_8014DF8C = 255.0f;
            
            D_800F0588.unk30 = 0;
            
            GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
            D_800E69C0.syscalls |= 1;
            
            return;
    }

    if(actor->actorVars.varB4.fp != 0.0f){
        actor->actorVars.varB4.integer--;

        D_80144248 = actor->actorVars.varB4.integer * 63;

        if(actor->actorVars.varB4.integer <= 0){
            D_80144264 = 0;
        }
    }

    D_800F0588.unk30 = 1;

    func_8002646C(id2, idx, 15.0f);

    if(actor2->health <= 0){
        D_800F0588.unk30 = 0;
    }
}

void func_8004CCC4(s16 idx, Actor* actor){
    func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);

    if(D_800F9910.unk1 != 0){
        actor->pos.x = D_800F9910.unkC;
        actor->pos.y = D_800F9910.unk10;
        actor->pos.z = D_800F9910.unk14;
    }
    else{
        GET_ACTOR_PTR(idx)->status = 500;
    }
}
