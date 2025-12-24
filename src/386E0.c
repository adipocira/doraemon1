#include "386E0.h"

#include "11F10.h"
#include "13940.h"
#include "15F60.h"
#include "23B20.h"
#include "29980.h"
#include "73660.h"
#include "89D30.h"
#include "6FA0.h"
#include "9320.h"
#include "7FC0.h"
#include "B4E0.h"

#include "global.h"
#include "libc/math.h"

extern f32 D_80159170;
extern s16 D_80141CAA;

extern s16 D_802BDE50;
extern s16 D_802BDE52;
extern s16 D_802BDE54;
extern s16 D_802BDE56;

extern s16 D_800F0680;

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

typedef struct D_800E6B20_struct {
    s16 unk0;
    s32 unk4;
    u8 unk8[0xE];
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B[0x5];
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26[0x3];
    u8 unk29;
    u8 unk2A[0x655D];
    u8 unk6587;
} D_800E6B20_struct;

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

extern D_800E6B20_struct D_800E6B20;

extern u8 D_802BDB7C[];

extern u8 D_800F38E1;

typedef struct D_800F0588_struct{
    u8 unk0[0x1B];
    u8 unk1B;
    s8 unk1C;
    s8 unk1D;
    u8 unk1E[0x84];
    s16 unkA2;
}D_800F0588_struct;

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x24];
}D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

typedef struct D_801414A8_struct {
    u8 unk0[0x30];
    f32 unk30;
    u8 unk34[0x4];
    s32 unk38;
}D_801414A8_struct;

extern D_801414A8_struct* D_801414A8;

extern D_800F0588_struct D_800F0588;

extern u8 D_800F0630;

#define D_800E6B20_2022_sets(arg1, arg2) D_800E6B20.unk20 = (arg1);\
D_800E6B20.unk22 = (arg2)\

void func_80037AE0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad;
    s16 temp1;
    s16 temp;

    switch(player->unk4){
        case 0:
            player->unk8C |= 0x10;
            player->unkA0.fp = player->unk90.x;
            player->unk90.x = player->unk90.y = player->unk90.z = player->unk90.x * 0.1;
            player->unk5C = 2.5f;
            player->unkA4.fp = 0.0f;
            player->unkA8.integer = 0;
            player->unkAC.fp = D_80159170 / 4;
            player->unkB0.integer = 3;
            player->unk4 = 1;
            break;
        default:
            break;
        case 1:
            player->unkA4.fp += 1.0f;
            player->unk90.x = player->unk90.y = player->unk90.z = (player->unkA4.fp * player->unkA0.fp) * 0.1;

            if(player->unkA4.fp == 10.0f){
                player->unk8C &= ~0x10;
                player->unkA4.fp = 720.0f;
                player->unk4 = 2;
            }
            break;
        case 2:
            if(player->unkA4.fp == 0.0f){
                player->unk4 = 3;
                player->unkA4.fp = 30.0f;
            }
            else{
                player->unkA4.fp -= 1.0f;
            }
            break;
        case 3:
            player->unkA4.fp -= 1.0f;

            if(player->unkA4.fp == 0.0f){
                func_80023FCC(idx);
                return;
            }
            
            player->unk90.x = player->unk90.y = player->unk90.z = (player->unkA4.fp * player->unkA0.fp) * (0.1/3.0);
            
            break;
    }

    temp = player->unk48;
    if(temp == 0x33 || temp == 0x24 || temp == 0x38){
        player->unk28.y = func_8000ADE0(player->unk28.y + 1.0);
    } 

    temp1 = D_80141CB0[idx].unk0;
    if(temp1 != -1){
        switch(temp){
            case 0x15:
                func_80008C6C(D_802BDE50, 0);
                cdata.unk22++;
                func_80022F20(idx, func_8002CF48);
                break;
            case 0x16:
                func_80008C6C(D_802BDE52, 0);
                GET_PLAYER_PTR(temp1)->unk74 += 0x32;

                if(GET_PLAYER_PTR(temp1)->unk74 >= 0xFB){
                    GET_PLAYER_PTR(temp1)->unk74 = 0xFA;
                }
                func_80022F20(idx, func_80039000);
                
                break;
            case 0x33:
                cdata.unk28 |= 0x40;

                if(cdata.unk70 == 0){
                    func_80038F4C();
                }
                cdata.unk77 = 0;
                cdata.unk70 = 0x384;                
                cdata.unk76 = cdata.unk77;
                func_80022F20(idx, func_80039000);
                
                player->unk8C |= 0x1000;
                player->unkDC.integer = temp1;
                break;
            case 0x24:
                cdata.unk28 |= 0x80;
                if (cdata.unk6E == 0) {
                    cdata.unk74 = D_800F0680;
                }
                cdata.unk6E = 0x4B0;
                
                func_800073C0(0x1F, 0);
                func_80022F20(idx, func_80039000);
                
                player->unk8C |= 0x1000;
                player->unkDC.integer = temp1;
                break;
            case 0x38:
                cdata.unk28 |= 0x20;

                func_80008C6C(D_802BDE54, 0);
                player->unkDC.integer = temp1;
                func_80022F20(idx, func_80039000);
                player->unk8C |= 0x1000;
                break;
            case 0x42:
                cdata.unk28 |= 0x40000000;
                cdata.unk24++;
                func_80008C6C(D_802BDE56, 0);
                func_80022F20(idx, func_80039000);
                break;
            default:
                func_80023FCC(idx);
                break;
        }
    }

    if(player->unkA8.integer != 0){
        return;
    }

    func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unk5C);

    if(D_800F9910.unk0 != 0){    
        if(player->unkB0.integer != 0){
            player->unkB0.integer--;
            player->unk5C *= -0.5;
        }
        else{
            player->unkA8.integer = 1;
        }
    }
    else{
        player->pos.y += player->unk5C;
        player->unk5C -= player->unkAC.fp;
    }
}


