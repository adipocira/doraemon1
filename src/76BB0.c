#include "76BB0.h"
#include "9320.h"
#include "B4E0.h"
#include "11DF0.h"
#include "23B20.h"
#include "2DE50.h"
#include "386E0.h"
#include "73660.h"
#include "7F2B0.h"
#include "zzDebug.h"
#include "zzGame.h"
#include "segments.h"
#include "global.h"
#include "common.h"
#include "controller.h"

#include "libc/math.h"

extern u8 D_80159318;

extern u16 D_8015A392;
extern s16 D_802BDE3E;

extern f32 D_80159170;

extern u8 D_802BDB7C[];

extern s16 D_8015A370[];
extern u16 D_8015B1A0[];
extern u16 D_8015B3A0[];
extern u16 D_802BD1E8[];
extern u16 D_802BD208[];
extern u16 D_802BD226[];
extern u16 D_802BD228[];
extern u16 D_802BD234[];
extern u16 D_802BD278[];
extern u16 D_802BD65C[];
extern s16 D_802BD668[];
extern s16 D_802BD6F8[];
extern u16 D_80352A90[];

extern s16 D_802BD49E[][0xE]; 

extern u8* D_801C7F00[];
extern u8* D_801C7F38[];
extern u8* D_801C7F0C[];
extern u8* D_801C7F1C[];

extern u16* D_802BD07C[];
extern u16* D_802BD61C[];

extern Vec3f* D_802BD2CC;

s16 func_80075FB0(Actor* actor, f32 rot, f32 dist){
    f32 xDiff;
    f32 zDiff;
    f32 yDiff;
    f32 x = actor->pos.x;
    f32 y = actor->pos.y;
    f32 z = actor->pos.z;
    f32 dist3;
    f32 rotPre;
    Actor* actorP;
    s16 dists;
    s16 ret = -1;
    f32 rot1 = actor->rot.y - rot;
    f32 rot2 = actor->rot.y + rot;
    u16 i;
    u8 s4;
    s32 a0;

    (void)"ITM %llx\n";

    if(rot1 < 0.0f){
        rotPre = rot2;
        rot2 = rot1 + 360.0f;
        rot1 = rotPre;
        s4 = 1;
    }
    else if(rot2 >= 360.0f){
        rotPre = rot1;
        rot1 = rot2 - 360.0f;
        rot2 = rotPre;
        s4 = 1;
    }
    else{
        s4 = 0;
    }

    for(i = 20, actorP = GET_ACTOR_PTR(i); i < 40; i++, actorP++){
        if(!(actorP->flags & 0x100) && actorP->unk0 != 0){
            xDiff = actorP->pos.x - x;
            zDiff = actorP->pos.z - z;
        
            dists = func_80025C48(zDiff, xDiff);
    
            a0 = rot1 <= dists && dists <= rot2;
            if((a0 != s4) != 0){
                yDiff = y - actorP->pos.y;
                dist3 = sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
                
                if(dist3 < dist){
                    dist = dist3;
                    ret = dists;
                }
            }
        }
    }

    return ret;
}

s16 func_800761BC(Actor* actor, f32 dist){
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 x = actor->pos.x;
    f32 y = actor->pos.y;
    f32 z = actor->pos.z;
    Actor* actorP;
    s16 ret = -1;
    u16 i;
    f32 dist1;


    for(i = 20, actorP = GET_ACTOR_PTR(20); i < 40; i++, actorP++){
        if(!(actorP->flags & 0x8100) && actorP->unk0 != 0){
            xDiff = actorP->pos.x - x;
            yDiff = actorP->pos.y - y;
            zDiff = actorP->pos.z - z;

            dist1 = sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
        
            if(dist1 < dist){
                dist = dist1;
                ret = i;
            }
        }
    }

    return ret;
}

