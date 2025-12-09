#include "44CC0.h"

#include "11F10.h"
#include "15F60.h"
#include "73660.h"
#include "23B20.h"
#include "29980.h"
#include "55270.h"
#include "684A0.h"
#include "9320.h"

#include "libc/math.h"
#include "global.h"

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
    u8 unk0[0x34];
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

void func_800440C0(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp;
    s16 temp1 = D_80159178->unk48[D_800F38E1].unk0;
    s16 temp2;
    s32 pad[3];
    f32 temp3; 
    
    switch(player->unk4){
        case 0:
            player->unkC0.integer = 2;
            player->unkC8.integer = 1;
            player->unk6C = 0x14;

            player->unkCC.fp = (player->unkA0.fp + player->pos.x) * 0.5;
            player->unkD0.fp = (player->unkA4.fp + player->pos.y) * 0.5;
            player->unkD4.fp = (player->unkA8.fp + player->pos.z) * 0.5;

            player->unkB4.fp = player->pos.x;
            player->unkB8.fp = player->pos.y;
            player->unkBC.fp = player->pos.z;

            player->unkE4.fp = player->unk90.x;
            player->unkE8.fp = player->unk90.y;
            player->unkEC.fp = player->unk90.z;

            func_80025AF4(player);  

            player->unk4 = 1;
            
            break;
        case 1:
            switch(player->unkC8.integer){
                case 0:
                    player->unkD8.fp = player->unkB4.fp;
                    player->unkDC.fp = player->unkB8.fp;
                    player->unkE0.fp = player->unkBC.fp;
                    
                    break;
                case 1:
                    player->unkD8.fp = player->unkA0.fp;
                    player->unkDC.fp = player->unkA4.fp;
                    player->unkE0.fp = player->unkA8.fp;
                    
                    break;
            }

            player->unkC4.integer = 0x1E;

            player->unk4 = 2;
            break;
        case 2:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                player->unk4E = 2;
                func_80022F48(idx, 1);
                player->unkC4.integer = 0x3C;
                player->unk4 = 3;
            }            

            func_800256CC(player, player->unkD8.fp, player->unkE0.fp, 10.0f);
            break;
        case 3:
            player->unkC4.integer--;
            temp3 = func_800253B0(idx, temp1);
            temp = func_80074E68(player->unk28.y, temp3);

            if((temp < 45.0f || temp > -45.0f) && func_80024CA0(0, idx, player->unkAC.fp) != -1 && player->unkC4.integer <= 0){
                player->unk28.y = temp3;
                func_80022F48(idx, 3);
                player->unkC4.integer = 0x29;
                player->unk4 = 0xA;
            }
            if(func_80024EA4(idx, player->unkD8.fp, player->unkDC.fp, player->unkE0.fp) < 50.0f){
                player->unkC4.integer = 0x8F;
                func_80022F48(idx, 0);
                player->unk4 = 4;
            }
            func_800256CC(player, player->unkD8.fp, player->unkE0.fp, 2.0f);
            func_80024FC8(idx, 2.0f, 0.0f);
            func_8002507C(idx);
            break;
        case 4:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                player->unk4E = 0;
                player->unkC8.integer = 1- player->unkC8.integer;
                func_80025AF4(player);
                player->unk4 = 1; 
            }
            break;
        case 10:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                player->unkC4.integer = 0x4C;
                func_80022F48(idx, 4);
                player->unk4 = 20; 
            }
            break;
        case 20:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                func_80022F48(idx, 2);
                player->unk4 = 30;
            }

            if(player->unkC4.integer == 50){
                temp2 = func_80023644(5, 0x140, player->pos.x, player->pos.y + 15.0f, player->pos.z, 0.0f, player->unk28.y, 0.0f);

                if(temp2 != -1){
                    func_80008E10(0x48, 2, idx);
                    func_80024FC8(temp2, 4.0f, 0.0f);
                    func_8002507C(temp2);
                    func_800242F0(idx, 4, 0xFFFF);    

                    player->unkC0.integer = 0;
                }
            }
            break;
        case 30:
            if((player->unkB0.fp < func_80024EA4(idx, player->unkCC.fp, player->unkD0.fp, player->unkD4.fp)) || D_80141CB0[idx].unk0 != -1){
                if(player->unkC0.integer == 0){
                    func_80022F48(idx, 5);
                    player->unkC4.integer = 0x63;
                    player->unk4 = 40;
                }
                else{
                    player->unk4E = 0;
                    player->unkC8.integer = 1 - player->unkC8.integer;
                    func_80025AF4(player);
                    player->unk4 = 1;
                }
            }

            func_80025454(player, GET_PLAYER_PTR(temp1), 8.0f);
            func_80024FC8(idx, 3.0f, 0.0f);
            func_8002507C(idx);
            break;
        case 40:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                player->unkC8.integer = 1 - player->unkC8.integer;
                player->unkC0.integer = 2;
                player->unk4E = 0;
                func_80025AF4(player);
                player->unk4 = 1;
            }

            if(player->unkC4.integer < 0xB){
                player->unkC0.integer = 1;
                func_80024348(idx, 4);
                func_800247E8(idx, 4, (10 - player->unkC4.integer) * 0.1);
            }
            break;
        case 50:
            player->unkC4.integer--;

            if(player->unkC4.integer <= 0){
                player->unk8B = 0xFF;
                player->unk4 = 51;
            }

            player->pos.y -= 3.0f;
            player->unk90.x *= 0.99;
            player->unk90.y *= 1.05;
            player->unk90.z *= 0.99;
            player->unk28.y += 30.0f;

            NORM_ANGLE(player->unk28.y);

            player->unk8B -= 8;
            
            break;
        case 51:
            player->unk4 = 52;
            player->pos.x = player->unkD8.fp;
            player->pos.y = player->unkDC.fp;
            player->pos.z = player->unkE0.fp;
            
            break;
        case 52:
            player->unk90.x *= 10.0f;
            player->unk90.y *= 0.05; 
            player->unk90.z *= 10.0f;
            player->unk4 = 53;
            
            break;
        case 53:
            player->unkC4.integer = 0x8F;
            player->unk90.x = player->unkE4.fp;
            player->unk90.y = player->unkE8.fp;
            player->unk90.z = player->unkEC.fp;
            func_80022F48(idx, 0);
            player->unk8C &= ~0x10;
            player->unk4 = 4;
            break; 
    }

    if(player->unk70 == -1){
        return;
    }

    if((GET_PLAYER_PTR(player->unk70)->unk8C & 8 || player->pos.y - GET_PLAYER_PTR(player->unk70)->pos.y > 30.0f) && player->unk4 < 50){
        player->unk8C |= 0x2010;
        player->unkC4.integer = 0x28;
        player->unk4 = 50;
    }
    else {
        f32 temp = GET_PLAYER_PTR(player->unk70)->pos.y + 5.0f;
        if(temp < player->pos.y){
            player->pos.y -= 1.0f;
        }
        else {
            player->pos.y = temp;
        }
    }
}

