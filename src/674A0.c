#include "674A0.h"
#include "actor.h"
#include "23B20.h"
#include "73660.h"

void func_800668A0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s32 id;
    
    switch(actor->status){
        case 0:
            if(func_80076FA0(0x2A)){
                func_80023644(1, 0x2A, 1573.0f, 430.0f, -476.0f, 0.0f, 90.0f, 0.0f);
            }

            id = func_80023644(8, 0x62, 273.0f, 51.0f, 2657.0f, 0.0f, 225.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 5;
            }
            
            actor->status = 1;
            break;
        case 1:
            break;
    }
}