void func_800762B0(Actor* actor){
    D_801414A0_ptr_struct* v1;
    s16 v0;
    s16 v0_3;
    
    if(actor->actorVars.varB8.shorts[0] != 0xF && actor->actorVars.varB8.shorts[0] != 0xB && D_80159318 != 0){
        if(actor->actorVars.varC8.shorts[0] != 2){
            if(actor->actorVars.varC4.shorts[0] == 1){
                actor->actorVars.varD0.shorts[0] = 1320;
            }
        }
        else{
            if(actor->actorVars.varD0.shorts[0] != 0){
                actor->actorVars.varD0.shorts[0]--;

                if(actor->actorVars.varD0.shorts[0] == 0){
                    actor->dir.y = D_80159170 / 2;

                    actor->actorVars.varA4.fp = D_80159170;
                    
                    actor->actorVars.varB8.shorts[0] = 6;
                    actor->unk6A = 0;

                    actor->actorVars.varBC.shorts[1] = 0;
                    actor->actorVars.varC8.shorts[0] = 0;

                    actor->unk52 = 0; 

                    actor->unk50 = actor->unk52;

                    func_80008C6C(D_802BD6F8[actor->unk48], 0);

                }
                else{
                    v1 = D_801414A0[actor->unk38 + D_802BD234[actor->unk48]];
                    v0 = v0_3 = actor->actorVars.varD0.shorts[0];

                    if(v0_3 > 600){
                        v0 = 34;
                    }
                    else{
                        v0 /= 20;
                    }

                    v1->unk34 = func_8000ADE0(v1->unk34+v0);
                    actor->actorVars.varD0.shorts[1] += v0;

                    if(actor->actorVars.varD0.shorts[1] > 300){
                        actor->actorVars.varD0.shorts[1] = 0;
                        func_80008C6C(D_802BDE3E, 1);
                    }
                }
            }
        }
    }

}