void func_80044930(s16 idx){
    s32 pad;
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unk4 = 1;
            player->unkA0.fp = 1.0f; 
        case 1:
            player->unkA0.fp -= 0.03;
            func_80024FC8(idx, 4.0f, player->unkA0.fp);

            func_80019F78(&D_800F9910, cdata.nextstg, player->pos.x, player->pos.y, player->pos.z, player->unk58, player->unk5C, player->unk60);
            if(D_800F9910.unk1 != 0){
                func_80023FCC(idx);
            }
            else{
                player->unk28.x += 40.0f;
 
                NORM_ANGLE(player->unk28.x);

                func_8002507C(idx);
            }
            break;
    } 
}

void func_80044ADC(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    f32 temp2 = func_80074E68(player->unk28.y, func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0));
    s16 temp3;

    switch(player->unk4){
        case 0:
            func_80024FC8(idx, 0.0f, -10.0f);
            func_80056894(player);

            if(D_800F9910.unk0 != 0){
                player->unk4E = 2;
                player->unk6C = 0x26;
                func_80022F48(idx, 2);
                player->unk4 = 1;
                player->unkB4.fp = player->unkA4.fp;
                player->unkC8.fp = 0.0f;
                
                player->unkB8.fp = player->unkA8.fp;
                player->unkC4.fp = 5.0f;
                
            }
            break;
        case 1:
            func_80022F48(idx, 2);
            player->unkBC.integer = 0x3C;
            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            player->unk4 = 2;
            break;
        case 2:
            if(player->unkC4.fp > 5.0f){
                player->unkC4.fp -= 1.0f;
            }

            player->unkBC.integer--; 
            
            if(player->unkBC.integer <= 0){
                player->unk4 = 3;
                player->unkC8.fp = 0.0f;
            }

            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            
            break;
        case 3:
            func_80022F48(idx, 4);
            player->unkBC.integer = 0x3C;
            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            player->unk4 = 4;            
            break;
        case 4:
            player->unkBC.integer--;

            if(player->unkBC.integer <= 0){
                player->unk4 = 5;
            }
            func_800256CC(player, player->unkB4.fp, player->unkB8.fp, 16.0f);
            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            break;
        case 5:
            func_80022F48(idx, 3);
            player->unkC0.fp = 0.0f;
            player->unkC8.fp = 0.0f;
            player->unkCC.fp = 0.0f; 
            player->unkD0.fp = func_80024EA4(idx, player->unkB4.fp, player->pos.y, player->unkB8.fp) * 0.3;
            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            player->unk4 = 6;
            break;
        case 6:
            if(player->unkC0.fp < 4.0f){
                player->unkC0.fp += 0.2;
            }

            if(player->unkC8.fp > -3.0f){
                player->unkC8.fp -= D_80159170 * 0.25; 
            }

            func_80024FC8(idx, player->unkC0.fp, player->unkC8.fp);

            player->unkD8.fp = player->pos.x;
            player->unkDC.fp = player->pos.z;

            func_80056894(player);
            func_8006846C(player, player->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);

            if(temp < 300.0f){
                func_80025454(player, p, 32.0f);

                if((temp < 100.0f) && temp2 < 20.0f && temp2 > -20.0f){
                    if(D_800F9910.unk0 != 0){
                        player->unk4 = 7;
                    }
                }
                else{
                    player->unkC0.fp *= 0.9;
                } 
            }
            else{
                func_800256CC(player, player->unkB4.fp, player->unkB8.fp, 16.0f);

                if(func_80024EA4(idx, player->unkB4.fp, player->pos.y, player->unkB8.fp) < 100.0f && D_800F9910.unk0 != 0){
                    player->unk4 = 7;
                }
                
            }

            if(player->unkC8.fp <= 3.0f && D_800F9910.unk0 != 0){
                if(player->unkC0.fp * 0.3 < player->unkC0.fp - sqrtf(SQ(player->pos.z - player->unkDC.fp) + SQ(player->pos.x - player->unkD8.fp))){
                    func_80008E10(0x45, 2, idx);
                    player->unkC8.fp = 5.0f;
                }
            }
            
            
            break;
        case 7:
            temp3 = func_80023644(6, 0x18A, player->pos.x, player->pos.y + 52.0f, player->pos.z, 0.0f, player->unk28.y, 0.0f);

            if(temp3 != -1){
                func_80008E10(0x58, 2, idx);
                func_80024874(temp3, 0.04f); 
                func_80022F20(temp3, func_800453B8);
                func_80024FC8(temp3, player->unkC0.fp, 2.0f);
            }

            func_80022F48(idx, 0);

            if(player->unkC8.fp > -3.0f){
                player->unkC8.fp -= D_80159170 * 0.25;
            }

            func_80024FC8(idx, player->unkC0.fp, player->unkC8.fp); 
            func_80056894(player);

            player->unkBC.integer = 0x33;
            player->unk4 = 8;
            
            break;
        case 8:
            player->unkBC.integer--;

            if(player->unkBC.integer <= 0){
                player->unk4 = 9;
            }

            if(player->unkBC.integer < 0x14){
                player->unk58 *= 0.96;
                player->unk60 *= 0.96;
            }

            if(player->unkC8.fp > -3.0f){
                player->unkC8.fp -= D_80159170 * 0.25;
            }

            player->unk5C = player->unkC8.fp;
            func_80056894(player);
            
            break;
        case 9:
            func_80022F48(idx, 1);

            if(player->unkC8.fp > -3.0f){
                player->unkC8.fp -= D_80159170 * 0.25;
            }
            
            player->unk5C = player->unkC8.fp;

            func_80056894(player);

            player->unkBC.integer = 0x45;
            player->unk4 = 10;
            break;
        case 10:
            if(player->unkC8.fp > -3.0f){
                player->unkC8.fp -= D_80159170 * 0.25;
            }
            
            player->unk5C = player->unkC8.fp;

            func_80056894(player);
            
            player->unkBC.integer--;

            if(player->unkBC.integer <= 0){
                player->unkA0.integer++;

                if(player->unkA0.integer >= 2){
                    player->unkA0.integer = 0;
                }

                switch(player->unkA0.integer){
                    case 0:
                        player->unkB4.fp = player->unkA4.fp;
                        player->unkB8.fp = player->unkA8.fp;
                        
                        break;
                    case 1:
                        player->unkB4.fp = player->unkAC.fp;
                        player->unkB8.fp = player->unkB0.fp;
                        
                        break;
                }

                player->unk4 = 1;
                player->unkC4.fp = 15.0f; 
            }
 
            break;
    }
    
}

