#include "6F000.h"

#include "23B20.h"
#include "72610.h"
#include "284C0.h"
#include "2DE50.h"
#include "13940.h"
#include "73660.h"
#include "B4E0.h"
#include "7FC0.h"
#include "common.h"
#include "zzOpScene.h"

static s32 __op_scene_0(void);
static s32 __op_scene_1(void);
static s32 __op_scene_2(void);
static s32 __op_scene_3(void);
static s32 __op_scene_4(void);

extern u16 D_800F3950;
extern s32 D_800F39AC;

extern f32 D_801522E0;

extern s32 D_802BD61C[];
extern s32 D_802BD630;


void func_8006E400(s16 idx) {
    static u8 D_800B6220[] = {
        1, 0xFF, 2, 0xFF, 3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 4, 0xFF, 0xFF, 0xFF, 0xFF, 0,

    };
    static zzOpSceneFunc D_800B6234[] = {
        NULL,         __op_scene_0, __op_scene_1, __op_scene_2, __op_scene_3, __op_scene_4,
        __op_scene_4, __op_scene_4, __op_scene_4, __op_scene_4, __op_scene_4,
    };
    static s32 D_801590F0;
    static s32 D_801590F4;
    static f32 D_801590F8[2];
    static f32 D_80159100[2];
    static f32 D_80159108[2];
    static f32 D_80159110[2];
    static f32 D_80159118[2];
    static f32 D_80159120[2];

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;

    (void)"Opening Story Demo Event (debug).....\n";
    (void)"tell.....\n";

    (void)"Opening Story Demo Event.....\n";
    (void)"CORONA MNO %d\n";
    (void)"KING MNO %d\n";

    if (cdata.unk46[0] & 0x4000 || D_800E69C0.unkA == 0xC8) {
        D_800E69C0.unkA = 0xC8;
        func_80022F20(idx, func_80071A10);

        return;
    }
    switch (actor->status) {
        case 0:
            if (D_800E69C0.unk8 == 0x97) {
                actor->status = 100;
            } else {
                actor->status = 5;
            }
            break;
        case 5:
            cdata.unk44 |= 1;
            actor->actorVars.varA4.integer = func_80023644(1, 0x2F, 150.0f, 60.0f, -410.0f, 0.0f, 0.0f, 0.0f);
            func_80022F20(actor->actorVars.varA4.integer, func_80030ADC);

            actor->status = 10;
            break;
        case 10:
            if (func_80024E0C(actor->actorVars.varA4.integer, D_80159178->unk48[cdata.unk41].unk0) < 50.0f) {
                actor->status = 15;
            }
            break;
        case 15:
            if (func_80012D40(0x12, 0, 1) == 0) {
                actor->status = 20;
            }
            break;
        case 20:
            if (func_80024E0C(actor->actorVars.varA4.integer, D_80159178->unk48[cdata.unk41].unk0) > 100.0f) {
                actor->status = 10;
            }
            break;
        case 50:
            if (D_800F5FB0.unk0 == 3) {
                actor->status = 9999;
            }
            break;
        case 100:
            D_800F39AC = 0;

            cdata.unk44 |= 1;
            D_800E69C0.unkD &= ~1;
            D_800E69C0.unkE |= 1;

            D_801590F0 = func_80023644(8, 0x1E2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            func_80022F20(D_801590F0, func_80028024);

            GET_ACTOR_PTR(D_801590F0)->actorVars.varA0.integer = 0xC;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varA4.integer = 0x1F4;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varA8.integer |= 0x1301;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varAC.integer = 0;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varB4.integer = 0x3C;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varB8.integer = 0x3C;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varBC.integer = idx;
            GET_ACTOR_PTR(D_801590F0)->actorVars.varC0.integer = 0xD;

            D_800F0548.unkC = -220.0f;
            D_800F0548.unk10 = 40.0f;
            D_800F0548.unk14 = -450.0f;
            D_800F0548.unk0 = 280.0f;
            D_800F0548.unk4 = 80.0f;
            D_800F0548.unk8 = -450.0f;

            D_801590F8[0] = 0.0f;
            D_801590F8[1] = 0.0f;

            D_80159100[0] = 30.0f;
            D_80159108[0] = -500.0f;
            D_80159100[1] = 31.0f;
            D_80159108[1] = -300.0f;

            D_80159110[0] = 0.0f;
            D_80159118[0] = 0.0f;
            D_80159120[0] = 0.0f;

            D_800E69C0.unk3E[0].ishort =
                func_80023644(2, 0xB, D_801590F8[0], D_80159100[0], D_80159108[0], 0.0f, 0.0f, 0.0f);

            func_80022F20(D_800E69C0.unk3E[0].ishort, NULL);

            actor2 = GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort);

            actor2->unk44 = D_802BD61C[GET_ACTOR_PTR(D_800E69C0.unk3E[0].ishort)->unk48];
            actor2->unk4E = 2;
            actor2->unk6C = 0x37;

            D_800E69C0.unk3E[1].ishort =
                func_80023644(2, 5, D_801590F8[1], D_80159100[1], D_80159108[1], 0.0f, 180.0f, 0.0f);

            func_80022F20(D_800E69C0.unk3E[1].ishort, NULL);

            actor2 = GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort);

            actor2->unk44 = D_802BD630;
            (&D_801414A0[actor2->unk38])[D_803361C0.unk44]->unk48 = D_803361C0.unk3C;
            (&D_801414A0[actor2->unk38])[D_803361C0.unk44]->unk4C = D_803361C0.unk40;
            actor2->unk4E = 2;
            actor2->unk6C = D_802BD494.unk96;

            func_80074D74(actor2, D_802BD494.unk9A);
            func_80022F48(D_800E69C0.unk3E[1].ishort, 2);

            actor->actorVars.varAC.integer = 0;
            actor->actorVars.varB0.integer = 1;
            actor->actorVars.varB4.integer = 0;

            func_8000B120(2);

            D_800F3920.unk0 = 6;
            D_800F3920.unk2 = 0xA;

            D_800E69C0.unkE |= 1;

            func_800073C0(0x35, 0);

            actor->status = 150;
            break;
        case 110:
            func_80028874(0.1f, 0xA, &D_80159110[actor->actorVars.varA0.integer],
                          &D_80159118[actor->actorVars.varA0.integer], &D_80159120[actor->actorVars.varA0.integer], 1);

            func_800284A4(1.0f, 5, cdata.unk41);
            func_8002875C(1.0f, 5, &D_801522E0, 1);

            GET_ACTOR_PTR(D_800E69C0.unk3E[actor->actorVars.varA0.integer].ishort)->rot.x =
                D_80159110[actor->actorVars.varA0.integer];
            GET_ACTOR_PTR(D_800E69C0.unk3E[actor->actorVars.varA0.integer].ishort)->rot.y =
                D_80159118[actor->actorVars.varA0.integer];
            GET_ACTOR_PTR(D_800E69C0.unk3E[actor->actorVars.varA0.integer].ishort)->rot.z =
                D_80159120[actor->actorVars.varA0.integer];

            if ((&D_800F3940)[cdata.unk41]->unk30 == 1) {
                actor->status = 9999;
            }
            if ((&D_800F3940)[2]->unk10 == 1) {
                func_80022F48(D_800E69C0.unk3E[1].ishort, ++actor->actorVars.varAC.integer % 17);
            } else if ((&D_800F3940)[2]->unk14 == 1) {
                GET_ACTOR_PTR(idx)->actorVars.varB4.integer++;
                func_80022F48(D_800E69C0.unk3E[0].ishort, 0);
            }

            break;
        case 150:
            if (D_800F3920.unk0 == 0) {
                actor->status = 200;
            }
            break;
        case 200:
            if (D_800B6220[actor->actorVars.varAC.integer] == 0xFF) {
                actor->actorVars.varAC.integer++;
                actor->status = 250;
            } else if (D_800B6220[actor->actorVars.varAC.integer] != 0) {
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

            if (func_80012D40(0x12, actor->actorVars.varB0.integer, 0xF0) == 0) {
                actor->status = 200;
                actor->actorVars.varB0.integer++;
            }
            break;
        case 300:
            if (D_800B6234[D_800B6220[actor->actorVars.varAC.integer]]() == 0) {
                actor->status = 200;
                actor->actorVars.varAC.integer++;
            }
            break;
        case 9999:
            if (D_800F5FB0.unk0 == 3) {
                func_80023FCC(D_800E69C0.unk3E[0].ishort);
                func_80023FCC(D_800E69C0.unk3E[1].ishort);

                func_8000B120(2);

                D_800F3920.unk0 = 5;
                D_800F3920.unk2 = 1;

                D_800E69C0.unkA = 0x98;
                D_800F3950 = 0xF;

                cdata.unk42 = 0;

                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;

                cdata.unk44 = 0;

                func_80023FCC(idx);
            }
            break;
    }
}

