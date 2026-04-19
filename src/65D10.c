#include "65D10.h"
#include "actor.h"
#include "23B20.h"
#include "global.h"

#include "57820.h"
#include "70DF0.h"

extern u8 D_801E3CEC[];

void func_80065110(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;
    
    switch(actor->status){
        case 0:
            id = func_80023498(6, 0x1A1, 903.0f, 101.0f, -249.0f, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                func_80022F20(id, func_80064BC8);
            }
            if(D_800E69C0.unk8 == 0x99){
                func_80023468(D_801E3CEC);
                func_80022F20(func_80023644(8, 0x1E2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f), func_800701F0);
            }

            actor->status = 1;
            break;
        case 1:
            break;
    }
}
