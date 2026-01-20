#include "44CC0.h"

#include "11F10.h"
#include "15F60.h"
#include "73660.h"
#include "23B20.h"
#include "29980.h"
#include "55270.h"
#include "684A0.h"
#include "9320.h"

#include "actor.h"
#include "libc/math.h"

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
    u16 unk0; 
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA[0x2];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    s32 unk48;
    s32 unk4C;
    u16 unk50;
    u16 unk52;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 unk60[0x80];
    Mtx mtx;
    u8 unk120[0x200];
    u8 unk320;
    u8 unk321;
    u8 unk322;
    u8 unk323;
    u8 unk324[0xC];
    f32 unk330;
    f32 unk334;
    f32 unk338;
    f32 unk33C;
    f32 unk340;
    f32 unk344;
    f32 unk348;
    f32 unk34C;
    f32 unk350;
}D_801414A0_ptr_struct;
extern D_801414A0_ptr_struct* D_801414A0[];
typedef struct D_801414A0_struct{
    u8 unk0[0x8];
    void* unk8;
    void* unkC;
    void* unk10;
}D_801414A0_struct;

extern D_801414A0_ptr_struct* D_801414A0[];


extern f32 D_80159170;

void func_800440C0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp;
    s16 temp1 = D_80159178->unk48[cdata.unk41].unk0;
    s16 temp2;
    s32 pad[3];
    f32 temp3; 
    
    switch(actor->status){
        case 0:
            actor->unkC0.integer = 2;
            actor->unkC8.integer = 1;
            actor->unk6C = 0x14;

            actor->unkCC.fp = (actor->unkA0.fp + actor->pos.x) * 0.5;
            actor->unkD0.fp = (actor->unkA4.fp + actor->pos.y) * 0.5;
            actor->unkD4.fp = (actor->unkA8.fp + actor->pos.z) * 0.5;

            actor->unkB4.fp = actor->pos.x;
            actor->unkB8.fp = actor->pos.y;
            actor->unkBC.fp = actor->pos.z;

            actor->unkE4.fp = actor->scale.x;
            actor->unkE8.fp = actor->scale.y;
            actor->unkEC.fp = actor->scale.z;

            func_80025AF4(actor);  

            actor->status = 1;
            
            break;
        case 1:
            switch(actor->unkC8.integer){
                case 0:
                    actor->unkD8.fp = actor->unkB4.fp;
                    actor->unkDC.fp = actor->unkB8.fp;
                    actor->unkE0.fp = actor->unkBC.fp;
                    
                    break;
                case 1:
                    actor->unkD8.fp = actor->unkA0.fp;
                    actor->unkDC.fp = actor->unkA4.fp;
                    actor->unkE0.fp = actor->unkA8.fp;
                    
                    break;
            }

            actor->unkC4.integer = 0x1E;

            actor->status = 2;
            break;
        case 2:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                actor->unk4E = 2;
                func_80022F48(idx, 1);
                actor->unkC4.integer = 0x3C;
                actor->status = 3;
            }            

            func_800256CC(actor, actor->unkD8.fp, actor->unkE0.fp, 10.0f);
            break;
        case 3:
            actor->unkC4.integer--;
            temp3 = func_800253B0(idx, temp1);
            temp = func_80074E68(actor->rot.y, temp3);

            if((temp < 45.0f || temp > -45.0f) && func_80024CA0(0, idx, actor->unkAC.fp) != -1 && actor->unkC4.integer <= 0){
                actor->rot.y = temp3;
                func_80022F48(idx, 3);
                actor->unkC4.integer = 0x29;
                actor->status = 0xA;
            }
            if(func_80024EA4(idx, actor->unkD8.fp, actor->unkDC.fp, actor->unkE0.fp) < 50.0f){
                actor->unkC4.integer = 0x8F;
                func_80022F48(idx, 0);
                actor->status = 4;
            }
            func_800256CC(actor, actor->unkD8.fp, actor->unkE0.fp, 2.0f);
            func_80024FC8(idx, 2.0f, 0.0f);
            func_8002507C(idx);
            break;
        case 4:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                actor->unk4E = 0;
                actor->unkC8.integer = 1- actor->unkC8.integer;
                func_80025AF4(actor);
                actor->status = 1; 
            }
            break;
        case 10:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                actor->unkC4.integer = 0x4C;
                func_80022F48(idx, 4);
                actor->status = 20; 
            }
            break;
        case 20:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                func_80022F48(idx, 2);
                actor->status = 30;
            }

            if(actor->unkC4.integer == 50){
                temp2 = func_80023644(5, 0x140, actor->pos.x, actor->pos.y + 15.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);

                if(temp2 != -1){
                    func_80008E10(0x48, 2, idx);
                    func_80024FC8(temp2, 4.0f, 0.0f);
                    func_8002507C(temp2);
                    func_800242F0(idx, 4, 0xFFFF);    

                    actor->unkC0.integer = 0;
                }
            }
            break;
        case 30:
            if((actor->unkB0.fp < func_80024EA4(idx, actor->unkCC.fp, actor->unkD0.fp, actor->unkD4.fp)) || D_80141CB0[idx].unk0 != -1){
                if(actor->unkC0.integer == 0){
                    func_80022F48(idx, 5);
                    actor->unkC4.integer = 0x63;
                    actor->status = 40;
                }
                else{
                    actor->unk4E = 0;
                    actor->unkC8.integer = 1 - actor->unkC8.integer;
                    func_80025AF4(actor);
                    actor->status = 1;
                }
            }

            func_80025454(actor, GET_ACTOR_PTR(temp1), 8.0f);
            func_80024FC8(idx, 3.0f, 0.0f);
            func_8002507C(idx);
            break;
        case 40:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                actor->unkC8.integer = 1 - actor->unkC8.integer;
                actor->unkC0.integer = 2;
                actor->unk4E = 0;
                func_80025AF4(actor);
                actor->status = 1;
            }

            if(actor->unkC4.integer < 0xB){
                actor->unkC0.integer = 1;
                func_80024348(idx, 4);
                func_800247E8(idx, 4, (10 - actor->unkC4.integer) * 0.1);
            }
            break;
        case 50:
            actor->unkC4.integer--;

            if(actor->unkC4.integer <= 0){
                actor->a = 255;
                actor->status = 51;
            }

            actor->pos.y -= 3.0f;
            actor->scale.x *= 0.99;
            actor->scale.y *= 1.05;
            actor->scale.z *= 0.99;
            actor->rot.y += 30.0f;

            NORM_ANGLE(actor->rot.y);

            actor->a -= 8;
            
            break;
        case 51:
            actor->status = 52;
            actor->pos.x = actor->unkD8.fp;
            actor->pos.y = actor->unkDC.fp;
            actor->pos.z = actor->unkE0.fp;
            
            break;
        case 52:
            actor->scale.x *= 10.0f;
            actor->scale.y *= 0.05; 
            actor->scale.z *= 10.0f;
            actor->status = 53;
            
            break;
        case 53:
            actor->unkC4.integer = 0x8F;
            actor->scale.x = actor->unkE4.fp;
            actor->scale.y = actor->unkE8.fp;
            actor->scale.z = actor->unkEC.fp;
            func_80022F48(idx, 0);
            actor->flags &= ~0x10;
            actor->status = 4;
            break; 
    }

    if(actor->unk70 == -1){
        return;
    }

    if((GET_ACTOR_PTR(actor->unk70)->flags & 8 || actor->pos.y - GET_ACTOR_PTR(actor->unk70)->pos.y > 30.0f) && actor->status < 50){
        actor->flags |= 0x2010;
        actor->unkC4.integer = 0x28;
        actor->status = 50;
    }
    else {
        f32 temp = GET_ACTOR_PTR(actor->unk70)->pos.y + 5.0f;
        if(temp < actor->pos.y){
            actor->pos.y -= 1.0f;
        }
        else {
            actor->pos.y = temp;
        }
    }
}

