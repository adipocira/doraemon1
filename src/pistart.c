#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/pistart/PI_startPI.s")

/*
void PI_startPI() {
    s32 i;
    s32 idx;
    func_80003710_loadSegments();

    for (i = 0; i < 0x25800; i++) {
        D_803B5000 = 0;
    }

    for (i = 0; i < 0x12C00; i++) {
        D_80297800 = 0;
    }

    func_80013CF0(D_800E6A20, 16);

    idx = func_80013DDC(D_800E6A20, 16);

    D_800E6A20[idx].unk1 = 2;D_800E6A20[idx].unk2 = 1;D_800E6A20[idx].unk8 =
1;D_800E6A20[idx].unkC = 0;

    idx = func_80013DDC(D_800E6A20, 16);


    D_800E6A20[idx].unk1 = 2;D_800E6A20[idx].unk2 = 1;D_800E6A20[idx].unk8 =
60;D_800E6A20[idx].unkC = 0;

    idx = func_80013DDC(D_800E6A20, 16);

    D_800E6A20[idx].unk1 = 3;D_800E6A20[idx].unkC = 3600;D_800E6A20[idx].unk2 =
-1;D_800E6A20[idx].unk8 = 60;

    func_80013DDC(D_800E6A20, 16);
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    D_800F5FB0.unk1 = 0x14;
    osCreatePiManager(OS_PRIORITY_PIMGR, &piMesgQueue, piMsg,
ARRAY_COUNT(piMsg)); osCreateMesgQueue(&D_800E3F18, &D_800E3F30, 1);
    osCreateMesgQueue(&D_800EDDD0, &D_800EDDE8, 1);
}
*/