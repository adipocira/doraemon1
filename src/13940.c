#include "global.h"

#include "11DF0.h"
#include "13940.h"
#include "segments.h"

typedef struct D_801BABB0_struct {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    u16 unkA;
    u8 unkC[0x8];
    u8** unk14;
    u8 unk18[0x10];
    u8 unk28;
    u8 unk29;
    u8 unk2A;
} D_801BABB0_struct;

typedef struct TexRec {
    u16 num;
    u16 amount;
    u32 unk4;
    s32* unk8;
    u8* unkC;
} TexRec;

typedef struct D_800F5F88_struct {
    u8 unk0;
    s32* unk4;
} D_800F5F88_struct;

typedef struct D_800F3940_struct {
    u8 unk0[0x3C];
    s32 unk3C;
    u8 unk40[0x64];
    u8 unkA4;
    u8 unkA5;
    u8 unkA6;
    u8 unkA7;
    u8 unkA8;
    u8 unkA9;
    u8 unkAA[0x8];
    u8 unkB2;
} D_800F3940_struct;

typedef struct D_800E6B20_struct {
    s16 unk0;
    s32 unk4;
    u8 unk8[0x12];
    u8 unk1A;
    u8 unk1B[0x5];
    u16 unk20;
    u16 unk22;
    u8 unk24[0x6563];
    u8 unk6587;
} D_800E6B20_struct;

typedef struct D_800F5F90_struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
} D_800F5F90_struct;

typedef struct D_800F3920_struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
} D_800F3920_struct;

typedef struct D_801591C0_struct {
    s16 unk0;
    u8 unk2[0x66];
} D_801591C0_struct;

typedef struct D_800E6A20_struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} D_800E6A20_struct;

extern D_801591C0_struct D_801591C0[1];

extern D_800E6A20_struct D_800E6A20[256];

extern TexRec texRec;

extern D_800F5F90_struct D_800F5F90;

extern D_800F3920_struct D_800F3920;

extern Cdata cdata;

extern D_800F3940_struct* D_800F3940;

extern D_801BABB0_struct D_801BABB0;
extern s32 D_801BB488;

extern D_800E6B20_struct D_800E6B20;

extern u8 D_800ED0A7;

extern u16 D_800F5F82;
extern u8 D_800F5F96[];

extern s32 D_800F5FA0;

extern u8 D_801D1A00[];
extern u8 D_801D1220[];

extern u8 D_800F5FA4[2];
extern u16 D_800F5FA6;

extern u16 D_800F5FA8[];

extern D_800F5F88_struct* D_801BA090[1];
extern D_800F5F88_struct* D_800F5F84;
extern D_800F5F88_struct* D_800F5F88;
extern s32* D_800F5F8C;

extern u8 D_800F6010[];
extern u8 D_800F6170[];

extern s32 D_800F5F9C;
extern s32 D_800F5F98;

extern u16 D_800F5F80;

u8 D_800AC090 = 0;

