#include "6DAB0.h"
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
static s32 __op_scene_9(void);
static s32 __op_scene_10(void);

s32 __op_scene_11(void);
s32 __op_scene_12(void);
s32 __op_scene_13(void);

s32 D_801590E0;

f32 D_801590E4;
f32 D_801590E8;

extern u16 D_800F3950;

extern s32 D_800F39AC;

extern f32 D_801522E0;

extern s32 D_802BD61C[];

extern s16 D_802BD49E[][0xE];

extern s32 D_802BD630;

extern s16 D_802BD52A;

void func_8006CEB0() {
}


void func_8006CEB8(s16 idx) {
    static s32 D_800B61B0[] = { 4, 2, 3, 1, 0 };
    static u8 D_800B61C4[] = {
        1,    0xFF, 2,    0xFF, 3,    0xFF, 4,    0xFF, 4,    0xFF, 5,    0xFF, 0xFF, 6,
        0xFF, 7,    0xFF, 8,    0xFF, 9,    0xFF, 10,   0xFF, 11,   0xFF, 12,   0xFF, 0,
    };
    static zzOpSceneFunc D_800B61E0[] = {
        NULL,          __op_scene_0,  __op_scene_1, __op_scene_2, __op_scene_3, __op_scene_4,
        __op_scene_5,  __op_scene_6,  __op_scene_7, __op_scene_8, __op_scene_9, __op_scene_10,
        __op_scene_11, __op_scene_13, NULL,         NULL,
    };
    static s32 D_801590EC;
    s32 pad[3];
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;
    s32 i;

    (void)"Opening Story Demo Event 2.....\n";
    (void)"GET ATM : 0x%lx\n";
    (void)"GO FUNC: %d \n";

    switch (actor->status) {
        case 0:
            if (D_800E69C0.unk8 == 0x98) {
                actor->status = 100;
            }
            break;
        case 100:
            D_800F39AC = 0;
            cdata.unk44 |= 1;
            D_800E69C0.unkD &= ~1;
            D_800E69C0.unkE |= 1;

            D_801590EC = func_80023644(8, 0x1E2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

            func_80022F20(D_801590EC, func_80028024);

            GET_ACTOR_PTR(D_801590EC)->actorVars.varA0.integer = 0xC;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varA4.integer = 0x1F4;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varA8.integer |= 0x1301;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varAC.integer = 0;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varB4.integer = 0x3C;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varB8.integer = 0x3C;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varBC.integer = idx;
            GET_ACTOR_PTR(D_801590EC)->actorVars.varC0.integer = 0xD;

            D_800F0548.unkC = 0.0f;
            D_800F0548.unk10 = 580.0f;
            D_800F0548.unk14 = 770.0f;
            D_800F0548.unk0 = 0.0f;
            D_800F0548.unk4 = 600.0f;
            D_800F0548.unk8 = 970.0f;

            D_801522E0 = 0.0f;

            D_800E69C0.unk3E[0].ishort = func_80023498(2, 4, 0.0f, 52.0f, -16.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk3E[1].ishort = func_80023498(2, 2, 35.0f, 1.0f, 45.0f, 0.0f, -60.0f, 0.0f);
            D_800E69C0.unk3E[2].ishort = func_80023498(2, 3, -35.0f, 1.0f, 30.0f, 0.0f, 60.0f, 0.0f);
            D_800E69C0.unk3E[3].ishort = func_80023498(2, 1, -15.0f, 1.0f, 200.0f, 0.0f, 180.0f, 0.0f);
            D_800E69C0.unk3E[4].ishort = func_80023498(2, 0, 15.0f, 1.0f, 220.0f, 0.0f, 180.0f, 0.0f);

            D_800E69C0.unk4E = func_80023498(6U, 0x19A, 187.0f, 40.0f, -187.0f, 0.0f, 0.0f, 0.0f);
            func_80024158(D_800E69C0.unk4E, 0, 0, 0, 255);

            GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.x = GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.y =
                GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.z = 0.1;

            for (i = 0; i < 5; i++) {
                actor2 = GET_ACTOR_PTR(D_800E69C0.unk3E[i].ishort);

                actor2->unk44 = D_802BD61C[D_800B61B0[i]];
                GET_ACTOR_PTR(D_800E69C0.unk3E[i].ishort)->unk44 = D_802BD61C[D_800B61B0[i]];

                func_80022F20(D_800E69C0.unk3E[i].ishort, func_8002D6BC);

                actor2->unk4E = 2;
                actor2->unk6C = D_802BD49E[D_800B61B0[i]][0];

                func_80022F48(D_800E69C0.unk3E[i].ishort, 0);
            }

            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varAC.integer = 0;

            func_8000B120(2);

            D_800F3920.unk0 = 6;
            D_800F3920.unk2 = 0xA;

            D_800E69C0.unkE |= 1;

            func_800073C0(0x2A, 0);

            D_800F5FB0.unk1C[0] = 1;
            D_800F5FB0_sets(1, 2, 1);

            actor->status = 150;

            func_8007FFB0(0);
            break;
        case 110:
            func_800284A4(1.0f, 5, cdata.unk41);
            func_8002875C(1.0f, 5, &D_801522E0, 1);

            if ((&D_800F3940)[cdata.unk41]->unk14 == 1) {
                D_800F0548.unkC = 0.0f;
                D_800F0548.unk10 = 0.0f;
                D_800F0548.unk14 = 0.0f;
                D_800F0548.unk0 = 0.0f;
                D_800F0548.unk4 = 0.0f;
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
            if (D_800B61C4[actor->actorVars.varA4.integer] == 0xFF) {
                actor->actorVars.varA4.integer++;
                actor->status = 250;
            } else if (D_800B61C4[actor->actorVars.varA4.integer] != 0) {
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

            if (func_80012D40(0xF, actor->actorVars.varA8.integer, 0xF0) == 0) {
                actor->status = 200;
                actor->actorVars.varA8.integer++;
            }
            break;
        case 300:
            if (D_800B61E0[D_800B61C4[actor->actorVars.varAC.integer]]() == 0) {
                actor->status = 200;
            }
            break;
        case 9999:
            if (D_800F5FB0.unk0 == 3) {
                func_80023FCC(D_800E69C0.unk3E[0].ishort);
                func_80023FCC(D_800E69C0.unk3E[1].ishort);

                func_80007648(0);
                func_8000B120(2);

                D_800F3920.unk0 = 5;
                D_800F3920.unk2 = 1;

                D_800E69C0.unkA = 0x99;

                cdata.unk42 = 0;

                D_800F3950 = 0xD;
                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;
                cdata.unk44 = 0;
            }
            break;
    }
}

 s32 __op_scene_0() {
    (void)"__op_scene_0\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800E69C0.unk52 = 0x78;
            D_800E69C0.unk3C.ishort = 0xA;
            break;
        case 10:
            if ((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0) {
                D_801590E4 = (D_800F0548.unk10 - 47.0) / 180.0;
                D_801590E8 = (D_800F0548.unk14 - 41.0) / 180.0;
                D_800E69C0.unk52 = 0xB4;
                D_800E69C0.unk3C.ishort = 0x14;
            }

            break;
        case 20:
            if ((D_800E69C0.unk52 = D_800E69C0.unk52 - 1) < 0) {
                return 0;
            }
            
            D_800F0548.unk14 -= D_801590E8;\
            D_800F0548.unk8 -= D_801590E8;\
            D_800F0548.unk10 -= D_801590E4;\
            D_800F0548.unk4 -= D_801590E4;\

            break;
    }

    return 1;
}

 s32 __op_scene_1() {
    (void)"__op_scene_1\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            func_80022F48(D_800E69C0.unk3E[3].ishort, 1);
            func_80022F48(D_800E69C0.unk3E[4].ishort, 1);
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z -= 0.8;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.z -= 0.8;

            if (GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z <= 70.0) {
                func_80022F48(D_800E69C0.unk3E[3].ishort, 0);
                func_80022F48(D_800E69C0.unk3E[4].ishort, 0);

                return 0;
            }
            break;
    }

    return 1;
}

 s32 __op_scene_2() {
    (void)"__op_scene_2\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unkC = -288.0f;
            D_800F0548.unk10 = 66.0f;
            D_800F0548.unk14 = -97.0f;
            D_800F0548.unk0 = 110.0f;
            D_800F0548.unk4 = 6.0f;
            D_800F0548.unk8 = 113.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->rot.y = 150.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->rot.y = 120.0f;

            return 0;
    }

    return 1;
}

 s32 __op_scene_3() {
    (void)"__op_scene_3\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unkC = 0.0f;
            D_800F0548.unk10 = 69.0f;
            D_800F0548.unk14 = -138.0f;
            D_800F0548.unk0 = 0.0f;
            D_800F0548.unk4 = 90.0f;
            D_800F0548.unk8 = 61.0f;

            return 0;
    }

    return 1;
}

 s32 __op_scene_4() {
    (void)"__op_scene_4\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unkC = -288.0f;
            D_800F0548.unk10 = 66.0f;
            D_800F0548.unk14 = -97.0f;
            D_800F0548.unk0 = 110.0f;
            D_800F0548.unk4 = 6.0f;
            D_800F0548.unk8 = 113.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.x = 0.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.y = 1.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.z = 35.0f;

            return 0;
        case 10:
            break;
    }

    return 1;
}

 s32 __op_scene_5() {
    (void)"__op_scene_5\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unkC = 187.0f;
            D_800F0548.unk10 = 30.0f;
            D_800F0548.unk14 = -165.0f;
            D_800F0548.unk0 = 187.0f;
            D_800F0548.unk4 = 30.0f;
            D_800F0548.unk8 = 35.0f;

            return 0;
        case 10:
            break;
    }

    return 1;
}

 s32 __op_scene_6() {
    (void)"__op_scene_6\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.x += 0.05;
            GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.y = GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.z =
                GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.x;

            if (GET_ACTOR_PTR(D_800E69C0.unk4E)->scale.x >= 3.5) {
                return 0;
            }
    }

    return 1;
}

 s32 __op_scene_7() {
    Actor* actor;

    (void)"__op_scene_7\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800E69C0.unk48 = func_80023498(2U, 5U, 187.0f, 40.0f, -187.0f, 0.0f, 0.0f, 0.0f);
            func_80022F20(D_800E69C0.unk48, func_8002D6BC);

            actor = GET_ACTOR_PTR(D_800E69C0.unk48);
            actor->unk44 = D_802BD630;
            actor->unk4E = 2;
            actor->unk6C = D_802BD52A;

            func_80022F48(D_800E69C0.unk48, 5);
            D_800F0548.unkC = 188.0f;
            D_800F0548.unk10 = 53.0f;
            D_800F0548.unk14 = -96.0f;
            D_800F0548.unk0 = 260.0f;
            D_800F0548.unk4 = 62.0f;
            D_800F0548.unk8 = 104.0f;

            func_80008C6C(0x30, 1);

            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z += 2.0;
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.y += 0.8;

            if (-150.0 < GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z) {
                D_800E69C0.unk3C.ishort = 20;
            }
            break;
        case 20:
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z += 1.0;
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.y -= 1.0;

            if (GET_ACTOR_PTR(D_800E69C0.unk48)->pos.y <= 1.0) {
                func_80022F48(D_800E69C0.unk48, 0);
                func_80008C6C(0xA6, 1);

                return 0;
            }
            break;
    }

    return 1;
}

 s32 __op_scene_8() {
    (void)"__op_scene_8...\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.x = 0.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->pos.z = 35.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->rot.y = 80.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.x = 20.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z = 35.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->rot.y = 80.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.x = -5.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->pos.z = 55.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[2].ishort)->rot.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.x = 0.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->pos.z = 75.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[3].ishort)->rot.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.x = 5.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->pos.z = 95.0f;
            GET_ACTOR_PTR(D_800E69C0.unk3E[4].ishort)->rot.y = 100.0f;
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.x = 70.0f;
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z = 50.0f;
            GET_ACTOR_PTR(D_800E69C0.unk48)->rot.y = -80.0f;

            D_800F0548.unkC = -83.0f;
            D_800F0548.unk10 = 10.0f;
            D_800F0548.unk14 = -41.0f;
            D_800F0548.unk0 = 135.0f;
            D_800F0548.unk4 = 25.0f;
            D_800F0548.unk8 = 160.0f;

            return 0;
    }

    return 1;
}

 s32 __op_scene_9() {
    (void)"__op_scene_9...\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            func_80007648(0);
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            func_800073C0(0xB, 0);

            D_800F0548.unkC = 92.0f;
            D_800F0548.unk10 = 79.0f;
            D_800F0548.unk14 = 149.0f;
            D_800F0548.unk0 = 219.0f;
            D_800F0548.unk4 = 159.0f;
            D_800F0548.unk8 = 350.0f;

            D_800E69C0.unk54 = func_80023498(6, 0x184, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            D_800E69C0.unk56 = func_80023498(2, 0x5B, 0.0f, 100.0f, 40.0f, 0.0f, 0.0f, 0.0f);

            func_80022F20(D_800E69C0.unk56, func_80028C00);

            D_800E69C0.unk58 =
                func_80023644(6, 0x4E, GET_ACTOR_PTR(D_800E69C0.unk56)->pos.x, GET_ACTOR_PTR(D_800E69C0.unk56)->pos.y,
                              GET_ACTOR_PTR(D_800E69C0.unk56)->pos.z, 0.0f, 0.0f, 0.0f);

            GET_ACTOR_PTR(D_800E69C0.unk58)->actorVars.varA0.integer = D_800E69C0.unk56;

            func_80022F20(D_800E69C0.unk58, func_80028CF8);
            func_80077D24();

            return 0;
    }

    return 1;
}

 s32 __op_scene_10() {
    (void)"__op_scene_10...\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            func_800073C0(0x2B, 0);

            func_80023FCC(D_800E69C0.unk54);
            func_80023FCC(D_800E69C0.unk56);
            func_80023FCC(D_800E69C0.unk58);

            D_800F0548.unkC = -83.0f;
            D_800F0548.unk10 = 10.0f;
            D_800F0548.unk14 = -41.0f;
            D_800F0548.unk0 = 135.0f;
            D_800F0548.unk4 = 25.0f;
            D_800F0548.unk8 = 160.0f;

            return 0;
    }
    return 1;
}

 s32 __op_scene_11() {
    (void)"__op_scene_11...\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unkC = 187.0f;
            D_800F0548.unk10 = 30.0f;
            D_800F0548.unk14 = -165.0f;
            D_800F0548.unk0 = 187.0f;
            D_800F0548.unk4 = 30.0f;
            D_800F0548.unk8 = 35.0f;

            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.x = 187.0f;
            GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z = -100.0f;

            GET_ACTOR_PTR(D_800E69C0.unk48)->rot.y = 180.0f;

            func_80022F48(D_800E69C0.unk48, 2);

            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            if((GET_ACTOR_PTR(D_800E69C0.unk48)->pos.z -= 1.0f) <= -187.0f){
                func_80023FCC(D_800E69C0.unk48);
                D_800E69C0.unk58 = 0x3C;
                D_800E69C0.unk3C.ishort = 20;
            }
            break;
        case 20:
            if ((D_800E69C0.unk58 = D_800E69C0.unk58 - 1) < 0) {
                D_800F0548.unkC = -83.0f;
                D_800F0548.unk10 = 10.0f;
                D_800F0548.unk14 = -41.0f;
                D_800F0548.unk0 = 135.0f;
                D_800F0548.unk4 = 25.0f;
                D_800F0548.unk8 = 160.0f;

                return 0;
            }
            break;
    }
    return 1;
}

s32 __op_scene_12() {
    (void)"NOP...\n";

    return 0;
}

s32 __op_scene_13() {
    (void)"NOP...\n";

    return 0;
}
