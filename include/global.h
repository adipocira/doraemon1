#ifndef GLOBAL_H
#define GLOBAL_H

#include "ultra64.h"

typedef struct Vec3f {
    f32 x,y,z;
} Vec3f;

typedef struct cdata_struct {
    u8 unk0[0x1D];
    u8 nextstg;
    u8 unk1E[0x12];
    s32 unk30;
    u8 unk34;
    s8 unk35;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    f32 unk3C;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u16 unk44;
    u8 unk46[0x24];
    u8 unk6A;
    u8 unk6B[0x3];
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    u8 unk73;
    u8 unk74[0x8];
    s32 unk7C;
} Cdata;

typedef struct Player{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unk10;
    Vec3f pos;
    u8 unk1C[0x70];
    u32 unk8C;
    u8 unk90[0x10];
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


typedef struct D_800E69C0_struct {
    volatile u32 unk0;
    u8 unk4[0x4];
    volatile u16 unk8;
    volatile u16 unkA;
    volatile u8 unkC;
    volatile u8 unkD;
    volatile u8 unkE;
    volatile u8 unkF;
    volatile s32 unk10;
    volatile u32 unk14;
    u8 unk18[0x5];
    u8 unk1D[0x8];
    u8 unk25[0x17];
    volatile u8 unk3C;
    volatile u8 unk3D;
    volatile u8 unk3E;
    volatile u8 unk3F;
    volatile u8 unk40;
    volatile u8 unk41;
} D_800E69C0_struct;

typedef struct D_801BAA80_struct{
    u16 unk0[4];
}D_801BAA80_struct;

typedef struct D_800F5FB0_struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    f32 unk14;
    f32 unk18;
    u16 unk1C[17];
    D_801BAA80_struct* unk40;
    u8 unk44;
    void* unk48;
}D_800F5FB0_struct;

typedef struct D_800F3940_struct {
    u8 unk0[0x10];
    u32 unk10;
    u32 unk14;
    u8 unk18[0x18];
    u32 unk30;
    u32 unk34;
    u32 unk38;
    s32 unk3C;
    u8 unk40[0x64];
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
    u8 unkA7;
    u8 unkA8;
    u8 unkA9;
    u8 unkAA[0x8];
    u8 unkB2;
}D_800F3940_struct;

typedef struct D_800E6A20_struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} D_800E6A20_struct;

extern D_800E6A20_struct D_800E6A20[256];

extern D_800F3940_struct* D_800F3940;

extern D_800F5FB0_struct D_800F5FB0;
extern D_801BAA80_struct D_801BAA80;

extern D_800E69C0_struct D_800E69C0;

extern Cdata cdata;

extern u8 D_800F6010[];
extern u8 D_800F6170[];

void func_80023FCC(s16);

#define D_800F5FB0_sets(arg0, arg1, arg2) D_800F5FB0.unkC = (arg0);D_800F5FB0.unk2 = (arg1);D_800F5FB0.unk0 = (arg2)


#endif
