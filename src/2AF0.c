#include "2AF0.h"
#include "7FC0.h"
#include "9320.h"
#include "7310.h"
#include "save_file.h"
#include "common.h"
#include "scheduler.h"

extern OSMesgQueue D_800E3FA8;
extern s16 D_800EDDB0;
extern OSMesgQueue D_800EDDD0;

void func_80001EF0(D_800F3958_struct* arg0){
    s16* msg = NULL;
    s32 mask;
    D_800F3958_struct* var_s6;
    s32 s4;
    u32 s2;
    D_800F3958_struct* var_s0;

    var_s0 = arg0;
    var_s6 = arg0;
    
    s4 = 0;
    arg0->unk50(arg0);
    osScAddClient(&sc, &var_s0->client, &var_s0->mq);

    while(TRUE){
        var_s0->unk68(var_s0);
        mask = osSetIntMask(OS_IM_NONE);

        while(var_s6->mq.validCount != 0){
            osRecvMesg(&var_s0->mq, NULL, OS_MESG_BLOCK);
        }
        
        
        osSetIntMask(mask);
    
        D_800E69C0.unk1D[0] = var_s0->unk3;
        D_800E69C0.unk1D[1] = 0;
        D_800E69C0.unk1D[2] = 0;
        s2 = 0;

        while(var_s6->unk0 != 0){
            osRecvMesg(&var_s0->mq, &msg, OS_MESG_BLOCK);

            switch(*msg){
                case 1:
                    zzAudioSeqProc();
                    func_80009240();

                    if(s4 == D_800E69C0.unk10){
                        break;
                    }
                    while(!D_800E69C0.unk1C);

                    s4 = D_800E69C0.unk10;
                    D_800E69C0.unk1C = 0;

                    var_s0->unk7 = 1;
                    D_800E69C0.unk4 = var_s0->unk7;

                    if(D_800E69C0.unk0 != 0){
                        D_800E69C0.syscalls &= ~0x10;
                        func_80007648(0);
                        func_800090B0(0);

                        s2++;
                    
                        if(D_800E69C0.unk14 +8 < s2 && func_80006924() == 0){
                            var_s0->unk0 = 0;
                            break;
                        }
                    }
                    if(D_800E69C0.syscalls & 1){
                        if(var_s0->unk54 != NULL){
                            if(D_800E69C0.unk0 == 0){
                                var_s0->unk54(var_s0);
                            }
                            else if(s2 < D_800E69C0.unk14){
                                var_s0->unk54(var_s0);
                            }
                        }
                    }
                    if(var_s0->unk7 == 1 && D_800E69C0.syscalls & 0x10){
                        if(var_s0->unk58 != NULL){
                            var_s0->unk58(var_s0);
                        }
                    }

                    var_s0->unk7 = 2;
                    D_800E69C0.unk4 = var_s0->unk7;

                    if(D_800E69C0.syscalls & 0x20 && var_s0->unk5 == 1 && var_s0->unk2 < 2){
                        var_s0->unk5C(var_s0);
                    }
                    if(D_800E69C0.syscalls & 0x40 && var_s0->unk5 == 1 && var_s0->unk2 < 2){
                        D_800E69C0.unk1D[var_s0->unk3] = 1;
                        var_s0->unk60(var_s0);
                        var_s0->unk7 = 0;
                        var_s0->unk2++;
                        var_s0->unk3 ^= 1;
                        D_800E69C0.unk1D[0] = var_s0->unk3;
                    }
                    
                    break;
                case 2:
                case 3:
                    var_s0->unk2--;
                    D_800E69C0.unk1D[var_s0->unk3 ^ 1] = 0;
                    break;
                case 5:
                    var_s0->unk2 += 2;
                    break;
            }
        }
        
        var_s0->unk64(var_s0);
    }
}

void func_80002280(){
    osSetEventMesg(OS_EVENT_SI, &D_800EDDD0, (OSMesg)1);
}

void func_800022AC(){
    osSetEventMesg(OS_EVENT_SI, &D_800E3FA8, (OSMesg)&D_800EDDB0);
}

void func_800022DC(SysGameData* gameData){
    s32 i;
    s32 j;
    s32 k;
    u8* v0 = gameData->unk0.unk0;
    u8 buf[EEPROM_BLOCK_SIZE*64];
    s32 v1;
    s32 sp230[1];
    s32 sp130[64];
    s32 sp12C[1];
    s32 sp2C[64];

    sp230[0] = 0;
    
    for(i = 0; i < gameData->unk0.count; i++){
        v1 = 0;
        
        for(j = 0; j < 8; j++, v0++){
            v1 += v0[0];
        }

        sp130[i] = v1;
        sp230[0] += v1;
    }

    if(osEepromLongRead(&D_800EDDD0, gameData->unk0.addr, buf, gameData->unk0.count*EEPROM_BLOCK_SIZE) != 0){
        D_800EEFB8.unk4 = -2;
    }
    else{
        sp12C[0] = 0;
        v0 = buf;
        
        for(i = 0; i < gameData->unk0.count; i++){
            v1 = 0;
            
            for(j = 0; j < 8; j++, v0++){
                v1 += v0[0];
            }

            sp2C[i] = v1;
            sp12C[0] += v1;
        }       

        for(i = 0; i < gameData->unk0.count; i++){
            if(sp2C[i] != sp130[i]){
                D_800EEFB8.unk4 = -2;
                return;
            }
        }

        D_800EEFB8.unk4 = 0;
    }
}