void func_800453B8(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s32 pad;
    s16 temp;
    
    switch(player->unk4){
        case 0:
            player->unkA0.integer = 0x28;
            func_8006846C(player, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            player->unk4 = 1;
            break;
        case 1:
            player->unk5C -= D_80159170 * 0.25;
            func_80059760(player);

            if(D_800F9910.unk1 != 0){
                player->unkA0.integer--;

                if(player->unkA0.integer <= 0){
                    func_80023FCC(idx); 
                }

                if(!(player->unkA0.integer & 3)){
                    temp = func_80023644(6, 0x18A, player->pos.x, player->pos.y + 52.0f, player->pos.z, 0.0f, player->unk28.y, 0.0f); 

                    if(temp != -1){
                        func_80024874(temp, 0.04f);
                        func_80022F20(temp, func_80045568);                        
                    }
                }
            }

            func_8006846C(player, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            
            break;
    }
}

void func_80045568(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s16 id;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    switch(player->unk4){
        case 0:
            player->unkA0.integer = 0x1E;
            func_8006846C(player, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            player->unk4 = 1;
            break;
        case 1:
            player->unkA0.integer--;

            if(player->unkA0.integer <= 0){
                func_80023FCC(idx);
            }
            
            temp2 = func_80011528(0) % 20U - 10.0f;
            temp3 = func_80011528(0) % 20U - 10.0f;
            temp4 = func_80011528(0) % 20U - 10.0f;
            
            id = func_80023644(5, 0x18A, player->pos.x + temp2, player->pos.y + temp3, player->pos.z + temp4, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                GET_PLAYER_PTR(id)->unk8C |= 0x1020;
                func_80024874(id, 0.166f);
                func_80022F20(id, func_8002CB3C);
                func_80024FC8(id, 0.0f, 3.0f);
            }
            
            break;
        
    }
}

void func_80045794(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);

    switch(player->unk4){
        case 0:
            func_80024874(idx, 2.5f);
            player->unk8B = 0;
            player->unk8C |= 0x10;
            player->unk4 = 10;
            break;
        case 10:
            player->unkA0.integer--;

            if(player->unkA0.integer <= 0){
                player->unk4 = 11;
            }
            break;
        case 11:
            if(func_80011528(0) % 100U < 10){
                player->unk8C |= 0x2000;
                player->unk8B = 0x7F;
            }
            else{
                player->unk8B = 0;
                player->unk8C &= ~0x2000;
            }

            if(func_80024CA0(0, idx, 300.0f) != -1){
                func_80008E10(0x5A, 2, idx);
                player->unk8B = 0;
                player->unk8C &= ~0x2000;
                func_800255AC(player, p, func_80011528(0) % 360U, 300.0f);
                player->unk28.y = func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0);
                player->unk4 = 20;
            }
            break;
        case 20:
            player->unk8B += 5;

            if(player->unk8B >= 0xFA){
                player->unk8C &= ~0x10;
                player->unk8B = 0xFF;
                player->unkA0.integer = 0xB4;
                player->unk4 = 30;
                player->unkA4.fp = 0.0f; 
            }
            break;
        case 30:
            if(player->unkA4.fp < 2.0f){
                player->unkA4.fp += 0.2;
            }

            player->unkA0.integer--;

            if(player->unkA0.integer <= 0 || D_80141CB0[idx].unk0 != -1 || func_80024CA0(4, idx, 100.0f) != -1){
                player->unk8C |= 0x10;
                player->unk4  = 40;
            }

            func_80024FC8(idx, player->unkA4.fp, 0.0f);
            func_8002507C(idx);
            break;
        case 40:
            func_80024FC8(idx, player->unkA4.fp, 0.0f);
            func_8002507C(idx);

            player->unk8B -= 5;

            if(player->unk8B < 0xA){
                player->unk8C |= 0x10;
                player->unk8B = 5;
                player->unkA0.integer = 0xC8;
                player->unk4 = 10;
            }
            break;
    }
}

void func_80045B18(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0);
    s16 i;
    s16 id;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    func_80074E68(player->unk28.y, func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0));

    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x2C;
            player->unk4 = 50;
            player->unkA0.fp = player->pos.x;
            player->unkA4.fp = player->pos.y;
            player->unkA8.fp = player->pos.z;
            break;
        case 50:
            func_80022F48(idx, 0);

            player->unk8B = 0;
            player->unk8C |= 0x10;

            if(temp < 400.0f){
                player->pos.x = player->unkA0.fp;
                player->pos.y = player->unkA4.fp + 50.0f;
                player->pos.z = player->unkA8.fp;
                player->unk4 = 100;
            }
            else{
                player->pos.x = player->unkA0.fp;
                player->pos.y = player->unkA4.fp;
                player->pos.z = player->unkA8.fp;
                
            }
            break;
        case 100:

            for(i = 0; i < 16; i++){

                temp2 = func_80011528(0) % 40U - 40.0f;
                temp3 = func_80011528(0) % 20U;
                temp4 = func_80011528(0) % 40U - 40.0f;

                
                id = func_80023498(6, 0x183, player->pos.x + temp2, player->pos.y + temp3, player->pos.z + temp4, 0.0f, 0.0f, 0.0f);
 
                if(id != -1){
                    func_80022F20(id, func_8002C2D0);
                    func_80024874(id, 0.4f);                    
                }
            }

            player->unk8B = 0xFF;
            player->unkB0.integer = 0x39;
            player->unk4 = 101;
            break;
        case 101:
            func_80025454(player, p, 16.0f);

            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                player->unk8C &= ~0x10;
                player->unk8C &= 0x80000;
                player->unk8B = 0xFF;
                player->unk4 = 102;
                player->unk60 = 0.0f;
                player->unk58 = 0.0f;
                player->unkAC.fp = 0.0f;
            }
            
            break;
        case 102:
            player->unkAC.fp -= D_80159170 * 0.25;
            player->unk5C = player->unkAC.fp;
            func_80059760(player);

            if(D_800F9910.unk0 != 0){
                player->unk8C &= ~0x80000;
                func_80022F48(idx, 3); 
                player->unkB0.integer = 0x19;
                player->unk4 = 103;
            }
            break;
        case 103:
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                func_80022F48(idx, 1);
                player->unkB0.integer = 0x59;
                player->unk4 = 104;
            }
            break;
        case 104:
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                player->unk4 = 150;
            }
            break;
        case 150:
            func_80022F48(idx, 5);
            player->unkB0.integer = 0x51;
            player->unkB4.integer = func_80011528(0) % 4U;
            player->unk4 = 151;
            break;
        case 151: 
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                player->unkAC.fp = 0.0f;
                func_80022F48(idx, 4);
                player->unk4 = 200; 
            }

            if(player->unkB0.integer == 0xF && (id = func_80023498(5, 0x183, 0.0f, 0.0f, 0.0f,0.0f, player->unk28.y, 0.0f)) != -1){
                func_80008E10(0x48, 2, idx);
                func_80025638(GET_PLAYER_PTR(id), player, player->unk28.y - 10.0f, 30.0f, 30.0f);

                switch(player->unkB4.integer){
                    case 0:
                        func_80022F20(id, func_8004E6A8);
                        break;
                    case 1:
                        func_80022F20(id, func_8004E6A8);
                        break;
                    case 2:
                        func_80022F20(id, func_8004E6A8);
                        break;
                    case 3:
                        func_80022F20(id, func_8004E6A8);
                        break;
                }
            }
            break;
        case 200:
            player->unkAC.fp += 0.1;
            func_80024FC8(idx, player->unkAC.fp, 0.0f);
            func_8002507C(idx);
            player->unk8B -= 2;

            if(player->unk8B < 2){
                player->unkB0.integer = 0x12C;
                player->unk4 = 201;
            }
            player->unk8C |= 0x10;
            break;
        case 201:
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                player->unk4 = 50;
            }
            break;
    }
}


