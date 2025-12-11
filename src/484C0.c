#include "484C0.h"

#include "13940.h"
#include "1D870.h"
#include "73660.h"
#include "23B20.h"
#include "3AA90.h"
#include "55270.h"
#include "9320.h"

#include "libc/math.h"
#include "global.h"

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

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

extern u8 D_800F38E1;
extern f32 D_80159170;

typedef struct D_800B5374_struct{
    s32 unk0;
    s32 unk4;
}D_800B5374_struct;

typedef struct D_800F9B08_struct{
    u8 unk0[0x4B8];
    u16 unk4B8;
    u8 unk4BA[0x382];
    u16 unk83C;
}D_800F9B08_struct; 

extern D_800F9B08_struct D_800F9B08;

extern D_800B5374_struct D_800B5374[];
extern D_800B5374_struct D_800B53BC[]; 
extern D_800B5374_struct D_800B53F4[];

extern u16 D_800F38EE;
extern s16 D_800B5370;
extern s16 D_800B5424; 

void func_800478C0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    s32 id = player->unk4;

    (void)"0water face: %f\n";
    (void)"1water face: %f\n";

    switch(id){
        case 0:
            player->unkAC.integer = 0;
            player->unk4 = 1U;
            break;
        case 1:
            id = 1;
            switch(player->unkA0.integer){
                case 0:
                case 1:
                case 3: 
                case 4:
                case 5:
                case 7:
                case 8:
                    player->unk4 = 450;
                    break;
                case 6:
                    if(D_800F38EE % 2U == id){ 
                        player->unkA0.integer = 7;
                    } 
                    
                    player->unk4 = 450;
                    break;
                case 2:
                    if(func_80076FA0(0x1A)){
                        player->unk4 = 400;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 400:
            player->unkA8.integer = 0;
            player->unk8C |= 0x10;
            player->unk4 = 401;
            break;
        case 401:
            if(temp < 30.0f){
                player->unk4 = 402;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 402: 
            if(!func_80012D40(D_800B5374[player->unkA0.integer].unk0, D_800B5374[player->unkA0.integer].unk4, 1)){
                p->unk8C &= ~0x4000;
                player->unkA8.integer++;

                if(player->unkA8.integer > 0){
                    player->unk4 = 404;
                }
                else{
                    player->unk4 = 403;
                }
            } 
            break;
        case 403:
            if(temp > 150.0f){
                player->unk4 = 401;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 404:
            D_800F05B8 = 1U;
            p->unk8C |= 0x4000;
            func_80025F18(2539.0f, 390.0f, 989.0f, 2443.0f, 371.0f, 1019.0f, 120.0f);
            player->unkA8.integer = 0x78; 
            player->unk4 = 405;
            break;
        case 405:
            player->unkA8.integer--;

            if(player->unkA8.integer <= 0 && func_80076FA0(0x1A)){
                id = func_80023644(8, 0x81, 2443.0f, 471.0f, 1019.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_PLAYER_PTR(id)->unk68 = 0x1A;
                    player->unkA8.integer = 0x78; 
                    player->unk4 = 406;
                } 
            }
            func_80026380();
            break;
        case 406:
            player->unkA8.integer--;

            if(player->unkA8.integer <= 0){
                D_800F05B8 = 0;
                p->unk8C &= ~0x4000;
                player->unk4 = 453;
            }
            break;
        case 450:
            player->unkA8.integer = 0;
            player->unk4 = 451;
            player->unk8C |= 0x10;
            break;
        case 451:
            if(temp < 30.0f){
                player->unk4 = 452;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B5374[player->unkA0.integer].unk0, D_800B5374[player->unkA0.integer].unk4, 1)){
                p->unk8C &= ~0x4000;
                player->unkA8.integer++;

                if(player->unkA8.integer >= 2){
                    player->unkA8.integer = 0;
                }
                player->unk4 = 453;
            } 
            break;            
        case 453:
            if(temp > 250.0f){
                player->unk4 = 451;

                switch(player->unkA0.integer){
                    case 0:
                    case 2:
                        player->unkA0.integer = 4;
                        break;
                    case 6:
                        player->unkA0.integer = 7;
                        break;
                }
            }
 
            if(player->unkA0.integer == 6){
                 D_800F9B08.unk4B8 &= ~1;
            }
            func_80025454(player, p, 1.0f);
            break;
        default:
            break;
    }

    func_80039FDC(idx, 25.0f);
}

void func_80047DB8(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    s32 temp2; 

    switch(player->unk4){
        case 0:
            player->unkA8.integer = 0;
            player->unk4 = 1;
            break;
        case 1:
            switch(player->unkA0.integer){
                case 0:
                case 3:
                case 5:
                    player->unk4 = 450;
                    break;
                case 1:
                    if((D_800B5370 & 1) != 1){
                        player->unk4 = 400;
                    }
                    else{
                        func_80025454(player, p, 1.0f);
                    }
                    break;
                case 2:
                    if((D_800B5370 & 4) != 4){
                        player->unk4 = 450;
                    }
                    else{
                        func_80025454(player, p, 1.0f);
                    }
                    break;
                case 4:
                    if((D_800B5370 & 2) != 2){
                        player->unk4 = 400;
                    }
                    else{
                        func_80025454(player, p, 1.0f);
                    }
                    break;
                
            }
            break;
        case 400:
            player->unkA4.integer = 0;
            player->unk8C |= 0x10;
            player->unk4 = 401;
            break;
        case 401:
            if(temp < 30.0f){
                player->unk4 = 402;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 402:
            if(!func_80012D40(D_800B53BC[player->unkA0.integer].unk0, D_800B53BC[player->unkA0.integer].unk4, 1)){
                player->unkA4.integer++;

                if(player->unkA4.integer >= 2){
                    player->unkA4.integer = 0;
                }
                player->unk4 = 404;
            } 
            break;  
        case 404:
            D_800F05B8 = 1;
            p->unk8C |= 0x4000;
            
            switch(player->unkA0.integer){
                case 1:
                    func_80025F18(-1535.0f, -1006.0f, -621.0f, -1435.0f, -1079.0f, -611.0f, 120.0f);
                    break;
                case 4:
                    func_80025F18(1351.0f, 271.0f, 2130.0f, 1428.0f, 211.0f, 2104.0f, 120.0f);
                    break;
            }

            player->unkA4.integer = 0x78;
            player->unk4 = 405;
            break;
        case 405:
            player->unkA4.integer--;

            if(player->unkA4.integer <= 0){
                switch(player->unkA0.integer){
                    case 1:
                        if(func_80076FA0(0x23)){
                            temp2 = func_80023644(8, 0x81, -1435.0f, -999.0f, -621.0f, 0.0f, 180.0f, 0.0f);

                            if(temp2 != -1){
                                GET_PLAYER_PTR(temp2)->unk68 = 0x23; 
                                D_800B5370 |= 1;
                                player->unkA4.integer = 0x78;
                                player->unk4 = 406;
                            }
                        }
                        break;
                    case 4:
                        if(func_80076FA0(0x39)){
                            temp2 = func_80023644(8, 0x81, 1453.0f, 300.0f, 2107.0f, 0.0f, 225.0f, 0.0f);

                            if(temp2 != -1){
                                GET_PLAYER_PTR(temp2)->unk68 = 0x39; 
                                player->unkA4.integer = 0x78;
                                D_800B5370 |= 2;
                                player->unk4 = 406;                
                            }
                        }
                        break;
                }
            }

            func_80026380();
            
            break;
        case 406:
            player->unkA4.integer--;

            if(player->unkA4.integer <= 0){
                D_800F05B8 = 0;
                p->unk8C &= ~0x4000;
                player->unk4 = 453;
            }
            break;
        case 450:
            player->unkA4.integer = 0;
            player->unk8C |= 0x10;
            player->unk4 = 451;
            break;
        case 451:
            if(temp < 30.0f){
                player->unk4 = 452;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B53BC[player->unkA0.integer].unk0, D_800B53BC[player->unkA0.integer].unk4, 1)){
                p->unk8C &= ~0x4000;
                player->unkA4.integer++;

                if(player->unkA4.integer >= 2){
                    player->unkA4.integer = 0;
                }

                player->unk4 = 453;
            }
            break;
        case 453:
            if(temp > 250.0f){
                player->unk4 = 451;
            }
            
            if(player->unkA0.integer == 4){
                player->unkA0.integer = 5;
            }
            if(player->unkA0.integer == 1){
                player->unkA0.integer = 6;
            }

            func_80025454(player, p, 1.0f);
            
            break;
        case 455:
            break;
    }

    func_80039FDC(idx, 25.0f);
}

void func_800483BC(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    s32 pad;
    s32 pad2;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    s32 temp2;

    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x1E;
            func_80022F48(idx, 0);
            player->unkA8.integer = 0;
            player->unk4 = 1;
            break;
        case 1:
            switch(player->unkA0.integer){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    player->unk4 = 450;
                    break;
                case 6:
                    player->unk4 = 400;
                    break;
            }
            break;
        case 400:
            break;
        case 450:
            player->unkA4.integer = 0;
            player->unk8C |= 0x10;
            player->unk4 = 451;
            break;
        case 451:
            if(temp < 30.0f){
                player->unk4 = 452;
            }
            func_80025454(player, p, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B53F4[player->unkA0.integer].unk0, D_800B53F4[player->unkA0.integer].unk4, 1U)){
                p->unk8C &= ~0x4000;
                player->unkA4.integer++;

                if(player->unkA4.integer >= 2){
                    player->unkA4.integer = 0;
                }

                player->unk4 = 453;
            }
            break;
        case 453:
            if(player->unkA0.integer == 4){
                D_800F9B08.unk83C &= ~1;
                player->unk4 = 455; 
            }

            if(player->unkA0.integer == 0){
                temp2 = func_80023644(8, 0x69, -2338.0f, -117.0f, -960.0f, 0.0f, 180.0f, 0.0f);

                if(temp2 != -1){
                    GET_PLAYER_PTR(temp2)->unkA0.integer = 4;
                    D_800B5424 |= 1;
                }

                player->unk4 = 455;
            }

            if(temp > 250.0f){
                player->unk4 = 451;
            }

            func_80025454(player, p, 5.0f);
            break;
        case 454:
            break;
        case 455:
            func_80025454(player, p, 5.0f);
            break;
    }
    
    func_80039FDC(idx, 25.0f);
}

