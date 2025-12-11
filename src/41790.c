#include "41790.h"

#include "11F10.h"
#include "73660.h"
#include "23B20.h"
#include "55270.h"
#include "9320.h"
#include "29980.h"
#include "15F60.h"
#include "2DE50.h"
#include "B4E0.h"
#include "1D870.h"

#include "libc/math.h"
#include "global.h"
 
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

typedef struct func_80040BD8_struct_player{
    u8 unk0[0x34];
    f32 unk34;
    s32 unk38;
    f32 unk3C;
    f32 unk40;
}func_80040BD8_struct_player;

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

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x6];
    s16 unk8;
    u8 unkA[0x3];
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x24];
}D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

extern u8 D_800F38E1;
extern f32 D_80159170;

void func_80040B90(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unk4 = 1;
            break;
        case 1:
            break;
    }
}

void func_80040BD8(s16 idx){
    s16 temp;
    f32 temp4;
    f32 temp8;
    f32 temp7;
    f32 temp6;
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp2;
    f32 temp5;
    f32 temp3;

    if(player->unk38 != 0xFFFF){
        D_801414A0_ptr_struct **tmp = &D_801414A0[player->unk38];
        player->unkBC.ptr = tmp[2];\
        player->unkC0.ptr = tmp[3];\
        player->unkC4.ptr = tmp[4];\
        
        switch(player->unk4){
            case 0:
                player->unk8B = 0x64;
                player->unkD8.fp = player->unkB4.integer;
                player->unkDC.fp = -(f32)player->unkB8.integer * 0.05;
                player->unkC8.fp = func_80011528(0) % 360U;
                player->unkCC.fp = 0.0f;
                player->unkD0.integer = 0xC8;
                player->unkD4.integer = -1;

                if(player->unkD8.fp == 0.0f){
                    player->unkD8.fp = 2.0f;
                }

                if(player->unkDC.fp == 0.0f){
                    player->unkDC.fp = -0.3f;
                }
            
                player->unk4 = 1;
                break;
            case 1:
                temp3 = 0.0f;
                temp = func_80024CA0(0, idx, 200.0f);
            
                if(temp != -1){
                    temp2 = func_80074E68(player->unk28.y, func_800253B0(idx, temp)) / 60.0f;

                    player->unk28.y += temp2;

                NORM_ANGLE(player->unk28.y);
                    
                if(temp2 < 1.0f && -0.1 < temp2 && player->unkCC.fp > 0.0f){
                        temp3 = 1.0f;
                    }
                }

                player->unkC8.fp += 3.0f;

                NORM_ANGLE(player->unkC8.fp);

                temp4 = sinf(player->unkC8.fp * 6.28 / 180.0) ;
                temp8 = sinf((player->unkC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp7 = sinf(player->unkC8.fp * 3.14 / 180.0) ;
                temp6 = sinf((player->unkC8.fp + 30.0f) * 6.28 / 180.0) ;
                temp5 = (1.0f - temp4) * 0.04 + 1.0;

                func_800248A4(idx, temp5, temp5, temp5);

                ((func_80040BD8_struct_player*)(player->unkBC.ptr))->unk3C = temp4 * 0.05 + 1.0;
                ((func_80040BD8_struct_player*)(player->unkC0.ptr))->unk3C = temp4 * 0.2 + 1.0;
                ((func_80040BD8_struct_player*)(player->unkC0.ptr))->unk40 = temp7 * 0.2 + 1.0;
                ((func_80040BD8_struct_player*)(player->unkC0.ptr))->unk34 = temp4 * 5.0f;
                ((func_80040BD8_struct_player*)(player->unkC4.ptr))->unk3C = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_player*)(player->unkC4.ptr))->unk40 = temp8 * 0.2 + 1.0;
                ((func_80040BD8_struct_player*)(player->unkC4.ptr))->unk34 = temp6 * 5.0f;
                
                player->unkD0.integer += player->unkD4.integer;

                if(player->unkCC.fp > 0.0f){
                    player->unkCC.fp *= 0.95;

                    if(player->unkCC.fp < 0.1){
                        player->unkCC.fp = 0.0f;
                    }
                }
                else{
                    player->unkCC.fp -= 0.01;

                    if(player->unkCC.fp < player->unkDC.fp){
                        player->unkCC.fp = player->unkDC.fp;
                    }
                }

                if(player->unkD0.integer <= 0){
                    player->unkD0.integer = func_80011528(0) % 120U + 0x78;
                    player->unkCC.fp = player->unkD8.fp;
                }

                func_80024FC8(idx, temp3, player->unkCC.fp);
                func_8002507C(idx);
                func_8002513C(player);

                switch(player->unkB4.integer & 7U){
                    case 1:
                        player->pos.x -= player->unk58;
                        player->pos.z -= player->unk60;
                        break;
                    case 4:
                        player->unkD0.integer = 0;
                        player->unkD4.integer = -1;
                        player->unkCC.fp = player->unkD8.fp;
                        
                        break;
                    case 2:
                        player->unkCC.fp = 0.0f;
                        player->unkD0.integer = func_80011528(0) % 120U + 0x78;
                        player->unkD4.integer = 0;
                        break;
                }
                break; 
        }
    }
}