void func_800380BC(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s16 temp;

    if (player->unk4 == 0){
        player->unk28.y = func_8000ADE0(player->unk28.y + 1.0);
        temp = D_80141CB0[idx].unk0;
        if(temp != -1){
            switch (player->unk48) {
                case 0x33:
                    cdata.unk28 |= 0x40; 

                    if (cdata.unk70 == 0) {
                        func_80038F4C();
                    }
                    cdata.unk77 = 0;

                    cdata.unk70 = 0x384;
                    cdata.unk76 = cdata.unk77;
                    break;
                case 0x24:
                    cdata.unk28 |= 0x80;
                    if (cdata.unk6E == 0) {
                        cdata.unk74 = D_800F0680;
                    }
                    cdata.unk6E = 0x4B0;
                
                    func_800073C0(0x1F, 0);
                    break;
                default:
                    func_80023FCC(idx);
                    break;
            }
            func_80022F20(idx, func_80039000);
            player->unk8C |= 0x1000;
            player->unkDC.integer = temp;
        }
    }
}


void func_80038224(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad;
    s16 temp;

    switch(player->unk4){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);
            player->unk4 = 1;
            player->unk28.z = 45.0f;
            break;
        case 1:
            player->unk28.y = func_8000ADE0(player->unk28.y + 1.0);
            temp = D_80141CB0[idx].unk0;

            if(temp != -1){
                player->unkA0.integer = temp;
                D_800E6B20_2022_sets(0x20, 0xB0);

                func_800073C0(0x25, 1);
                func_80076F2C(player->unk48);
                func_800894B8(0x1E, 0xAE);
                
                func_800778C0(D_802BDB7C[player->unk48 - 0x14], 1, func_80077050());
                func_80076B64(temp);
                player->unk4 = 2;
            }
            break;
        case 2:
            if(func_80012D40(0x13, 0, 0) == 0){
                func_80089A4C();
                GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->unk8C &= ~0x4000;
                func_80023FCC(idx);
            }
            break;
    }
}

void func_800383E4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s16 id;

    switch(player->unk4){
        case 0:
            id = D_80141CB0[idx].unk0;
            
            if(id != -1){
                player->unkA0.integer = id;
                D_800E69C0.unkD &= ~1;
                D_800E6B20_2022_sets(0x20, 0xB0);
                
                func_800073C0(0x25, 1);
                func_80076F2C(player->unk48);
                func_800894B8(0x1E, 0xAE);
                func_800778C0(D_802BDB7C[player->unk48 - 0x14], 3, 6);

                player->unk4 = 1;
            }
            break;
        case 1:
            if(func_80012D40(0x13, 0, 0) == 0){
                func_80089A4C();
                GET_PLAYER_PTR(D_80159178->unk48[cdata.unk41].unk0)->unk8C &= ~0x4000;
                
                D_800E6B20_2022_sets(0x4B, 0xB7);\
                D_800E6B20.unk19 = cdata.unk6A;\
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;\

                func_80022F20(idx, func_80039000);
                player->unk8C |= 0x1000;
                D_800E69C0.unkD |= 1;
            }
            break;
    }
}