void func_800486B4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);

    switch(player->unk4){
        case 0:
            player->unkD4.fp = player->unkB4.fp;
            player->unkD8.fp = player->unkB8.fp;
            player->unkDC.fp = player->unkBC.fp;
            
            player->unkC0.fp = 5.0f;
            player->unkC4.fp = 2.0f;
            player->unkC8.fp = 0.1f;
            player->unkCC.fp = 8.0f;
            player->unkD0.fp = 60.0f;



            player->unk4E = 2;
            player->unk6C = 0x24;
            
            func_80022F48(idx, 1);

            player->unk4 = 1;
            break;
        case 1:
            func_80021B90(idx);

            if(temp < 300.0f){
                player->unk4 = 2;
            }
            break;
        case 2:
            player->unk58 *= 0.97;
            player->unk60 *= 0.97;

            func_800259B4(player, p->pos.y, 4.0f, 0.5f);

            if(player->unk58 < 0.1 && player->unk60 < 0.1){
                player->unk4 = 3;
            }

            func_80025454(player, p, 16.0f);
            func_8002507C(idx);
            break;
        case 3:
            func_80024FC8(idx, 6.0f, 0.0f);
            player->unkE0.integer = 0x28;
            player->unk4 = 4;
            break;
        case 4:
            player->unkE0.integer--;

            if(player->unkE0.integer <= 0){
                player->unk4 = 1;
            }

            if(player->unkE0.integer < 0x14){
                player->unk58 *= 0.99;
                player->unk60 *= 0.99;
            }

            func_8002507C(idx);
            break;
    }
}

