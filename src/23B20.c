#include "23B20.h"
#include "29980.h"
#include "1D870.h"
#include "73660.h"
#include "11F10.h"
#include "libc/math.h"
#include "actor.h"

typedef struct D_801AF8C4_struct{
    u8 unk0[0x4];
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18; 
    s32 unk1C;
    ActorUnk80Func unk20;
    s32 flags;
}D_801AF8C4_struct;

extern D_801AF8C4_struct D_801AF8C4[];
extern u8 D_80142AB0[];
extern s32 D_801B52E0[];

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

extern u16 D_800B50F0[];

extern s16 D_801AF810[];

extern u16 D_80141CA2;

extern u16 D_800B5130[];

typedef struct D_80141CB0_struct{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
}D_80141CB0_struct;
extern D_80141CB0_struct D_80141CB0[];

extern s16 D_801545E0;
extern s16 D_801545E2;
extern f32 D_801545E4;
extern f32 D_801545E8;
extern f32 D_801545EC;
extern f32 D_801545F0;
extern f32 D_801545F4;
extern f32 D_801545F8;

extern f32 D_801545FC;
extern f32 D_80154600;
extern f32 D_80154604;
extern f32 D_80154608;
extern f32 D_8015460C;
extern f32 D_80154610;

extern u16 D_80141CA2;
 
extern f32 D_80154614;
extern f32 D_80154618;
extern f32 D_8015461C;
extern f32 D_80154620;
extern f32 D_80154624;

typedef struct D_80152360_struct{
    u8 unk0;
    u8 unk1[0x4];
}D_80152360_struct;

extern D_80152360_struct D_80152360[];

typedef struct D_801525E0_struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 unk6[0x6];
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
}D_801525E0_struct;

extern D_801525E0_struct D_801525E0[];

void func_80022F20(s16 idx, ActorUnk80Func arg1){
    Actor* actor = GET_ACTOR_PTR(idx);

    (void)" set default motion %d, %d\n";
    (void)" set default motion %d, %d\n";

    actor->unk80 = arg1,
    actor->status = 0;
}

void func_80022F48(s16 idx, s16 arg1){
    Actor* actor = GET_ACTOR_PTR(idx);
    
    actor->unk52 = 0;
    actor->unk6A = arg1;
    actor->unk50 = actor->unk52;
}

