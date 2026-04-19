#include "675B0.h"
#include "23B20.h"
#include "386E0.h"
#include "89D30.h"
#include "73660.h"
#include "7FC0.h"
#include "13940.h"
#include "9320.h"
#include "29980.h"

#include "segments.h"

#include "global.h"
#include "libc/math.h"
#include "common.h"

extern s16 D_800FB340;

extern u8 D_801522E4;
extern u8 D_801522E5;
extern u8 D_801522E6;
extern u8 D_801522E7;
extern u8 D_801522E8;
extern u8 D_801522E9;

extern f32 D_8014DF8C;
extern f32 D_800F054C;

void func_800669B0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->flags |= 0x10;
            break;
        case 1:
            if(dist < 30.0f){
                func_80038F4C();
                D_800E6B20_2022_sets(0x20, 0xB0);
                func_800894B8(0x1E, 0xAE);

                if(func_80076FA0(0x46) != 0){
                    actor->status = 100;
                }
                else{
                    func_800073C0(0x37, 1);
                    D_800F9B08.unk800 &= 0xFFFE;
                    D_800F9B08.unk8F0 &= 0xFFFE;
                    actor->status = 101;
                }
            }
            break;
        case 100:
            if(func_80012D40(6, 8, 0) == 0){
                func_80089A4C();
                func_80038FA8();

                actor2->flags &= ~0x4000;
                actor->status = 110;
            }
            break;
        case 101:
            if(func_80012D40(6, 9, 0) == 0){
                func_80089A4C();
                actor2->flags &= ~0x4000;
                func_80038FA8();
                actor->status = 111;
            }
            break;
        case 110:
            if(dist > 600.0f){
                actor->status = 1;
            }
            break;
        case 111:
            break;
    }
}

