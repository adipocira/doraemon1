#include "147B0.h"
#include "global.h"

void func_80013BB0(D_800E6A20_struct* arg, s32 arg1){
    s32 i;
    
    for(i = 0; i < arg1; i++){        
        if((arg + i)->unk0 == 0){
            switch((arg + i)->unk1){
                case 1:
                    (arg + i)->unk4++;

                    if(((arg + i)->unk4 / (arg + i)->unk8) != 0){
                        (arg + i)->unk4 = 0;
                        (arg + i)->unkC += (arg + i)->unk2;
                    }
                    break;
                case 2:
                    (arg + i)->unkC = 0;
                    (arg + i)->unk1 = 1; 
                    (arg + i)->unk4 = 1;

                    if((1U / (arg + i)->unk8) != 0){
                        (arg + i)->unk4 = 0;
                        (arg + i)->unkC += (arg + i)->unk2;
                        
                    }
                    break;
                case 3:
                    (arg + i)->unk1 = 1;
                    (arg + i)->unk4 = 1;

                    if((1U / (arg + i)->unk8) != 0){
                        (arg + i)->unk4 = 0;
                        (arg + i)->unkC += (arg + i)->unk2;
                        
                    }
                    break;
                case 0:
                    (arg + i)->unk4 = 0;
                    break;
            }
        }
    }
}

void func_80013CF0(D_800E6A20_struct* arg, s32 arg1){
    s32 i;
    
    for(i = 0; i < arg1;){
        (arg + i)->unk0 = 1;
        (arg + i)->unk1 = 0;
        (arg + i)->unk2 = 1;
        (arg + i)->unk4 = 0;
        (arg + i)->unk8 = 1;
        (arg + i)->unkC = 0;
        i++;
    }
}

s32 func_80013DDC(D_800E6A20_struct* arg, s32 arg1){
    s32 i;

    for(i = 0; i < arg1; i++){
        if((arg + i)->unk0 == 1){
            (arg + i)->unk0 = 0;
            return i;
        }
    }

    return 0;
}

void func_80013ECC(D_800E6A20_struct* arg, s32 arg1){
    s32 i;
    
    (arg + arg1)->unk0 = 1;
    (arg + arg1)->unk1 = 0;
    (arg + arg1)->unk2 = 1;
    (arg + arg1)->unk4 = 0;
    (arg + arg1)->unk8 = 1;
    (arg + arg1)->unkC = 0;
}
