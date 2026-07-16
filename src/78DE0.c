#include "78DE0.h"
#include "7B6C0.h"
#include "73660.h"
#include "386E0.h"
#include "2DE50.h"
#include "29980.h"
#include "23B20.h"
#include "15F60.h"
#include "B4E0.h"
#include "9320.h"
#include "6FA0.h"
#include "7FC0.h"
#include "7310.h"
#include "common.h"

#include "libc/math.h"

extern s16 D_802BD6B0[];
extern s16 D_802BD67A[];
extern s16 D_802BD6F8[];

extern Vec3f* D_802BEDB8[];

extern u8 D_800F0630;
extern u16 D_800F3950;

void func_800781E0(Actor* actor){ 
    s32 a0 = 20;

    (void)"r %f spd %f\n";
    (void)"%f %f %f-- %f \n";
    
    switch(actor->actorVars.varB8.uchars[2]){
        case 0:
            func_80008C6C(D_802BD6B0[cdata.unk1C], 1);
            actor->actorVars.varB8.uchars[2] = a0;
            actor->actorVars.varB8.uchars[3] = a0;
            break;
        case 20:
            actor->actorVars.varB8.uchars[3]--;

            if(!actor->actorVars.varB8.uchars[3]){
                
                func_800073C0(0x17, 0);
                a0 = 1;
                D_800F0588.unk1B = (u64)a0;
                D_800F0588.unk1D = 0;
                D_800F0630 = 7;
                
                actor->actorVars.varB8.uchars[2] = 10;
                actor->actorVars.varB8.uchars[3] = 120;
            }
            break;
        case 10:
            actor->actorVars.varB8.uchars[3]--;

            if(!actor->actorVars.varB8.uchars[3]){
                D_800F5FB0.unk1C[0] = 0xFFFF;
                D_800F5FB0_sets(0x3C,2,1); 

                actor->actorVars.varB8.uchars[2] = 30;
            }
            break;
        case 30:
            if(D_800F5FB0.unk0 == 3 && func_80006924() == 0){
                actor->actorVars.varB8.uchars[2] = 40;
                cdata.unk42 = 2;

                D_800E69C0.unk0 = 1;
                D_800E69C0.unkD = 0x60;
                D_800E69C0.unk14 = 0x14;

                D_800E69C0.unk3C.uchar[0] = 1;
            }
            break;
        case 40:
            break;
    }
}

void func_8007835C(Actor* actor){
    s32 temp;
    
    if(actor->actorVars.varB8.uchars[2] == 0){
        temp = 1;
        
        D_800F0588.unk1B = (u64)temp;
        D_800F0588.unk1D = 0;
        D_800F0630 = 9;

        actor->unk52 = 0;
        actor->unk6A = 0xB;
        actor->unk50 = actor->unk52; 
        
        func_80008C6C(D_802BD6F8[cdata.unk1C], 1);
        actor->actorVars.varB8.uchars[2]++;
    }
    else if(actor->actorVars.varB8.uchars[2] > 150){
        if(D_800F3920.unk0 == 0){
            D_800E69C0.unk0 = 1;

            if(cdata.unk24 != 0){
                cdata.unk24--;
                cdata.unk42 = 1;
                
                D_800E69C0.unk0 = 1;
                D_800E69C0.unkD = 0x60;

                

                D_800E69C0.unk3C.uchar[0] = 1;
            }
            else{
                D_800E69C0.unk0 = 1;
                D_800E69C0.unkD = 0x60;
                D_800E69C0.unk14 = 0x1E;
                D_800E69C0.unkA = 0x3E7;
                
            }
        }
    }
    else{
        temp = actor->actorVars.varB8.uchars[2]++ ^ 0x96;
        
        if(temp == 0){
            func_800076E4(0x4E20, 0U);
            func_800073C0(0x18, 0);
            func_8000B120(3U);

            D_800F3920.unk2 = 0x96;
            D_800F3920.unk0 = 6;
        }
    }

    actor->pos.y -= 4.0f;
}

void func_800784C8(Actor* actor){
    D_801591C0_struct_unk4* temp_v0;
    
    temp_v0 = &D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4;
    
    if (temp_v0->unk14 == 1) {
        actor->actorVars.varAC.fp = (f32)temp_v0->unk4 * 0.002;
        actor->actorVars.varB0.fp = (f32)temp_v0->unk6 * 0.01;
    }
}