void func_800385C0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 temp;
    s16 temp2 = D_80159178->unk48[D_800F38E1].unk0;
    s16 pad;
    s16 temp1;
    s16 pad1;
    s32 pad2;
    
    player->unk28.y = func_8000ADE0(player->unk28.y + 1.0);

    if(player->unk48 == 0x1C){
        GET_PLAYER_PTR(player->unkB4.integer)->unk28.y = player->unk28.y;
    }

    temp1 = player->unk48 - 0x14;

    switch(player->unk4){
        case 0:
            player->unkA0.integer = 0x3C;
            
            if(D_802BDB7C[player->unk48 - 0x14] >= 5){
                func_80008C6C(0x9E, 0);
            }
            else{
                func_80008C6C(0x9F, 0);
            }

            player->unk4 = 5;
            break;
        case 5:
            player->unkA0.integer--;

            if(player->unkA0.integer == 0){
                player->unk4 = 10;
            }

            func_80024874(idx, ((0x3C - player->unkA0.integer) / 60.0f) * player->unkA4.fp);

            player->pos.y += 0.8;
            player->unk28.y = func_8000ADE0(player->unk28.y + 17.0);

            if(player->unk48 == 0x1C){
                GET_PLAYER_PTR(player->unkB4.integer)->unk28.y = player->unk28.y;
                GET_PLAYER_PTR(player->unkB4.integer)->pos.y = player->pos.y;

                func_80024874(player->unkB4.integer, player->unk90.x);
            }
            break;
        
        case 10:
            D_800E69C0.unkD &= ~1;
            D_800E6B20_2022_sets(0x20, 0xB0);

            func_80076F2C(player->unk48);
            func_800894B8(0x1E, 0xAE);

            if(D_802BDB7C[temp1] < 5){
                func_800778C0(D_802BDB7C[temp1] , 1, func_80077050());
                func_80076B64(temp2);
            }
            else{
                if(D_802BDB7C[temp1] >= 0x2D){
                    temp = 3;
                }
                else{
                    if(D_802BDB7C[temp1] >= 0x20){
                        temp = 2;
                    }
                    else{
                        temp = 1;
                    }
                }

                func_800778C0(D_802BDB7C[temp1], temp, 6U);
            }

            player->unk4 = 15;
                
            break;
        case 15:
            temp = (D_802BDB7C[temp1] >= 0x20 ? 1 : 0) * 1;
                
            if(func_80012D40(0x13, temp, 0) == 0){
                func_80089A4C();
                GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->unk8C &= ~0x4000;
                func_80023FCC(D_800F0588.unkA2);
                
                D_800E6B20_2022_sets(0x4B, 0xB7);
                D_800E6B20.unk19 = cdata.unk6A;
                
                D_800E6B20.unk16 = 1;\
                D_800E6B20.unk24 = 0xB;\
                D_800E6B20.unk25 = 4;\
                D_800E6B20.unk29 = 5;
                
                D_800F0630 = D_800F0588.unk1C;
                D_800F0588.unk1B = 0;
                D_800F0588.unk1D = 1;

                func_80022F20(idx, func_80039000);

                player->unk8C |= 0x1000;

                if(player->unkC8.integer & 4){
                    func_800770FC();
                }
                if(player->unk48 == 0x1C){
                    GET_PLAYER_PTR(player->unkB4.integer)->unk80 = func_80039000;
                }
                
                D_800E69C0.unkD |= 1;
            }
            break;
    }
}

