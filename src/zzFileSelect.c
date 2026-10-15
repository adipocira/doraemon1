#include "zzFileSelect.h"
#include "zzGameData.h"
#include "zzBGScreen.h"
#include "save_file.h"
#include "zzGame.h"
#include "TexRec.h"
#include "global.h"
#include "common.h"
#include "controller.h"
#include "segments.h"
#include "7FC0.h"
#include "9320.h"
#include "FA60.h"
#include "11DF0.h"
#include "11F10.h"
#include "15040.h"

extern u8 D_8016B23C;
extern u8 D_8016B24C;


extern u16 D_800F3950;
extern u16 D_8016B0C0;
extern u16 D_8016B2AA;
extern u16 D_8016B2AC;
extern u16 D_8016B2B0;

extern s8 D_800AC040;

extern s16 D_8016B22C;
extern s16 D_8016B22E;
extern s16 D_8016B230;
extern s16 D_8016B232;
extern s16 D_8016B2A8;

extern s32 D_800ABCD0;
extern s32 D_800B6954;
extern s32 D_8016B250;
extern s32 D_801DB7D4;
extern s32 D_801DB7D8;
extern s32 D_801DB7DC;
extern s32 D_801DB7E0;
extern s32 D_801DB7E4;
extern s32 D_801DB7E8;
extern s32 D_801DB7EC;
extern s32 D_801DB7F0;
extern s32 D_801BDF10;
extern s32 D_801BEF60;
extern s32 D_801BEF80;
extern s32 D_801BEFA0;
extern s32 D_801BEFC0;

extern f32 D_8016B234;
extern f32 D_8016B238;

extern u8 D_800EEFB0[];
extern u8 D_8016B240[];

extern u16 D_8016B228[2];

extern s16 D_8016B298[];
extern s16 D_8016B2A0[];
extern s16 D_801D8EB0[];
extern s16 D_801D95F0[];
extern s16 D_801D9D70[];
extern s16 D_801D92C0[];
extern s16 D_801D99E0[];
extern s16 D_801DA160[];

extern s32 D_800B6958[];
extern s32 D_8016B0C8[];
extern s32 D_8016B220[];
extern s32 D_8016B2B8[];
extern s32 D_801DB560[];
extern s32 D_8016B2B8[];
extern s32 D_801C6B2C[];
extern s32 D_801C6B44[];

extern f32 D_8016B258[];
extern f32 D_8016B268[];
extern f32 D_8016B278[];
extern f32 D_8016B288[];

extern Gfx D_801D8BA8[];
extern Gfx D_801D9328[];
extern Gfx D_801D9A48[];
extern Gfx D_801D8FB8[];
extern Gfx D_801D9718[];
extern Gfx D_801D9E38[];

extern Gfx D_801BC748[][0x20];

u8 D_800B6920[][4] = {
    {
        0xFF, 0x02, 0x01, 0x0FF,
    },
    {
        0xFF, 0x03, 0xFF, 0x00,
    },
    {
        0x00, 0xFF, 0x03, 0xFF,
    },
    {
        0x01, 0xFF, 0xFF, 0x02,
    },
};

u8 D_800B6930 = 0;
u8 D_800B6934 = 0;
u8 D_800B6938 = 0;
u8 D_800B693C = 0;
u8 D_800B6940 = 0;

char D_800B6944[] = "DORAEMON DEBUG!";

s32 D_800B6954 = 0;

//todo
s32 D_800B6958[] = {
    0x801BDF10,
    0x801BEF60,
    0x801BEF80,
    0x801BEFA0,
    0x801BEFC0,
};

void func_80081C40(void){
    s32 i;

    (void)"sysGameData[%d].data.characterNO = %d\n";
    (void)"__loadItemCount()-------------------\n";
    (void)"    item = 0x%llx\n";
    (void)"    number of item = %d\n";
    (void)"__loadStone()-----------------------\n";
    (void)"    item = 0x%llx\n";
    (void)"    perfect stone\n";
    (void)"    piece stone\n";
    (void)"********** fileno = %d\n";
    (void)"__file_lv0():first\n";
    (void)" __file_lv30():NEW\n";
    (void)"copy : cfile = %d\n";
    (void)" __option_lv0():first\n";
    (void)"return option.....................\n";
    (void)"rgb 0:0:50 = 0x%x\n";
    (void)"zzFileSelectSub() : Error Bad Case.\n";
    (void)"ZZFileSelectSub() : case 8 debug pass\n";
    (void)"All Clear EEPROM\n";
    (void)"ZZFileSelectSub() : Case Error : %d\n";

    D_800EEFB0[0] = D_800B6930;
    D_800EEFB0[1] = 0;

    if(sysGameData[D_800EEFB0[0]].characterNO == 0){
        sysGameData[D_800EEFB0[0]].characterNO = 1;
        cdata.unk1C = 0;
        cdata.unk42 = 0;

        D_800F3950 = ZZ_GAME0_LEVEL_INTRO_DEBUG;
        D_800E69C0.unkA = 0x97;
    }
    else{
        D_800F3950 = ZZ_GAME0_LEVEL_OVERWORLD_GROUND;
        cdata.unk42 = 0;
        cdata.unk1C = sysGameData[D_800EEFB0[0]].characterNO - 1;
        D_800E69C0.unkA = 0x1F4;
    }

    cdata.unk20 = sysGameData[D_800EEFB0[0]].unk12;
    cdata.unk78[0] = 0;
    cdata.lives = sysGameData[D_800EEFB0[0]].lives;
    cdata.bells = sysGameData[D_800EEFB0[0]].bells;
    cdata.item = sysGameData[D_800EEFB0[0]].item;
    cdata.settings = sysGameData[D_800EEFB0[0]].settings;
    cdata.unk7C = sysGameData[D_800EEFB0[0]].unk20;
    
    for (i = 0; i < 18; i++) {
        cdata.events[i] = sysGameData[D_800EEFB0[0]].events[i];
    }

    if(cdata.settings & GAME_SETTING(ZZ_GAME0_SETTING_DIALOG_SPEED)){
        cdata.unk6A = 5;
    }
    else{
        cdata.unk6A = 0xA;
    }
    if(cdata.settings & GAME_SETTING(ZZ_GAME0_SETTING_AUDIO_MONO)){
        if(D_800ABCD0 != 0){
            D_800ABCD0 = 0;
            func_800074A8(0);
        }
    }
    else if(D_800ABCD0 == 0){
        D_800ABCD0 = 1;
        func_8000741C(0);
    }
    if(cdata.settings & GAME_SETTING(ZZ_GAME0_SETTING_BRIGHTNESS)){
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_ON | OS_VI_GAMMA_DITHER_ON | OS_VI_GAMMA_ON);
    }
    else{
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_ON | OS_VI_GAMMA_DITHER_ON | OS_VI_GAMMA_OFF);
    }
}

void func_80081E44(){
    D_800F3940_struct_unk0* v0 = &controllers[cdata.unk41]->unk0;

    if(v0->buttonTimers[ZZ_TIMER_START_BUTTON] == 0){
        D_8016B228[1] &= ~0x1;
    }
    if(v0->buttonTimers[ZZ_TIMER_A_BUTTON] == 0){
        D_8016B228[1] &= ~0x2;
    }
    if(v0->buttonTimers[ZZ_TIMER_B_BUTTON] == 0){
        D_8016B228[1] &= ~0x4;
    }
    if(v0->buttonTimers[ZZ_TIMER_L_TRIG] == 0){
        D_8016B228[1] &= ~0x20;
    }
    if(v0->buttonTimers[ZZ_TIMER_R_TRIG] == 0){
        D_8016B228[1] &= ~0x10;
    }    
}

