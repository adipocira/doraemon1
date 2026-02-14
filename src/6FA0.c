#include "6FA0.h"
#include "6E50.h"
#include "23B20.h"
#include "actor.h"

void func_800063A0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 old = actor->status;

    switch(old){ 
        case 0:  
          D_800F05B8 = 1;
          
          D_800F0548.unk0 = 0.0f;
          D_800F0548.unk4 = D_800C0D70;
          D_800F0548.unk8 = D_800C0D74;
          D_800F0548.unkC = 0.0f; 
          D_800F0548.unk10 = -2800.0f;
          D_800F0548.unk14 = -350.0f;
            
          GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            if (!func_80012D40(12, 0, 1)) {
                D_800F05B8 = 0;
                func_80023FCC(idx);
            }
            else if (D_800F0548.unk10 < 500.0f) {
                D_800F0548.unk10 += 6.0f;
                if (D_800C0D78 < D_800F0548.unk10) {
                    D_800F0548.unk8 += 2.0f;
                    D_800F0548.unk10 += 2.0f;
                }
            }
            
            break;
    }
}

void func_800064F0(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 =  GET_ACTOR_PTR(actor->actorVars.varA0.integer);
    Actor* actor2 = GET_ACTOR_PTR(actor->actorVars.varA4.integer);
    
    if (actor->status == 0) {
        D_800F05C8 = actor->actorVars.varA8.fp + actor1->pos.x;
        D_800F05CC = actor->actorVars.varAC.fp + actor1->pos.y;
        D_800F05D0 = actor->actorVars.varB0.fp + actor1->pos.z;

        D_800F05D4 = actor->actorVars.varB4.fp + actor2->pos.x;
        D_800F05D8 = actor->actorVars.varB8.fp + actor2->pos.y;
        D_800F05DC = actor->actorVars.varBC.fp + actor2->pos.z;
    }
}