void func_80044930(s16 idx){
    s32 pad;
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->status = 1;
            actor->unkA0.fp = 1.0f; 
        case 1:
            actor->unkA0.fp -= 0.03;
            func_80024FC8(idx, 4.0f, actor->unkA0.fp);

            func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            if(D_800F9910.unk1 != 0){
                func_80023FCC(idx);
            }
            else{
                actor->rot.x += 40.0f;
 
                NORM_ANGLE(actor->rot.x);

                func_8002507C(idx);
            }
            break;
    } 
}

void func_80044ADC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    f32 temp2 = func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));
    s16 temp3;

    switch(actor->status){
        case 0:
            func_80024FC8(idx, 0.0f, -10.0f);
            func_80056894(actor);

            if(D_800F9910.unk0 != 0){
                actor->unk4E = 2;
                actor->unk6C = 0x26;
                func_80022F48(idx, 2);
                actor->status = 1;
                actor->unkB4.fp = actor->unkA4.fp;
                actor->unkC8.fp = 0.0f;
                
                actor->unkB8.fp = actor->unkA8.fp;
                actor->unkC4.fp = 5.0f;
                
            }
            break;
        case 1:
            func_80022F48(idx, 2);
            actor->unkBC.integer = 0x3C;
            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            actor->status = 2;
            break;
        case 2:
            if(actor->unkC4.fp > 5.0f){
                actor->unkC4.fp -= 1.0f;
            }

            actor->unkBC.integer--; 
            
            if(actor->unkBC.integer <= 0){
                actor->status = 3;
                actor->unkC8.fp = 0.0f;
            }

            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            
            break;
        case 3:
            func_80022F48(idx, 4);
            actor->unkBC.integer = 0x3C;
            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            actor->status = 4;            
            break;
        case 4:
            actor->unkBC.integer--;

            if(actor->unkBC.integer <= 0){
                actor->status = 5;
            }
            func_800256CC(actor, actor->unkB4.fp, actor->unkB8.fp, 16.0f);
            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            break;
        case 5:
            func_80022F48(idx, 3);
            actor->unkC0.fp = 0.0f;
            actor->unkC8.fp = 0.0f;
            actor->unkCC.fp = 0.0f; 
            actor->unkD0.fp = func_80024EA4(idx, actor->unkB4.fp, actor->pos.y, actor->unkB8.fp) * 0.3;
            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);
            actor->status = 6;
            break;
        case 6:
            if(actor->unkC0.fp < 4.0f){
                actor->unkC0.fp += 0.2;
            }

            if(actor->unkC8.fp > -3.0f){
                actor->unkC8.fp -= D_80159170 * 0.25; 
            }

            func_80024FC8(idx, actor->unkC0.fp, actor->unkC8.fp);

            actor->unkD8.fp = actor->pos.x;
            actor->unkDC.fp = actor->pos.z;

            func_80056894(actor);
            func_8006846C(actor, actor->unkC4.fp, 52.0f, 0.0f, 0.0f, 2.0f);

            if(temp < 300.0f){
                func_80025454(actor, actor1, 32.0f);

                if((temp < 100.0f) && temp2 < 20.0f && temp2 > -20.0f){
                    if(D_800F9910.unk0 != 0){
                        actor->status = 7;
                    }
                }
                else{
                    actor->unkC0.fp *= 0.9;
                } 
            }
            else{
                func_800256CC(actor, actor->unkB4.fp, actor->unkB8.fp, 16.0f);

                if(func_80024EA4(idx, actor->unkB4.fp, actor->pos.y, actor->unkB8.fp) < 100.0f && D_800F9910.unk0 != 0){
                    actor->status = 7;
                }
                
            }

            if(actor->unkC8.fp <= 3.0f && D_800F9910.unk0 != 0){
                if(actor->unkC0.fp * 0.3 < actor->unkC0.fp - sqrtf(SQ(actor->pos.z - actor->unkDC.fp) + SQ(actor->pos.x - actor->unkD8.fp))){
                    func_80008E10(0x45, 2, idx);
                    actor->unkC8.fp = 5.0f;
                }
            }
            
            
            break;
        case 7:
            temp3 = func_80023644(6, 0x18A, actor->pos.x, actor->pos.y + 52.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);

            if(temp3 != -1){
                func_80008E10(0x58, 2, idx);
                func_80024874(temp3, 0.04f); 
                func_80022F20(temp3, func_800453B8);
                func_80024FC8(temp3, actor->unkC0.fp, 2.0f);
            }

            func_80022F48(idx, 0);

            if(actor->unkC8.fp > -3.0f){
                actor->unkC8.fp -= D_80159170 * 0.25;
            }

            func_80024FC8(idx, actor->unkC0.fp, actor->unkC8.fp); 
            func_80056894(actor);

            actor->unkBC.integer = 0x33;
            actor->status = 8;
            
            break;
        case 8:
            actor->unkBC.integer--;

            if(actor->unkBC.integer <= 0){
                actor->status = 9;
            }

            if(actor->unkBC.integer < 0x14){
                actor->dir.x *= 0.96;
                actor->dir.z *= 0.96;
            }

            if(actor->unkC8.fp > -3.0f){
                actor->unkC8.fp -= D_80159170 * 0.25;
            }

            actor->dir.y = actor->unkC8.fp;
            func_80056894(actor);
            
            break;
        case 9:
            func_80022F48(idx, 1);

            if(actor->unkC8.fp > -3.0f){
                actor->unkC8.fp -= D_80159170 * 0.25;
            }
            
            actor->dir.y = actor->unkC8.fp;

            func_80056894(actor);

            actor->unkBC.integer = 0x45;
            actor->status = 10;
            break;
        case 10:
            if(actor->unkC8.fp > -3.0f){
                actor->unkC8.fp -= D_80159170 * 0.25;
            }
            
            actor->dir.y = actor->unkC8.fp;

            func_80056894(actor);
            
            actor->unkBC.integer--;

            if(actor->unkBC.integer <= 0){
                actor->unkA0.integer++;

                if(actor->unkA0.integer >= 2){
                    actor->unkA0.integer = 0;
                }

                switch(actor->unkA0.integer){
                    case 0:
                        actor->unkB4.fp = actor->unkA4.fp;
                        actor->unkB8.fp = actor->unkA8.fp;
                        
                        break;
                    case 1:
                        actor->unkB4.fp = actor->unkAC.fp;
                        actor->unkB8.fp = actor->unkB0.fp;
                        
                        break;
                }

                actor->status = 1;
                actor->unkC4.fp = 15.0f; 
            }
 
            break;
    }
    
}

