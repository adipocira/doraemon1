#include "E020.h"
#include "23B20.h"
#include "73660.h"
#include "78DE0.h"
#include "zzGame.h"

#include "common.h"

extern s32 D_801DB890[];
extern s32 D_801E12B0[];
extern s32 D_801E2880[];
extern s32 D_801E6A30[];
extern s32 D_801D5E40[];
extern s32 D_801E1AB0[]; 
extern s32 D_801E7210[];
extern s32 D_801E4100[];
extern s32 D_801E9680[];
extern s32 D_801DEF10[];
extern s32 D_801DF630[];
extern s32 D_801DA7D0[];
extern s32 D_801E7150[];
extern s32 D_801E3B60[];
extern s32 D_801E1290[];
extern s32 D_801DD5A0[];
extern s32 D_801D5B20[];
extern s32 D_801DD5A0[];
extern s32 D_801DD5A0[];

extern u16 D_8015A392;
extern u16 D_800F3952;

extern s32 D_800ABF70[];

void func_8000D420(u32* stagePtr){
    //TODO
    /*
    static s32 D_800ABF70[] = {
        D_801DB890, D_801E12B0, D_801E2880, D_801E6A30, D_801D5E40, D_801E1AB0, D_801E7210,
        D_801E4100, D_801E9680, D_801DEF10, D_801DF630, D_801DA7D0, D_801E7150, D_801E3B60,
        D_801E1290, D_801DD5A0, D_801D5B20, D_801DD5A0, D_801DD5A0,
    };
    */

    Actor* actor;
    u32 stage = *stagePtr;
    s16 id;

    D_8015A392 &= ~0x8;
    cdata.unk6B = 1;

    if(D_800F3952 == 1){
        D_80159178->unk48[cdata.unk41].unk0 = func_800238B0(0, cdata.unk1C, D_801B58F8[stage].unk1C, D_801B58F8[stage].unk20, D_801B58F8[stage].unk24,0.0f, D_801B58F8[stage].unk28,0.0f);
        cdata.unk6D = 1;
    }
    else if((stage == ZZ_GAME0_LEVEL_INTRO_TOKYO || stage == ZZ_GAME0_LEVEL_DEBUG || stage == ZZ_GAME0_LEVEL_OVERWORLD_GROUND) && (D_800E69C0.unk8 >= 0x97 && D_800E69C0.unk8 < 0x9A) || D_800E69C0.unk8 == 0xC8){
        D_800E69C0.unkF &= ~0x2;
    }
    else{
        D_80159178->unk48[cdata.unk41].unk0 = func_800238B0(0, cdata.unk1C, D_801B58F8[stage].unkC, D_801B58F8[stage].unk10, D_801B58F8[stage].unk14, 0.0f, D_801B58F8[stage].unk18,0.0f);
    }
    if(D_800E69C0.unk8 == 0x99){  
        func_80023644(8, 0x1D2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    }
    else{
        func_80023468(D_800ABF70[stage]);

        if(stage == ZZ_GAME0_LEVEL_OVERWORLD_GROUND){
            if(func_80076FA0(0x20)){
                func_80023644(1, 0x20, 500.0f, 272.0f, -500.0f, 0.0f, 0.0f, 0.0f);
            }
        }
    }
    switch(stage){
        case ZZ_GAME0_LEVEL_DEVIL:
            break;
        case ZZ_GAME0_LEVEL_1_1:
            break;
        case ZZ_GAME0_LEVEL_1_2:
            break;
        case ZZ_GAME0_LEVEL_1_3:
            break;
        case ZZ_GAME0_LEVEL_1_4:
            break;
        case ZZ_GAME0_LEVEL_2_1:
            break;
        case ZZ_GAME0_LEVEL_2_2:
            id = func_80023644(2, 0x1C2, 6005.0f, 50.0f, 4965.0f,0.0f,0.0f,0.0f);
            func_80022F20(id, func_800796A0);
            actor = GET_ACTOR_PTR(id);
            
            actor->unk8 |= 0x100;
        case ZZ_GAME0_LEVEL_2_3:
            break;
        case ZZ_GAME0_LEVEL_2_4:
            break;
        case ZZ_GAME0_LEVEL_3_1: 
            break;
        case ZZ_GAME0_LEVEL_3_2:
            break;
        case ZZ_GAME0_LEVEL_3_3:
            break;
        case ZZ_GAME0_LEVEL_3_4:
            break;
        case ZZ_GAME0_LEVEL_OVERWORLD_GROUND:
            cdata.unk20 = 0xFA;
            cdata.unk6B = 0;
            
            if(D_800E69C0.unk8 != 0x97 && D_800E69C0.unk8 != 0x98 && D_800E69C0.unk8 != 0x99 && D_800E69C0.unk8 != 0xC8 && !(cdata.item & 0x100000000000)){
                func_80023644(6, 0x15F, D_801B58F8[stage].unkC, D_801B58F8[stage].unk10, D_801B58F8[stage].unk14,0.0f, D_801B58F8[stage].unk18,0.0f);
            }
            break;
        case ZZ_GAME0_LEVEL_OVERWORLD_AIR:
            if(D_800E69C0.unk8 != 0x97 && D_800E69C0.unk8 != 0x98){
                func_80023644(6, 0x15F, D_801B58F8[stage].unkC, D_801B58F8[stage].unk10, D_801B58F8[stage].unk14,0.0f, D_801B58F8[stage].unk18,0.0f);
            }
            
            cdata.unk20 = 0xFA;
            cdata.unk6B = 0;
            break;
        case ZZ_GAME0_LEVEL_INTRO_TOKYO:
            break;
        case ZZ_GAME0_LEVEL_DEBUG:
            break;
        default:
            break;
    }

    GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->unk74 = cdata.unk20;
}
