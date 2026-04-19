#include "4A610.h"
#include "global.h"
#include "23B20.h"
#include "73660.h"
#include "15F60.h"
#include "11F10.h"
#include "9320.h"
#include "57820.h"
#include "13940.h"
#include "386E0.h"
#include "1D870.h"
#include "3AA90.h"

#include "libc/math.h"
#include "common.h"

extern f32 D_80159170;
extern f32 D_80142BCC;
extern f32 D_8014DF8C;

void func_80049A10(s16 idx) {
    static D_800B5430_struct D_800B5430[] = {
        {
            0x022C,
            0x06EA,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0x00E5,
            0x06C3,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFEEB,
            0x05C5,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFD74,
            0x0422,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFC98,
            0x0258,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFADA,
            0xFFE8,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFA79,
            0xFD4D,
            0x0000,
            0x0000,
            6.0f,
            5.0f,
        },
        {
            0xFAC6,
            0xFA7A,
            0x0000,
            0x0000,
            6.0f,
            4.5f,
        },
        {
            0xFCDE,
            0xFAC7,
            0x0000,
            0x0000,
            10.0f,
            4.0f,
        },
        {
            0x004C,
            0xFB57,
            0x0000,
            0x0000,
            10.0f,
            3.5f,
        },
        {
            0x0212,
            0xFAEC,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x04B1,
            0xFB71,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x0733,
            0xFCBF,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x069B,
            0xFEBE,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x061A,
            0x0064,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x0416,
            0x01B4,
            0x0000,
            0x0000,
            10.0f,
            3.0f,
        },
        {
            0x0204,
            0x0070,
            0x0000,
            0x0000,
            8.0f,
            3.5f,
        },
        {
            0x01A3,
            0xFE5A,
            0x0002,
            0x0000,
            6.0f,
            4.0f,
        },
        {
            0x01D7,
            0xFCEF,
            0x0000,
            0x0000,
            6.0f,
            4.0f,
        },
        {
            0x02A7,
            0xF730,
            0x0000,
            0x0000,
            6.0f,
            3.5f,
        },
        {
            0x0409,
            0xF5F5,
            0x0000,
            0x0000,
            6.0f,
            3.5f,
        },
        {
            0x07A7,
            0xF618,
            0x0000,
            0x0000,
            6.0f,
            3.5f,
        },
        {
            0x09D8,
            0xF731,
            0x0000,
            0x0000,
            6.0f,
            3.0f,
        },
        {
            0x0B3D,
            0xF6EE,
            0x0000,
            0x0000,
            6.0f,
            3.0f,
        },
        {
            0x0CDA,
            0xF2EE,
            0x0000,
            0x0000,
            6.0f,
            3.0f,
        },
        {
            0x0D18,
            0xF327,
            0x0001,
            0x0000,
            6.0f,
            3.0f,
        },
        {
            0xFFFF,
            0xFFFF,
            0x0001,
            0x0000,
            6.0f,
            3.0f,
        },
    };
    Actor* actor;
    Actor* actor1;
    f32 v0;
    f32 v1;
    s16 id;
    s16 pad;

    actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    v0 = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    actor = GET_ACTOR_PTR(idx);

    v1 = func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));

    (void)" you'r time is %d clock!\n";

    switch (actor->status) {
        case 0:
            if (GET_ACTOR_PTR(idx)->actorVars.varA0.integer != 0) {
                actor->unk8 = 0x73F;
                actor->flags |= 0x40000;
                actor->scale.x = 1.5f;
                actor->scale.y = 1.5f;
                actor->scale.z = 1.5f;
            }

            actor->unk4E = 2;
            actor->unk6C = 0x15;
            func_80022F48(idx, 0);
            actor->status = 1;

            break;
        case 1:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            func_80016EB8(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, -10.0f, 0.0f);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varB4.fp = actor->pos.x;
                actor->actorVars.varB8.fp = actor->pos.z;

                switch (actor->actorVars.varA0.integer) {
                    case 0:
                        actor->status = 100;
                        break;
                    case 1:
                        actor->status = 200;
                        break;
                    case 2:
                        actor->status = 400;
                        break;
                    case 3:
                        actor->status = 450;
                        break;
                }
            }
            actor->pos.y = D_800F9910.unk10;
            break;
        case 100:
            func_80022F48(idx, 0);

            actor->actorVars.varA8.integer = (func_80011528(0) + 60) & 0x7F;
            actor->status = 101;
            break;
        case 101:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor->status = 110;
            }
            break;
        case 110:
            actor->actorVars.varAC.fp = ((func_80011528(0) & 0x200) + actor->actorVars.varB4.fp) - 256.0f;
            actor->actorVars.varB0.fp = ((func_80011528(0) & 0x200) + actor->actorVars.varB8.fp) - 256.0f;

            actor->actorVars.varA8.integer = 10;
            actor->status = 111;
            break;
        case 111:
            func_80022F48(idx, 1);
            func_800256CC(actor, actor->actorVars.varAC.fp, actor->actorVars.varB0.fp, 3.0f);

            if (actor->pos.y <= (&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) {
                actor->actorVars.varBC.fp = 10.0f;
                actor->actorVars.varC0.fp = 8.0f;
            } else {
                actor->actorVars.varBC.fp = 4.0f;
                actor->actorVars.varC0.fp = 4.0f;
            }

            func_80008E10(0x49, 2, idx);
            actor->status = 112;
            break;
        case 112:
            func_80024FC8(idx, actor->actorVars.varC0.fp, actor->actorVars.varBC.fp);

            actor->actorVars.varBC.fp -= D_80159170 * 0.5;
            actor->actorVars.varC4.fp = actor->pos.x;
            actor->actorVars.varC8.fp = actor->pos.z;

            func_80059760(actor);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varBC.fp = 0.0f;
            }
            if (D_800F9910.unk1 != 0 &&
                (actor->actorVars.varC0.fp * 0.3 <
                 actor->actorVars.varC0.fp - sqrtf(SQ(actor->pos.z - actor->actorVars.varC8.fp) + SQ(actor->pos.x - actor->actorVars.varC4.fp)))) {
                actor->rot.y += 180.0f;
                NORM_ANGLE(actor->rot.y);

                actor->actorVars.varA8.integer = 1;
                actor->actorVars.varC0.fp = 4.0f;
                actor->actorVars.varBC.fp = 6.0f;
            } else if (D_800F9910.unk0 != 0) {
                if (func_80024EA4(idx, actor->actorVars.varAC.fp, actor->pos.y, actor->actorVars.varB0.fp) < 100.0f ||
                    --actor->actorVars.varA8.integer <= 0) {
                    actor->status = 113;
                } else if (v0 < 250.0f) {
                    actor->status = 120;
                } else {
                    actor->status = 111;
                }
            }
            break;
        case 113:
            actor->actorVars.varBC.fp -= D_80159170 * 0.5;
            actor->actorVars.varC0.fp *= 0.95;

            func_80024FC8(idx, actor->actorVars.varC0.fp, actor->actorVars.varBC.fp);
            func_80059760(actor);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varBC.fp = 0.0f;
            }
            if (actor->actorVars.varC0.fp < 0.1 && D_800F9910.unk0 != 0) {
                actor->status = 100;
            }
            break;
        case 120:
            actor->actorVars.varBC.fp -= D_80159170 * 0.5;
            actor->actorVars.varC0.fp *= 0.95;

            func_80024FC8(idx, actor->actorVars.varC0.fp, actor->actorVars.varBC.fp);
            func_80059760(actor);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varBC.fp = 0.0f;
            }
            if (actor->actorVars.varC0.fp < 0.1 && D_800F9910.unk0 != 0) {
                actor->status = 121;
            }
            break;
        case 121:
            func_80025454(actor, actor1, 16.0f);

            if (v1 < 5.0f && v1 > -5.0f) {
                actor->actorVars.varA8.integer = 10;
                actor->status = 122;
            }
            break;
        case 122:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor->actorVars.varA8.integer = 1;
                actor->status = 112;
                actor->actorVars.varBC.fp = 4.0f;
                actor->actorVars.varC0.fp = 10.0f;
            }
            break;
        case 200:
            func_80022F48(idx, 0);

            actor->actorVars.varD0.integer = 0;
            actor->actorVars.varCC.integer = 0;

            if (v0 < 200.0f) {
                D_800E6B20.unk20 = 0x4B;
                D_800E6B20.unk22 = 0xB7;

                actor->status = 201;
            }
            break;
        case 201:
            if (func_80012D40(4, 3, 1U) == 0) {
                actor1->flags &= ~0x4000;
                actor->status = 300;
            }
            break;
        case 300:
            func_80022F48(idx, 0);
            actor->status = 301;
            break;
        case 301:
            func_80025454(actor, actor1, 20.0f);

            if (v0 < 150.0f) {
                actor->actorVars.varAC.fp = D_800B5430[actor->actorVars.varCC.integer].unk0;
                actor->actorVars.varB0.fp = D_800B5430[actor->actorVars.varCC.integer].unk2;

                if (D_800B5430[actor->actorVars.varCC.integer].unk4 == 0) {
                    actor->actorVars.varCC.integer++;
                    actor->status = 303;

                } else {
                    actor->actorVars.varCC.integer++;

                    if (actor->actorVars.varAC.fp == -1.0f && actor->actorVars.varB0.fp == -1.0f) {
                        D_800E6B20.unk20 = 0x4B;
                        D_800E6B20.unk22 = 0xB7;

                        actor->status = 350;
                        return;
                    }
                    actor->actorVars.varA8.integer = 30;
                    actor->status = 302;
                }
            }
            break;
        case 302:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor->status = 303;
            }

            func_800256CC(actor, actor->actorVars.varAC.fp, actor->actorVars.varB0.fp, 20.0f);
            break;
        case 303:
            func_80022F48(idx, 1);
            func_800256CC(actor, actor->actorVars.varAC.fp, actor->actorVars.varB0.fp, 1.0f);

            if (D_800B5430[actor->actorVars.varCC.integer - 1].unk4 == 2) {
                GET_ACTOR_PTR(idx)->actorVars.varC0.fp = 4.0f;
                GET_ACTOR_PTR(idx)->actorVars.varBC.fp = 25.0f;
            } else {
                actor->actorVars.varBC.fp = D_800B5430[actor->actorVars.varCC.integer].unk8;
                actor->actorVars.varC0.fp = D_800B5430[actor->actorVars.varCC.integer].unkC;
            }

            func_80008E10(0x49, 2, idx);
            GET_ACTOR_PTR(idx)->status = 304;
            break;
        case 304:
            func_80024FC8(idx, actor->actorVars.varC0.fp, actor->actorVars.varBC.fp);

            actor->actorVars.varBC.fp -= D_80159170;
            actor->actorVars.varC4.fp = actor->pos.x;
            actor->actorVars.varC8.fp = actor->pos.z;

            func_80059760(actor);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varBC.fp = 0.0f;
            }
            if (D_800F9910.unk0 != 0) {
                if (func_80024EA4(idx, actor->actorVars.varAC.fp, actor->pos.y, actor->actorVars.varB0.fp) < 150.0f) {
                    if (D_800B5430[actor->actorVars.varCC.integer - 1].unk4 == 1) {
                        actor->actorVars.varD0.integer = 0, actor->status = 305;
                    } else {
                        actor->actorVars.varAC.fp = D_800B5430[actor->actorVars.varCC.integer].unk0;
                        actor->actorVars.varB0.fp = D_800B5430[actor->actorVars.varCC.integer].unk2;
                        actor->actorVars.varCC.integer++;
                        actor->status = 303;
                    }
                } else {
                    actor->status = 303;
                }
            }
            break;
        case 305:
            actor->actorVars.varBC.fp -= D_80159170;
            actor->actorVars.varC0.fp *= 0.95;

            func_80024FC8(idx, actor->actorVars.varC0.fp, actor->actorVars.varBC.fp);
            func_80059760(actor);

            if (D_800F9910.unk0 != 0) {
                actor->actorVars.varBC.fp = 0.0f;
            }
            if (actor->actorVars.varC0.fp < 0.1 && D_800F9910.unk0 != 0) {
                actor->status = 300;
            }
            break;
        case 350:
            if (func_80012D40(4, 4, 1U) == 0) {
                actor->flags |= 0x10;
                actor1->flags &= ~0x4000;

                actor->status = 351;
            }
            break;
        case 351:
            id = func_80023498(1, 0x29, 3712.0f, 450.0f, -3680.0f, 0.0f, 0.0f, 0.0f);

            if (id != -1) {
                actor1->flags |= 0x4000;
                actor->actorVars.varD4.integer = id;
                D_800F05B8 = 1;

                actor->actorVars.varA8.integer = 240;
                func_80025F18(3535.0f, 632.0f, -3674.0f, 3716.0f, 526.0f, -3677.0f, 240.0f);

                D_80142BCC = 100.0f;
                D_8014DF8C = 100.0f;

                actor->status = 352;
            }
            break;
        case 352:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor->status = 353;

                actor->actorVars.varBC.fp = 5.0f;
            }

            func_80026380();
            break;
        case 353:
            if (GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y < 550.0f && actor->actorVars.varBC.fp < 0.0f) {
                actor->actorVars.varA8.integer = 90;
                actor->status = 354;
            }

            actor->actorVars.varBC.fp -= D_80159170 * 0.125;
            GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y += actor->actorVars.varBC.fp;
            func_80022528(1, 2, GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.x, GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y,
                          GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.z, (f32)(func_80011528(0) & 0x3F),
                          (f32)(func_80011528(0) & 0xFF), (f32)(func_80011528(0) & 0x1F));
            break;
        case 354:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor1->flags &= ~0x4000;
                D_800F05B8 = 0;
                func_8002263C(1);
                D_80142BCC = 255.0f;
                D_8014DF8C = 255.0f;
                actor->status = 355;
            }
            break;
        case 355:
            func_80025454(actor, actor1, 32.0f);
            break;
        case 400:
            actor->actorVars.varA8.integer = 0;
            actor->flags |= 0x10;
            GET_ACTOR_PTR(idx)->status = 401;
            break;
        case 401:
            if (v0 < 200.0f) {
                D_800E6B20.unk20 = 0x4B;
                D_800E6B20.unk22 = 0xB7;
                GET_ACTOR_PTR(idx)->status = 402;
            }

            func_80025454(actor, actor1, 32.0f);
            break;
        case 402:
            if (func_80012D40(4, actor->actorVars.varA8.integer + 5, 1U) == 0) {
                actor1->flags &= ~0x4000;
                actor->actorVars.varA8.integer++;

                if (actor->actorVars.varA8.integer >= 6) {
                    GET_ACTOR_PTR(idx)->status = 404;
                } else {
                    GET_ACTOR_PTR(idx)->status = 403;
                }
            }
            break;
        case 403:
            if (v0 > 250.0f) {
                GET_ACTOR_PTR(idx)->status = 401;
            }

            func_80025454(actor, actor1, 32.0f);
            break;
        case 404:
            id = func_80023498(8, 0x81, 3372.0f, 451.0f, -3716.0f, 0.0f, 345.0f, 0.0f);

            if (id != -1) {
                GET_ACTOR_PTR(id)->unk68 = 0x17;
                (&D_801414A8)[GET_ACTOR_PTR(id)->unk38]->unk30 = 90.0f;

                func_80022F20(id, NULL);

                actor1->flags |= 0x4000;
                actor->actorVars.varD4.integer = id;

                D_800F05B8 = 1;
                actor->actorVars.varA8.integer = 240;

                func_80025F18(3494.0f, 633.0f, -3656.0f, 3372.0f, 501.0f, -3716.0f, 240.0f);

                D_80142BCC = 100.0f;
                D_8014DF8C = 100.0f;

                actor->status = 405;
            }
            break;
        case 405:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                actor->status = 406;
                actor->actorVars.varBC.fp = 5.0f;
            }

            func_80026380();
            break;
        case 406:
            if (GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y < 530.0f && actor->actorVars.varBC.fp < 0.0f) {
                actor->actorVars.varA8.integer = 90;
                actor->status = 407;
            }

            actor->actorVars.varBC.fp -= D_80159170 * 0.125;

            GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y += actor->actorVars.varBC.fp;
            func_80022528(1, 2, GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.x, GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.y,
                          GET_ACTOR_PTR(actor->actorVars.varD4.integer)->pos.z, (f32)(func_80011528(0) & 0xFF),
                          (f32)(func_80011528(0) & 0xFF), (f32)(func_80011528(0) & 0x1F));

            break;
        case 407:
            actor->actorVars.varA8.integer--;

            if (actor->actorVars.varA8.integer <= 0) {
                func_80022F20(actor->actorVars.varD4.integer, func_80039254);
                actor1->flags &= ~0x4000;
                D_800F05B8 = 0;
                func_8002263C(1);
                D_80142BCC = 255.0f;
                D_8014DF8C = 255.0f;
                actor->status = 453;
            }
            break;
        case 450:
            actor->actorVars.varA8.integer = 0;
            GET_ACTOR_PTR(idx)->status = 451;
            actor->flags |= 0x10;
            break;
        case 451:
            if (v0 < 200.0f) {
                D_800E6B20.unk20 = 0x4B;
                D_800E6B20.unk22 = 0xB7;
                GET_ACTOR_PTR(idx)->status = 452;
            }

            func_80025454(actor, actor1, 32.0f);
            break;
        case 452:
            if (func_80012D40(4, actor->actorVars.varA8.integer + 11, 1U) == 0) {
                actor1->flags &= ~0x4000;

                actor->actorVars.varA8.integer++;

                if (actor->actorVars.varA8.integer >= 2) {
                    actor->actorVars.varA8.integer = 0;
                }

                actor->status = 453;
            }
            break;
        case 453:
            if (v0 > 250.0f) {
                actor->status = 451;
            }

            func_80025454(actor, actor1, 32.0f);
            break;
    }
    actor->actorVars.varD0.integer++;

    if (actor->actorVars.varA0.integer != 0) {
        func_80039FDC(idx, 60.0f);
    }
}

