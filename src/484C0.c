#include "484C0.h"

#include "13940.h"
#include "1D870.h"
#include "73660.h"
#include "23B20.h"
#include "3AA90.h"
#include "55270.h"
#include "9320.h"

#include "libc/math.h"
#include "actor.h"

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
            actor->unkAC.integer = 0;
            actor->status = 1U;
            break;
        case 1:
            id = 1;
            switch(actor->unkA0.integer){
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
                        actor->unkA0.integer = 7;
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
            actor->unkA8.integer = 0;
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
            if(!func_80012D40(D_800B5374[actor->unkA0.integer].unk0, D_800B5374[actor->unkA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->unkA8.integer++;

                if(actor->unkA8.integer > 0){
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
            actor->unkA8.integer = 0x78; 
            actor->status = 405;
            break;
        case 405:
            actor->unkA8.integer--;

            if(actor->unkA8.integer <= 0 && func_80076FA0(0x1A)){
                id = func_80023644(8, 0x81, 2443.0f, 471.0f, 1019.0f, 0.0f, 90.0f, 0.0f);

                if(id != -1){
                    GET_ACTOR_PTR(id)->unk68 = 0x1A;
                    actor->unkA8.integer = 0x78; 
                    actor->status = 406;
                } 
            }
            func_80026380();
            break;
        case 406:
            actor->unkA8.integer--;

            if(actor->unkA8.integer <= 0){
                D_800F05B8 = 0;
                actor1->flags &= ~0x4000;
                actor->status = 453;
            }
            break;
        case 450:
            actor->unkA8.integer = 0;
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
            if(!func_80012D40(D_800B5374[actor->unkA0.integer].unk0, D_800B5374[actor->unkA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->unkA8.integer++;

                if(actor->unkA8.integer >= 2){
                    actor->unkA8.integer = 0;
                }
                actor->status = 453;
            } 
            break;            
        case 453:
            if(temp > 250.0f){
                actor->status = 451;

                switch(actor->unkA0.integer){
                    case 0:
                    case 2:
                        actor->unkA0.integer = 4;
                        break;
                    case 6:
                        actor->unkA0.integer = 7;
                        break;
                }
            }
 
            if(actor->unkA0.integer == 6){
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
            actor->unkA8.integer = 0;
            actor->status = 1;
            break;
        case 1:
            switch(actor->unkA0.integer){
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
            actor->unkA4.integer = 0;
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
            if(!func_80012D40(D_800B53BC[actor->unkA0.integer].unk0, D_800B53BC[actor->unkA0.integer].unk4, 1)){
                actor->unkA4.integer++;

                if(actor->unkA4.integer >= 2){
                    actor->unkA4.integer = 0;
                }
                actor->status = 404;
            } 
            break;  
        case 404:
            D_800F05B8 = 1;
            actor1->flags |= 0x4000;
            
            switch(actor->unkA0.integer){
                case 1:
                    func_80025F18(-1535.0f, -1006.0f, -621.0f, -1435.0f, -1079.0f, -611.0f, 120.0f);
                    break;
                case 4:
                    func_80025F18(1351.0f, 271.0f, 2130.0f, 1428.0f, 211.0f, 2104.0f, 120.0f);
                    break;
            }

            actor->unkA4.integer = 0x78;
            actor->status = 405;
            break;
        case 405:
            actor->unkA4.integer--;

            if(actor->unkA4.integer <= 0){
                switch(actor->unkA0.integer){
                    case 1:
                        if(func_80076FA0(0x23)){
                            temp2 = func_80023644(8, 0x81, -1435.0f, -999.0f, -621.0f, 0.0f, 180.0f, 0.0f);

                            if(temp2 != -1){
                                GET_ACTOR_PTR(temp2)->unk68 = 0x23; 
                                D_800B5370 |= 1;
                                actor->unkA4.integer = 0x78;
                                actor->status = 406;
                            }
                        }
                        break;
                    case 4:
                        if(func_80076FA0(0x39)){
                            temp2 = func_80023644(8, 0x81, 1453.0f, 300.0f, 2107.0f, 0.0f, 225.0f, 0.0f);

                            if(temp2 != -1){
                                GET_ACTOR_PTR(temp2)->unk68 = 0x39; 
                                actor->unkA4.integer = 0x78;
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
            actor->unkA4.integer--;

            if(actor->unkA4.integer <= 0){
                D_800F05B8 = 0;
                actor1->flags &= ~0x4000;
                actor->status = 453;
            }
            break;
        case 450:
            actor->unkA4.integer = 0;
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
            if(!func_80012D40(D_800B53BC[actor->unkA0.integer].unk0, D_800B53BC[actor->unkA0.integer].unk4, 1)){
                actor1->flags &= ~0x4000;
                actor->unkA4.integer++;

                if(actor->unkA4.integer >= 2){
                    actor->unkA4.integer = 0;
                }

                actor->status = 453;
            }
            break;
        case 453:
            if(temp > 250.0f){
                actor->status = 451;
            }
            
            if(actor->unkA0.integer == 4){
                actor->unkA0.integer = 5;
            }
            if(actor->unkA0.integer == 1){
                actor->unkA0.integer = 6;
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
            actor->unkA8.integer = 0;
            actor->status = 1;
            break;
        case 1:
            switch(actor->unkA0.integer){
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
            actor->unkA4.integer = 0;
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
            if(!func_80012D40(D_800B53F4[actor->unkA0.integer].unk0, D_800B53F4[actor->unkA0.integer].unk4, 1U)){
                actor1->flags &= ~0x4000;
                actor->unkA4.integer++;

                if(actor->unkA4.integer >= 2){
                    actor->unkA4.integer = 0;
                }

                actor->status = 453;
            }
            break;
        case 453:
            if(actor->unkA0.integer == 4){
                D_800F9B08.unk83C &= ~1;
                actor->status = 455; 
            }

            if(actor->unkA0.integer == 0){
                temp2 = func_80023644(8, 0x69, -2338.0f, -117.0f, -960.0f, 0.0f, 180.0f, 0.0f);

                if(temp2 != -1){
                    GET_ACTOR_PTR(temp2)->unkA0.integer = 4;
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
            actor->unkD4.fp = actor->unkB4.fp;
            actor->unkD8.fp = actor->unkB8.fp;
            actor->unkDC.fp = actor->unkBC.fp;
            
            actor->unkC0.fp = 5.0f;
            actor->unkC4.fp = 2.0f;
            actor->unkC8.fp = 0.1f;
            actor->unkCC.fp = 8.0f;
            actor->unkD0.fp = 60.0f;



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
            actor->unk58 *= 0.97;
            actor->unk60 *= 0.97;

            func_800259B4(actor, actor1->pos.y, 4.0f, 0.5f);

            if(actor->unk58 < 0.1 && actor->unk60 < 0.1){
                actor->status = 3;
            }

            func_80025454(actor, actor1, 16.0f);
            func_8002507C(idx);
            break;
        case 3:
            func_80024FC8(idx, 6.0f, 0.0f);
            actor->unkE0.integer = 0x28;
            actor->status = 4;
            break;
        case 4:
            actor->unkE0.integer--;

            if(actor->unkE0.integer <= 0){
                actor->status = 1;
            }

            if(actor->unkE0.integer < 0x14){
                actor->unk58 *= 0.99;
                actor->unk60 *= 0.99;
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
            if(actor->unkA0.integer == 1){
                actor->unk74 = 0xA;
                
                actor->unk90.x = 3.0f;
                actor->unk90.y = 3.0f;
                actor->unk90.z = 3.0f;
                
            }

            actor->unk8 = 0x43E;
            actor->unk4E = 2;
            actor->unk6C = 0x25;
            func_80022F48(idx, 2);
            actor->unkA0.integer = 0x14;
            actor->status = 10;
            break;
        case 10:
            if(temp < 50.0f){
                actor->unkA4.fp = 2.0f;
                actor->unkA0.integer = 0x28;
                func_80008E10(0x55, 2, idx);
                actor->status = 11;
            }
            break;
        case 11:
            actor->unkA0.integer--;
            
            if(actor->unkA0.integer <= 0){
                actor->unk8 = 0;
                func_80022F48(idx, 0);
                actor->status = 12;
            }

            func_80025454(actor, actor1, 5.0f);
            break;
        case 12:
            func_80024FC8(idx, 4.0f, actor->unkA4.fp);
            actor->unkA4.fp -= D_80159170 * 0.25;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                func_80008E10(0x17, 2, idx);
                actor->unkA0.integer = 10;
                actor->unk8 = 0x43E;
                func_80022F48(idx, 2);
                actor->status = 13;
            }
            break;
        case 13:
            actor->unkA0.integer--;

            if(actor->unkA0.integer <= 0){
                actor->status = 10;
            }
            break;
    }

}