void func_80041268(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    
    s16 id;


    switch(GET_PLAYER_PTR(idx)->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x1F;
            func_80022F48(idx, 1);
            player->unk4 = 1;
            break;
        case 1:
            func_80022F48(idx, 1);
            player->unkA0.integer = 0x64;
            player->unkA8.fp = func_80011528(0) & 360U;
            player->unk58 = 0.0f;
            player->unk4 = 2;
            player->unk5C = 0.0f;
            player->unk60 = 0.0f;
            player->unkA4.fp = 0.0f;
            break;
        case 2:
            GET_PLAYER_PTR(idx)->unkA0.integer--;

            if(GET_PLAYER_PTR(idx)->unkA0.integer <= 0){
                player->unkA8.fp = func_80011528(0) & 360U;            
                player->unkA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(player, player->unkA8.integer, 40.0f);
            
            player->unkA4.fp += 0.04;

            if(player->unkA4.fp > 1.0f){
                player->unk4 = 3;
            }

            func_80024F20(idx, -0.5f);
            player->unk5C = player->unkA4.fp;
            func_80059760(player);
            break;
        case 3:
            GET_PLAYER_PTR(idx)->unkA0.integer--;

            if(GET_PLAYER_PTR(idx)->unkA0.integer <= 0){
                player->unkA8.fp = func_80011528(0) & 360U;            
                player->unkA0.integer =(func_80011528(0) + 100) & 0x7F;
            }

            func_80025820(player, player->unkA8.integer, 40.0f);
            
            player->unkA4.fp -= 0.04;

            if(player->unkA4.fp < -1.0f){
                player->unk4 = 2;
            }

            func_80024F20(idx, -0.5f);
            player->unk5C = player->unkA4.fp;
            func_80059760(player);
            break;
        case 10:
            player->unkA0.integer = 0x1E;
            player->unk4 = 11;
            break;
        case 11:
            GET_PLAYER_PTR(idx)->unkA0.integer--;

            if(GET_PLAYER_PTR(idx)->unkA0.integer <= 0){
                func_80008E10(0x51, 2, idx);
                player->unkA0.integer = 0x20;
                player->unk4 = 12;
            }

            func_80025454(player, p, 16.0f);
            break;
        case 12:
            GET_PLAYER_PTR(idx)->unkA0.integer--; 

            if(GET_PLAYER_PTR(idx)->unkA0.integer <= 0){
                player->unkA0.integer = 0x1F4;
                player->unk4 = 13;
            }
            func_80025454(player, p, 16.0f);
            func_80024FC8(idx, -1.0f, 0.0f);
            func_80059760(player);

            if(player->unkA0.integer & 1){
                id = func_80023644(6, 0x183, 0.0f, 0.0f, 0.0f, 0.0f, player->unk28.y, 0.0f);

                if(id != -1){
                    GET_PLAYER_PTR(id)->unk8C |= 0x1000;
                    func_80022F20(id, func_8002C3AC);
                    func_80025638(GET_PLAYER_PTR(id), player, player->unk28.y, 30.0f, 5.0f);
                    func_80024874(id, 0.2f);
                }
            }
        case 13:
            func_80022F48(idx, 1);

            GET_PLAYER_PTR(idx)->unkA0.integer--;

            if(GET_PLAYER_PTR(idx)->unkA0.integer <= 0){
                player->unk4 = 1;
                player->unkA4.fp = 0.0f;
            }

            func_80025454(player, p, 16.0f);
            func_80024FC8(idx, -player->unkA4.fp, 0.0f);
            func_80059760(player);

            if(temp < 300.0f){
                player->unkA4.fp = 5.0f;
            }

            if(player->unkA4.fp > 0.0f){
                player->unkA4.fp -= 0.01;
            }
        break;
        
    }

    if(temp < 300.0f){
        if(player->unk4 > 0 && player->unk4 < 3){
            player->unk4 = 10;
        }
    }


}

void func_80041790(s16 idx){
    s32 pad;
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x20;
            func_80022F48(idx, 0);
            player->unk4 = 1;
            break;
        case 1:
            break;
    }
}