s32 D_800B55E0[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xB8000000, 0x00000000, 0xB8000000, 0x00000000, 0xB8000000,
    0x00000000, 0xB8000000, 0x00000000, 0xB8000000, 0x00000000, 0xB8000000, 0x00000000, 0xB8000000, 0x00000000,
};

void func_8004AF68(s16 idx) {
    Actor* actor;
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 v0;

    v0 = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    actor = GET_ACTOR_PTR(idx);

    if (actor->unk38 != 0xFFFF) {
        switch (actor->status) {
            case 0:
                if (actor->actorVars.varA0.integer == 1) {
                    actor->unk74 = 0xA;
                    actor->scale.x = 3.0f;
                    actor->scale.y = 3.0f;
                    actor->scale.z = 3.0f;
                }

                actor->unk8 = 0x53F;
                actor->actorVars.varA4.integer = 10;

                D_801414A0[actor->unk38 + 3]->unk30 = -90.0f;
                D_801414A0[actor->unk38 + 4]->unk30 = -90.0f;

                actor->status = 10;
                break;
            case 10:
                if (v0 < 100.0f) {
                    actor->actorVars.varA4.integer = 60;
                    actor->actorVars.varA8.fp = 3.0f;

                    func_80008E10(0x55, 2, idx);

                    D_801414A0[actor->unk38 + 3]->unk30 = 0.0f;
                    D_801414A0[actor->unk38 + 4]->unk30 = 0.0f;

                    actor->status = 11;
                }
                break;
            case 11:
                actor->actorVars.varA4.integer--;

                if (actor->actorVars.varA4.integer <= 0) {
                    actor->status = 12;
                }

                func_80025454(actor, actor1, 24.0f);
                break;
            case 12:
                func_80024FC8(idx, 4.0f, actor->actorVars.varA8.fp);
                actor->actorVars.varA8.fp -= D_80159170 * 0.25;
                func_80059760(actor);

                D_801414A0[actor->unk38 + 2]->unk30 = -60.0f;

                actor->unk8 = 1;

                if (D_800F9910.unk0 != 0) {
                    func_80008E10(0x17, 2, idx);
                    D_801414A0[actor->unk38 + 2]->unk30 = 0.0f;

                    actor->actorVars.varA4.integer = 60;
                    actor->status = 13;
                }
                break;
            case 13:
                actor->actorVars.varA4.integer--;

                if (actor->actorVars.varA4.integer <= 0) {
                    D_801414A0[actor->unk38 + 3]->unk30 = -90.0f;
                    D_801414A0[actor->unk38 + 4]->unk30 = -90.0f;
                    D_801414A0[actor->unk38 + 2]->unk30 = 0.0f;

                    actor->unk8 = 0x53F;
                    actor->status = 10;
                }
                break;
        }
    }
}