void func_80081EEC(void){
    static s16 D_800B696C = 0;
    
    D_800F3940_struct* temp_v0;
    u8 temp_a1;
    u16 i;
    u16 j;

    temp_v0 = controllers[cdata.unk41];
    temp_a1 = D_800B6930;
    
    if(temp_v0->unkB8 >= 0x3D && temp_v0->unkBC < 0x3D){
        if(D_800B6920[D_800B6930][0] != 0xFF){
            D_800B6930 = D_800B6920[D_800B6930][0];
        }
    }else if(temp_v0->unkB8 < -0x3C && temp_v0->unkBC >= -0x3C){
        if(D_800B6920[D_800B6930][1] != 0xFF){
            D_800B6930 = D_800B6920[D_800B6930][1];
        }
    }else {
        if(temp_v0->unkB6 >= 0x3D && temp_v0->unkBA < 0x3D){
            if(D_800B6920[D_800B6930][2] != 0xFF){
                D_800B6930 = D_800B6920[D_800B6930][2];
            }
        }else if(temp_v0->unkB6 < -0x3C && temp_v0->unkBA >= -0x3C){
            if(D_800B6920[D_800B6930][3] != 0xFF){
                D_800B6930 = D_800B6920[D_800B6930][3];
            }
        }
    }
    if(D_800B6930 != temp_a1){
        func_80008C6C(0x26, 0);
    }

    for(i = 0, j = 0; i < 4; i++, j += 2){
        if(D_800B6930 == i){
            D_800B696C = 0;
        }else{
            D_800B696C = 0x40;
        }
        
        texRecAccess(D_8016B0C8[j + 0x48])->unk24 = D_800B696C;
        texRecAccess(D_8016B0C8[j + 0x49])->unk24 = D_800B696C;
    }
}

void func_800820FC(u8 idx){
    u8 characterNO = sysGameData[idx].characterNO;
    s32 pad;

    if(characterNO == 0){
        romCopy(D_3FB080, D_801DB800 + (idx * 0x7E0), 0x7E0);
        romCopy(D_3FB860, D_801DD780 + (idx * 0x200), 0x200);
    }
    else{
        characterNO--;
        romCopy(D_3DF820_segment + (characterNO * 0x3720), D_801DB800 + (idx * 0x7E0), 0x7E0);
        romCopy(D_3FA940_segment, D_801DD780 + (idx * 0x200), 0x200);
    }
}

void __loadItemCount(u8 idx){
    u16 i;
    s32* v0;
    u64 item = sysGameData[idx].item;
    u16 count = 0;
    
    for(i = 0; i < ZZ_ITEM_MAX_GADGETS; i++){
        if(item & CDATA_ITEM(i)){
            count++;
        }
    }

    v0 = &D_8016B0C8[idx*2];

    texRecAccess(v0[0x34])->unk10 = D_801BC748[count / 10];
    texRecAccess(v0[0x35])->unk10 = D_801BC748[count % 10];
}

void __loadStone(u8 fileIdx) {
    u16 i;
    u16 count;
    u16 itemStones[3];
    u16 j;
    u64 item;
    Gfx *sp70[6];
    s16 *sp58[6];

    sp70[0] = D_801D8BA8; sp70[1] = D_801D9328; sp70[2] = D_801D9A48; 
    sp70[3] = D_801D8FB8; sp70[4] = D_801D9718;sp70[5] = D_801D9E38;
    
    sp58[0] = D_801D8EB0;sp58[1] = D_801D95F0;sp58[2] = D_801D9D70;
    sp58[3] = D_801D92C0;sp58[4] = D_801D99E0;sp58[5] = D_801DA160;
    
    item = sysGameData[fileIdx].item;

    itemStones[0] = ZZ_ITEM_GREEN_STONE;itemStones[1] = ZZ_ITEM_BLUE_STONE;itemStones[2] = ZZ_ITEM_RED_STONE;

 
    for (i = 0; i < 3; i++) {
        if (item & CDATA_ITEM(itemStones[i])) {
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 28])->unk10 = sp70[i];
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 28])->unk14 = sp58[i];
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 40])->unk2A = 0;
            
            D_8016B240[fileIdx * 3 + i] = 0;
        } else {
            count = 0;
            
            for (j = 1; j < 4; j++) {
                if (item & CDATA_ITEM(itemStones[i]+j)) {
                    count++;
                }
            }

            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 28])->unk10 = sp70[i + 3];
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 28])->unk14 = sp58[i + 3];
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 40])->unk10 = &D_801BC748[count][0];
            texRecAccess(D_8016B0C8[fileIdx * 3 + i + 40])->unk2A = 1;
            
            D_8016B240[fileIdx * 3 + i] = 1;
        }
    }
}

void func_800826FC(u8 idx){
    func_800820FC(idx);
    __loadStone(idx);
    __loadItemCount(idx);    
}

void func_80082730(){
    s32 i;
    
    func_80089130(2);
    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);

    D_8016B0C0 = 0;

    for(i = 0; i < 0x55; i++){
        D_8016B0C8[D_8016B0C0++] = func_80015200(&texRec, D_801DB560[i]);
    }
    for(i = 0; i < 4; i++){
        func_800826FC(i);
    }

    texRecAccess(D_8016B0C8[0x48])->unk24 = 0;
    texRecAccess(D_8016B0C8[0x49])->unk24 = 0;
    texRecAccess(D_8016B0C8[0x4A])->unk24 = 0x40;
    texRecAccess(D_8016B0C8[0x4B])->unk24 = 0x40;
    texRecAccess(D_8016B0C8[0x4C])->unk24 = 0x40;
    texRecAccess(D_8016B0C8[0x4D])->unk24 = 0x40;
    texRecAccess(D_8016B0C8[0x4E])->unk24 = 0x40;
    texRecAccess(D_8016B0C8[0x4F])->unk24 = 0x40;

    D_8016B220[0] = func_80015200(&texRec, D_801BB3F0.unk0);
    texRecAccess(D_8016B220[0])->unk4 = 0x80;
    texRecAccess(D_8016B220[0])->unk6 = 0xAC;
    texRecAccess(D_8016B220[0])->unk8 = texRecAccess(D_8016B220[0])->unk0 + 0x80;
    texRecAccess(D_8016B220[0])->unkA = texRecAccess(D_8016B220[0])->unk2 + 0xAC;
    texRecAccess(D_8016B220[0])->unk28 = 0xFF;
    texRecAccess(D_8016B220[0])->unk24 = 0xFF;
    texRecAccess(D_8016B220[0])->unk2A = 0;

    D_8016B220[1] = func_80015200(&texRec, D_801BB3F0.unk5C);
    texRecAccess(D_8016B220[1])->unk4 = 0x84;
    texRecAccess(D_8016B220[1])->unk6 = 0xB0;
    texRecAccess(D_8016B220[1])->unk8 = texRecAccess(D_8016B220[1])->unk0 + 0x84;
    texRecAccess(D_8016B220[1])->unkA = texRecAccess(D_8016B220[1])->unk2 + 0xB0;
    texRecAccess(D_8016B220[1])->unk28 = 0xFA;
    texRecAccess(D_8016B220[1])->unk24 = 0x88;
    texRecAccess(D_8016B220[1])->unk2A = 0;
}

