#include "global.h"


#include "8A6C0.h"
#include "15040.h"
#include "TexRec.h"

u16 D_8016B470[4];
s16 D_8016B478;

extern u8 D_800F6010[];
extern u8 D_800F6170[];

extern D_801BABB0_struct* D_801EB188[];


void func_80089AC0(s32 arg0){
    s32 i;
    s32 idx;
    s32 cond; 
    u8 unk24;

    func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);

    switch(arg0){
        case 1:
            idx = 0;
            cond = 4;
            unk24 = 0xFF;
            break;
        case 2: 
            idx = 4;
            cond = 4;
            unk24 = 0xFF;
            break;
        case 3:
            idx = 8;
            cond = 2;
            unk24 = 0x88;
            break;
        default:
            if(unk24);
            break;
    }

    D_8016B478 = 0;
    
    for(i = 0; i < cond; i++, idx++){
        D_8016B470[i] = func_80015200(&texRec, D_801EB188[idx]);

        texRecAccess(D_8016B470[i])->unk24 = unk24; 
        texRecAccess(D_8016B470[i])->unk28 = 0x64; 
        texRecAccess(D_8016B470[i])->unk2A = 0; 
        
        if(arg0 == 3){
            *texRecAccess(D_8016B470[i])->unk14 = 0xD; 
            
        }

    }
}

void func_80089C90(){
    s32 i;

    for(i = 0; i < D_8016B478; i++){
        func_80015258(&texRec, D_8016B470[i]);
    }
}
