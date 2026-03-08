#include "70DF0.h"
#include "zzOpScene.h"
#include "actor.h"
#include "23B20.h"
#include "global.h"
#include "B4E0.h"
#include "7FC0.h"
#include "80BB0.h"
#include "284C0.h"
#include "13940.h"
#include "9320.h"
#include "73660.h"
#include "2DE50.h"

#include "common.h"

static s32 __op_scene_0(void);
static s32 __op_scene_1(void);
static s32 __op_scene_2(void);
static s32 __op_scene_3(void);
static s32 __op_scene_4(void);
static s32 __op_scene_5(void);
static s32 __op_scene_6(void);
static s32 __op_scene_7(void);
static s32 __op_scene_8(void);
static s32 __op_scene_8a(void);
static s32 __op_scene_10(void);
static s32 __op_scene_11(void);

extern s32 D_800F39AC;
extern s32 D_802BD61C[];

extern f32 D_801522E0;

extern u16 D_800F3950;

extern s16 D_802BD49E[][0xE];

s32 D_80159150;
s32 D_80159154;
s32 D_80159158;

void func_800701F0(s16 idx){
    static s32 D_800B6260[] = {
        0,1,2,3,4
    }; 
    static u8 D_800B6274[] = {
        0x01, 0xFF, 0x02, 0xFF, 0x03, 0x04, 0xFF, 0xFF, 0x05, 0xFF, 0x06, 0x07,
        0xFF, 0x08, 0xFF, 0x09, 0xFF, 0x0A, 0xFF, 0xFF, 0x0B, 0x00, 0x00, 0x00,
    };
    static zzOpSceneFunc D_800B628C[] = {
        NULL, __op_scene_0, __op_scene_1, __op_scene_2, __op_scene_3, __op_scene_4, __op_scene_5,
        __op_scene_6, __op_scene_7, __op_scene_8, __op_scene_8a, __op_scene_10, __op_scene_11,
    };
    static s32 D_8015915C;
    
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;
    s32 pad[3];
    s32 i;

    (void)"Opening Story Demo Event Prolog.....\n";
    (void)"GET ATM : 0x%lx\n";
    (void)"GO FUNC: %d \n";
    
    switch(actor->status){
        case 0:
            if(D_800E69C0.unk8 == 0x99){
                actor->status = 0x64;
            }
            break;
        case 100:
            D_800F39AC = 0;
            cdata.unk44 |= 1;
            D_800E69C0.unkD &= ~1;
            D_800E69C0.unkE |= 1;

            D_8015915C = func_80023644(8, 0x1E2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

            func_80022F20(D_8015915C, func_80028024);

            GET_ACTOR_PTR(D_8015915C)->actorVars.varA0.integer = 0xC;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varA4.integer = 0x1F4;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varA8.integer |= 0x1301;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varAC.integer = 0;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varB4.integer = 0x3C;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varB8.integer = 0x3C;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varBC.integer = idx;
            GET_ACTOR_PTR(D_8015915C)->actorVars.varC0.integer = 0xD;

            D_800F0548.unkC = 1218.0f;
            D_800F0548.unk10 = 128.0f;
            D_800F0548.unk14 = -190.0f;
            D_800F0548.unk0 = 1218.0f;
            D_800F0548.unk4 = 148.0f;
            D_800F0548.unk8 = 11.0f;

            D_801522E0 = 0.0f;

            D_800E69C0.unk3E[0].ishort = func_80023498(2, 0, 1220.0f, 100.0f, -200.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3E[1].ishort = func_80023498(2, 1, 1250.0f, 100.0f, -200.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3E[2].ishort = func_80023498(2, 2, 1190.0f, 100.0f, -200.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3E[3].ishort = func_80023498(2, 3, 1280.0f, 100.0f, -200.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3E[4].ishort = func_80023498(2, 4, 1160.0f, 100.0f, -200.0f, 0.0f, 0.0f, 0.0f);
            
            func_80077D24();
            
            for (i = 0; i < 5; i++) {
                actor2 = GET_ACTOR_PTR(D_800E69C0.unk3E[i].ishort);

                actor2->unk44 = D_802BD61C[D_800B6260[i]];
                GET_ACTOR_PTR(D_800E69C0.unk3E[i].ishort)->unk44 = D_802BD61C[D_800B6260[i]];

                func_80022F20(D_800E69C0.unk3E[i].ishort, func_8002D6BC);

                actor2->unk4E = 2;
                actor2->unk6C = D_802BD49E[D_800B6260[i]][0];

                func_80022F48(D_800E69C0.unk3E[i].ishort, 0);
            }    
            
            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varAC.integer = 0;

            func_8000B120(2);

            D_800F3920.unk0 = 6;
            D_800F3920.unk2 = 0xA;

            D_800E69C0.unkE |= 1;

            func_800073C0(0x2F, 0);

            D_800F5FB0.unk1C[0] = 1;
            D_800F5FB0_sets(1, 2, 1);

            actor->status = 150;

            break;
        case 110:
            func_800284A4(1.0f, 5, cdata.unk41);
            func_8002875C(1.0f, 5, &D_801522E0, 1);

            if ((&D_800F3940)[cdata.unk41]->unk14 == 1) {
                D_800F0548.unkC = 1220.0f;
                D_800F0548.unk10 = 100.0f;
                D_800F0548.unk14 = -0.0f;
                D_800F0548.unk0 = 1220.0f;
                D_800F0548.unk4 = 100.0f;
                D_800F0548.unk8 = 100.0f;
            }
            break;
        case 150:
            if (D_800F5FB0.unk0 == 3 && D_800F3920.unk0 == 0) {
                D_800F5FB0_sets(0x3C, 1, 1);
                actor->status = 200;
            }
            break;
        case 200:
            if(D_800F3944->unk38 != 0){
                actor->status = 110;
                break;
            }
            if (D_800B6274[actor->actorVars.varA4.integer] == 0xFF) {
                actor->actorVars.varA4.integer++;
                actor->status = 250;
            } else if (D_800B6274[actor->actorVars.varA4.integer] != 0) {
                GET_ACTOR_PTR(idx)->actorVars.varAC.integer = actor->actorVars.varA4.integer;
                GET_ACTOR_PTR(idx)->actorVars.varA4.integer++;

                D_800E69C0.unk3C.ishort = 0;
                actor->status = 300;
            } else {
                D_800F5FB0_sets(0x3C, 2, 1);
                func_80007520(0xB4, 0);
                actor->status = 9999;
            }
            break;
        case 250:
            D_800E69C0.unkE |= 1;

            if (func_80012D40(0x5A, actor->actorVars.varA8.integer, 0xF0) == 0) {
                actor->status = 200;
                actor->actorVars.varA8.integer++;
            }
            break;
        case 300:
            if (D_800B628C[D_800B6274[actor->actorVars.varAC.integer]]() == 0) {
                actor->status = 200;
            }
            break;
        case 9999:
            if (D_800F5FB0.unk0 == 3) {
                func_80023FCC(D_800E69C0.unk3E[0].ishort);
                func_80023FCC(D_800E69C0.unk3E[1].ishort);
                func_80023FCC(D_800E69C0.unk3E[2].ishort);
                func_80023FCC(D_800E69C0.unk3E[3].ishort);
                func_80023FCC(D_800E69C0.unk3E[4].ishort);
                

                func_80007648(0);
                func_8000B120(2);

                D_800F3920.unk0 = 5;
                D_800F3920.unk2 = 1;

                D_800E69C0.unkA = 0x1F4;

                cdata.unk42 = 0;

                D_800F3950 = 0xD;
                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;
                cdata.unk44 = 0;
            }
            break;
    }
}

static s32 __op_scene_0(){
    (void)"__op_scene_0\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            D_800E69C0.unk52 = 120;
            D_800E69C0.unk3C.ishort = 10;
            
        case 10:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                return 0;
            }
            
            break;
    }

    return 1;
}

static s32 __op_scene_1(){
    (void)"__op_scene_1\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:    
            D_800E69C0.unk48 = func_80023644(6, 0x15F, 1150.0f, 95.0f, 290.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk4A = func_80023644(6, 0x1E2, 1150.0f, 95.0f, 290.0f, 0.0f, 0.0f, 0.0f);
            D_80159178->unk48[cdata.unk41].unk0 = D_800E69C0.unk4A;
            
            func_80022F20(D_800E69C0.unk48, func_8002F820);

            D_800E69C0.unk52 = 120;
            D_800E69C0.unk3C.ishort = 10;
            
            D_800F0548.unkC = 1218.0f;
            D_800F0548.unk10 = 146.0f;
            D_800F0548.unk14 = 104.0f;
            D_800F0548.unk0 = 1218.0f;
            D_800F0548.unk4 = 146.0f;
            D_800F0548.unk8 = -96.0f;

            break;
        case 10:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                D_800E69C0.unk52 = 240;
                D_800E69C0.unk3C.ishort = 20;
            }
            else{
                D_800F0548.unkC += 1.0;
            }
            break;
        case 20: 
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                D_800E69C0.unk52 = 32;
                D_800E69C0.unk3C.ishort = 30;
            }
            else{
                D_800F0548.unkC -= 1.0;
            }
            break;
        case 30:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                D_800E69C0.unk3C.ishort = 40;
            }
            else{
                D_800F0548.unkC += 2.5;
            }
            break;
        case 40:
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x = 1000.0f;
            return 0;
            break;
    }

    return 1;
}