s32 func_80012D40(s32 arg0, s32 arg1, u8 arg2) {

    if (D_800AC090 == 0 && !(arg2 & 0xF0)) {
        if (func_80077548() == 0) {
            return 1;
        }
    }

    if (D_800AC090 == 0) {
        (&D_800F3940)[cdata.unk41]->unkB2 = 1;
        (&D_800F3940)[cdata.unk41]->unkA9 = 1;
        (&D_800F3940)[cdata.unk41]->unkA8 = 1;
        (&D_800F3940)[cdata.unk41]->unkA7 = 1;
        (&D_800F3940)[cdata.unk41]->unkA6 = 1;
        (&D_800F3940)[cdata.unk41]->unkA5 = 1;
        (&D_800F3940)[cdata.unk41]->unkA4 = 1;

        D_800F5FA6 = 0;

        if (D_800F5FA8[0] == 0) {
            D_800F5FA8[0] = 0x3C;
        }

        D_800E6B20.unk6587 |= 0x21;

        D_800F5F84 = D_801BA090[arg0];

        D_800F5F88 = &D_800F5F84[arg1];

        D_800F5F80 = D_800F5F88->unk0;
        D_800F5F8C = D_800F5F88->unk4;

        D_800E6B20.unk1A = cdata.unk6A;
        D_800F5F82 = 0;
        D_800F5F96[0] = 0;
        D_800F5FA4[0] = 0;
        D_800E69C0.unkD &= ~0x1;
        D_800F5F96[1] = D_800E69C0.unkE;
        (D_800F5F90.unk1 = 0);

        D_800E69C0.unkE |= 1;
        D_800F3920.unk1 |= 1;
        D_800F5F90.unk3 = 0;

        if (D_800F5F80) {}

        if (!(D_800E6B20.unk6587 & 0x10)) { \
            func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
        }

        D_800F5F9C = func_80015200(&texRec, &D_801BABB0.unk0);
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5F9C]])->unk28 = 0xC8;
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5F9C]])->unk2A = 0;

        D_800F5FA0 = func_80015200(&texRec, D_801BB488);
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk4 = 0x10;
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk6 = 0xB4;

        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk8 =
            ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk0 + 0x10;
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unkA =
            ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2 + 0xB4;

        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk28 = 0xA;
        ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2A = 0;

        if (arg2 & 0xF) {
            func_8000B120(2);
            D_800F3920.unk0 = 6;
            D_800F3920.unk2 = 0xA;
            D_800F5F96[0] = 1;
            D_800F5F98 = func_80013DDC(D_800E6A20, 0x10);

            D_800E6A20[D_800F5F98].unk1 = 2;D_800E6A20[D_800F5F98].unk2 = 1;D_800E6A20[D_800F5F98].unk8 = 60;D_800E6A20[D_800F5F98].unkC = 0;
        } else {
            if ((&D_800F3940)[cdata.unk41]->unk3C != 0) {
                D_800F5F90.unk0 = 0;
            } else {
                D_800F5F90.unk0 = 1;
            }
            D_800E6B20.unk4 = *D_800F5F8C;
            D_800E6B20.unk0 = 2;
        }
        D_800AC090 = 1;

    } else if (D_800F5F96[0] == 1) {

        if (D_800F3920.unk0 == 0) {
            D_800F5FA6++;

            if (D_800F5FA6 < D_800F5FA8[0]) {
                return D_800F5F82 + 1;
            } else {
                D_800E6A20[D_800F5F98].unk1 = 0;
                func_80013ECC(D_800E6A20, D_800F5F98);
                if ((&D_800F3940)[cdata.unk41]->unk3C != 0) {
                    D_800F5F90.unk0 = 0;
                } else {
                    D_800F5F90.unk0 = 1;
                }
                D_800F5F96[0] = 2;
                D_800E6B20.unk4 = *D_800F5F8C;
                D_800E6B20.unk0 = 2;
            }
        }

    } else {
        if (D_800F5F90.unk0 == 1) {
            if ((&D_800F3940)[cdata.unk41]->unk3C != 0) {
                D_800F5F90.unk1 = 1;
            }
        } else {
            if ((&D_800F3940)[cdata.unk41]->unk3C == 0) {
                D_800F5F90.unk0 = 1;
                D_800F5F90.unk1 = 0;
            }
        }
        if (D_800F5FA4[0] != 0) {

            if (D_800F3920.unk0 == 0) {
                D_800F5FA4[0] = 0;
                (&D_800F3940)[cdata.unk41]->unk3C = 0xA;
                (&D_800F3940)[cdata.unk41]->unkB2 = 0;
                (&D_800F3940)[cdata.unk41]->unkA9 = 0;
                (&D_800F3940)[cdata.unk41]->unkA8 = 0;
                (&D_800F3940)[cdata.unk41]->unkA7 = 0;
                (&D_800F3940)[cdata.unk41]->unkA6 = 0;
                (&D_800F3940)[cdata.unk41]->unkA5 = 0;
                (&D_800F3940)[cdata.unk41]->unkA4 = 0;
                D_800E6B20.unk6587 = 0;

                D_800E69C0.unkE = D_800F5F96[1];
                D_800E69C0.unkD |= 1;
                players[D_801591C0[cdata.unk41].unk0].unk8C &= ~0x4000;
                D_800AC090 = 0;
                D_800F3920.unk1 &= ~0x1;
                return 0;
            } else {
                return D_800F5F82 + 1;
            }
        }

        switch (D_800E6B20.unk0) {
            case 3:
                if (D_800F5F90.unk0 == 1 && D_800F5F90.unk1 == 1) {
                    D_800E6B20.unk1A = 1;
                    D_800F5F90.unk0 = 0;
                }

                return D_800F5F82 + 1;
                break;
            case 1:
                if (D_800F5F90.unk0 == 1 && D_800F5F90.unk1 == 1) {
                    D_800F5F82++;
                    if (D_800F5F82 == D_800F5F80) {
                        D_800E6B20.unk0 = 0;
                        if (D_800F5F96[0] == 2) {
                            D_800F5F96[0] = 0;
                            func_8000B120(2);
                            D_800F3920.unk0 = 5;
                            D_800F3920.unk2 = 0xA;
                            D_800F5FA4[0] = 1;
                            func_80015258(&texRec, D_800F5F9C);
                            func_80015258(&texRec, D_800F5FA0);
                            D_800E6B20.unk20 = 0x4B;
                            D_800E6B20.unk22 = 0xB7;
                            D_800F5FA8[0] = 0x3C;

                        } else {
                            D_800AC090 = 0;
                            (&D_800F3940)[cdata.unk41]->unk3C = 0xA;
                            func_80015258(&texRec, D_800F5F9C);
                            func_80015258(&texRec, D_800F5FA0);

                            D_800E6B20.unk6587 = 0;
                            D_800E69C0.unkE = D_800F5F96[1];
                            D_800E69C0.unkD |= 1;
                            D_800F3920.unk1 &= ~0x1;
                            D_800E6B20.unk20 = 0x4B;
                            D_800E6B20.unk22 = 0xB7;
                            players[D_801591C0[cdata.unk41].unk0].unk8C &= ~0x4000;
                            (&D_800F3940)[cdata.unk41]->unkB2 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA9 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA8 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA7 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA6 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA5 = 0;
                            (&D_800F3940)[cdata.unk41]->unkA4 = 0;

                            return 0;
                        }

                    } else {
                        D_800E6B20.unk1A = cdata.unk6A;
                        D_800F5F8C++;
                        D_800E6B20.unk4 = *D_800F5F8C;
                        D_800E6B20.unk0 = 2;

                        D_800F5F90.unk0 = 0;

                        return D_800F5F82 + 1;
                    }
                }
                break;
            case 4:
                break;
            case 0:
                D_800E6B20.unk0 = 0;
                D_800AC090 = 0;
                func_80015258(&texRec, D_800F5F9C);
                func_80015258(&texRec, D_800F5FA0);
                D_800E69C0.unkD |= 1;
                D_800E6B20.unk6587 = 0;
                D_800E69C0.unkE = D_800F5F96[1];
                D_800E6B20.unk20 = 0x4B;
                D_800E6B20.unk22 = 0xB7;
                players[D_801591C0[cdata.unk41].unk0].unk8C &= ~0x4000;
                (&D_800F3940)[cdata.unk41]->unkB2 = 0;
                (&D_800F3940)[cdata.unk41]->unkA9 = 0;
                (&D_800F3940)[cdata.unk41]->unkA8 = 0;
                (&D_800F3940)[cdata.unk41]->unkA7 = 0;
                (&D_800F3940)[cdata.unk41]->unkA6 = 0;
                (&D_800F3940)[cdata.unk41]->unkA5 = 0;
                (&D_800F3940)[cdata.unk41]->unkA4 = 0;

                return 0;
                break;
        }
    }

    return D_800F5F82 + 1;
}

