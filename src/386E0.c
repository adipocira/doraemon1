#include "386E0.h"

#include "11F10.h"
#include "13940.h"
#include "15F60.h"
#include "23B20.h"
#include "29980.h"
#include "73660.h"
//They forgot to include this header
//#include "89D30.h"
#include "6FA0.h"
#include "9320.h"
#include "7FC0.h"
#include "B4E0.h"

#include "actor.h"
#include "libc/math.h"

#include "common.h"

extern f32 D_80159170;
extern s16 D_80141CAA;

extern s16 D_802BDE50;
extern s16 D_802BDE52;
extern s16 D_802BDE54;
extern s16 D_802BDE56;

extern s16 D_800F0680;

extern u8 D_802BDB7C[];

extern u8 D_800F0630;

void func_80037AE0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s16 temp1;
    s16 temp;

    switch(actor->status){
        case 0:
            actor->flags |= 0x10;
            actor->actorVars.varA0.fp = actor->scale.x;
            actor->scale.x = actor->scale.y = actor->scale.z = actor->scale.x * 0.1;
            actor->dir.y = 2.5f;
            actor->actorVars.varA4.fp = 0.0f;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varAC.fp = D_80159170 / 4;
            actor->actorVars.varB0.integer = 3;
            actor->status = 1;
            break;
        default:
            break;
        case 1:
            actor->actorVars.varA4.fp += 1.0f;
            actor->scale.x = actor->scale.y = actor->scale.z = (actor->actorVars.varA4.fp * actor->actorVars.varA0.fp) * 0.1;

            if(actor->actorVars.varA4.fp == 10.0f){
                actor->flags &= ~0x10;
                actor->actorVars.varA4.fp = 720.0f;
                actor->status = 2;
            }
            break;
        case 2:
            if(actor->actorVars.varA4.fp == 0.0f){
                actor->status = 3;
                actor->actorVars.varA4.fp = 30.0f;
            }
            else{
                actor->actorVars.varA4.fp -= 1.0f;
            }
            break;
        case 3:
            actor->actorVars.varA4.fp -= 1.0f;

            if(actor->actorVars.varA4.fp == 0.0f){
                func_80023FCC(idx);
                return;
            }
            
            actor->scale.x = actor->scale.y = actor->scale.z = (actor->actorVars.varA4.fp * actor->actorVars.varA0.fp) * (0.1/3.0);
            
            break;
    }

    temp = actor->unk48;
    if(temp == 0x33 || temp == 0x24 || temp == 0x38){
        actor->rot.y = func_8000ADE0(actor->rot.y + 1.0);
    } 

    temp1 = D_80141CB0[idx].unk0;
    if(temp1 != -1){
        switch(temp){
            case 0x15:
                func_80008C6C(D_802BDE50, 0);
                cdata.unk22++;
                func_80022F20(idx, func_8002CF48);
                break;
            case 0x16:
                func_80008C6C(D_802BDE52, 0);
                GET_ACTOR_PTR(temp1)->unk74 += 0x32;

                if(GET_ACTOR_PTR(temp1)->unk74 >= 0xFB){
                    GET_ACTOR_PTR(temp1)->unk74 = 0xFA;
                }
                func_80022F20(idx, func_80039000);
                
                break;
            case 0x33:
                cdata.item |= 0x40;

                if(cdata.unk70 == 0){
                    func_80038F4C();
                }
                cdata.unk77 = 0;
                cdata.unk70 = 0x384;                
                cdata.unk76 = cdata.unk77;
                func_80022F20(idx, func_80039000);
                
                actor->flags |= 0x1000;
                actor->actorVars.varDC.integer = temp1;
                break;
            case 0x24:
                cdata.item |= 0x80;
                if (cdata.unk6E == 0) {
                    cdata.unk74 = D_800F0680;
                }
                cdata.unk6E = 0x4B0;
                
                func_800073C0(0x1F, 0);
                func_80022F20(idx, func_80039000);
                
                actor->flags |= 0x1000;
                actor->actorVars.varDC.integer = temp1;
                break;
            case 0x38:
                cdata.item |= 0x20;

                func_80008C6C(D_802BDE54, 0);
                actor->actorVars.varDC.integer = temp1;
                func_80022F20(idx, func_80039000);
                actor->flags |= 0x1000;
                break;
            case 0x42:
                cdata.item |= 0x40000000;
                cdata.unk24++;
                func_80008C6C(D_802BDE56, 0);
                func_80022F20(idx, func_80039000);
                break;
            default:
                func_80023FCC(idx);
                break;
        }
    }

    if(actor->actorVars.varA8.integer != 0){
        return;
    }

    func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.y);

    if(D_800F9910.unk0 != 0){    
        if(actor->actorVars.varB0.integer != 0){
            actor->actorVars.varB0.integer--;
            actor->dir.y *= -0.5;
        }
        else{
            actor->actorVars.varA8.integer = 1;
        }
    }
    else{
        actor->pos.y += actor->dir.y;
        actor->dir.y -= actor->actorVars.varAC.fp;
    }
}


