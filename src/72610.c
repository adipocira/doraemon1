#include "72610.h"
#include "zzAudio.h"
#include "actor.h"
#include "23B20.h"
#include "29980.h"
#include "B4E0.h"
#include "global.h"
#include "common.h"
#include "save_file.h"
#include "zzGame.h"
#include "zzGameData.h"
#include "zzEvents.h"
#include "7FC0.h"
#include "9320.h"
#include "11F10.h"

extern u8 D_800F0630;

extern s32 D_800F39AC;

extern f32 D_80159170;

extern u8 D_800EEFB0[];

extern s32 D_802BD61C[];

extern s16 D_802BD49E[][0xE]; 

void func_80071A10(s16 idx){
    static s16 D_800B62C0[] = {
        4,  127, 222, -52,  1,    160, 7,  6,    270, 3,  -54, 74, -549, 28, 68,  -550, 1,   60,  2,    16,
        -1, 3,   -4,  64,   -448, -28, 66, -550, 1,   30, 7,   6,  270,  8,  7,   9,    1,   120, 2,    17,
        -1, 3,   0,   60,   -580, 0,   41, -317, 7,   6,  0,   2,  18,   -1, 6,   20,   4,   99,  86,   -453,
        5,  -28, 46,  -585, 2,    19,  20, 21,   22,  23, 24,  -1, 3,    82, 164, -771, -28, 0,   -448, 2,
        25, 26,  27,  28,   29,   30,  31, 32,   33,  34, 35,  36, 37,   38, 39,  40,   41,  42,  43,   -1,
    };
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 id;
    s32 t0;
    s32 temp;
    s32 pad;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            func_8000B120(2);
            D_800F3920.unk0 = 6;
            D_800F3920.unk2 = 0xA;
            
            D_800F39AC = 0;

            cdata.hudFlags |= 1;
            D_800E69C0.cfb_render |= 1;

            actor->actorVars.varA0.integer = func_80023644(2, ZZ_ACTORS_DORAEMON, 0.0f, 31.0f, -370.0f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varA4.integer = func_80023644(2, ZZ_ACTORS_NOBITA, -25.0f, 31.0f, -380.0f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varA8.integer = func_80023644(2, ZZ_ACTORS_SHIZUKA, -50.0f, 31.0f, -390.0f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varAC.integer = func_80023644(2, ZZ_ACTORS_SUNEO, 25.0f, 31.0f, -380.0f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varB0.integer = func_80023644(2, ZZ_ACTORS_TAKESHI, 50.0f, 31.0f, -390.0f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varB4.integer = func_80023644(2, ZZ_ACTORS_CORONA, -30.0f, 31.0f, -550.0f, 0.0f, 0.0f, 0.0f);

            for (i = 0; i < 6; i++) {
                func_80022F20(actor->actorVars.rawVars[i].integer, func_80072718);

                actor1->health = 100;

                actor1 = GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer);

                actor1->unk6C = D_802BD49E[actor1->unk48][0];
                actor1->unk44 = D_802BD61C[actor1->unk48];
                
                actor1->actorVars.varCC.uchars[1] = 0xFF;
                actor1->actorVars.varCC.shorts[1] = 0;
                actor1->actorVars.varCC.uchars[0] = 0;
                
                actor1->unk4E = 2;
                
                func_80022F48(actor->actorVars.rawVars[i].integer, 0);
            }

            id = func_80023644(2, ZZ_ACTORS_KING_SKY, 30.0f, 31.0f, -550.0f, 0.0f, 0.0f, 0.0f);
            actor->actorVars.varB8.integer = id;

            if(id != -1){
                func_80022F20(actor->actorVars.varB8.integer, func_80072718);
                
                actor1 = GET_ACTOR_PTR(actor->actorVars.varB8.integer);
                actor1->health = 100;

                actor1 = GET_ACTOR_PTR(actor->actorVars.varB8.integer);
                actor1->unk44 = D_802BD61C[actor1->unk48];
                actor1->unk6C = D_802BD49E[actor1->unk48][0];
                actor1->unk4E = 2;
                
                func_80022F48(actor->actorVars.varB8.integer, 0);
            }

            id = func_80023644(2, ZZ_ACTORS_FAIRY, -30.0f, 90.0f, -550.0f, 0.0f, 0.0f, 0.0f);
            actor->actorVars.varBC.integer = id;

            if(id != -1){
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA0.integer = actor->actorVars.varB4.integer;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA4.fp = 10.0f;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA8.fp = 0.0f;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varAC.fp = 0.0f;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varB0.fp = 0.0f;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varB4.integer = 8;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->status = 1;
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->health = 100;
            }

            GET_ACTOR_PTR(actor->actorVars.varB4.integer)->flags |= 8;
            func_80024874(actor->actorVars.varB4.integer, 0.1f);
            
            D_800F0588.unk1B = 1;
            D_800F0588.unk1D = 0;
            D_800E69C0.unkF |= 2;
            
            D_800F0630 = 0xC;
            
            D_800F0588.unk4C = D_800F0548.unk0 = 257.0f;
            D_800F0588.unk50 = D_800F0548.unk4 = 498.0f;
            D_800F0588.unk54 = D_800F0548.unk8 = 214.0f;
            D_800F0588.unk40 = D_800F0548.unkC = 0.0f;
            D_800F0588.unk44 = D_800F0548.unk10 = 50.0f;
            D_800F0588.unk48 = D_800F0548.unk14 = -486.0f;
            D_800F0588.unk58 = 100.0f;
            D_800F0588.unk5C = 100.0f;
            D_800F0588.unk60 = 100.0f;
            D_800F0588.unk64 = 100.0f;
            D_800F0588.unk68 = 100.0f;
            D_800F0588.unk6C = 100.0f;

            
            zzAudioSeqSetVol(0x4E20, 0);
            zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_ENDING, 0);
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            if(D_800F3920.unk0 == 0){
                actor->actorVars.varC4.integer = 0;
                GET_ACTOR_PTR(idx)->status = 100;
            }
            break;
        case 100:
            t0 = 1;
            
            for(; t0 != 0;){
                switch(D_800B62C0[actor->actorVars.varC4.integer++]){
                    case 2:
                        t0 = 0;
                        GET_ACTOR_PTR(idx)->status = 150;
                        break;
                    case 1:
                        t0 = 0;
                        GET_ACTOR_PTR(idx)->status = 200;
                        break;
                    case 3:
                        D_800F0588.unk4C = D_800F0548.unk0 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk50 = D_800F0548.unk4 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk54 = D_800F0548.unk8 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk40 = D_800F0548.unkC = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk44 = D_800F0548.unk10 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk48 = D_800F0548.unk14 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        break;
                    case 4:
                        D_800F0588.unk4C = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk50 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk54 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        break;
                    case 5:
                        D_800F0588.unk40 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk44 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk48 = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        break;
                    case 6:
                        D_800F0588.unk6C = (f32)D_800B62C0[actor->actorVars.varC4.integer++];
                        D_800F0588.unk68 = D_800F0588.unk6C;
                        D_800F0588.unk64 = D_800F0588.unk68;
                        D_800F0588.unk60 = D_800F0588.unk64;
                        D_800F0588.unk5C = D_800F0588.unk60;
                        D_800F0588.unk58 = D_800F0588.unk5C;
                        break;
                    case 7:
                        temp = (s16)actor->actorVars.rawVars[D_800B62C0[actor->actorVars.varC4.integer++]].integer;
                        actor1 = GET_ACTOR_PTR(temp);

                        actor1->actorVars.varA0.integer = 7;
                        actor1->actorVars.varA4.fp = (f32)D_800B62C0[actor->actorVars.varC4.integer];
                        actor->actorVars.varC4.integer++;
                        break;
                    case 8:
                        GET_ACTOR_PTR(actor->actorVars.rawVars[D_800B62C0[actor->actorVars.varC4.integer]].integer)->actorVars.varA0.integer = 8;
                        actor->actorVars.varC4.integer++;
                        
                        break;
                    case 9:
                        GET_ACTOR_PTR(actor->actorVars.varB4.integer)->actorVars.varA0.integer = 9;
                        break;
                    case 0:
                        t0 = 0;
                        GET_ACTOR_PTR(idx)->status = 9000;
                        break;
                }
            }
            break;
        case 150:
            D_800E69C0.cfb_render |= 1;
            
            if(func_80012D40(0x12, D_800B62C0[actor->actorVars.varC4.integer], 0xF0) == 0){
                actor->actorVars.varC4.integer++;

                if(D_800B62C0[actor->actorVars.varC4.integer] == -1){
                    actor->actorVars.varC4.integer++;
                    GET_ACTOR_PTR(idx)->status = 100;
                }
                else{
                    actor->actorVars.varC0.integer = 2;
                    GET_ACTOR_PTR(idx)->status = 151;
                }
            }
            break;
        case 151:
            actor->actorVars.varC0.integer--;

            if(actor->actorVars.varC0.integer == 0){
                GET_ACTOR_PTR(idx)->status = 150;
            }
            break;
        case 200:
            actor->actorVars.varC0.integer = D_800B62C0[actor->actorVars.varC4.integer];
            actor->actorVars.varC4.integer++;
            GET_ACTOR_PTR(idx)->status = 201;
            break;
        case 201:
            actor->actorVars.varC0.integer--;

            if(actor->actorVars.varC0.integer <= 0){
                GET_ACTOR_PTR(idx)->status = 100;
            }
            break;
        case 9000:
            func_8000B120(2);
            D_800F3920.unk0 = 5;
            GET_ACTOR_PTR(idx)->status = 9001;
            break;
        case 9001:
            if(D_800F3920.unk0 == 0){
                GET_ACTOR_PTR(idx)->status = 9002;
            }
            break;
        case 9002:
            cdata.item |= CDATA_ITEM(44);

            sysGameData[D_800EEFB0[0]].characterNO = ZZ_CHARACTER_CORONA;
            sysGameData[D_800EEFB0[0]].unk12 = 0x19;

            if(cdata.lives < 2){
                sysGameData[D_800EEFB0[0]].lives = 2;
            }
            else{
                sysGameData[D_800EEFB0[0]].lives = cdata.lives;
            }

            sysGameData[D_800EEFB0[0]].bells = cdata.bells;
            sysGameData[D_800EEFB0[0]].item = cdata.item;
            sysGameData[D_800EEFB0[0]].settings = cdata.settings;
            sysGameData[D_800EEFB0[0]].raceBestTime = cdata.raceBestTime;

            for(i = 0; i < ZZ_EVENT_MAX; i++){
                sysGameData[D_800EEFB0[0]].events[i] = cdata.events[i];
            }

            func_80002BB8();
            D_800E69C0.unk3E[0].ishort = 8;
            
            GET_ACTOR_PTR(idx)->status = 9003;
            break;
        case 9003:
            if(--D_800E69C0.unk3E[0].ishort < 0){
                func_80002BF4();
                GET_ACTOR_PTR(idx)->status = 9004;
            }
            break;
        case 9004:
            D_800F5FB0.unk1C[0] = 1;
            D_800F5FB0_sets(0xB4, 2, 1);
            
            func_80007520(0xB4, 0);
            GET_ACTOR_PTR(idx)->status = 9005;
            break;
        case 9005:
            if (D_800F5FB0.unk0 == 3) {
                D_800E69C0.unkA = 0x63;
                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;
                
                GET_ACTOR_PTR(idx)->status = 9006;
            }
            break; 
        case 9006:
            break;
        
    }   
}

void func_80072718(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    f32 x;
    f32 y;
    f32 z;
    s16 id;

    if(actor->unk48 < 6){
        func_80077164(actor, idx);
    }
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 0;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            break;
        case 100:
            actor->actorVars.varA4.fp = 0.1;
            
            for(i = 0; i < 16; i++){
                x = (random(0) % 40U) - 40.0f;
                y = random(0) % 20U;
                z = (random(0) % 40U)- 40.0f;

                id = func_80023498(6, ZZ_ACTORS_CLOUD_15, actor->pos.x + x, actor->pos.y + y, actor->pos.z + z, 0.0f, 0.0f, 0.0f);
            
                if(id != -1){
                    func_80022F20(id, func_8002C2D0);
                    func_80024874(id, 0.4f);
                }
            }    

            actor->flags &= ~0x8;
            GET_ACTOR_PTR(idx)->status = 101;
            break;
        case 101:
            if(actor->actorVars.varA4.fp < 0.3){
                actor->actorVars.varA4.fp += 0.01;
                func_80024874(idx, actor->actorVars.varA4.fp);
            }

            actor->dir.y -= D_80159170 * 0.25;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0 && 0.3 == actor->actorVars.varA4.fp){
                GET_ACTOR_PTR(idx)->status = 1;
            }
            break;
    }
    switch(actor->actorVars.varA0.integer){
        case 7:
            actor->actorVars.varA0.integer = 0;
            actor->rot.y = actor->actorVars.varA4.fp;
            break;
        case 8:
            func_80023FCC(idx);
            break;
        case 9:
            GET_ACTOR_PTR(idx)->status = 100;
            actor->actorVars.varA0.integer = 0;
            break;
        case 0:
            break;
    }
    
}

