#include "3AA90.h"
#include "common.h"
#include "23B20.h"
#include "15F60.h"
#include "actor.h"
#include "13940.h"
#include "7F4E0.h"
#include "9320.h"

#include "libc/math.h"

extern u16 D_800F3950;
extern u16 D_800F3952;

u32 D_80159040;

f32 D_800B5340 = 300.0f;

void func_80039E90(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    (void)"GOTO STAGE 1-1\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 1-2\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 1-3\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 1-4\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 2-1\n";
    (void)"GOTO STAGE 2-2\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 2-3\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 2-4\n";
    (void)"Tellop No. %d\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 3-X\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 3-1\n";
    (void)"GOTO STAGE 3-2\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 3-3\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 3-4\n";
    (void)"Tellop No. %d\n";
    (void)"GOTO STAGE 0-1\n";
    (void)"Tellop No. %d\n";

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            if(actor->actorVars.varA4.integer > 0 && actor->actorVars.varA4.integer < 5){
                D_800F5FB0.unk1C[0] = 0x7C1;
            }
            else if(actor->actorVars.varA4.integer >= 5 && actor->actorVars.varA4.integer < 9){
                D_800F5FB0.unk1C[0] = 0x3F;
            }
            else if(actor->actorVars.varA4.integer >= 9 && actor->actorVars.varA4.integer < 0xD){
                D_800F5FB0.unk1C[0] = 0xF801;
            }
            else{
                D_800F5FB0.unk1C[0] = 0xFFFF;
            }

            D_800F5FB0_sets(0x14, 2, 1);
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(D_800F5FB0.unk0 == 3){
                GET_ACTOR_PTR(idx)->status = 2;
            }
            break;
        case 2:
            cdata.unk42 = 0;
            D_800F3950 = actor->actorVars.varA4.integer;
            
            D_800E69C0.unk0 = 1;
            D_800E69C0.unk14 = 0x14;

            GET_ACTOR_PTR(idx)->status = 10;
            
            break;
        case 10:
            break;
    }
}

void func_80039FDC(s16 idx, f32 arg1){
    s32 pad;
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    f32 degAng = func_80025C48(actor2->pos.z - actor->pos.z, actor2->pos.x - actor->pos.x);
    f32 ang = DEG2RAD_ALT(degAng);
    f32 var_fv1;

    if(dist < arg1 && !(actor2->flags & 0x4000)){
        var_fv1 = (arg1+1.0f) - dist;

        actor2->actorVars.rawVars[3].fp += sinf(ang) * var_fv1;
        actor2->actorVars.rawVars[5].fp += cosf(ang) * var_fv1;
    }
}

void func_8003A138(u16 arg0){
    static u16 D_800B5344[] = {
        0x20, 0x00, 0x21, 0x1F, 0x1E, 0x00, 0x45, 0x22, 0x25, 0x44, 0x36, 
        0x00, 0x37, 0x26, 0x23, 0x00, 
    };
    s32 pad[8];
    f64 fv1;
    Vec3f sp34;
    s32 pad2;
    
    
    sp34.x = D_800F0548.unkC - D_800F0548.unk0;
    sp34.y = D_800F0548.unk10 - D_800F0548.unk4;
    sp34.z = D_800F0548.unk14 - D_800F0548.unk8;
    
    fv1 = 100.0 / sqrtf(func_800165DC(&sp34, &sp34));

    sp34.x *= fv1;
    sp34.y *= fv1;
    sp34.z *= fv1;
    
    func_80023498(1, D_800B5344[arg0], D_800F0548.unk0 + sp34.x, D_800F0548.unk4 + sp34.y, D_800F0548.unk8 + sp34.z, 1.0f, 1.0f, 1.0f);
} 

void func_8003A24C(s16 idx){
    func_8003BFAC(idx);
}

void func_8003A274(s16 idx){
    static u16 D_80159044;
    
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 350.0f){
                if(cdata.item & 0x80000){
                    actor->actorVars.varA4.integer = 1;
                    func_80022F20(idx, func_80039E90);
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            D_80159044 = (s16)func_80012D40(0x18, 0, 1);
            
            if(D_80159044 == 0){
                GET_ACTOR_PTR(idx)->status = 12;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 370.0f)){
                GET_ACTOR_PTR(idx)->status = 1;
            }
            break;
    }

    func_80039FDC(idx, 350.0f);
}