void func_80078554(Actor* actor){

    switch(actor->actorVars.varE8.shorts[0]){
        case 1:
            actor->actorVars.varAC.fp = 0.16f;
            actor->actorVars.varB0.fp = -0.5f;
            break;
        case 2:
            actor->actorVars.varAC.fp = -0.16f;
            actor->actorVars.varB0.fp = -0.5f;
            break;
        case 3:
            actor->actorVars.varB0.fp = -0.5f;
            break;
    }
}

void func_800785CC(Actor* actor){
    D_80159178_struct* sp74;
    f32 x;
    f32 y;
    f32 z;
    f32 fv1;
    f32 ang;
    s16 pad;
    s32 pad2;
    s16 id;
    s16 id2;
    s16 v1;
    s16 id3;
    Actor* actor1;
    
    if(actor->actorVars.varB8.shorts[0] != 0xB && actor->actorVars.varB8.shorts[0] != 0xC && actor->actorVars.varB8.shorts[0] != 0xD && actor->actorVars.varB8.shorts[0] != 0xF){
        sp74 = &((D_801591C0_struct_unk48*)D_80159178)[(s16)actor->actorVars.varC4.integer]; //fake
        
        actor->actorVars.varDC.fp = func_8000ADE0(actor->actorVars.varDC.fp + actor->actorVars.varAC.fp);
        actor->actorVars.varE4.fp += actor->actorVars.varB0.fp;

        if(actor->actorVars.varE4.fp < -50.0f){
            actor->actorVars.varE4.fp = -50.0f;
        }
        else if(actor->actorVars.varE4.fp > 50.0f){
            actor->actorVars.varE4.fp = 50.0f;
        }

        ang = DEG2RAD_ALT(actor->actorVars.varDC.fp);
        actor->actorVars.varE0.fp += 1.5;
        y = actor->actorVars.varE0.fp + actor->actorVars.varE4.fp;
        fv1 = (y - -5800.0f) * -0.02285714261f + 600.0f;

        x = sinf(ang) * fv1;
        z = cosf(ang) * fv1;

        actor->rot.y = func_8000ADE0(actor->actorVars.varDC.fp + 180.0f);

        func_80019058(sp74, cdata.nextstg, D_801414A4[actor->unk38]->unk54 * D_801AF8D8[actor->unk48].unk0, actor->pos.x, actor->pos.y, actor->pos.z, x - actor->pos.x, y - actor->pos.y, z - actor->pos.z);

        if(actor->actorVars.varB8.shorts[0] != 0xF && sp74->unk1 != 0){
            if(actor->actorVars.varB8.shorts[0] != 0xA){
                func_80008C6C(D_802BD67A[actor->unk48], 1);
                actor->health -= 20;
            }
            if(actor->health > 0){
                actor->unk52 = 0;
                actor->unk6A = 0xA;

                actor->actorVars.varB8.shorts[0] = 0xA;

                actor->unk50 = actor->unk52;

                if(func_80074E68(actor->actorVars.varDC.fp, func_80025C48(sp74->unk20 * 100.0f, sp74->unk18 * 100.0f)) > 0.0f){
                    actor->actorVars.varE8.shorts[0] = 1;
                }
                else{
                    actor->actorVars.varE8.shorts[0] = 2;
                }

                actor->actorVars.varC0.shorts[1] = 0xA;
            }
            else{
                actor->health = 0;
                actor->actorVars.varB8.shorts[0] = 0xB;
            }
        }

        actor->pos.x = x;
        actor->pos.y = y;
        actor->pos.z = z;

        if(6500.0f < y && actor->actorVars.varB8.shorts[0] != 0xB){
            if(cdata.item & 0x20000){
                v1 = 0;
            }
            else if(cdata.item & 0x40000000000){
                v1 = 0x26;
            }
            else{
                v1 = 0x31;
            }

            actor->unk52 = 0;
            actor->unk6A = 0;
            actor->unk50 = actor->unk52;

            if(v1 == 0){
                actor->actorVars.varB8.shorts[0] = 0xF;
                actor->actorVars.varC4.shorts[0] = 0;

                actor->actorVars.varA8.integer = 0;
                actor->actorVars.varA4.integer = 0;
                actor->actorVars.varAC.fp = 5.0f;
                actor->actorVars.varB0.fp = 60.0f;
            }
            else{
                actor->actorVars.varB8.shorts[0] = 0xC;
                actor->actorVars.varC4.shorts[0] = 1;

                actor->actorVars.varA8.integer = 0;
                actor->actorVars.varA4.integer = 0;
                actor->actorVars.varAC.fp = 5.0f;
                actor->actorVars.varB0.fp = 60.0f;

                id = func_80023644(6, 0x81, 1.0f, 6623.0f, -20.0f, 0.0f, 30.0f, 0.0f);
                func_80022F20(id, func_80039254);
                GET_ACTOR_PTR(id)->actorVars.varC8.integer = 4;
                GET_ACTOR_PTR(id)->unk68 = v1;
                
                
                id2 = func_80023498(8, 0x1C2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                func_80022F20(id2, func_800790FC);
                GET_ACTOR_PTR(id2)->actorVars.varA0.integer = id;
                GET_ACTOR_PTR(id2)->actorVars.varA4.integer = D_80159178->unk48[cdata.unk41].unk0;
                GET_ACTOR_PTR(id2)->actorVars.varA8.fp = 2.5f;

                D_800F0588.unk1D = 0;
                D_800F0630 = 0xC;
                D_800F0588.unkA2 = id3 =  func_80023498(8U, 0x1C2, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);

                func_80022F20(D_800F0588.unkA2, func_800064F0);
                actor1 = GET_ACTOR_PTR(D_800F0588.unkA2); 
                actor1->actorVars.varA0.integer = id;
                actor1->actorVars.varA4.integer = id2;
            }
        
        }
    }
}

void func_80078BA0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad;
    f32 fa0;
    f32 ang;
    f32 sp34;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 80;
            actor->dir.y = 8.0f;
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer != 0){
                actor->a -= 2;
                D_801414A0[actor->unk38]->unk6 = 45 - (actor->actorVars.varA0.integer % 3);

                sp34 = ((actor->pos.y + actor->dir.y) - -5800.0f) * -0.02285714261f + 600.0f + 10.0f ;
                
                ang = DEG2RAD_ALT(actor->actorVars.varDC.fp);
                
                actor->dir.x = sinf(ang) * sp34 - actor->pos.x;
                actor->dir.z = cosf(ang) * sp34 - actor->pos.z;

                func_80019F78(&D_800F9910, cdata.nextstg, actor->pos.x, actor->pos.y, actor->pos.z, actor->dir.x, actor->dir.y, actor->dir.z);
            
                if(D_800F9910.unk1 != 0){
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

    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 1, 2);
        func_80023FCC(idx);
    }
}