static s32 __op_scene_2(){
    s32 i;
    
    (void)"__op_scene_2\n";
    
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:  
            D_800F0548.unkC = 1161.0f;
            D_800F0548.unk10 = 130.0f;
            D_800F0548.unk14 = 383.0f;
            D_800F0548.unk0 = 1161.0f;
            D_800F0548.unk4 = 130.0f;
            D_800F0548.unk8 = 483.0f;

            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x = 1300.0f;

            D_800E69C0.unk52 = 250;

            for(i = 0; i < 5; i++){
                func_80022F48(D_800E69C0.unk3E[i].ishort, 2);
            }

            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            if(D_800E69C0.unk52 == 80){
                D_800F5FB0_sets(0x3C, 2, 1);
            }
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                D_800E69C0.unk3C.ishort = 20;
            }
            else{
                GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.z += 0.9;
                GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z += 1.0;
                GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.z += 0.6;
                GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z += 1.2;
                GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.z += 1.0;
                
            }
            break;
        case 20:
            if (D_800F5FB0.unk0 == 3) {
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_3(){
    s32 i;

    (void)"__op_scene_3\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            D_800F5FB0_sets(0x3C, 1, 1);

            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.x = 1185.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.z = 20.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.x = 1215.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z = 40.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.x = 1155.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.z = 40.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.x = 1245.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.y = 100.0f;;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z = 60.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.x = 1125.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.z = 60.0f;

            for(i = 0; i < 5; i++){
                func_80022F48(D_800E69C0.unk3E[i].ishort, 0);
            }

            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x = 1185.0f;
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.y = 105.0f;
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z = 70.0f;
            
            D_800F0548.unkC = 1183.0f;
            D_800F0548.unk10 = 130.0f;
            D_800F0548.unk14 = 107.0f;
            D_800F0548.unk0 = 1183.0f;
            D_800F0548.unk4 = 150.0f;
            D_800F0548.unk8 = -128.0f;

            return 0;
            break;
    }

    return 1;
}