void func_8003A400(s16 idx){
    static u16 D_80159046;
    static u16 D_80159048;
    static u16 D_8015904A;
    static u16 D_8015904C;
    
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 10;
            D_8015904C = 0;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 450.0f){
                actor->actorVars.varA4.integer = 2;
                func_80022F20(idx, func_80039E90);
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 430.0f){
                D_80159046 = func_8007E8E0(2);

                if(D_80159046 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                    D_8015904A = 0;
                }
            }
            break;
        case 11:
            D_80159048 = (s16)func_80012D40(D_80159046 + 0x1C, 0, 1);

            if(D_80159048 == 0){
                if(D_80159046 == 0 || D_80159046 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }

            if(D_80159048 == 1){
                if(D_8015904A == 0){
                    func_80008C6C(0xC3, 4);
                }
                if(D_8015904A < 0x50){
                    D_8015904A++;
                }
                else{
                    D_8015904A = 0;
                }
            }
            if((D_80159046 == 0 && D_80159048 == 9) || (D_80159046 == 2 && D_80159048 == 7)){
                if(D_8015904A == 0){
                    func_80008C6C(0xC3, 4);
                }
                if(D_8015904A < 0x50){
                    D_8015904A++;
                }
                else{
                    D_8015904A = 0;
                }
            }
            if(D_8015904C == 0 && ((D_80159046 == 0 && D_80159048 == 5) || (D_80159046 == 2 && D_80159048 == 3))){
                D_8015904C = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                GET_ACTOR_PTR(idx)->status = 20;
                D_8015904A = 0x4C;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 450.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            D_80159048 = func_80012D40(D_80159046 + 0x1C, 0, 1);

            if(D_8015904A == 0){
                func_80008C6C(0x8D, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_8015904A = 0xEC;
            }
            else{
                D_8015904A--;
            }
            break;
        case 21:
            D_80159048 = func_80012D40(D_80159046 + 0x1C, 0, 1);

            if(D_8015904A == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_8015904A--;
            }
            break;
    }

    func_80039FDC(idx, 430.0f);
}

void func_8003A8A0(s16 idx){
    static u16 D_8015904E;
    static u16 D_80159050;
    static u16 D_80159052;
    static u16 D_80159054;
    static u16 D_80159056;
    
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;
    s32 id;
    s32 v1;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_80159056 = 0;
            D_80159052 = 0x64;

            if(((u16*)&cdata.unk0)[cdata.nextstg+0x25] & 4 && cdata.unk46[cdata.nextstg] & 4){
                GET_ACTOR_PTR(idx)->status = 13;
                return;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 150.0f){
                actor->actorVars.varA4.integer = 3;
                func_80022F20(idx, func_80039E90);
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 130.0f){
                D_8015904E = func_8007E8E0(3);

                if(D_8015904E == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11: // todo fake temps
            v1 = (u16)func_80012D40(D_8015904E + 0x20, 0, 1);

            D_80159050 = v1;

            if(v1 == 0){
                if(D_8015904E == 0 || D_8015904E == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            id = 2;
            
            if(D_80159052 != 0 && ((D_8015904E == 0 && v1 == 5U) || (D_8015904E == id && v1 == id+1))){
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                GET_ACTOR_PTR(idx)->status = 14;
            }
            if(D_80159056 == 0 && ((D_8015904E == 0 && v1 == 4U) || (D_8015904E == id && v1 == 2U))){
                D_80159056 = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_80159054 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 150.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 13:
            id = func_80024970(0x28, 0xB2);
            
            actor2 = GET_ACTOR_PTR(id);
            actor2->scale.x = 0.0f;
            actor2->scale.y = 0.0f;
            actor2->scale.z = 0.0f;
            
            GET_ACTOR_PTR(idx)->status = 10;
            return;
        case 14:
            D_80159050 = (s16)func_80012D40(D_8015904E + 0x20, 0, 1);
            
            id = func_80024970(0x28, 0xB2);

            if(D_80159052 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159052--;
                 
                actor2 = GET_ACTOR_PTR(id);
                actor2->scale.x -= 0.01;
                actor2->scale.y -= 0.01;
                actor2->scale.z -= 0.01;  
            }
            break;
        case 20:
            id = (s16)func_80012D40(D_8015904E + 0x20, 0, 1);
            
            D_80159050 = id;
            
            if(D_80159054 == 0){
                func_80008C6C(0x92, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159054 = 0x7F;
            }
            else{
                D_80159054--; 
            }
            break;
        case 21:
            id = (s16)func_80012D40(D_8015904E + 0x20, 0, 1);
            
            D_80159050 = id;

            if(D_80159054 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159054--;
            }
            break;
    }

    func_80039FDC(idx, 130.0f);
}

void func_8003ADF8(s16 idx){
    static u16 D_80159058;
    static u16 D_8015905A;
    static u16 D_8015905C;
    static u16 D_8015905E;
    
    s32 id;
    s32 id2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 10;
            D_8015905E = 0;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 370.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 4;
                func_80022F20(idx, func_80039E90);
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 350.0f){
                D_80159058 = func_8007E8E0(4);

                if(D_80159058 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11: // todo remove temps
            id2 = (u16)func_80012D40(D_80159058 + 0x24, 0, 1);

            D_8015905A = id2;

            if(id2 == 0){
                if(D_80159058 == 0 || D_80159058 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }

            if (1); if(1); // todo: @!FAKE
            
            id = 2;
            
            if(D_8015905E == 0 && ((D_80159058 == 0 && id2 == 4U) || (D_80159058 == id && id2 == 2U))){
                D_8015905E = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_8015905C = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 370.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            id = (u16)func_80012D40(D_80159058 + 0x24, 0, 1);
            
            D_8015905A = id;
            
            if(D_8015905C == 0){
                func_80008C6C(0x96, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_8015905C = 0x9C;
            }
            else{
                D_8015905C--; 
            }
            break;
        case 21:
            id2 = (u16)func_80012D40(D_80159058 + 0x24, 0, 1);
            
            D_8015905A = id2;

            if(D_8015905C == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_8015905C--;
            }
    }

    func_80039FDC(idx, 350.0f);
}

void func_8003B180(s16 idx){
    static u16 D_80159060;
    static u16 D_80159062;

    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 410.0f){
                actor->actorVars.varA4.integer = 5;
                func_80022F20(idx, func_80039E90);
            }
            break;
    }
}

void func_8003B23C(s16 idx){
    static u16 D_80159064;
    static u16 D_80159066;
    static u16 D_80159068;
    static u16 D_8015906A;
    
    s32 id;
    s32 id2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_8015906A = 0;
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 330.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 6;
                func_80022F20(idx, func_80039E90);
                cdata.item |= 0x100000;
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 310.0f){
                D_80159064 = func_8007E8E0(6);

                if(D_80159064 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11: // todo remove temps
            id2 = (u16)func_80012D40(D_80159064 + 0x2C, 0, 1);

            D_80159066 = id2;

            if(id2 == 0){
                if(D_80159064 == 0 || D_80159064 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }

            if (1); if(1); // todo: @!FAKE
            
            id = 2;
            
            if(D_8015906A == 0 && ((D_80159064 == 0 && id2 == 7U) || (D_80159064 == id && id2 == id+1))){
                D_8015906A = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_80159068 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 330.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            id = (u16)func_80012D40(D_80159064 + 0x2C, 0, 1);
            
            D_80159066 = id;
            
            if(D_80159068 == 0){
                func_80008C6C(0x94, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159068 = 0x99;
            }
            else{
                D_80159068--; 
            }
            break;
        case 21:
            id = (u16)func_80012D40(D_80159064 + 0x2C, 0, 1);
            
            D_80159066 = id;

            if(D_80159068 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159068--;
            }
            break;
    }

    func_80039FDC(idx, 310.0f);
}

void func_8003B5E4(s16 idx){
    static u16 D_8015906C;
    static u16 D_8015906E;
    static u16 D_80159070;
    static u16 D_80159072;
    
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_80159072 = 0;
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(cdata.unk36 == 0x29){
                actor->actorVars.varA4.integer = 7;
                func_80022F20(idx, func_80039E90);
            }
            break;
        case 10:
            if(cdata.unk36 == 0x29){
                D_8015906C = func_8007E8E0(7);

                if(D_8015906C == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            D_8015906E = (s16)func_80012D40(D_8015906C + 0x30, 0, 1);
            
            if(D_8015906E == 0){
                if(D_8015906C == 0 || D_8015906C == 2U){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }

            if(D_80159072 == 0 && ((D_8015906C == 0 && D_8015906E == 4) || (D_8015906C == 2U && D_8015906E == 2))){
                D_80159072 = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0U);
                D_80159070 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(cdata.unk36 != 0x29){
                GET_ACTOR_PTR(idx)->status = 0xA;
            }
            break;
        case 20:
            D_8015906E = func_80012D40(D_8015906C + 0x30, 0, 1U);
            
            if(D_80159070 == 0){
                func_80008C6C(0x91, 4U);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159070 = 0x9F;
            } 
            else{
                D_80159070--;
            }
            break;
        case 21:
            D_8015906E = func_80012D40(D_8015906C + 0x30, 0, 1U);
            
            if(D_80159070 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159070--;
            }
            break;
    }
}

void func_8003B8AC(s16 idx){
    static u16 D_80159074;
    static u16 D_80159076;
    static u16 D_80159078;
    static u16 D_8015907A;
    
    s32 id;
    s32 id2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_8015907A = 0;
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 320.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 8;
                func_80022F20(idx, func_80039E90);
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 300.0f){
                D_80159074 = func_8007E8E0(8);

                if(D_80159074 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11: // todo remove temps
            id2 = (u16)func_80012D40(D_80159074 + 0x34, 0, 1);

            D_80159076 = id2;

            if(id2 == 0){
                if(D_80159074 == 0 || D_80159074 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }

            if (1); if(1); // todo: @!FAKE
                        
            if(D_8015907A == 0 && ((D_80159074 == 0 && id2 == 5U) || (D_80159074 == 2U && id2 == 2))){
                D_8015907A = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_80159078 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 320.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            id = (u16)func_80012D40(D_80159074 + 0x34, 0, 1);
            
            D_80159076 = id;
            
            if(D_80159078 == 0){
                func_80008C6C(0x97, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159078 = 0x7d;
            }
            else{
                D_80159078--; 
            }
            break;
        case 21:
            id = (u16)func_80012D40(D_80159074 + 0x34, 0, 1);
            
            D_80159076 = id;

            if(D_80159078 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159078--;
            }
            break;
    }

    func_80039FDC(idx, 300.0f);
}

void func_8003BC34(s16 idx){
    static u16 D_8015907C;
    static u16 D_8015907E;
    static u16 D_80159080;
    static u16 D_80159082;
    
    s32 id;
    s32 id2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_80159082 = 0;

            if(((u16*)&cdata.unk0)[cdata.nextstg+0x25] & 0x100 && cdata.unk46[cdata.nextstg] & 0x100){
                GET_ACTOR_PTR(idx)->status = 1;
                return;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 1:
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 1150.0f){
                D_8015907C = func_8007E8E0(9);

                if(D_8015907C == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11: //todo remove temps
            id2 = (u16)func_80012D40(D_8015907C + 0x38, 0, 1);

            D_8015907E = id2;

            if(id2 == 0){
                if(D_8015907C == 0 || D_8015907C == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            id = 2;

            if (1); if(1); // todo: @!FAKE
            
            if(D_80159082 == 0 && ((D_8015907C == 0 && id2 == 4U) || (D_8015907C == id && id2 == 2U))){
                D_80159082 = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_80159080 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 1170.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            id = (u16)func_80012D40(D_8015907C + 0x38, 0, 1);
            
            D_8015907E = id;
            
            if(D_80159080 == 0){
                func_80008C6C(0x7E, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159080 = 0x76;
            }
            else{
                D_80159080--; 
            }
            break;
        case 21:
            id = (u16)func_80012D40(D_8015907C + 0x38, 0, 1);
            
            D_8015907E = id;

            if(D_80159080 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159080--;
            }
            break;
    }

    func_80039FDC(idx, 1150.0f);
}

void func_8003BFAC(s16 idx){
    static u16 D_80159084;
    static u16 D_80159086;
    static u16 D_80159088;
    static u16 D_8015908A;
    static u16 D_8015908C;
    
    s32 id;
    s32 id2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_8015908C = 0;
            D_8015908A = 0;

            if(((u16*)&cdata.unk0)[cdata.nextstg+0x25] & 0x200 && cdata.unk46[cdata.nextstg] & 0x200){
                GET_ACTOR_PTR(idx)->status = 13;
                return;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 150.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 14;
                func_80022F20(idx, func_80039E90);
            }
            return;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 130.0f){
                D_80159084 = func_8007E8E0(10);

                if(D_80159084 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            id2 = (u16)func_80012D40(D_80159084 + 0x3C, 0, 1);

            D_80159086 = id2;

            if(id2 == 0){
                if(D_80159084 == 0 || D_80159084 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    return;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            id = 2;

            if (1); if(1); // todo: @!FAKE

            if(D_8015908C == 0 && ((D_80159084 == 0 && id2 == 5U) || (D_80159084 == id && id2 == id+1))){
                D_800F9B08[0x22].unk8 &= (u16)~0x1;
                D_8015908C = 1;
                D_80159088 = 0x1C2;
                
                GET_ACTOR_PTR(idx)->status = 14;
            }
            if(D_8015908A == 0 && ((D_80159084 == 0 && id2 == 4U) || (D_80159084 == id && id2 == 2U))){
                D_8015908A = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_80159088 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 150.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 13:
            (&D_801B58AC)[cdata.nextstg]->unk4E4 |= 2; 
            (&D_801B58AC)[cdata.nextstg]->unk4CC = 300.0f; 
            GET_ACTOR_PTR(idx)->status = 10;
            return;
        case 14:
            if(D_80159088 == 0){
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159088--;
            }
            break;
        case 20:
            id = (u16)func_80012D40(D_80159084 + 0x3C, 0, 1);
            
            D_80159086 = id;
            
            if(D_80159088 == 0){
                func_80008C6C(0x85, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_80159088 = 0x7E;
            }
            else{
                D_80159088--; 
            }
            break;
        case 21:
            id = (u16)func_80012D40(D_80159084 + 0x3C, 0, 1);
            
            D_80159086 = id;

            if(D_80159088 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_80159088--;
            }
            break;
    }

    func_80039FDC(idx, 130.0f);
}

void func_8003C478(s16 idx){
    static u16 D_8015908E;
    static u16 D_80159090;
    static u16 D_80159092;
    static u16 D_80159094;


    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(cdata.unk36 == 0xC){
                actor->actorVars.varA4.integer = 9;
                func_80022F20(idx, func_80039E90);
                actor2->flags |= 0x4000;
            }
            break;
    }
}

void func_8003C53C(s16 idx){
    static u16 D_80159096;
    static u16 D_80159098;
    static u16 D_8015909A;
    static u16 D_8015909C;

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 160.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 10;
                func_80022F20(idx, func_80039E90);
                actor2->flags |= 0x4000;
            }
            
            break;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 140.0f){
                D_80159096 = func_8007E8E0(12);

                if(D_80159096 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            // todo
            D_80159098 = (s16)func_80012D40(D_80159096 + 0x44, 0, 1);

            if(D_80159098 == 0){
                if(D_80159096 == 0 || D_80159096 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            if(D_8015909C == 0 && ((D_80159096 == 0 && D_80159098 == 11U) || (D_80159096 == 2U && D_80159098 == 10U))){
                D_8015909C = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_8015909A = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 160.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            D_80159098 = (s16)func_80012D40(D_80159096 + 0x44, 0, 1);
            
            
            if(D_8015909A == 0){
                func_80008C6C(0x8E, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_8015909A = 0xB4;
            }
            else{
                D_8015909A--; 
            }
            break;
        case 21:
            D_80159098 = (s16)func_80012D40(D_80159096 + 0x44, 0, 1);
            
            if(D_8015909A == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_8015909A--;
            }
            break;
    }

    func_80039FDC(idx, 140.0f); 
}

void func_8003C88C(s16 idx){
    static u16 D_8015909E;
    static u16 D_801590A0;
    static u16 D_801590A2;
    static u16 D_801590A4;

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 300.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 11;
                func_80022F20(idx, func_80039E90);
                actor2->flags |= 0x4000;
            }
            
            break;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 280.0f){
                D_8015909E = func_8007E8E0(13);

                if(D_8015909E == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            // todo
            D_801590A0 = (s16)func_80012D40(D_8015909E + 0x48, 0, 1);

            if(D_801590A0 == 0){
                if(D_8015909E == 0 || D_8015909E == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            if(D_801590A4 == 0 && ((D_8015909E == 0 && D_801590A0 == 7U) || (D_8015909E == 2U && D_801590A0 == 2))){
                D_801590A4 = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_801590A2 = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 300.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            D_801590A0 = (s16)func_80012D40(D_8015909E + 0x48, 0, 1);
            
            if(D_801590A2 == 0){
                func_80008C6C(0x95, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_801590A2 = 0x65;
            }
            else{
                D_801590A2--; 
            }
            break;
        case 21:
            D_801590A0 = (s16)func_80012D40(D_8015909E + 0x48, 0, 1);

            if(D_801590A2 == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_801590A2--;
            }
            break;
    }

    func_80039FDC(idx, 280.0f);
}

void func_8003CBDC(s16 idx){
    static u16 D_801590A6;
    static u16 D_801590A8;
    static u16 D_801590AA;
    static u16 D_801590AC;

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 430.0f){
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer = 12;
                func_80022F20(idx, func_80039E90);
                actor2->flags |= 0x4000;
            }
            
            break;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 410.0f){
                D_801590A6 = func_8007E8E0(14);

                if(D_801590A6 == 4){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 11;
                }
            }
            break;
        case 11:
            D_801590A8 = (s16)func_80012D40(D_801590A6 + 0x4C, 0, 1);

            if(D_801590A8 == 0){
                if(D_801590A6 == 0 || D_801590A6 == 2){
                    GET_ACTOR_PTR(idx)->status = 1;
                    break;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 12;
                }
            }
            
            if(D_801590AC == 0 && ((D_801590A6 == 0 && D_801590A8 == 11U) || (D_801590A6 == 2U && D_801590A8 == 2))){
                D_801590AC = 1;
                D_800F3940[cdata.unk41]->unkA4[15] = 1;
                func_80008C6C(0x79, 0);
                D_801590AA = 0x4C;
                GET_ACTOR_PTR(idx)->status = 20;
            }
            break;
        case 12:
            if(!(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 430.0f)){
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 20:
            D_801590A8 = (s16)func_80012D40(D_801590A6 + 0x4C, 0, 1);
            
            if(D_801590AA == 0){
                func_80008C6C(0x87, 4);
                GET_ACTOR_PTR(idx)->status = 21;
                D_801590AA = 0x97;
            }
            else{
                D_801590AA--; 
            }
            break;
        case 21:
            D_801590A8 = (s16)func_80012D40(D_801590A6 + 0x4C, 0, 1);

            if(D_801590AA == 0){
                D_800F3940[cdata.unk41]->unkA4[15] = 0;
                GET_ACTOR_PTR(idx)->status = 11;
            }
            else{
                D_801590AA--;
            }
            break;
    }

    func_80039FDC(idx, 410.0f);
}

void func_8003CF2C(s16 idx){
    static u16 D_801590AE;
    static u16 D_801590B0;

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            if(((u16*)&cdata.unk0)[cdata.nextstg+0x25] & 0x10){
                GET_ACTOR_PTR(idx)->status = 1;
            }
            else{
                GET_ACTOR_PTR(idx)->status = 10;
            }
            break;
        case 1:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 180.0f){
                actor->actorVars.varA4.integer = 13;
                D_800F3952 = 1;
                func_80022F20(idx, func_80039E90);
                actor2->flags |= 0x4000;
            }
            break;
        case 10:
            if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) < 230.0f){
                func_8007E8E0(15);
                D_801590AE = 0;
                GET_ACTOR_PTR(idx)->status = 11;
                
            }
            break;
        case 11:
            D_801590B0 = (s16)func_80012D40(D_801590AE + 0x50, 0, 1);
            
            
            if(D_801590B0 == 0){
                GET_ACTOR_PTR(idx)->status = 1;
            }
            break;
    }

    func_80039FDC(idx, 180.0f);
}

void func_8003D0E0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            break;
    }
}