void func_800380BC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 temp;

    if (actor->status == 0){
        actor->rot.y = func_8000ADE0(actor->rot.y + 1.0);
        temp = D_80141CB0[idx].unk0;
        if(temp != -1){
            switch (actor->unk48) {
                case 0x33:
                    cdata.item |= 0x40; 

                    if (cdata.unk70 == 0) {
                        func_80038F4C();
                    }
                    cdata.unk77 = 0;

                    cdata.unk70 = 0x384;
                    cdata.unk76 = cdata.unk77;
                    break;
                case 0x24:
                    cdata.item |= 0x80;
                    if (cdata.unk6E == 0) {
                        cdata.unk74 = D_800F0680;
                    }
                    cdata.unk6E = 0x4B0;
                
                    func_800073C0(0x1F, 0);
                    break;
                default:
                    func_80023FCC(idx);
                    break;
            }
            func_80022F20(idx, func_80039000);
            actor->flags |= 0x1000;
            actor->actorVars.varDC.integer = temp;
        }
    }
}


void func_80038224(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s16 temp;

    switch(actor->status){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            actor->status = 1;
            actor->rot.z = 45.0f;
            break;
        case 1:
            actor->rot.y = func_8000ADE0(actor->rot.y + 1.0);
            temp = D_80141CB0[idx].unk0;

            if(temp != -1){
                actor->actorVars.varA0.integer = temp;
                D_800E6B20_2022_sets(0x20, 0xB0);

                func_800073C0(0x25, 1);
                func_80076F2C(actor->unk48);
                func_800894B8(0x1E, 0xAE);
                
                func_800778C0(D_802BDB7C[actor->unk48 - 0x14], 1, func_80077050());
                func_80076B64(temp);
                actor->status = 2;
            }
            break;
        case 2:
            if(func_80012D40(0x13, 0, 0) == 0){
                func_80089A4C();
                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                func_80023FCC(idx);
            }
            break;
    }
}

void func_800383E4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;

    switch(actor->status){
        case 0:
            id = D_80141CB0[idx].unk0;
            
            if(id != -1){
                actor->actorVars.varA0.integer = id;
                D_800E69C0.unkD &= ~1;
                D_800E6B20_2022_sets(0x20, 0xB0);
                
                func_800073C0(0x25, 1);
                func_80076F2C(actor->unk48);
                func_800894B8(0x1E, 0xAE);
                func_800778C0(D_802BDB7C[actor->unk48 - 0x14], 3, 6);

                actor->status = 1;
            }
            break;
        case 1:
            if(func_80012D40(0x13, 0, 0) == 0){
                func_80089A4C();
                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;\

                func_80022F20(idx, func_80039000);
                actor->flags |= 0x1000;
                D_800E69C0.unkD |= 1;
            }
            break;
    }
}

