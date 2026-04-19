#include "497E0.h"
#include "4D980.h"
#include "23B20.h"
#include "73660.h"
#include "9320.h"
#include "11F10.h"
#include "57820.h"

#include "actor.h"
#include "libc/math.h"

#include "common.h"

extern f32 D_80159170;

void func_80048BE0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad[7];

    func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));

    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x1A;
            func_80022F48(idx, 3);
            actor->status = 1;
            break;
        case 1:
            break;
    }
}

void func_80048CD4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 pad2;
    s32 pad5;
    s32 pad;
    s32 pad3;
    s16 pad4;
    s16 temp2;
    s16 temp3;

    func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));

    switch(actor->status){
        case 0:
            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA0.integer = 0x64;
            actor->unk8 = 0x53F;
            actor->unk4E = 2;
            actor->unk6C = 0x1D;
            func_80022F48(idx, 3);
            actor->status = 1;  
            break;
        case 1:
            if(temp < 100.0f){
                actor->actorVars.varA0.integer = 0x3C;
                actor->status = 2;
            }
            break;
        default:
            
            break;
        case 2:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer < 0){
                actor->unk8 = 0;

                if(actor->actorVars.varA4.integer >= 3){
                    actor->actorVars.varA4.integer = 0;
                }
                
                func_80022F48(idx, temp3 = actor->actorVars.varA4.integer++); 
                actor->status = 3;
                actor->actorVars.varA0.integer = 0x1E;
            }
            func_80025454(actor, actor1, 12.0f);
            break;
        case 3:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer < 0){
                func_80008E10(0x17, 2, idx);
                actor->actorVars.varA0.integer = 0x3C;
                func_80022F48(idx, 3);
                actor->status = 4;
            }
            if(actor->actorVars.varA0.integer == 0x1C){
                temp2 = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, actor->rot.y, 0.0f);
                
                if(temp2 != -1){
                    func_800242F0(temp2, 0, -1);
                    func_80022F20(temp2, func_8004EAC4);
                    func_80025638(GET_ACTOR_PTR(temp2), actor, actor->rot.y, 40.0f,10.0f);
                }
            }
            break;
        case 4:
            actor->unk8 = 0x53F;
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 1;
            }
            break;
    }
    
}

