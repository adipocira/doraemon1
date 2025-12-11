#include "3DD30.h"

#include "23B20.h"
#include "11F10.h"
#include "9320.h"
#include "15F60.h"
#include "73660.h"
#include "4D980.h"

#include "global.h"
#include "libc/math.h"

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_801414A0_ptr_struct{
    u8 unk0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
}D_801414A0_ptr_struct; 

typedef struct D_801414A0_struct{
    u8 unk0[0x8];
    void* unk8;
    void* unkC;
    void* unk10;
}D_801414A0_struct;

extern D_801414A0_ptr_struct* D_801414A0[];

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

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x6];
    s16 unk8;
    u8 unkA[0x3];
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

extern u8 D_800F38E1;

void func_8003D130(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);  
    s32 temp;
    s32 temp2;
    f32 temp1;

    if(player->unk38 != 0xFFFF){
        switch(player->unk4){
            case 0:
                if(player->unkA0.fp < 1.0f){
                    player->unkA0.fp = 400.0f;
                }

                player->unkB4.integer = 4;
                player->unkBC.integer = 4;
                player->unk4E = 2;

                player->unkA4.fp = player->pos.x;
                player->unkA8.fp = player->pos.y;
                player->unkAC.fp = player->pos.z;
                player->pos.y -= 30.0f;
                player->unk6C = 15;
                
                func_80022F48(idx, 0);
                player->unk4 = 1;
                break;
            case 1:
                if(func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0) < player->unkA0.fp * 4.0f){
                    player->unk4 = 2;
                    player->unkB0.integer = func_80011528(0) % 20U;
                }
                break;
            case 2:
                player->unkB0.integer--;

                if(player->unkB0.integer <= 0){
                    player->unk4 = 3;

                    temp = func_80011528(0);
                    player->pos.x = (player->unkA4.fp + (temp % (u32)(s32)(player->unkA0.fp * 2))) - player->unkA0.fp;
                    temp2 = func_80011528(0);
                    player->pos.z = (player->unkAC.fp + (temp2 % (u32)(s32)(player->unkA0.fp * 2))) - player->unkA0.fp;
                    player->pos.y = player->unkA8.fp;

                    player->unkB8.fp = func_800253B0(idx,  D_80159178->unk48[D_800F38E1].unk0);
                    player->unkC8.integer = 0;
                    player->unk28.x = 0.0f;
                }
                break;
            case 3:
                if(player->unkC8.integer <= 0){
                    func_80008E10(0x43, 3, idx);
                    player->unkC8.integer = 0xA;
                }
                else{
                    player->unkC8.integer--;
                }

                player->unkBC.integer--;
                player->unk28.y = player->unkB4.integer + player->unkB8.fp;

                if(player->unkBC.integer <= 0){
                    player->unkB4.integer = -player->unkB4.integer;
                    player->unkBC.integer = 4;
                }

                NORM_ANGLE(player->unk28.y);

                player->pos.y += 0.2;

                func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y + 9.0f, player->pos.z, -50.0f);

                if(D_800F9910.unk1 != 0){
                    player->pos.y = D_800F9910.unk10 - 9.0f;
                    player->unk4 = 4;
                    func_80008E10(0x45, 2, idx);
                    player->unkCC.integer = 0;
                    player->unkC0.fp = 5.0f;
                    func_80022F48(idx, 3);
                }
                break;
            case 4:
                player->unkCC.integer++;

                if(player->unkCC.integer >= 0x29){
                    if(player->unkCC.integer < 0x36){
                        player->pos.y += 0.15;
                    }
                    else{
                        func_80024FC8(idx, 2.0f, player->unkC0.fp);
                        player->unkC0.fp -= 0.2;
                        D_801414A0[player->unk38]->unk30 += 12.0f;
                        func_80016EB8(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
                        
                        if (D_800F9910.unk0 != 0) {
                            player->unk4 = 5;
                            player->unkB0.integer = 0x3C;
                            D_801414A0[player->unk38]->unk30 += 12.0f;
                        }
                        player->pos.x = D_800F9910.unkC;
                        player->pos.y = D_800F9910.unk10;
                        player->pos.z = D_800F9910.unk14;
                    }
                }
                break;
            case 5:
                player->unkBC.integer--;

                if(player->unkBC.integer <= 0){
                    player->unkB4.integer = -player->unkB4.integer;
                    player->unkBC.integer = 4;
                }

                NORM_ANGLE(player->unk28.y);
                
                player->unkB0.integer--;

                if(player->unkB0.integer <= 0){
                    player->unk4 = 6;
                    player->unkB0.integer = func_80011528(0) % 150U + 0x96;
                    player->unkC4.fp = 0.0f;
                    func_80022F48(idx, 2);
                }
                break;
            case 6:
                temp1 = func_80025C48(p->pos.z - player->pos.z, p->pos.x - player->pos.x);

                player->unk28.y += func_80074E68(player->unk28.y, temp1) / 90.0f;
                
                NORM_ANGLE(player->unk28.y);
                
                if(player->unkC4.fp < 1.0f){
                    player->unkC4.fp += 0.025;
                }

                func_80024FC8(idx, player->unkC4.fp, -1.0f);
                
                func_80016EB8(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);

                if(player->pos.x + player->unk58 < (player->unkA0.fp + player->unkA4.fp) && (player->unkA4.fp - player->unkA0.fp) < player->pos.x + player->unk58){
                    if(player->pos.z + player->unk60 < (player->unkA0.fp + player->unkAC.fp) && (player->unkAC.fp - player->unkA0.fp) < player->pos.z + player->unk60){
                        player->pos.x = D_800F9910.unkC;
                        player->pos.y = D_800F9910.unk10;
                        player->pos.z = D_800F9910.unk14;                    
                    }

                }
                
                player->unkB0.integer--;
                
                if(player->unkB0.integer <= 0){
                    player->unk4 = 7;
                    player->unkB0.integer = 0x78;
                    player->unkB8.fp = player->unk28.y;
                    func_80022F48(idx, 1);
                }
                
                break;
            case 7:
                player->unkBC.integer--;
                player->unk28.y = player->unkB4.integer + player->unkB8.fp;
                
                if(player->unkBC.integer <= 0){
                    player->unkB4.integer = -player->unkB4.integer;
                    player->unkBC.integer = 4;
                }

                NORM_ANGLE(player->unk28.y);

                player->pos.y -= 0.2;

                if(player->unk28.x < 90.0f){
                    player->unk28.x += 5.0f;
                }
                else if(player->unk28.x < 120.0f){
                    player->unk28.x += 2.0f;
                }
                else if(player->unk28.x < 160.0f){
                    player->unk28.x += 1.0f;
                }

                player->unkB0.integer--;

                if(player->unkB0.integer <= 0){
                    player->unk4 = 1;
                    player->pos.x = player->unkA4.fp;
                    player->pos.y = player->unkA8.fp;
                    player->pos.z = player->unkAC.fp;
                }
                
                break;
        }
    }
}