void func_80038A0C(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp;
    s16 temp2;

    switch(player->unk4){
        case 0:
            player->unk4 = 1;
            player->unkA0.fp = player->pos.y;
            player->unkA4.fp = 0.0f;
            GET_PLAYER_PTR(player->unk70)->unk80 = NULL;
            break;
        case 1:
            temp = func_8000ADE0(player->unkA4.fp + 5.0f);
            player->unkA4.fp = temp;
            player->pos.y = sinf(RAD2DEG_ALT(temp)) * 8.0f + player->unkA0.fp;
            break;
    }
    player->unk28.y = func_8000ADE0(player->unk28.y + 3.0);

    temp2 = D_80141CB0[idx].unk0;
    
    if(temp2 != -1){
        GET_PLAYER_PTR(D_80159178->unk48[cdata.unk41].unk0)->unkE0.fp += 0.5;
            
        if(GET_PLAYER_PTR(D_80159178->unk48[cdata.unk41].unk0)->unkE0.fp > 24.0f){
            GET_PLAYER_PTR(D_80159178->unk48[cdata.unk41].unk0)->unkE0.fp = 24.0f;
        }

        (s16)GET_PLAYER_PTR(D_80159178->unk48[cdata.unk41].unk0)->unkD4.integer = 0xC;

        if(1);

        cdata.unk28 |= 0x20;

        func_80008C6C(D_802BDE54, 0);
        func_80023FCC(idx);
    }
    
}


void func_80038BDC(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            func_8002524C(idx, 0.0f, 0.0f, 0.0f);

            player->unkB0.integer = 1;
            player->unkB4.integer = 3;
            player->unk8C |= 0x10;
            player->unk4 = 1;
            player->unkA0.fp = player->unk90.x;
            player->unk90.x = 0.01f;
            player->unk90.y = 0.01f;
            player->unkA8.fp = 3.0f;
            break;
        case 1:
            player->unk90.x += 0.01;
            player->unk90.y += 0.01;

            if(player->unkA0.fp <= player->unk90.x){
                player->unkA4.integer = 0x384;
                player->unk8C &= ~0x10;
                player->unk4 = 2;
            }
            break;
        case 2:
            if(D_80141CB0[idx].unk0 != -1){
                func_80008C6C(0xDB, 0);
                cdata.unk22++;
                func_80022F20(idx, func_8002CF48);
            }
            else{
                player->unkA4.integer--;

                if(player->unkA4.integer <= 0){
                    player->unk4 = 3;
                }
            }
            break;
        case 3:
            player->unk90.x -= 0.01;
            player->unk90.y -= 0.01;

            if(player->unk90.x < 0.02){
                func_80023FCC(idx);
            }
            break;
    }

    if(player->unkB0.integer != 0){
        player->unkA8.fp -= D_80159170 / (4.0f * 1);

        if(((&D_801B58F8[cdata.nextstg])->unk4 + 16.0f) < player->pos.y){
            player->unkAC.fp = player->unkA8.fp;
        }
        else{
            player->unkAC.fp = player->unkA8.fp / 2;

            if(player->unkAC.fp < -5.0f){
                player->unkAC.fp = -5.0f;
            } 
        }

        func_8002524C(idx, 0.0f, player->unkAC.fp, 0.0f);
        func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unkAC.fp);
    
        if(D_800F9910.unk0 != 0){
            if(player->unkB4.integer != 0){
                if(player->unkA8.fp < 0.0f){
                    player->unkB4.integer--;
                    player->unkA8.fp = -player->unkA8.fp * 0.5;
                }
            }
            else{
                player->unkB0.integer = 0;
            }
        }
        else{
            func_8002507C(idx);
        }
    }
}


void func_80038F4C(void){
    u16 i;
    Player* p = GET_PLAYER_PTR(0x14); 

    D_80141CAA = TRUE;
    
    for(i = 0x14; i < 0x28; i++){
        if(p->unk0 != 0){
            if(!(p->unk8C & 0x8000)){
                p->unk8C |= 0x84000;
            }
        }
        p++;
    }
}

void func_80038FA8(){
    u16 i;
    Player* p = GET_PLAYER_PTR(0x14); 

    D_80141CAA = FALSE;
    
    for(i = 0x14; i < 0x28; i++){
        if(p->unk0 != 0){
            if(!(p->unk8C & 0x8000)){
                p->unk8C &= ~0x84000;
            }
        }
        p++;
    }
}

void func_80039000(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(player->unkDC.integer);

    player->unk90.x = player->unk90.y = player->unk90.z = player->unk90.x * 0.93;

    if(player->unk90.x < 0.05){
        func_80023FCC(idx);
    }
    else{
        player->pos.x += (p->pos.x - player->pos.x) * 0.2;
        player->pos.y += (p->pos.y + 20.0f - player->pos.y) * 0.2;
        player->pos.z += (p->pos.z - player->pos.z) * 0.2;
        
    }
}

s32 func_80039110(){
    u16 count = 0;
    u16 i;

    for(i = 0; i < 32; i++){
        if(cdata.unk28 & (1ULL << i)){
            count++;
        }
    }

    return count;
}