void func_80048FB4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x27;
            
            func_80022F48(idx, 2);
            
            actor->actorVars.varA4.fp = actor->pos.x;
            actor->actorVars.varA8.fp = actor->pos.z;

            if(actor->actorVars.varA0.integer != 0){
                actor->unk74 = 0x258;
                actor->status = 0x1F4;
                
                actor->scale.x = 8.0f;
                actor->scale.y = 8.0f;
                actor->scale.z = 8.0f;
            }
            else{
                actor->status = 0x32;
            }
            break;
        case 0x32:
            func_80022F48(idx, 2);
            actor->actorVars.varAC.integer = 0x3C;
            actor->status = 0x33;
            break;
        case 0x33:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                actor->status = 0x64;
            }

            actor->dir.y = actor->actorVars.varB8.fp -= D_80159170 * 0.25;

            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                actor->actorVars.varB8.fp = 0.0f;
            }
            break;
        case 0x64:
            func_80022F48(idx, 4);
            actor->actorVars.varB0.fp = func_80011528(0) % 400U + actor->actorVars.varA4.fp - 200.0f;
            actor->actorVars.varB4.fp = func_80011528(0) % 400U + actor->actorVars.varA8.fp - 200.0f;

            actor->actorVars.varAC.integer = 0x3C;
            actor->status = 0x65;
            
            break;

        case 0x65:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                actor->actorVars.varAC.integer = 0x78;
                actor->status = 0x66;
                actor->actorVars.varBC.fp = 0.0f;
            }
            func_800256CC(actor, actor->actorVars.varB0.fp, actor->actorVars.varB4.fp, 20.0f);
            break;
        case 0x66:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                actor->status = 0x67;
            }

            if(func_80024EA4(idx, actor->actorVars.varB0.fp, actor->pos.y, actor->actorVars.varB4.fp) < 30.0f){
                func_80022F48(idx, 0);
                actor->actorVars.varAC.integer = 0x3C;
                actor->status = 0x67;
            }

            func_800256CC(actor, actor->actorVars.varB0.fp, actor->actorVars.varB4.fp, 20.0f);

            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(actor->actorVars.varBC.fp < 1.0f){
                    actor->actorVars.varBC.fp += 0.025;
                }
                else{
                    actor->actorVars.varBC.fp = 1.0f;
                }
            }
            else{
                if(actor->actorVars.varBC.fp < 1.5){
                    actor->actorVars.varBC.fp += 0.05;
                }
                else{
                    actor->actorVars.varBC.fp = 1.5f;
                }
            }

            actor->actorVars.varB8.fp -= D_80159170 * 0.25;

            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->actorVars.varB8.fp *= 0.95;
            }

            func_80024FC8(idx, actor->actorVars.varBC.fp, actor->actorVars.varB8.fp);

            actor->actorVars.varC0.fp = actor->pos.x;
            actor->actorVars.varC4.fp = actor->pos.z;

            func_80059760(actor); 

            if(D_800F9910.unk0 != 0){
                actor->actorVars.varB8.fp = 0.0f;
            }

            if(actor->actorVars.varB8.fp <= 3.0f && actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(actor->actorVars.varBC.fp * 0.3 < actor->actorVars.varBC.fp - sqrtf(SQ(actor->pos.z - actor->actorVars.varC4.fp) + SQ(actor->pos.x - actor->actorVars.varC0.fp))){
                    func_80008E10(0x45, 2, idx);
                    actor->actorVars.varB8.fp = 10.0f;
                }    
            }
            break;
        case 0x67:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                func_80022F48(idx, 1);
                actor->actorVars.varAC.integer = 0x26;
                actor->status = 0x96;
                actor->dir.x = 0.0f;
                actor->dir.z = 0.0f;
            }

            if(actor->actorVars.varAC.integer < 0x28){
                actor->dir.x *= 0.95;
                actor->dir.z *= 0.95;
            }

            actor->actorVars.varB8.fp -= D_80159170 * 0.25;
            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->actorVars.varB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < actor->actorVars.varB8.fp){
                    actor->actorVars.varB8.fp = 0.0f;
                }
            }

            actor->dir.y = actor->actorVars.varB8.fp;

            func_80059760(actor);
            
            if(D_800F9910.unk0 != 0){
                actor->actorVars.varB8.fp = 0.0f;
            }
            
            break;

        case 0x96:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;
            
            if(actor->actorVars.varAC.integer <= 0){
                actor->status = 0x32;    
            }
            
            actor->actorVars.varB8.fp -= D_80159170 * 0.25;
            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->actorVars.varB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < actor->actorVars.varB8.fp){
                    actor->actorVars.varB8.fp = 0.0f;
                }
            }
            actor->dir.y = actor->actorVars.varB8.fp;

            func_80059760(actor);
            
            if(D_800F9910.unk0 != 0){
                actor->actorVars.varB8.fp = 0.0f;
            }
            break;

        case 0x1F4:
            actor->actorVars.varC8.integer = 0;
            actor->actorVars.varDC.fp = 1494.0f;
            actor->actorVars.varE0.fp = -1845.0f;
            
            actor->status = 0x1F5;
            actor->actorVars.varD4.fp = actor->pos.x;
            actor->actorVars.varD8.fp = actor->pos.z;
            break;
        case 0x1F5:
            func_80022F48(idx, 3);

            switch(actor->actorVars.varC8.integer){
                case 0:
                    actor->actorVars.varCC.fp = actor->actorVars.varD4.fp;
                    actor->actorVars.varD0.fp = actor->actorVars.varD8.fp;
                    break;
                case 1:
                    actor->actorVars.varCC.fp = actor->actorVars.varDC.fp;
                    actor->actorVars.varD0.fp = actor->actorVars.varE0.fp;
                    break;
            }

            actor->actorVars.varAC.integer = 0xC8;
            actor->status = 0x1F6;
            
            break;
        case 0x1F6:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                actor->status = 0x1F7;
                actor->actorVars.varB8.fp = 0.0f;
            }

            func_800256CC(actor, actor->actorVars.varCC.fp, actor->actorVars.varD0.fp, 64.0f);
            break;
        case 0x1F7:
            if(actor->actorVars.varB8.fp < 3.0f){
                actor->actorVars.varB8.fp += 0.01;
            }

            if(func_80024EA4(idx, actor->actorVars.varCC.fp, actor->pos.y, actor->actorVars.varD0.fp) < 50.0f){
                actor->status = 0x1F8;
            }

            func_800256CC(actor, actor->actorVars.varCC.fp, actor->actorVars.varD0.fp, 64.0f);
            func_80024FC8(idx, actor->actorVars.varB8.fp, -1.0f);
            func_80059760(actor);
            break;
        case 0x1F8:
            if(actor->dir.x < 0.1 && actor->dir.z < 0.1){
                actor->actorVars.varC8.integer = 1 - actor->actorVars.varC8.integer;
                actor->actorVars.varAC.integer = 0x78;
                actor->status = 0x1F9;
            }

            actor->dir.x *= 0.98;
            actor->dir.z *= 0.98;
            
            break;
        case 0x1F9:
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;

            if(actor->actorVars.varAC.integer <= 0){
                actor->status = 0x1F5;
            }
            break;
    }
    
}
