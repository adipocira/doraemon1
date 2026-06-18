#include "common.h"
#include "2DE50.h"
#include "73660.h"
#include "9320.h"
#include "78DE0.h"
#include "actor.h"
#include "zzGame.h"
#include "scheduler.h"
#include "11F10.h"
#include "386E0.h"
#include "29980.h"
#include "B4E0.h"
#include "23B20.h"
#include "15F60.h"
#include "789F0.h"

#include "libc/math.h"

extern s16 D_802BD49E[][0xE]; 

extern u16 D_802BD70A[];
extern u16 D_802BD71C[];
extern u16 D_802BD240[];

extern s32 D_802BD61C[];

extern u8 D_80142AB0[0x100];

extern f32 D_800F05B4;
extern f32 D_801485A4;
extern f32 D_801485A8;
extern f32 D_80159170;
extern f32 D_80159174;

extern u16 D_802BDE4C;
extern u16 D_802BDE4E;

extern s16 D_802BDE5A;

extern u8 D_801522E7;
extern u8 D_801522E8;
extern u8 D_801522E9;
 
void func_8002D250(s16 idx){ 
    Actor* actor = GET_ACTOR_PTR(idx);
    D_802BD2A4_struct* ptr; 
    s16 t2 = actor->unk48;

    (void)" quu %f \n";
    (void)"{%f, %f, %f} %f\n";
    (void)"pts{%f, %f, %f} %f\n";
    (void)"scl{%f, %f} \n";
    (void)"{r%d g%d b%d}\n";
    (void)"light{rox%f, h%f}\n";
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0: 
            actor->actorVars.varA4.fp = D_80159170;
            actor->dir.y = D_80159170 / 2;
            
            actor->unk4E = 2;
            actor->unk6C = D_802BD49E[t2][0];
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            func_80072A60(idx);
            
            if(actor->unk52 == 0 && actor->actorVars.varC4.shorts[0] == 1){
                ptr = (&D_802BD2A4)[t2];
                if(ptr->unk0 == actor->unk50 || ptr->unk1 == actor->unk50){
                    
                    if(actor->actorVars.varB8.shorts[0] == 1){
                        func_80008C6C(D_802BD70A[t2], 1);
                    }
                    else if(actor->actorVars.varB8.shorts[0] == 2){
                        func_80008C6C(D_802BD71C[t2], 1);
                    }
                }
            }
            break;
    }
}

void func_8002D394(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->health = 0xFA;
            actor->unk4E = 2;
            actor->unk6C = 6;
            actor->actorVars.varA4.fp = D_80159170;
            actor->dir.y = D_80159170 / 2;
            break;
    }
}

void func_8002D3FC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_802BD2A4_struct* ptr;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA4.fp = D_80159170;
            actor->dir.y = D_80159170 / 2;
            actor->health = 0xFA;
            actor->unk4E = 2;
            actor->unk6C = 6;
            
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            func_8007461C(idx);
            
            if(actor->unk52 == 0){
                ptr = (&D_802BD2A4)[actor->unk48];
                
                if(ptr->unk0 == actor->unk50 || ptr->unk1 == actor->unk50){
                    
                    if(actor->actorVars.varB8.shorts[0] == 1){
                        func_80008C6C(D_802BD70A[0], 1);
                    }
                    else if(actor->actorVars.varB8.shorts[0] == 2){
                        func_80008C6C(D_802BD71C[0], 1);
                    }
                }
            }
            break;
    }
}

void func_8002D518(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA4.fp = D_80159170;
            actor->dir.y = D_80159170 / 2;
            actor->health = 0xFA;
            actor->unk4E = 0;

            func_80008C6C(D_802BDE4C, 1);

            actor->actorVars.varD8.fp = 0.0f;
            actor->actorVars.varE0.fp = 19.0f;
            actor->actorVars.varE4.fp = actor->scale.x;
            
            actor->actorVars.varE8.shorts[0] = 1;            
            actor->actorVars.varD4.shorts[0] = 0;
            
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            func_80079180(idx);
            break;
    }
}

void func_8002D5F8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 t2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = 0x38;
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            t2 = actor->unk6A;
            
            if(D_800F3940->unk2C == 1){
                t2 = 0;
            }
            if(D_800F3940->unk28 == 1){
                t2 = 6;
            }
            if(D_800F3940->unk24 == 1){
                t2 = 0xA;    
            }
            if(D_800F3940->unk20 == 1){
                t2 = 0xB;
            }
            if(t2 != actor->unk6A){
                actor->unk6A = t2;
                actor->unk50 = 0;
                actor->unk52 = 0;
            }
            break;
    }
}

void func_8002D6BC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 t2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varCC.uchars[1] = 0xFF;
            actor->actorVars.varCC.shorts[1] = 0;
            actor->actorVars.varCC.uchars[0] = 0;
            
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            t2 = actor->actorVars.varCC.uchars[0];
            
            if(D_800F3940->unk2C == 1){
                t2 = 0;
            }
            if(D_800F3940->unk28 == 1){
                t2 = 2;
            }
            if(D_800F3940->unk24 == 1){
                t2 = 4;    
            }
            if(D_800F3940->unk20 == 1){
                t2 = 3;
            }
            if(t2 != actor->actorVars.varCC.uchars[0]){
                actor->actorVars.varCC.uchars[1] = 0xFF;
                actor->actorVars.varCC.shorts[1] = 0;
                actor->actorVars.varCC.uchars[0] = t2;
                
            }
            break;
    }

    func_80077164(GET_ACTOR_PTR(idx), idx);
} 

void func_8002D7AC(s16 idx){
    u16 t1;
    s16 id;
    Actor *actor = GET_ACTOR_PTR(idx);
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->actorVars.varA0.fp = 0.0f;
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            GET_ACTOR_PTR(idx)->actorVars.varA0.fp += 2.0;
            GET_ACTOR_PTR(idx)->rot.y = func_8000ADE0(GET_ACTOR_PTR(idx)->rot.y + GET_ACTOR_PTR(idx)->actorVars.varA0.fp);

            GET_ACTOR_PTR(idx)->scale.x *= 0.92;
            GET_ACTOR_PTR(idx)->scale.y *= 0.92; 
            GET_ACTOR_PTR(idx)->scale.z *= 0.92;
 
            if(GET_ACTOR_PTR(idx)->scale.x < 0.01){ 
                func_80023FCC(idx);

                if(cdata.nextstg == ZZ_GAME0_LEVEL_3_2){
                    return;
                }

                if(!(sc.sc.unk284 % 8U)){
                    if(cdata.unk43 % 2U){
                        random(0);
                    }

                    t1 = D_802BD240[random(0) % 8U];
                }
                else{
                    t1 = 0x15;
                }
                
                id = func_80023644(
                    1U,
                    t1,
                    actor->pos.x,
                    actor->pos.y + 18.0f,
                    actor->pos.z,
                    0.0f,
                    actor->rot.y,
                    0.0f
                );

                if(id != -1){
                    func_80022F20(id, func_80037AE0);
                }
            }
            break;
    }
}