void func_8003DC20(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp;
    
    NORM_ANGLE(player->unk28.y);

    switch(player->unk4){
        case 0:
            player->unk4 = 1;
            player->unkC0.fp = 0.0f;
            player->unkA8.integer = player->pos.x;
            player->unkAC.integer = player->pos.y;
            player->unkB0.integer = player->pos.z;
            
            break;
        case 1:

            if(func_80024CA0(0, idx, 300.0f) == -1){
                player->unk4 = 2;
                player->unkA0.integer = 0x168;
                player->unkA4.integer = 5;
            }
            else{
                player->unk4 = 6;
                func_8002524C(idx, 0.0f, 0.0f, 0.0f);
                player->unkB4.fp = 0.0f;
                player->unkB8.fp = 0.0f;
                player->unkBC.fp = 0.0f;
                
            }
            break;
        case 2:
            player->unk28.y += 6.0f;
            player->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, player->unkA4.integer--);
            func_8002507C(idx);

            if(player->unkA4.integer < 0){
                player->unkA4.integer = 5;
                player->unk4 = 3;
            }
            else if(player->unkA0.integer < 0){
                player->unk4 = 4; 
                player->unkA0.integer = 0x168;
            }
            break;
        case 3:
            player->unk28.y += 6.0f;
            player->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -player->unkA4.integer--);
            func_8002507C(idx);

            if(player->unkA4.integer < 0){
                player->unkA4.integer = 5;
                player->unk4 = 2;
            }
            else if(player->unkA0.integer < 0){
                player->unk4 = 4;
                player->unkA0.integer = 0x168;
            }
            break;
        case 4:
            player->unk28.y -= 6.0f;
            player->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, player->unkA4.integer--);
            func_8002507C(idx);

            if(player->unkA4.integer < 0){
                player->unkA4.integer = 5;
                player->unk4 = 5;
            }
            else if(player->unkA0.integer < 0){
                player->unk4 = 2; 
                player->unkA0.integer = 0x168;
            }
            break;
        case 5:
            player->unk28.y -= 6.0f;
            player->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -player->unkA4.integer--);
            func_8002507C(idx);

            if(player->unkA4.integer < 0){
                player->unkA4.integer = 5;
                player->unk4 = 4;
            }
            else if(player->unkA0.integer < 0){ 
                player->unk4 = 1; 
                player->pos.x = player->unkA8.integer;
                player->pos.z = player->unkB0.integer;
            }
            break;
        case 6:
            player->unkB4.fp += 0.5;
            player->unkBC.fp += player->unkB4.fp;

            if(func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0) < 0){
                player->unk28.y += 4.0f;

                 while (player->unk28.y >= 360.0f) {
                    player->unk28.y -= 360.0f;
                }
            }
            else {
                player->unk28.y -= 4.0f;

                 while (player->unk28.y < 0.0f) { 
                    player->unk28.y += 360.0f;
                }
                
            }

            if(player->pos.y - player->unkBC.fp < GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->pos.y){
                player->unk4 = 7;
                func_80008E10(0x44, 2, idx);
                player->unkB8.fp = player->unkB4.fp;
            }
            break;
        case 7:
            func_80024FC8(idx, 2.0f, -player->unkB4.fp);
            func_8002507C(idx);

            player->unkB4.fp -= 0.5;

            if(player->unkB4.fp == 0.0f){
                player->unk4 = 8;
            }
            break;
        case 8:
            func_80024FC8(idx, 2.0f, player->unkB4.fp);
            func_8002507C(idx);
            
            player->unkB4.fp += 0.5;

            if(player->unkB8.fp < player->unkB4.fp){
                player->unk4 = 1;
                player->unkA8.integer = player->pos.x;
                player->pos.y = player->unkAC.integer;
                player->unkB0.integer = player->pos.z;

            }
            break;
    }
    player->unkC0.fp += 30.0f;

    NORM_ANGLE(player->unkC0.fp);

    temp = sinf(player->unkC0.fp * 3.14 / 180.0);

    if(player->unk38 != 0xFFFF){
        D_801414A0[player->unk38 + 3]->unk34 = temp * 40.0f;
        D_801414A0[player->unk38 + 4]->unk34 = -temp * 40.0f;        
    }
}

