#include "497E0.h"
#include "4D980.h"
#include "23B20.h"
#include "73660.h"
#include "9320.h"
#include "11F10.h"

#include "actor.h"
#include "libc/math.h"

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x24];
}D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1]; 


extern f32 D_80159170;

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

void func_80048BE0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad[8];

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
            actor->unkA4.integer = 0;
            actor->unkA0.integer = 0x64;
            actor->unk8 = 0x53F;
            actor->unk4E = 2;
            actor->unk6C = 0x1D;
            func_80022F48(idx, 3);
            actor->status = 1;  
            break;
        case 1:
            if(temp < 100.0f){
                actor->unkA0.integer = 0x3C;
                actor->status = 2;
            }
            break;
        default:
            
            break;
        case 2:
            actor->unkA0.integer--;

            if(actor->unkA0.integer < 0){
                actor->unk8 = 0;

                if(actor->unkA4.integer >= 3){
                    actor->unkA4.integer = 0;
                }
                
                func_80022F48(idx, temp3 = actor->unkA4.integer++); 
                actor->status = 3;
                actor->unkA0.integer = 0x1E;
            }
            func_80025454(actor, actor1, 12.0f);
            break;
        case 3:
            actor->unkA0.integer--;

            if(actor->unkA0.integer < 0){
                func_80008E10(0x17, 2, idx);
                actor->unkA0.integer = 0x3C;
                func_80022F48(idx, 3);
                actor->status = 4;
            }
            if(actor->unkA0.integer == 0x1C){
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
            actor->unkA0.integer--;

            if(actor->unkA0.integer <= 0){
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
            
            actor->unkA4.fp = actor->pos.x;
            actor->unkA8.fp = actor->pos.z;

            if(actor->unkA0.integer != 0){
                actor->unk74 = 0x258;
                actor->status = 0x1F4;
                
                actor->unk90.x = 8.0f;
                actor->unk90.y = 8.0f;
                actor->unk90.z = 8.0f;
            }
            else{
                actor->status = 0x32;
            }
            break;
        case 0x32:
            func_80022F48(idx, 2);
            actor->unkAC.integer = 0x3C;
            actor->status = 0x33;
            break;
        case 0x33:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                actor->status = 0x64;
            }

            actor->unk5C = actor->unkB8.fp -= D_80159170 * 0.25;

            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                actor->unkB8.fp = 0.0f;
            }
            break;
        case 0x64:
            func_80022F48(idx, 4);
            actor->unkB0.fp = func_80011528(0) % 400U + actor->unkA4.fp - 200.0f;
            actor->unkB4.fp = func_80011528(0) % 400U + actor->unkA8.fp - 200.0f;

            actor->unkAC.integer = 0x3C;
            actor->status = 0x65;
            
            break;

        case 0x65:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                actor->unkAC.integer = 0x78;
                actor->status = 0x66;
                actor->unkBC.fp = 0.0f;
            }
            func_800256CC(actor, actor->unkB0.fp, actor->unkB4.fp, 20.0f);
            break;
        case 0x66:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                actor->status = 0x67;
            }

            if(func_80024EA4(idx, actor->unkB0.fp, actor->pos.y, actor->unkB4.fp) < 30.0f){
                func_80022F48(idx, 0);
                actor->unkAC.integer = 0x3C;
                actor->status = 0x67;
            }

            func_800256CC(actor, actor->unkB0.fp, actor->unkB4.fp, 20.0f);

            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(actor->unkBC.fp < 1.0f){
                    actor->unkBC.fp += 0.025;
                }
                else{
                    actor->unkBC.fp = 1.0f;
                }
            }
            else{
                if(actor->unkBC.fp < 1.5){
                    actor->unkBC.fp += 0.05;
                }
                else{
                    actor->unkBC.fp = 1.5f;
                }
            }

            actor->unkB8.fp -= D_80159170 * 0.25;

            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->unkB8.fp *= 0.95;
            }

            func_80024FC8(idx, actor->unkBC.fp, actor->unkB8.fp);

            actor->unkC0.fp = actor->pos.x;
            actor->unkC4.fp = actor->pos.z;

            func_80059760(actor); 

            if(D_800F9910.unk0 != 0){
                actor->unkB8.fp = 0.0f;
            }

            if(actor->unkB8.fp <= 3.0f && actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(actor->unkBC.fp * 0.3 < actor->unkBC.fp - sqrtf(SQ(actor->pos.z - actor->unkC4.fp) + SQ(actor->pos.x - actor->unkC0.fp))){
                    func_80008E10(0x45, 2, idx);
                    actor->unkB8.fp = 10.0f;
                }    
            }
            break;
        case 0x67:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                func_80022F48(idx, 1);
                actor->unkAC.integer = 0x26;
                actor->status = 0x96;
                actor->unk58 = 0.0f;
                actor->unk60 = 0.0f;
            }

            if(actor->unkAC.integer < 0x28){
                actor->unk58 *= 0.95;
                actor->unk60 *= 0.95;
            }

            actor->unkB8.fp -= D_80159170 * 0.25;
            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->unkB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < actor->unkB8.fp){
                    actor->unkB8.fp = 0.0f;
                }
            }

            actor->unk5C = actor->unkB8.fp;

            func_80059760(actor);
            
            if(D_800F9910.unk0 != 0){
                actor->unkB8.fp = 0.0f;
            }
            
            break;

        case 0x96:
            GET_ACTOR_PTR(idx)->unkAC.integer--;
            
            if(actor->unkAC.integer <= 0){
                actor->status = 0x32;    
            }
            
            actor->unkB8.fp -= D_80159170 * 0.25;
            
            if(actor->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                actor->unkB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < actor->unkB8.fp){
                    actor->unkB8.fp = 0.0f;
                }
            }
            actor->unk5C = actor->unkB8.fp;

            func_80059760(actor);
            
            if(D_800F9910.unk0 != 0){
                actor->unkB8.fp = 0.0f;
            }
            break;

        case 0x1F4:
            actor->unkC8.integer = 0;
            actor->unkDC.fp = 1494.0f;
            actor->unkE0.fp = -1845.0f;
            
            actor->status = 0x1F5;
            actor->unkD4.fp = actor->pos.x;
            actor->unkD8.fp = actor->pos.z;
            break;
        case 0x1F5:
            func_80022F48(idx, 3);

            switch(actor->unkC8.integer){
                case 0:
                    actor->unkCC.fp = actor->unkD4.fp;
                    actor->unkD0.fp = actor->unkD8.fp;
                    break;
                case 1:
                    actor->unkCC.fp = actor->unkDC.fp;
                    actor->unkD0.fp = actor->unkE0.fp;
                    break;
            }

            actor->unkAC.integer = 0xC8;
            actor->status = 0x1F6;
            
            break;
        case 0x1F6:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                actor->status = 0x1F7;
                actor->unkB8.fp = 0.0f;
            }

            func_800256CC(actor, actor->unkCC.fp, actor->unkD0.fp, 64.0f);
            break;
        case 0x1F7:
            if(actor->unkB8.fp < 3.0f){
                actor->unkB8.fp += 0.01;
            }

            if(func_80024EA4(idx, actor->unkCC.fp, actor->pos.y, actor->unkD0.fp) < 50.0f){
                actor->status = 0x1F8;
            }

            func_800256CC(actor, actor->unkCC.fp, actor->unkD0.fp, 64.0f);
            func_80024FC8(idx, actor->unkB8.fp, -1.0f);
            func_80059760(actor);
            break;
        case 0x1F8:
            if(actor->unk58 < 0.1 && actor->unk60 < 0.1){
                actor->unkC8.integer = 1 - actor->unkC8.integer;
                actor->unkAC.integer = 0x78;
                actor->status = 0x1F9;
            }

            actor->unk58 *= 0.98;
            actor->unk60 *= 0.98;
            
            break;
        case 0x1F9:
            GET_ACTOR_PTR(idx)->unkAC.integer--;

            if(actor->unkAC.integer <= 0){
                actor->status = 0x1F5;
            }
            break;
    }
    
}