void func_80041808(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p;
    f32 temp;
    s16 temp3;
    
    NORM_ANGLE(player->unk28.y);

    func_8002513C(player);

    switch(player->unk4){
        case 0:
            player->unkBC.integer = 0;
            player->unkC0.integer = 0;
            player->unkC4.fp = 0.0f;
            player->unkC8.fp = 0.0f;
            player->unkCC.fp = func_80011528(0) % 360U;
            player->unkD0.integer = func_80011528(0) % 400U + 0x1F4;
            player->unk4 = 1;
            
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < player->pos.y + 100.0f){
                player->pos.y -= 1.0f;
            }

            if(player->unkDC.integer == 0){
                player->unkD4.integer = func_80024CA0(0, idx, 300.0f);

                if(player->unkD4.integer != -1){
                    p = GET_PLAYER_PTR(player->unkD4.integer);
                    
                    if(player->pos.y - 20.0f < p->pos.y && p->pos.y < player->pos.y + 50.0f){
                        player->unk4 = 2;
                        player->unkDC.integer = 0x1F4;
                    }
                }
            }
            temp3 = (func_80011528(0) % 12U - 6);
            
            if(temp3 > 0){
                player->unkBC.integer++;
            }

            if(player->unkBC.integer >= 0x5B){
                player->unkBC.integer = 0;
                player->unkC0.integer = 0x5A;
                player->unkC4.fp = 1.0f;
            }

            if(player->unkC0.integer != 0){
                temp = player->unkC4.fp;
                player->unkC0.integer--;
            }
            else {
                temp = player->unkC4.fp;
                if(player->unkC4.fp > 0.0f) {
                    player->unkC4.fp -= -0.002;
                }
            }
            
            temp -= 0.05;
            func_80024FC8(idx, temp, 0.0f);
                
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, 0.0f, player->unk60);

            if(D_800F9910.unk1 != 0){
                if(player->unkC8.fp == 0.0f){
                    player->unkB8.fp = func_80074E68(player->unk28.y, func_80025C48(player->unkA8.fp - player->pos.z, player->unkA0.fp - player->pos.x));
                    player->unkC8.fp = player->unkB8.fp / (func_80011528(0) % 5U + 1);
                }

                player->pos.x = D_800F9910.unkC;
                player->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
            }
            
            break;
        case 2:
            temp = func_80074E68(player->unk28.y, func_800253B0(idx, player->unkD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                player->unk4 = 3;
                player->unkD8.integer = 0x32;
            }

            player->unk28.y += temp * 0.1;
            player->unkC4.fp *= 0.9;
            break;
        case 3:
            player->unkD8.integer--;

            if(player->unkD8.integer <= 0){
                player->unkBC.integer = 0;
                player->unkC0.integer = 0xA;
                player->unkC4.fp = 3.0f;
                func_80008E10(0x53, 2, idx);
                player->unk4 = 1;
            }
            break;
        
    }

    if(player->unkDC.integer != 0){
        player->unkDC.integer--;
    }

    player->unkD0.integer--;

    if(player->unkD0.integer <= 0){
        player->unkD0.integer = (func_80011528(0) % 400U) + 0x1F4;

        if(player->unkC8.fp == 0.0f){
            player->unkC8.fp = func_80011528(0) % 180U;
        }
    }

    player->unkCC.fp += 3.0f;

    NORM_ANGLE(player->unkCC.fp);

    if(player->unkC8.fp != 0.0f){
        player->unkC8.fp = func_80025374(idx, player->unkC8.fp, 0.05);

        if(player->unkC8.fp < 10.0f && player->unkC8.fp > -10.0f){
            player->unkC8.fp = 0.0f;
        }
    }
    else{
        player->unk28.y += sinf((player->unkCC.fp * 3.14) / 180.0)  * 0.3;
    }

    player->pos.y += cosf((player->unkCC.fp * 3.14) / 180.0)  * 0.2;
 
    switch(player->unkB4.integer & 7){
        case 1:
            if(player->unkC8.fp == 0.0f){
               player->unkC8.fp = player->unkB8.fp / (func_80011528(0) % 5U + 1);
            }
            break;
        case 2:
        case 4: 
            break; 
    }
}

