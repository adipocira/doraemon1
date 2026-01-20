#ifndef ACTOR_H
#define ACTOR_H

#include "ultra64.h"

#include "global.h"

typedef enum ActorCategory{
    ZZ_ACTOR_CATEGORY_1 = 1,
    ZZ_ACTOR_CATEGORY_2,
    ZZ_ACTOR_CATEGORY_3,
    ZZ_ACTOR_CATEGORY_4,
    ZZ_ACTOR_CATEGORY_5,
    ZZ_ACTOR_CATEGORY_6,
    ZZ_ACTOR_CATEGORY_7,
    ZZ_ACTOR_CATEGORY_8,
}zzActorCategory;

typedef enum zzActors{
    ZZ_ACTORS_PLAYER = 0x15E,
    ZZ_ACTORS_TREE = 0x164,
    ZZ_ACTORS_FIRE = 0x18A,
}zzActors;

typedef union s32_f32_ptr{
    s32 integer;
    f32 fp;
    void* ptr;
}s32_f32_ptr;

typedef void (*ActorUnk80Func)(s16);

typedef struct ActorUnk34Struct{
    f32 x;
    f32 y;
    f32 z;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
}ActorUnk34Struct;

typedef struct Actor {
    s16 unk0;
    u16 unk2;
    s32 status;
    s32 unk8;
    void* unkC;
    Vec3f pos;
    u32 unk1C;
    f32 unk20;
    f32 unk24;
    Vec3f rot;
    ActorUnk34Struct* unk34;
    s32 unk38;
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
    Vec3f dir;
    s16 unk64;
    u8 unk66;
    u8 unk67;
    s16 unk68;
    s16 unk6A;
    s16 unk6C;
    s16 unk6D;
    s16 unk70;
    s16 unk72;
    s32 unk74;
    u8 unk78[0x8];
    ActorUnk80Func unk80;
    s32 unk84;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 flags;
    Vec3f scale;
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
} Actor;

#define GET_ACTOR_PTR(idx) ((&actors[(idx)]))
#define GET_ACTOR(x) (actors[x])

extern Actor actors[];

#endif
