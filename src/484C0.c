#include "484C0.h"

#include "13940.h"
#include "1D870.h"
#include "73660.h"
#include "23B20.h"
#include "3AA90.h"
#include "57820.h"
#include "9320.h"

#include "libc/math.h"
#include "actor.h"

#include "common.h"

extern f32 D_80159170;

extern s16 D_800B5370;
extern s16 D_800B5424; 

void func_800478C0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 id = actor->status;

    (void)"0water face: %f\n";
    (void)"1water face: %f\n";

    switch(id){
        case 0:
            actor->actorVars.varAC.integer = 0;
            actor->status = 1U;
            break;
        case 1:
            id = 1;
            switch(actor->actorVars.varA0.integer){
                case 0:
                case 1:
                case 3: 
                case 4:
                case 5:
                case 7:
                case 8:
                    actor->status = 450;
                    break;
                case 6:
                    if(cdata.unk4E % 2U == id){ 
                        actor->actorVars.varA0.integer = 7;
                    } 
                    
                    actor->status = 450;
                    break;
                case 2:
                    if(func_80076FA0(0x1A)){
                        actor->status = 400;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 400:
            actor->actorVars.varA8.integer = 0;
            actor->flags |= 0x10;
            actor->status = 401;
            break;
        case 401:
            if(temp < 30.0f){
                actor->status = 402;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 402: 
            if(!func_80012D40(D_800B5374[actor->actorVars.varA0.integer].unk0, D_800B5374[actor->actorVars.varA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->actorVars.varA8.integer++;

                if(actor->actorVars.varA8.integer > 0){
                    actor->status = 404;
                }
                else{
                    actor->status = 403;
                }
            } 
            break;
        case 403:
            if(temp > 150.0f){
                actor->status = 401;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 404:
            D_800F05B8 = 1U;
            actor1->flags |= 0x4000;
            func_80025F18(2539.0f, 390.0f, 989.0f, 2443.0f, 371.0f, 1019.0f, 120.0f);
            actor->actorVars.varA8.integer = 0x78; 
            actor->status = 405;
            break;
        case 405:
            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer <= 0 && func_80076FA0(0x1A)){
                id = func_80023644(8, 0x81, 2443.0f, 471.0f, 1019.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->unk68 = 0x1A;
                    actor->actorVars.varA8.integer = 0x78; 
                    actor->status = 406;
                } 
            }
            func_80026380();
            break;
        case 406:
            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer <= 0){
                D_800F05B8 = 0;
                actor1->flags &= ~0x4000;
                actor->status = 453;
            }
            break;
        case 450:
            actor->actorVars.varA8.integer = 0;
            actor->status = 451;
            actor->flags |= 0x10;
            break;
        case 451:
            if(temp < 30.0f){
                actor->status = 452;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B5374[actor->actorVars.varA0.integer].unk0, D_800B5374[actor->actorVars.varA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->actorVars.varA8.integer++;

                if(actor->actorVars.varA8.integer >= 2){
                    actor->actorVars.varA8.integer = 0;
                }
                actor->status = 453;
            } 
            break;            
        case 453:
            if(temp > 250.0f){
                actor->status = 451;

                switch(actor->actorVars.varA0.integer){
                    case 0:
                    case 2:
                        actor->actorVars.varA0.integer = 4;
                        break;
                    case 6:
                        actor->actorVars.varA0.integer = 7;
                        break;
                }
            }
 
            if(actor->actorVars.varA0.integer == 6){
                 D_800F9B08.unk4B8 &= ~1;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        default:
            break;
    }

    func_80039FDC(idx, 25.0f);
}

void func_80047DB8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 temp2; 

    switch(actor->status){
        case 0:
            actor->actorVars.varA8.integer = 0;
            actor->status = 1;
            break;
        case 1:
            switch(actor->actorVars.varA0.integer){
                case 0:
                case 3:
                case 5:
                    actor->status = 450;
                    break;
                case 1:
                    if((D_800B5370 & 1) != 1){
                        actor->status = 400;
                    }
                    else{
                        func_80025454(actor, actor1, 1.0f);
                    }
                    break;
                case 2:
                    if((D_800B5370 & 4) != 4){
                        actor->status = 450;
                    }
                    else{
                        func_80025454(actor, actor1, 1.0f);
                    }
                    break;
                case 4:
                    if((D_800B5370 & 2) != 2){
                        actor->status = 400;
                    }
                    else{
                        func_80025454(actor, actor1, 1.0f);
                    }
                    break;
                
            }
            break;
        case 400:
            actor->actorVars.varA4.integer = 0;
            actor->flags |= 0x10;
            actor->status = 401;
            break;
        case 401:
            if(temp < 30.0f){
                actor->status = 402;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 402:
            if(!func_80012D40(D_800B53BC[actor->actorVars.varA0.integer].unk0, D_800B53BC[actor->actorVars.varA0.integer].unk4, 1)){
                actor->actorVars.varA4.integer++;

                if(actor->actorVars.varA4.integer >= 2){
                    actor->actorVars.varA4.integer = 0;
                }
                actor->status = 404;
            } 
            break;  
        case 404:
            D_800F05B8 = 1;
            actor1->flags |= 0x4000;
            
            switch(actor->actorVars.varA0.integer){
                case 1:
                    func_80025F18(-1535.0f, -1006.0f, -621.0f, -1435.0f, -1079.0f, -611.0f, 120.0f);
                    break;
                case 4:
                    func_80025F18(1351.0f, 271.0f, 2130.0f, 1428.0f, 211.0f, 2104.0f, 120.0f);
                    break;
            }

            actor->actorVars.varA4.integer = 0x78;
            actor->status = 405;
            break;
        case 405:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                switch(actor->actorVars.varA0.integer){
                    case 1:
                        if(func_80076FA0(0x23)){
                            temp2 = func_80023644(8, 0x81, -1435.0f, -999.0f, -621.0f, 0.0f, 180.0f, 0.0f);

                            if(temp2 != -1){
                                GET_ACTOR_PTR(temp2)->unk68 = 0x23; 
                                D_800B5370 |= 1;
                                actor->actorVars.varA4.integer = 0x78;
                                actor->status = 406;
                            }
                        }
                        break;
                    case 4:
                        if(func_80076FA0(0x39)){
                            temp2 = func_80023644(8, 0x81, 1453.0f, 300.0f, 2107.0f, 0.0f, 225.0f, 0.0f);

                            if(temp2 != -1){
                                GET_ACTOR_PTR(temp2)->unk68 = 0x39; 
                                actor->actorVars.varA4.integer = 0x78;
                                D_800B5370 |= 2;
                                actor->status = 406;                
                            }
                        }
                        break;
                }
            }

            func_80026380();
            
            break;
        case 406:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer <= 0){
                D_800F05B8 = 0;
                actor1->flags &= ~0x4000;
                actor->status = 453;
            }
            break;
        case 450:
            actor->actorVars.varA4.integer = 0;
            actor->flags |= 0x10;
            actor->status = 451;
            break;
        case 451:
            if(temp < 30.0f){
                actor->status = 452;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B53BC[actor->actorVars.varA0.integer].unk0, D_800B53BC[actor->actorVars.varA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->actorVars.varA4.integer++;

                if(actor->actorVars.varA4.integer >= 2){
                    actor->actorVars.varA4.integer = 0;
                }

                actor->status = 453;
            }
            break;
        case 453:
            if(temp > 250.0f){
                actor->status = 451;
            }
            
            if(actor->actorVars.varA0.integer == 4){
                actor->actorVars.varA0.integer = 5;
            }
            if(actor->actorVars.varA0.integer == 1){
                actor->actorVars.varA0.integer = 6;
            }

            func_80025454(actor, actor1, 1.0f);
            
            break;
        case 455:
            break;
    }

    func_80039FDC(idx, 25.0f);
}

void func_800483BC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s32 pad;
    s32 pad2;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s32 temp2;

    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x1E;
            func_80022F48(idx, 0);
            actor->actorVars.varA8.integer = 0;
            actor->status = 1;
            break;
        case 1:
            switch(actor->actorVars.varA0.integer){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    actor->status = 450;
                    break;
                case 6:
                    actor->status = 400;
                    break;
            }
            break;
        case 400:
            break;
        case 450:
            actor->actorVars.varA4.integer = 0;
            actor->flags |= 0x10;
            actor->status = 451;
            break;
        case 451:
            if(temp < 30.0f){
                actor->status = 452;
            }
            func_80025454(actor, actor1, 1.0f);
            break;
        case 452:
            if(!func_80012D40(D_800B53F4[actor->actorVars.varA0.integer].unk0, D_800B53F4[actor->actorVars.varA0.integer].unk4, 1U)){
                actor1->flags &= ~0x4000;
                actor->actorVars.varA4.integer++;

                if(actor->actorVars.varA4.integer >= 2){
                    actor->actorVars.varA4.integer = 0;
                }

                actor->status = 453;
            }
            break;
        case 453:
            if(actor->actorVars.varA0.integer == 4){
                D_800F9B08.unk83C &= ~1;
                actor->status = 455; 
            }

            if(actor->actorVars.varA0.integer == 0){
                temp2 = func_80023644(8, 0x69, -2338.0f, -117.0f, -960.0f, 0.0f, 180.0f, 0.0f);

                if(temp2 != -1){
                    GET_ACTOR_PTR(temp2)->actorVars.varA0.integer = 4;
                    D_800B5424 |= 1;
                }

                actor->status = 455;
            }

            if(temp > 250.0f){
                actor->status = 451;
            }

            func_80025454(actor, actor1, 5.0f);
            break;
        case 454:
            break;
        case 455:
            func_80025454(actor, actor1, 5.0f);
            break;
    }
    
    func_80039FDC(idx, 25.0f);
}

void func_800486B4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            actor->actorVars.varD4.fp = actor->actorVars.varB4.fp;
            actor->actorVars.varD8.fp = actor->actorVars.varB8.fp;
            actor->actorVars.varDC.fp = actor->actorVars.varBC.fp;
            
            actor->actorVars.varC0.fp = 5.0f;
            actor->actorVars.varC4.fp = 2.0f;
            actor->actorVars.varC8.fp = 0.1f;
            actor->actorVars.varCC.fp = 8.0f;
            actor->actorVars.varD0.fp = 60.0f;



            actor->unk4E = 2;
            actor->unk6C = 0x24;
            
            func_80022F48(idx, 1);

            actor->status = 1;
            break;
        case 1:
            func_80021B90(idx);

            if(temp < 300.0f){
                actor->status = 2;
            }
            break;
        case 2:
            actor->dir.x *= 0.97;
            actor->dir.z *= 0.97;

            func_800259B4(actor, actor1->pos.y, 4.0f, 0.5f);

            if(actor->dir.x < 0.1 && actor->dir.z < 0.1){
                actor->status = 3;
            }

            func_80025454(actor, actor1, 16.0f);
            func_8002507C(idx);
            break;
        case 3:
            func_80024FC8(idx, 6.0f, 0.0f);
            actor->actorVars.varE0.integer = 0x28;
            actor->status = 4;
            break;
        case 4:
            actor->actorVars.varE0.integer--;

            if(actor->actorVars.varE0.integer <= 0){
                actor->status = 1;
            }

            if(actor->actorVars.varE0.integer < 0x14){
                actor->dir.x *= 0.99;
                actor->dir.z *= 0.99;
            }

            func_8002507C(idx);
            break;
    }
}

