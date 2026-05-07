#include "682B0.h"
#include "73660.h"
#include "23B20.h"


void func_800676B0(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 id;
    s32 pad;

    switch (GET_ACTOR_PTR(idx)->status) {
        case 0:
            if (func_80076FA0(0x2C)) {
                func_80023644(1, 0x2C, 480.0f, 630.0f, -1490.0f, 0.0f, 90.0f, 0.0f);
            }
            if ((cdata.unk50 & 1) != 1) {
                id = func_80023644(8, 0x69, -123.0f, -14.0f, -1333.0f, 0.0f, 180.0f, 0.0f);

                if (id != -1) {
                    GET_ACTOR_PTR(id)->actorVars.varA0.integer = 0;
                }
            }

            actor->status = 1;
            break;
        case 1:
            break;
    }
}

void func_800677C0(s16 idx) {
    static s32 D_800B56A0[] = {
        0x9880006D, 0xFFFFFDD8, 0xFFFFFF79, 0xFFFFF7EF, 0x00000000, 0x0000015E, 0x00000000, 0x00000000, 0x0000001E,
        0x0000003C, 0x00000008, 0x00000002, 0x00000005, 0x00100001, 0x00020303, 0x9880006D, 0xFFFFFE3D, 0xFFFFFFA1,
        0xFFFFF7F6, 0x00000000, 0x0000015E, 0x00000000, 0x00000000, 0x0000003C, 0x0000003C, 0x00000008, 0x00000002,
        0x00000005, 0x00100001, 0x00020303, 0x9880006D, 0xFFFFFEBE, 0xFFFFFFA1, 0xFFFFF802, 0x00000000, 0x0000015E,
        0x00000000, 0x00000000, 0x00000064, 0x0000003C, 0x00000008, 0x00000002, 0x00000005, 0x00100001, 0x00020303,
        0x9880006D, 0xFFFFFF06, 0xFFFFFF7E, 0xFFFFF80D, 0x00000000, 0x0000015E, 0x00000000, 0x00000000, 0x0000008C,
        0x0000003C, 0x00000008, 0x00000002, 0x00000005, 0x00100001, 0x00020303, 0xFFFFFFFF,
    };
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 varA0;
    s32 pad2;
    s32 unk38;

    switch (GET_ACTOR_PTR(idx)->status) {
        case 0:
            unk38 = cdata.unk38;
            
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varA4.integer = unk38;
            actor->actorVars.varA0.integer = unk38;
            actor->status = 1;
            break;
        case 1:
            break;
    }

    unk38 = cdata.unk38;
    
    actor->actorVars.varA4.integer = cdata.unk38;
    unk38 = GET_ACTOR_PTR(idx)->actorVars.varA4.integer;
    varA0 = GET_ACTOR_PTR(idx)->actorVars.varA0.integer;

    if(actor);
    
    if (varA0 != unk38) {
        if (actor->actorVars.varA0.integer == 7 && unk38 == 8 && actor->actorVars.varA8.integer <= 0) {
            func_80023468(D_800B56A0);
            actor->actorVars.varA8.integer = 300;
            unk38 = actor->actorVars.varA4.integer;
        }

        actor->actorVars.varA0.integer = unk38;
    }
    if (actor->actorVars.varA8.integer != 0) {
        actor->actorVars.varA8.integer--;
    }
}
