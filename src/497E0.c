#include "497E0.h"
#include "4D980.h"
#include "23B20.h"
#include "73660.h"
#include "9320.h"
#include "11F10.h"


#include "global.h"
#include "libc/math.h"

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x24];
}D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1]; 

extern u8 D_800F38E1;
extern f32 D_80159170;

typedef struct D_800F9910_struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    
    /* todo more*/
}D_800F9910_struct;

extern D_800F9910_struct D_800F9910;

void func_80048BE0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad[8];

    func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);

    func_80074E68(player->unk28.y, func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0));

    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x1A;
            func_80022F48(idx, 3);
            player->unk4 = 1;
            break;
        case 1:
            break;
    }
}

void func_80048CD4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    s32 pad2;
    s32 pad5;
    s32 pad;
    s32 pad3;
    s16 pad4;
    s16 temp2;
    s16 temp3;

    func_80074E68(player->unk28.y, func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0));

    switch(player->unk4){
        case 0:
            player->unkA4.integer = 0;
            player->unkA0.integer = 0x64;
            player->unk8 = 0x53F;
            player->unk4E = 2;
            player->unk6C = 0x1D;
            func_80022F48(idx, 3);
            player->unk4 = 1;  
            break;
        case 1:
            if(temp < 100.0f){
                player->unkA0.integer = 0x3C;
                player->unk4 = 2;
            }
            break;
        default:
            
            break;
        case 2:
            player->unkA0.integer--;

            if(player->unkA0.integer < 0){
                player->unk8 = 0;

                if(player->unkA4.integer >= 3){
                    player->unkA4.integer = 0;
                }
                
                func_80022F48(idx, temp3 = player->unkA4.integer++); 
                player->unk4 = 3;
                player->unkA0.integer = 0x1E;
            }
            func_80025454(player, p, 12.0f);
            break;
        case 3:
            player->unkA0.integer--;

            if(player->unkA0.integer < 0){
                func_80008E10(0x17, 2, idx);
                player->unkA0.integer = 0x3C;
                func_80022F48(idx, 3);
                player->unk4 = 4;
            }
            if(player->unkA0.integer == 0x1C){
                temp2 = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, player->unk28.y, 0.0f);
                
                if(temp2 != -1){
                    func_800242F0(temp2, 0, -1);
                    func_80022F20(temp2, func_8004EAC4);
                    func_80025638(GET_PLAYER_PTR(temp2), player, player->unk28.y, 40.0f,10.0f);
                }
            }
            break;
        case 4:
            player->unk8 = 0x53F;
            player->unkA0.integer--;

            if(player->unkA0.integer <= 0){
                player->unk4 = 1;
            }
            break;
    }
    
}