void func_8001392C(u8 arg0) {
    static u8 D_800AC094 = 0;
    char* copySrc1;
    char* copySrc2;

    if (arg0 == 0) {
        D_801BABB0.unk2A = 0;
        if (D_800ED0A7 & 0x20) {
            ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2A = 0;
        }
    } else {
        D_801BABB0.unk2A = 1;

        if (D_800E6B20.unk6587 & 0x20) {
            ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2A = 1;
        }

        if (D_800AC094 == arg0) {
            D_801BABB0.unk2A = 1;

            if (D_800E6B20.unk6587 & 0x20) {
                ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2A = 1;
            }
        } else {
            D_800AC094 = arg0;

            if (arg0 >= 0xD2) {
                copySrc1 = (arg0 * 0x7E0) - 0x675C0 + (u32)&D_3F42E0_segment;
                copySrc2 = &D_3FAB40_segment;
            } else if (arg0 >= 0xA0) {
                copySrc1 = (arg0 * 0x7E0) - 0x4EC00 + (u32)&D_3F9980_segment;
                copySrc2 = &D_3FAF40_segment;
            } else if (arg0 >= 0x6E) {
                copySrc1 = (arg0 * 0x7E0) - 0x36240 + (u32)&D_3F5A80_segment;
                copySrc2 = &D_3FAD40_segment;
            } else {
                copySrc1 = (arg0 * 0x7E0) - 0x4EC0 + (u32)&D_3DF820_segment;
                copySrc2 = &D_3FA940_segment;
            }

            romCopy(copySrc1, D_801D1220, 0x7E0);
            romCopy(copySrc2, D_801D1A00, 0x200);

            if (&D_800E6B20)
                ;

            D_801BABB0.unk14 = &D_801D1A00;
            D_801BABB0.unk2A = 1;

            if (D_800ED0A7 & 0x20) {
                ((D_801BABB0_struct*)texRec.unk8[texRec.unkC[D_800F5FA0]])->unk2A = 1;
            }
        }
    }
}
