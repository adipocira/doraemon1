#include "284C0.h"
#include "actor.h"
#include "global.h"
#include "11F10.h"
#include "13940.h"
#include "23B20.h"
#include "7FC0.h"
#include "9320.h"

#include "libc/math.h"

typedef struct D_8010B820_struct{
    u8 unk0[0xA4];
    s32 unkA4;
    s32 unkA8;
}D_8010B820_struct;

extern D_8010B820_struct* D_8010B820;

typedef struct D_800E6B20_struct {
    s16 unk0;
    s32 unk4;
    u8 unk8[0xE];
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B[0x5];
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26[0x3];
    u8 unk29;
    u8 unk2A[0x655D];
    u8 unk6587;
} D_800E6B20_struct;

extern D_800E6B20_struct D_800E6B20;

extern s16 D_800F3950;

void func_800278C0(u16 idx, Gfx** gfxPtr){
    D_8010B820_struct* ptr = (&D_8010B820)[idx];

    switch(ptr->unkA4){
        case 0:
            ptr->unkA8++;

            if(ptr->unkA8 >= 0x40){
                ptr->unkA8 = 0;
            }
            
            gDPSetTileSize(gfxPtr[0]++, 1, 0, ptr->unkA8<<1, 0x7C, 0x7C);
            
            break;
        case 1:
            ptr->unkA8--;

            if(ptr->unkA8 <= -0x40){
                ptr->unkA8 = 0;
            }
            
            gDPSetTileSize(gfxPtr[0]++, 1, 0, ptr->unkA8<<1, 0x7C, 0x7C);

            break;
        case 2:
            ptr->unkA8++;

            if(ptr->unkA8 >= 0x40){
                ptr->unkA8 = 0;
            }
        
            gDPSetTileSize(gfxPtr[0]++, 1, ptr->unkA8<<1, 0, 0x7C, 0x7C);
            
            break;
        case 3:
            ptr->unkA8--;

            if(ptr->unkA8 <= -0x40){
                ptr->unkA8 = 0;
            }
            
            gDPSetTileSize(gfxPtr[0]++, 1, ptr->unkA8<<1, 0, 0x7C, 0x7C);
            
            break;
    }
}

void func_80027A44(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    f32 z;

    if(actor->actorVars.varAC.integer == 0){
        actor->status = 0;
    }

    switch(actor->status){
        case 0:
            actor->actorVars.varAC.integer = 1;
            actor->actorVars.varA0.integer = 0;
            
            
            z = cosf(DEG2RAD_ALT2((actor->rot.y)));

            z = actor->actorVars.varA8.integer * z;
            
            actor->status = 1;

            actor->dir.z = z;
            actor->pos.z += z;
            
            break;
        case 1:
            actor->pos.z += actor->dir.z;

            if(actor->actorVars.varA4.integer <= actor->pos.z){
                actor->status = 2;
                actor->actorVars.varA0.integer = 1;
            }
            break;
        case 2:
            break;
    }
}

void func_80027B50(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s16 x;
    s16 y;
    s16 temp;
    s16 temp2;
    f32 z;
    
    switch(actor->status){
        case 0:
            actor->pos.z = actor->actorVars.varC0.integer;
            
            temp = (actor->actorVars.varA8.integer - actor->actorVars.varA0.integer) > 0 ?  (actor->actorVars.varA8.integer - actor->actorVars.varA0.integer) : (actor->actorVars.varA8.integer - actor->actorVars.varA0.integer) * -1;
            temp2 = (actor->actorVars.varA4.integer - actor->actorVars.varAC.integer) > 0 ?  (actor->actorVars.varA4.integer - actor->actorVars.varAC.integer) : (actor->actorVars.varA4.integer - actor->actorVars.varAC.integer) * -1;

            x = (func_80011528(0) % (u32)temp) + actor->actorVars.varA0.integer;
            y = actor->actorVars.varA4.integer - func_80011528(0) % (u32)temp2;

            if(actor->actorVars.varB0.integer < x && x < actor->actorVars.varB8.integer){
                if(func_80011528(0) & 1){
                    x = actor->actorVars.varA0.integer;
                }
                else{
                    x = actor->actorVars.varA8.integer;
                }
            }
            if(y < actor->actorVars.varB4.integer && actor->actorVars.varBC.integer < y){
                y = actor->actorVars.varA4.integer;
            }

            actor->pos.x = x;
            actor->pos.y = y;
            
            actor->actorVars.varD0.integer = func_80011528(0) % (u32)actor->actorVars.varCC.integer + 5;
            
            z = cosf(DEG2RAD_ALT2((actor->rot.y)));
            
            actor->dir.z = actor->actorVars.varC8.integer * z;
            
            actor->a = 127;
            actor->actorVars.varD8.fp = 127.0f;
            
            actor->actorVars.varDC.fp = (actor->actorVars.varC8.integer > 0 ? actor->actorVars.varC8.integer : -actor->actorVars.varC8.integer) * 0.254; 
            actor->status = 1;
            
            break;
        case 1:
            actor->actorVars.varD0.integer--;

            if(actor->actorVars.varD0.integer < 0){
                actor->status = 2;
            }
            break;
        case 2:
            actor->pos.z += actor->dir.z;

            if((actor->actorVars.varC4.integer - 0x1F4) < actor->pos.z){
                actor->actorVars.varD8.fp -= actor->actorVars.varDC.fp;

                if(actor->actorVars.varD8.fp >= 0.0){
                    actor->a = (s32)actor->actorVars.varD8.fp;
                }
            }

            if(actor->actorVars.varC4.integer <= actor->pos.z){
                actor->status = 0;
            }
            break;
    }
}

