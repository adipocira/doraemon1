#ifndef ACTOR_H
#define ACTOR_H

#include "ultra64.h"

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

#endif