static s32 __op_scene_4(){
    (void)"__op_scene_4\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            D_800E69C0.unk4C = func_80023644(6, 0x4E, GET_ACTOR_PTR(D_800E69C0.unk48)->pos.x, GET_ACTOR_PTR(D_800E69C0.unk48)->pos.y, GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z, 0.0f, 0.0f, 0.0f);
            GET_ACTOR_PTR(D_800E69C0.unk4C)->actorVars.varA0.integer = D_800E69C0.unk48;
            func_80022F20(D_800E69C0.unk4C, func_80028CF8);

            D_800E69C0.unk52 = 60;
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_5(){
    (void)"__op_scene_5\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            func_80023FCC(D_800E69C0.unk4C);
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            D_800E69C0.unk52 = 60;
            D_800E69C0.unk3C.ishort = 20;
            
            D_800F0548.unkC = 1185.0f;
            D_800F0548.unk10 = 108.0f;
            D_800F0548.unk14 = -32.0f;
            D_800F0548.unk0 = 1185.0f;
            D_800F0548.unk4 = 104.0f;
            D_800F0548.unk8 = 68.0f;
            break;
        case 20:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                D_800E69C0.unk3C.ishort = 30;
            }
            break;
        case 30:
            func_80077CF4();

            D_800E69C0.unk52 = 90;
            D_800E69C0.unk3C.ishort = 40;
            break;
        case 40:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                return 0;
            }
            break;
    }
    
    return 1;
}