//todo
#ifdef NON_MATCHING
void func_8007645C(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_801AF8C4_struct* v1;
    D_801414A0_ptr_struct* s0;
    D_801AF8C4_struct_unkC* s1;
    D_803361C0_struct* a3;
    D_803050E4_struct* s2;
    D_803050E4_struct* tmp;
    D_802BD494_struct* a2;
    Vec3f* s3;
    u16 i;
    f32 fv0;
    s16 temp;

    v1 = &D_801AF8C4[cdata.unk1C];
    temp = v1->unk6 - 1;
    
    s1 = v1->unkC;
    s3 = &D_802BD2CC[cdata.unk1C];
    a3 = &D_803361C0[cdata.unk1C];
    a2 = &D_802BD494[cdata.unk1C];
    s2 = D_803050E4[a2->unkA][a2->unk12];
    

    for(i = 0; i < temp; i++, s1++, s2++){
        s0 = D_801414A0[actor->unk38 + 0x13 + i];

        s0->unk6 = s0->unk8 = s1->unk12;
        
        if(i == 0){
            s0->unkC = s0->unk18 = s3->x - 0.0;

            s0->unk10 = s0->unk1C = s3->y - 57.58;

            s0->unk14 = s0->unk20 = s3->z - 0.0;
        }
        else{
            s0->unkC = s0->unk18 = s1->unk0;

            s0->unk10 = s0->unk1C = s1->unk4;

            s0->unk14 = s0->unk20 = s1->unk8;
        }

        guTranslate(&s0->mtx, s0->unkC, s0->unk10, s0->unk14);

        if(s1->unkC != 0xFFFF){
            s0->unk0 = s1->unkC + 0x13;
        }
        else{
            s0->unk0 = 0xFFFF;
        }
        if(s1->unkE != 0xFFFF){
            s0->unk2 = s1->unkE + 0x13;
        }
        else{
            s0->unk2 = 0xFFFF;
        }

        s0->unk24 = s2->unk0;
        s0->unk28 = s2->unk2;
        s0->unk2C = s2->unk4;
        s0->unk30 = s2->unk6;
        s0->unk34 = s2->unk8;
        s0->unk38 = s2->unkA;
        
    }

    (&D_801414A0[actor->unk38 + 0x13])[a3->unk8]->unk48 = a3->unk0;
    (&D_801414A0[actor->unk38 + 0x13])[a3->unk8]->unk4C = a3->unk4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/76BB0/func_8007645C.s")
#endif

void func_80076768(){
    Actor* actor;
    Vec3f pos;
    Vec3f rot;
    s16 varC8;
    s16 unk6A;
    s16 varB8;
    s16 varD0;
    s16 id;
    s32 health;

    id = D_80159178->unk48[cdata.unk41].unk0;
    actor = GET_ACTOR_PTR(id);

    pos.x = actor->pos.x;
    pos.y = actor->pos.y;
    pos.z = actor->pos.z;

    rot.x = actor->rot.x;
    rot.y = actor->rot.y;
    rot.z = actor->rot.z;

    health = actor->health;
    unk6A = actor->unk6A;
    varC8 = actor->actorVars.varC8.shorts[0];
    varB8 = actor->actorVars.varB8.shorts[0];
    varD0 = actor->actorVars.varD0.shorts[0];
    

    func_80023FCC(id);
    D_80159318 = 0;

    if(cdata.nextstg == ZZ_GAME0_LEVEL_1_2){
        id = func_800238B0(0, 6, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z);

        actor->unk6C = D_802BD49E[cdata.unk1C][0];
        func_80022F20(id, func_8002D3FC);
        func_80008C6C(D_802BD668[cdata.unk1C], 0);
        actor->unk44 = D_802BD61C[cdata.unk1C];
    }
    else if(cdata.nextstg == ZZ_GAME0_LEVEL_3_2){
        id = func_800238B0(0, 7, pos.x, pos.y, pos.z, 0.0f, 0.0f, 0.0f);
        
        func_8007645C(id);
        func_80008C6C(D_802BD668[actor->unk48], 0);
        actor->unk44 = D_802BD61C[cdata.unk1C];
        actor->actorVars.varC4.shorts[1] = cdata.unk41;
        return;
    }
    else if(cdata.nextstg == ZZ_GAME0_LEVEL_2_2){
        id = func_800238B0(0, 8, pos.x, pos.y, pos.z, 0.0f, rot.y, 0/*.0*/);
        actor->unk6C = D_802BD49E[cdata.unk1C][0];
        func_80022F20(id, func_8002D518);
        actor->unk44 = D_802BD61C[cdata.unk1C];
    }
    else {
        if(cdata.nextstg == ZZ_GAME0_LEVEL_3_3){
            D_80159318 = 1;
        }

        id = func_800238B0(0, cdata.unk1C, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z);
        actor->unk6C = D_802BD49E[actor->unk48][0];
        actor->unk44 = D_802BD61C[actor->unk48];
        
        if(cdata.unk6D != 1){
            func_80008C6C(D_802BD668[actor->unk48], 1);
        }
        else{
            cdata.unk6D = 0;
        }
    } 

    func_80076B64(id);

    actor->actorVars.varCC.uchars[1] = 0xFF;
    actor->actorVars.varCC.shorts[1] = 0;
    actor->actorVars.varCC.uchars[0] = 0;

    func_80077164(actor, id);

    actor->health = health;
    actor->unk4E = 2;
    actor->actorVars.varC4.shorts[1] = cdata.unk41;
    actor->actorVars.varC4.shorts[0] = 0;
    actor->actorVars.varB8.shorts[0] = varB8;
    actor->actorVars.varD0.shorts[0] = varD0;
    actor->unk6A = unk6A;
    actor->actorVars.varC8.shorts[0] = varC8;
    actor->unk52 = 0;
    actor->unk50 = actor->unk52;
    ((D_801591C0_struct_unk8*)D_80159178->unk8)[actor->actorVars.varC4.shorts[1]].unk0 = 0.0f;
}

//todo
#ifdef NON_MATCHING
void func_80076B64(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_802BD314_struct* v0;
    D_802BD314_struct* v1;

    if(cdata.unk6B !=  0){
        if(GET_ACTOR_PTR(idx)->unk48 < 6){
            if(D_80159318 != 0){
                func_800242F0(idx, D_802BD234[actor->unk48], 0x8C);
            }
            else{
                func_800242F0(idx, D_802BD234[actor->unk48], 0xFFFF);
            }
        }
        switch(GET_ACTOR_PTR(idx)->unk48){
            case 0:
                if(cdata.item & 0x1){
                    func_800242F0(idx, D_802BD228[GET_ACTOR_PTR(idx)->unk48], 0x22);
                    func_800247E8(idx, D_802BD228[GET_ACTOR_PTR(idx)->unk48], 1.0f);
                }
                break;
            case 1:
                if(cdata.item & 0x2){
                    func_800242F0(idx, D_802BD228[GET_ACTOR_PTR(idx)->unk48], 0x6B);
                }
                break;
            case 3:
                if(cdata.item & 0x8){
                    func_800242F0(idx, D_802BD226[GET_ACTOR_PTR(idx)->unk48], 0x55);
                    func_800242F0(idx, D_802BD228[GET_ACTOR_PTR(idx)->unk48], 0x54);
                } 
                break;
            case 4:
                if(cdata.item & 0x10){
                    func_800242F0(idx, D_802BD228[GET_ACTOR_PTR(idx)->unk48], 0x6E);
                }
                break;
            case 6:
                v0 = &D_802BD314[cdata.unk1C];
                    
                func_800242F0(idx, 0x12, v0->unk0[0].unk0);
                func_8002443C(idx, 0x12, v0->unk0[0].unk4, v0->unk0[0].unk8, v0->unk0[0].unkC);
                func_800242F0(idx, 0x13, v0->unk0[1].unk0);
                func_8002443C(idx, 0x13, v0->unk0[1].unk4, v0->unk0[1].unk8, v0->unk0[1].unkC);
            
                break;
            case 8:
                v1 = &D_802BD3D4[cdata.unk1C];

                if(cdata.unk1C == 0){
                    func_800242F0(idx, 7, 0xFFFF);
                }
                    
                func_800242F0(idx, 0x8, v1->unk0[0].unk0);
                func_8002443C(idx, 0x8, v1->unk0[0].unk4, v1->unk0[0].unk8, v1->unk0[0].unkC);
                func_800242F0(idx, 0x9, v1->unk0[1].unk0);
                func_8002443C(idx, 0x9, v1->unk0[1].unk4, v1->unk0[1].unk8, v1->unk0[1].unkC);
                    
                D_802BD63C->unkE0 = D_802BD65C[cdata.unk1C];
                break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/76BB0/func_80076B64.s")
#endif

void func_80076F2C(u16 idx){
    s16 id = idx - 0x14;
    u8 v1;

    if(id >= 0){
        v1 = D_802BDB7C[id];
        
        if(v1 != 0xFF){
            cdata.item |= (u64)1 << v1;
        }
    }
}

s32 func_80076FA0(u16 idx){
    s16 id = idx - 0x14;
    u8 v1;

    if(id < 0){
        if(idx == 0){
            id = 0x2E;
        }
        else{
            return -1;
        }
    }

    v1 = D_802BDB7C[id];

    if(v1 == 0xFF){
        return -1;
    }

    if(cdata.item & (u64)1 << v1){
        return 0;
    }
    else{
        return 1;
    }

}

u16 func_80077050(){
    u16 ret = 0;

    if(cdata.item & 0x1){
        ret++;
    }
    if(cdata.item & 0x2){
        ret++;
    }
    if(cdata.item & 0x4){
        ret++;
    }
    if(cdata.item & 0x8){
        ret++;
    }
    if(cdata.item & 0x10){
        ret++;
    }

    return ret;
}

void func_800770FC(){
    Actor* actor = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    actor->actorVars.varB8.shorts[0] = 0xF;
    
    actor->unk52 = 0;
    actor->unk50 = actor->unk52;
    actor->unk6A = 0;
    
    actor->actorVars.varCC.uchars[1] = 0xFF;
    actor->actorVars.varCC.shorts[1] = 0;
    actor->actorVars.varCC.uchars[0] = 4;
}

void func_80077164(Actor* actor, s16 idx) {
    D_803361C0_struct* v0;
    s16 a2;
    u8 a1;
    u8 t0;
    D_80336980_struct** t1;
    D_80336980_struct* t2;
    u8 a3;
    u8 t3;
    D_803361C0_struct_unk4* v1;

    if (actor->unk48 == 6 || actor->unk48 == 8) {
        a3 = cdata.unk1C;
    } else {
        a3 = actor->unk48;
    }
    if (actor->actorVars.varC8.uchars[2] == 1) {
        t0 = a3+6;
    } else {
        t0 = a3;
    }
    if (actor->unk48 == 0xC) {
        t0 = 0xC;
        a3 = 5;
    }
    
    t1 = D_80336980[a3];
    t2 = t1[actor->actorVars.varCC.uchars[0]];
    v0 = &D_803361C0[t0];
    
    v1 = v0->unk4;
    
    t3 = actor->actorVars.varCC.uchars[1];
    
    if (actor->actorVars.varCC.shorts[1] == 0) {
        t3++;
        a2 = t2[t3].unk0;
        
        if (a2 < 0) {
            if (a2 == -1) {
                t3 = t2[t3].unk2;
            } else if (a2 == -3) {
                actor->actorVars.varCC.uchars[0] = t2[t3].unk2;
                t3 = t2[t3 + 1].unk2;
                t2 = t1[actor->actorVars.varCC.uchars[0]];
            } else if (a2 == -2) {
                t3--;
            }
        }
        
        actor->actorVars.varCC.uchars[1] = t3;
        actor->actorVars.varCC.shorts[1] = t2[t3].unk2;
    }
    actor->actorVars.varCC.shorts[1]--;
    
    if (actor->unk48 == 6) {
        a1 = actor->unk38 + 0x12;
    } else if (actor->unk48 == 8) {
        a1 = actor->unk38 + 8;
    } else {
        a1 = actor->unk38 + v0->unk8;
    }
    
    D_801414A0[a1]->unk48 = v0->unk0;
    D_801414A0[a1]->unk4C = &v1[t2[t3].unk0];
}

void func_8007734C(Actor* actor, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6){
    f32 fs0 = (f32)arg5 / (f32)arg6;

    actor->pos.x = actor->actorVars.rawVars[arg2].fp + (actor->actorVars.rawVars[arg1].fp - actor->actorVars.rawVars[arg2].fp) * fs0;
    actor->pos.y = actor->actorVars.rawVars[arg2 + 1].fp + (actor->actorVars.rawVars[arg1 + 1].fp - actor->actorVars.rawVars[arg2 + 1].fp) * fs0;
    actor->pos.z = actor->actorVars.rawVars[arg2 + 2].fp + (actor->actorVars.rawVars[arg1 + 2].fp - actor->actorVars.rawVars[arg2 + 2].fp) * fs0;

    actor->scale.x =  actor->scale.y =  actor->scale.z = actor->actorVars.rawVars[arg2 + 3].fp + (actor->actorVars.rawVars[arg1 + 3].fp - actor->actorVars.rawVars[arg2 + 3].fp) * fs0;

    actor->rot.x = func_8000ADE0(actor->actorVars.rawVars[arg4].fp + func_80074E68(actor->actorVars.rawVars[arg4].fp, actor->actorVars.rawVars[arg3].fp) * fs0);
    actor->rot.y = func_8000ADE0(actor->actorVars.rawVars[arg4 + 1].fp + func_80074E68(actor->actorVars.rawVars[arg4 + 1].fp, actor->actorVars.rawVars[arg3 + 1].fp) * fs0);
    actor->rot.z = func_8000ADE0(actor->actorVars.rawVars[arg4 + 2].fp + func_80074E68(actor->actorVars.rawVars[arg4 + 2].fp, actor->actorVars.rawVars[arg3 + 2].fp) * fs0);
}

void func_800774FC(Actor* actor0, Actor* actor1){
    actor1->pos.x = actor0->pos.x;
    actor1->pos.y = actor0->pos.y;
    actor1->pos.z = actor0->pos.z;
    
    actor1->scale.x = actor0->scale.x;
    actor1->scale.y = actor0->scale.y;
    actor1->scale.z = actor0->scale.z;
    
    actor1->rot.x = actor0->rot.x;
    actor1->rot.y = actor0->rot.y;
    actor1->rot.z = actor0->rot.z;
}

s32 func_80077548(){
    Actor* actor = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);

    if(actor->actorVars.varB8.shorts[0] == 0xB || actor->actorVars.varB8.shorts[0] == 0xF || actor->actorVars.varC4.shorts[0] == 0){
        return 0;
    }
    switch(actor->actorVars.varC8.shorts[0]){
        case 0:
            actor->actorVars.varB8.shorts[0] = 0;
            actor->unk6A = 0;
            break;
        case 1:
            actor->actorVars.varB8.shorts[0] = 0xC;
            actor->unk6A = 0xD;
            break;
        case 2:
            actor->actorVars.varB8.shorts[0] = 0x10;
            actor->unk6A = 0x12;
            break;
    }

    actor->unk52 = 0;
    actor->unk50 = actor->unk52;
    
    actor->actorVars.varA8.fp = 0.0f;
    actor->actorVars.varA0.fp = 0.0f;
    
    actor->flags |= 0x4000;

    return 1;
}

void func_80077630(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    u16* v1 = D_8015B1A0;
    u16* a2 = D_8015B3A0;
    u16* a1 = D_802BD61C[actor->unk48];
    
    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            for(i = 0; i < 0x100; i++, v1++, a2++, a1++){
                 *v1 = *a2 = *a1;
            }

            func_8007E6B0(D_8015B1A0, D_8015B1A0, 0x70, -6);
            actor->unk44 = D_8015B3A0;
            GET_ACTOR_PTR(idx)->status = 1;
            break;
        case 1:
            func_8007E7D0(D_8015B1A0, a1, D_8015B3A0, 0, 0x70);
            GET_ACTOR_PTR(idx)->status = 2;
            
            break;
        case 2:
            
            break;
    }
}

void func_80077744(s32 arg0){
    u16 s2 = D_802BD278[arg0];

    if(s2 & 0x1){ROMCOPY(D_2EF5C0, D_801EB320);}
    if(s2 & 0x10){ROMCOPY(D_2F8770, D_801F5320);}
    if(s2 & 0x20){ROMCOPY(D_2FF9E0, D_801F5320);}
    if(s2 & 0x2){ROMCOPY(D_302530, D_801FCB20);}
    if(s2 & 0x8){ROMCOPY(D_30D4E0, D_801FCB20);}
    if(s2 & 0x4){ROMCOPY(D_31A690, D_801FCB20);}
}

void func_800778C0(u16 arg0, u16 arg1, u16 arg2){
    u8* a3;
    u8* v1;
    s32 i;
    s32 v0;
    s32 a1;

    a3 = D_801C7F00[0];
    v1 = D_801C7F38[arg0];
    
    do{
        *a3++ = *v1;
    }while(*v1++ != 0xFE);
    
    v1 = D_801C7F0C[arg1]+1;
    
    do{
        *a3++ = *v1;
    }while(*v1++ != 0xFF);

    v1 = D_801C7F1C[arg2];
    a3 = D_801C7F00[1];

    *a3++ = *v1++;

    if(arg2 == 6){
        v0 = func_80039110();
        a1 = v0 / 10;

        if(a1 != 0){
            *a3++ = a1+1;
        }

        a1 = v0 % 10;

        *a3++ = a1 + 1;
    }

    do{
        *a3++ = *v1;
    }while(*v1++ != 0xFF);
}

void func_80077A48(){
    s16* temp = D_8015A370;
     
    if(controllers[0]->unk0.unkA2){
        temp[0]++;

        if(temp[0] >= 0x10){
            temp[0] = 0;
        }
        
        temp[*temp+1] = controllers[0]->unk0.unkA2;
        func_80077AC8(&D_8015A370);
    }
}

void func_80077AC8(u16* arg0){
    u16 i;
    u16 j;
    u16* a2;
    s16 v1;
    s16 a0;

    for(i = 0, j = 1; i < 7; i++, j*=2){
        a2 = D_802BD07C[i];
        v1 = arg0[0];
        a0 = a2[0]+1;
        
        while(a0 >= 2){
            if(a2[a0] == arg0[v1--+1]){
                if(v1 < 0){
                    v1 = 0xF;
                }
                a0--;
            }
            else{
                break;
            }
        }
        
        if(a0 == 1){
            func_80008C6C(a2[1], 0);
            D_8015A392 ^= j;
        }
    }
    if(D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_5)){
        D_8015A392 ^= DEBUG_FLAG(ZZ_DEBUG_FLAG_5);
        D_800E69C0.unk0 = 1;
        D_800E69C0.unk14 = 0x1E;
        D_800E69C0.unkA = 0x64;
    }
    if(D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_6)){
        if(cdata.item);
        D_8015A392 ^= DEBUG_FLAG(ZZ_DEBUG_FLAG_6);
        cdata.item = -1;
    }
}