void func_80048970(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            if(actor->actorVars.varA0.integer == 1){
                actor->unk74 = 0xA;
                
                actor->scale.x = 3.0f;
                actor->scale.y = 3.0f;
                actor->scale.z = 3.0f;
                
            }

            actor->unk8 = 0x43E;
            actor->unk4E = 2;
            actor->unk6C = 0x25;
            func_80022F48(idx, 2);
            actor->actorVars.varA0.integer = 0x14;
            actor->status = 10;
            break;
        case 10:
            if(temp < 50.0f){
                actor->actorVars.varA4.fp = 2.0f;
                actor->actorVars.varA0.integer = 0x28;
                func_80008E10(0x55, 2, idx);
                actor->status = 11;
            }
            break;
        case 11:
            actor->actorVars.varA0.integer--;
            
            if(actor->actorVars.varA0.integer <= 0){
                actor->unk8 = 0;
                func_80022F48(idx, 0);
                actor->status = 12;
            }

            func_80025454(actor, actor1, 5.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, actor->actorVars.varA4.fp);
            actor->actorVars.varA4.fp -= D_80159170 * 0.25;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                actor->actorVars.varA0.integer = 10;
                actor->unk8 = 0x43E;
                func_80022F48(idx, 2);
                actor->status = 13;
            }
            break;
        case 13:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer <= 0){
                actor->status = 10;
            }
            break;
    }

}
