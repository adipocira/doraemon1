#ifndef SEGMENTS_H
#define SEGMENTS_H

#include "ultra64.h"

extern u8* D_800A82D8;
extern s32 curSegmentSize;

extern u8 D_3FAB40_segment[];
extern u8 D_3FAF40_segment[];
extern u8 D_3FAD40_segment[];
extern u8 D_3FA940_segment[];

extern u8 D_3F42E0_segment[];
extern u8 D_3F9980_segment[];
extern u8 D_3F5A80_segment[];
extern u8 D_3DF820_segment[];

extern u8 D_354270[0x14090];
extern u8 D_8020C820[];

extern u8 D_3B32F0[0xD260];
extern u8 D_8020C820[];

// Use this for ROMCOPY involving curSegmentSize
#define ROMCOPY(segment, vram) curSegmentSize = (u32)&segment[sizeof(segment)] - (u32)segment; \
            D_800A82D8 = (vram);\
            romCopy(segment, D_800A82D8, curSegmentSize)

#endif