void func_800385C0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 temp;
    s16 temp2 = D_80159178->unk48[cdata.unk41].unk0;
    s16 pad;
    s16 temp1;
    s16 pad1;
    s32 pad2;
    
    actor->rot.y = func_8000ADE0(actor->rot.y + 1.0);

    if(actor->unk48 == 0x1C){
        GET_ACTOR_PTR(actor->actorVars.varB4.integer)->rot.y = actor->rot.y;
    }

    temp1 = actor->unk48 - 0x14;

    switch(actor->status){
        case 0:
            actor->actorVars.varA0.integer = 0x3C;
            
            if(D_802BDB7C[actor->unk48 - 0x14] >= 5){
                func_80008C6C(0x9E, 0);
            }
            else{
                func_80008C6C(0x9F, 0);
            }

            actor->status = 5;
            break;
        case 5:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer == 0){
                actor->status = 10;
            }

            func_80024874(idx, ((0x3C - actor->actorVars.varA0.integer) / 60.0f) * actor->actorVars.varA4.fp);

            actor->pos.y += 0.8;
            actor->rot.y = func_8000ADE0(actor->rot.y + 17.0);

            if(actor->unk48 == 0x1C){
                GET_ACTOR_PTR(actor->actorVars.varB4.integer)->rot.y = actor->rot.y;
                GET_ACTOR_PTR(actor->actorVars.varB4.integer)->pos.y = actor->pos.y;

                func_80024874(actor->actorVars.varB4.integer, actor->scale.x);
            }
            break;
        
        case 10:
            D_800E69C0.unkD &= ~1;
            D_800E6B20_2022_sets(0x20, 0xB0);

            func_80076F2C(actor->unk48);
            func_800894B8(0x1E, 0xAE);

            if(D_802BDB7C[temp1] < 5){
                func_800778C0(D_802BDB7C[temp1] , 1, func_80077050());
                func_80076B64(temp2);
            }
            else{
                if(D_802BDB7C[temp1] >= 0x2D){
                    temp = 3;
                }
                else{
                    if(D_802BDB7C[temp1] >= 0x20){
                        temp = 2;
                    }
                    else{
                        temp = 1;
                    }
                }

                func_800778C0(D_802BDB7C[temp1], temp, 6U);
            }

            actor->status = 15;
                
            break;
        case 15:
            temp = (D_802BDB7C[temp1] >= 0x20 ? 1 : 0) * 1;
                
            if(func_80012D40(0x13, temp, 0) == 0){
                func_80089A4C();
                GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
                func_80023FCC(D_800F0588.unkA2);
                
                D_800E6B20_2022_sets(0x4B, 0xB7);
                D_800E6B20.unk19 = cdata.unk6A;
                
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;
                
                D_800F0630 = D_800F0588.unk1C;
                D_800F0588.unk1B = 0;
                D_800F0588.unk1D = 1;

                func_80022F20(idx, func_80039000);

                actor->flags |= 0x1000;

                if(actor->actorVars.varC8.integer & 4){
                    func_800770FC();
                }
                if(actor->unk48 == 0x1C){
                    GET_ACTOR_PTR(actor->actorVars.varB4.integer)->unk80 = func_80039000;
                }
                
                D_800E69C0.unkD |= 1;
            }
            break;
    }
}

void func_80038A0C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp;
    s16 temp2;

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->actorVars.varA0.fp = actor->pos.y;
            actor->actorVars.varA4.fp = 0.0f;
            GET_ACTOR_PTR(actor->unk70)->unk80 = NULL;
            break;
        case 1:
            temp = func_8000ADE0(actor->actorVars.varA4.fp + 5.0f);
            actor->actorVars.varA4.fp = temp;
            actor->pos.y = sinf(DEG2RAD_ALT(temp)) * 8.0f + actor->actorVars.varA0.fp;
            break;
    }
    actor->rot.y = func_8000ADE0(actor->rot.y + 3.0);

    temp2 = D_80141CB0[idx].unk0;
    
    if(temp2 != -1){
        GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->actorVars.varE0.fp += 0.5;
            
        if(GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->actorVars.varE0.fp > 24.0f){
            GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->actorVars.varE0.fp = 24.0f;
        }

        (s16)GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->actorVars.varD4.integer = 0xC;

        if(1);

        cdata.item |= 0x20;

        func_80008C6C(D_802BDE54, 0);
        func_80023FCC(idx);
    }
    
}