f32 func_800391A4(s16 idx1, s16 idx2, Vec3f* pos){
    Player* player = GET_PLAYER_PTR(idx2);
    Player* p = GET_PLAYER_PTR(idx1);
    f32 x;
    f32 y;
    f32 z;

    if(player->unk0 == 0){
        return 0.0f;
    }

    x = player->pos.x + pos->x - p->pos.x;
    y = player->pos.y + pos->y - p->pos.y;
    z = player->pos.z + pos->z - p->pos.z;
    
    return sqrtf(SQ(x) + SQ(y) + SQ(z));
}

void func_80039254(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 dist;
    f32 r = RAD2DEG_ALT(player->unk28.y);
    f32 r2;
    Vec3f pos;
    s16 id;
    f32 temp2;
    Player* p2;
    f32 temp;
    u8 temp3;
    f32 temp4;

    pos.x = sinf(r) * 8.0f;
    pos.y = 0.0f;
    pos.z = cosf(r) * 8.0f;

    dist = func_800391A4(idx, D_80159178->unk48[D_800F38E1].unk0, &pos);

    r = func_80025C48((p->pos.z - player->pos.z) + pos.z, (p->pos.x - player->pos.x) + pos.x);
    r2 = RAD2DEG_ALT(r);
 
    if(dist < 30.0f && !(p->unk8C & 0x4000)){
        p->unkAC.fp += sinf(r2) * (31.0f - dist);
        p->unkB4.fp += cosf(r2) * (31.0f - dist);   
    }

    switch(player->unk4){
        case 0:
            if( func_80076FA0(player->unk68) != 0){
                (&D_801414A8)[player->unk38]->unk30 = 90.0f;
            }
            else{
                (&D_801414A8)[player->unk38]->unk30 = 0.0f;
                player->unk68 = -1;
            }

            player->unkA8.integer = 0;
            player->unk5C = 0.0f;
            player->unkAC.fp = D_80159170 / (2.0f * 1.0f);
            player->unkB0.integer = 0;
            player->unk4 = 3;
        case 3:
            func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unk5C);
            
            if(D_800F9910.unk0 != 0){
                player->pos.y = D_800F9910.unk10 + 1.0;

                if(player->unkB0.integer >= 0xB){
                    func_80008C6C(7, 0);
                }
                if(player->unk68 == -1){
                    player->unk4 = 15;
                }
                else{
                    player->unk4 = 5;
                }
            }
            else{
                player->unkB0.integer++;
                player->pos.y += player->unk5C;
                player->unk5C -= player->unkAC.fp;
            }
            break;
        case 5:
            if(player->unkC8.integer & 2){
                player->unk4 = 8;
            }
            if(dist < 45.0f){ 
                if(func_80074E68(player->unk28.y, r) > 0.0f){
                    temp = func_80074E68(player->unk28.y, r);
                }
                else{
                    temp = -func_80074E68(player->unk28.y, r);
                }
                if(temp < 25.0f){
                    temp = func_80074E68(player->unk28.y, func_8000ADE0(p->unk28.y + 180.0f)) > 0.0f ? \
                         func_80074E68(player->unk28.y, func_8000ADE0(p->unk28.y + 180.0f)) : \
                        -func_80074E68(player->unk28.y, func_8000ADE0(p->unk28.y + 180.0f));

                    if(temp < 25.0f && func_80077548() != 0){
                        temp2 = RAD2DEG_ALT(func_8000ADE0(player->unk28.y + 45.0f));
                        D_800F0588.unk1C = D_800F0630;
                        D_800F0588.unk1B = 1;
                        D_800F0588.unk1D = 0;
                        D_800F0630 = 0xC;
                        D_800F0588.unkA2 = func_80023498(8, 0x1C2, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);

                        func_80022F20(D_800F0588.unkA2, func_800064F0);
                        p2 = GET_PLAYER_PTR(D_800F0588.unkA2); 
                        
                        p2->unkA4.integer = idx;
                        p2->unkA0.integer = idx;
                        
                        p2->unkB4.fp = sinf(temp2) * 110.0f;
                        p2->unkB8.fp = 25.0f;
                        p2->unkBC.fp = cosf(temp2) * 110.0f;

                        func_80008C6C(0x55, 2);

                        player->unk4 = 10;
                    } 
                }
            }
            break;
        case 8:
            D_800F0588.unk1C = D_800F0630;
            D_800F0588.unk1D = 0;
            D_800F0588.unk1B = 1;
            D_800F0630 = 0xC;
            D_800F0588.unkA2 = func_80023498(8, 0x1C2, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);

            func_80022F20(D_800F0588.unkA2, func_800064F0);
            p2 = GET_PLAYER_PTR(D_800F0588.unkA2);   

            if(cdata.nextstg == 0xA){
                p2->unkA4.integer = idx;
                p2->unkA0.integer = idx;
                p2->unkB8.fp = 300.0f;
                p2->unkBC.fp = -300.0f;
            }
            else{
                p2->unkA4.integer = idx;
                p2->unkA0.integer = idx;
                p2->unkB8.fp = 50.0f;
                p2->unkBC.fp = -120.0f;                
            }

            func_80008C6C(0x55, 2);
            
            player->unk4 = 10;
            break;
        case 10:
            temp4 = (&D_801414A8)[player->unk38]->unk30 = func_8000ADE0((&D_801414A8)[player->unk38]->unk30 - 2.0f);

            if(temp4 == 0.0f){
                id = func_80023498(1, player->unk68, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f); 
                    
                if(player->unk68 == 0x1C){
                    GET_PLAYER_PTR(id)->unkB4.integer = func_80023498(1, 0x1D, player->pos.x, player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);
                    func_80024874(GET_PLAYER_PTR(id)->unkB4.integer, 0.0f);
                }

                func_80022F20(id, func_800385C0);
                p = GET_PLAYER_PTR(id);
                
                p->unkC8.integer = player->unkC8.integer;
                p->unkA4.fp = p->unk90.x;
  
                GET_PLAYER_PTR(D_800F0588.unkA2)->unkA0.integer = id;

                func_80024874(id, 0.0f); 
                
                
                player->unk4 = 15;
            }
            break;
        case 15: 
            if(player->unkC8.integer % 2U){
                player->unkA4.integer = 0x3C;
                player->unk4 = 20;
            }
            else{
                player->unk4 = 99;
            }
            break;
        case 20:
            player->unkA4.integer--;

            if(player->unkA4.integer != 0){
                func_80023FCC(idx);
            }
            else{
                temp = 0.95 * player->unk90.x;
                
                player->unk90.x = player->unk90.y = player->unk90.z = temp;
            }
            break;
        case 99:
            break;
    }
}