#ifdef NON_MATCHING
//todo
void func_80082B88(u8 arg0, s16 arg1, s16 arg2){
    #define MY_SETTER(idx, x, y) \
    texRecAccess(D_8016B0C8[(idx)])->unk4 = (s32)(x); \
    texRecAccess(D_8016B0C8[(idx)])->unk6 = (s32)(y); \
    texRecAccess(D_8016B0C8[(idx)])->unk8 = texRecAccess(D_8016B0C8[(idx)])->unk0 + (s32)(x); \
    texRecAccess(D_8016B0C8[(idx)])->unkA = texRecAccess(D_8016B0C8[(idx)])->unk2 + (s32)(y); 

    MY_SETTER(arg0*2+0x5, (u16)arg1, (u16)arg2);
    MY_SETTER(arg0*2+0x6, (u16)arg1, (u16)arg2+32);
    
    MY_SETTER(arg0*2+0x48, (u16)arg1, (u16)arg2);
    MY_SETTER(arg0*2+0x49, (u16)arg1, (u16)arg2+32);

    MY_SETTER(arg0*2+0x11, (u16)arg1+2, (u16)arg2+2);
    MY_SETTER(arg0*2+0x12, (u16)arg1+2, (u16)arg2+34);

    MY_SETTER(arg0*1+0x44, (u16)arg1+5, (u16)arg2+4);

    MY_SETTER(arg0*3+0x1C, (u16)arg1+52, (u16)arg2+6);
    MY_SETTER(arg0*3+0x1D, (u16)arg1+75, (u16)arg2+6);
    MY_SETTER(arg0*3+0x1E, (u16)arg1+98, (u16)arg2+6);

    MY_SETTER(arg0*3+0x28, (u16)arg1+59, (u16)arg2+7);
    MY_SETTER(arg0*3+0x29, (u16)arg1+82, (u16)arg2+7);
    MY_SETTER(arg0*3+0x2A, (u16)arg1+105, (u16)arg2+7);

    MY_SETTER(arg0*1+0x3C, (u16)arg1+57, (u16)arg2+34);

    MY_SETTER(arg0*2+0x34, (u16)arg1+77, (u16)arg2+41);
    MY_SETTER(arg0*2+0x35, (u16)arg1+91, (u16)arg2+41);

    MY_SETTER(arg0*1+0x40, (u16)arg1+104, (u16)arg2+43);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzFileSelect/func_80082B88.s")
#endif

void func_80083758(u8 arg0, s16 arg1){
    texRecAccess(D_8016B0C8[arg0*2+0x5])->unk28 = arg1+30;
    texRecAccess(D_8016B0C8[arg0*2+0x6])->unk28 = arg1+30;
    texRecAccess(D_8016B0C8[arg0*2+0x48])->unk28 = arg1+60;
    texRecAccess(D_8016B0C8[arg0*2+0x49])->unk28 = arg1+60;
    texRecAccess(D_8016B0C8[arg0*2+0x11])->unk28 = arg1+20;
    texRecAccess(D_8016B0C8[arg0*2+0x12])->unk28 = arg1+20;
    texRecAccess(D_8016B0C8[arg0*1+0x44])->unk28 = arg1+40;
    texRecAccess(D_8016B0C8[arg0*3+0x1C])->unk28 = arg1+40;
    texRecAccess(D_8016B0C8[arg0*3+0x1D])->unk28 = arg1+40;
    texRecAccess(D_8016B0C8[arg0*3+0x1E])->unk28 = arg1+40;
    texRecAccess(D_8016B0C8[arg0*3+0x28])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*3+0x29])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*3+0x2A])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*1+0x3C])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*2+0x34])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*2+0x35])->unk28 = arg1+50;
    texRecAccess(D_8016B0C8[arg0*1+0x40])->unk28 = arg1+40;
}

void func_80083A18(u8 arg0, u8 arg1){
    texRecAccess(D_8016B0C8[arg0*2+0x5])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x6])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x48])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x49])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x11])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x12])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*1+0x44])->unk2A = arg1;
    
    texRecAccess(D_8016B0C8[arg0*3+0x1C])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*3+0x1D])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*3+0x1E])->unk2A = arg1;

    if(D_8016B240[arg0*3+0] != 0){
        texRecAccess(D_8016B0C8[arg0*3+0x28])->unk2A = arg1;
    }
    if(D_8016B240[arg0*3+1] != 0){
        texRecAccess(D_8016B0C8[arg0*3+0x29])->unk2A = arg1;
    }
    if(D_8016B240[arg0*3+2] != 0){
        texRecAccess(D_8016B0C8[arg0*3+0x2A])->unk2A = arg1;
    }

    texRecAccess(D_8016B0C8[arg0*1+0x3C])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x34])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*2+0x35])->unk2A = arg1;
    texRecAccess(D_8016B0C8[arg0*1+0x40])->unk2A = arg1;
}

void func_80083CF4(){
    u8 a0 = D_800B6930;

    if(D_800B6938 == 0){
        D_800E6B20.unk4 = D_801DB7D4;
        D_800E6B20.unk0 = 2;
        D_800B6938++;
    }

    func_80081EEC();

    if(D_800B6930 == a0){
        if(!(D_8016B228[1] & 0x2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
            D_8016B228[1] |= 2;
            D_800B6934 = 1;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);
        }
        else if(!(D_8016B228[1] & 0x20) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_L_TRIG] == 1){
            D_8016B228[1] |= 2;
            D_800B6934 = 20;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);            
        }
        else if(!(D_8016B228[1] & 0x10) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_R_TRIG] == 1){
            D_8016B228[1] |= 2;
            D_800B6934 = 30;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);            
        }
        else if(!(D_8016B228[1] & 0x8) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_Z_TRIG] == 1){
            D_8016B228[1] |= 2;

            if(sysGameData[D_800B6930].characterNO == 0){
                D_800B6940 = 2;
            }
            else{
                D_800B6940 = 1;
            }
            
            D_800B6934 = 40;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);            
        }
    }
}

