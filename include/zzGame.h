#ifndef ZZ_GAME_H
#define ZZ_GAME_H

#include "ultra64.h"

typedef enum Game0Level{
    ZZ_GAME0_LEVEL_DEVIL,
    ZZ_GAME0_LEVEL_1_1, // Grass
    ZZ_GAME0_LEVEL_1_2, // Dino
    ZZ_GAME0_LEVEL_1_3, // Cave
    ZZ_GAME0_LEVEL_1_4, // Volcano
    ZZ_GAME0_LEVEL_2_1, // Water
    ZZ_GAME0_LEVEL_2_2, // Race
    ZZ_GAME0_LEVEL_2_3, // Ship
    ZZ_GAME0_LEVEL_2_4, // Santa
    ZZ_GAME0_LEVEL_3_1, // Air
    ZZ_GAME0_LEVEL_3_2, // Bird
    ZZ_GAME0_LEVEL_3_3, // Thunder
    ZZ_GAME0_LEVEL_3_4, // Castle
    ZZ_GAME0_LEVEL_OVERWORLD_GROUND,
    ZZ_GAME0_LEVEL_OVERWORLD_AIR,
    ZZ_GAME0_LEVEL_INTRO_TOKYO,
    ZZ_GAME0_LEVEL_DEBUG,
}ZZGame0Level;

void func_8000E320(void);
void func_8000DF50(void);
void func_8000DAD0(void);
void func_8000E72C(void);
void func_8000E9E8(void);
void func_8000ED00(void);

#endif
