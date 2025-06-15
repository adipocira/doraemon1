#ifndef GLOBAL_H
#define GLOBAL_H

#include "ultra64.h"

typedef struct Vec3f {
    f32 x,y,z;
} Vec3f;

typedef struct Player{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unk10;
    Vec3f pos;
    u8 unk1C[0x84];
    s32 unkA0;
    s32 unkA4;
    f32 unkA8;
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
    f32 unkB8;
    f32 unkBC;
    u8 unkC0[0x40];
}Player;

#define GET_PLAYER_PTR(idx) ((&players[(idx)]))

extern Player players[5];

extern struct _80006250_arg1 D_800F0548;

extern f32 D_800C0D70;
extern f32 D_800C0D74;
extern f32 D_800C0D78;

extern s8 D_800F05B8;

extern f32 D_800F05C8;
extern f32 D_800F05CC;
extern f32 D_800F05D0;
extern f32 D_800F05D4;
extern f32 D_800F05D8;
extern f32 D_800F05DC;


typedef struct  D_800E69C0_struct {
    u8 unk0[0x4];
    u8 unk4[0x4];
    volatile u16 unk8;
    volatile u16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    volatile s32 unk10;
    u8 unk14[4];
    u8 unk18[0x5];
    u8 unk1D[0x8];
} D_800E69C0_struct;

extern D_800E69C0_struct D_800E69C0;

s32 func_80012D40(s32 arg0, s32 arg1, u8 arg2);
void func_80023FCC(s16);

#endif