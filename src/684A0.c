#include "684A0.h"
#include "global.h"
#include "23B20.h"
#include "segments.h"
#include "29980.h"
#include "9320.h"
#include "73660.h"
#include "7FC0.h"
#include "1D870.h"
#include "11F10.h"

#include "common.h"

extern f32 D_80159174;
extern s16 D_800FB340; 

extern f32 D_8014DF8C;

extern u8 D_801E41EC[];
extern u8 D_801E43EC[];
extern u8 D_801E44D0[];
extern u8 D_801E45FC[];

extern f32 D_800FB84C[][64];

void func_800678A0(s16 idx){
    static s16 D_800B57A0[] = {
        0xFFFF,
        0x0000,
        0x0001,
        0x0002,
        0x0003,
        0x0004,
        0x0005,
        0x0006,
        0x0007,
        0x0008,
        0x0009,
        0x000A,
        0x000B,
        0x000C,
        0x000D,
        0x000E,
        0x001C,
        0x0020,
        0x0021,
        0x0023,
        0x0025,
        0x0026,
        0x0027,
        0xFFFF,
    };
    static s16 D_801590D0;

    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s16 i;
    s16 temp1 = D_80159178->unk48[cdata.unk41].unk0; 
    Actor* actor3;
    f32 dist;
    s16 id;

    dist = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);\
    if(dist < 300.0f){\
        if(D_80159174 > 100.0f && actor->actorVars.varA0.integer == 0){
            actor->actorVars.varA0.integer = 1;
        }
    }

    switch(actor->status){
        case 0:
            D_800FB340 = 0;
            
            id = func_80023644(8, 0x69, -902.0f, -299.0f, -1320.0f, 0.0f, 45.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 2;
            }            
            
            id = func_80023644(8, 0x69, -932.0f, -298.0f, -1231.0f, 0.0f, 90.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->actorVars.varA0.integer = 5;
            } 
            
            D_801590D0 = func_80023644(8, 0x81, -1346.0f, -39.0f, -980.0f, 0.0f, 90.0f, 0.0f);
            if(D_801590D0 != -1){
                GET_ACTOR_PTR(D_801590D0)->unk68 = 0x36;
            }

            ROMCOPY(D_3A0350, D_8020C820);

            actor->actorVars.varA0.integer = 0;
            actor->actorVars.varAC.integer = -1;

            actor->status = 1;
            break;
        case 1:
            if(D_80159174 > -91.0f){
                actor->actorVars.varA4.integer = 60;
                actor->status = 10;
            }
            else if(actor2->pos.y < D_80159174){
                if(D_800FB340 != 0){
                    func_800240CC(D_800FB340);
                }

                func_80023468(D_801E41EC);

                D_800FB340 = 1;
                actor->status = 2;
            }
            break;
        case 2:
            if(D_80159174 > -91.0f){
                actor->actorVars.varA4.integer = 60;
                actor->status = 10;
            }
            else if(D_80159174 + 300.0f <= actor2->pos.y){
                if(D_800FB340 != 0){
                    func_800240CC(D_800FB340);
                }
                
                func_80023468(D_801E43EC);
                
                D_800FB340 = 2;
                actor->status = 1;
            }
            break;
        case 10:
            func_80023FCC(D_801590D0);
            D_801590D0 = -1;

            if(actor2->pos.y < D_80159174){
                actor->status = 11;
            }
            else{
                actor->status = 12;
            }
            break;
        case 11:
            if(actor2->pos.y < D_80159174){
                if(D_800FB340 != 0){
                    func_800240CC(D_800FB340);
                }

                func_80023468(D_801E44D0);

                D_800FB340 = 3;
                actor->status = 12;
            //!@BUG
            case 12:
                if(D_80159174 + 300.0f <= actor2->pos.y){
                    if(D_800FB340 != 0){
                        func_800240CC(D_800FB340);
                    }

                    func_80023468(D_801E45FC);
                
                    D_800FB340 = 4;
                    actor->status = 11;
                }
            }
         break;
        case 99:
            if(D_800FB340 != 0){
                func_800240CC(D_800FB340);
            }
            actor->status = 100;
            break;
        case 100:
            break;
    }
    if(D_800FB340 == 2 || D_800FB340 == 4){
        s16 temp = 0;
                
        for(i = 0; i < 0x100; i++){
            actor3 = GET_ACTOR_PTR(i);
            
            if(actor3->unk0 != 0 && actor3->unk64 == D_800FB340 && actor3->unk48 == 0x68){
                temp = 1; 
                break;
            }
        }
        if(temp == 0){
            D_800F9B08.unk878 &= ~0x1;
        }
    }

    if(D_80159174 >= 109.0f && D_801590D0 == -1){
        D_801590D0 = func_80023644(8, 0x81, -1412.0f, 151.0f, -1000.0f, 0.0f, 90.0f, 0.0f);
        
        if(D_801590D0 != -1){
            GET_ACTOR_PTR(D_801590D0)->unk68 = 0x36;
        }
    }
    switch(actor->actorVars.varA0.integer){
        case 0:
            actor->actorVars.varA4.integer++;

            if(actor->actorVars.varA4.integer > 0xFFFF){
                actor->actorVars.varA4.integer = 0; 
            }

            func_80068264(actor, 60.0f, 60.0f);

            if(dist < 1200.0f && D_80159174 > 100.0f && actor2->pos.y > 650.0f && !(actor->actorVars.varA4.integer % 16U)){
                func_80008E10(0xE, 3, idx);
            }
            break;
        case 1:
            GET_ACTOR_PTR(idx)->status = 99;

            if(func_80077548() != 0){
                func_80068264(actor, 60.0f, 60.0f);
                func_800073C0(0x20, 0);

                actor->actorVars.varA0.integer = 2;
                actor->actorVars.varA8.integer = 160;

                func_80022528(1, 3, actor->pos.x, actor->pos.y - 10.0f, actor->pos.z, 255.0f, 160.0f, 50.0f);

                D_80142BB8.unk14 = 64.0f;
                D_80142BB8.unk1690 = 0.0f;
                D_80142BB8.unk168C = 255.0f;
                D_80142BB8.unk1694 = 3.0f;

                D_8014DF8C = 64.0f;
            }
            break;
        case 2:
            func_80068264(actor, 60.0f, 60.0f);

            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer <= 0){
                actor->actorVars.varAC.integer = func_80023644(2, 0x1BC, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
                
                if(actor->actorVars.varAC.integer != -1){
                    D_800FB84C[actor->actorVars.varAC.integer][0] = func_800253B0(actor->actorVars.varAC.integer, temp1);
                    actor->actorVars.varA0.integer = 3;
                    actor->actorVars.varA8.integer = 300;

                    func_80022528(2, 2, actor->pos.x, actor->pos.y - 10.0f, actor->pos.z, 50.0f, 160.0f, 255.0f);

                    D_80142BB8.unk1694 = 2.0f;
                    D_80142BB8.unk2D0C = 2.0f;
                    D_80142BB8.unk168C = 0.0f;
                    D_80142BB8.unk2D08 = 0.0f;
                    D_80142BB8.unk2D04 = 255.0f;   

                    for (i = 0; D_800B57A0[i] != -1; i++) {
                        D_801D5F30[i].unk1C = 0;
                    }
                }
            }
            break;
        case 3:                                         
            actor->actorVars.varA8.integer--;
            if (actor->actorVars.varA8.integer <= 0) {
                actor->actorVars.varA0.integer = 4;
            }
            if (actor->actorVars.varA8.integer == 44) {
                func_8002263C(1);
            }
            if ((actor->actorVars.varA8.integer < 20) || (actor->actorVars.varA8.integer & 4)) {
                func_80008E10(0xB, 3, idx);
            }
            
            func_80068264(actor, 60.0f, 60.0f);
            break;
        case 4:
            return;
    }
}