static s32 __op_scene_6(){
    (void)"__op_scene_6\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            D_800F0548.unkC = 1183.0f;
            D_800F0548.unk10 = 130.0f;
            D_800F0548.unk14 = 107.0f;
            D_800F0548.unk0 = 1183.0f;
            D_800F0548.unk4 = 150.0f;
            D_800F0548.unk8 = -128.0f;   

            return 0;
            break;
    }

    return 1;
}


static s32 __op_scene_7(){
    static f32 D_80159160;
    static f32 D_80159164;
    f64 temp;

    (void)"__op_scene_7\n";
    
    switch(D_800E69C0.unk3C.ishort){
        case 0:
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z = 500.0f;
            D_80159160 = (GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x - 500.0) / 180.0;

            if(GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z < -500.0) {
                temp = (-500.0 - GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z);
            }
            else{
                temp = -(-500.0 - GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z);
            }

            D_80159164 = temp / 180.0;
            
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            if(GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x <= 400.0 && GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z <= -350.0){
                D_800E69C0.unk3C.ishort = 20;
                break;
            }
            else{
                GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x -= D_80159160;
                GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z -= D_80159164;
                
                D_800F0548.unkC = GET_ACTOR_PTR(D_800E69C0.unk48)->pos.x;
                D_800F0548.unk10 = GET_ACTOR_PTR(D_800E69C0.unk48)->pos.y;
                D_800F0548.unk14 = GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z;
                D_800F0548.unk0 = D_800F0548.unkC;
                D_800F0548.unk4 = D_800F0548.unk10;
                D_800F0548.unk8 = D_800F0548.unk14 + 100.0f;        
                break;
            }
        case 20:
            D_800F0548.unkC = 500.0f;
            D_800F0548.unk10 = 137.0f;
            D_800F0548.unk14 = -372.0f;
            D_800F0548.unk0 = 500.0f;
            D_800F0548.unk4 = 97.0f;
            D_800F0548.unk8 = -172.0f;
            
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.x = 450.0f;
            GET_ACTOR_PTR(D_800E69C0.unk4A)->pos.z = -350.0f;
            return 0;
            break;
    }

    return 1;
}

static s32 __op_scene_8(){
    (void)"__op_scene_8...\n";
    
    switch (D_800E69C0.unk3C.ishort){
        case 0:
            D_800E69C0.unk4E = func_80023644(1, 0x20, 500.0f, 272.0f, -488.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            D_800F0548.unk10 += 0.5;
            D_800F0548.unk4 += 0.5;

            if(D_800F0548.unk10 >= 235.0){
                return 0;
            }
            break;
    }
    
    return 1;
}

static s32 __op_scene_8a(){
    (void)"__op_scene_8a...\n";
    
    switch (D_800E69C0.unk3C.ishort){
        case 0:
            D_800F0548.unk10 -= 0.5;
            D_800F0548.unk4 -= 0.5;

            if(D_800F0548.unk10 <= 137.0){
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_10(){
    s32 i;
    
    (void)"__op_scene_10...\n";
    
    
    switch (D_800E69C0.unk3C.ishort){
        case 0:
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.x = 500.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.z = -400.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.x = 530.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z = -400.0f;;

            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.x = 470.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.z = -400.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.x = 560.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z = -400.0f;

            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.x = 440.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.z = -400.0f;  

            D_800E69C0.unk52 = 120;
            D_800E69C0.unk3C.ishort = 10;
                    
            D_800F0548.unkC = 500.0f;
            D_800F0548.unk10 = 183.0f;
            D_800F0548.unk14 = -264.0f;
            D_800F0548.unk0 = 500.0f;
            D_800F0548.unk4 = 224.0f;
            D_800F0548.unk8 = -164.0f;
            
            break;
        case 10:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) <= 0){
                for(i = 0; i < 5; i++){
                    func_80022F48(D_800E69C0.unk3E[i].ishort, 5);
                }
                D_800E69C0.unk52 = 30;
                D_800E69C0.unk3C.ishort = 20;
            }

            break;
        case 20:
            if((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0){
                return 0;
            }
            for(i = 0; i < 5; i++){
                GET_ACTOR_PTR(D_800E69C0.unk3E[i].ishort)->pos.y += 1.0;
            }

            break;
    }

    return 1;
}

static s32 __op_scene_11() {
    (void)"NOP...\n";
    
    return 0;
}