void func_800453B8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s16 temp;
    
    switch(actor->status){
        case 0:
            actor->unkA0.integer = 0x28;
            func_8006846C(actor, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            actor->status = 1;
            break;
        case 1:
            actor->dir.y -= D_80159170 * 0.25;
            func_80059760(actor);

            if(D_800F9910.unk1 != 0){
                actor->unkA0.integer--;

                if(actor->unkA0.integer <= 0){
                    func_80023FCC(idx); 
                }

                if(!(actor->unkA0.integer & 3)){
                    temp = func_80023644(6, 0x18A, actor->pos.x, actor->pos.y + 52.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f); 

                    if(temp != -1){
                        func_80024874(temp, 0.04f);
                        func_80022F20(temp, func_80045568);                        
                    }
                }
            }

            func_8006846C(actor, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            
            break;
    }
}

void func_80045568(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 id;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    switch(actor->status){
        case 0:
            actor->unkA0.integer = 0x1E;
            func_8006846C(actor, 5.0f, 0.0f, 0.0f, 0.0f, 2.0f);
            actor->status = 1;
            break;
        case 1:
            actor->unkA0.integer--;

            if(actor->unkA0.integer <= 0){
                func_80023FCC(idx);
            }
            
            temp2 = func_80011528(0) % 20U - 10.0f;
            temp3 = func_80011528(0) % 20U - 10.0f;
            temp4 = func_80011528(0) % 20U - 10.0f;
            
            id = func_80023644(5, 0x18A, actor->pos.x + temp2, actor->pos.y + temp3, actor->pos.z + temp4, 0.0f, 0.0f, 0.0f);

            if(id != -1){
                GET_ACTOR_PTR(id)->flags |= 0x1020;
                func_80024874(id, 0.166f);
                func_80022F20(id, func_8002CB3C);
                func_80024FC8(id, 0.0f, 3.0f);
            }
            
            break;
        
    }
}

void func_80045794(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    switch(actor->status){
        case 0:
            func_80024874(idx, 2.5f);
            actor->a = 0;
            actor->flags |= 0x10;
            actor->status = 10;
            break;
        case 10:
            actor->unkA0.integer--;

            if(actor->unkA0.integer <= 0){
                actor->status = 11;
            }
            break;
        case 11:
            if(func_80011528(0) % 100U < 10){
                actor->flags |= 0x2000;
                actor->a = 127;
            }
            else{
                actor->a = 0;
                actor->flags &= ~0x2000;
            }

            if(func_80024CA0(0, idx, 300.0f) != -1){
                func_80008E10(0x5A, 2, idx);
                actor->a = 0;
                actor->flags &= ~0x2000;
                func_800255AC(actor, actor1, func_80011528(0) % 360U, 300.0f);
                actor->rot.y = func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0);
                actor->status = 20;
            }
            break;
        case 20:
            actor->a += 5;

            if(actor->a >= 250){
                actor->flags &= ~0x10;
                actor->a = 255;
                actor->unkA0.integer = 0xB4;
                actor->status = 30;
                actor->unkA4.fp = 0.0f; 
            }
            break;
        case 30:
            if(actor->unkA4.fp < 2.0f){
                actor->unkA4.fp += 0.2;
            }

            actor->unkA0.integer--;

            if(actor->unkA0.integer <= 0 || D_80141CB0[idx].unk0 != -1 || func_80024CA0(4, idx, 100.0f) != -1){
                actor->flags |= 0x10;
                actor->status  = 40;
            }

            func_80024FC8(idx, actor->unkA4.fp, 0.0f);
            func_8002507C(idx);
            break;
        case 40:
            func_80024FC8(idx, actor->unkA4.fp, 0.0f);
            func_8002507C(idx);

            actor->a -= 5;

            if(actor->a < 10){
                actor->flags |= 0x10;
                actor->a = 5;
                actor->unkA0.integer = 0xC8;
                actor->status = 10;
            }
            break;
    }
}