#ifdef NON_EQUIVALENT
//todo
void func_80083F30(){
    s32 i;
    s32 v1;
    s32 a0;
    s32 a1;
    
    if(D_800B6938 == 0){
        D_800E6B20.unk0 = 0;

        texRecAccess(D_8016B0C8[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x2])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x3])->unk2A = 0;

        texRecAccess(D_8016B0C8[0xD])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xF])->unk2A = 0;

        texRecAccess(D_8016B0C8[0x19])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1B])->unk2A = 0;

        texRecAccess(D_8016B0C8[0x50])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x52])->unk2A = 0;

        D_8016B298[0] = 28;
        D_8016B278[0] = 28;
        
        D_8016B2A0[0] = 44;
        D_8016B288[0] = 44;
        
        D_8016B258[0] = (96.0f - 28) / 10;
        D_8016B268[0] = (88.0f - 44) / 10;

        D_8016B298[1] = 164;
        D_8016B278[1] = 164;
        
        D_8016B2A0[1] = 44;
        D_8016B288[1] = 44;
        
        D_8016B258[1] = (96.0f - 164) / 10;
        D_8016B268[1] = (88.0f - 44) / 10;

        D_8016B298[2] = 164;
        D_8016B278[2] = 164;
        
        D_8016B2A0[2] = 44;
        D_8016B288[2] = 44;
        
        D_8016B258[2] = (96.0f - 112) / 10;
        D_8016B268[2] = (88.0f - 44) / 10;

        D_8016B298[3] = 164;
        D_8016B278[3] = 164;
        
        D_8016B2A0[3] = 112;
        D_8016B288[3] = 112;
        
        D_8016B258[3] = (96.0f - 164) / 10;
        D_8016B268[3] = (88.0f - 112) / 10;

        func_80083758(D_800B6930, 0x64);
        
        D_8016B2A8 = 10;
        D_800B6938++;
    }
    else{
        D_8016B2A8--;

        if(D_8016B2A8 < 0){
            for(i = 0; i < 4; i++){
                func_80082B88(i, 0x60, 0x58);
            }
            for(i = 0; i < 4; i++){
                if(D_800B6930 != i){
                    func_80083A18(i, 0);
                }
            }

            D_800B6934 = 2;
            D_800B6938--;
        }
        else{
            for(i = 0; i < 4; i++){
                D_8016B278[i] += D_8016B258[i];
                D_8016B288[i] += D_8016B268[i];    

                func_80082B88(i, D_8016B278[i], D_8016B288[i]);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/zzFileSelect/func_80083F30.s")
#endif

void func_80084490(){
    texRecAccess(D_8016B220[0])->unk2A = 1;
    texRecAccess(D_8016B220[1])->unk2A = 1;
    
    texRecAccess(D_8016B220[0])->unk4 = 128;
    texRecAccess(D_8016B220[0])->unk6 = 172;

    texRecAccess(D_8016B220[0])->unk8 = texRecAccess(D_8016B220[0])->unk0 + 128;
    texRecAccess(D_8016B220[0])->unkA = texRecAccess(D_8016B220[0])->unk2 + 172;

    texRecAccess(D_8016B220[1])->unk4 = 130;
    texRecAccess(D_8016B220[1])->unk6 = 174;

    texRecAccess(D_8016B220[1])->unk8 = texRecAccess(D_8016B220[1])->unk0 + 130;
    texRecAccess(D_8016B220[1])->unkA = texRecAccess(D_8016B220[1])->unk2 + 174;

    D_8016B2AA = D_800E6B20.unk20;
    D_8016B2AC = D_800E6B20.unk22;

    D_800E6B20.unk20 = 48;
    D_800E6B20.unk22 = 156;
    D_800E6B20.unk4 = D_801DB7D8;
    D_800E6B20.unk0 = 2;
    

    D_8016B23C = 1;
    D_8016B22E = 0x10;
    D_8016B230 = 0xAC;
    D_8016B234 = 0.0f;
    D_8016B238 = 0.25f;
    D_8016B22C = 0x10;
    D_800B6934 = 3;
}

void func_800846D4(){
    if(!(D_8016B228[1] & 2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
        D_8016B228[1] |= 2;
        D_800E6B20.unk0 = 0;

        D_800B6938 = 0;

        func_80008C6C(0xAD, 0);

        if(sysGameData[D_800B6930].characterNO == 0){
            D_800B6940 = 3;
            D_800B6934 = 0x28;
        }
        else{
            func_80081C40();
            D_800E6B20.unk0 = 0;
            D_800B6938 = 0;
            
            func_80008C6C(0xAD, 0);
            D_800E69C0.unk3C.uchar[0] = 0x46;
        }
    }
    else if(!(D_8016B228[1] & 4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
        D_8016B228[1] |= 4;
        texRecAccess(D_8016B220[0])->unk2A = 0;
        texRecAccess(D_8016B220[1])->unk2A = 0;
        
        D_800E6B20.unk0 = 0;
        
        D_800E6B20.unk20 = D_8016B2AA;
        D_800E6B20.unk22 = D_8016B2AC;
        D_800B6934 = 4;
        
        func_80008C6C(0xAD, 0);
    }
    else{
        func_80011564(&D_8016B22C, &D_8016B22E, &D_8016B238, &D_8016B234, &D_8016B23C, &D_8016B230);
        
        texRecAccess(D_8016B220[0])->unk4 = 128;
        texRecAccess(D_8016B220[0])->unk6 = D_8016B230;

        texRecAccess(D_8016B220[0])->unk8 = texRecAccess(D_8016B220[0])->unk0 + 128;
        texRecAccess(D_8016B220[0])->unkA = texRecAccess(D_8016B220[0])->unk2 + (u16)D_8016B230;

        texRecAccess(D_8016B220[1])->unk4 = 128 + 2;
        texRecAccess(D_8016B220[1])->unk6 = (u16)D_8016B230 + 2;

        texRecAccess(D_8016B220[1])->unk8 = texRecAccess(D_8016B220[1])->unk0 + 128 + 2;
        texRecAccess(D_8016B220[1])->unkA = texRecAccess(D_8016B220[1])->unk2 + (u16)D_8016B230 + 2;
    }
}

void func_80084A54(void){
    s32 i;

    if(D_800B6938 == 0){
        for(i = 0; i < 4; i++){
            D_8016B278[i] = D_8016B298[i] = 0x60;
            D_8016B288[i] = D_8016B2A0[i] = 0x58;
            
            D_8016B258[i] = ((s32)((u32)(i & 1) * 0x88 + 28) - D_8016B278[i]) / 10.0;
            D_8016B268[i] = ((i > 1) * 0x44 + 44 - D_8016B288[i]) / 10.0;
            
            func_80083A18(i, 1);
        }
        D_8016B2A8 = 10;
        D_800B6938++;
    }
    else {
        D_8016B2A8--;
        
        if(D_8016B2A8 < 0){
            for(i = 0; i < 4; i++){
                func_80082B88(i, (i % 2U) * 0x88 + 28, (i >= 2) * 0x44 + 44);
            }

            func_80083758(D_800B6930, 0);

            texRecAccess(D_8016B0C8[1])->unk2A = 1;
            texRecAccess(D_8016B0C8[2])->unk2A = 1;
            texRecAccess(D_8016B0C8[3])->unk2A = 1;

            texRecAccess(D_8016B0C8[13])->unk2A = 1;
            texRecAccess(D_8016B0C8[14])->unk2A = 1;
            texRecAccess(D_8016B0C8[15])->unk2A = 1;

            texRecAccess(D_8016B0C8[25])->unk2A = 1;
            texRecAccess(D_8016B0C8[26])->unk2A = 1;
            texRecAccess(D_8016B0C8[27])->unk2A = 1;

            texRecAccess(D_8016B0C8[80])->unk2A = 1;
            texRecAccess(D_8016B0C8[81])->unk2A = 1;
            texRecAccess(D_8016B0C8[82])->unk2A = 1;

            D_800B6934 = 0;
            D_800B6938--;
        }
        else{
            for(i = 0; i < 4; i++){
                D_8016B278[i] += D_8016B258[i];
                D_8016B288[i] += D_8016B268[i];
            
                func_80082B88(i, D_8016B278[i], D_8016B288[i]);
            }
        }
    }
}

void func_80084EEC(){
    if(D_800B6938 == 0){
        texRecAccess(D_8016B0C8[0x50])->unk24 = 0;

        D_8016B23C = 1;
        D_8016B22E = 4;
        D_8016B230 = 0x1C;
        D_8016B234 = 0.0f;
        D_8016B238 = 0.5f;
        D_8016B22C = 4;
        D_8016B232 = 0x18;
        
        D_800B6938++;
    }
    else if(--D_8016B232 < 0){
        texRecAccess(D_8016B0C8[0xD])->unk4 = 28;
        texRecAccess(D_8016B0C8[0xD])->unk6 = 196;

        texRecAccess(D_8016B0C8[0xD])->unk8 = texRecAccess(D_8016B0C8[0xD])->unk0 + 28;
        texRecAccess(D_8016B0C8[0xD])->unkA = texRecAccess(D_8016B0C8[0xD])->unk2 + 196;
                
        texRecAccess(D_8016B0C8[0x50])->unk4 = 28;
        texRecAccess(D_8016B0C8[0x50])->unk6 = 196;

        texRecAccess(D_8016B0C8[0x50])->unk8 = texRecAccess(D_8016B0C8[0x50])->unk0 + 28;
        texRecAccess(D_8016B0C8[0x50])->unkA = texRecAccess(D_8016B0C8[0x50])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x19])->unk4 = 28+3;
        texRecAccess(D_8016B0C8[0x19])->unk6 = 196+3;

        texRecAccess(D_8016B0C8[0x19])->unk8 = texRecAccess(D_8016B0C8[0x19])->unk0 + 28+3;
        texRecAccess(D_8016B0C8[0x19])->unkA = texRecAccess(D_8016B0C8[0x19])->unk2 + 196+3;

        texRecAccess(D_8016B0C8[0x1])->unk4 = 28 + 35;
        texRecAccess(D_8016B0C8[0x1])->unk6 = 196+1;

        texRecAccess(D_8016B0C8[0x1])->unk8 = texRecAccess(D_8016B0C8[0x1])->unk0 + 28 + 35;
        texRecAccess(D_8016B0C8[0x1])->unkA = texRecAccess(D_8016B0C8[0x1])->unk2 + 196+1;

        D_800B6934 = 0x15;
        D_800B6938--;
    }
    else{
        func_80011564(&D_8016B22C, &D_8016B22E, &D_8016B238, &D_8016B234, &D_8016B23C, &D_8016B230);

        texRecAccess(D_8016B0C8[0xD])->unk4 = (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0xD])->unk6 = 196;

        texRecAccess(D_8016B0C8[0xD])->unk8 = texRecAccess(D_8016B0C8[0xD])->unk0 + (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0xD])->unkA = texRecAccess(D_8016B0C8[0xD])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x50])->unk4 = D_8016B230;
        texRecAccess(D_8016B0C8[0x50])->unk6 = 196;

        texRecAccess(D_8016B0C8[0x50])->unk8 = texRecAccess(D_8016B0C8[0x50])->unk0 + (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0x50])->unkA = texRecAccess(D_8016B0C8[0x50])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x19])->unk4 = (u16)D_8016B230+3;
        texRecAccess(D_8016B0C8[0x19])->unk6 = 196+3;

        texRecAccess(D_8016B0C8[0x19])->unk8 = texRecAccess(D_8016B0C8[0x19])->unk0 + (u16)D_8016B230+3;
        texRecAccess(D_8016B0C8[0x19])->unkA = texRecAccess(D_8016B0C8[0x19])->unk2 + 196+3;

        texRecAccess(D_8016B0C8[0x1])->unk4 = (u16)D_8016B230 + 35;
        texRecAccess(D_8016B0C8[0x1])->unk6 = 196+1;

        texRecAccess(D_8016B0C8[0x1])->unk8 = texRecAccess(D_8016B0C8[0x1])->unk0 + (u16)D_8016B230 + 35;
        texRecAccess(D_8016B0C8[0x1])->unkA = texRecAccess(D_8016B0C8[0x1])->unk2 + 196+1;

        texRecAccess(D_8016B0C8[0x2])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x3])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xF])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1B])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x52])->unk2A = 0;
    }
}
void func_800856C4(){
    u8 v1 = D_800B6930;
    
    if(D_800B6938 == 0){
        D_800E6B20.unk4 = D_801DB7DC;
        D_800E6B20.unk0 = 2;
        D_800B6938++;
    }

    func_80081EEC();

    if(D_800B6930 == v1){
        if(!(D_8016B228[1] & 2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
            D_8016B228[1] |= 2;
            
            D_800B6934 = 0x16;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);
        }
        else if(!(D_8016B228[1] & 4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
            D_8016B228[1] |= 4;

            texRecAccess(D_8016B0C8[0x50])->unk24 = 0x40;
                    
            texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x3])->unk2A = 1;
            texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
            texRecAccess(D_8016B0C8[0xF])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x1B])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x52])->unk2A = 1;

            D_800B6934 = 0;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);
            D_800B6930 = 0;
        }
    }
}

