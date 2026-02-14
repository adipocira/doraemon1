#include "661D0.h"
#include "segments.h"
#include "global.h"
#include "actor.h"
#include "73660.h"
#include "23B20.h"
#include "7FC0.h"
#include "9320.h"

typedef struct D_801591C0_struct_unk48{
    s16 unk0;
    u8 unk2[0x66];
}D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
}D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_80141CB0_struct{
    s16 unk0;
    u8 unk2[0x6];
    s16 unk8;
    u8 unkA[0x3];
}D_80141CB0_struct;

extern D_80141CB0_struct D_80141CB0[];

extern f32 D_8014DF8C;
extern f32 D_80142BCC;

extern u16 D_8015A392;

void func_800655D0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s32 id;
    s16 id2;
    
    switch(actor->status){
        case 0:
            if(func_80076FA0(0x28) == 0){
                if(func_80076FA0(0x1A) != 0){
                    id = func_80023644(8, 0x62, 2533.0f, 371.0f, 1000.0f, 0.0f, 180.0f, 0.0f);
                    
                    if(id != -1){
                        GET_ACTOR_PTR(id)->actorVars.varA0.integer = 2;
                    }
                }
                
                id = func_80023644(8, 0x62, -1194.0f, 121.0f, 972.0f, 0.0f, 0.0f, 0.0f);
                
                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 1;
                }

                id = func_80023644(8, 0x62, -1476.0f, 92.0f, 1353.0f, 0.0f, 0.0f, 0.0f);
                
                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 4;
                }
            }
            else if(cdata.unk46[cdata.nextstg] & 0x8000){
                id = func_80023644(8, 0x62, -1476.0f, 92.0f, 1353.0f, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 4;
                }

                id = func_80023644(8, 0x62, -1194.0f, 121.0f, 972.0f, 0.0f, 0.0f, 0.0f);
                
                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 3;
                }
            }
            else{
                id = func_80023644(8, 0x62, -1476.0f, 92.0f, 1353.0f, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 0;
                }

                id = func_80023644(8, 0x62, -1194.0f, 121.0f, 972.0f, 0.0f, 0.0f, 0.0f);
                
                if(id != -1){
                     GET_ACTOR_PTR(id)->actorVars.varA0.integer = 3;
                }
            }

            id2 = func_80023644(8, 0x1C2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

            if(id2 != -1){
                func_80022F20(id2, func_80065C70);
            }

            id2 = func_80023644(8, 0x1C2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

            if(id2 != -1){
                func_80022F20(id2, func_80065E7C);
            }

            actor->actorVars.varBC.integer = func_80023644(8, 0x1C2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

            if(actor->actorVars.varBC.integer != -1){
                func_80022F20(actor->actorVars.varBC.integer, func_80066088);
                GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA0.integer = 1;
            }

            actor->status = 1;
            break;
        case 1:
            break;
        case 2:
            actor->status = 3;
            break;
        case 3:
            break;
    }
    if(actor->actorVars.varC0.integer == 0x32 && ((func_80024E0C(actor->actorVars.varD8.integer, D_80159178->unk48[cdata.unk41].unk0) > 1000.0f) || actor2->pos.y < 400.0f)){
        GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA0.integer = 1;
        actor->actorVars.varC0.integer = 0;

        func_800073C0(0, 0);
        func_800240CC(8);
        D_80142BCC = 255.0f;
        D_8014DF8C = 255.0f;
        D_800F05B8 = 0;
        cdata.unk35 = 1;
    }

    if(D_80141CB0[idx].unk0 != -1){
        if(actor->actorVars.varC0.integer < 0x32){
            actor->actorVars.varC0.integer++;
        }
    }
    if(actor->actorVars.varC0.integer == 0x31){
        func_800240CC(1);
        func_800240CC(2);
        func_800240CC(3);
        func_800240CC(4);
        func_800240CC(5);
        func_800240CC(6);
        func_80007648(0);
        func_800090B0(0);

        ROMCOPY(D_354270, D_8020C820);

        GET_ACTOR_PTR(actor->actorVars.varBC.integer)->actorVars.varA0.integer = 0;

        id = func_80023644(2, 0x1B8, actor->pos.x, actor->pos.y + 900.0f, actor->pos.z, 0.0f, 180.0f, 0.0f);
        actor->actorVars.varD8.integer = id;

        GET_ACTOR_PTR(id)->unk64 = 8;

        if(D_8015A392 & 1){
            GET_ACTOR_PTR(actor->actorVars.varD8.integer)->unk74 = 1;
        }

        func_800073C0(0xE, 0);

        actor->actorVars.varC0.integer = 0x32;

        cdata.unk35 = 0;
    }
    if(actor->actorVars.varC0.integer == 0x32 && GET_ACTOR_PTR(actor->actorVars.varD8.integer)->unk0 == 0){
        actor->status = 2;
        actor->actorVars.varC0.integer = 0x33;
    }
}

void func_80065C70(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);   
    s16 i;
    s16 id;

    if(actor2->pos.z < -250.0f && -1700.0f < actor2->pos.z && actor2->pos.x < -400.0f){
        if(actor->actorVars.varA8.integer < 2){
            actor->actorVars.varA8.integer++;
        }
    }
    else{
        actor->actorVars.varA8.integer = 0;
        func_800240CC(4);
        actor->actorVars.varC4.integer = -1;
        actor->actorVars.varC8.integer = -1;
        actor->actorVars.varCC.integer = -1;
        actor->actorVars.varD0.integer = -1;
    }

    if(actor->actorVars.varA8.integer != 0){
        for(i = 9; i < 13; i++){
            if(actor->actorVars.rawVars[i].integer == -1){
                id = func_80023644(2, 0x5A, -1169.0f, 60.0f, -1132.0f, 0.0f, 0.0f, 0.0f);
                actor->actorVars.rawVars[i].integer = id;

                if(id != -1){
                    actor2 = (u8*)actors + (id << 7 << 1); //!fake
                    actor2->unk64 = 4;
                    GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->actorVars.varA0.fp = 150.0f;
                }
            }
            else if(GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->unk0 == 0){
                actor->actorVars.rawVars[i].integer = -1;
            }
        }
    }
}