void func_80045B18(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0);
    s16 i;
    s16 id;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));

    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x2C;
            actor->status = 50;
            actor->unkA0.fp = actor->pos.x;
            actor->unkA4.fp = actor->pos.y;
            actor->unkA8.fp = actor->pos.z;
            break;
        case 50:
            func_80022F48(idx, 0);

            actor->a = 0;
            actor->flags |= 0x10;

            if(temp < 400.0f){
                actor->pos.x = actor->unkA0.fp;
                actor->pos.y = actor->unkA4.fp + 50.0f;
                actor->pos.z = actor->unkA8.fp;
                actor->status = 100;
            }
            else{
                actor->pos.x = actor->unkA0.fp;
                actor->pos.y = actor->unkA4.fp;
                actor->pos.z = actor->unkA8.fp;
                
            }
            break;
        case 100:
            for(i = 0; i < 16; i++){
                temp2 = func_80011528(0) % 40U - 40.0f;
                temp3 = func_80011528(0) % 20U;
                temp4 = func_80011528(0) % 40U - 40.0f;

                
                id = func_80023498(6, 0x183, actor->pos.x + temp2, actor->pos.y + temp3, actor->pos.z + temp4, 0.0f, 0.0f, 0.0f);
 
                if(id != -1){
                    func_80022F20(id, func_8002C2D0);
                    func_80024874(id, 0.4f);                    
                }
            }

            actor->a = 255;
            actor->unkB0.integer = 0x39;
            actor->status = 101;
            break;
        case 101:
            func_80025454(actor, actor1, 16.0f);

            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                actor->flags &= ~0x10;
                actor->flags &= 0x80000;
                actor->a = 255;
                actor->status = 102;
                actor->dir.z = 0.0f;
                actor->dir.x = 0.0f;
                actor->unkAC.fp = 0.0f;
            }
            
            break;
        case 102:
            actor->unkAC.fp -= D_80159170 * 0.25;
            actor->dir.y = actor->unkAC.fp;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                actor->flags &= ~0x80000;
                func_80022F48(idx, 3); 
                actor->unkB0.integer = 0x19;
                actor->status = 103;
            }
            break;
        case 103:
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                func_80022F48(idx, 1);
                actor->unkB0.integer = 0x59;
                actor->status = 104;
            }
            break;
        case 104:
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                actor->status = 150;
            }
            break;
        case 150:
            func_80022F48(idx, 5);
            actor->unkB0.integer = 0x51;
            actor->unkB4.integer = func_80011528(0) % 4U;
            actor->status = 151;
            break;
        case 151: 
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                actor->unkAC.fp = 0.0f;
                func_80022F48(idx, 4);
                actor->status = 200; 
            }

            if(actor->unkB0.integer == 0xF && (id = func_80023498(5, 0x183, 0.0f, 0.0f, 0.0f,0.0f, actor->rot.y, 0.0f)) != -1){
                func_80008E10(0x48, 2, idx);
                func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y - 10.0f, 30.0f, 30.0f);

                switch(actor->unkB4.integer){
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
            actor->unkAC.fp += 0.1;
            func_80024FC8(idx, actor->unkAC.fp, 0.0f);
            func_8002507C(idx);
            actor->a -= 2;

            if(actor->a < 2){
                actor->unkB0.integer = 0x12C;
                actor->status = 201;
            }
            actor->flags |= 0x10;
            break;
        case 201:
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                actor->status = 50;
            }
            break;
    }
}


