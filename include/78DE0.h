#ifndef _78DE0_H
#define _78DE0_H

#include "ultra64.h"

struct Actor;

typedef struct func_80079538_arg0{
    u32 unk0;
    u8 unk4[0x24];
}func_80079538_arg0; 

typedef struct func_80079538_arg1{
    u32 unk0;
    u8 unk4[0xC];
}func_80079538_arg1;

void func_800781E0(struct Actor* actor);
void func_8007835C(struct Actor* actor);
void func_800784C8(struct Actor* actor);
void func_80078554(struct Actor* actor);
void func_800785CC(struct Actor* actor);
void func_80078BA0(s16 idx);
void func_80078DB0(s16 idx);
s32 func_80078F78(struct Actor* actor);
void func_800790FC(s16 idx);
void func_80079180(s16 idx);
void func_8007928C(struct Actor* actor);
void func_800793F4(u16 arg0, u8* arg1);
void func_80079538(func_80079538_arg0** arg0, func_80079538_arg1* arg1, u16 arg2);
void func_8007957C(u32 arg0, u8* arg1);


#endif