void func_80048FB4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x27;
            
            func_80022F48(idx, 2);
            
            player->unkA4.fp = player->pos.x;
            player->unkA8.fp = player->pos.z;

            if(player->unkA0.integer != 0){
                player->unk74 = 0x258;
                player->unk4 = 0x1F4;
                
                player->unk90.x = 8.0f;
                player->unk90.y = 8.0f;
                player->unk90.z = 8.0f;
            }
            else{
                player->unk4 = 0x32;
            }
            break;
        case 0x32:
            func_80022F48(idx, 2);
            player->unkAC.integer = 0x3C;
            player->unk4 = 0x33;
            break;
        case 0x33:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                player->unk4 = 0x64;
            }

            player->unk5C = player->unkB8.fp -= D_80159170 * 0.25;

            func_80059760(player);

            if(D_800F9910.unk0 != 0){
                player->unkB8.fp = 0.0f;
            }
            break;
        case 0x64:
            func_80022F48(idx, 4);
            player->unkB0.fp = func_80011528(0) % 400U + player->unkA4.fp - 200.0f;
            player->unkB4.fp = func_80011528(0) % 400U + player->unkA8.fp - 200.0f;

            player->unkAC.integer = 0x3C;
            player->unk4 = 0x65;
            
            break;

        case 0x65:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                player->unkAC.integer = 0x78;
                player->unk4 = 0x66;
                player->unkBC.fp = 0.0f;
            }
            func_800256CC(player, player->unkB0.fp, player->unkB4.fp, 20.0f);
            break;
        case 0x66:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                player->unk4 = 0x67;
            }

            if(func_80024EA4(idx, player->unkB0.fp, player->pos.y, player->unkB4.fp) < 30.0f){
                func_80022F48(idx, 0);
                player->unkAC.integer = 0x3C;
                player->unk4 = 0x67;
            }

            func_800256CC(player, player->unkB0.fp, player->unkB4.fp, 20.0f);

            if(player->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(player->unkBC.fp < 1.0f){
                    player->unkBC.fp += 0.025;
                }
                else{
                    player->unkBC.fp = 1.0f;
                }
            }
            else{
                if(player->unkBC.fp < 1.5){
                    player->unkBC.fp += 0.05;
                }
                else{
                    player->unkBC.fp = 1.5f;
                }
            }

            player->unkB8.fp -= D_80159170 * 0.25;

            
            if(player->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                player->unkB8.fp *= 0.95;
            }

            func_80024FC8(idx, player->unkBC.fp, player->unkB8.fp);

            player->unkC0.fp = player->pos.x;
            player->unkC4.fp = player->pos.z;

            func_80059760(player); 

            if(D_800F9910.unk0 != 0){
                player->unkB8.fp = 0.0f;
            }

            if(player->unkB8.fp <= 3.0f && player->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                if(player->unkBC.fp * 0.3 < player->unkBC.fp - sqrtf(SQ(player->pos.z - player->unkC4.fp) + SQ(player->pos.x - player->unkC0.fp))){
                    func_80008E10(0x45, 2, idx);
                    player->unkB8.fp = 10.0f;
                }    
            }
            break;
        case 0x67:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                func_80022F48(idx, 1);
                player->unkAC.integer = 0x26;
                player->unk4 = 0x96;
                player->unk58 = 0.0f;
                player->unk60 = 0.0f;
            }

            if(player->unkAC.integer < 0x28){
                player->unk58 *= 0.95;
                player->unk60 *= 0.95;
            }

            player->unkB8.fp -= D_80159170 * 0.25;
            
            if(player->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                player->unkB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < player->unkB8.fp){
                    player->unkB8.fp = 0.0f;
                }
            }

            player->unk5C = player->unkB8.fp;

            func_80059760(player);
            
            if(D_800F9910.unk0 != 0){
                player->unkB8.fp = 0.0f;
            }
            
            break;

        case 0x96:
            GET_PLAYER_PTR(idx)->unkAC.integer--;
            
            if(player->unkAC.integer <= 0){
                player->unk4 = 0x32;    
            }
            
            player->unkB8.fp -= D_80159170 * 0.25;
            
            if(player->pos.y + 15.0f < ((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f)){
                player->unkB8.fp *= 0.95;
                
                if(-D_80159170 * 0.25 < player->unkB8.fp){
                    player->unkB8.fp = 0.0f;
                }
            }
            player->unk5C = player->unkB8.fp;

            func_80059760(player);
            
            if(D_800F9910.unk0 != 0){
                player->unkB8.fp = 0.0f;
            }
            break;

        case 0x1F4:
            player->unkC8.integer = 0;
            player->unkDC.fp = 1494.0f;
            player->unkE0.fp = -1845.0f;
            
            player->unk4 = 0x1F5;
            player->unkD4.fp = player->pos.x;
            player->unkD8.fp = player->pos.z;
            break;
        case 0x1F5:
            func_80022F48(idx, 3);

            switch(player->unkC8.integer){
                case 0:
                    player->unkCC.fp = player->unkD4.fp;
                    player->unkD0.fp = player->unkD8.fp;
                    break;
                case 1:
                    player->unkCC.fp = player->unkDC.fp;
                    player->unkD0.fp = player->unkE0.fp;
                    break;
            }

            player->unkAC.integer = 0xC8;
            player->unk4 = 0x1F6;
            
            break;
        case 0x1F6:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                player->unk4 = 0x1F7;
                player->unkB8.fp = 0.0f;
            }

            func_800256CC(player, player->unkCC.fp, player->unkD0.fp, 64.0f);
            break;
        case 0x1F7:
            if(player->unkB8.fp < 3.0f){
                player->unkB8.fp += 0.01;
            }

            if(func_80024EA4(idx, player->unkCC.fp, player->pos.y, player->unkD0.fp) < 50.0f){
                player->unk4 = 0x1F8;
            }

            func_800256CC(player, player->unkCC.fp, player->unkD0.fp, 64.0f);
            func_80024FC8(idx, player->unkB8.fp, -1.0f);
            func_80059760(player);
            break;
        case 0x1F8:
            if(player->unk58 < 0.1 && player->unk60 < 0.1){
                player->unkC8.integer = 1 - player->unkC8.integer;
                player->unkAC.integer = 0x78;
                player->unk4 = 0x1F9;
            }

            player->unk58 *= 0.98;
            player->unk60 *= 0.98;
            
            break;
        case 0x1F9:
            GET_PLAYER_PTR(idx)->unkAC.integer--;

            if(player->unkAC.integer <= 0){
                player->unk4 = 0x1F5;
            }
            break;
    }
    
}