void func_80042040(s16 idx){
    
    switch(GET_PLAYER_PTR(idx)->unkA0.integer){
        case 0:
            func_80022F20(idx, func_800420A4);
            func_800420A4(idx); 
            break;
        case 1:
            break;
    }
}

void func_800420A4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    
    switch(player->unk4){
        case 0:
            player->unkA4.integer--;

            if(player->unkA4.integer <= 0){
                player->unkB0.fp *= 0.1;
                player->unkB4.fp *= 0.1;
                player->unk4 = 1;
            }

            player->unkB8.integer = 0;
            player->unk8C |= 0x2000;
            break;
        case 1:
            player->unkB8.integer += 8;

            if(player->unkB8.integer >= 0x100){
                player->unkB8.integer = 0xFF;
                player->unk4 = 2;
            }
            break;
        case 2:
            GET_PLAYER_PTR(idx)->unkA8.integer--;

            if(GET_PLAYER_PTR(idx)->unkA8.integer <= 0){
                GET_PLAYER_PTR(idx)->unkA8.integer = 0x78;
                player->unk4 = 3;
            }

            func_80024FC8(idx, player->unkAC.fp, 0.0f);
            func_8002507C(idx);
            
            break;
        case 3:
            GET_PLAYER_PTR(idx)->unkA8.integer--;

            if(GET_PLAYER_PTR(idx)->unkA8.integer <= 0){
                GET_PLAYER_PTR(idx)->unkA8.integer = 0x12C;
                player->unk4 = 4;
            }

            func_80025454(player, p, 8.0f);

            player->unk58 *= 0.98;
            player->unk60 *= 0.98;
            player->pos.x += player->unk58;
            player->pos.z += player->unk60;
            
            
            break;
        case 4:
            GET_PLAYER_PTR(idx)->unkA8.integer--;

            if(GET_PLAYER_PTR(idx)->unkA8.integer <= 0){
                player->unk4 = 5;
            }
            func_80025454(player, p, 16.0f);
            func_8002592C(player, p, player->unkB0.fp, player->unkB4.fp);
            func_80024F20(idx, player->unkAC.fp);
            func_8002507C(idx);
            break;
        case 5:
            player->unkB8.integer -= 8;

            if(player->unkB8.integer < 0){
                player->unkB8.integer = 0;
                func_80023FCC(idx);
                return;
            }
            else{
                func_8002507C(idx);
            }
            break;
    }

    player->unk8B = player->unkB8.integer;
    D_801414A0[player->unk38 + 2]->unk38 += 30.0f;

    NORM_ANGLE(D_801414A0[player->unk38 + 2]->unk38);
}