void func_8003E410(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp;
    
    NORM_ANGLE(player->unk28.y);

    switch(player->unkA0.integer){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            func_80016EB8(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, 0.0f, -10.0f, 0.0f);

            if(D_800F9910.unk0 != 0){
                player->unkA0.integer = 1;
                player->unkA8.integer = 1;
                player->unk4E = 2;
                player->unk6C = 0x11;
                
                func_80022F48(idx, 0);
            }
            player->pos.y = D_800F9910.unk10;
            
            break;
        case 1:
            if(func_80024CA0(0, idx, 200.0f) == -1){
                player->unkA0.integer = 2;
                player->unkA4.integer = 0x43;
            }
            else{
                player->unkA0.integer = 3;
            }
            break;
        case 2:
            if(player->unkA4.integer > 0){
                player->unk28.y -= (player->unkA8.integer * 4);
                player->unkA4.integer--;
            }
            else{
                player->unkA0.integer = 1;
                player->unkA8.integer = -player->unkA8.integer;
            }
            break;
        case 3:
            player->unkA0.integer = 4;
            player->unkA8.integer = func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0);
            player->unkB0.integer = 9;
            player->unkB4.integer = 2;
            break;
        case 4:
            player->unk28.y -= (player->unkA8.integer * player->unkB0.integer);

            if(player->unkA8.integer > 0){
                if(func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0) < 0){
                    player->unkB0.integer--;

                    if(player->unkB0.integer == 0){
                        player->unkB4.integer--;

                        if(player->unkB4.integer != 0){
                            player->unkA8.integer = func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0);
                            player->unkB0.integer = 9;
                        }
                        else{
                            player->unkA0.integer = 5;
                            player->unkAC.integer = func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0);                            
                            player->unkA8.integer = func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0);     
                        }
                    }
                }
            }
            else{
                if(func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0) > 0){
                    player->unkB0.integer--;

                    if(player->unkB0.integer == 0){
                        player->unkB4.integer--;

                        if(player->unkB4.integer != 0){
                            player->unkA8.integer = func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0);
                            player->unkB0.integer = 9;
                        }
                        else{
                            player->unkA0.integer = 5;
                            player->unkAC.integer = func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0);                            
                            player->unkA8.integer = func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0);     
                        }
                    }
                }
            }
            break;
        case 5:
            if(player->unkA8.integer > 0){
                player->unk28.y -= 10.0f;

                if(func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0) < 0){
                    player->unk28.y = player->unkAC.integer;
                    func_80008E10(0x45, 2, idx);
                    player->unkA0.integer = 6;
                    player->unkAC.integer = 7;
                    func_80022F48(idx, 1);
                }
            }
            else{
                player->unk28.y += 10.0f;

                if(func_80025288(idx, D_80159178->unk48[D_800F38E1].unk0) > 0){
                    player->unk28.y = player->unkAC.integer;
                    func_80008E10(0x45, 2, idx);
                    player->unkA0.integer = 6;
                    player->unkAC.integer = 7;
                    func_80022F48(idx, 1);
                }
            }
            break;
        case 6:
            func_80024FC8(idx, 5.0f, --player->unkAC.integer);
            func_800180F0(&D_800F9910, cdata.nextstg, 13.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);

            if(D_800F9910.unk0 != 0){
                player->unkA0.integer = 7;
                player->unkA8.integer = 0x64;
                func_80022F48(idx, 2);
            }

            player->pos.x = D_800F9910.unkC;
            player->pos.y = D_800F9910.unk10;
            player->pos.z = D_800F9910.unk14;
            break;
        case 7:
            player->unkA8.integer--;

            if(player->unkA8.integer <= 0){
                player->unkA0.integer = 1;
                player->unkA8.integer = 1;
            }

            if(player->unkA8.integer == 0x49){
                func_80022F48(idx, 0);
            }
            break;
    }
}