void func_8002D998(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    u16 t1;
    s16 id;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->scale.x *= 1.5;
            actor->scale.y *= 0.1;
            actor->scale.z *= 1.5;
            
            actor->actorVars.varA0.integer = 25;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer == 0){
                func_80023FCC(idx);

                if(cdata.nextstg != ZZ_GAME0_LEVEL_3_2){
                    if(!(sc.sc.unk284 % 8U)){
                        if(cdata.unk43 % 2U){
                             t1 = D_802BD240[random(0) % 2U];
                        }
                        else{
                            t1 = D_802BD240[random(0) % 8U];
                        }
                    }
                    else{
                        t1 = 0x15;
                    }
                    
                    id = func_80023644(1U, t1, actor->pos.x, actor->pos.y + 18.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);

                    if(id != -1){
                        func_80022F20(id, func_80037AE0);
                    }
                }
            }
            else{
                actor->scale.x *= 0.98;
                actor->scale.z *= 0.98;
            }
            
            break;
    }
}

void func_8002DB90(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 x;
    f32 z;
    s32 pad[2];
    f32 y;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            func_80024FC8(idx, 9.0f, 0.0f);
            GET_ACTOR_PTR(idx)->status = 1;
            
            actor->actorVars.varA0.integer = 90;

            x = actor->pos.x + actor->dir.x * 2;
            z = actor->pos.z + actor->dir.z * 2;
            
            y = actor->pos.y - GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->pos.y;
            func_80016EB8(&D_800F9910, cdata.nextstg, x, actor->pos.y + y * 6.0f, z, 0.0f, -y * 7.5, 0.0f);

            if(D_800F9910.unk1 != 0){
                actor->dir.y = ((D_800F9910.unk10 + y) - actor->pos.y) * 0.5;
            }
            break;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer != 0){
                if(D_80141CB0[idx].unk4 == -1){
                    if(cdata.unk35 != 0){
                        func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
                    
                        if(D_800F9910.unk1 != 0){
                            D_800F9B08[D_800F9910.unk2].unk8 |= 4;
                            func_80022F20(idx, func_8002CDE0);
                        }
                        else{
                            func_8002507C(idx);
                        }
                    }
                    else{
                        func_8002507C(idx);
                    }
                }
                else{
                    func_80022F20(idx, func_8002CDE0);
                }
            }
            else{
                func_80022F20(idx, func_8002CDE0);
            }
            break;
    }
    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 0xA, 2);
        func_80023FCC(idx);
    }
}


void func_8002DEF0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 x;
    f32 z;
    s32 pad[2];
    f32 y;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            func_80024FC8(idx, 8.5f, 0.0f);
            GET_ACTOR_PTR(idx)->status = 1;
            
            actor->actorVars.varA0.integer = 90;

            x = actor->pos.x + actor->dir.x * 2;
            z = actor->pos.z + actor->dir.z * 2;
            y = actor->pos.y - GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->pos.y;
            func_80016EB8(&D_800F9910, cdata.nextstg, x, actor->pos.y + y * 6.0f, z, 0.0f, -y * 7.5, 0.0f);

            if(D_800F9910.unk1 != 0){
                actor->dir.y = ((D_800F9910.unk10 + y) - actor->pos.y) * 0.5;
            }
            break;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer != 0){
                if(D_80141CB0[idx].unk4 == -1){
                    if(cdata.unk35 != 0){
                        func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
                    
                        if(D_800F9910.unk1 != 0){
                            D_800F9B08[D_800F9910.unk2].unk8 |= 4;
                            func_80022F20(idx, func_8002CDE0);
                        }
                        else{
                            func_8002507C(idx);
                        }
                    }
                    else{
                        func_8002507C(idx);
                    }
                }
                else{
                    func_80022F20(idx, func_8002CDE0);
                }
            }
            else{
                func_80022F20(idx, func_8002CDE0);
            }
            break;
    }
    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 0xA, 2);
        func_80023FCC(idx);
    }
}

void func_8002E250(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2;
    s16 temp;
    f32 rotY;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            rotY = DEG2RAD_ALT(actor->rot.y);
            actor->actorVars.varA0.integer = 60;

            actor->dir.x = sinf(rotY) * 8.0f;
            actor->dir.z = cosf(rotY) * 8.0f;

            GET_ACTOR_PTR(idx)->status = 1;
        
        case 1:
            temp =  D_80141CB0[idx].unk4;
            func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);

            if(D_800F9910.unk1 != 0 || --actor->actorVars.varA0.integer == 0 || temp != -1){
                if(D_800F9910.unk1 != 0){
                    D_800F9B08[D_800F9910.unk2].unk8 |= 4;
                }

                actor->scale.x = actor->scale.y = actor->scale.z = 0.4f;
                actor->actorVars.varA8.fp = 60.0f;
                func_80008C6C(D_802BDE4E, 1);

                func_80022F20(idx, func_8002E4F8);

                D_801414A0[actor->unk38]->unk50 = 2;
                D_801414A0[actor->unk38]->unk54 = 180.0f;
                
                actor->unk4A = 6;
                D_801414A0[actor->unk38]->unk6 = 4;
                
                actor->unk84 = func_80030CC4;
                func_80023FCC(actor->actorVars.varAC.integer);
            }
            else{
                actor2 = GET_ACTOR_PTR(actor->actorVars.varAC.integer);
                actor->pos.x = D_800F9910.unkC;
                actor2->pos.x = actor->pos.x;
                
                actor->pos.y = D_800F9910.unk10;
                actor2->pos.y = actor->pos.y;
                
                actor->pos.z = D_800F9910.unk14;
                actor2->pos.z = actor->pos.z;

                actor->dir.y -= D_80159170 * 0.6;
            }
            break;
    }
}