void func_80042418(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);

    switch(player->unk4){
        case 0:
            player->unk8 = 0x53F;
            player->unk4E = 2;
            player->unk6C = 0x23;
            func_80022F48(idx, 0);
            player->unkA4.integer = 10;

            if(player->pos.x < 0.0f){
                player->unkAC.fp = -((s32)player->pos.x % 600);
            }
            else{
                player->unkAC.fp = ((s32)player->pos.x % 600);
            }

            player->unk4 = 10;
            
            break;
        case 10:
            if(temp < 100.0f){
                player->unkA8.fp = 4.0f;
                player->unkA4.integer = 0x3C;
                func_80008E10(0x55, 2, idx);
                player->unk4 = 11;
            }

            player->unkAC.fp += 1.0f;

            if(player->unkAC.fp > 500.0f){
                player->unkA4.integer = 0x64;
                player->unk8 = 0;
                player->unkAC.fp = 0.0f;
                func_80022F48(idx, 2);
                player->unk4 = 14;
            }
            break;
        case 11:
            player->unkA4.integer--;

            if(player->unkA4.integer <= 0){
                player->unk8 = 0;
                func_80022F48(idx, 1);
                player->unk4 = 12;
            }
            func_80025454(player, p, 24.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, player->unkA8.fp);
            player->unkA8.fp -= D_80159170 * 0.666;
            func_80059760(player);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                player->unkA4.integer = 0x3C;
                func_80022F48(idx, 0);
                player->unk4 = 13;
            }
            break;
        case 13:
            player->unk8 = 0x53F;
            player->unkA4.integer--;
             

            if(player->unkA4.integer <= 0){
                player->unk4 = 10;
            }
            break;
        case 14:
            player->unkA4.integer--;

            if(player->unkA4.integer <= 0){
                func_80022F48(idx, 0);
                player->unk8 = 0x53F;
                player->unk4 = 10;
            }
            break;

    }
}

void func_80042758(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad;

    switch(player->unk4){
        case 0:
            player->unkD4.fp = player->unkB4.fp;
            player->unkD8.fp = player->unkB8.fp;
            player->unkDC.fp = player->unkBC.fp;
            player->unkC0.fp = 1.0f;
            player->unkC4.fp = 0.9f;
            player->unkC8.fp = 0.05f;
            player->unkCC.fp = 32.0f;
            player->unkD0.fp = 200.0f;
            player->unkE0.fp = player->unk90.x;
            player->unkE4.integer = 0x1E;
            player->unk4 = 1; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < player->pos.y + 100.0f){
                player->pos.y -= 1.0f;
            }

            if(func_80024CA0(0, idx, 50.0f) != -1){
                player->unkE4.integer = 0xF;
                player->unk4 = 2;
            }
            func_80021B90(idx);
            break;
        case 2:
            player->unkE4.integer--;

            if(player->unkE4.integer >= 2){
                player->unk90.x += 0.4;
                player->unk90.z += 0.4;
                player->unk90.y += 0.4;
            }
            else{
                player->unk4 = 3;
            }
            break;
        case 3:
            if(func_80024CA0(0, idx, 100.0f) != -1){
                func_80021B90(idx);
            }
            else{
                func_80008E10(0x59, 2, idx);
                player->unkE4.integer = 0x14;
                player->unk4 = 4;
            }
            break;
        case 4:
            player->unkE4.integer--;

            if(player->unkE4.integer >= 2){
                player->unk90.x -= 0.2;
                player->unk90.z -= +0.2;
                player->unk90.y -= 0.2;
            }
            else{
                player->unk4 = 1;

                player->unk90.x = player->unkE0.fp;
                player->unk90.z = player->unkE0.fp;
                player->unk90.y = player->unkE0.fp;
            } 
            break;
    }
}