void func_80046238(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    s16 temp;
    f32 pad;
    s32 pad2;
    s32 pad3;
     
    switch(player->unk4){
        case 0:
            player->unk28.y += 90.0f;
            player->unk8 |= 1;
            player->unk74 = 0x140;

            NORM_ANGLE(player->unk28.y);

            func_80024FC8(idx, 1.0f, 0.0f); 

            player->unk28.y -= 90.0f;

            NORM_ANGLE(player->unk28.y);         

            player->unkD8.integer = 0xC8;
            player->unkC8.integer = 0xC8;
            player->unk4 = 1;
            player->unkE0.fp = player->unk58;
            player->unkDC.fp = player->unk60;
            player->unkD4.fp = player->pos.x;
            player->unkD0.fp = player->pos.y;
            player->unkCC.fp = player->pos.z;
            player->unkC4.fp = player->unk90.x;
            break;
        case 1:
            player->unkC8.integer--;
            
            if(player->unkC8.integer <= 0){
                player->unkC8.integer = 0x5A;
                player->unk4 = 2;
            }
            break;
        case 2:
            player->unkC8.integer--;

            if(player->unkC8.integer <= 0){
                GET_PLAYER_PTR(idx)->pos.x = player->unkD4.fp;
                GET_PLAYER_PTR(idx)->pos.z = player->unkCC.fp;
                player->unk4 = 3;
            }
            if(player->unkC8.integer & 1){
                GET_PLAYER_PTR(idx)->pos.x = player->unkE0.fp + player->unkD4.fp;
                GET_PLAYER_PTR(idx)->pos.z = player->unkDC.fp + player->unkCC.fp;
            }
            else{
                GET_PLAYER_PTR(idx)->pos.x = player->unkD4.fp - player->unkE0.fp;
                GET_PLAYER_PTR(idx)->pos.z = player->unkCC.fp - player->unkDC.fp;
            }
            break;
        case 3:
            player->unk90.x = player->unkC4.fp * 0.8;
            player->unk90.z = player->unkC4.fp * 0.8;
            player->unk90.y = player->unkC4.fp * 1.2;
        
            player->unk4 = 4;
            break;
        case 4:
            player->unk90.x = player->unkC4.fp * 1.1;
            player->unk90.z = player->unkC4.fp * 1.1;
            player->unk90.y = player->unkC4.fp * 0.8;
        
            player->unk4 = 5;
            break;
        case 5:
            player->unk90.x = player->unkC4.fp * 1.3;
            player->unk90.z = player->unkC4.fp * 1.3;
            player->unk90.y = player->unkC4.fp * 0.6;
        
            player->unk4 = 6;
            break;
        case 6:

            player->unk90.x = player->unkC4.fp * 1.4;
            player->unk90.z = player->unkC4.fp * 1.4;
            player->unk90.y = player->unkC4.fp * 0.5;
            
            player->unk4 = 7;\
            player->unkC8.integer = 8;
            break;
        case 7:
            player->unkC8.integer--;

            if(player->unkC8.integer <= 0){
                func_80008E10(0x5C, 2, idx);
                player->unkC8.integer = 0x78;
                player->unkC0.fp = 0.05f;
                player->unk4 = 8;
            }
            break;
        case 8:
            player->unkC8.integer--;

            if(player->unkC8.integer <= 0){
                player->unk90.z = player->unkC4.fp;
                player->unk90.y = player->unkC4.fp;
                player->unk90.x = player->unkC4.fp;
                player->pos.x = player->unkD4.fp;
                player->pos.z = player->unkCC.fp;
                if(player->unk90.x);
                player->unkC8.integer = player->unkD8.integer;
                player->unk4 = 1;
            }

            
            if(player->unkC8.integer % 2U){
                func_80024874(idx, (player->unkC0.fp + 1.0f) * player->unkC4.fp);
            }
            else{
                func_80024874(idx, (1.0f - player->unkC0.fp ) * player->unkC4.fp);
            }

            player->unkC0.fp -= 0.000416666;

            if((func_80011528(0) & 0x7F) > 80U){
                temp = func_80023644(6, 0x183, player->pos.x, (player->unkC4.fp * 4.0f) + player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);
            }
            else{
                temp = func_80023644(5, 0x183, player->pos.x, (player->unkC4.fp * 4.0f) + player->pos.y, player->pos.z, 0.0f, 0.0f, 0.0f);
            }

            if(temp != -1){
                func_80022F20(temp, func_8002B8A8);
            }
            break;
    }
}