void func_80078DB0(s16 idx){
    s32 pad;
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 ang;
    f32 x;
    f32 y;
    f32 z;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            GET_ACTOR_PTR(idx)->status = 1;
            
            D_801414A0[actor->unk38]->unk54 = 80.0f;
            actor->actorVars.varAC.fp = func_8000ADE0(actor->rot.y + 180.0f);
            actor->actorVars.varB0.fp = 0.0f;
            break;
        case 1:
            actor->actorVars.varB0.fp += 10.0f;

            if(actor->actorVars.varB0.fp >= 360.0f){
                func_80023FCC(idx);
                return;
            }
            break;
    }

    actor = GET_ACTOR_PTR(idx);
    ang = DEG2RAD_ALT(func_8000ADE0(actor->actorVars.varB0.fp + actor->actorVars.varAC.fp));

    actor = GET_ACTOR_PTR(idx);
    actor->pos.x = GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA8.integer)->pos.x + sinf(ang) * 50.0f;
    actor->pos.y = GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA8.integer)->pos.y + 10.0f;
    actor->pos.z = GET_ACTOR_PTR(GET_ACTOR_PTR(idx)->actorVars.varA8.integer)->pos.z + cosf(ang) * 50.0f;

    if(D_80141CB0[idx].unk4 != -1){
        func_80030D0C(D_80141CB0[idx].unk4, 1, 2);
    }
}

s32 func_80078F78(Actor* actor){
    Vec3f* v0 = D_802BEDB8[actor->actorVars.varA8.integer];
    f32 fv0 = actor->actorVars.varB0.fp;
    Vec3f* v1 = &v0[actor->actorVars.varA4.integer];
    f32 dist;

    if(fv0 == 0.0f){
        fv0 = 1.0f;
    }

    actor->pos.x += (v1->x - actor->pos.x) / fv0;
    actor->pos.y += (v1->y - actor->pos.y) / fv0;
    actor->pos.z += (v1->z - actor->pos.z) / fv0;

    dist = sqrtf(SQ(actor->pos.x - v1->x) + SQ(actor->pos.y - v1->y) + SQ(actor->pos.z - v1->z));
    
    if(dist < actor->actorVars.varAC.fp){
        actor->actorVars.varA4.integer++;
        
        v1 = &v0[actor->actorVars.varA4.integer];
        
        if(v1->x == 0.0f && v1->y == 0.0f && v1->z == 0.0f){
            return 1;
        }
        
    }
    else{
        return 0;
    }

    return 0;
}