void func_80038BDC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);

            actor->actorVars.varB0.integer = 1;
            actor->actorVars.varB4.integer = 3;
            actor->flags |= 0x10;
            actor->status = 1;
            actor->actorVars.varA0.fp = actor->scale.x;
            actor->scale.x = 0.01f;
            actor->scale.y = 0.01f;
            actor->actorVars.varA8.fp = 3.0f;
            break;
        case 1:
            actor->scale.x += 0.01;
            actor->scale.y += 0.01;

            if(actor->actorVars.varA0.fp <= actor->scale.x){
                actor->actorVars.varA4.integer = 0x384;
                actor->flags &= ~0x10;
                actor->status = 2;
            }
            break;
        case 2:
            if(D_80141CB0[idx].unk0 != -1){
                func_80008C6C(0xDB, 0);
                cdata.unk22++;
                func_80022F20(idx, func_8002CF48);
            }
            else{
                actor->actorVars.varA4.integer--;

                if(actor->actorVars.varA4.integer <= 0){
                    actor->status = 3;
                }
            }
            break;
        case 3:
            actor->scale.x -= 0.01;
            actor->scale.y -= 0.01;

            if(actor->scale.x < 0.02){
                func_80023FCC(idx);
            }
            break;
    }

    if(actor->actorVars.varB0.integer != 0){
        actor->actorVars.varA8.fp -= D_80159170 / (4.0f * 1);

        if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < actor->pos.y){
            actor->actorVars.varAC.fp = actor->actorVars.varA8.fp;
        }
        else{
            actor->actorVars.varAC.fp = actor->actorVars.varA8.fp / 2;

            if(actor->actorVars.varAC.fp < -5.0f){
                actor->actorVars.varAC.fp = -5.0f;
            } 
        }

        func_8002524C(idx, 0.0f, actor->actorVars.varAC.fp, 0.0f);
        func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->actorVars.varAC.fp);
    
        if(D_800F9910.unk0 != 0){
            if(actor->actorVars.varB4.integer != 0){
                if(actor->actorVars.varA8.fp < 0.0f){
                    actor->actorVars.varB4.integer--;
                    actor->actorVars.varA8.fp = -actor->actorVars.varA8.fp * 0.5;
                }
            }
            else{
                actor->actorVars.varB0.integer = 0;
            }
        }
        else{
            func_8002507C(idx);
        }
    }
}


void func_80038F4C(void){
    u16 i;
    Actor* actor = GET_ACTOR_PTR(0x14); 

    D_80141CAA = TRUE;
    
    for(i = 0x14; i < 0x28; i++){
        if(actor->unk0 != 0){
            if(!(actor->flags & 0x8000)){
                actor->flags |= 0x84000;
            }
        }

        actor++;
    }
}

void func_80038FA8(){
    u16 i;
    Actor* actor = GET_ACTOR_PTR(0x14); 

    D_80141CAA = FALSE;
    
    for(i = 0x14; i < 0x28; i++){
        if(actor->unk0 != 0){
            if(!(actor->flags & 0x8000)){
                actor->flags &= ~0x84000;
            }
        }
        actor++;
    }
}

void func_80039000(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(actor->actorVars.varDC.integer);

    actor->scale.x = actor->scale.y = actor->scale.z = actor->scale.x * 0.93;

    if(actor->scale.x < 0.05){
        func_80023FCC(idx);
    }
    else{
        actor->pos.x += (actor1->pos.x - actor->pos.x) * 0.2;
        actor->pos.y += (actor1->pos.y + 20.0f - actor->pos.y) * 0.2;
        actor->pos.z += (actor1->pos.z - actor->pos.z) * 0.2;
        
    }
}

s32 func_80039110(){
    u16 count = 0;
    u16 i;

    for(i = 0; i < 32; i++){
        if(cdata.item & (1ULL << i)){
            count++;
        }
    }

    return count;
}

f32 func_800391A4(s16 idx1, s16 idx2, Vec3f* pos){
    Actor* actor = GET_ACTOR_PTR(idx2);
    Actor* actor1 = GET_ACTOR_PTR(idx1);
    f32 x;
    f32 y;
    f32 z;

    if(actor->unk0 == 0){
        return 0.0f;
    }

    x = actor->pos.x + pos->x - actor1->pos.x;
    y = actor->pos.y + pos->y - actor1->pos.y;
    z = actor->pos.z + pos->z - actor1->pos.z;
    
    return sqrtf(SQ(x) + SQ(y) + SQ(z));
}