void func_80085964(){
    if(D_800B6938 == 0){
        texRecAccess(D_8016B220[0x0])->unk4 = 128;
        texRecAccess(D_8016B220[0x0])->unk6 = 192;

        texRecAccess(D_8016B220[0x0])->unk8 = texRecAccess(D_8016B220[0x0])->unk0 + 128;
        texRecAccess(D_8016B220[0x0])->unkA = texRecAccess(D_8016B220[0x0])->unk2 + 192;

        texRecAccess(D_8016B220[0x1])->unk4 = 128 + 2;
        texRecAccess(D_8016B220[0x1])->unk6 = 192 + 2;

        texRecAccess(D_8016B220[0x1])->unk8 = texRecAccess(D_8016B220[0x1])->unk0 + 128 + 2;
        texRecAccess(D_8016B220[0x1])->unkA = texRecAccess(D_8016B220[0x1])->unk2 + 192 + 2;

        texRecAccess(D_8016B220[0x0])->unk2A = 1;
        texRecAccess(D_8016B220[0x1])->unk2A = 1;

        D_800E6B20.unk4 = D_801DB7E0;
        D_800E6B20.unk0 = 2;
        
        D_8016B23C = 1;
        D_8016B22E = 8;
        D_8016B230 = 0xC0;
        D_8016B234 = 0.0f;
        D_8016B238 = 0.25f;
        D_8016B22C = 8;
        
        D_800B6938++;
        
    }
    
    if(!(D_8016B228[1] & 2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
        D_8016B228[1] |= 2;

        texRecAccess(D_8016B0C8[0x50])->unk24 = 0x40;

        texRecAccess(D_8016B220[0x0])->unk2A = 0;
        texRecAccess(D_8016B220[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x3])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xF])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1B])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x52])->unk2A = 1;

        D_800B6934 = 0x17;
        D_800B6938--;
            
        func_80008C6C(0xAD, 0);
    }
    else if(!(D_8016B228[1] & 4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
        D_8016B228[1] |= 4;

        texRecAccess(D_8016B0C8[0x50])->unk24 = 0x40;
                    
        texRecAccess(D_8016B220[0x0])->unk2A = 0;
        texRecAccess(D_8016B220[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x3])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xF])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1B])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x52])->unk2A = 1;

        D_800B6934 = 0;
        D_800B6938--;
            
        func_80008C6C(0xAD, 0);
        
        D_800B6930 = 0;
    }
    else{
        func_80011564(&D_8016B22C, &D_8016B22E, &D_8016B238, &D_8016B234, &D_8016B23C, (s16*)&D_8016B230);


        texRecAccess(D_8016B220[0x0])->unk4 = 128;
        texRecAccess(D_8016B220[0x0])->unk6 = D_8016B230;

        texRecAccess(D_8016B220[0x0])->unk8 = texRecAccess(D_8016B220[0x0])->unk0 + 128;
        texRecAccess(D_8016B220[0x0])->unkA = texRecAccess(D_8016B220[0x0])->unk2 + (u16)D_8016B230;

        texRecAccess(D_8016B220[0x1])->unk4 = 128 + 2;
        texRecAccess(D_8016B220[0x1])->unk6 = (u16)D_8016B230 + 2;

        texRecAccess(D_8016B220[0x1])->unk8 = texRecAccess(D_8016B220[0x1])->unk0 + 128 + 2;
        texRecAccess(D_8016B220[0x1])->unkA = texRecAccess(D_8016B220[0x1])->unk2 + (u16)D_8016B230 + 2;
    }
}

void func_8008616C(void){
    s32 i;
    
    if(D_800B6938 == 0){
        D_800B6938 = 1;

        for(i = 0; i < (s32)sizeof(SysGameData_unk0); i++) { sysGameData[D_800B6930].unk0.raw[i] = 0; }

        sysGameData[D_800B6930].characterNO = ZZ_CHARACTER_NONE;
        sysGameData[D_800B6930].unk12 = 0x19;
        sysGameData[D_800B6930].lives = 2;
        sysGameData[D_800B6930].bells = 0;
        sysGameData[D_800B6930].item = 0;

        sysGameData[D_800B6930].settings = 0;
        sysGameData[D_800B6930].unk20 = 594000;
        
        for(i = 0; i < 18; i++){
            sysGameData[D_800B6930].events[i] = 0;
        }

        *D_800EEFB0 = D_800B6930;
        func_80002BB8();
    }
    else if(++D_800B6938 >= 9){
        func_80002BF4();
        D_800B6934 = 0x18;
    }
}