void func_800790FC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor1 = GET_ACTOR_PTR(actor->actorVars.varA0.integer);
    Actor* actor2 = GET_ACTOR_PTR(actor->actorVars.varA4.integer);
    
    actor->pos.x = (actor->actorVars.varA8.fp * (actor2->pos.x - actor1->pos.x)) + actor1->pos.x;
    actor->pos.y = (actor->actorVars.varA8.fp * (actor2->pos.y - actor1->pos.y)) + actor1->pos.y;
    actor->pos.z = (actor->actorVars.varA8.fp * (actor2->pos.z - actor1->pos.z)) + actor1->pos.z;
    
}

void func_80079180(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    
    func_80073B80(D_800F3940[(s16)actor->actorVars.varC4.integer], &D_80159178->unk48[(s16)actor->actorVars.varC4.integer].unk4);
    func_80077164(actor, idx);

    switch(actor->actorVars.varB8.shorts[0]){
        case 0:
            func_8007B0D4(actor);
            break;
        case 15:
            func_8007928C(actor);
            break;
    }

    func_8007B4C4(actor);
    func_80072FB0(actor);

    cdata.unk10 = actor->pos.x;
    cdata.unk14 = actor->pos.y + (80.0f * actor->scale.y);
    cdata.unk18 = actor->pos.z;
    
    actor->actorVars.varAC.fp = 0.0f;
    actor->actorVars.varB0.fp = 0.0f;
    actor->actorVars.varB4.fp = 0.0f;
}

void func_8007928C(Actor* actor){
    switch(actor->actorVars.varB8.uchars[2]){
        case 0:
            actor->actorVars.varB8.uchars[2] = 20;
            actor->actorVars.varB8.uchars[3] = 30;
            D_800F0588.unk1B = 1;
            D_800F0588.unk1D = 0;
            D_800F0630 = 0xA;
            break;
        case 10:
            break;
        case 20:
            actor->actorVars.varB8.uchars[3]--;

            if(!actor->actorVars.varB8.uchars[3]){
                actor->actorVars.varB8.uchars[2] = 30;
                D_800F5FB0.unk1C[0] = 0xFFFF;
                D_800F5FB0_sets(0x3C, 2, 1);
            }
            break;
        case 30:
            if(D_800F5FB0.unk0 == 3 && func_80006924() == 0){
                actor->actorVars.varB8.uchars[2] = 10;
                D_800E69C0.unk0 = 1;
                cdata.unk42 = 0;
                D_800E69C0.unkD = 0x60;

                if(D_800F3940[cdata.unk41]->unk0[15] && D_800F3940[cdata.unk41]->unk0[14]){
                    D_800F3950 = 6;
                }
                else{
                    D_800F3950 = 0xD;
                }

                D_800E69C0.unk14 = 0x14;
                D_800E69C0.unk3C.uchar[0] = 1; 

            }
            break;
    }
}

void func_800793F4(u16 arg0, u8* arg1){
    u16 i;
    u16 t8;
    u16 t3;
    u16 t6;
    
    if(arg0 > 9999){
        for(i = 0; i < 4; i++){
            *arg1++ = 9;
        }
    }
    else{
        t8 = arg0 / 1000;
        *arg1++ = t8;
        arg0 -= (t8 * 1000);

        t8 = arg0 / 100;
        *arg1++ = t8;
        arg0 -= (t8 * 100);

        t8 = arg0 / 10;
        *arg1++ = t8;
        *arg1++ = arg0 - (t8 * 10);
    }
}

void func_80079538(func_80079538_arg0** arg0, func_80079538_arg1* arg1, u16 arg2){
    u16 i;
    func_80079538_arg1* v0 = arg1;
    func_80079538_arg0* v1 = arg0;
    (func_80079538_arg0**)v1 += arg2;

    for(i = 0; i < 8; i++, v0++, v1++){
        v0->unk0 = v1->unk0;
    }
}

void func_8007957C(u32 arg0, u8* arg1){
    u16 i;
    
    if(arg0 > 594000){
        for(i = 0; i < 6; i++){
            *arg1++ = 9;
        }
    }
    else{
        *arg1++ = arg0 / 60000;
        arg0 -= (arg0 / 60000) * 60000;
        *arg1++ = arg0 / 6000;
        arg1 += 3;
        arg0 -= (arg0 / 6000) * 6000;
        arg1[-3] = arg0 / 1000;
        arg0 -= (arg0 / 1000) * 1000;
        arg1[-2] = arg0 / 100;
        arg0 -= (arg0 / 100) * 100;
        arg1[-1] = arg0 / 10;
        arg0 -= (arg0 / 10) * 10;
        arg1[0] = arg0;
    }
}