#ifdef NON_MATCHING
void func_80022F7C(s32* arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 pad;
    f32 temp_ft4;
    s32 sp7C;
    s32 var_v0;
    s32 sp74;
    s32 pad4;
    s32 temp_a2;
    s32 pad3;
    s32 pad2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 i;
    s32 var_ft5;
    s32 var_t1;
    s32 temp_a0;
    Actor* sp44;
    s32 temp_t6;

    while (*arg0 != -1) {
        // this is probably bitfield stuff
        temp_t6 = (u32)(*arg0 & 0x03C00000) >> 0x16; // max 15 if *arg0 = 0xFFFFFFFF
        sp7C = (u32)(*arg0 & 0x7C000000) >> 0x1A; // max 31 if *arg0 = 0xFFFFFFFF
        sp74 = *arg0 & 0x200000;
        if (*arg0 & 0x80000000) {
            var_v0 = func_80023644(temp_t6, *arg0, arg0[1] + arg1, arg0[2] + arg2, arg0[3] + arg3, arg0[4], arg0[5], arg0[6]);
            arg0 += 7;
        } else {
            var_v0 = func_80023644(temp_t6, *arg0, arg0[1] + arg1, arg0[2] + arg2, arg0[3] + arg3, 0.0f, 0.0f, 0.0f);
            arg0 += 4;
        }
        if (var_v0 != -1) {
            sp44 = GET_ACTOR_PTR(var_v0);
            if (sp74 != 0) {
                sp44->unk64 = *arg0;
                arg0++;
            }
            if (sp7C != 0) {
                for (i = 0; i != sp7C; i++) {
                    ((s32_f32_ptr*)&sp44->unkA0)[i].integer = arg0[0];
                    arg0++;
                }
            }
        } else {
            if (sp74 != 0) {
                arg0++;
            }
            if (sp7C != 0) {
                for (i = 0; i != sp7C; i++) {
                    arg0++;
                }
            }
        }
        if (*arg0 & 0x100000) {
            var_t1 = *arg0 & 0xFFFF;
            if (*arg0 != -1U) {
                arg0++;
                if (var_v0 != -1U) {
                    while (var_t1 != 0) {
                        temp_v1 = *arg0 & 0xFFFF0000;
                        temp_a2 = *arg0 & 0xFFFF;
                        arg0++;
                        switch (temp_v1) {
                            case 0:
                                ((s32_f32_ptr*)&sp44->unkA0)[temp_a2].integer = var_v0;
                                var_t1--;
                                break;
                            case 0x10000:
                                sp44->unk84 = D_801B52E0[temp_a2];
                                var_t1--;
                                break;
                            case 0x20000:{
                                temp_a0 = temp_a2 << 8;
                                for (i = temp_a0; i != temp_a0 + (temp_a2 & 0xFF); i++) {
                                    ((s32_f32_ptr*)&sp44->unkA0)[i].fp = ((s32_f32_ptr*)&sp44->unkA0)[i + 1].integer;
                                }
                                var_t1--;
                            }
                                break;
                            case 0x40000:
                                sp44->unk68 = temp_a2;
                                var_t1--;
                                break;
                            default:
                                break;
                        }
                    }
                } else {
                    while (var_t1 != 0) {
                        temp_v1 = *arg0 & 0xFFFF0000;
                        arg0++;
                        switch (temp_v1) {
                        case 0x0:
                            var_t1--;
                            break;
                        case 0x10000:
                            var_t1--;
                            break;
                        case 0x20000:
                            var_t1--;
                            break;
                        case 0x40000:
                            var_t1--;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/23B20/func_80022F7C.s")
#endif

void func_80023468(s32* arg0){
    func_80022F7C(arg0, 0.0f, 0.0f, 0.0f);
}

s16 func_80023498(u16 arg0, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7){
    u16 temp;
    s32 temp2;
    u16 from; 
    u16 to;

    temp = D_800B50F0[arg0 * 2];
    from = temp;
    to = D_800B50F0[arg0 * 2 + 1];
    for (; from < to; from++){
        if(GET_ACTOR_PTR(from)->unk0 == 0 && GET_ACTOR_PTR(from)->unk67 == 0){
            func_80023A58(from, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

            if(!(GET_ACTOR_PTR(from)->flags & 0x100000)){
                func_80023C04(from);
            }
            if(GET_ACTOR_PTR(from)->unk38 == 0xFFFF && !(GET_ACTOR_PTR(from)->flags & 0x100000)){
                func_80023FCC(from);
                break;
            }
            if(arg1 > 0x59 && arg1 < 0x7F){
                temp2 = D_801AF810[(arg1 * 2)-0xB4];
                if(temp2 != -1){
                    GET_ACTOR_PTR(from)->unk4E = 2;
                    GET_ACTOR_PTR(from)->unk6C = temp2;

                    func_80022F48(from, D_801AF810[(arg1 * 2)-0xB3]);

                    if(GET_ACTOR_PTR(from)->unk38 != 0xFFFF){
                        func_80074D24(GET_ACTOR_PTR(from));
                    }
                }
                if(cdata.unk70 != 0){
                    GET_ACTOR_PTR(from)->flags |= 0x84000;
                }
            }

            return from;
        }
    }

    return -1;
}

s16 func_80023644(u16 arg0, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7){
    u16 temp;
    s16 temp2;
    s16 temp3;
    u16 to;
    u16 from;

    temp = D_800B50F0[arg0 * 2];
    from = temp;
    to = D_800B50F0[arg0 * 2 + 1];
    for (; from < to; from++){
        if(GET_ACTOR_PTR(from)->unk0 == 0 && GET_ACTOR_PTR(from)->unk67 == 0){
            func_80023A58(from, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

            if(!(GET_ACTOR_PTR(from)->flags & 0x100000)){
                func_80023C04(from);
            }
            if(GET_ACTOR_PTR(from)->unk38 == 0xFFFF && !(GET_ACTOR_PTR(from)->flags & 0x100000)){
                func_80023FCC(from);
                return -1;
            }
            if(!(GET_ACTOR_PTR(from)->flags & 0x40)){
                temp2 = func_80023644(6, 0x15E, arg2, arg3, arg4, 0.0f, 0.0f, 0.0f);

                if(temp2 != -1){
                    GET_ACTOR_PTR(temp2)->scale.x = (&D_801AF8C4[arg1])->unk18 * (&D_801AF8C4[arg1])->unk14;
                    GET_ACTOR_PTR(temp2)->scale.y = GET_ACTOR_PTR(temp2)->scale.x;
                    GET_ACTOR_PTR(temp2)->scale.z = GET_ACTOR_PTR(temp2)->scale.y;
                    GET_ACTOR_PTR(temp2)->unkA0.integer = from;
                    GET_ACTOR_PTR(from)->unk70 = temp2;

                    if(!(GET_ACTOR_PTR(temp2)->flags & 0x100)){
                        func_80028D80(temp2);
                    }
                }
            }
            if(arg1 > 0x59 && arg1 < 0x7F){
                temp3 = D_801AF810[(arg1 * 2)-0xB4];
                if(temp3 != -1){
                    GET_ACTOR_PTR(from)->unk4E = 2;
                    GET_ACTOR_PTR(from)->unk6C = temp3;

                    func_80022F48(from, D_801AF810[(arg1 * 2)-0xB3]);

                    if(GET_ACTOR_PTR(from)->unk38 != 0xFFFF){
                        func_80074D24(GET_ACTOR_PTR(from));
                    }
                }
                if(cdata.unk70 != 0){
                    GET_ACTOR_PTR(from)->flags |= 0x84000;
                }
            }

            return from;
        }
    }

    return -1;    
}

s16 func_800238B0(s16 idx, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7){   
    s16 id;
    s16 temp;
    
    if(GET_ACTOR_PTR(idx)->unk0 == 0){
        func_80023A58(idx, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

        if(!(GET_ACTOR_PTR(idx)->flags & 0x100000)){
            func_80023C04(idx);
        }
        if(GET_ACTOR_PTR(idx)->unk38 == 0xFFFF && !(GET_ACTOR_PTR(idx)->flags & 0x100000)){
            func_80023FCC(idx);
        }
        else {
            if(!(GET_ACTOR_PTR(idx)->flags & 0x40)){
                id = func_80023644(6, 0x15E, arg2, arg3, arg4, 0.0f, 0.0f, 0.0f);

                if(id != -1){
                    temp = (u32) id;
                    GET_ACTOR_PTR(temp)->scale.x = (&D_801AF8C4[arg1])->unk18;
                    GET_ACTOR_PTR(temp)->scale.y = GET_ACTOR_PTR(temp)->scale.x;
                    GET_ACTOR_PTR(temp)->scale.z = GET_ACTOR_PTR(temp)->scale.y;
                    GET_ACTOR_PTR(temp)->unkA0.integer = idx;
 
                    GET_ACTOR_PTR(idx)->unk70 = (u32)temp;

                    if(!(GET_ACTOR_PTR(temp)->flags & 0x100)){
                        func_80028D80(id);
                    }
                }
            }

            return idx;
        }
    }
    
    return -1;
}

#ifdef NON_MATCHING
s16 func_80023A58(s16 idx, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7){
    Actor* actor;
    D_801AF8C4_struct* ptr;
    u16 i;
    D_80142AB0[idx] = 0;
    actor = GET_ACTOR_PTR(idx);
    ptr = &D_801AF8C4[arg1];
        
    actor->scale.x = ptr->unk14;
    actor->scale.y = ptr->unk14;
    actor->scale.z = ptr->unk14;
    
    actor->unk0 = 1;
    actor->status = 0;
    actor->unk8 = 0;
    
    actor->unkC = ptr->unk0;
    
    actor->pos.x = arg2;
    actor->pos.y = arg3;
    actor->pos.z = arg4;
    actor->unk1C = arg2 + 1.0f;
    actor->unk20 = arg3 + 1.0f;
    actor->unk24 = arg4 + 1.0f;
    
    actor->rot.x = arg5;
    actor->rot.y = arg6;
    actor->rot.z = arg7;
    actor->unk34 = ptr->unkC;
    actor->unk38 = 0xFFFF;
    actor->unk3C = ptr->unk6;
    actor->unk40 = ptr->unk8;
    actor->unk44 = 0;
    
    actor->unk48 = ptr->unk10;
    actor->unk4A = ptr->unk4;
    
    actor->unk4C = ptr->unk10;
    actor->unk4E = 0;
    
    actor->unk50 = 0;
    actor->dir.x = 0.0f;
    actor->dir.y = 0.0f;
    actor->dir.z = 0.0f;   
    actor->unk64 = 0;
    actor->unk66 = 0xA;
    actor->unk67 = 2;
    actor->unk6D = 0x80;
    
    actor->unk70 = -1;
    actor->unk72 = ptr->unk10;
    actor->unk74 = ptr->unk1C;
    actor->unk80 = ptr->unk20;
    actor->unk84 = 0;
    
    actor->unk88 = 0xFF;
    actor->unk89 = 0xFF;
    actor->unk8A = 0xFF;
    actor->unk8B = 0xFF;
    actor->flags = ptr->flags;


    for(i = 0; i < 0x18; i++){
        actor[i].unkA0.integer = 0;
    }

    D_80141CA2++;

    return idx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/23B20/func_80023A58.s")
#endif

s16 func_80023C04(s16 idx){
    s32 pad[2];
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 i;
    s16 j;
    D_801414A0_ptr_struct* ptr;
    ActorUnk34Struct* ptr2;  
    
    if(actor->unk38 != 0xFFFF){
        return -2;
    }

    i = 0;
    j = func_8001F7FC(actor->unk3C + actor->unk40);
    
    if((j+1)){
        actor->unk38 = j;
        ptr2 = actor->unk34;

        if (actor->unk40 != 0) {
            for(i = 0; i < actor->unk40; i++){
                ptr = D_801414A0[j];
                ptr->unk48 = 0;
                ptr->unk4C = 0;
                ptr->unk4 = 0x1F;
                ptr->unk6 = ptr->unk8 = 0xFFFF;
                ptr->unk0 = 0xFFFF;
                ptr->unk2 = i+1;
    
                ptr->unk24 = 0.0f;
                ptr->unk28 = 0.0f;
                ptr->unk2C = 0.0f;
                ptr->unk30 = 0.0f;
                ptr->unk34 = 0.0f;
                ptr->unk38 = 0.0f;
                ptr->unk3C = 1.0f;
                ptr->unk40 = 1.0f;
                ptr->unk44 = 1.0f;
                ptr->unk50 = 0;
                ptr->unk54 = 0.0f;
                ptr->unk58 = 0.0f;
                ptr->unk5C = 0.0f;
                ptr->unkC = 0.0f;
                ptr->unk10 = 0.0f;
                ptr->unk14 = 0.0f;
                ptr->unk18 = 0.0f;
                ptr->unk1C = 0.0f;
                ptr->unk20 = 0.0f;
                ptr->unk320 = 0xFF;
                ptr->unk322 = 0xFF;
                ptr->unk321 = 0xFF;
                ptr->unk323 = 0xFF;
                ptr->unk334 =
                ptr->unk338 = 0.0f;
                ptr->unk330 = 0.0f;
                ptr->unk340 = 
                ptr->unk344 = 0.0f;
                ptr->unk33C = 0.0f;
                ptr->unk350 = 0.0f;
                ptr->unk34C = 0.0f;
                ptr->unk348 = 0.0f;
                guTranslate(&ptr->mtx, 0.0f, 0.0f, 0.0f);
                j++;
            }
        }
        for(i = 0; i < actor->unk3C;ptr2++, j++, i++){
            ptr = D_801414A0[j];
            
            ptr->unk48 = 0;
            ptr->unk4C = 0;
            ptr->unk4 = ptr2->unk10;
            ptr->unk6 = ptr->unk8 = ptr2->unk12;

            if(ptr2->unkC == 0xFFFF){
                ptr->unk0 = ptr2->unkC;
            }
            else{
                ptr->unk0 = ptr2->unkC + actor->unk40;
            }

            if(ptr2->unkE == 0xFFFF){
                ptr->unk2 = ptr2->unkE;
            }
            else{
                ptr->unk2 = ptr2->unkE + actor->unk40;
            }

            ptr->unk24 = 0.0f;
            ptr->unk28 = 0.0f;
            ptr->unk2C = 0.0f;
            ptr->unk30 = 0.0f;
            ptr->unk34 = 0.0f;
            ptr->unk38 = 0.0f;
            ptr->unk3C = 1.0f;
            ptr->unk40 = 1.0f;
            ptr->unk44 = 1.0f;

            
            ptr->unk50 = ptr2->unk14;
            ptr->unk54 = ptr2->unk18;
            ptr->unk58 = ptr2->unk1C;
            ptr->unk5C = ptr2->unk20;

            ptr->unkC = ptr->unk18 = ptr2->x;
            ptr->unk10 = ptr->unk1C = ptr2->y;
            ptr->unk14 = ptr->unk20 = ptr2->z;

            ptr->unk320 = 0xFF;
            ptr->unk322 = 0xFF;
            ptr->unk321 = 0xFF;
            ptr->unk323 = 0xFF;
            ptr->unk330 = 0.0f;
            ptr->unk334 = 0.0f;
            ptr->unk338 = 0.0f;
            ptr->unk33C = 0.0f;
            ptr->unk340 = 0.0f;
            ptr->unk344 = 0.0f;
            ptr->unk348 = 0.0f;
            ptr->unk34C = 0.0f;
            ptr->unk350 = 0.0f;

            guTranslate(&D_801414A0[j]->mtx, ptr2->x, ptr2->y, ptr2->z); 
        }

        ptr = D_801414A0[actor->unk38];

        ptr->unk24 = actor->pos.x;
        ptr->unk28 = actor->pos.y;
        ptr->unk2C = actor->pos.z;

        ptr->unk30 = actor->rot.x;
        ptr->unk34 = actor->rot.y;
        ptr->unk38 = actor->rot.z;

        actor->flags &= ~0x100;

        return idx;
    }

    actor->flags |= 0x100;

    return -1;
}

void func_80023FCC(s16 idx){
    Actor* actor;
    D_80141CB0_struct* ptr;

    if(idx != -1){
        actor = GET_ACTOR_PTR(idx);
        if(1);

        if(actor->unk38 != 0xFFFF && !(actor->flags & 0x100000)){
            func_8001F878(actor->unk38, (actor->unk3C + actor->unk40));
        }
        
        actor->unk0 = 0;
        actor->unk4E = 0; actor->flags = 0x80000; 

        ptr = &D_80141CB0[idx];
        
        ptr->unkC = -1;
        ptr->unk0 = ptr->unk2 = ptr->unk4 = ptr->unk6 = ptr->unk8 = ptr->unkA = ptr->unkC;
            
        if(actor->unk70 != -1){
            func_80023FCC(actor->unk70);
        }

        D_80141CA2--;
    }
}

void func_800240CC(s16 idx){
    u16 i;

    for(i = 0; i < 0x100; i++){
        if(GET_ACTOR_PTR(i)->unk0 != 0 && idx == GET_ACTOR_PTR(i)->unk64){
            func_80023FCC(i);
        }
    }
}

void func_80024158(s16 idx, u8 r, u8 g, u8 b, u8 a){
    Actor* actor = GET_ACTOR_PTR(idx);

    actor->r = r;
    actor->g = g;
    actor->b = b;
    actor->a = a;
}

void func_80024198(s16 idx, s16 r, s16 g, s16 b, s16 a){
    Actor* actor = GET_ACTOR_PTR(idx); 
    s32 red = (s16)(actor->r + r);
    s32 green = (s16)(actor->g + g);
    s32 blue = (s16)(actor->b + b);
    s32 alpha = (s16)(actor->a + a);

    if(red < 0){
        actor->r = 0;
    }
    else if(red > 255){
        actor->r = 255;
    }
    else{
        actor->r = red;
    }
    if(green < 0){
        actor->g = 0;
    }
    else if(green > 255){
        actor->g = 255;
    }
    else{
        actor->g = green;
    }

    if(blue < 0){
        actor->b = 0;
    }
    else if(blue > 255){
        actor->b = 255;
    }
    else{
        actor->b = blue;
    }

    if(alpha < 0){
        actor->a = 0;
    }
    else if(alpha > 255){
        actor->a = 255;
    }
    else{
        actor->a = alpha;
    }   
}

void func_800242C0(s16 idx, s16 arg1){
    GET_ACTOR_PTR(idx)->unk72 = arg1;
    GET_ACTOR_PTR(idx)->unk4C = GET_ACTOR_PTR(idx)->unk72;
}

void func_800242F0(s16 idx, u16 arg1, u16 arg2){
    Actor* actor = GET_ACTOR_PTR(idx); 
     
    if(actor->unk38 != 0xFFFF){
        (&D_801414A0[actor->unk38])[arg1]->unk6 = arg2;
    }   
}

void func_80024348(s16 idx, u16 arg1){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_801414A0_ptr_struct* ptr;
     
    if(actor->unk38 != 0xFFFF){
        ptr = (&D_801414A0[actor->unk38])[arg1];

        ptr->unk6 = ptr->unk8;
    }   
}

void func_8002439C(s16 idx, u16 arg1){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_801414A0_ptr_struct* ptr;
    s16 i;
    
    if(actor->unk38 != 0xFFFF){
        for(i = 0; i < actor->unk3C; i++){
            ptr = (&(&D_801414A0[i])[actor->unk38])[actor->unk40];

            if(ptr->unk8 != 0xFFFF){
                ptr->unk6 = ptr->unk8 + arg1;
            }
        }

    }   
}

void func_8002443C(s16 idx, u16 arg1, f32 x, f32 y, f32 z){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_801414A0_ptr_struct* ptr;
     
    if(actor->unk38 != 0xFFFF){
        ptr = (&D_801414A0[actor->unk38])[arg1];
        
        ptr->unkC = x;
        ptr->unk10 = y;
        ptr->unk14 = z;

        guTranslate(&ptr->mtx, x, y, z);
    }   
}

void func_800244C4(s16 idx, u16 arg1){
    Actor* actor = GET_ACTOR_PTR(idx);
    D_801414A0_ptr_struct* ptr;
    
    if(actor->unk38 != 0xFFFF){
        ptr = (&D_801414A0[actor->unk38])[arg1];
        
        ptr->unkC = ptr->unk18;
        ptr->unk10 = ptr->unk1C;
        ptr->unk14 = ptr->unk20;

        guTranslate(&ptr->mtx, ptr->unk18, ptr->unk1C, ptr->unk20);
    }   
}

void func_8002454C(s16 idx, u16 arg1, u16 arg2, u16 arg3, f32 x, f32 y, f32 z){
    D_801414A0_ptr_struct* temp_s0;
    Actor *actor = GET_ACTOR_PTR(idx);

    if (actor->unk38 == 0xFFFF) {
        return;
    }

    temp_s0 = (&D_801414A0[actor->unk38])[arg1];
    if (arg2 == arg3) {
        temp_s0->unkC = x;
        temp_s0->unk10 = y;
        temp_s0->unk14 = z;
        guTranslate(&temp_s0->mtx, x, y, z);
    }

    if (temp_s0->unk2 != 0xFFFF) {
        func_8002454C(idx, temp_s0->unk2, arg2 + 1, arg3, x, y, z);
    }

    if (temp_s0->unk0 != 0xFFFF) {
        func_8002454C(idx, temp_s0->unk0, arg2, arg3, x, y, z);
    }
}

void func_800246AC(s16 idx, u16 arg1, u16 arg2, u16 arg3) {
    D_801414A0_ptr_struct* temp_s0;

    if (GET_ACTOR_PTR(idx)->unk38 == 0xFFFF) {
        return;
    }

    temp_s0 = (&D_801414A0[GET_ACTOR_PTR(idx)->unk38])[arg1];
    if (arg2 == arg3) {
        temp_s0->unkC = temp_s0->unk18;
        temp_s0->unk10 = temp_s0->unk1C;
        temp_s0->unk14 = temp_s0->unk20;
        guTranslate(&temp_s0->mtx, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20);
    }
    if (temp_s0->unk2 != 0xFFFF) {
        func_800246AC(idx, temp_s0->unk2, (arg2 + 1), arg3);
    }
    if (temp_s0->unk0 != 0xFFFF) {
        func_800246AC(idx, temp_s0->unk0, arg2, arg3);
    }
}

void func_800247E8(s16 idx, u16 arg1, f32 arg2){
    Actor* actor = GET_ACTOR_PTR(idx);

    if(actor->unk38 != 0xFFFF){
        (&D_801414A0[actor->unk38])[arg1]->unk3C = arg2;
        (&D_801414A0[actor->unk38])[arg1]->unk40 = arg2;
        (&D_801414A0[actor->unk38])[arg1]->unk44 = arg2;
    }
}

void func_80024874(s16 idx, f32 val){
    GET_ACTOR_PTR(idx)->scale.x = val;
    GET_ACTOR_PTR(idx)->scale.y = val;
    GET_ACTOR_PTR(idx)->scale.z = val; 
}

void func_800248A4(s16 idx, f32 x, f32 y, f32 z){
    GET_ACTOR_PTR(idx)->scale.x = x;
    GET_ACTOR_PTR(idx)->scale.y = y;
    GET_ACTOR_PTR(idx)->scale.z = z;
}

s16 func_800248E0(s16 idx, s16 arg1){
    Actor* actor;
    u16 temp1;
    u16 temp2;
    u16 i;
    u16 j;

    temp1 = D_800B50F0[idx * 2];
    temp2 = D_800B50F0[idx * 2 + 1];
    i = 0;
    j = temp1;
    while (j < temp2) {
        actor = GET_ACTOR_PTR(j);
        if (arg1 == actor->unk48 && actor->unk0 != 0){
            i++;
        }
        j++;
    }

    return i;
}

s16 func_80024970(u16 idx, u16 arg1){    
    u16 id = idx;
    
    while(id < 0x100){
        if(GET_ACTOR_PTR(id)->unk0 != 0 && arg1 == GET_ACTOR_PTR(id)->unk48){
            return id;
        }
        
        id++;
    }

    return -1;
}

s16 func_800249E4(u16 idx, u16 arg1, s16 arg2, f32 dist){
    Actor* actor;
    Actor* actor2;
    f32 x;
    f32 y;
    f32 z;
    f32 d;
    u16 temp = 0xFFFF;
    f32 t = -1.0f;
    u16 id = idx;
    
    while(id < 0x100){
        if(arg2 != id){
            actor = GET_ACTOR_PTR(id);

            if(actor->unk0 != 0){
                actor2 = GET_ACTOR_PTR(arg2);

                if(actor->unk48 == arg1){
                    x = actor->pos.x - actor2->pos.x;
                    y = actor->pos.y - actor2->pos.y;
                    z = actor->pos.z - actor2->pos.z;

                    d = sqrtf(SQ(x) + SQ(y) + SQ(z));

                    if(d < dist){
                        if(t == -1.0f){
                            t = d;
                            temp = id;
                        }
                        else if(d < t){
                            t = d;
                            temp = id;
                        }
                    }
                }
            }
        }
        id++;
    }

    return temp;
}

s16 func_80024B50(u16 idx, s16 arg1, f32 dist) {
    f32 x;
    f32 y;
    f32 z;
    f32 t;
    u16 temp = 0xFFFF;
    u16 id = idx;
    f32 d;
    
    t = -1.0f;
    
    while (id < 0x100) {
        if (arg1 != id) {
            if (GET_ACTOR_PTR(id)->unk0 != 0) {
                
                x = GET_ACTOR_PTR(id)->pos.x - GET_ACTOR_PTR(arg1)->pos.x;
                y = GET_ACTOR_PTR(id)->pos.y - GET_ACTOR_PTR(arg1)->pos.y;
                z = GET_ACTOR_PTR(id)->pos.z - GET_ACTOR_PTR(arg1)->pos.z;
                
                d = sqrtf(SQ(x) + SQ(y) + SQ(z));
                
                if(d < dist){
                    if(t == -1.0f){
                        t = d;
                        temp = id;
                    }
                    else if(d < t){
                        t = d;
                        temp = id;
                    }
                }
            }
        }
        id++;
    }
    return temp;
}

s16 func_80024CA0(u16 idx, s16 arg1, f32 dist) {
    f32 x;
    f32 y;
    f32 z;
    u16 temp = 0xFFFF;
    u16 temp3 = D_800B50F0[idx * 2];
    u16 temp2 = D_800B50F0[idx * 2 + 1];
    f32 t = -1.0f;
    u16 id = temp3;
    f32 d;
    
    while (id < temp2) {
        if (arg1 != id) {
            if (GET_ACTOR_PTR(id)->unk0 != 0) {
                
                x = GET_ACTOR_PTR(id)->pos.x - GET_ACTOR_PTR(arg1)->pos.x;
                y = GET_ACTOR_PTR(id)->pos.y - GET_ACTOR_PTR(arg1)->pos.y;
                z = GET_ACTOR_PTR(id)->pos.z - GET_ACTOR_PTR(arg1)->pos.z;
                
                d = sqrtf(SQ(x) + SQ(y) + SQ(z));
                
                if(d < dist){
                    if(t == -1.0f){
                        t = d;
                        temp = id;
                    }
                    else if(d < t){
                        t = d;
                        temp = id;
                    }
                }
            }
        }
        id++;
    }
    return temp;
}

f32 func_80024E0C(s16 id1, s16 id2){
    Actor* actor1;
    Actor* actor2;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;

    actor2 = GET_ACTOR_PTR(id2);
    actor1 = GET_ACTOR_PTR(id1);
    
    if(actor2->unk0 == 0){
        return 0.0f;
    }

    xDiff = actor2->pos.x - actor1->pos.x;
    yDiff = actor2->pos.y - actor1->pos.y;
    zDiff = actor2->pos.z - actor1->pos.z;
    
    return sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
}

f32 func_80024EA4(s16 idx, f32 x, f32 y, f32 z){
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;

    xDiff = x - GET_ACTOR_PTR(idx)->pos.x;
    yDiff = y - GET_ACTOR_PTR(idx)->pos.y;
    zDiff = z - GET_ACTOR_PTR(idx)->pos.z;
    
    
    return sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
}

void func_80024F20(s16 idx, f32 arg1){
    GET_ACTOR_PTR(idx)->dir.z = cosf(DEG2RAD_ALT2(GET_ACTOR_PTR(idx)->rot.y)) * arg1;
    GET_ACTOR_PTR(idx)->dir.x = sinf(DEG2RAD_ALT2(GET_ACTOR_PTR(idx)->rot.y)) * arg1;
}

void func_80024FC8(s16 idx, f32 arg1, f32 arg2){
    GET_ACTOR_PTR(idx)->dir.z = cosf(DEG2RAD_ALT2(GET_ACTOR_PTR(idx)->rot.y)) * arg1;
    GET_ACTOR_PTR(idx)->dir.x = sinf(DEG2RAD_ALT2(GET_ACTOR_PTR(idx)->rot.y)) * arg1;
    GET_ACTOR_PTR(idx)->dir.y = arg2;
}

void func_8002507C(s16 idx){
    GET_ACTOR_PTR(idx)->pos.x += GET_ACTOR_PTR(idx)->dir.x;
    GET_ACTOR_PTR(idx)->pos.y += GET_ACTOR_PTR(idx)->dir.y;
    GET_ACTOR_PTR(idx)->pos.z += GET_ACTOR_PTR(idx)->dir.z;
}

void func_800250CC(s16 idx){
    GET_ACTOR_PTR(idx)->pos.x += GET_ACTOR_PTR(idx)->dir.x;
    GET_ACTOR_PTR(idx)->pos.z += GET_ACTOR_PTR(idx)->dir.z;
}

void func_8002510C(s16 idx){
    GET_ACTOR_PTR(idx)->pos.y += GET_ACTOR_PTR(idx)->dir.y;
}

void func_8002513C(Actor* actor){
    f32 x;
    f32 z; 
    s32 temp;
    
    x = actor->pos.x - actor->unkA0.fp;
    temp = 0;
    z = actor->pos.z - actor->unkA8.fp;

    if(actor->unkAC.fp < sqrtf(SQ(x) + SQ(z))){
        temp = 1;
        actor->unkB8.fp = func_80074E68(actor->rot.y, func_80025C48(actor->unkA8.fp - actor->pos.z, actor->unkA0.fp - actor->pos.x));
    }
    if(actor->unkB0.fp + actor->unkA4.fp < actor->pos.y){
        temp |= 2;
    }
    else if(actor->pos.y < actor->unkA4.fp){
        temp |= 4;
    }

    actor->unkB4.integer = temp;
    
}

void func_8002524C(s16 idx, f32 x, f32 y, f32 z){
    Actor* actor = GET_ACTOR_PTR(idx); 

    actor->dir.x = x;
    actor->dir.y = y;
    actor->dir.z = z;
}

s32 func_80025288(s16 id1, s16 id2){
    Actor* actor1 = GET_ACTOR_PTR(id1);
    Actor* actor2 = GET_ACTOR_PTR(id2);
    f32 r = func_80025C48(actor2->pos.z - actor1->pos.z, actor2->pos.x - actor1->pos.x) - actor1->rot.y;

    if(r < 0.0f){
        r += 360.0f;
    }
    if(r < 180.0f){
        return -1;
    }
    else{
        return 1;
    }
}

f32 func_80025374(s16 idx, f32 arg1, f32 arg2){
    f32 temp;

    temp = arg1 * arg2;
    GET_ACTOR_PTR(idx)->rot.y += temp;

    return arg1 - temp;
}

s16 func_800253B0(s16 id1, s16 id2){
    Actor* actor1;
    Actor* actor2;   
    f32 r;

    actor1 = GET_ACTOR_PTR(id1);
    actor2 = GET_ACTOR_PTR(id2);

    r = func_80025C48(actor2->pos.z - actor1->pos.z, actor2->pos.x - actor1->pos.x);

    return r;
}

void func_80025454(Actor* actor1, Actor* actor2, f32 arg1){
    f32 r;
    f32 angle;
 
    r = func_80025C48(actor2->pos.z - actor1->pos.z, actor2->pos.x - actor1->pos.x);
    
    if(arg1 <= 1.0f){
        angle = func_80074E68(actor1->rot.y, r); 
    }
    else { 
        angle = func_80074E68(actor1->rot.y, r) / arg1;
    }
 
    actor1->rot.y += angle; 
    
    NORM_ANGLE(actor1->rot.y);
}

void func_800255AC(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3){
    actor1->pos.x = sinf(arg2 * DEG2RAD_ALT3(1)) * arg3 + actor2->pos.x;
    actor1->pos.y = actor2->pos.y;
    actor1->pos.z = cosf(arg2 * DEG2RAD_ALT3(1)) * arg3 + actor2->pos.z;
} 


void func_80025638(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3, f32 arg4){
    actor1->pos.x = sinf(arg2 * DEG2RAD_ALT3(1)) * arg3 + actor2->pos.x;
    actor1->pos.y = actor2->pos.y + arg4; 
    actor1->pos.z = cosf(arg2 * DEG2RAD_ALT3(1)) * arg3 + actor2->pos.z;
}
 
void func_800256CC(Actor* actor, f32 x, f32 z, f32 arg3){
    f32 temp;
    f32 angle;
 
    temp = func_80025C48(z - actor->pos.z, x - actor->pos.x);
    
    if(arg3 <= 1.0f){
        angle = func_80074E68(actor->rot.y, temp);
    }
    else {
        angle = func_80074E68(actor->rot.y, temp) / arg3;
    }

    actor->rot.y += angle;
    
    NORM_ANGLE(actor->rot.y);
}

void func_80025820(Actor* actor, f32 arg1, f32 arg2){
    f32 angle;
    
    if(arg2 <= 1.0f){
        angle = func_80074E68(actor->rot.y, arg1);
    }
    else {
        angle = func_80074E68(actor->rot.y, arg1) / arg2;
    }

    actor->rot.y += angle;
    
    NORM_ANGLE(actor->rot.y);
}

void func_8002592C(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3){
    if(actor1->pos.y < actor2->pos.y){
        actor1->dir.y += arg3;
    }
    else if(actor2->pos.y < actor1->pos.y){
        actor1->dir.y -= arg3;
    }
    if(arg2 < actor1->dir.y){
        actor1->dir.y = arg2;
    }
    else if(actor1->dir.y < -arg2){
        actor1->dir.y = -arg2;
    }
}

void func_800259B4(Actor* actor, f32 arg1, f32 arg2, f32 arg3){
    if(actor->pos.y < arg1){
        actor->dir.y += arg3;
    }
    else if(arg1 < actor->pos.y){
        actor->dir.y -= arg3;
    }
    if(arg2 < actor->dir.y){
        actor->dir.y = arg2;
    }
    else if(actor->dir.y < -arg2){
        actor->dir.y = -arg2;
    }
}

void func_80025A44(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3){
    if(actor2->pos.x < actor1->pos.x){
        actor1->dir.x -= arg2;
    }
    else{
        actor1->dir.x += arg2;
    }
    if(actor2->pos.y+arg3 < actor1->pos.y){
        actor1->dir.y -= arg2;
    }
    else{
        actor1->dir.y += arg2;
    }
    if(actor2->pos.z < actor1->pos.z){
        actor1->dir.z -= arg2;
    }
    else{
        actor1->dir.z += arg2;
    }
}

void func_80025AF4(Actor* actor){
    s16 i;

    if(actor->unk38 != 0xFFFF){
        for(i = 0; i < actor->unk3C; i++){
            (&D_801414A0[actor->unk38])[i]->unk30 = 0.0f;
            (&D_801414A0[actor->unk38])[i]->unk34 = 0.0f;
            (&D_801414A0[actor->unk38])[i]->unk38 = 0.0f;
        }
    }
}

void func_80025B90(Actor* actor, f32 arg1, f32 arg2, f32 arg3){
    if(arg1 < actor->dir.x){
        actor->dir.x = arg1;
    }
    else if(actor->dir.x < -arg1){
        actor->dir.x = -arg1;
    }
    if(arg2 < actor->dir.y){
        actor->dir.y = arg2;
    }
    else if(actor->dir.y < -arg2){
        actor->dir.y = -arg2;
    }
    if(arg3 < actor->dir.z){
        actor->dir.z = arg3;
    }
    else if(actor->dir.z < -arg3){
        actor->dir.z = -arg3;
    }
}

u16 func_80025C48(s32 arg0, s32 arg1){
    s32 temp1;
    s32 temp2;
    u16 ret;

    temp1 = (u16)(ABSOLUTE(arg0));
    temp2 = (u16)(ABSOLUTE(arg1));

    if(temp1 == 0){
        if(arg1 > 0){
            return 0x5A;
        }
        else{
            return 0x10E;
        }
    }
    if(temp2 == 0){
        if(arg0 > 0){
            return 0;
        }
        else{
            return 0xB4;
        }
    }

    if(temp1 == temp2){
        if(arg0 > 0){
            if(arg1 > 0){
                return 0x2D;
            }
            else{
                return 0x13B;
            }
        }
        if(arg1 > 0){
            return 0x87;
        }
        else{
            return 0xE1;
        }
    }

    if(temp2 < temp1){
        ret = D_800B5130[(temp2*64) / temp1];
    }
    else{
        ret = 0x5A - D_800B5130[(temp1*64) / temp2];
    }

    if(arg1 < 0){
        if(arg0 < 0){
            return ret + 0xB4; 
        }
        else{
            return (0x168 - ret) % 360;
        }
    }
    if(arg0 < 0){
        return 0xB4 - ret;
    }
    else{
        return ret;
    }
    
}

void func_80025E14(f32* x, f32* y, f32* z){
    f32 dist;

    dist = sqrtf(SQ(*x) + SQ(*y) + SQ(*z));

    if(dist == 0.0f){
        dist = 1.0f;    
    }

    dist = 1.0f / dist;
    
    *x *= dist;
    *y *= dist;
    *z *= dist;
}

void func_80025EB8(){
    D_800F05B8 = TRUE;
    
    D_801545E4 = D_800F0548.unk0;
    D_801545E8 = D_800F0548.unk4;    
    D_801545EC = D_800F0548.unk8;    
    D_801545F0 = D_800F0548.unkC;    
    D_801545F4 = D_800F0548.unk10;    
    D_801545F8 = D_800F0548.unk14;    
}

void func_80025F18(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    f32 fact;
    
    if(arg6 == 0.0f){
        arg6 = 1.0f;
    }

    fact = 1.0f / arg6;
    
    D_801545FC = (arg0 - D_800F0548.unk0) * fact;
    D_80154600 = (arg1 - D_800F0548.unk4) * fact;
    D_80154604 = (arg2 - D_800F0548.unk8) * fact;
    D_80154608 = (arg3 - D_800F0548.unkC) * fact;
    D_8015460C = (arg4 - D_800F0548.unk10) * fact;
    D_80154610 = (arg5 - D_800F0548.unk14) * fact;     
}

void func_80025FE8(s16 id1, s16 id2, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8){
    Actor* actor1;
    Actor* actor2;
    f32 fact;
    f32 sin1;

    f32 temp4;

    f32 cos1;
    f32 sin2;
    f32 temp1;
    f32 cos2;
    
    f32 x;
    f32 z;
    f32 dist;
    f32 temp2;
    s32 pad;    
    
    if(arg8 == 0.0f){
        arg8 = 1.0f;
    }
    actor1 = GET_ACTOR_PTR(id1);
    actor2 = GET_ACTOR_PTR(id2);

    fact = 1.0f / arg8;

    x = actor2->pos.x - actor1->pos.x;
    z = actor2->pos.z - actor1->pos.z;

    dist = sqrtf(SQ(x) + SQ(z)) * 0.5;

    temp1 = temp2 = func_800253B0(id1, id2);

    temp1 = temp1 + 180.0f + arg4;
    NORM_ANGLE(temp1);
    
    temp2 += arg7;
    NORM_ANGLE(temp2);

    x = (actor1->pos.x + actor2->pos.x) * 0.5;
    z = (actor1->pos.z + actor2->pos.z) * 0.5;

    sin1 = sinf(temp1 * DEG2RAD_ALT3(1)) * (dist + arg3) + x;
    cos1 = cosf(temp1 * DEG2RAD_ALT3(1)) * (dist + arg3) + z;

    temp4 = actor1->pos.y + arg2;

    sin2 = sinf(temp2 * DEG2RAD_ALT3(1)) * (dist + arg6) + x;
    cos2 = cosf(temp2 * DEG2RAD_ALT3(1)) * (dist + arg6) + z;
    
    temp2 = actor2->pos.y + arg5;
    
    D_801545FC = (sin1 - D_800F0548.unk0) * fact;
    D_80154600 = (temp4 - D_800F0548.unk4) * fact;
    D_80154604 = (cos1 - D_800F0548.unk8) * fact;
    D_80154608 = (sin2 - D_800F0548.unkC) * fact;
    D_8015460C = (temp2 - D_800F0548.unk10) * fact;
    D_80154610 = (cos2 - D_800F0548.unk14) * fact;
}

void func_80026380(){
    D_800F05B8 = TRUE;

    D_800F0548.unk0 += D_801545FC;
    D_800F0548.unk4 += D_80154600;
    D_800F0548.unk8 += D_80154604;
    D_800F0548.unkC += D_80154608;
    D_800F0548.unk10 += D_8015460C;
    D_800F0548.unk14 += D_80154610;
}

void func_80026410(){
    D_800F05B8 = FALSE;

    D_800F0548.unk0 = D_801545E4;
    D_800F0548.unk4 = D_801545E8;
    D_800F0548.unk8 = D_801545EC;
    D_800F0548.unkC = D_801545F0;
    D_800F0548.unk10 = D_801545F4;
    D_800F0548.unk14 = D_801545F8;
}

void func_8002646C(s16 id1, s16 id2, f32 arg2){
    f32 temp = func_80074E68(D_80154614, D_80154618);
    f32 dist = func_80024E0C(id1, id2);
     
    if(arg2 < temp){
        temp = temp - arg2;
    }
    else if(temp < -arg2){
        temp = temp + arg2;
    }
    else{
        temp = 0.0f;
    }

    D_80154614 += temp * (0.1 - (ABSOLUTEF(temp) * 0.0005555));

    NORM_ANGLE(D_80154614);
    
    D_800F0548.unkC = GET_ACTOR_PTR(id1)->pos.x + sinf(DEG2RAD_ALT2(D_80154614)) * dist;
    D_800F0548.unk14 = GET_ACTOR_PTR(id1)->pos.z + cosf(DEG2RAD_ALT2(D_80154614)) * dist;
    D_800F0548.unk10 = GET_ACTOR_PTR(id2)->pos.y + D_80154620;
    
    D_800F0548.unk0 = GET_ACTOR_PTR(id1)->pos.x + sinf(DEG2RAD_ALT2(D_80154614)) * -D_80154624;
    D_800F0548.unk8 = GET_ACTOR_PTR(id1)->pos.z + cosf(DEG2RAD_ALT2(D_80154614)) * -D_80154624;
    D_800F0548.unk4 = GET_ACTOR_PTR(id1)->pos.y + D_8015461C;

}

void func_8002675C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6){
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    
    if(D_801545E0 < 0x80 && D_801545E2 < 0x7F){
        D_80152360[D_801545E0++].unk0 = 1;
        
        temp3 = arg6 >> 0x18;
        temp1 = (arg6 & 0xFF0000) >> 0x10;
        temp2 = (arg6 & 0xFF00) >> 8;
        temp4 = arg6 & 0xFF;
        
        D_801525E0[D_801545E2].unk0 = arg0;
        D_801525E0[D_801545E2].unk2 = arg1;
        D_801525E0[D_801545E2].unk4 = arg2;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;

        D_801525E0[D_801545E2].unk0 = arg3;
        D_801525E0[D_801545E2].unk2 = arg4;
        D_801525E0[D_801545E2].unk4 = arg5;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;

        
    }
}

void func_80026878(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s32 arg9){
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
        
    if(D_801545E0 < 0x80 && D_801545E2 < 0x7E){
        D_80152360[D_801545E0++].unk0 = 2;
                
        temp3 = arg9 >> 0x18;
        temp1 = (arg9 & 0xFF0000) >> 0x10;
        temp2 = (arg9 & 0xFF00) >> 8;
        temp4 = arg9 & 0xFF;
        
        D_801525E0[D_801545E2].unk0 = arg0;
        D_801525E0[D_801545E2].unk2 = arg1;
        D_801525E0[D_801545E2].unk4 = arg2;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
        
        D_801525E0[D_801545E2].unk0 = arg3;
        D_801525E0[D_801545E2].unk2 = arg4;
        D_801525E0[D_801545E2].unk4 = arg5;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
        
        D_801525E0[D_801545E2].unk0 = arg6;
        D_801525E0[D_801545E2].unk2 = arg7;
        D_801525E0[D_801545E2].unk4 = arg8;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
    }
}

void func_800269EC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s32 arg9, s32 arg10, s32 arg11) {
    if ((D_801545E0 < 0x80) && (D_801545E2 < 0x7E)) {
        D_80152360[D_801545E0++].unk0 = 2;

        D_801525E0[D_801545E2].unk0 = arg0;
        D_801525E0[D_801545E2].unk2 = arg1;
        D_801525E0[D_801545E2].unk4 = arg2;
        D_801525E0[D_801545E2].unkC = arg9 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg9 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg9 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg9 & 0xFF;

        D_801525E0[D_801545E2].unk0 = arg3;
        D_801525E0[D_801545E2].unk2 = arg4;
        D_801525E0[D_801545E2].unk4 = arg5;
        D_801525E0[D_801545E2].unkC = arg10 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg10 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg10 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg10 & 0xFF;

        D_801525E0[D_801545E2].unk0 = arg6;
        D_801525E0[D_801545E2].unk2 = arg7;
        D_801525E0[D_801545E2].unk4 = arg8;
        D_801525E0[D_801545E2].unkC = arg11 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg11 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg11 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg11 & 0xFF;
    }
}

void func_80026B88(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12){
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;

    if(D_801545E0 < 0x80 && D_801545E2 < 0x7D){
        D_80152360[D_801545E0++].unk0 = 3;
        
        temp3 = arg12 >> 0x18;
        temp1 = (arg12 & 0xFF0000) >> 0x10;
        temp2 = (arg12 & 0xFF00) >> 8;
        temp4 = arg12 & 0xFF;

        D_801525E0[D_801545E2].unk0 = arg0;
        D_801525E0[D_801545E2].unk2 = arg1;
        D_801525E0[D_801545E2].unk4 = arg2;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
        
        D_801525E0[D_801545E2].unk0 = arg3;
        D_801525E0[D_801545E2].unk2 = arg4;
        D_801525E0[D_801545E2].unk4 = arg5;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
        
        D_801525E0[D_801545E2].unk0 = arg6;
        D_801525E0[D_801545E2].unk2 = arg7;
        D_801525E0[D_801545E2].unk4 = arg8;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
        
        D_801525E0[D_801545E2].unk0 = arg9;
        D_801525E0[D_801545E2].unk2 = arg10;
        D_801525E0[D_801545E2].unk4 = arg11;
        D_801525E0[D_801545E2].unkC = temp3;
        D_801525E0[D_801545E2].unkD = temp1;
        D_801525E0[D_801545E2].unkE = temp2;
        D_801525E0[D_801545E2++].unkF = temp4;
    }
      
}

void func_80026D50(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15){
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    
    if (D_801545E0 < 0x80 && D_801545E2 < 0x7E) {
        D_80152360[D_801545E0++].unk0 = 3;
        
        D_801525E0[D_801545E2].unk0 = arg0;
        D_801525E0[D_801545E2].unk2 = arg1;
        D_801525E0[D_801545E2].unk4 = arg2;
        D_801525E0[D_801545E2].unkC = arg12 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg12 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg12 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg12 & 0xFF;
        
        D_801525E0[D_801545E2].unk0 = arg3;
        D_801525E0[D_801545E2].unk2 = arg4;
        D_801525E0[D_801545E2].unk4 = arg5;
        D_801525E0[D_801545E2].unkC = arg13 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg13 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg13 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg13 & 0xFF;
                
        D_801525E0[D_801545E2].unk0 = arg6;
        D_801525E0[D_801545E2].unk2 = arg7;
        D_801525E0[D_801545E2].unk4 = arg8;
        D_801525E0[D_801545E2].unkC = arg14 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg14 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg14 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg14 & 0xFF;
         
        D_801525E0[D_801545E2].unk0 = arg9;
        D_801525E0[D_801545E2].unk2 = arg10;
        D_801525E0[D_801545E2].unk4 = arg11;
        D_801525E0[D_801545E2].unkC = arg15 >> 0x18;
        D_801525E0[D_801545E2].unkD = (arg15 & 0xFF0000) >> 0x10;
        D_801525E0[D_801545E2].unkE = (arg15 & 0xFF00) >> 8;
        D_801525E0[D_801545E2++].unkF = arg15 & 0xFF;
    }
}

s32 func_80026F58(s16 arg0, s16 arg1, s16 arg2, s16 arg3){
    CLAMP_U8(arg0);
    CLAMP_U8(arg1);
    CLAMP_U8(arg2);
    CLAMP_U8(arg3);

    return (arg0 << 0x18) + (arg1 << 0x10) + (arg2 << 8) + arg3;
}

void func_80027014(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9){
    s16 i;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 temp_fs3;
    f32 temp_fs5;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 var_fs1;
    f32 temp_t7;
    f32 temp_t9;
    s32 temp_s0;
    f32 f4;

    temp_s0 = arg6 * 2;
    temp_fs3 = (f32) arg6;

    for(i = 0; i < 5; i++) {
        temp_t7 = (func_80011528(0) & 3) + 1;
        temp_t9 = (func_80011528(0) & 3) + 1;

        temp_ft4 = arg3 - arg0;
        temp_ft5 = arg4 - arg1;
        temp_fs0 = arg5 - arg2;

        temp_fs5 = arg0 + ((temp_ft4 * temp_t7) * 0.1);
        sp90 = arg1 + ((temp_ft5 * temp_t7) * 0.1);
        sp88 = arg2 + ((temp_fs0 * temp_t7) * 0.1);

        temp_fa1 = temp_t9 + temp_t7;
        sp94 = arg0 + ((temp_ft4 * temp_fa1) * 0.1);
        sp8C = arg1 + ((temp_ft5 * temp_fa1) * 0.1);
        sp84 = arg2 + ((temp_fs0 * temp_fa1) * 0.1);

        arg0 += (func_80011528(0) % temp_s0) - temp_fs3;
        arg1 += (func_80011528(0) % temp_s0) - temp_fs3;
        arg2 += (func_80011528(0) % temp_s0) - temp_fs3;
        temp_fs5 += (func_80011528(0) % temp_s0) - temp_fs3;
        sp90 += (func_80011528(0) % temp_s0) - temp_fs3;
        sp88 += (func_80011528(0) % temp_s0) - temp_fs3;
        sp94 += (func_80011528(0) % temp_s0) - temp_fs3;
        sp8C += (func_80011528(0) % temp_s0) - temp_fs3;
        sp84 += (func_80011528(0) % temp_s0) - temp_fs3;
        arg3 += (func_80011528(0) % temp_s0) - temp_fs3;
        arg4 += (func_80011528(0) % temp_s0) - temp_fs3;
        arg5 += (func_80011528(0) % temp_s0) - temp_fs3;

        #define Callfunc_800269EC(a, b, c, d, e, f) func_800269EC((a),(b),(c),(((a) + (d)) * 0.5) + temp_fs0,(((b) + (e)) * 0.5) + temp_fs1,(((c) + (f)) * 0.5) + f4,(d),(e),(f),arg7,arg8,arg9)

        temp_fs0 = (func_80011528(0) & 7) - 4.0f;
        temp_fs1 = (func_80011528(0) & 7) - 4.0f;
        f4 = (func_80011528(0) & 7) - 4.0f;
        Callfunc_800269EC(arg0, arg1, arg2, temp_fs5, sp90, sp88);

        temp_fs0 = (func_80011528(0) & 7) - 4.0f;
        temp_fs1 = (func_80011528(0) & 7) - 4.0f;
        f4 = (func_80011528(0) & 7) - 4.0f;
        Callfunc_800269EC(temp_fs5, sp90, sp88, sp94, sp8C, sp84);

        temp_fs0 = (func_80011528(0) & 7) - 4.0f;
        temp_fs1 = (func_80011528(0) & 7) - 4.0f;
        f4 = (func_80011528(0) & 7) - 4.0f;
        Callfunc_800269EC(sp94, sp8C, sp84, arg3, arg4, arg5);
    }
}