void func_80086294(){
    if(D_800EEFB8.unk8 == 0){
        func_80002C50();
        func_800826FC(D_800B6930);

        D_800B6934 = 0;
        D_800B6938 = 0;
        D_800B6930 = 0;
    }
}

void func_800862EC(){
    if(D_800B6938 == 0){
        texRecAccess(D_8016B0C8[0x52])->unk24 = 0;
        
        D_8016B23C = 1;
        D_8016B22E = 4;
        D_8016B230 = 0xD4;
        D_8016B234 = 0.0f;
        D_8016B238 = 0.5f;
        D_8016B22C = 4;
        D_8016B232 = 0x18;

        D_800B6938++;
    }
    else if(--D_8016B232 < 0){
        texRecAccess(D_8016B0C8[0xF])->unk4 = 212;
        texRecAccess(D_8016B0C8[0xF])->unk6 = 196;

        texRecAccess(D_8016B0C8[0xF])->unk8 = texRecAccess(D_8016B0C8[0xF])->unk0 + 212;
        texRecAccess(D_8016B0C8[0xF])->unkA = texRecAccess(D_8016B0C8[0xF])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x52])->unk4 = 212;
        texRecAccess(D_8016B0C8[0x52])->unk6 = 196;

        texRecAccess(D_8016B0C8[0x52])->unk8 = texRecAccess(D_8016B0C8[0x52])->unk0 + 212;
        texRecAccess(D_8016B0C8[0x52])->unkA = texRecAccess(D_8016B0C8[0x52])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x1B])->unk4 = 212 + 3;
        texRecAccess(D_8016B0C8[0x1B])->unk6 = 196 + 3;

        texRecAccess(D_8016B0C8[0x1B])->unk8 = texRecAccess(D_8016B0C8[0x1B])->unk0 + 212 + 3;
        texRecAccess(D_8016B0C8[0x1B])->unkA = texRecAccess(D_8016B0C8[0x1B])->unk2 + 196 + 3;

        texRecAccess(D_8016B0C8[0x3])->unk4 = 212 + 4;
        texRecAccess(D_8016B0C8[0x3])->unk6 = 196 + 1;

        texRecAccess(D_8016B0C8[0x3])->unk8 = texRecAccess(D_8016B0C8[0x3])->unk0 + 212 + 4;
        texRecAccess(D_8016B0C8[0x3])->unkA = texRecAccess(D_8016B0C8[0x3])->unk2 + 196 + 1;

        D_800B6934 = 0x1F;
        D_800B6938--;
    }
    else{
        func_80011564(&D_8016B22C, &D_8016B22E, &D_8016B238, &D_8016B234, &D_8016B23C, &D_8016B230);

        texRecAccess(D_8016B0C8[0xF])->unk4 = (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0xF])->unk6 = 196;

        texRecAccess(D_8016B0C8[0xF])->unk8 = texRecAccess(D_8016B0C8[0xF])->unk0 + (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0xF])->unkA = texRecAccess(D_8016B0C8[0xF])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x52])->unk4 = D_8016B230;
        texRecAccess(D_8016B0C8[0x52])->unk6 = 196;

        texRecAccess(D_8016B0C8[0x52])->unk8 = texRecAccess(D_8016B0C8[0x52])->unk0 + (u16)D_8016B230;
        texRecAccess(D_8016B0C8[0x52])->unkA = texRecAccess(D_8016B0C8[0x52])->unk2 + 196;

        texRecAccess(D_8016B0C8[0x1B])->unk4 = (u16)D_8016B230+3;
        texRecAccess(D_8016B0C8[0x1B])->unk6 = 196+3;

        texRecAccess(D_8016B0C8[0x1B])->unk8 = texRecAccess(D_8016B0C8[0x1B])->unk0 + (u16)D_8016B230+3;
        texRecAccess(D_8016B0C8[0x1B])->unkA = texRecAccess(D_8016B0C8[0x1B])->unk2 + 196+3;

        texRecAccess(D_8016B0C8[0x3])->unk4 = (u16)D_8016B230 + 4;
        texRecAccess(D_8016B0C8[0x3])->unk6 = 196+1;

        texRecAccess(D_8016B0C8[0x3])->unk8 = texRecAccess(D_8016B0C8[0x3])->unk0 + (u16)D_8016B230 + 4;
        texRecAccess(D_8016B0C8[0x3])->unkA = texRecAccess(D_8016B0C8[0x3])->unk2 + 196+1;

        texRecAccess(D_8016B0C8[0x2])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 0;
        texRecAccess(D_8016B0C8[0xD])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x19])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x50])->unk2A = 0;        
    }
}

void func_80086AC4(){
    u8 v1 = D_800B6930;
    
    if(D_800B6938 == 0){
        D_800E6B20.unk4 = D_801DB7E4;
        D_800E6B20.unk0 = 2;

        texRecAccess(D_8016B0C8[0x52])->unk24 = 0;

        D_800B6938++;
    }

    func_80081EEC();

    if(D_800B6930 == v1){
        if (1);
        if(!(D_8016B228[1] & 0x2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
            D_8016B228[1] |= 2;
            D_800B693C = D_800B6930 & 0xFFFF;

            texRecAccess(D_8016B0C8[0x53])->unk4 = (((u32)(D_800B6930 & 1) * 0x88 + 28));
            texRecAccess(D_8016B0C8[0x53])->unk6 = ((D_800B693C > 1) * 0x44 + 44 + 47);
            
            texRecAccess(D_8016B0C8[0x53])->unk8 = texRecAccess(D_8016B0C8[0x53])->unk0 + ((s32)((u32)(D_800B693C & 1) * 0x88 + 28));
            texRecAccess(D_8016B0C8[0x53])->unkA = texRecAccess(D_8016B0C8[0x53])->unk2 + ((D_800B693C > 1) * 0x44 + 44 + 47);

            texRecAccess(D_8016B0C8[0x53])->unk2A = 1;
            
            D_800B6934 = 0x20;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);
        }
        else if(!(D_8016B228[1] & 0x4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
            do{
                D_8016B228[1] |= 4; 
                texRecAccess(D_8016B0C8[0x52])->unk24 = 0x40;
                texRecAccess(D_8016B0C8[0x53])->unk2A = 0;
                texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
                texRecAccess(D_8016B0C8[0x1])->unk2A = 1;
                texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
                texRecAccess(D_8016B0C8[0xD])->unk2A = 1;
                texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
                texRecAccess(D_8016B0C8[0x19])->unk2A = 1;
                texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
                texRecAccess(D_8016B0C8[0x50])->unk2A = 1;
                D_800B6934 = 0;
            }while(0);
            
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);        

            D_800B6930 = 0;
        }
    }
}