void func_8004681C(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);

    switch(player->unk4){
        case 0:
            player->unkA4.integer = 0;
            player->unkA0.integer = 0x64;
            player->unk4 = 1;
            break;
        case 1:
            if(player->unkA4.integer >= 2){
                player->unkA4.integer = 0;
            }
            player->unkA4.integer++;
            player->unk4 = 2;
            break;
        case 2:
            player->unkA0.integer--;

            if(player->unkA0.integer < 0){
                player->unkA0.integer = 0x64;
                player->unk4 = 1;
            }
            break;
    }
}

void func_800468C4(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    Player* p = GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0);
    s16 i;
    f32 temp2;
    f32 temp4;
    f32 temp3;
    s16 id;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[D_800F38E1].unk0); 
 
    func_80074E68(player->unk28.y, func_800253B0(idx, D_80159178->unk48[D_800F38E1].unk0));
    
    
    switch(player->unk4){
        case 0:
            player->unk4E = 2;
            player->unk6C = 0x32;
            player->unk4 = 50;
            player->unkA0.fp = player->pos.x;
            player->unkA4.fp = player->pos.y;
            player->unkA8.fp = player->pos.z;
            
            break;
        case 50:
            func_80022F48(idx, 1);
            player->unk8B = 0;
            player->unk8C |= 0x10;

            if(temp < 300.0f){
                temp2 = (func_80011528(0) % 200U) - 200.0f;
                temp3 = (func_80011528(0) % 200U) - 200.0f;

                player->pos.x = p->pos.x + temp2;
                player->pos.y = p->pos.y + 50.0f;
                player->pos.z = p->pos.z + temp3;
                
                player->unk4 = 100;
                
            }
            else{
                player->pos.x = player->unkA0.fp;
                player->pos.y = player->unkA4.fp;
                player->pos.z = player->unkA8.fp;
            }
            break;
        case 100:
            for(i = 0; i < 0x10; i++){
                temp2 = func_80011528(0) % 40U - 40.0f;
                temp3 = func_80011528(0) % 20U;
                temp4 = func_80011528(0) % 40U - 40.0f;

                
                id = func_80023498(6, 0x183, player->pos.x + temp2, player->pos.y + temp3, player->pos.z + temp4, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002C2D0);
                    func_80024874(id, 0.4f);                    
                }                
            }

            player->unk4 = 101;
            break;
        case 101:
            func_80025454(player, p, 16.0f);

            player->unk8B += 2;

            if(player->unk8B >= 0xFE){
                player->unk8C &= ~0x10;
                player->unk8B = 0xFF;
                player->unkB0.integer = 0x28;
                player->unk4 = 102;
                player->unk60 = 0.0f;
                player->unk58 = 0.0f;
                player->unkAC.fp = 0.0f;
            }
            
            break;
        case 102:
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                player->unk4 = 104;
            }
            
            player->unkAC.fp -= D_80159170 * 0.125;
            player->unk5C = player->unkAC.fp;
            func_80059760(player);

            if(D_800F9910.unk0 != 0){
                player->unk4 = 103;
            }
            break;
        case 103:
            player->unk4 = 150; 
            
            break;
        case 104:
            player->unk8B -= 2;

            if(player->unk8B < 2){
                player->unk4 = 50;
            }
            player->unk5C -= D_80159170 * 0.125;
            func_8002507C(idx);
            break;
        case 150:
            func_80022F48(idx, 2);
            player->unkB0.integer = 0x22;
            player->unkB4.integer = func_80011528(0) % 4U;
            player->unk4 = 151;
            break;
        case 151: 
            player->unkB0.integer--;

            if(player->unkB0.integer <= 0){
                func_80022F48(idx, 1);
                player->unk4 = 200; 
            }

            if(player->unkB0.integer == 0xA && (id = func_80023498(5, 0x19A, 0.0f, 0.0f, 0.0f,0.0f, player->unk28.y, 0.0f)) != -1){
                func_80025638(GET_PLAYER_PTR(id), player, player->unk28.y - 10.0f, 30.0f, 30.0f);

                switch(player->unkB4.integer){
                    case 0:
                        func_800242F0(id, 0, 0x4E);
                        func_80022F20(id, func_800617D8);
                        func_80024874(id, 3.0f);
                        break;
                    case 1:
                        func_800242F0(id, 0, 0x4E);
                        func_80022F20(id, func_800617D8);
                        func_80024874(id, 3.0f);
                        break;
                    case 2:
                        func_800242F0(id, 0, 0x4E);
                        func_80022F20(id, func_800617D8);
                        func_80024874(id, 3.0f);
                        break;
                    case 3:
                        func_800242F0(id, 0, 0x4E);
                        func_80022F20(id, func_800617D8);
                        func_80024874(id, 3.0f);
                        break;
                }
            }
            break;
        case 200:
            player->unk8B -= 3; 

            if(player->unk8B < 3){
                player->unk4 = 50;
            }
            player->unk8C |= 0x10;
            break;
    }
}

