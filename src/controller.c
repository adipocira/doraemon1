#include "controller.h"
#include "scheduler.h"

extern OSScClient D_800E69B8;
extern s16 D_800EDDB0;
extern volatile u8 D_800EEFB8;

void func_800016D0(D_800E6270_struct* arg0){
    s32 v0;
    s8 x;
    s8 y;
    s16 oldX;
    s16 oldY;
    u16 btn;
    D_800E6468_struct* a1;
    u8 sp7F;
    D_800E6270_struct* sp78;
    s32 i;
    s16* m = 0;
    OSContPad pads[4];
    s32 k;

    sp78 = arg0;
    sp7F = TRUE;

    osScAddClient(&sc.sc, &D_800E69B8, sp78->msgQueue);
    
    while(sp7F){
        osRecvMesg(sp78->msgQueue, &m, OS_MESG_BLOCK);

        switch(*m){
            case 9:
                osContGetReadData(pads); 

                for(i = 0; i < sp78->unk4; i++){
                    v0 = sp78->unk5[i];
                    
                    y = 0;
                    x = 0;
                    btn = 0;

                    a1 = &sp78->unk1C4[v0];
                        
                    if(pads[v0].errnum != 0){
                        a1->unkFC = 1;
                    }
                    else{
                        btn = pads[v0].button;
                        a1->unk48.unkA2 = btn & (a1->unk48.unkA0 ^ btn);
                        a1->unk48.unkA0 = btn;
                        
                        x = pads[v0].stick_x;
                        y = pads[v0].stick_y;
                        
                        a1->unkFC = 0;
                    }

                    for(k = 0; k < 16; k++){
                        if(btn & (1 << k) && !a1->unk48.unkA4[a1->unk48.unk80[k]] && a1->unkFC == 0){
                            a1->unk48.unk0[a1->unk48.unk80[k]]++;
                        }
                        else{
                            a1->unk48.unk40[a1->unk48.unk80[k]] = a1->unk48.unk0[a1->unk48.unk80[k]];  
                            a1->unk48.unk0[a1->unk48.unk80[k]] = 0;
                        }
                    }

                    a1->unk102 = a1->unkFE;
                    a1->unk104 = a1->unk100;
                    
                    a1->unkFE = x;
                    a1->unk100 = y;


                    if(a1->unkFE > -50 && a1->unkFE < 50){
                        a1->unk108 = 0; 
                    }
                    else if(a1->unkFE >= 50){
                        if(a1->unk102 <= -50){
                            a1->unk108 = 1;
                        }
                        else{
                            a1->unk108++;
                        }
                    }
                    else if(a1->unk102 >= 50){
                        a1->unk108 = -1;
                    }
                    else{
                        a1->unk108--;
                    }

                    if(a1->unk100 > -50 && a1->unk100 < 50){
                        a1->unk10C = 0;
                    }
                    else if(a1->unk100 >= 50){
                        if(a1->unk104 <= -50){
                            a1->unk10C = 1;
                        }
                        else{
                            a1->unk10C++;
                        }
                    }
                    else if(a1->unk104 >= 50){
                        a1->unk10C = -1;
                    }
                    else{
                        a1->unk10C--;
                    }
                }

                for(i = 0; i < 4; i++){
                    D_800F3940[i] = &D_800E6270.unk1C4[D_800E6270.unk5[i]].unk48;
                }

                sp78->unk0 = 0;
                sp78->unk1F0 = 1;
                D_800E69C0.unk1C = 1;
                break;
            case 1:
                if(D_800E69C0.unk8 == 0x7D0){
                    for(i = 0; i < 4; i++){
                        D_800F3940[i] = &D_800E6270.unk1C4[D_800E6270.unk5[i]].unk48;
                    }
                    
                    sp78->unk0 = 0;
                    sp78->unk1F0 = 1;
                    D_800E69C0.unk1C = 1;
                }
                else if(sp78->unk4 != 0 && sp78->unk0 == 0){
                    sp78->unk0 = 1;
                    func_80001BF8(sp78->msgQueue);
                }
                break;
            case 11:
                sp7F = FALSE;
                break;
        }
    }
}

void func_80001BF8(OSMesgQueue* queue){
    osContStartReadData(queue);
}

void func_80001C18(OSMesgQueue* queue, D_800E6270_struct* arg1){
    osContReset(queue, arg1->status);
}

s32 func_80001C38(OSMesgQueue* queue, OSMesg* msg, s32 count, void* arg3, D_800E6270_struct* arg4, D_800E6468_struct* arg5, u8 arg6, u8 arg7){
    s32 i;
    s32 j;
    s32 k;
    D_800E6468_struct* temp;
    u8 pattern;
    s32 pad;
    
    D_800EDDB0 = 9;
    
    osCreateMesgQueue(queue, msg, count);
    osSetEventMesg(OS_EVENT_SI, queue, &D_800EDDB0);
    
    osContInit(queue, &pattern, arg4->status);

    if(osEepromProbe(queue) != 0){
        D_800EEFB8 = TRUE;
    }
    else{
        D_800EEFB8 = FALSE;
    }
    
    arg5[4].unkFC = 1;
    arg5[4].unk48.unkA0 = 0;
    arg5[4].unkFE = 0;
    arg5[4].unk100 = 0;
    arg5[4].unk102 = 0;
    arg5[4].unk104 = 0;
    
    arg4->unk4 = 0;
    
    for(k = 0; k < MAXCONTROLLERS; k++) arg4->unk5[k] = 4;
    for(k = 0; k < MAXCONTROLLERS; k++) arg4->unk1B[k] = 0;

    for(i = 0, temp = arg5; i < MAXCONTROLLERS; i++, temp++){
        if((pattern & (1 << i)) && !(arg4->status[i].errnum & CONT_NO_RESPONSE_ERROR)){
            arg4->unk5[arg4->unk4++] = i;
            temp->unkFC = 0;

            arg4->unk1F[i] = osPfsInit(queue, &arg4->pfs[i], i);
            
            if(arg4->unk1F[i] == 0){
                arg4->unk1A = 1;
                arg4->unk1B[i] = 1;
            }
            else if(arg4->unk1F[i] != PFS_ERR_ID_FATAL && arg4->unk1F[i] == PFS_ERR_DEVICE){
            }
        }
        else{
            temp->unkFC = 1;
        }

        for(j = 0; j < 16; j++){
            temp->unk48.unk0[j] = 0;
            temp->unk48.unk80[j] = j;
            temp->unk48.unk40[j] = 0;
            temp->unk48.unkA4[j] = 0;
        }

        
        temp->unk48.unkA0 = 0;
        temp->unk48.unkA2 = 0;
        temp->unkFE = 0;
        temp->unk100 = 0;
        temp->unk102 = 0;
        temp->unk104 = 0;
    }
    
    arg4->unk1C4 = arg5;
    arg4->msgQueue = queue;
    arg4->unk1CC = arg3;
    arg4->unk0 = 0;
    arg4->unk1F4 = arg6;
    arg4->unk1F5 = arg7-1;
    arg4->unk1F0 = 0;
    arg4->unk1D0 = 0xA;

    if(arg4->unk4 == 0){
        return -1;
    }

    return 0;
}