void func_8002E4F8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->scale.x *= 0.97;
            actor->scale.y *= 0.97;
            actor->scale.z *= 0.97;

            actor->actorVars.varA8.fp -= 1.0f;

            if(actor->actorVars.varA8.fp == 0.0f){
                func_80023FCC(idx);
            }
            break;
    }

    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 1, 8);
    }
}

void func_8002E5F0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    f32 rotY;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_801414A0[GET_ACTOR_PTR(idx)->unk38]->unk54 = 60.0f;

            rotY = DEG2RAD_ALT(actor->rot.y);
            
            GET_ACTOR_PTR(idx)->dir.x = sinf(rotY) * 0.5;
            GET_ACTOR_PTR(idx)->dir.z = cosf(rotY) * 0.5;

            GET_ACTOR_PTR(idx)->scale.x = 2.0 * GET_ACTOR_PTR(idx)->scale.x;
            GET_ACTOR_PTR(idx)->scale.y = 2.0 * GET_ACTOR_PTR(idx)->scale.y;
            GET_ACTOR_PTR(idx)->scale.z = 2.0 * GET_ACTOR_PTR(idx)->scale.z;

            GET_ACTOR_PTR(idx)->actorVars.varA8.integer = 50;
            GET_ACTOR_PTR(idx)->actorVars.varAC.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varB4.fp = 0.0f;

            GET_ACTOR_PTR(idx)->status = 1;

        case 1:
            GET_ACTOR_PTR(idx)->actorVars.varAC.fp += GET_ACTOR_PTR(idx)->dir.x;
            GET_ACTOR_PTR(idx)->actorVars.varB4.fp += GET_ACTOR_PTR(idx)->dir.z;

            GET_ACTOR_PTR(idx)->pos.x = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.x + GET_ACTOR_PTR(idx)->actorVars.varAC.fp;
            GET_ACTOR_PTR(idx)->pos.y = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.y + 15.0f;
            GET_ACTOR_PTR(idx)->pos.z = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.z + GET_ACTOR_PTR(idx)->actorVars.varB4.fp ;
            

            if(D_80141CB0[idx].unk4 != -1){
                func_80030D0C(D_80141CB0[idx].unk4, 0x19, 0x10);
            }

            actor->actorVars.varA8.integer--;

            if(actor->actorVars.varA8.integer == 0){
                func_80023FCC(idx);
            }
            break;
    }
}

void func_8002E7F8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    f32 a0;
    s32 pad2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_801414A0[actor->unk38]->unk54 = 60.0f;

            actor->a = 46;
            actor->actorVars.varA8.integer = 20;

            actor->actorVars.varB0.fp = 1.0f;
            actor->actorVars.varB4.fp = 8.0f;

            GET_ACTOR_PTR(idx)->status = 1;
        
        case 1:
            actor->a += 10;
            actor->actorVars.varA8.integer--;

            actor->scale.x *= 1.03;
            actor->scale.y *= 1.03;
            actor->scale.z *= 1.03;

            if(actor->actorVars.varA8.integer == 0){
                actor->actorVars.varA8.integer = 60;
                GET_ACTOR_PTR(idx)->status = 2;
            }
            break;
        case 2:
            actor->a -= 4;
            actor->actorVars.varA8.integer--;
 
            if(actor->actorVars.varA8.integer == 0){
                func_80023FCC(idx);
                return;
            }
            break;
    }

    GET_ACTOR_PTR(idx)->actorVars.varB4.fp += 0.8;
    GET_ACTOR_PTR(idx)->actorVars.varB0.fp += 0.5; 

    a0 = DEG2RAD_ALT(actor->actorVars.varAC.fp);

    GET_ACTOR_PTR(idx)->pos.x = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.x + sinf(a0) * GET_ACTOR_PTR(idx)->actorVars.varB0.fp;
    GET_ACTOR_PTR(idx)->pos.y = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.y + GET_ACTOR_PTR(idx)->actorVars.varB4.fp;
    GET_ACTOR_PTR(idx)->pos.z = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.z + cosf(a0) * GET_ACTOR_PTR(idx)->actorVars.varB0.fp;
}

void func_8002EA24(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s32 pad3;
    s32 pad2;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            D_801414A0[actor->unk38]->unk54 = 60.0f;
            actor->actorVars.varA8.integer = 12;

            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->actorVars.varA8.integer--;

            actor->scale.x *= 1.12;
            actor->scale.y *= 1.12;
            actor->scale.z *= 1.12;

            if(actor->actorVars.varA8.integer == 0){
                actor->actorVars.varA8.integer = 40;
                GET_ACTOR_PTR(idx)->status = 2;
            }
            break;
        case 2:
            actor->actorVars.varA8.integer--;
            
            if(actor->actorVars.varA8.integer == 0){
                actor->actorVars.varA8.integer = 25;
                GET_ACTOR_PTR(idx)->status = 3;
            }
            break;
        case 3:
            actor->actorVars.varA8.integer--;

            actor->scale.x *= 0.9;
            actor->scale.y *= 0.9;
            actor->scale.z *= 0.9;

            if(actor->actorVars.varA8.integer == 0){
                func_80023FCC(idx);
            }
            
            break;
    }

    GET_ACTOR_PTR(idx)->pos.x = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.x;
    GET_ACTOR_PTR(idx)->pos.y = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.y;
    GET_ACTOR_PTR(idx)->pos.z = GET_ACTOR_PTR(actor->actorVars.varA4.integer)->pos.z;

    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 1, 0x20);
    }
}

void func_8002EC2C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 40;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer == 0){
                func_80023FCC(idx);
            }
            else{
                actor->pos.y -= 0.5;
            }
            break;
    }
}

