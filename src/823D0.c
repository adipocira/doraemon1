#include "823D0.h"

#include "147B0.h"
#include "global.h"
#include "TexRec.h"

extern f32 D_8016B0B0;
extern f32 D_8016B0B4;
extern u8 D_801E202C;

extern u16 D_800B6910;

extern u32 D_8016B0B8;
extern u32 D_8016B0BC;

extern u8 D_801E2008[];
extern u8 D_801E2034[];

extern u32 D_800E6A2C[4];


void func_80008C6C(s32, s32);


void func_800817D0(s32 arg0){

    if(D_800E69C0.unk3E.uchar[1] < ++D_800E69C0.unk3D){
        if(D_800E69C0.unk3E.uchar[0] != 0){
            D_8016B0B0 = 255.0f; 
        }
        else{
            D_8016B0B0 = 0.0f;
        }

        D_800E69C0.unk3E.uchar[0] ^= 1;
        D_800E69C0.unk3D = 0; 
    }
    else{
        if(D_800E69C0.unk3E.uchar[0] != 0){
            D_8016B0B0 += D_8016B0B4;
        }
        else{
            D_8016B0B0 -= D_8016B0B4;
        }

        D_801E202C = D_8016B0B0;
    } 
} 

void func_8008191C(s32 arg0){

    switch(D_800E69C0.unk3C){
        case 0:
            if((&D_800F3940)[cdata.unk41]->unk30 == 1){
                func_80008C6C(0xAD,0);
                D_800E69C0.unk3C = 1;
                D_800F5FB0_sets(0x1E,2,1);
            }
            
            break;
        default:
             
            break;
        case 1:
            D_800B6910 = 0;
            D_800E69C0.unk3D = 0;
            D_800E69C0.unk3E.uchar[0] = 1;
            D_800E69C0.unk3E.uchar[1] = 0x3C;

            D_8016B0B4 = 255.0 / (f32)D_800E69C0.unk3E.uchar[1];
            D_8016B0B0 = 0.0f;
            func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
            D_8016B0B8 = func_80015200(&texRec, D_801E2008);
            D_8016B0BC = func_80015200(&texRec, D_801E2034);
            D_800E69C0.unk3C = 2;
            
            break;
        case 2:
            if(((&D_800F3940)[cdata.unk41]->unk30 == 1 && D_800E69C0.unk40 & 2) || (&D_800E6A2C)[D_800E69C0.unk41][0] > 0x37){
                if((&D_800F3940)[cdata.unk41]->unk30 == 1){
                    func_80008C6C(0xAD,0);
                }
                else{
                    D_800B6910 = 1; 
                }
                
                do{func_80013ECC(D_800E6A20, D_800E69C0.unk41);}while(0);

                
                D_800F5FB0.unk1C[0] = 1;
                if (D_800B6910 != 0) {
                    D_800F5FB0_sets(0xB4,2,1);
                    func_80007520(0x78, 0);
                } else {
                    D_800F5FB0_sets(0x3C,2,1);
                }
                D_800E69C0.unk3C = 3;
            }
            else{
                func_800817D0(0);
            }
            
            break;
        case 3:
            if (D_800F5FB0.unk0 == 3) {
                func_80015258(&texRec, D_8016B0B8);
                func_80015258(&texRec, D_8016B0BC);
                cdata.unk44 = cdata.unk44 | 8;
                D_800E69C0.unk3C = 4;
                
            }
            
            break;
        case 4:

            
            D_800E69C0.unk0 = 1;
            D_800E69C0.unk14 = 0x1E;
            if (D_800B6910 != 0) {
                D_800E69C0.unkA = 0x63;
                func_80007648(0);
            } else {
                D_800E69C0.unkA = 0x12C;
            }
            D_800E69C0.unk3C = 5;
            
            break;
        case 5:
            
            break;
    }
}