void func_80027E80(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);    
    s16 temp;
    f32 z;
    s32 temp2;
    
    switch(actor->status){
        case 0:
            actor->pos.y = actor->actorVars.varA8.integer;
            actor->pos.z = actor->actorVars.varAC.integer;
            
            temp = (actor->actorVars.varA0.integer - actor->actorVars.varA4.integer) > 0 ?  (actor->actorVars.varA0.integer - actor->actorVars.varA4.integer) : (actor->actorVars.varA0.integer - actor->actorVars.varA4.integer) * -1;
            
            actor->pos.x =  (s16)(func_80011528(0) % (u32)temp) + GET_ACTOR_PTR(idx)->actorVars.varA4.integer;
            actor->actorVars.varD0.integer = (func_80011528(0) % (u32)actor->actorVars.varB8.integer) + 5;
            
            z = cosf(DEG2RAD_ALT2(actor->rot.y));

            actor->dir.z = actor->actorVars.varDC.fp * z;

            actor->status = 1;
            
            break;
        case 1:
            actor->actorVars.varD0.integer--;

            if(actor->actorVars.varD0.integer < 0){
                actor->status = 2;
            }
            break;
        case 2:
            actor->pos.z += actor->dir.z;

            if(actor->actorVars.varB0.integer <= actor->pos.z){
                actor->status = 0;
            }
            break;
    }
}

void func_80028024(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);  
    
    switch((u32)actor->status){
        case 0:
            if((&D_800F3940)[cdata.unk41]->unk0[actor->actorVars.varA0.integer] == 1){
                if(actor->actorVars.varA8.integer & 1){
                    func_80007648(actor->actorVars.varAC.integer);
                }
                else if(actor->actorVars.varA8.integer & 0x10){
                    func_80007520(actor->actorVars.varB4.integer, actor->actorVars.varAC.integer);
                }

                if(actor->actorVars.varA8.integer & 0x4){
                    func_80007648(actor->actorVars.varC4.integer);
                }
                else if(actor->actorVars.varA8.integer & 0x40){
                    func_80007520(actor->actorVars.varB4.integer, actor->actorVars.varC4.integer);
                    
                }

                if(actor->actorVars.varA8.integer & 0x2){
                    func_800090B0(actor->actorVars.varB0.integer);
                }
                if(actor->actorVars.varA8.integer & 0x8){
                    func_800090B0(actor->actorVars.varC8.integer);
                }

                if(actor->actorVars.varA8.integer & 0x1000){
                    D_800F5FB0_sets(actor->actorVars.varB8.integer, 2, 1);
                }

                if(actor->actorVars.varA8.integer & 0x100){
                    D_800E6B20.unk0 = 0;
                }

                if(actor->actorVars.varA8.integer & 0x200){
                    func_80023FCC(actor->actorVars.varBC.integer);
                }

                actor->status = 0;
                actor->status += 10U;
            }
            break;
        case 10:
            if(D_800F5FB0.unk0 == 3){
                if(actor->actorVars.varA8.integer & 0x10){
                    func_800076E4(0x4E20, actor->actorVars.varAC.integer);
                }
                if(actor->actorVars.varA8.integer & 0x40){
                    func_800076E4(0x4E20, actor->actorVars.varC4.integer);
                }
                actor->status = 20;
            }
            break;
        case 20:
            (&D_800F3940)[cdata.unk41]->unk3C = 10;
            (&D_800F3940)[cdata.unk41]->unkB2 = 0;
            (&D_800F3940)[cdata.unk41]->unkA9 = 0;
            (&D_800F3940)[cdata.unk41]->unkA8 = 0;
            (&D_800F3940)[cdata.unk41]->unkA7 = 0;
            (&D_800F3940)[cdata.unk41]->unkA6 = 0;
            (&D_800F3940)[cdata.unk41]->unkA5 = 0;
            (&D_800F3940)[cdata.unk41]->unkA4 = 0;  
            
            D_800E6B20.unk0 = 0;
            
            D_800AC090 = 0;
            D_800E69C0.unk0 = 1;
            D_800E69C0.unk14 = 0x14;
            D_800E69C0.unkA = GET_ACTOR_PTR(idx)->actorVars.varA4.integer;
            
            if(actor->actorVars.varC0.integer != -1){
                D_800F3950 = actor->actorVars.varC0.integer;
            }

            func_80023FCC(idx);
            
            break;
    }
}