void func_8002ECD0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    s16 id;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 180;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer != 0){
                if(actor->actorVars.varA0.integer < 165){
                    id = func_800761BC(actor, 200.0f);
 
                    if(id != -1){
                        func_8002EFEC(actor, GET_ACTOR_PTR(id));
                    }

                    func_8002EF18(actor, 5.0f);
                }
                else{
                    func_8002EF18(actor, 5.0f);
                }

                func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            
                if(D_800F9910.unk1 != 0){
                    D_800F9B08[D_800F9910.unk2].unk8 |= 4;
                    func_80022F20(idx, func_8002CDE0);
                }
                else{
                    func_8002507C(idx);
                }
            }
            else{
                func_80022F20(idx, func_8002CDE0);
            }

            break;
    }

    if(!(actor->actorVars.varA0.integer % 4U)){
        id = func_80023644(6, 0x160, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, actor->rot.y, 0.0f);

        if(id != -1){
            func_80022F20(id, func_8002EC2C);
            func_80024874(id, 0.08f);
        }
    }
    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 0xA, 0x400);
        func_80023FCC(idx);
    }
}

void func_8002EF18(Actor* actor, f32 y){
    f32 cos;
    
    actor->dir.y = sinf(DEG2RAD_ALT(actor->rot.x)) * y;
    cos = cosf(DEG2RAD_ALT(actor->rot.x)) * y;

    actor->dir.x = sinf(DEG2RAD_ALT(actor->rot.y)) * cos;
    actor->dir.z = cosf(DEG2RAD_ALT(actor->rot.y)) * cos;
}

void func_8002EFEC(Actor* actor1, Actor* actor2){
    f32 ang;
    f32 ang2;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 a0;

    xDiff = actor2->pos.x - actor1->pos.x;
    yDiff = (actor2->pos.y + 16.0f) - actor1->pos.y;
    zDiff = actor2->pos.z - actor1->pos.z;

    ang = func_80025C48(zDiff, xDiff);
    ang2 = func_8000ADE0(0 - ang);
    ang = func_80074E68(actor1->rot.y, ang);
    a0 = DEG2RAD_ALT(ang2);
    
    a0 = func_80025C48( (zDiff * cosf(a0) - sinf(a0) * xDiff), yDiff);
    
    ang2 = func_80074E68(actor1->rot.x, a0);
    actor1->rot.x = func_8000ADE0(actor1->rot.x + ang2 / 15.0f);
    actor1->rot.y = func_8000ADE0(actor1->rot.y + ang / 15.0f);
}

void func_8002F174(s16 idx) {
    s32 pad;                  
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 unk48 = actor->unk48;

    switch (GET_ACTOR_PTR(idx)->status) {
        case 0:
            actor->actorVars.varD8.fp = 1000.0f;  
            actor->actorVars.varDC.fp = 0.0f;
            actor->actorVars.varE4.fp = 0.0f;
            actor->actorVars.varE0.fp = actor->pos.y;
            actor->unk4E = 2;
            actor->unk6C = D_802BD49E[unk48][0];
            GET_ACTOR_PTR(idx)->status = 1;
            actor->rot.x = 270.0f;
        case 1:
            func_80077DF0(idx);
            
            if (actor->unk6A == 0 && actor->unk50 == 2 && actor->unk52 == 0) {
                func_80008C6C(D_802BDE5A, 1);
            }
            break;
    }
}

void func_8002F264(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->unk4E = 2;
            actor->unk6C = D_802BD49E[actor->unk48][0];
            actor->unk6A = 3;
            actor->unk44 = D_802BD61C[actor->unk48];
            
            GET_ACTOR_PTR(idx)->status = 1;
            
            break;
        case 1:
            break;
    }
}

void func_8002F2F0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 ang;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.fp = actor->pos.x;
            actor->actorVars.varA4.fp = actor->pos.z;
            actor->actorVars.varA8.fp = 0.0f;
            actor->actorVars.varAC.fp = 1.0f;

            actor->scale.x *= 5.0;
            actor->scale.y *= 5.0;
            actor->scale.z *= 5.0;

            func_80008C6C(4, 1);
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->actorVars.varA8.fp = func_8000ADE0(actor->actorVars.varA8.fp + 10.0);
            actor->actorVars.varAC.fp += 1.0;

            actor->scale.x *= 0.98;
            actor->scale.y *= 0.98;
            actor->scale.z *= 0.98;

            ang = DEG2RAD_ALT(GET_ACTOR_PTR(idx)->actorVars.varA8.fp);

            actor->pos.x = sinf(ang) * actor->actorVars.varAC.fp + actor->actorVars.varA0.fp;
            actor->pos.z = cosf(ang) * actor->actorVars.varAC.fp + actor->actorVars.varA4.fp;

            if(GET_ACTOR_PTR(idx)->actorVars.varAC.fp > 100.0f){
                func_80023FCC(idx);
            }
            
            break;
    }
}

void func_8002F4C8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            actor->actorVars.varA0.fp = GET_ACTOR_PTR(idx)->scale.x;
        case 1:
            if(D_80141CB0[idx].unk8 != -1){
                actor->scale.x += 0.3;

                if(actor->scale.x > 4.0){
                    actor->scale.x = 4.0f;

                    func_80022F20(idx, func_8002D7AC);
                    func_80008C6C(0xE3, 3);
                }

                actor->scale.y = actor->scale.x;
                actor->scale.z = actor->scale.x;
            }
            else{
                if(actor->actorVars.varA0.fp != actor->scale.x){
                    GET_ACTOR_PTR(idx)->scale.x -= 0.01;

                    if(actor->scale.x < actor->actorVars.varA0.fp){
                        actor->scale.x = actor->actorVars.varA0.fp;
                    }

                    actor->scale.y = actor->scale.x;
                    actor->scale.z = actor->scale.x;
                }
            }
            break;
    }
}