void func_80042A38(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s16 id;
    f32 temp1;

    switch(player->unk4){
        case 0:
            switch(player->unkA0.integer){
                case 0:
                    func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y + 5.0f, player->pos.z, -300.0f);

                    if(D_800F9910.unk0 != 0){
                        player->pos.y = D_800F9910.unk10 + 0.5;
                        player->unk28.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        player->unk28.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        player->unkBC.fp = D_800F9910.unk18;
                        player->unkC0.fp = D_800F9910.unk1C;
                        player->unkC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        player->unkBC.fp = 0.0f;
                        player->unkC0.fp = 1.0f;
                        player->unkC4.fp = 0.0f;
                        
                    }
                    break;
                case 1:
                    func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y - 5.0f, player->pos.z, 300.0f);
                    
                    if(D_800F9910.unk0 != 0){
                        player->pos.y = D_800F9910.unk10 - 0.5;
                        player->unk28.z = -(DEG2RAD(90) - func_8000AE70(D_800F9910.unk1C / sqrtf(1.0f - SQ(D_800F9910.unk1C)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                        player->unk28.y = -func_8000B038(D_800F9910.unk20, D_800F9910.unk18) * 57.32484076; //RAD2DEG(x) x being more than 1...?

                        player->unkBC.fp = D_800F9910.unk18;
                        player->unkC0.fp = D_800F9910.unk1C;
                        player->unkC4.fp = D_800F9910.unk20;
                        
                    }
                    else{
                        player->unkBC.fp = 0.0f;
                        player->unkC0.fp = -1.0f;
                        player->unkC4.fp = 0.0f;
                        
                    }                    
                    break;
            }

            player->unkC8.fp = func_80011528(0) % 360U;
            player->unkA4.fp = player->unk90.x;
            player->unkB4.integer = 0;
            
            player->unk4 = 1;
            
            break;
        case 1:
            player->unkC8.fp += 5.0f;

            NORM_ANGLE(player->unkC8.fp);

            player->unk90.x = sinf((player->unkC8.fp * 6.28) / 180.0) * 0.05 + (f64)player->unkA4.fp;
            player->unk90.z = sinf((player->unkC8.fp * 6.28) / 180.0) * 0.05 + (f64)player->unkA4.fp; 
            player->unk90.y = cosf((player->unkC8.fp * 3.14) / 180.0) * 0.08 + (f64)player->unkA4.fp; 
 
            if(player->unkB4.integer != 0){
                player->unkB4.integer--;
            }

            if(player->unkB4.integer == 0){
                player->unkA8.integer = func_80024CA0(0, idx, 300.0f);

                if(player->unkA8.integer != -1){
                    player->unkAC.fp = 0.0f;
                    player->unkB0.fp = 0.0f;
                    player->unkB8.fp = 0.05f;
                    player->unk4 = 2;
                     
                }
            }
            
            break;
        case 2:
            player->unkAC.fp += player->unkB8.fp;
            player->unkB8.fp -= 0.001;

            if(player->unkAC.fp > 1.0f){
                player->unkB0.fp = player->unkAC.fp; 

                id = func_80023644(2, 0x70, player->unkBC.fp * 10.0f + player->pos.x, player->unkC0.fp * 10.0f + player->pos.y, player->unkC4.fp * 10.0f + player->pos.z, 0.0f, 0.0f, 0.0f); 
                func_80008E10(0x54, 2, idx);
                
                if(id != -1){
                    GET_PLAYER_PTR(id)->unkA4.fp = player->unkBC.fp;
                    GET_PLAYER_PTR(id)->unkA8.fp = player->unkC0.fp;
                    GET_PLAYER_PTR(id)->unkAC.fp = player->unkC4.fp;
                    
                }
                player->unk4 = 3;

            } 
            func_800248A4(idx, player->unkAC.fp + player->unkA4.fp, player->unkB0.fp + player->unkA4.fp, player->unkAC.fp + player->unkA4.fp);
            
            break;
        case 3: 
            player->unkAC.fp-= 0.02;

            if(player->unkAC.fp < 0.03){
                player->unk4 = 4;
            }

            func_800248A4(idx, player->unkAC.fp + player->unkA4.fp, player->unkB0.fp + player->unkA4.fp, player->unkAC.fp + player->unkA4.fp);
            break;
        case 4:
            player->unkB0.fp -= 0.012;
    
            if(player->unkB0.fp < 0.03){
                player->unkB4.integer = 0x1F4;
                player->unk4 = 1;
            } 
            
            func_800248A4(idx, player->unkAC.fp + player->unkA4.fp, player->unkB0.fp + player->unkA4.fp, player->unkAC.fp + player->unkA4.fp);
            
            break;
    }
} 


void func_8004312C(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    

    if(D_80141CB0[idx].unk8 != -1){
        func_80022F20(idx, func_8002D7AC); 
        func_80023644(6, 0x161, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);

        return;
    }

    if(D_80141CB0[idx].unk0 != -1){
        func_80023FCC(idx);
        func_80023644(6, 0x161, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);

        return;
    }


    switch(player->unk4){ 
        case 0:
            player->unkA0.integer = 0x1F4;
            player->unk28.z = -(DEG2RAD(90) - func_8000AE70(player->unkA8.fp / sqrtf(1.0f - SQ(player->unkA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            player->unk28.y = -func_8000B038(player->unkAC.fp, player->unkA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
            func_8002524C(idx, player->unkA4.fp, player->unkA8.fp, player->unkAC.fp); 
            player->unk4 = 1;
            break;
        case 1:
            player->unkB0.integer = func_80024CA0(0, idx, 300.0f);

            if(player->unkB0.integer != -1){
                player->unkB4.integer = 0x78;
                player->unkB8.ptr = GET_PLAYER_PTR(player->unkB0.integer);
                player->unk4 = 2;                     
            }         
            func_8002507C(idx);
             
            break;
        case 2:
            GET_PLAYER_PTR(idx)->unkB4.integer--;

            if(GET_PLAYER_PTR(idx)->unkB4.integer == 0){
                player->unk4 = 3;
            }
            
            func_8002507C(idx);
            break;
        case 3:
            player->unkA0.integer--;

            if(player->unkA0.integer != 0){
                if(player->pos.x < ((Player*)(player->unkB8.ptr))->pos.x){
                    player->unkA4.fp += 0.3;
                }
                else{
                    player->unkA4.fp -= 0.3;
                }
                
                if(player->pos.y < ((Player*)(player->unkB8.ptr))->pos.y + 25.0f){
                    player->unkA8.fp += 0.3;
                }
                else{
                    player->unkA8.fp -= 0.3;
                }
                if(player->pos.z < ((Player*)(player->unkB8.ptr))->pos.z){
                    player->unkAC.fp += 0.3;
                }
                else{
                    player->unkAC.fp -= 0.3; 
                }  

                func_80025E14(&player->unkA4.fp, &player->unkA8.fp, &player->unkAC.fp); 
                player->unk28.z = -(DEG2RAD(90) - func_8000AE70(player->unkA8.fp / sqrtf(1.0f - SQ(player->unkA8.fp)))) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                player->unk28.y = -func_8000B038(player->unkAC.fp, player->unkA4.fp) * 57.32484076; //RAD2DEG(x) x being more than 1...?
                func_8002524C(idx, player->unkA4.fp, player->unkA8.fp, player->unkAC.fp); 
                func_8002507C(idx);
            }
            else{
                func_80023FCC(idx);
                func_80023644(6, 0x161, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);

            }
            break;
    }
}


void func_800435A0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player *player2;
    f32 temp;
    f32 temp3;
    s16 temp2; 
    
    NORM_ANGLE(player->unk28.y);

    switch(player->unk4){
        case 0:
            player->unkBC.integer = 0;
            player->unkC0.integer = 0;
            player->unkC4.fp = 0.0f;
            player->unkC8.fp = 0.0f;
            player->unkCC.fp = func_80011528(0) % 360U;
            player->unkD0.integer = func_80011528(0) % 400U + 0x1F4;
            
            player->unkE0.fp = 0.01f;
            player->unkE4.integer = func_80011528(0) % 400U + 0x64;
            player->unk4 = 1;
            player->unkE8.fp = 0.0f; 
            break;
        case 1:
            if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < player->pos.y + 100.0f){
                player->pos.y -= 1.0f;
            }

            if(player->unkDC.integer == 0){
                player->unkD4.integer = func_80024CA0(0, idx, 400.0f);
                
                
                if(player->unkD4.integer != -1){
                    player2 = GET_PLAYER_PTR(player->unkD4.integer);
                    if(player->pos.y - 50.0f < player2->pos.y && player2->pos.y < (player->pos.y + 80.0f)){
                        player->unk4 = 2;
                        player->unkDC.integer = 0x190;
                    }
                }
            }

            player->unkE4.integer--;

            if(player->unkE4.integer <= 0){
                player->unkE4.integer = func_80011528(0) % 400U + 0x64;
                player->unkE0.fp *= -1.0f;
            }

            player->unkE8.fp += player->unkE0.fp;

            if(player->unkE8.fp > 0.5){
                player->unkE8.fp = 0.5;
            }
            if(player->unkE8.fp < -0.5){
                player->unkE8.fp = -0.5;
            }

            temp2 = func_80011528(0) % 12U - 6;
            
            if(temp2 > 0){
                player->unkBC.integer++;
            }            

            if(player->unkBC.integer >= 0x5B){
                player->unkBC.integer = 0;
                player->unkC0.integer = 0x5A;
                player->unkC4.fp = 2.0f;
            }

            if(player->unkC0.integer != 0){
                temp3 = player->unkC4.fp;
                player->unkC0.integer--;
            }
            else {
                temp3 = player->unkC4.fp;
                if((player->unkC4.fp) > 0.0f) {
                    player->unkC4.fp -= -0.002; 
                }
            }

             
            temp3 -= 0.05;
            func_80024FC8(idx, temp3, player->unkE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
            if(D_800F9910.unk1 != 0){
                if(player->unkC8.fp == 0.0f){
                    player->unkB8.fp = func_80074E68(player->unk28.y, func_80025C48(player->unkA8.fp - player->pos.z, player->unkA0.fp - player->pos.x));
                    player->unkC8.fp = player->unkB8.fp / (func_80011528(0) % 5U + 1);
                }

                player->pos.x = D_800F9910.unkC; 
                player->pos.y = D_800F9910.unk10;
                player->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
                func_8002513C(player);
            }
            break;
        case 2:
            temp = func_80074E68(player->unk28.y, func_800253B0(idx, player->unkD4.integer));

            if(temp < 5.0f && temp > -5.0f){
                player->unk4 = 3;
                player->unkD8.integer = 0xA;
            }

            player->unk28.y += temp * 0.2;
            temp3 = player->unkC4.fp;
            func_80024FC8(idx, temp3, player->unkE8.fp);
            func_800180F0(&D_800F9910, cdata.nextstg, 30.0f, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
            if(D_800F9910.unk1 != 0){
                if(player->unkC8.fp == 0.0f){
                    player->unkB8.fp = func_80074E68(player->unk28.y, func_80025C48(player->unkA8.fp - player->pos.z, player->unkA0.fp - player->pos.x));
                    player->unkC8.fp = player->unkB8.fp / (func_80011528(0) % 5U + 1);
                }

                player->pos.x = D_800F9910.unkC; 
                player->pos.y = D_800F9910.unk10;
                player->pos.z = D_800F9910.unk14;
            }
            else{
                func_8002507C(idx);
                func_8002513C(player);
            }
            break;
        case 3:
            player->unkD8.integer--;
            
            if(player->unkD8.integer <= 0){
                player->unkBC.integer = 0;
                player->unkC0.integer = 0xA;
                player->unkC4.fp = 4.0f;

                if(GET_PLAYER(player->unkD4.integer).pos.y + 25.0f < player->pos.y + 34.0f){
                    player->unkE0.fp = -0.01;
                    player->unkE8.fp *= 0.5;
                }
                else if(player->pos.y < GET_PLAYER(player->unkD4.integer).pos.y + 25.0f ){
                    player->unkE0.fp = 0.01;
                    player->unkE8.fp *= 0.5;                    
                }

                player->unk4 = 1;
            }
            
            break;
    }

        if(player->unkB4.integer & 6){
            if(player->unkB0.fp + player->unkA4.fp < player->pos.y){
                player->pos.y = player->unkB0.fp + player->unkA4.fp;
            }

            if(player->pos.y < player->unkA4.fp){
                player->pos.y = player->unkA4.fp;
            }
        }

        if(player->unkDC.integer != 0){
            player->unkDC.integer--;
        }

        player->unkD0.integer--;

        if(player->unkD0.integer <= 0){
            player->unkD0.integer = func_80011528(0) % 400U + 0x1F4;

            if(player->unkC8.fp == 0.0f){
                player->unkC8.fp = func_80011528(0) % 180U;
            }
        }

        player->unkCC.fp += 3.0f;

        NORM_ANGLE(player->unkCC.fp);

        if(player->unkC8.fp != 0.0f){
            player->unkC8.fp = func_80025374(idx, player->unkC8.fp, 0.05f);

            if(player->unkC8.fp < 10.0f && player->unkC8.fp > -10.0f){
                player->unkC8.fp = 0.0f;
            }
        }

        switch(player->unkB4.integer & 7){
            case 1:
                if(player->unkC8.fp == 0.0f){
                    player->unkC8.fp = player->unkB8.fp / (f32)(func_80011528(0) % 5U + 1);
                }
                break;
            case 2:
                if(player->unkE8.fp > 0.0f){
                    player->unkE8.fp *= 0.5;
                    player->unkE0.fp = -0.01;
                }
                break;
            case 4:
                
                if(player->unkE8.fp < 0.0f){
                    player->unkE8.fp *= 0.5;
                    player->unkE0.fp = 0.01;
                }
                break;
        
    }
}