static s32 __op_scene_0() {
    (void)"__op_scene_0\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800E69C0.unk3E[2].ishort = 0x78;
            D_800E69C0.unk3C.ishort = 10;
            break;
        case 10:
            if ((D_800E69C0.unk3E[2].ishort = D_800E69C0.unk3E[2].ishort - 1) < 0) {
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_1() {
    (void)"__op_scene_1\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            if ((GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z -= 1.2) <= -400.0) {
                func_80022F48(D_800E69C0.unk3E[1].ishort, 0);
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_2() {
    (void)"__op_scene_2\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            D_800F0548.unk0 -= 1.2;

            if (D_800F0548.unk0 <= 200.0) {
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_3() {
    (void)"__op_scene_3\n";

    switch (D_800E69C0.unk3C.ishort) {
        case 0:
            GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->rot.y = 0.0f;

            func_80022F48(D_800E69C0.unk3E[1].ishort, 1);
            D_800E69C0.unk3C.ishort = 10;

            break;
        case 10:
            if (-350.0 <= (GET_ACTOR_PTR(D_800E69C0.unk3E[1].ishort)->pos.z += 1.2)) {
                return 0;
            }
            break;
    }

    return 1;
}

static s32 __op_scene_4() {
    (void)"NOP...\n";

    return 0;
}