void func_8002F624(s16 idx){
    f32 xz;
    s32 pad[2];
    Mtx m;
    Mtx m2;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer = D_80159178->unk48[cdata.unk41].unk0;
            GET_ACTOR_PTR(idx)->actorVars.varA4.fp = 20.0f;
            GET_ACTOR_PTR(idx)->actorVars.varA8.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varAC.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varB0.fp = 0.0f;

            GET_ACTOR_PTR(idx)->status = 1;
            
        case 1:
            xz =  GET_ACTOR_PTR(idx)->actorVars.varA4.fp;
            guRotate(&m,  GET_ACTOR_PTR(idx)->actorVars.varA8.fp, 1.0f, 0.0f, 0.0f);
            guRotate(&m2,  GET_ACTOR_PTR(idx)->actorVars.varAC.fp, 0.0f, 1.0f, 0.0f);
            guMtxCatL(&m, &m2, &m);
            guRotate(&m2,  GET_ACTOR_PTR(idx)->actorVars.varB0.fp, 0.0f, 0.0f, 1.0f);
            guMtxCatL(&m, &m2, &m);
            guMtxXFML(&m, xz , 0.0f, xz, & GET_ACTOR_PTR(idx)->pos.x, & GET_ACTOR_PTR(idx)->pos.y, & GET_ACTOR_PTR(idx)->pos.z);
            
            GET_ACTOR_PTR(idx)->pos.x += GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.x;
            GET_ACTOR_PTR(idx)->pos.y += GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.y + 15.0f;
            GET_ACTOR_PTR(idx)->pos.z += GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.z;

            GET_ACTOR_PTR(idx)->actorVars.varAC.fp = func_8000ADE0( GET_ACTOR_PTR(idx)->actorVars.varAC.fp + 6.0);
            GET_ACTOR_PTR(idx)->actorVars.varB0.fp = func_8000ADE0( GET_ACTOR_PTR(idx)->actorVars.varB0.fp + 0.5);
            
            break;
    }
} 

void func_8002F820(s16 idx){
    f32 xz;
    s32 pad[2];
    Mtx m;
    Mtx m2;
    f32 ox;
    f32 oy;
    f32 oz;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer = D_80159178->unk48[cdata.unk41].unk0;
            GET_ACTOR_PTR(idx)->actorVars.varA4.fp = 10.0f;
            GET_ACTOR_PTR(idx)->actorVars.varA8.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varAC.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varB0.fp = 0.0f;
            GET_ACTOR_PTR(idx)->actorVars.varB4.integer = 8;

            GET_ACTOR_PTR(idx)->status = 1;
            
        case 1:
            xz =  GET_ACTOR_PTR(idx)->actorVars.varA4.fp;
            guRotate(&m,  GET_ACTOR_PTR(idx)->actorVars.varA8.fp, 1.0f, 0.0f, 0.0f);
            guRotate(&m2,  GET_ACTOR_PTR(idx)->actorVars.varAC.fp, 0.0f, 1.0f, 0.0f);
            guMtxCatL(&m, &m2, &m);
            guRotate(&m2,  GET_ACTOR_PTR(idx)->actorVars.varB0.fp, 0.0f, 0.0f, 1.0f);
            guMtxCatL(&m, &m2, &m);
            guMtxXFML(&m, xz , 0.0f, xz, &ox, &oy, &oz);
            
            GET_ACTOR_PTR(idx)->pos.x += ((GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.x + ox) - GET_ACTOR_PTR(idx)->pos.x) / 80.0f;
            GET_ACTOR_PTR(idx)->pos.y += ((GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.y + oy + 55.0f) - GET_ACTOR_PTR(idx)->pos.y) / 80.0f;
            GET_ACTOR_PTR(idx)->pos.z += ((GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA0.integer)->pos.z + oz) - GET_ACTOR_PTR(idx)->pos.z) / 80.0f;

            GET_ACTOR_PTR(idx)->actorVars.varAC.fp = func_8000ADE0( GET_ACTOR_PTR(idx)->actorVars.varAC.fp + 3.0);
            GET_ACTOR_PTR(idx)->actorVars.varB0.fp = func_8000ADE0( GET_ACTOR_PTR(idx)->actorVars.varB0.fp + 0.5);

            GET_ACTOR_PTR(idx)->actorVars.varB4.integer--;

            if(GET_ACTOR_PTR(idx)->actorVars.varB4.integer == 0){
                GET_ACTOR_PTR(idx)->actorVars.varB4.integer = 8;
                
                if(D_801414A0[GET_ACTOR_PTR(idx)->unk38]->unk6 == 0x33){
                    D_801414A0[GET_ACTOR_PTR(idx)->unk38]->unk6 = 0x34;
                }
                else{
                    D_801414A0[GET_ACTOR_PTR(idx)->unk38]->unk6 = 0x33;
                }
            }
            break;
    }
} 

void func_8002FAAC(s16 idx){
    Actor* actor;
    Actor* actor1;
    s32 temp = 350;
    f32 xDiff;
    f32 zDiff;
    f32 dist;
    f32 ang;
    s16 id = D_80141CB0[idx].unk0;
    
    if(id != -1){
        actor = GET_ACTOR_PTR(idx);
        actor1 = GET_ACTOR_PTR(id);
        
        xDiff = (s16)(GET_ACTOR_PTR(id)->pos.x - GET_ACTOR_PTR(idx)->pos.x);
        zDiff = (s16)(GET_ACTOR_PTR(id)->pos.z - GET_ACTOR_PTR(idx)->pos.z);
        ang = func_80025C48(zDiff, xDiff);
    
        dist = sqrtf(SQ(xDiff) + SQ(zDiff));

        if(dist < 120.0f){
            dist = 120.0f;
        }
        dist = temp / dist;
        
        GET_ACTOR_PTR(id)->actorVars.varAC.fp += sinf(ang) * dist;
        GET_ACTOR_PTR(id)->actorVars.varB4.fp += cosf(ang) * dist; 
        
    }
}

void func_8002FC18(s16 idx){
    Actor* actor1;
    s16 id;
    
    GET_ACTOR_PTR(idx)->rot.y = func_8000ADE0(GET_ACTOR_PTR(idx)->rot.y + 1.0);
    id = D_80141CB0[idx].unk0;
    
    if(id != -1){
        func_80023FCC(idx);
        func_80076F2C(GET_ACTOR_PTR(idx)->unk48);

        actor1 = GET_ACTOR_PTR(id); 
        
        actor1->unk52 = 0;
        actor1->unk6A = 0;
        actor1->unk50 = actor1->unk52;
        actor1->actorVars.varB8.shorts[0] = 15;
    }
}

void func_8002FCE8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 60;
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->scale.x *= 0.98;
            actor->scale.y *= 0.98;
            actor->scale.z *= 0.9;
            
            actor->actorVars.varA0.integer--;
                
            if(actor->actorVars.varA0.integer == 0){
                func_80023FCC(idx);
            }
            break;
    }
}

