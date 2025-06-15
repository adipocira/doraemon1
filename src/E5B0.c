#include "E5B0.h"

#include "global.h"

void func_8000D9B0() {
    D_800E69C0.unk8 = D_800E69C0.unkA;
    
    switch (D_800E69C0.unk8) {               
        case 0x63:
        case 0x6E:
        case 0x78:
        case 0x82:
        case 0x8C:
            func_8000E320();
            break;
        case 0x64:
            func_8000DF50();
            break;
        case 0x97:
        case 0x98:
        case 0x99:
        case 0xC8:
        case 0x1F4:
            func_8000DAD0();
            break;
        case 0x1F5:
            break;
        case 0x1F6:
            break;
        case 0x12C:
            func_8000E72C();
            break;
        case 0x3E7:
            func_8000E9E8();
            break;
        case 0x7D0:
            func_8000ED00();
            break;
    }
}
