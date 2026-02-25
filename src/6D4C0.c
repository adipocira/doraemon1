#include "6D4C0.h"
#include "actor.h"
#include "23B20.h"
#include "386E0.h"
#include "89D30.h"
#include "73660.h"
#include "13940.h"
#include "11DF0.h"
#include "7FC0.h"

#include "segments.h"
#include "common.h"

extern s16 D_800B5370;
extern s16 D_800FB340;

void func_8006C8C0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->flags |= 0x10;
            break;
        case 1:
            if(dist < 120.0f){
                func_80038F4C();
                D_800E6B20_2022_sets(0x20, 0xB0);
                func_800894B8(0x1E, 0xAE);

                if(func_80076FA0(0x48)){
                    actor->status = 100;
                }
                else{
                    func_800073C0(0x37, 1);
                    actor->status = 101;
                }
            }
            break;
        case 100:
            if(dist < 30.0f && func_80012D40(0xE, 9, 0) == 0){
                func_80089A4C();
                actor2->flags &= ~0x4000;
                func_80038FA8();
                actor->status = 110;
            }
            break;
        case 101:
            if(func_80012D40(0xE, 0xA, 0) == 0){
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

void func_8006CACC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;
    s16 id;
    s16 i;
    
    if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 500.0f && actor->actorVars.varA0.integer == 0){
        actor->actorVars.varA0.integer = 1;
    }
    switch(actor->status){
        case 0:
            id = func_80023498(8, 0x1CD, 903.0f, 351.0f, 1028.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_8006C8C0);
            }
            if(func_80076FA0(0x39)){
                id = func_80023644(8, 0x63, 1277.0f, 200.0f, 2135.0f, 0.0f, 225.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 4;
                }
            }
            else{
                id = func_80023644(8, 0x63, 1277.0f, 200.0f, 2135.0f, 0.0f, 225.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 5;
                }                
            }
            if(func_80076FA0(0x39)){
                D_800B5370 &= ~2;
            }
            else{
                D_800B5370 |= 2;
            }

            ROMCOPY(D_37F1A0, D_8020C820);

            actor->actorVars.varA0.integer = 0;
            actor->actorVars.varA8.integer = -1;

            actor->status = 1;
            break;
        case 1:
            break;
    }
    if(D_800FB340 == 1){
        s16 temp = 0;
                
        for(i = 0; i < 0x100; i++){
            actor2 = GET_ACTOR_PTR(i);
            
            if(actor2->unk0 != 0 && actor2->unk64 == D_800FB340 && actor2->unk48 == 0x7E){
                temp = 1; 
                break;
            }
        }
        if(temp == 0){
            D_800F9B08.unkA58 &= ~0x1;
            D_800F9B08.unkA94 &= ~0x1;
        } 
    }
    switch(actor->actorVars.varA0.integer){
        case 0:
            break;
        case 1:
            func_800073C0(0xF, 0);
            actor->actorVars.varA0.integer = 2;
            break;
        case 2:
            actor->actorVars.varA8.integer = func_80023644(2, 0x1BA, 1099.0f, 551.0f, -1548.0f, 0.0f, 206.0f, 0.0f);

            if(actor->actorVars.varA8.integer != -1){
                actor->actorVars.varA0.integer = 3;
            }
            break;
        case 3:
            break;
    }   
}