void func_8002FDAC(s16 idx){
    static f32 D_800B52F0[] = {
        1.0f, 0.9f, 0.8f, 0.9f, 
    };
    static f32 D_800B5300[] = {
        1.0f, 0.9f,
    };
    
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            
            actor->actorVars.varA0.fp = actor->scale.x;
            actor->actorVars.varA4.fp = actor->scale.y;
            actor->actorVars.varA8.integer = 0;
            actor->actorVars.varAC.integer = 0;

        case 1:
            GET_ACTOR_PTR(idx)->scale.x = D_800B52F0[actor->actorVars.varA8.integer] * GET_ACTOR_PTR(idx)->actorVars.varA0.fp ;
            GET_ACTOR_PTR(idx)->scale.y = D_800B5300[actor->actorVars.varAC.integer] * GET_ACTOR_PTR(idx)->actorVars.varA4.fp;

            actor->pos.y += 1.5;
            
            actor->actorVars.varA8.integer++;
            actor->actorVars.varA8.integer %= 4U;
            actor->actorVars.varAC.integer++;
            actor->actorVars.varAC.integer %= 2U;

            if(D_80159174 < actor->pos.y){
                func_80023FCC(idx);
            }
            break;
    }
}

void func_8002FEC8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1;
    s16 i;
    s16 id;
    f32 ang;
    f32 rAng;
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.fp = 0.0f;
            actor->actorVars.varA4.fp = 1.0f;
            actor->actorVars.varA8.fp = actor->pos.x;
            actor->actorVars.varAC.fp = actor->pos.y;
            actor->actorVars.varB0.fp = actor->pos.z;
            actor->actorVars.varB4.fp = 25.0f;
            
            for(i = 1; i < 8; i++){
                id = func_80023644(6, 0x18B, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    func_80022F20(id, func_8002FEC8);

                    actor1 = GET_ACTOR_PTR(id);
                    actor1->status = 1;
                    actor1->actorVars.varA0.fp = i*45;
                    actor1->actorVars.varA4.fp = 1.0f;
                    actor1->actorVars.varA8.fp = actor->pos.x;
                    actor1->actorVars.varAC.fp = actor->pos.y;
                    actor1->actorVars.varB0.fp = actor->pos.z;
                    actor1->actorVars.varB4.fp = 25.0f;
                }
            }
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->r = 0;
            actor->g = 0;
            actor->b = 255;
            actor->a = 80;

            ang = func_8000ADE0(actor->actorVars.varA4.fp + actor->actorVars.varA0.fp);
            
            actor->actorVars.varA0.fp = ang; 
            actor->rot.y = ang;
            
            rAng = DEG2RAD_ALT(ang);
        
            actor->pos.x = sinf(rAng) * GET_ACTOR_PTR(idx)->actorVars.varB4.fp + actor->actorVars.varA8.fp;
            actor->pos.z = cosf(rAng) * GET_ACTOR_PTR(idx)->actorVars.varB4.fp + actor->actorVars.varB0.fp;
            actor->pos.y = actor->actorVars.varAC.fp;
            
            break;
    }
}

void func_800300F4(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 x;
    f32 y;
    f32 z;
    s32 sp34;
    s32 pad;
    
    if(D_800F3944->unk2C == 1){
        if(GET_ACTOR_PTR(idx)->actorVars.varAC.integer < 0x24){
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer++;
        }
        else{
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer = 0;
        }

    }
    else if(D_800F3944->unk28 == 1){
        if(GET_ACTOR_PTR(idx)->actorVars.varAC.integer > 0){
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;
        }
        else{
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer = 0x24;
        }
    } else {
        return;
    }

    x = actor->pos.x;
    y = actor->pos.y;
    z = actor->pos.z;

    sp34 = actor->actorVars.varAC.integer;
    
    func_80023FCC(idx);
    func_800238B0(idx, (u16) (sp34 + 0x5A), x, y, z, 0.0f, 0.0f, 0.0f);

    if(idx != -1){
        func_80022F20(idx, func_800300F4);
    }

    actor->actorVars.varAC.integer = sp34;
}

void func_80030224(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 x;
    f32 y;
    f32 z;
    s32 sp34;
    s32 pad;
    
    if(D_800F3944->unk2C == 1){
        if(GET_ACTOR_PTR(idx)->actorVars.varAC.integer < 0x31){
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer++;
        }
        else{
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer = 0;
        }

    }
    else if(D_800F3944->unk28 == 1){
        if(GET_ACTOR_PTR(idx)->actorVars.varAC.integer > 0){
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer--;
        }
        else{
            GET_ACTOR_PTR(idx)->actorVars.varAC.integer = 0x31;
        }
    } else {
        return;
    }

    x = actor->pos.x;
    y = actor->pos.y;
    z = actor->pos.z;

    sp34 = actor->actorVars.varAC.integer;
    
    func_80023FCC(idx);
    func_800238B0(idx, (u16) (sp34 + 0x14), x, y, z, 0.0f, 0.0f, 0.0f);

    if(idx != -1){
        func_80022F20(idx, func_80030224);
    }

    actor->actorVars.varAC.integer = sp34;
}

void func_80030354(s16 idx){
    D_800F3944_struct** ptr;
    f32 x;
    f32 z;
    f32 scaleX;
    f32 y;
    s16 v0;
    Actor* actor = GET_ACTOR_PTR(idx);
    
    scaleX = actor->scale.x;
    x = actor->pos.x;
    y = actor->pos.y;
    z = actor->pos.z;
    
    ptr = &D_800F3944;

    v0 = (*ptr)->unk3C;
    
    if(v0 == 1 || v0 >= 0x15){
        scaleX += 0.01;
    }
    
    v0 = (*ptr)->unk38;
    
    if(v0 == 1 || v0 >= 0x15){
        scaleX -= 0.01;
    }

    v0 = (*ptr)->unk2C;
    
    if(v0 == 1 || v0 >= 0x15){
        if((*ptr)->unk34 != 0){
            z += 0.1;
        }
        else{
            y += 0.1;
        }
    }
    
    v0 = (*ptr)->unk28;
    
    if(v0 == 1 || v0 >= 0x15){
        if((*ptr)->unk34 != 0){
            z -= 0.1;
        }
        else{
            y -= 0.1;
        }
    }
    
    v0 = (*ptr)->unk24;
    
    if(v0 == 1 || v0 >= 0x15){
        x -= 0.1;
    }
    
    v0 = (*ptr)->unk20;
    
    if(v0 == 1 || v0 >= 0x15){
        x += 0.1;
    }
    
    actor->pos.x = x;
    actor->pos.y = y;
    actor->pos.z = z;
    
    actor->scale.x = actor->scale.y = actor->scale.z = scaleX;
}

