#ifndef COMMON_H
#define COMMON_H

#include "ultra64.h"
#include "global.h"
#include "actor.h"

typedef struct D_801591C0_struct_unk4 {
    u8 unk0[0x8];
    s16 unk8;
    u8 unkA[0x4];
    s16 unkE;
} D_801591C0_struct_unk4;

typedef struct D_801591C0_struct_unk48 {
    s16 unk0;
    u8 unk2[2];
    D_801591C0_struct_unk4* unk4;
    u8 unk8[0x60];
} D_801591C0_struct_unk48;

typedef struct D_80159178_struct {
    u8 unk0[0x48];
    D_801591C0_struct_unk48 unk48[1];
} D_80159178_struct;

extern D_80159178_struct D_80159178[1];

typedef struct D_801414A0_ptr_struct {
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
} D_801414A0_ptr_struct;
extern D_801414A0_ptr_struct* D_801414A0[];
typedef struct D_801414A0_struct{
    u8 unk0[0x8];
    void* unk8;
    void* unkC;
    void* unk10;
}D_801414A0_struct;

extern D_801414A0_ptr_struct* D_801414A0[];

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

typedef struct D_801B58F8_struct {
    s32 unk0;
    f32 unk4;
    u8 unk8[0x4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s16 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 unk28;
} D_801B58F8_struct;

extern D_801B58F8_struct D_801B58F8[1];

typedef struct D_800E6B20_struct {
    s16 unk0;
    s32 unk4;
    u8 unk8[0xE];
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B[0x5];
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26[0x3];
    u8 unk29;
    u8 unk2A[0x655D];
    u8 unk6587;
} D_800E6B20_struct;

extern D_800E6B20_struct D_800E6B20;

#define D_800E6B20_2022_sets(arg1, arg2) D_800E6B20.unk20 = (arg1);\
D_800E6B20.unk22 = (arg2)\

typedef struct D_801414A8_struct {
    u8 unk0[0x30];
    f32 unk30;
    u8 unk34[0x4];
    s32 unk38;
} D_801414A8_struct;

extern D_801414A8_struct* D_801414A8;

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

typedef struct D_800F9B08_struct{
    u8 unk0[0x4B8];
    u16 unk4B8;
    u8 unk4BA[0x30A];
    u16 unk7C4;
    u8 unk7C6[0x3A];
    u16 unk800;
    u8 unk802[0x3A];
    u16 unk83C;
    u8 unk83E[0x3A];
    u16 unk878;
    u8 unk87A[0x76];
    u16 unk8F0;
    u8 unk8F2[0x166];
    u16 unkA58;
    u8 unkA5A[0x3A];
    u16 unkA94;
    u8 unkA96[0x3A];
    u16 unkAD0;
    u8 unkAD2[0x3A];
    u16 unkB0C;
}D_800F9B08_struct; 
extern D_800F9B08_struct D_800F9B08;

typedef struct D_8010B820_struct{
    u8 unk0[0xA4];
    s32 unkA4;
    s32 unkA8;
}D_8010B820_struct;

extern D_8010B820_struct* D_8010B820;

typedef struct D_800F0588_struct{
    u8 unk0[0x1B];
    u8 unk1B;
    s8 unk1C;
    s8 unk1D;
    u8 unk1E[0x84];
    s16 unkA2;
}D_800F0588_struct;

extern D_800F0588_struct D_800F0588;

typedef struct D_800B5374_struct{
    s32 unk0;
    s32 unk4;
}D_800B5374_struct;

extern D_800B5374_struct D_800B5374[];
extern D_800B5374_struct D_800B53BC[]; 
extern D_800B5374_struct D_800B53F4[];

typedef struct D_802BD4A8_struct{
    f32 unk0;
    u8 unk4[0x18];
}D_802BD4A8_struct;

extern D_802BD4A8_struct D_802BD4A8[];

typedef struct D_800F5F88_struct {
    u8 unk0;
    s32* unk4;
} D_800F5F88_struct;

extern D_800F5F88_struct* D_801BA090[1];
extern D_800F5F88_struct* D_800F5F84;
extern D_800F5F88_struct* D_800F5F88;

typedef struct D_800F5F90_struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} D_800F5F90_struct;

extern D_800F5F90_struct D_800F5F90;

typedef struct D_800F3920_struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
} D_800F3920_struct;

extern D_800F3920_struct D_800F3920;

typedef struct D_800B6558_struct{
    s32 unk0;
    u8 unk4[0x10];
    u16* unk14;
}D_800B6558_struct;

extern D_800B6558_struct D_800B6558;

typedef struct D_800F3948_struct{
    u8 unk0[0x34];
    u32 unk34;
}D_800F3948_struct;

extern D_800F3948_struct* D_800F3948;

typedef struct D_80142BB8_struct{
    Vec3f unk0;
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
    s16 unk34;
    u8 unk36[0x1002];
    Light unk1038;
    u8 pad1048[0x61C];
    f32 unk1664;
    f32 unk1668;
    f32 unk166C;
    f32 unk1670;
    f32 unk1674;
}D_80142BB8_struct; // size = 0x1678
extern D_80142BB8_struct D_80142BB8[];
typedef struct D_801D5F30_struct{
    u8 unk0[0x1C];
    u16 unk1C;
    u8 unk1E[0x6];
} D_801D5F30_struct;

extern D_801D5F30_struct D_801D5F30[];

typedef struct D_802BD494_struct{
    u8 unk0[0x96];
    s16 unk96;
    u16 unk98;
    s16 unk9A;
}D_802BD494_struct;

extern D_802BD494_struct D_802BD494;

typedef struct D_803361C0_struct{
    u8 unk0[0x3C];
    s32 unk3C;
    s32 unk40;
    u16 unk44;
}D_803361C0_struct;
extern D_803361C0_struct D_803361C0;

typedef struct D_800F3944_struct{
    u8 unk0[0x14];
    s32 unk14;
    u8 unk18[0x18];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
}D_800F3944_struct;

extern D_800F3944_struct* D_800F3944;

#endif
