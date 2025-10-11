#include "6FA0.h"
#include "6E50.h"
#include "global.h"

void func_800063A0(s16 playerIdx){
    Player* player = &players[playerIdx];
    s32 old = player->unk4;

    switch(old){ 
        case 0:  
          D_800F05B8 = 1;
          
          D_800F0548.fovy = 0.0f;
          D_800F0548.aspect = D_800C0D70;
          D_800F0548.near = D_800C0D74;
          D_800F0548.far = 0.0f; 
          D_800F0548.scale = -2800.0f;
          D_800F0548.unk14 = -350.0f;
            
          GET_PLAYER_PTR(playerIdx)->unk4 = 1;
        case 1:
            if (!func_80012D40(12, 0, 1)) {
                D_800F05B8 = 0;
                func_80023FCC(playerIdx);
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

void func_800064F0(s16 playerIdx) {
    Player* chosenPlayer = GET_PLAYER_PTR(playerIdx);
    Player* playerA0 = GET_PLAYER_PTR(chosenPlayer->unkA0.integer);
    Player* playerA4 = GET_PLAYER_PTR(chosenPlayer->unkA4.integer);
    
    if (chosenPlayer->unk4 == 0) {
        D_800F05C8 = chosenPlayer->unkA8.fp + playerA0->pos.x;
        D_800F05CC = chosenPlayer->unkAC.fp + playerA0->pos.y;
        D_800F05D0 = chosenPlayer->unkB0.fp + playerA0->pos.z;
        D_800F05D4 = chosenPlayer->unkB4.fp + playerA4->pos.x;
        D_800F05D8 = chosenPlayer->unkB8.fp + playerA4->pos.y;
        D_800F05DC = chosenPlayer->unkBC.fp + playerA4->pos.z;
    }
}