void func_80086EEC(){
    u8 v1 = D_800B6930;
    s32 v0;
    
    if(D_800B6938 == 0){
        D_800E6B20.unk4 = D_801DB7E8;
        D_800E6B20.unk0 = 2;

        D_800B6938++;
    }

    func_80081EEC();

    if(D_800B6930 == v1){
        if(!(D_8016B228[1] & 0x2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
            D_8016B228[1] |= 2;
            if(D_800B6930 == D_800B693C){
                func_80008C6C(0xAE, 0);
                return;
            }
            else{
                texRecAccess(D_8016B0C8[0x54])->unk4 = (((u32)(D_800B6930 & 1) * 0x88 + 34));
                texRecAccess(D_8016B0C8[0x54])->unk6 = ((D_800B6930 > 1) * 0x44 + 44 + 49);
            
                texRecAccess(D_8016B0C8[0x54])->unk8 = texRecAccess(D_8016B0C8[0x54])->unk0 + ((s32)((u32)(D_800B6930 & 1) * 0x88 + 34));
                texRecAccess(D_8016B0C8[0x54])->unkA = texRecAccess(D_8016B0C8[0x54])->unk2 + ((D_800B6930 > 1) * 0x44 + 44 + 49);

                texRecAccess(D_8016B0C8[0x54])->unk2A = 1;
            
                D_800B6934 = 0x21;
                D_800B6938--;
            
                func_80008C6C(0xAD, 0);
            }
        }
        else if(!(D_8016B228[1] & 0x4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
            D_8016B228[1] |= 4;

            texRecAccess(D_8016B0C8[0x54])->unk2A = 0;
            texRecAccess(D_8016B0C8[0x52])->unk24 = 0x40;
            texRecAccess(D_8016B0C8[0x53])->unk2A = 0;
            
            texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x1])->unk2A = 1;
            texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
            texRecAccess(D_8016B0C8[0xD])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x19])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
            texRecAccess(D_8016B0C8[0x50])->unk2A = 1;
            
            D_800B6934 = 0;
            D_800B6938--;
            
            func_80008C6C(0xAD, 0);        

            D_800B6930 = 0;
        }
    }
}

void func_80087330(){
    if(D_800B6938 == 0){
        texRecAccess(D_8016B220[0x0])->unk4 = 128;
        texRecAccess(D_8016B220[0x0])->unk6 = 192;

        texRecAccess(D_8016B220[0x0])->unk8 = texRecAccess(D_8016B220[0x0])->unk0 + 128;
        texRecAccess(D_8016B220[0x0])->unkA = texRecAccess(D_8016B220[0x0])->unk2 + 192;

        texRecAccess(D_8016B220[0x1])->unk4 = 128 + 2;
        texRecAccess(D_8016B220[0x1])->unk6 = 192 + 2;

        texRecAccess(D_8016B220[0x1])->unk8 = texRecAccess(D_8016B220[0x1])->unk0 + 128 + 2;
        texRecAccess(D_8016B220[0x1])->unkA = texRecAccess(D_8016B220[0x1])->unk2 + 192 + 2;

        texRecAccess(D_8016B220[0x0])->unk2A = 1;
        texRecAccess(D_8016B220[0x1])->unk2A = 1;

        D_800E6B20.unk4 = D_801DB7EC;
        D_800E6B20.unk0 = 2;
        
        D_8016B23C = 1;
        D_8016B22E = 8;
        D_8016B230 = 0xC0;
        D_8016B234 = 0.0f;
        D_8016B238 = 0.25f;
        D_8016B22C = 8;
        
        D_800B6938++;
        
    }
    
    if(!(D_8016B228[1] & 2) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
        D_8016B228[1] |= 2;

        texRecAccess(D_8016B0C8[0x52])->unk24 = 0x40;

        texRecAccess(D_8016B220[0x0])->unk2A = 0;
        texRecAccess(D_8016B220[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x53])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x54])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xD])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x19])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x50])->unk2A = 1;

        D_800B6934 = 0x22;
        D_800B6938--;
            
        func_80008C6C(0xAD, 0);
    }
    else if(!(D_8016B228[1] & 4) && controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
        D_8016B228[1] |= 4;

        texRecAccess(D_8016B0C8[0x52])->unk24 = 0x40;

        texRecAccess(D_8016B220[0x0])->unk2A = 0;
        texRecAccess(D_8016B220[0x1])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x53])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x54])->unk2A = 0;
        texRecAccess(D_8016B0C8[0x2])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xE])->unk2A = 1;
        texRecAccess(D_8016B0C8[0xD])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x1A])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x19])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x51])->unk2A = 1;
        texRecAccess(D_8016B0C8[0x50])->unk2A = 1;

        D_800B6934 = 0;
        D_800B6938--;
            
        func_80008C6C(0xAD, 0);
        
        D_800B6930 = 0;
    }
    else{
        func_80011564(&D_8016B22C, &D_8016B22E, &D_8016B238, &D_8016B234, &D_8016B23C, (s16*)&D_8016B230);


        texRecAccess(D_8016B220[0x0])->unk4 = 128;
        texRecAccess(D_8016B220[0x0])->unk6 = D_8016B230;

        texRecAccess(D_8016B220[0x0])->unk8 = texRecAccess(D_8016B220[0x0])->unk0 + 128;
        texRecAccess(D_8016B220[0x0])->unkA = texRecAccess(D_8016B220[0x0])->unk2 + (u16)D_8016B230;

        texRecAccess(D_8016B220[0x1])->unk4 = 128 + 2;
        texRecAccess(D_8016B220[0x1])->unk6 = (u16)D_8016B230 + 2;

        texRecAccess(D_8016B220[0x1])->unk8 = texRecAccess(D_8016B220[0x1])->unk0 + 128 + 2;
        texRecAccess(D_8016B220[0x1])->unkA = texRecAccess(D_8016B220[0x1])->unk2 + (u16)D_8016B230 + 2;
    }
}

void func_80087BC8(){
    s32 i;

    if(D_800B6938 == 0){
        D_800B6938 = 1;

        for(i = 0; i < (s32)sizeof(SysGameData_unk0); i++) { sysGameData[D_800B6930].unk0.raw[i] = sysGameData[D_800B693C].unk0.raw[i]; }

        sysGameData[D_800B6930].characterNO = sysGameData[D_800B693C].characterNO;
        sysGameData[D_800B6930].unk12 = sysGameData[D_800B693C].unk12;
        sysGameData[D_800B6930].lives = sysGameData[D_800B693C].lives;
        sysGameData[D_800B6930].bells = sysGameData[D_800B693C].bells;
        sysGameData[D_800B6930].item = sysGameData[D_800B693C].item;

        sysGameData[D_800B6930].settings = sysGameData[D_800B693C].settings;
        sysGameData[D_800B6930].unk20 = sysGameData[D_800B693C].unk20;
        
        for(i = 0; i < 18; i++){
            sysGameData[D_800B6930].events[i] = sysGameData[D_800B693C].events[i];
        }

        *D_800EEFB0 = D_800B6930;
        func_80002BB8();
        return;
    }
    
    D_800B6938++;
    if(D_800B6938 >= 9){
        func_80002BF4();
        D_800B6934 = 0x23;
    }
}

void func_80087D4C(){
    if(D_800EEFB8.unk8 == 0){
        func_80002C50();
        func_800826FC(D_800B6930);

        D_800B6934 = 0;
        D_800B6930 = 0;
        D_800B6938 = 0;
    }
}

void func_80087DA4(){
    s32 i;
    
    if(D_800B6938 == 0){
        D_800F5FB0.unk1C[0] = 1;
        D_800F5FB0_sets(0x1E, 2, 1);
        D_800E6B20.unk0 = 0;

        D_800B6938++;
    }
    else if(D_800F5FB0.unk0 == 3){
        for(i = 0; i < D_8016B0C0; i++){
            func_80015258(&texRec, D_8016B0C8[i]);
        }

        func_80015258(&texRec, D_8016B220[0]);
        func_80015258(&texRec, D_8016B220[1]);

        D_800B6934 = 0x29;
        D_800AC040 = 0;

        cdata.settings = sysGameData[D_800B6930].settings;
        D_800B6938--;
    }
}