void func_80047084(s16 idx){
    Player* player = GET_PLAYER_PTR(idx);
    f32 temp;

    NORM_ANGLE(player->unk28.y);          

    switch(player->unk4){
        case 0:
            player->unk4 = 10;
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

                for(;player->unk28.y >= 360.0f;){
                    player->unk28.y -= 360.0f;
                }
            }
            else {
                player->unk28.y -= 4.0f;

                for(; player->unk28.y < 0.0f;){
                    player->unk28.y += 360.0f;
                }
                
            }

            if(player->pos.y - player->unkBC.fp < GET_PLAYER_PTR(D_80159178->unk48[D_800F38E1].unk0)->pos.y){
                player->unk4 = 7;
                func_80008E10(0x60, 2, idx);
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
                player->pos.y = player->unkAC.integer + 0x50;
                player->unkB0.integer = player->pos.z;

            }
            break;
        case 10:
            if(func_80024CA0(0, idx, 100.0f) != -1){
                player->unk4 = 1;
            }
            break;
    }

    player->unkC0.fp += 30.0f;

    NORM_ANGLE(player->unkC0.fp);

    temp = sinf(player->unkC0.fp * 3.14 / 180.0);

    if(player->unk4 != 10){
        if(player->unk38 != 0xFFFF){
            D_801414A0[player->unk38 + 3]->unk34 = temp * 40.0f;
            D_801414A0[player->unk38 + 4]->unk34 = -temp * 40.0f;
            
        }
    }
}