void func_80065E7C(s16 idx){
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);   
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 id;

    if(actor2->pos.z < 1150.0f && actor2->pos.z > -100.0f && actor2->pos.x < 600.0f){
        if(actor->actorVars.varAC.integer < 2){
            actor->actorVars.varAC.integer++;
        }        
    }
    else{
        actor->actorVars.varAC.integer = 0;
        func_800240CC(5);
        actor->actorVars.varC4.integer = -1;
        actor->actorVars.varC8.integer = -1;
        actor->actorVars.varCC.integer = -1;
        actor->actorVars.varD0.integer = -1;
    }

    if(actor->actorVars.varAC.integer != 0){
        for(i = 9; i < 13; i++){
            if(actor->actorVars.rawVars[i].integer == -1){
                id = func_80023644(2, 0x5A, 579.0f, 50.0f, 1010.0f, 0.0f, 0.0f, 0.0f);
                actor->actorVars.rawVars[i].integer = id;

                if(id != -1){
                    actor2 = (u8*)actors + (id << 7 << 1); //!fake
                    actor2->unk64 = 5;
                    GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->actorVars.varA0.fp = 100.0f;
                }
            }
            else if(GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->unk0 == 0){
                actor->actorVars.rawVars[i].integer = -1;
            }
        }
    }
}

void func_80066088(s16 idx){
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);   
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 id;    

    if(actor->actorVars.varA0.integer != 0){
        if(actor2->pos.y < 340.0f && actor2->pos.z > 700.0f){
            if(actor->actorVars.varB0.integer < 2){
                actor->actorVars.varB0.integer++;
            }             
        }    
        else{
            actor->actorVars.varB0.integer = 0;
            func_800240CC(6);
            actor->actorVars.varC4.integer = -1;
            actor->actorVars.varC8.integer = -1;
        }
        if(actor->actorVars.varB0.integer != 0){
            for(i = 9; i < 11; i++){
                if(actor->actorVars.rawVars[i].integer == -1){
                    id = func_80023644(2, 0x5A, 1498.0f, 60.0f, 1224.0f, 0.0f, 0.0f, 0.0f);
                    actor->actorVars.rawVars[i].integer = id;

                    if(id != -1){
                        actor2 = (u8*)actors + (id << 7 << 1); //!fake
                        actor2->unk64 = 6;
                        GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->actorVars.varA0.fp = 300.0f;
                    }
                }
                else if(GET_ACTOR_PTR(actor->actorVars.rawVars[i].integer)->unk0 == 0){
                    actor->actorVars.rawVars[i].integer = -1;
                }
            }
        }
    }
    else if(actor->actorVars.varB0.integer != 0){
        actor->actorVars.varB0.integer = 0;
        func_800240CC(6);
        actor->actorVars.varC4.integer = -1;
        actor->actorVars.varC8.integer = -1;        
    }
}