void func_80066BC8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;
    s16 i;
    s16 pad;
    s16 temp1 = D_80159178->unk48[cdata.unk41].unk0;
    Actor *actor2 = GET_ACTOR_PTR(temp1);
    f32 temp2;

    if(cdata.unk38 != 0xFFFF){
        if(GET_ACTOR_PTR(idx)->status != 0 && (cdata.unk38 == 0 || cdata.unk38 == 4)){
            actor->actorVars.varA4.integer = 0;
        }
        if(cdata.unk38 == 5){
            actor->actorVars.varA4.integer = 1;
        }
    }
    if(actor2->pos.x < -1414.0f && -2985 < actor2->pos.x){
        if(actor2->pos.y < -128.0f){
            if(actor2->pos.z < 1533.0f && actor2->pos.z > 65.0f){
                actor->actorVars.varAC.integer = 1;                
            }
            else{
                actor->actorVars.varAC.integer = 0;
            }
        }
        else{
            actor->actorVars.varAC.integer = 0; 
        }
    }
    else{
        actor->actorVars.varAC.integer = 0;
    }
    if(func_80024E0C(idx, temp1) < 500.0f && actor->actorVars.varA8.integer == 0){
        actor->actorVars.varA8.integer = 1;
    }
    switch(actor->status){
        case 0:
            id = func_80023498(8, 0x1C6, -1024.0f, -499.0f, -1496.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_800669B0);
            }
            if(!(cdata.unk46[cdata.nextstg] & 0x4000)){
                id = func_80023644(8, 0x62, -25.0f, -149.0f, -770.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 6;
                }
                
                id = func_80023644(8, 0x62, -53.0f, -149.0f, -596.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 7;
                }
            }

            actor->actorVars.varA0.fp = 0.0f;
            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varB4.integer = -1;
            D_80142BB8[2].unk18 = 0.0f;

            ROMCOPY(D_368300, D_8020C820);

            GET_ACTOR_PTR(idx)->status = 1;
                
            break;
        case 1:
            break;
    }
    switch(D_800FB340){
        case 1:
            {
                
            s16 temp = 0;
                
            for(i = 0; i < 0x100; i++){
                actor2 = GET_ACTOR_PTR(i);

                if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x5F){
                    temp = 1; 
                    break;
                }
            }

            if(temp == 0){
                D_800F9B08.unk83C &= ~0x1;
            }

            break;
            }
        case 2:
            {
            s16 temp = 0;
                
            for(i = 0; i < 0x100; i++){
                actor2 = GET_ACTOR_PTR(i);

                if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x7A){
                    temp = 1; 
                    break;
                }
            }

            if(!temp){
                D_800F9B08.unk878 &= ~0x1;
            }
                
            temp = 0;
                
            for(i = 0; i < 0x100; i++){
                actor2 = GET_ACTOR_PTR(i);

                if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x5F){
                    temp = 1; 
                    break;
                }
            }

            if(temp == 0){
                D_800F9B08.unk7C4 &= ~0x1;
            }
            
            break;
            }
    }
    switch(GET_ACTOR_PTR(idx)->actorVars.varA4.integer){
        case 0:
            
            D_80142BB8[2].unk34 = 0;
            D_801522E4 = 0xFF;
            D_801522E5 = 0xFF;
            D_801522E6 = 0xFF;
            D_801522E7 = 0xB4;
            D_801522E8 = 0xB4;
            D_801522E9 = 0xB4;

            D_8014DF8C = 255.0f;
            break;
        case 1:
            actor->actorVars.varA0.fp += 3.0f;

            NORM_ANGLE(actor->actorVars.varA0.fp);

            temp2 = (D_800F054C + 400.0f) / 5.0f;

            CLAMP_MAX_MIN(temp2, 255.0f, 0.0f);
            
            D_80142BB8[2].unk34 = 4;
            D_80142BB8[2].unk14 = (255.0f - temp2) + 20.0f; 
            D_80142BB8[2].unk28 = (sinf(DEG2RAD_ALT2(actor->actorVars.varA0.fp)) * 90.0f) + 165.0f;


            if(D_80142BB8[2].unk28 < 0.0f){
                D_80142BB8[2].unk28 = 0.0f;
            }
            if(D_80142BB8[2].unk28 > 255.0f){
                D_80142BB8[2].unk28 = 255.0f;
            } 

            D_80142BB8[2].unk2C = (255.0f - temp2) * 0.25;
            D_80142BB8[2].unk30 = 0.0f;  
            D_80142BB8[2].unkC = 0.0f;
            D_80142BB8[2].unk0.x = 0.0f;
            D_80142BB8[2].unk0.z = 0.0f;
            D_80142BB8[2].unk10 = -80.0f;
            D_80142BB8[2].unk0.y = -1.0f;

            
            D_801522E4 = (s8)(temp2 * 0.41) + 0x96;
            D_801522E5 = (s8)(temp2 * 0.49) + 0x82;
            D_801522E6 = (s8)(temp2 * 0.52) + 0x78;
            D_801522E7 = (s8)(temp2 * 0.27) + 0x6E; 
            D_801522E8 = (s8)(temp2 * 0.35) + 0x5A;
            D_801522E9 = (s8)(temp2 * 0.39) + 0x50;
            break;
    }
    switch(actor->actorVars.varA8.integer){
        case 1:
            if(func_80077548() != 0){
                actor->actorVars.varB0.integer = 300;
                actor->actorVars.varA8.integer = 2;
                func_80008C6C(0xE8, 2);
            }
            break;
        case 2:
            if(actor->actorVars.varB0.integer == 300){
                func_80008C6C(0xE8, 3);
            }
            
            actor->actorVars.varB0.integer--;

            if(actor->actorVars.varB0.integer <= 0){
                actor->actorVars.varA8.integer = 3;
            }

            if(actor->actorVars.varB0.integer % 2U){
                id = func_80023644(6, 0x183, actor->pos.x, actor->pos.y - 30.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002BB54);
                }
                if(actor->actorVars.varB0.integer < 200){
                    id = func_80023644(6, 0x183, actor->pos.x, actor->pos.y - 30.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_8002BE04);
                    }                    
                }
            }
            break;
        case 3:
            actor->actorVars.varB4.integer = func_80023644(2, 0x1B9, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 180.0f, 0.0f);

            if(actor->actorVars.varB4.integer != -1){
                func_800073C0(0xF, 0);
                GET_ACTOR_PTR(actor->actorVars.varB4.integer)->rot.y = func_800253B0(actor->actorVars.varB4.integer, temp1);
                actor->actorVars.varA8.integer = 4;
            }
            break;
        case 4:
            if(func_80024E0C(actor->actorVars.varB4.integer, temp1) > 2000.0f){
                if(GET_ACTOR_PTR(actor->actorVars.varB4.integer)->unk0 != 0 && GET_ACTOR_PTR(actor->actorVars.varB4.integer)->unk48 == 0x1B9){
                    func_800073C0(3, 0);
                    
                    actor->actorVars.varA8.integer = 0;
                    
                    D_800F05B8 = 0;
                    func_80023FCC(actor->actorVars.varB4.integer);
                }
            }
            break;
        case 0:
            break;
    }
}