void func_80087EF4(){
    s32 v0 = func_80010208(D_800B6940);

    if(v0){
        sysGameData[D_800B6930].settings = cdata.settings;

        if(D_800B6940 == 3 && v0 == 2){
            func_80081C40();

            D_800E69C0.unk3C.uchar[0] = 0x46;
        }
        else{
            D_800E69C0.unk3C.uchar[0] = 0xA;
        }
    }
}

void func_80087F8C(){
    if(D_800B6938 == 0){
        D_800B6938 = 1;
        func_80002C70();
    }
    else if(++D_800B6938 >= 9){
        func_80002CAC();
        D_800B6934 = 0x33;
    }
}

void func_80087FF0(){
    if(D_800EEFB8.unk8 == 0){
        func_80002D08();

        D_800B6930 = 0;
        D_800B6938 = 0;
        D_800B6934 = 0x34;
        
        D_800E6B20.unk4 = D_801DB7F0;
        D_800E6B20.unk0 = 2;
    }
}

void func_8008805C(){
    if(controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
        D_800B6934 = 0;
    }
}

void zzFileSelectSub(s32 arg0){
    s32 i;
    
    switch(D_800E69C0.unk3C.uchar[0]){
        case 0:
            D_800F5FB0.unk1C[0] = 1;
            D_800F5FB0_sets(1,2,1);
            D_800E69C0.unk3C.uchar[0] = 1;
            break;
        case 1:
            if(D_800F5FB0.unk0 == 3){
                func_800073C0(9, 0);
                D_800E69C0.unk3C.uchar[0] = 10;
            }
            break;
        case 10:
            D_800B6930 = 0;
            D_800B6938 = 0;
            D_800B693C = 0;
            D_800B6934 = 0;
            D_800E6B20.unk19 = 0;
            D_8016B24C = 0;
            D_8016B228[0] = 0;
            D_8016B228[1] = 0;
            D_800E69C0.unk3C.uchar[0] = 4;
            break;
        case 4:
            func_80082730();
            D_800E69C0.unk3C.uchar[0] = 6;
            break;
        case 6:
            D_800F5FB0_sets(30,1,1);
            D_800E69C0.unk3C.uchar[0] = 7;
            break;
        case 7:
            if(D_800E6B20.unk0 == 0){
                D_800E69C0.unk3C.uchar[0] = 8;
            }
            break;
        case 8:
            func_80081E44();

            switch(D_800B6934){
                case 0x0:                                   
                    func_80083CF4();
                    break;
                case 0x1:                                   
                    func_80083F30();
                    break;
                case 0x2:                                   
                    func_80084490();
                    break;
                case 0x3:                                   
                    func_800846D4();
                    break;
                case 0x4:                                   
                    func_80084A54();
                    break;
                case 0x14:                                  
                    func_80084EEC();
                    break;
                case 0x15:                                  
                    func_800856C4();
                    break;
                case 0x16:                                  
                    func_80085964();
                    break;
                case 0x17:                                  
                    func_8008616C();
                    break;
                case 0x18:                                  
                    func_80086294();
                    break;
                case 0x1E:                                  
                    func_800862EC();
                    break;
                case 0x1F:                                  
                    func_80086AC4();
                    break;
                case 0x20:                                  
                    func_80086EEC();
                    break;
                case 0x21:                                  
                    func_80087330();
                    break;
                case 0x22:                                  
                    func_80087BC8();
                    break;
                case 0x23:                                  
                    func_80087D4C();
                    break;
                case 0x28:                                  
                    func_80087DA4();
                    break;
                case 0x29:                                  
                    func_80087EF4();
                    break;
                case 0x32:                                  
                    func_80087F8C();
                    break;
                case 0x33:                                  
                    func_80087FF0();
                    break;
                case 0x34:                                  
                    func_8008805C();
                    break;
        }
            break;
        case 70:
            func_80008C6C(0xAD, 0);
            D_800F5FB0_sets(30,2,1);
            D_800E69C0.unk3C.uchar[0] = 100;
            break;
        case 80:
            if(D_8016B24C != 0){
                if(D_800EEFB8.unk8){
                }
                else{
                    D_8016B24C = 0;
                    D_800E69C0.unk8 = D_8016B250;
                    D_800E6270.unk0 = 0;
                }
            }
            else if(controllers[0]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
                func_80008C6C(0xAD, 0);
                D_800F5FB0_sets(30,2,1);
                D_800E69C0.unk3C.uchar[0] = 100;
            }
            else if(controllers[1]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
                D_800B6954++;
                D_800B6954 %= 5;

                D_801BB3F0.unk14->unk14 = D_800B6958[D_800B6954];
                D_801BB3F0.unk38->unk14 = D_800B6958[D_800B6954];
            }
            else if(controllers[1]->unk0.buttonTimers[ZZ_TIMER_Z_TRIG] != 0 && controllers[1]->unk0.buttonTimers[ZZ_TIMER_L_TRIG] == 1){
                D_800E6B20.unk4 = D_801DB7E0;
                D_800E6B20.unk0 = 2;
                func_80002CAC();
                
                
                D_800E6B20.unk4 = D_801DB7E4;
                D_800E6B20.unk0 = 2;

                D_8016B24C = 1;
                
            }
            break;
        case 100:
            if(D_800F5FB0.unk0 == 0 || D_800F5FB0.unk0 == 3){
                for(i = 0; i < D_8016B0C0; i++){
                    func_80015258(&texRec, D_8016B0C8[i]);
                }

                func_80015258(&texRec, D_8016B220[0]);
                func_80015258(&texRec, D_8016B220[1]);

                func_80007648(0U);
                D_800E69C0.unk0 = 1;
                D_800E69C0.unk14 = 0x14;
                
                D_800E69C0.unk3C.uchar[0] = 12;
            }
            break;
        default:
        case 11:
            D_800E69C0.unk3C.uchar[0];
            break;
        case 12:
            break;
    }
}

void func_80088640(){
    s32 i;
    
    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
    func_80089130(0);

    D_8016B2B0 = 0;
    D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B2C[0]);
    D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B2C[1]);
    D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B2C[2]);
    D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B2C[3]);
    D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B2C[4]);

    for(i = 0; i < 0x17; i++){
        D_8016B2B8[D_8016B2B0++] = func_80015200(&texRec, D_801C6B44[i]);
    }

    func_80088844(0);
}

void func_800887C4(){
    s32 i;
    
    func_8008943C();

    for(i = 0; i < D_8016B2B0; i++){
        func_80015258(&texRec, D_8016B2B8[i]);
    }
}

void func_80088844(u8 arg0){
    static u8 D_800B6970 = 0;
    static u8 D_800B6974 = 0;
    s32 i;

    for(i = 0; i < 4; i++){
        if(arg0 == i && D_800B6970 & 0x20){
            texRecAccess(D_8016B2B8[i+0x15])->unk24 = 0;
        }
        else{
            texRecAccess(D_8016B2B8[i+0x15])->unk24 = 0x88;
        }
    }
    if(arg0 == 0 && D_800B6970 & 0x20){
        texRecAccess(D_8016B2B8[0x19])->unk24 = 0;
        texRecAccess(D_8016B2B8[0x1A])->unk24 = 0;
        texRecAccess(D_8016B2B8[0x1B])->unk24 = 0;
    }
    else{
        texRecAccess(D_8016B2B8[0x19])->unk24 = 0x88;
        texRecAccess(D_8016B2B8[0x1A])->unk24 = 0x88;
        texRecAccess(D_8016B2B8[0x1B])->unk24 = 0x88;
    }
    if(arg0 == D_800B6974){ D_800B6970++; } else{ D_800B6970 = 32; }

    D_800B6974 = arg0;
}