void func_80077C3C(s16 idx){
    static s16 D_800B6390[] = {
        0x48, 0x48, 0x46, 0x46, 0x47, 0x47, 0x45
    };
    
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varA0.integer = 14;
            GET_ACTOR_PTR(idx)->status = 1;
        case 1:
            actor->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer == 0){
                func_80023FCC(idx);
            }
            else{
                D_801414A0[actor->unk38]->unk6 = D_800B6390[actor->actorVars.varA0.integer / 2];
            }
            break;
    }
}

void func_80077CF4(){
    func_80077D54(D_802BD1E8, D_80352A90, 0x10);
}

void func_80077D24(){
    func_80077D54(D_802BD208, D_80352A90, 0x10);
}

void func_80077D54(u16* arg0, u16* arg1, u16 arg2){
    u16 i;

    for(i = 0; i < arg2; i++){
        *arg1++ = *arg0++;
    }
}

void func_80077D90(f32 arg0){
    static f32 D_800B63A0[] = {
        1.0f, 1.2f, 1.0f, 1.2f, 0.5f, 1.0f, 1.2f, 1.2f, 1.2f, 1.2f
    };
    u16 i;

    for(i = 0; i < 10; i++){
        D_802BD494[i].unk14 = D_800B63A0[i]*arg0;
    }
}