void func_8003EB68(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    Player* p;
    f32 temp1;
    f32 temp2;
    u32 temp;

    switch (player->unk4) {     
        case 0:
            player->unk4 = 1;
            player->unkA0.fp = player->pos.x;
            player->unkA4.fp = player->pos.z;
            break;
        case 1:
            temp = func_80011528(0) % 100U;
            player->unkA8.fp = (temp + player->unkA0.fp) - 50.0f;
            
            temp = func_80011528(0) % 100U;
            player->unkAC.fp = (temp + player->unkA4.fp) - 50.0f;
            
            player->unk4 = 2;
            break;
        case 2:
            player->unk28.y += func_80074E68(player->unk28.y, func_80025C48((s32) (player->unkAC.fp - player->pos.z), (s32) (player->unkA8.fp - player->pos.x))) / 60.0f;
        
            NORM_ANGLE(player->unk28.y);
            
            func_80024FC8(idx, 1.0f, -30.0f);
            func_800180F0(&D_800F9910, cdata.nextstg, 10.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
            
            if (D_800F9910.unk1 != 0) {
                player->pos.x = D_800F9910.unkC;
                player->pos.y = D_800F9910.unk10;
                player->pos.z = D_800F9910.unk14;
            } else {
                func_8002507C(idx);
            }
            
            temp1 = player->unkAC.fp - player->pos.z;
            temp2 = player->unkA8.fp - player->pos.x;
            
            if (sqrtf(SQ(temp1) + SQ(temp2)) < 40.0f) {
                player->unk4 = 1;
            }
            
            break;
        case 4:
            p = GET_PLAYER_PTR(player->unkB0.integer);
            
            if (p->unk0 != 0) {
                player->unk28.y += func_80074E68(player->unk28.y,func_80025C48((player->pos.z - p->pos.z),(player->pos.x - p->pos.x))) / 30.0f;
                
                NORM_ANGLE(player->unk28.y);
                
                if (func_80024CA0(4, idx, 120.0f) != -1) {
                    func_80024FC8(idx, 8.0f, -30.0f);
                } else {
                    func_80024FC8(idx, 4.0f, -30.0f);
                }
                
                func_800180F0(&D_800F9910, cdata.nextstg, 10.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
                
                if (D_800F9910.unk1 != 0) {
                    player->pos.x = D_800F9910.unkC;
                    player->pos.y = D_800F9910.unk10;
                    player->pos.z = D_800F9910.unk14;
                } else {
                    func_8002507C(idx);
                }
                
                player->unkB0.integer = func_80024CA0(4, idx, 250.0f);
                
                if (player->unkB0.integer != -1) {
                    player->unk4 = 1;
                }
            } else {
                player->unk4 = 1;
            }
            break;
    } 
    player->unkB0.integer = func_80024CA0(4, idx, 200.0f);
    
    if (player->unkB0.integer != -1) {
        func_80008E10(0x46, 2, idx);
        player->unk4 = 4;
    }
}

void func_8003F09C(s16 idx){
    s32 pad;
    Player* player = GET_PLAYER_PTR(idx);

    if (player->unkA0.integer == 0) {
        player->unk4E = 2;
        player->unk6C = 0x13;

        func_80022F48(idx, 0);
        player->unkA4.integer = func_800249E4(0x14, 0x5E, idx, 50.0f);
        if (player->unkA4.integer != -1){
            func_80022F20(idx, func_8003F190);
            func_8003F190(idx);
        } else{
            func_80022F20(idx, func_8003F990);
            func_8003F990(idx);
        }
    }
}

void func_8003F190(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp1;
    f32 temp2;
    
    switch (player->unk4) {
        case 0:
            player->unk8C |= 0x10;
            GET_PLAYER(player->unkA4.integer).unkA8.integer = 1;
            player->unk4 = 1;
            player->unkB0.ptr = GET_PLAYER_PTR(player->unkA4.integer);
            player->unkAC.fp = player->unk28.y;
            break;
        case 1:
            if (player->unkA8.integer > 0) {
                GET_PLAYER(player->unkA4.integer).unkA8.integer = 2;
                player->unk4 = 2;
            }
            break;
        case 2:
            if (player->unkA8.integer >= 2) {
                player->unkA8.integer = 0;
                player->unkB4.integer = 0xC8;
                
                if (idx < player->unkA4.integer) {
                    player->unkA0.integer = 0;
                    player->unk4 = 100;
                } else {
                    player->unkA0.integer = 1;
                    player->unk4 = 200;
                }
            }
            break;
        case 100:
            if (player->unkA8.integer == 3) {
                player->unkB4.integer = 0xA;
                player->unk4 = 101;
            }
            break;
        case 101:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 5;
                GET_PLAYER(player->unkA4.integer).unkA8.integer = 3;
                func_80022F48(idx, 1);
                player->unk4 = 102;
            }
            func_80025454(player, player->unkB0.ptr, 16.0f);
            break;
        case 102:
            if (player->unkA8.integer == 4) {
                player->unkB4.integer = 0x1E;
                func_80022F48(idx, 0);
                player->unk4 = 103;
            }
            break;
        case 103:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 0xC8;
                player->unkA8.integer = 0;
                player->unk4 = 100;
            }
            
            temp2 = player->unkAC.fp;
            temp1 = player->unk28.y;
            player->unk28.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(player->unk28.y);
            break;
        case 200:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 5;
                player->unk4 = 201;
            }
        case 201:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = (func_80011528(0) % 400U) + 0x1F4;
                GET_PLAYER(player->unkA4.integer).unkA8.integer = 3;
                
                func_80022F48(idx, 1);
                player->unk4 = 202;
            }
            func_80025454(player, player->unkB0.ptr, 16.0f);
            break;
        case 202:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 0x1E;
                func_80022F48(idx, 0);
                player->unk4 = 203;
            }
            break;
        case 203:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 0xC8;
                GET_PLAYER(player->unkA4.integer).unkA8.integer = 4;
                player->unkA8.integer = 0;
                player->unk4 = 200;
            }
            
            temp2 = player->unkAC.fp;
            temp1 = player->unk28.y;
            player->unk28.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(player->unk28.y);
            break;
        case 300:
            if (player->unkA0.integer == 1) {
                player->unkB8.fp = player->unk28.y;
                GET_PLAYER(player->unkA4.integer).unkB8.fp = player->unk28.y;
                player->unkB4.integer = 0x1E;
            } else {
                player->unkB4.integer = 0xA;
            }
            
            player->unkBC.fp = 4.0f;
            func_80022F48(idx, 4);
            player->unk4 = 301;
            break;
        case 301:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unkB4.integer = 0x78;
                player->unk4 = 302;
            }
        case 302:
            player->unkB4.integer--;
            
            if (player->unkB4.integer <= 0) {
                player->unk8C |= 0x1000;
                func_80022F48(idx, 2);
                player->unk4 = 303;
            }
            
            if (player->unkBC.fp > 0.1) {
                player->unkBC.fp -= 0.25;
            } else {
                player->unkBC.fp = 0.0f;
            }
            
            func_80024FC8(idx, 0.0f, player->unkBC.fp);
            func_8002507C(idx);
            
            if (!(player->unkB4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 303:
            temp2 = player->unkB8.fp;
            temp1 = player->unk28.y;
            player->unk28.y += func_80074E68(temp1, temp2) / 16;
            
            NORM_ANGLE(player->unk28.y);
            
            if (player->unkBC.fp < 4.0f) {
                player->unkBC.fp += 0.05;
            }
            
            func_80024FC8(idx, 2.0f, player->unkBC.fp);
            func_8002507C(idx);
            
            if (!(player->unkB4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
    }
    
    if (player->unk4 < 300) {
        if (func_80024CA0(4, idx, 100.0f) != -1 || func_80024CA0(0, idx, 70.0f) != -1) {
            player->unk4 = 300;
        }
    }
}

void func_8003F990(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);  
    Player* p2;
    f32 temp1;
    f32 y;
    f32 diff;
    f32 dist;
    s32 pad;
    f32 z;
    f32 fact;

    switch (player->unk4) {
        case 0:
            player->unk4 = 10;
            player->unkB0.fp = player->pos.x;
            player->unkB4.fp = player->pos.y;
            player->unkB8.fp = player->pos.z;
            player->unkBC.fp = player->unk28.y;
            break;
        case 10:
            player->unkA4.integer = 0x32;
            player->unk4 = 11;
            break;
        case 11:
            player->unkA4.integer--;
            
            if (player->unkA4.integer <= 0) {
                player->unk4 = 15;
            }
            break;
        case 15:
            if ((player->unk70 != -1) && ((func_80024CA0(0, idx, 200.0f) != -1) || (func_80024CA0(4, idx, 200.0f) != -1))) {
                func_80022F48(idx, 4);
                player->unkA4.integer = 0x78;
                player->unk4 = 20;
                player->unkA0.fp = 0.5f;
            }
            break;
        case 20:
            player->unkA4.integer--;
            if (player->unkA4.integer <= 0) {
                player->unkA4.integer = 0;
                player->unk4 = 30;
            }
            func_80024FC8(idx, -0.25f, player->unkA0.fp);
            func_8002507C(idx);
            break;
        case 30:
            player->unkA4.integer++;
            player->unkA0.fp -= 0.05;
            
            if (player->unkA0.fp < 0.1) {
                func_80022F48(idx, 2);
                player->unkA4.integer = 0x21C;
                player->unk4 = 40;
            }
            
            func_80024FC8(idx, -0.05f, player->unkA0.fp);
            func_8002507C(idx);
            
            if (!(player->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 40:
            player->unkA4.integer--;
            
            if ((player->unkA4.integer <= 0) || (D_80141CB0[idx].unk0 != -1)) {
                func_80022F48(idx, 4);
                player->unk4 = 100;
            }
            
            p2 = GET_PLAYER_PTR(player->unk70);
            
            if (!(p2->unk8C & 8)) {
                diff = player->pos.y - p2->pos.y;
                
                if (diff < 20.0f) {
                    player->unkA0.fp = player->unk5C;
                    func_80022F48(idx, 4);
                    player->unk4 = 41;
                } else if (diff < 40.0f) {
                    player->unkA8.fp = 0.3f;
                    player->unkAC.fp = 0.1f;
                } else {
                    if (diff < 60.0f) {
                        player->unkA8.fp = 0.6f;
                        player->unkAC.fp = 0.1f;
                    } else if (diff < 80.0f) {
                        player->unkA8.fp = 0.9f;
                        player->unkAC.fp = 0.1f;
                    } else if (diff < 100.0f) {
                        player->unkA8.fp = 1.2f;
                        player->unkAC.fp = 0.1f;
                    } else {
                        player->unkA8.fp = 1.5f;
                        player->unkAC.fp = 0.1f;
                    }
                }
            }
            
            func_80025454(player, p, 16.0f);
            func_80024F20(idx, 2.0f);
            func_8002592C(player, p, player->unkA8.fp, player->unkAC.fp);
            func_8002507C(idx);
            
            if (!(player->unkA4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 41:
            player->unkA4.integer--;
            
            if ((player->unkA4.integer <= 0) || (D_80141CB0[idx].unk0 != -1)) {
                player->unkA4.integer = 0;
                player->unk4 = 100;
            }
            
            p2 = GET_PLAYER_PTR(player->unk70);
            diff = player->pos.y - p2->pos.y;
            
            if (p2->unk8C & 8) {
                player->unk4 = 40;
            }
            if (diff > 100.0f) {
                player->unk5C = player->unk5C * 0.93;
            } else {
                player->unk5C = player->unk5C + 0.01;
            }
            if (diff > 240.0f) {
                player->unk4 = 40;
            }
            
            player->unk58 = player->unk58 * 0.98;
            player->unk60 = player->unk60 * 0.98;
            
            func_80025454(player, p, 16.0f);
            func_8002507C(idx);
            
            if (!(player->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 100:
            player->unkA4.integer++;
            
            if (player->unk5C > 0.1) {
                player->unk5C *= 0.95;
                player->unk58 *= 0.95;
                player->unk60 *= 0.95;
            } else {
                func_80022F48(idx, 2);
                player->unk4 = 101;
            }
            if (!(player->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            
            func_8002507C(idx);
            break;
        case 101:
            player->unkA4.integer++;
            
            diff = player->unkB0.fp - player->pos.x;
            y = (player->unkB4.fp + 30.0f) - player->pos.y;
            z = player->unkB8.fp - player->pos.z;
            
            dist = sqrtf(SQ(diff) + SQ(z));
            
            if (dist == 0.0f) {
                dist = 1.0f;
            }
            
            player->unk5C = (y / dist) * 0.5 * 1.02;
            temp1 = func_80025C48(player->unkB8.fp - player->pos.z, player->unkB0.fp - player->pos.x);
            
            if (dist < 50.0f) {
                fact = 0.5f;
            } else if (dist < 100.0f) {
                fact = 0.3f;
            } else {
                fact = 0.1f;
            }
            
            player->unk28.y += func_80074E68(player->unk28.y, temp1) * fact;
            
            NORM_ANGLE(player->unk28.y);
            
            func_80024F20(idx, 2.0f);
            func_8002507C(idx);
            
            if ((dist < 5.0f) && (player->unkB4.fp < player->pos.y)) {
                func_80022F48(idx, 4);
                player->unk4 = 102;
            }
            if (!(player->unkA4.integer & 0xF)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 102:
            player->unkA4.integer++;
            
            player->unk58 = player->unk58 * 0.5;
            player->unk60 = player->unk60 * 0.5;
            player->unk5C = player->unk5C - 0.01;
            
            if (player->unk5C < -1.0f) {
                player->unk5C = -1.0f;
            }
            
            func_8002507C(idx);
            
            if (player->pos.y < player->unkB4.fp) {
                player->pos.y = player->unkB4.fp;
                func_80022F48(idx, 0);
                player->unk4 = 10;
            }
            if (!(player->unkA4.integer & 0x1F)) {
                func_80008E10(0x47, 2, idx);
            }
            break;
        case 900:
            player->unk8C |= 0x1000;
            func_80024FC8(idx, 2.0f, 2.0f);
            func_8002507C(idx);
            break;
        }
    
    if ((GET_PLAYER_PTR(player->unk70)->unk0 == 0) && (player->unk4 < 0x384)) {
        player->unk4 = 900;
    }
}

void func_80040404(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    f32 diffZ;
    f32 diffX;
    f32 diffY;
    s32 pad[2];
    f32 x;
    f32 y;
    f32 z;
    s32 pad2[3];
    f32 dist;
    
    switch (player->unkB8.integer) { 
        case 0:
            x = player->unkA0.fp;
            y = player->unkA4.fp;
            z = player->unkA8.fp;
            break;
        case 1:
            x = player->unkAC.fp;
            y = player->unkB0.fp;
            z = player->unkB4.fp;
            break;
    }
    
    diffX = x - player->pos.x;
    diffY = y - player->pos.y;
    diffZ = z - player->pos.z;
    
    dist = sqrtf(SQ(diffX) + SQ(diffY) + SQ(diffZ));
    
    switch (player->unk4) {
        case 0:
            player->unkB8.integer = 0;
            player->unk5C = 0.0f;
            player->unkE8.fp = 10.0f;
            player->unk4E = 2;
            player->unk6C = 0x16;
            
            func_80022F48(idx, 0);
            player->unk4 = 1;
            break;
        case 1:
            if (y < player->pos.y) {
                player->unk5C -= 0.05;
                if (player->unk5C < -3.0f) {
                    player->unk5C = -3.0f;
                }
            } else if (player->pos.y < y) {
                player->unk5C += 0.05;
                if (player->unk5C > 3.0f) {
                    player->unk5C = 3.0f;
                }
            }
            
            diffZ = func_80025C48(z - player->pos.z, x - player->pos.x);
            diffZ = func_80074E68(player->unk28.y, diffZ) * 0.03125;
            
            player->unk28.y += diffZ;
            
            NORM_ANGLE(player->unk28.y);
            
            func_80024F20(idx, player->unkE8.fp);
            func_8002507C(idx);
            break;
    }
    
    if (dist < 100.0f) {
        player->unkB8.integer = 1 - player->unkB8.integer;
        player->unkE8.fp = 10.0f;
    } else if (dist < 200.0f) {
        player->unkE8.fp = 2.0f;
    } else if (dist < 300.0f) {
        player->unkE8.fp = 4.5f;
    } else if (dist < 400.0f) {
        player->unkE8.fp = 6.5f;
    } else if (dist < 500.0f) {
        player->unkE8.fp = 8.0f;
    }
}

void func_800407FC(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    s32 id;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);

    switch (player->unk4) {
        case 0:
            if (player->unkA0.integer == 1) {
                player->unk74 = 0xA;
                player->unk90.x = 3.0f;
                player->unk90.y = 3.0f;
                player->unk90.z = 3.0f;
            }

            player->unk4E = 2;
            player->unk6C = 0x29;
            func_80022F48(idx, 2);
            player->unkA4.integer = 0xA;
            player->unk4 = 10;
        default:
            break;
        case 10:
            if (temp < 100.0f) {
                player->unkA8.fp = 4.0f;
                player->unkA4.integer = 0x3C;
                func_80008E10(0x55, 2, idx);
                player->unk4 = 11;
                return;
            }
            break;
        case 11:
            player->unkA4.integer--;

            if (player->unkA4.integer <= 0) {
                func_80022F48(idx, 0);
                player->unkA4.integer = 0x28;
                player->unk4 = 12;
            }

            func_80025454(player, p, 24.0f);
            return;
        case 12:
            player->unkA4.integer--;

            if (player->unkA4.integer <= 0) {
                func_80008E10(0x17, 2, idx);
                player->unkA4.integer = 0x3C;
                func_80022F48(idx, 2);
                player->unk4 = 13;
            }
            if (player->unkA4.integer == 5) {
                id = func_80023644(5, 0x141, 0.0f, 0.0f, 0.0f, 0.0f, player->unk28.y + 50.0f, 0.0f);

                if (id != -1) {
                    func_800242F0(id, 0, 0xFFFFU);
                    func_80022F20(id, func_8004EAC4);
                    func_80025638(GET_PLAYER_PTR(id), player, player->unk28.y + 50.0f, 20.0f, 10.0f);
                    return;
                }
            }
            break;
        case 13:
            player->unkA4.integer--;

            if (player->unkA4.integer <= 0) {
                player->unk4 = 10;
            }
            break;
    }
}

void func_80040AB8(s16 idx) {
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad;

    switch (player->unk4) {
        case 0:
            player->unkD4.fp = player->unkB4.fp;
            player->unkD8.fp = player->unkB8.fp;
            player->unkDC.fp = player->unkBC.fp;

            player->unkC0.fp = 2.0f;
            player->unkC4.fp = 0.9f;
            player->unkC8.fp = 0.05f;
            player->unkCC.fp = 32.0f;
            player->unkD0.fp = 200.0f;
            
            player->unk4 = 1;
            player->unk4E = 2;
            player->unk6C = 0x2B;
            func_80022F48(idx, 0);
            break;
        case 1:
            func_80021B90(idx);
            break;
    }
}