void func_80068264(Actor* actor, f32 arg1, f32 arg2){
    f32 x;
    f32 y;
    f32 z;
    s16 id;

    x = (func_80011528(0) % (s16)arg1) - (arg1 / 2);
    y = (func_80011528(0) % (s16)arg1) - (arg1 / 2);
    z = (func_80011528(0) % (s16)arg1) - (arg1 / 2);

    id = func_80023644(6, 0x18A, actor->pos.x + x, actor->pos.y + arg2 + y, actor->pos.z + z, 0.0f, 0.0f, 0.0f);

    if(id != -1){
        GET_ACTOR_PTR(id)->flags |= 0x1020;
        func_80024874(id, (arg1 * 0.0166 * 0.5));
        func_80022F20(id, func_8002CB3C);
        func_80024FC8(id, 0.0f, 3.0f);
    }
}

void func_8006846C(Actor* actor, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5){
    f32 x;
    f32 y;
    f32 z;
    s16 id;

    x = (func_80011528(0) % (s16)arg1) - (arg1 / 2);
    y = (func_80011528(0) % (s16)arg1) - (arg1 / 2);
    z = (func_80011528(0) % (s16)arg1) - (arg1 / 2);

    id = func_80023644(6, 0x18A, actor->pos.x + x, actor->pos.y + arg2 + y, actor->pos.z + z, 0.0f, 0.0f, 0.0f);

    if(id != -1){
        GET_ACTOR_PTR(id)->flags |= 0x1020;
        func_80024874(id, (arg1 * 0.0166 * 0.5));
        func_80022F20(id, func_8002CB3C);
        func_80024FC8(id, 0.0f, arg5);
    }
}