void func_80048970(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);

    switch(player->unk4){
        case 0:
            if(player->unkA0.integer == 1){
                player->unk74 = 0xA;
                
                player->unk90.x = 3.0f;
                player->unk90.y = 3.0f;
                player->unk90.z = 3.0f;
                
            }

            player->unk8 = 0x43E;
            player->unk4E = 2;
            player->unk6C = 0x25;
            func_80022F48(idx, 2);
            player->unkA0.integer = 0x14;
            player->unk4 = 10;
            break;
        case 10:
            if(temp < 50.0f){
                player->unkA4.fp = 2.0f;
                player->unkA0.integer = 0x28;
                func_80008E10(0x55, 2, idx);
                player->unk4 = 11;
            }
            break;
        case 11:
            player->unkA0.integer--;
            
            if(player->unkA0.integer <= 0){
                player->unk8 = 0;
                func_80022F48(idx, 0);
                player->unk4 = 12;
            }

            func_80025454(player, p, 5.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, player->unkA4.fp);
            player->unkA4.fp -= D_80159170 * 0.25;
            func_80059760(player);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                player->unkA0.integer = 10;
                player->unk8 = 0x43E;
                func_80022F48(idx, 2);
                player->unk4 = 13;
            }
            break;
        case 13:
            player->unkA0.integer--;

            if(player->unkA0.integer <= 0){
                player->unk4 = 10;
            }
            break;
    }

}