void func_800304F8(s16 idx){
    D_801414A0_ptr_struct* temp_v1;
    D_800F3944_struct** ptr;
    f32 x;
    f32 z;
    f32 scaleX;
    f32 y;
    s16 v0;
    Actor* actor = GET_ACTOR_PTR(idx);

    temp_v1 = D_801414A0[actor->unk38];
    x = temp_v1->unkC;
    y = temp_v1->unk10;
    z = temp_v1->unk14;
    
    scaleX = actor->scale.x;
    ptr = &D_800F3944;
      
    v0 = (*ptr)->unk28;
    
    if(v0 == 1 || v0 >= 0x15){
      scaleX += 0.01;
    }
    
    v0 = (*ptr)->unk2C;
    
    if(v0 == 1 || v0 >= 0x15){
      scaleX -= 0.01;
    }
    
    v0 = (*ptr)->unk38;
    
    if(v0 == 1 || v0 >= 0x15){
      x += 0.05;
    }
    
    v0 = (*ptr)->unk3C;
    
    if(v0 == 1 || v0 >= 0x15){
      x -= 0.05;
    }
    
    v0 = (*ptr)->unk4;
    
    if(v0 == 1 || v0 >= 0x15){
      y += 0.05;
    }
    
    v0 = (*ptr)->unk8;
    
    if(v0 == 1 || v0 >= 0x15){
      y -= 0.05;
    }
    
    v0 = (*ptr)->unkC;
    
    if(v0 == 1 || v0 >= 0x15){
      z += 0.05;
    }
    
    v0 = (*ptr)->unk0;
    
    if(v0 == 1 || v0 >= 0x15){
      z -= 0.05;
    }
    
    func_8002443C(idx, 0, x, y, z);
    
    actor->scale.x = actor->scale.y = actor->scale.z = scaleX;
    
    if(ptr);
}

void func_800306D8(s16 idx){
    D_801414A0_ptr_struct* temp_v1;
    D_800F3944_struct** ptr;
    f32 scale;
    s16 v0;
    s32 v1;
    Actor* actor = GET_ACTOR_PTR(idx); 
        
    ptr = &D_800F3944;

    if((*ptr)->unk34 != 0 && actor->unk70 != -1){
        v1 = TRUE;
        scale = D_801AF8D8[actor->unk48].unk4;
    }
    else{
        v1 = FALSE;
        scale = actor->scale.x;
    }

    v0 = (*ptr)->unk38;

    if(v0 == 1 || v0 >= 0x15){
        scale += 0.01;
    }

    v0 = (*ptr)->unk3C;

    if(v0 == 1 || v0 >= 0x15){
        scale -= 0.01;
    }

    if(v1 != 0){
        D_801AF8D8[actor->unk48].unk4 = scale;
    }
    else{
        actor->scale.x = actor->scale.y = actor->scale.z = scale;
    }
}

void func_800307EC(s16 idx){
    D_800F3944_struct** ptr = &D_800F3948;
    s16 a3;
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 v1 = actor->actorVars.varA0.integer;
    s16 a1 = actor->actorVars.varA4.integer;
    s16 a2 = actor->actorVars.varA8.integer;
    
    a3 = (*ptr)->unk38;

    if(a3 == 1 || a3 >= 0x15){
        v1++;
    }

    a3 = (*ptr)->unk3C;

    if(a3 == 1 || a3 >= 0x15){
        v1--;
    }

    if(v1 < 0){
        v1 = 0;
    }
    if(v1 >= 0x100){
        v1 = 0xFF;
    }

    a3 = (*ptr)->unk4;

    if(a3 == 1 || a3 >= 0x15){
        a1++;
    }

    a3 = (*ptr)->unk8;

    if(a3 == 1 || a3 >= 0x15){
        a1--;
    }

    if(a1 < 0){
        a1 = 0;
    }
    if(a1 >= 0x100){
        a1 = 0xFF;
    }

    a3 = (*ptr)->unkC;

    if(a3 == 1 || a3 >= 0x15){
        a2++;
    }

    a3 = (*ptr)->unk0;

    if(a3 == 1 || a3 >= 0x15){
        a2--;
    }
 
    if(a2 < 0){
        a2 = 0;
    }
    if(a2 >= 0x100){
        a2 = 0xFF;
    }

    
    D_8014ABB8.unk33D4 = 255.0f;
    D_8014ABB8.unk33D8 = 255.0f;
    
    actor->actorVars.varA0.integer = v1;D_801522E7 = v1;
    actor->actorVars.varA4.integer = a1;D_801522E8 = a1;
    actor->actorVars.varA8.integer = a2;D_801522E9 = a2;
}

void func_8003099C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_800F3944_struct** ptr = &D_800F3944;
    f32 y;
    f32 z;
    s16 v0;
    f32 x;

    x = actor->rot.x;
    y = actor->rot.y;
    z = actor->rot.z;
    
    v0 = (*ptr)->unk24;

    if(v0 == 1 || v0 >= 0x15){
        x -= 1.0;
    }

    v0 = (*ptr)->unk20;

    if(v0 == 1 || v0 >= 0x15){
        x += 1.0;
    }

    x = func_8000ADE0(x);

    v0 = (*ptr)->unk28;

    if(v0 == 1 || v0 >= 0x15){
        y -= 1.0;
    }
    
    v0 = (*ptr)->unk2C;

    if(v0 == 1 || v0 >= 0x15){
        y += 1.0;
    }

    GET_ACTOR_PTR(idx)->rot.x = x;
    GET_ACTOR_PTR(idx)->rot.y = y;
    GET_ACTOR_PTR(idx)->rot.z = z;

    D_801485A4 = x;
    D_801485A8 = actor->rot.y;

}

void func_80030ADC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    
    actor->rot.y = func_8000ADE0(actor->rot.y + 1.0);
}