void func_80039254(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 dist;
    f32 r = DEG2RAD_ALT(actor->rot.y);
    f32 r2;
    Vec3f pos;
    s16 id;
    f32 temp2;
    Actor* p2;
    f32 temp;
    u8 temp3;
    f32 temp4;

    pos.x = sinf(r) * 8.0f;
    pos.y = 0.0f;
    pos.z = cosf(r) * 8.0f;

    dist = func_800391A4(idx, D_80159178->unk48[cdata.unk41].unk0, &pos);

    r = func_80025C48((actor1->pos.z - actor->pos.z) + pos.z, (actor1->pos.x - actor->pos.x) + pos.x);
    r2 = DEG2RAD_ALT(r);
 
    if(dist < 30.0f && !(actor1->flags & 0x4000)){
        actor1->actorVars.varAC.fp += sinf(r2) * (31.0f - dist);
        actor1->actorVars.varB4.fp += cosf(r2) * (31.0f - dist);   
    }

    switch(actor->status){
        case 0:
            if( func_80076FA0(actor->unk68) != 0){
                (&D_801414A8)[actor->unk38]->unk30 = 90.0f;
            }
            else{
                (&D_801414A8)[actor->unk38]->unk30 = 0.0f;
                actor->unk68 = -1;
            }

            actor->actorVars.varA8.integer = 0;
            actor->dir.y = 0.0f;
            actor->actorVars.varAC.fp = D_80159170 / (2.0f * 1.0f);
            actor->actorVars.varB0.integer = 0;
            actor->status = 3;
        case 3:
            func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.y);
            
            if(D_800F9910.unk0 != 0){
                actor->pos.y = D_800F9910.unk10 + 1.0;

                if(actor->actorVars.varB0.integer >= 0xB){
                    func_80008C6C(7, 0);
                }
                if(actor->unk68 == -1){
                    actor->status = 15;
                }
                else{
                    actor->status = 5;
                }
            }
            else{
                actor->actorVars.varB0.integer++;
                actor->pos.y += actor->dir.y;
                actor->dir.y -= actor->actorVars.varAC.fp;
            }
            break;
        case 5:
            if(actor->actorVars.varC8.integer & 2){
                actor->status = 8;
            }
            if(dist < 45.0f){ 
                if(func_80074E68(actor->rot.y, r) > 0.0f){
                    temp = func_80074E68(actor->rot.y, r);
                }
                else{
                    temp = -func_80074E68(actor->rot.y, r);
                }
                if(temp < 25.0f){
                    temp = func_80074E68(actor->rot.y, func_8000ADE0(actor1->rot.y + 180.0f)) > 0.0f ? \
                         func_80074E68(actor->rot.y, func_8000ADE0(actor1->rot.y + 180.0f)) : \
                        -func_80074E68(actor->rot.y, func_8000ADE0(actor1->rot.y + 180.0f));

                    if(temp < 25.0f && func_80077548() != 0){
                        temp2 = DEG2RAD_ALT(func_8000ADE0(actor->rot.y + 45.0f));
                        D_800F0588.unk1C = D_800F0630;
                        D_800F0588.unk1B = 1;
                        D_800F0588.unk1D = 0;
                        D_800F0630 = 0xC;
                        D_800F0588.unkA2 = func_80023498(8, 0x1C2, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                        func_80022F20(D_800F0588.unkA2, func_800064F0);
                        p2 = GET_ACTOR_PTR(D_800F0588.unkA2); 
                        
                        p2->actorVars.varA4.integer = idx;
                        p2->actorVars.varA0.integer = idx;
                        
                        p2->actorVars.varB4.fp = sinf(temp2) * 110.0f;
                        p2->actorVars.varB8.fp = 25.0f;
                        p2->actorVars.varBC.fp = cosf(temp2) * 110.0f;

                        func_80008C6C(0x55, 2);

                        actor->status = 10;
                    } 
                }
            }
            break;
        case 8:
            D_800F0588.unk1C = D_800F0630;
            D_800F0588.unk1D = 0;
            D_800F0588.unk1B = 1;
            D_800F0630 = 0xC;
            D_800F0588.unkA2 = func_80023498(8, 0x1C2, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

            func_80022F20(D_800F0588.unkA2, func_800064F0);
            p2 = GET_ACTOR_PTR(D_800F0588.unkA2);   

            if(cdata.nextstg == 0xA){
                p2->actorVars.varA4.integer = idx;
                p2->actorVars.varA0.integer = idx;
                p2->actorVars.varB8.fp = 300.0f;
                p2->actorVars.varBC.fp = -300.0f;
            }
            else{
                p2->actorVars.varA4.integer = idx;
                p2->actorVars.varA0.integer = idx;
                p2->actorVars.varB8.fp = 50.0f;
                p2->actorVars.varBC.fp = -120.0f;                
            }

            func_80008C6C(0x55, 2);
            
            actor->status = 10;
            break;
        case 10:
            temp4 = (&D_801414A8)[actor->unk38]->unk30 = func_8000ADE0((&D_801414A8)[actor->unk38]->unk30 - 2.0f);

            if(temp4 == 0.0f){
                id = func_80023498(1, actor->unk68, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f); 
                    
                if(actor->unk68 == 0x1C){
                    GET_ACTOR_PTR(id)->actorVars.varB4.integer = func_80023498(1, 0x1D, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
                    func_80024874(GET_ACTOR_PTR(id)->actorVars.varB4.integer, 0.0f);
                }

                func_80022F20(id, func_800385C0);
                actor1 = GET_ACTOR_PTR(id);
                
                actor1->actorVars.varC8.integer = actor->actorVars.varC8.integer;
                actor1->actorVars.varA4.fp = actor1->scale.x;
  
                GET_ACTOR_PTR(D_800F0588.unkA2)->actorVars.varA0.integer = id;

                func_80024874(id, 0.0f); 
                
                
                actor->status = 15;
            }
            break;
        case 15: 
            if(actor->actorVars.varC8.integer % 2U){
                actor->actorVars.varA4.integer = 0x3C;
                actor->status = 20;
            }
            else{
                actor->status = 99;
            }
            break;
        case 20:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer != 0){
                func_80023FCC(idx);
            }
            else{
                temp = 0.95 * actor->scale.x;
                
                actor->scale.x = actor->scale.y = actor->scale.z = temp;
            }
            break;
        case 99:
            break;
    }
}


void func_80039B1C(s32 arg0){

}

void func_80039B24(s32 arg0){

}

void func_80039B2C(s32 arg0){

}

void func_80039B34(s32 arg0){

}

void func_80039B3C(s32 arg0){

}

void func_80039B44(s32 arg0){

}

void func_80039B4C(s32 arg0){

}

void func_80039B54(s32 arg0){

}

void func_80039B5C(s32 arg0){

}

void func_80039B64(s32 arg0){

}

void func_80039B6C(s32 arg0){

}

void func_80039B74(s32 arg0){

}

void func_80039B7C(s32 arg0){

}

void func_80039B84(s32 arg0){

}

void func_80039B8C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->actorVars.varA0.fp = (func_80011528(0) % 7U) + 2.5;
            actor->actorVars.varA4.fp = (func_80011528(0) % 2U) + 0.5;
            actor->actorVars.varA8.integer = 0x384;
            actor->rot.y = func_80011528(0) % 360U;

            func_80024FC8(idx, actor->actorVars.varA4.fp, actor->actorVars.varA0.fp);
            func_8002507C(idx);
            actor->status = 1;
            break;
        case 1:
            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer <= 0){
                actor->status = 2;
            }

            actor->actorVars.varA0.fp -= D_80159170 / (4.0f * 1);

            func_80024FC8(idx, actor->actorVars.varA4.fp, actor->actorVars.varA0.fp);
            func_8001B734(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->actorVars.varA0.fp);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0xDA, 3, idx);
                func_80022F20(idx, func_8002CF48);
                return;
            }
            
            func_8002507C(idx);
            
            break;
        case 2:
            actor->scale.x -= 0.01;
            actor->scale.y -= 0.01;

            if(actor->scale.x < 0.02){
                func_80023FCC(idx);
            }
            break;
    }

    if(D_80141CB0[idx].unk0 != -1){
        func_80008C6C(0xDA, 0);
        cdata.unk22++;
        func_80022F20(idx, func_8002CF48);
    }
}