void func_80046238(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 temp;
    f32 pad;
    s32 pad2;
    s32 pad3;
     
    switch(actor->status){
        case 0:
            actor->rot.y += 90.0f;
            actor->unk8 |= 1;
            actor->unk74 = 0x140;

            NORM_ANGLE(actor->rot.y);

            func_80024FC8(idx, 1.0f, 0.0f); 

            actor->rot.y -= 90.0f;

            NORM_ANGLE(actor->rot.y);         

            actor->unkD8.integer = 0xC8;
            actor->unkC8.integer = 0xC8;
            actor->status = 1;
            actor->unkE0.fp = actor->dir.x;
            actor->unkDC.fp = actor->dir.z;
            actor->unkD4.fp = actor->pos.x;
            actor->unkD0.fp = actor->pos.y;
            actor->unkCC.fp = actor->pos.z;
            actor->unkC4.fp = actor->scale.x;
            break;
        case 1:
            actor->unkC8.integer--;
            
            if(actor->unkC8.integer <= 0){
                actor->unkC8.integer = 0x5A;
                actor->status = 2;
            }
            break;
        case 2:
            actor->unkC8.integer--;

            if(actor->unkC8.integer <= 0){
                GET_ACTOR_PTR(idx)->pos.x = actor->unkD4.fp;
                GET_ACTOR_PTR(idx)->pos.z = actor->unkCC.fp;
                actor->status = 3;
            }
            if(actor->unkC8.integer & 1){
                GET_ACTOR_PTR(idx)->pos.x = actor->unkE0.fp + actor->unkD4.fp;
                GET_ACTOR_PTR(idx)->pos.z = actor->unkDC.fp + actor->unkCC.fp;
            }
            else{
                GET_ACTOR_PTR(idx)->pos.x = actor->unkD4.fp - actor->unkE0.fp;
                GET_ACTOR_PTR(idx)->pos.z = actor->unkCC.fp - actor->unkDC.fp;
            }
            break;
        case 3:
            actor->scale.x = actor->unkC4.fp * 0.8;
            actor->scale.z = actor->unkC4.fp * 0.8;
            actor->scale.y = actor->unkC4.fp * 1.2;
        
            actor->status = 4;
            break;
        case 4:
            actor->scale.x = actor->unkC4.fp * 1.1;
            actor->scale.z = actor->unkC4.fp * 1.1;
            actor->scale.y = actor->unkC4.fp * 0.8;
        
            actor->status = 5;
            break;
        case 5:
            actor->scale.x = actor->unkC4.fp * 1.3;
            actor->scale.z = actor->unkC4.fp * 1.3;
            actor->scale.y = actor->unkC4.fp * 0.6;
        
            actor->status = 6;
            break;
        case 6:

            actor->scale.x = actor->unkC4.fp * 1.4;
            actor->scale.z = actor->unkC4.fp * 1.4;
            actor->scale.y = actor->unkC4.fp * 0.5;
            
            actor->status = 7;\
            actor->unkC8.integer = 8;
            break;
        case 7:
            actor->unkC8.integer--;

            if(actor->unkC8.integer <= 0){
                func_80008E10(0x5C, 2, idx);
                actor->unkC8.integer = 0x78;
                actor->unkC0.fp = 0.05f;
                actor->status = 8;
            }
            break;
        case 8:
            actor->unkC8.integer--;

            if(actor->unkC8.integer <= 0){
                actor->scale.z = actor->unkC4.fp;
                actor->scale.y = actor->unkC4.fp;
                actor->scale.x = actor->unkC4.fp;
                actor->pos.x = actor->unkD4.fp;
                actor->pos.z = actor->unkCC.fp;
                if(actor->scale.x);
                actor->unkC8.integer = actor->unkD8.integer;
                actor->status = 1;
            }

            
            if(actor->unkC8.integer % 2U){
                func_80024874(idx, (actor->unkC0.fp + 1.0f) * actor->unkC4.fp);
            }
            else{
                func_80024874(idx, (1.0f - actor->unkC0.fp ) * actor->unkC4.fp);
            }

            actor->unkC0.fp -= 0.000416666;

            if((func_80011528(0) & 0x7F) > 80U){
                temp = func_80023644(6, 0x183, actor->pos.x, (actor->unkC4.fp * 4.0f) + actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
            }
            else{
                temp = func_80023644(5, 0x183, actor->pos.x, (actor->unkC4.fp * 4.0f) + actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
            }

            if(temp != -1){
                func_80022F20(temp, func_8002B8A8);
            }
            break;
    }
}


void func_8004681C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->unkA4.integer = 0;
            actor->unkA0.integer = 0x64;
            actor->status = 1;
            break;
        case 1:
            if(actor->unkA4.integer >= 2){
                actor->unkA4.integer = 0;
            }
            actor->unkA4.integer++;
            actor->status = 2;
            break;
        case 2:
            actor->unkA0.integer--;

            if(actor->unkA0.integer < 0){
                actor->unkA0.integer = 0x64;
                actor->status = 1;
            }
            break;
    }
}