void func_80030B38(s16 idx){
    Vec3f sp28[4];
    Actor *actor;
    f32 z = 32768.0f;
    f32 x = 32768.0f;
    s16 i;
    s16 j;
    s32 actorId;
    f32 xDiff;
    f32 zDiff;
    s16 id;

    for(i = 0, j = 0; j < 4; j++){
        actorId = D_800F0588.unk20[j];
        
        if(actorId >= 0){
            actor = GET_ACTOR_PTR(actorId);
            sp28[i].x = actor->pos.x;
            sp28[i].z = actor->pos.z; 
            i++;
        }
    }

    if (i == 0) {
        return;
    }

    for(j = 0; j < i; j++){
        if(sp28[j].x < x){
            x = sp28[j].x;
        }
        if(sp28[j].z < z){
            z = sp28[j].z;
        }  
    }
    
    zDiff = 0.0f;
    xDiff = 0.0f;

    // what?
    j *= 0.0f;
    
    for(; j < i; j++) {
        xDiff += sp28[j].x - x;
        zDiff += sp28[j].z - z;
    }

    actor = GET_ACTOR_PTR(D_800F0588.unk1E);
    actor->pos.x = xDiff / i + x;
    actor->pos.z = zDiff / i + z;
}

void func_80030CC4(s16 idx, Gfx** gfxPtr){
    gDPSetCombineMode(gfxPtr[0]++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetPrimColor(gfxPtr[0]++, 0, 0, 255, 255, 0, 255);
}

void func_80030D0C(s16 idx, s16 arg1, s32 arg2){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 v1;

    if(!(actor->unk8 & 0x200) && !(actor->unk8 & arg2)){
        v1 = actor->health - arg1;

        if(v1 < 0){
            v1 = 0;
        }

        actor->health = v1;
        D_80142AB0[idx] = 0;
    }
}

void func_80030D7C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer == 0){
                func_80023FCC(idx);
            }
            else{
                actor->a -= 5;
                actor->pos.y += 2.0;
                actor->scale.x = actor->scale.y = actor->scale.z = actor->scale.x * 1.02;
            }
            break;
    }
}

void func_80030E2C(Actor* actor){
    s16 id;
    f32 x;
    f32 ang;
    f32 z;
    
    ang = DEG2RAD_ALT(func_8000ADE0(actor->rot.y + 180.0f));
    z = cosf(ang) * 50.0f;
    x = sinf(ang) * 50.0f;
    
    id = func_80023644(6, 0x1A0, actor->pos.x + x, actor->pos.y + 28.0f, actor->pos.z + z, 0.0f, 0.0f, 0.0f);

    if(id != -1){
        GET_ACTOR_PTR(id)->unk80 = func_80030D7C;
        
        GET_ACTOR_PTR(id)->scale.x = GET_ACTOR_PTR(id)->scale.y = GET_ACTOR_PTR(id)->scale.z = actor->scale.x * 0.1;
        GET_ACTOR_PTR(id)->a = 254;
        
        GET_ACTOR_PTR(id)->actorVars.varA0.integer = 30;
        GET_ACTOR_PTR(id)->flags |= 0x40000;
        
    }
}

s16 func_80030F64(Actor* actor){
    D_802BED70_struct *temp;
    f32 ang;
    f32 x;
    f32 y;
    f32 z;
    s16 ret;

    ret = 0;
    actor->actorVars.varA4.integer--;

    if(actor->actorVars.varA4.integer == 0){

        temp = &D_802BED70[actor->actorVars.varB4.integer][actor->actorVars.varA0.integer++];
        
        if(actor->actorVars.varA0.integer == 1){
            actor->pos.x = temp->x;
            actor->pos.y = temp->y;
            actor->pos.z = temp->z;
            actor->rot.y = temp->unkC;
            
            actor->actorVars.varA4.integer = 1;
            
            return 0;
        }
        if(temp->x == 0.0f && temp->y == 0.0f && temp->z == 0.0f){
            ret = 1;
        }
        else{
            actor->actorVars.varA4.integer = temp->unkC;
            
            x = temp->x - actor->pos.x;
            y = (temp->y +20.0f) - actor->pos.y;
            z = temp->z - actor->pos.z;

            actor->actorVars.varA8.fp = func_80025C48(z, x);
            actor->actorVars.varAC.fp = sqrtf(SQ(x) + SQ(z)) / actor->actorVars.varA4.integer;
            actor->actorVars.varB0.fp = y / actor->actorVars.varA4.integer;
        }
    }

    actor->rot.y = func_8000ADE0(func_80074E68(actor->rot.y, actor->actorVars.varA8.fp) * 0.1 + actor->rot.f[1]); 
    ang = DEG2RAD_ALT(actor->rot.y);
    
    func_800180F0(
        &D_800F9910,
        cdata.nextstg,
        D_801414A4[actor->unk38]->unk54 * D_801AF8D8[actor->unk48].unk0,
        actor->pos.x,
        actor->pos.y,
        actor->pos.z,
        sinf(ang) * ((f32*)&actor->actorVars)[3],
        actor->actorVars.varB0.fp,
        cosf(ang) * ((f32*)&actor->actorVars)[3]
    );

    actor->pos.x = D_800F9910.unkC;
    actor->pos.y = D_800F9910.unk10;
    actor->pos.z = D_800F9910.unk14;

    (&D_801414A8)[actor->unk38]->unk38 = func_8000ADE0((&D_801414A8)[actor->unk38]->unk38 + actor->actorVars.rawVars[3].fp);
    return ret;
}

void func_80031254(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 0;
            actor->actorVars.varA4.integer = 1;
            actor->actorVars.varB8.integer = 0;
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 10:
            if(func_80030F64(actor) == 1){
                GET_ACTOR_PTR(idx)->status = 18;
                
                actor->actorVars.varA0.integer = 0;
                actor->actorVars.varB4.integer++;
                actor->actorVars.varA4.integer = 1;
            }
            break;
        case 18:
            actor->rot.y = D_800F05B4;
            break;
        case 20:
            if((!actor2->actorVars.varE8.shorts[0]) % 2U){
                GET_ACTOR_PTR(idx)->status = 25;
            }
            break;
        case 25:
            if(func_80030F64(actor) == 1){
                GET_ACTOR_PTR(idx)->status = 30;
            }
            break;
        case 30:
            D_801414A4[actor->unk38]->unk38 = func_8000ADE0(D_801414A4[actor->unk38]->unk38 + 3.0);
            break;
    }


    if(!(actor->actorVars.varB8.integer++ % 120)){
        func_80008E10(0x54, 3, idx);
    }
    if(!(actor->actorVars.varB8.integer % 8)){
        func_80030E2C(actor);
    }
}
