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
          
          D_800F0548.fovy = 0.0f;
          D_800F0548.aspect = D_800C0D70;
          D_800F0548.near = D_800C0D74;
          D_800F0548.far = 0.0f; 
          D_800F0548.scale = -2800.0f;
          D_800F0548.unk14 = -350.0f;
            
          GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            if (!func_80012D40(12, 0, 1)) {
                D_800F05B8 = 0;
                func_80023FCC(idx);
            }
            else if (D_800F0548.scale < 500.0f) {
                D_800F0548.scale += 6.0f;
                if (D_800C0D78 < D_800F0548.scale) {
                    D_800F0548.near += 2.0f;
                    D_800F0548.scale += 2.0f;
                }
            }
            
            break;
    }
}

void func_800064F0(s16 idx) {
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 =  GET_ACTOR_PTR(actor->unkA0.integer);
    Actor* actor2 = GET_ACTOR_PTR(actor->unkA4.integer);
    
    if (actor->status == 0) {
        D_800F05C8 = actor->unkA8.fp + actor1->pos.x;
        D_800F05CC = actor->unkAC.fp + actor1->pos.y;
        D_800F05D0 = actor->unkB0.fp + actor1->pos.z;

        D_800F05D4 = actor->unkB4.fp + actor2->pos.x;
        D_800F05D8 = actor->unkB8.fp + actor2->pos.y;
        D_800F05DC = actor->unkBC.fp + actor2->pos.z;
    }
}