void func_800468C4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    s16 i;
    f32 temp2;
    f32 temp4;
    f32 temp3;
    s16 id;
    f32 temp = func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0); 
 
    func_80074E68(actor->rot.y, func_800253B0(idx, D_80159178->unk48[cdata.unk41].unk0));
    
    
    switch(actor->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x32;
            actor->status = 50;
            actor->unkA0.fp = actor->pos.x;
            actor->unkA4.fp = actor->pos.y;
            actor->unkA8.fp = actor->pos.z;
            
            break;
        case 50:
            func_80022F48(idx, 1);
            actor->a = 0;
            actor->flags |= 0x10;

            if(temp < 300.0f){
                temp2 = (func_80011528(0) % 200U) - 200.0f;
                temp3 = (func_80011528(0) % 200U) - 200.0f;

                actor->pos.x = actor1->pos.x + temp2;
                actor->pos.y = actor1->pos.y + 50.0f;
                actor->pos.z = actor1->pos.z + temp3;
                
                actor->status = 100;
                
            }
            else{
                actor->pos.x = actor->unkA0.fp;
                actor->pos.y = actor->unkA4.fp;
                actor->pos.z = actor->unkA8.fp;
            }
            break;
        case 100:
            for(i = 0; i < 0x10; i++){
                temp2 = func_80011528(0) % 40U - 40.0f;
                temp3 = func_80011528(0) % 20U;
                temp4 = func_80011528(0) % 40U - 40.0f;

                
                id = func_80023498(6, 0x183, actor->pos.x + temp2, actor->pos.y + temp3, actor->pos.z + temp4, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002C2D0);
                    func_80024874(id, 0.4f);                    
                }                
            }

            actor->status = 101;
            break;
        case 101:
            func_80025454(actor, actor1, 16.0f);

            actor->a += 2;

            if(actor->a >= 254){
                actor->flags &= ~0x10;
                actor->a = 255;
                actor->unkB0.integer = 0x28;
                actor->status = 102;
                actor->dir.z = 0.0f;
                actor->dir.x = 0.0f;
                actor->unkAC.fp = 0.0f;
            }
            
            break;
        case 102:
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                actor->status = 104;
            }
            
            actor->unkAC.fp -= D_80159170 * 0.125;
            actor->dir.y = actor->unkAC.fp;
            func_80059760(actor);

            if(D_800F9910.unk0 != 0){
                actor->status = 103;
            }
            break;
        case 103:
            actor->status = 150; 
            
            break;
        case 104:
            actor->a -= 2;

            if(actor->a < 2){
                actor->status = 50;
            }
            actor->dir.y -= D_80159170 * 0.125;
            func_8002507C(idx);
            break;
        case 150:
            func_80022F48(idx, 2);
            actor->unkB0.integer = 0x22;
            actor->unkB4.integer = func_80011528(0) % 4U;
            actor->status = 151;
            break;
        case 151: 
            actor->unkB0.integer--;

            if(actor->unkB0.integer <= 0){
                func_80022F48(idx, 1);
                actor->status = 200; 
            }

            if(actor->unkB0.integer == 0xA && (id = func_80023498(5, 0x19A, 0.0f, 0.0f, 0.0f,0.0f, actor->rot.y, 0.0f)) != -1){
                func_80025638(GET_ACTOR_PTR(id), actor, actor->rot.y - 10.0f, 30.0f, 30.0f);

                switch(actor->unkB4.integer){
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
            actor->a -= 3; 

            if(actor->a < 3){
                actor->status = 50;
            }
            actor->flags |= 0x10;
            break;
    }
}