void func_80028320(s32 arg0, f32* arg1, f32 arg2, u8 arg3){
    if(!(arg0 < *arg1)){
        *arg1 += arg2;

        if(!(arg0 < *arg1)){
            func_80009088(((s32)(*arg1) & 7) << 0xC | 0xFFF, arg3);
        }
    }
}

void func_800283A4(f32* arg0, f32 arg1, u8 arg2){
    
    if(*arg0 > 7.0){
        *arg0 = 7.0;
    }

    if(!(*arg0 < 1.0)){
        *arg0 -= arg1;

        if(!(*arg0 < 1.0)){
            func_80009088(((s32)(*arg0)) << 0xC | 0xFFF, arg2);
        }
    }
}

void func_80028460(f32* arg0, f32 arg1){
    *arg0 += arg1;

    if(360.0 <= *arg0){
        *arg0 = 0.0f;
    }
}

void func_800284A4(f32 arg0, u8 arg1, u8 idx){
    f32 temp;
    D_800F3940_struct* var_v1 = (&D_800F3940)[idx];

    if((&D_800F3940)[idx]->unk34 != 0){
        temp = arg1 * arg0;
    }
    else{
        temp = arg0;
    }

    if((&D_800F3940)[idx]->unk3C != 0){
        D_800F0548.unk8 -= temp;
        D_800F0548.unk14 -= temp;        
    }
    else if((&D_800F3940)[idx]->unk38 != 0){
        D_800F0548.unk8 += temp;
        D_800F0548.unk14 += temp;           
    }
    else if((&D_800F3940)[idx]->unk2C != 0){
        D_800F0548.unk4 -= temp;
        D_800F0548.unk10 -= temp;   
    }
    else if((&D_800F3940)[idx]->unk28 != 0){
        D_800F0548.unk4 += temp;
        D_800F0548.unk10 += temp;          
    }
    else if((&D_800F3940)[idx]->unk24 != 0){
        D_800F0548.unk0 -= temp;
        D_800F0548.unkC -= temp;   
    }
    else if((&D_800F3940)[idx]->unk20 != 0){
        D_800F0548.unk0 += temp;
        D_800F0548.unkC += temp;          
    }
    else if((&D_800F3940)[idx]->unk8 != 0){
        D_800F0548.unk4 -= temp;          
    }
    else if((&D_800F3940)[idx]->unkC != 0){
        D_800F0548.unk4 += temp;          
    }
    else if((&D_800F3940)[idx]->unk4 != 0){
        D_800F0548.unk0 -= temp;
        if(360.0 <= D_800F0548.unk0){
            D_800F0548.unk0 = 0.0f;
        }

    }
    else if((&D_800F3940)[idx]->unk0[0] != 0){
        D_800F0548.unk0 += temp;
        if(360.0 <= D_800F0548.unk0){
            D_800F0548.unk0 = 0.0f;
        }

    }
    else {
        if((&D_800F3940)[idx]->unk30 != 0){
            D_800F0548.unk0 = D_800F0548.unk4 = 0.0f;
            D_800F0548.unk8 = 200.0f;
            D_800F0548.unk10 = D_800F0548.unk14 = 0.0f;
            D_800F0548.unkC = D_800F0548.unk10;  
        }
        do { } while (0);
    }
    if (!D_800F0548.unk10)
    {
    }
    if(var_v1);
}