void func_80039B1C(s32 arg0){

}

void func_80039B24(s32 arg0){

}

void func_80039B2C(s32 arg0){

}

void func_80039B34(s32 arg0){

}

void func_80039B3C(s32 arg0){

}

void func_80039B44(s32 arg0){

}

void func_80039B4C(s32 arg0){

}

void func_80039B54(s32 arg0){

}

void func_80039B5C(s32 arg0){

}

void func_80039B64(s32 arg0){

}

void func_80039B6C(s32 arg0){

}

void func_80039B74(s32 arg0){

}

void func_80039B7C(s32 arg0){

}

void func_80039B84(s32 arg0){

}

void func_80039B8C(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unkA0.fp = (func_80011528(0) % 7U) + 2.5;
            player->unkA4.fp = (func_80011528(0) % 2U) + 0.5;
            player->unkA8.integer = 0x384;
            player->unk28.y = func_80011528(0) % 360U;

            func_80024FC8(idx, player->unkA4.fp, player->unkA0.fp);
            func_8002507C(idx);
            player->unk4 = 1;
            break;
        case 1:
            player->unkA8.integer--;

            if(player->unkA8.integer <= 0){
                player->unk4 = 2;
            }

            player->unkA0.fp -= D_80159170 / (4.0f * 1);

            func_80024FC8(idx, player->unkA4.fp, player->unkA0.fp);
            func_8001B734(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unkA0.fp);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0xDA, 3, idx);
                func_80022F20(idx, func_8002CF48);
                return;
            }
            
            func_8002507C(idx);
            
            break;
        case 2:
            player->unk90.x -= 0.01;
            player->unk90.y -= 0.01;

            if(player->unk90.x < 0.02){
                func_80023FCC(idx);
            }
            break;
    }

    if(D_80141CB0[idx].unk0 != -1){
        func_80008C6C(0xDA, 0);
        cdata.unk22++;
        func_80022F20(idx, func_8002CF48);
    }
}