void func_80047084(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 temp;

    NORM_ANGLE(actor->rot.y);          

    switch(actor->status){
        case 0:
            actor->status = 10;
            actor->unkC0.fp = 0.0f;
            actor->unkA8.integer = actor->pos.x;
            actor->unkAC.integer = actor->pos.y;
            actor->unkB0.integer = actor->pos.z;
            break;
        case 1:

            if(func_80024CA0(0, idx, 300.0f) == -1){
                actor->status = 2;
                actor->unkA0.integer = 0x168;
                actor->unkA4.integer = 5;
            }
            else{
                actor->status = 6;
                func_8002524C(idx, 0.0f, 0.0f, 0.0f);
                actor->unkB4.fp = 0.0f;
                actor->unkB8.fp = 0.0f;
                actor->unkBC.fp = 0.0f;
                
            }
            break;
        case 2:
            actor->rot.y += 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 3;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 4; 
                actor->unkA0.integer = 0x168;
            }
            break;
        case 3:
            actor->rot.y += 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 2;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 4;
                actor->unkA0.integer = 0x168;
            }
            break;
        case 4:
            actor->rot.y -= 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 5;
            }
            else if(actor->unkA0.integer < 0){
                actor->status = 2; 
                actor->unkA0.integer = 0x168;
            }
            break;
        case 5:
            actor->rot.y -= 6.0f;
            actor->unkA0.integer -= 6;

            func_80024FC8(idx, 8.0f, -actor->unkA4.integer--);
            func_8002507C(idx);

            if(actor->unkA4.integer < 0){
                actor->unkA4.integer = 5;
                actor->status = 4;
            }
            else if(actor->unkA0.integer < 0){ 
                actor->status = 1; 
                actor->pos.x = actor->unkA8.integer;
                actor->pos.z = actor->unkB0.integer;
            }
            break;
        case 6:
            actor->unkB4.fp += 0.5;
            actor->unkBC.fp += actor->unkB4.fp;

            if(func_80025288(idx, D_80159178->unk48[cdata.unk41].unk0) < 0){
                actor->rot.y += 4.0f;

                for(;actor->rot.y >= 360.0f;){
                    actor->rot.y -= 360.0f;
                }
            }
            else {
                actor->rot.y -= 4.0f;

                for(; actor->rot.y < 0.0f;){
                    actor->rot.y += 360.0f;
                }
                
            }

            if(actor->pos.y - actor->unkBC.fp < GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->pos.y){
                actor->status = 7;
                func_80008E10(0x60, 2, idx);
                actor->unkB8.fp = actor->unkB4.fp;
            }
            break;
        case 7:
            func_80024FC8(idx, 2.0f, -actor->unkB4.fp);
            func_8002507C(idx);

            actor->unkB4.fp -= 0.5;

            if(actor->unkB4.fp == 0.0f){
                actor->status = 8;
            }
            break;
        case 8:
            func_80024FC8(idx, 2.0f, actor->unkB4.fp);
            func_8002507C(idx);
            
            actor->unkB4.fp += 0.5;

            if(actor->unkB8.fp < actor->unkB4.fp){
                actor->status = 1;
                actor->unkA8.integer = actor->pos.x;
                actor->pos.y = actor->unkAC.integer + 0x50;
                actor->unkB0.integer = actor->pos.z;

            }
            break;
        case 10:
            if(func_80024CA0(0, idx, 100.0f) != -1){
                actor->status = 1;
            }
            break;
    }

    actor->unkC0.fp += 30.0f;

    NORM_ANGLE(actor->unkC0.fp);

    temp = sinf(actor->unkC0.fp * 3.14 / 180.0);

    if(actor->status != 10){
        if(actor->unk38 != 0xFFFF){
            D_801414A0[actor->unk38 + 3]->unk34 = temp * 40.0f;
            D_801414A0[actor->unk38 + 4]->unk34 = -temp * 40.0f;
            
        }
    }
}
