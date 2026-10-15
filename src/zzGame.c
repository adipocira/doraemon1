#include "zzGame.h"

#include "common.h"
#include "controller.h"
#include "global.h"
#include "segments.h"
#include "TexRec.h"
#include "zzFileSelect.h"
#include "zzTeller.h"
#include "7FC0.h"
#include "9320.h"
#include "B4E0.h"
#include "C830.h"
#include "C9E0.h"
#include "D530.h"
#include "14B00.h"
#include "15040.h"
#include "1D870.h"
#include "23B20.h"
#include "76BB0.h"
#include "823D0.h"

extern u8 D_800F6390[];

extern u16 D_800F3950;
extern u16 D_800CA220;

extern s32 D_800CA224;
extern s32 D_800CA228;

extern void* D_801BAAA0;

extern u8 D_800F6230[];

extern s32 D_800AC0A0[];
extern s32 D_800B50A0[];
extern s32 D_800AC008[];

extern TexRec D_800F6220;

#ifdef NON_MATCHING
void func_8000DAD0(_8000DAD0_arg0_struct* arg0){
    ROMCOPY(D_126480, D_802BD000);
    ROMCOPY(D_16A070, D_80305000);
    ROMCOPY(D_197F80, D_80335000);
    ROMCOPY(D_214A30, D_801CED20);
    curSegmentSize = D_80224820 - D_8020C820;
    D_800A82DC = &D_8020C820[curSegmentSize];

    D_800F3958.unk54 = func_8000BB58;
    D_800F3958.unk58 = func_8000AD54;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD4C;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 1;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.unkF = 7;
    D_800E69C0.syscalls = 0x71;
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 0;

    if (1);

    if(cdata.unk42 == 0){
        cdata.nextstg = D_800F3950;
    }else if(cdata.unk42 == 1){
        cdata.nextstg = D_800F3950;
    }else if(cdata.unk42 == 2){
        cdata.nextstg = ZZ_GAME0_LEVEL_OVERWORLD_GROUND;
    }else if(cdata.unk42 == 5){
        cdata.nextstg = ZZ_GAME0_LEVEL_OVERWORLD_GROUND;
    }else if(cdata.unk42 == 4){
        cdata.nextstg = ZZ_GAME0_LEVEL_OVERWORLD_GROUND;
    }else{
        cdata.nextstg = D_800F3950;
    }

    level_8000C930(0, D_8020C820, 1, arg0);

    D_800E69C0.unk3C.uchar[0] = 0;

    if(cdata.settings & GAME_SETTING(ZZ_GAME0_SETTING_DIFFICULTY)){
        func_80077D90(0.8f);
    }
    else{
        func_80077D90(1.0f);
    }

    func_80012C24(&D_800E6B20, D_800AC0A0, &D_800B50A0, 0x4B, 0xB7, 0, 2, 2, cdata.unk6A);
    
    D_800E6B20.unk16 = 1;
    D_800E6B20.unk24 = 0xB;\
    D_800E6B20.unk25 = 4;\
    D_800E6B20.unk29 = 5;
 
    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_800151B4(&D_800F6220, D_800F6230, D_800F6390, 0x58);
    
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    
    D_800F5FB0.unk1 = 0x14;

    if(cdata.nextstg > ZZ_GAME0_LEVEL_DEVIL && cdata.nextstg < ZZ_GAME0_LEVEL_2_1){
        D_800F5FB0.unk1C[0] = 0x7C1;
    } else if(cdata.nextstg >= ZZ_GAME0_LEVEL_2_1 && cdata.nextstg < ZZ_GAME0_LEVEL_3_1){
        D_800F5FB0.unk1C[0] = 0x3F;
    } else if(cdata.nextstg >= ZZ_GAME0_LEVEL_3_1 && cdata.nextstg < ZZ_GAME0_LEVEL_OVERWORLD_GROUND){
        D_800F5FB0.unk1C[0] = 0xF801;
    } else if(cdata.nextstg == ZZ_GAME0_LEVEL_INTRO_TOKYO && D_800E69C0.unk8 == 0x98){
        D_800F5FB0.unk1C[0] = 1;
    } else if(cdata.nextstg == ZZ_GAME0_LEVEL_INTRO_DEBUG && D_800E69C0.unk8 == 0x97){
        D_800F5FB0.unk1C[0] = 1;
    } else {
        D_800F5FB0.unk1C[0] = 0xFFFF;
    }

    func_8000B120(3);
    
    D_800F3920.unk0 = 5;
    D_800F3920.unk2 = 0xA;
    D_800F5FB0_sets(60, 1, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzGame/func_8000DAD0.s")
#endif

void func_8000DF50(_8000DAD0_arg0_struct* arg0){
    (void)"zzGame0() : cdata.nextstg = %d , stage_controll = %d\n";
    (void)"zzGameCntErr() : A\n";
    (void)"zzGameCntErr() : B\n";

    ROMCOPY(D_126480, D_802BD000);
    ROMCOPY(D_16A070, D_80305000);
    ROMCOPY(D_197F80, D_80335000);
    ROMCOPY(D_3CD4B0, D_801D5B20);
    ROMCOPY(D_214A30, D_801CED20);
    curSegmentSize = D_80224820 - D_8020C820;
    D_800A82DC = &D_8020C820[curSegmentSize];

    D_800F3958.unk54 = func_8008191C;
    D_800F3958.unk58 = func_8001DAC8;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD4C;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 3;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.unkF = 0;
    D_800E69C0.syscalls = 0x71;
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 3;

    D_800CA220 = 1;
    D_800CA224 = 0x3CF;
    D_800CA228 = 0x3E8;
    D_800CA230.unk0 = 0x8E;
    D_800CA230.unk4 = 0xCD;
    D_800CA230.unk8 = 0xF0;
    D_800CA230.unkC = 0xFF;

    controllers[0]->unk0.buttonTimers[ZZ_TIMER_START_BUTTON] = 10;

    cdata.nextstg = ZZ_GAME0_LEVEL_1_1;
    cdata.unk44 |= 8;

    D_800F0530.unk0 = 30.0f;
    D_800F0530.unk4 = 1.3333334f;
    D_800F0530.unk8 = 32.0f;
    D_800F0548.unkC = 0.0f;
    D_800F0548.unk10 = 0.0f;
    
    D_800F0548.unk14 = 0.0f;
    
    D_800F0530.unkC = 2000.0f;
    D_800F0548.unk0 = D_800F0548.unkC;
    D_800F0530.unk10 = 1.0f;
    D_800F0548.unk1C = 1.0f;
    D_800F0548.unk4 = D_800F0548.unk10 + 5.0f;
    D_800F0548.unk18 = 0.0f;
    D_800F0548.unk20 = 0.0f;
    D_800F0548.unk8 = D_800F0548.unk14 - 150.0f;

    func_8001CC70();
    func_80023644(8, 0x1E1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_80007648(0);
    func_800090B0(0);
    func_80012C24(&D_800E6B20, D_800AC0A0, D_800B50A0, 0x4B, 0xB7, 0, 2, 2, 8);

    D_800E6B20.unk16 = 1;
    D_800E6B20.unk24 = 0xB;\
    D_800E6B20.unk25 = 4;\
    D_800E6B20.unk29 = 5;

    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    
    D_800F5FB0.unk1 = 0x14;
    D_800F5FB0.unk1C[0] = 1;
    D_800E69C0.unk3C.uchar[0] = 0;
}

void func_8000E320(_8000DAD0_arg0_struct* arg0){
    ROMCOPY(D_126480, D_802BD000);
    ROMCOPY(D_16A070, D_80305000);
    ROMCOPY(D_197F80, D_80335000);
    ROMCOPY(D_3CD4B0, D_801D5B20);

    if(D_800E69C0.unk8 == 0x8C || D_800E69C0.unk8 == 0x63){
        ROMCOPY(D_3C0550, D_8020C820);
    }
    
    ROMCOPY(D_214A30, D_801CED20);
    curSegmentSize = D_80224820 - D_8020C820;
    D_800A82DC = &D_8020C820[curSegmentSize];

    D_800F3958.unk54 = NULL;
    D_800F3958.unk58 = func_8001DAC8;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD4C;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 3;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.unkF = 0;
    D_800E69C0.syscalls = 0x70;
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 3;

    D_800CA220 = 1;
    D_800CA224 = 0x3CF;
    D_800CA228 = 0x3E8;
    D_800CA230.unk0 = 0x8E;
    D_800CA230.unk4 = 0xCD;
    D_800CA230.unk8 = 0xF0;
    D_800CA230.unkC = 0xFF;

    controllers[0]->unk0.buttonTimers[ZZ_TIMER_START_BUTTON] = 10;

    cdata.nextstg = ZZ_GAME0_LEVEL_1_1;
    cdata.unk44 |= 8;

    D_800F0530.unk0 = 30.0f;
    D_800F0530.unk4 = 1.3333334f;
    D_800F0530.unk8 = 32.0f;
    D_800F0548.unkC = 0.0f;
    D_800F0548.unk10 = 0.0f;
    
    D_800F0548.unk14 = 0.0f;
    
    D_800F0530.unkC = 2000.0f;
    D_800F0548.unk0 = D_800F0548.unkC;
    D_800F0530.unk10 = 1.0f;
    D_800F0548.unk1C = 1.0f;
    D_800F0548.unk4 = D_800F0548.unk10 + 5.0f;
    D_800F0548.unk18 = 0.0f;
    D_800F0548.unk20 = 0.0f;
    D_800F0548.unk8 = D_800F0548.unk14 - 150.0f;

    func_8001CC70();
    func_80023644(8, 0x1E4, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_80007648(0);
    func_800090B0(0);
    func_80012C24(&D_800E6B20, D_800AC0A0, D_800B50A0, 0x4B, 0xB7, 0, 2, 2, 8);

    D_800E6B20.unk16 = 1;
    D_800E6B20.unk24 = 0xB;\
    D_800E6B20.unk25 = 4;\
    D_800E6B20.unk29 = 5;

    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    
    D_800F5FB0.unk1 = 0x14;
    D_800F5FB0.unk1C[0] = 1;
}

#ifdef NON_MATCHING
void func_8000E72C(_8000DAD0_arg0_struct* arg0){
    ROMCOPY(D_126480, D_802BD000);
    ROMCOPY(D_16A070, D_80305000);
    ROMCOPY(D_197F80, D_80335000);
    ROMCOPY(D_3CD4B0, D_801D5B20);

    D_800F3958.unk54 = zzFileSelectSub;
    D_800F3958.unk58 = NULL;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD4C;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 4;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.unkF = 0;
    D_800E69C0.syscalls = 0x61;
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 1;

    controllers[0]->unk0.buttonTimers[ZZ_TIMER_START_BUTTON] = 10;

    D_800F0530.unk0 = 30.0f;
    D_800F0530.unk4 = 1.3333334f;
    D_800F0530.unk8 = 32.0f;
    D_800F0548.unkC = 0.0f;
    D_800F0548.unk10 = 0.0f;
    
    D_800F0548.unk14 = 0.0f;
    
    D_800F0530.unkC = 2000.0f;
    D_800F0548.unk0 = D_800F0548.unkC;
    D_800F0530.unk10 = 1.0f;
    D_800F0548.unk1C = 1.0f;
    D_800F0548.unk4 = D_800F0548.unk10 + 5.0f;
    D_800F0548.unk18 = 0.0f;
    D_800F0548.unk20 = 0.0f;
    D_800F0548.unk8 = D_800F0548.unk14 - 150.0f;

    func_800090B0(0);
    func_80012C24(&D_800E6B20, D_800AC0A0, D_800B50A0, 0x1E, 0xB7, 0, 2, 2, 0);

    D_800E6B20.unk16 = 1;

    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_800151B4(&D_800F6220, D_800F6230, D_800F6390, 0x58);
    
    D_800E69C0.unk3C.uchar[0] = 0;
    D_800E69C0.unk3C.uchar[0] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzGame/func_8000E72C.s")
#endif

#ifdef NON_MATCHING
void func_8000E9E8(_8000DAD0_arg0_struct* arg0){
    ROMCOPY(D_126480, D_802BD000);
    ROMCOPY(D_16A070, D_80305000);
    ROMCOPY(D_197F80, D_80335000);
    ROMCOPY(D_214A30, D_801CED20);

    D_800F3958.unk54 = NULL;
    D_800F3958.unk58 = func_8001DAC8;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD4C;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 5;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.syscalls = 0x70;
    D_800E69C0.unkF = 0; 
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 3;

    controllers[0]->unk0.buttonTimers[ZZ_TIMER_START_BUTTON] = 10;
    cdata.nextstg = ZZ_GAME0_LEVEL_1_1;

    D_800F0530.unk0 = 30.0f;
    D_800F0530.unk4 = 1.3333334f;
    D_800F0530.unk8 = 32.0f;
    D_800F0548.unkC = 0.0f;
    D_800F0548.unk10 = 0.0f;
    
    D_800F0548.unk14 = 0.0f;
    
    D_800F0530.unkC = 2000.0f;
    D_800F0548.unk0 = D_800F0548.unkC;
    D_800F0530.unk10 = 1.0f;
    D_800F0548.unk1C = 1.0f;
    D_800F0548.unk4 = D_800F0548.unk10 + 5.0f;
    D_800F0548.unk18 = 0.0f;
    D_800F0548.unk20 = 0.0f;
    D_800F0548.unk8 = D_800F0548.unk14 - 150.0f;

    func_8001CC70();
    func_80023644(8, 0x1E5, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_80007648(0);
    func_800090B0(0);
    func_80012C24(&D_800E6B20, D_800AC0A0, D_800B50A0, 0x4B, 0xB7, 0, 2, 2, 8);

    D_800E6B20.unk16 = 1;
    D_800E6B20.unk24 = 0xB;\
    D_800E6B20.unk25 = 4;\
    D_800E6B20.unk29 = 5;

    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_80013F00(&D_800F5FB0, &D_801BAAA0, &D_801BAA80);
    
    D_800F5FB0.unk1 = 0x14;
    D_800F5FB0.unk1C[0] = 1;

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzGame/func_8000E9E8.s")
#endif

#ifdef NON_MATCHING
void func_8000ED00(_8000DAD0_arg0_struct* arg0){
    D_800F3958.unk54 = func_8000AD44;
    D_800F3958.unk58 = func_8000AD44;
    D_800F3958.unk5C = func_8000BDE0;
    D_800F3958.unk60 = func_8000BC30;
    D_800F3958.unk64 = func_8000AD44;
    D_800F3958.unk6C = 0;
    D_800F3958.unk70 = 0;
    D_800F3958.unk74 = 0;

    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk1 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 0;
    arg0->unk5 = 1;
    arg0->unk6 = 0;
    arg0->unk7 = 0;

    D_800E69C0.unk0 = 0;
    D_800E69C0.unk4 = 0;
    D_800E69C0.unk10 = 0;
    D_800E69C0.unk14 = 0;
    D_800E69C0.unkF = 0;
    D_800E69C0.syscalls = 0x60;
    D_800E69C0.unk18 = 0;
    D_800E69C0.cfb_render = 1;

    func_80007648(0);
    func_800090B0(0);
    func_80012C24(&D_800E6B20, D_800AC0A0, D_800B50A0, 0x2B, 0x60, 1, 4, 1, 0);

    D_800E6B20.unk24 = 0;\
    D_800E6B20.unk25 = 0;\
    D_800E6B20.unk29 = 0;
    
    if(D_800EEFB8.unk0 == 0){
        D_800E6B20.unk4 = D_800AC008;D_800E6B20.unk0 = 2;
        
    }else{
        D_800E6B20.unk4 = D_800ABFC0;D_800E6B20.unk0 = 2;
    }

    D_800F5FB0.unk0 = 0;
    func_80008C6C(0x37, 0U);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzGame/func_8000ED00.s")
#endif
