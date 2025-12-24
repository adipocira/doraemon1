#ifndef GLOBAL_H
#define GLOBAL_H

#include "ultra64.h"

typedef struct Vec3f {
    f32 x,y,z;
} Vec3f;

typedef union s32_f32_ptr{
    s32 integer;
    f32 fp;
    void* ptr;
}s32_f32_ptr;

typedef union s82x_s16{
    u8 uchar[2];
    s16 ishort;
}char2x_short;

typedef struct cdata_struct {
    u16* unk0;
    u8 unk4[0x19];
    u8 nextstg;
    u8 unk1E[0x4];
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u64 unk28;
    s32 unk30;
    u8 unk34;
    s8 unk35;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    f32 unk3C;
    s8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u16 unk44;
    u8 unk46[0x4];
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 unk4D;
    u16 unk4E;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u16 unk56;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    u8 unk5C;
    u8 unk5D;
    u16 unk5E;
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u16 unk66;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    u8 unk6B[0x3];
    u16 unk6E;
    u16 unk70;
    u8 unk72;
    u8 unk73;
    s16 unk74;
    u8 unk76;
    s8 unk77;
    u8 unk78[4];
    s32 unk7C;
} Cdata;

typedef void (*PlayerUnk80Func)(s16);

typedef struct Player {
    s16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    void* unkC;
    Vec3f pos;
    u32 unk1C;
    u8 unk20[0x8];
    Vec3f unk28;
    u8 unk34[0x4];
    u32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    u16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    u8 unk54[0x4];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    u8 unk64[0x2];
    u8 unk66;
    u8 unk67;
    s16 unk68;
    s16 unk6A;
    s16 unk6C;
    s16 unk6D;
    s16 unk70;
    s16 pad72;
    s32 unk74;
    u8 unk78[0x8];
    PlayerUnk80Func unk80;
    s32 unk84;
    u8 unk88;
    u8 unk89;
    u8 unk8A;
    u8 unk8B;
    s32 unk8C;
    Vec3f unk90;
    u32 unk9C;
    s32_f32_ptr unkA0;
    s32_f32_ptr unkA4;
    s32_f32_ptr unkA8;
    s32_f32_ptr unkAC;
    s32_f32_ptr unkB0;
    s32_f32_ptr unkB4;
    s32_f32_ptr unkB8;
    s32_f32_ptr unkBC;
    s32_f32_ptr unkC0;
    s32_f32_ptr unkC4;
    s32_f32_ptr unkC8;
    s32_f32_ptr unkCC;
    s32_f32_ptr unkD0;
    s32_f32_ptr unkD4;
    s32_f32_ptr unkD8;
    s32_f32_ptr unkDC;
    s32_f32_ptr unkE0;
    s32_f32_ptr unkE4;
    s32_f32_ptr unkE8;
    s32_f32_ptr unkEC;
    u8 unkF0[0x10];
} Player;

#define GET_PLAYER_PTR(idx) ((&players[(idx)]))
#define GET_PLAYER(x) (players[x])

#define RAD2DEG(x) ((f32)x * (180.0 / M_PI)) 
#define DEG2RAD(x) ((f32)x * (M_PI / 180.0))

#define RAD2DEG_ALT(x) (((f32)x * (2.0 * 3.14)) / 360.0)

#define NORM_ANGLE(x) \
        if((x) >= 360.0f){\
            for(; (x) >= 360.0f;){\
                (x) -= 360.0f;\
            }\
        }\
        else if((x) < 0.0f){\
            for(; (x) < 0.0f; ){\
                (x) += 360.0f;\
            }\
        }\

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
    volatile char2x_short unk3E;
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

#define D_800F5FB0_sets(arg0, arg1, arg2) D_800F5FB0.unkC = (arg0);D_800F5FB0.unk2 = (arg1);D_800F5FB0.unk0 = (arg2)
#define SQ(x) ((x) * (x))

#endif