#ifdef NON_MATCHING
void func_8002875C(f32 arg0, u8 arg1, f32* arg2, u8 idx){
    D_800F3940_struct* ptr = (&D_800F3940)[idx];
    f32 temp;

    if(ptr->unk34 != 0){
        temp = arg1 * arg0;
    }
    else{
        temp = arg0;
    }

    if(ptr->unk3C != 0){
        *arg2 += temp;

        if(360.0 <= *arg2){
            *arg2 = 0.0f;
        }
    }
    else if(ptr->unk38 != 0){
        *arg2 -= temp;

        if(360.0 <= *arg2){
            *arg2 = 0.0f;
        }        
    }
    else if(ptr->unk30 == 1){
        *arg2 = 0.0f;
    }
    
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/284C0/func_8002875C.s")
#endif

#ifdef NON_MATCHING
void func_80028874(f32 arg0, u8 arg1, f32* arg2, f32* arg3, f32* arg4, u8 idx){
    D_800F3940_struct* ptr = (&D_800F3940)[idx];
    f32 temp;

    if(ptr->unk34 != 0){
        temp = arg1 * arg0;
    }
    else{
        temp = arg0;
    }

    if(ptr->unk8 != 0){
        *arg2 += temp;

        if(360.0 <= *arg2){
            *arg2 = 0.0f;
        }
    }
    else if(ptr->unkC != 0){
        *arg2 += temp;

        if(360.0 <= *arg2){
            *arg2 = 0.0f;
        }
    }
    else if(ptr->unk4 != 0){
        *arg3 -= temp;

        if(360.0 <= *arg3){
            *arg3 = 0.0f;
        }
    }
    else if(ptr->unk0[0] != 0){
        *arg3 += temp;

        if(360.0 <= *arg3){
            *arg3 = 0.0f;
        }
    }    
    else if(ptr->unk10 != 0){
        *arg4 = 0.0f;
        *arg3 = 0.0f;
        *arg2 = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/284C0/func_80028874.s")
#endif

void func_80028A28(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    s32 pad[2];

    switch(actor->status){
        case 0:
            if(D_800F5FB0.unk0 == 3){
                actor->actorVars.varA0.integer = 1;
                actor->status = 1;
            }
            break;
        case 1:
            GET_ACTOR_PTR(idx)->actorVars.varA0.integer--;

            if(actor->actorVars.varA0.integer < 0){
                
                osViBlack(FALSE);
                D_800F5FB0_sets(0x3C, 1, 1);
                actor->status = 10;
                
            }
            
            break;
        case 10:
            func_80023FCC(idx);
            break;
    }
}

void func_80028AFC(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    static s16 D_80158AD0;
    static s16 D_80158AD2;
    static s16 D_80158AD4;
    static f32 D_80158AD8;
    static f32 D_80158ADC;
    static s8 D_80158AE0;
 
    switch(actor->status){
        case 0:
            D_80158AD0 = 0x10;
            D_80158AD2 = 0x10;
            D_80158AD8 = 0.25f;
            D_80158ADC = 0.0f;
            D_80158AE0 = 1;
            D_80158AD4 = 0x62;
            actor->status = 10;
            break;
        case 10:
            func_80011564(&D_80158AD0, &D_80158AD2, &D_80158AD8, &D_80158ADC, &D_80158AE0, &D_80158AD4);
            actor->pos.y += (f32)D_80158AD4;
            break;
    }
}

void func_80028C00(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);

    switch(actor->status){
        case 0:
            actor->rot.x = 0.0f;
            actor->flags |= 0x2000;
            actor->actorVars.varA0.integer = 0;
            actor->actorVars.varA4.integer = 0;
            actor->actorVars.varA8.fp = 10.0f;
            actor->actorVars.varBC.fp = 10.0f;
            actor->actorVars.varAC.fp = 80.0f;
            actor->actorVars.varB0.fp = 40.0f;
            actor->actorVars.varB8.fp = 70.0f;
            actor->actorVars.varB4.fp = 0.0f;
            actor->actorVars.varC0.fp = 1.0f;
            actor->actorVars.varC4.fp = 0.3f;
            actor->actorVars.varC8.fp = 0.1f;
            actor->actorVars.varCC.fp = 100.0f;
            actor->actorVars.varD0.fp = 50.0f;
            actor->status = 1;
            
            break;
        case 1:
            func_80021B90(idx);
             break;
    }
}


void func_80028CF8(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    volatile ActorVariable* ptr;
    

    switch(actor->status){
        case 0:
            ptr = &actor->actorVars.varA0;
            actor->pos.x = GET_ACTOR_PTR(ptr->integer)->pos.x;
            actor->pos.y = GET_ACTOR_PTR(ptr->integer)->pos.y;
            actor->pos.z = GET_ACTOR_PTR(ptr->integer)->pos.z;
            
            break;
        case 10:
            break;
    }
}
