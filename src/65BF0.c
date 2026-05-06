#include "65BF0.h"
#include "7FC0.h"
#include "23B20.h"
#include "segments.h"

void func_80064FF0(s16 idx){
    s32 pad;
    s32 pad2;
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;

    switch(actor->status){
        case 2:
            break;
        case 0:
            func_800073C0(0x10, 0);
            ROMCOPY(D_3C0550, D_8020C820);

            actor->actorVars.varA0.integer = 1;
            actor->actorVars.varA8.integer = -1;
            actor->status = 1;
            break;
        case 1:
            id = func_80023644(2, 0x1BE, -8.007941f, -49.0f, 488.091156f, 0.0f, 180.0f, 0.0f);
            actor->actorVars.varA8.integer = id;

            if(id != -1){
                actor->status = 2; 
            }
            break;
    }

    switch(actor->actorVars.varA0.integer){
        case 0:
            break;
        case 1:
            break;
    }
}

