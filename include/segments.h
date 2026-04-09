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

extern u8 D_7AC690[4];
extern u8 D_354270[0x14090];
extern u8 D_368300[0x16EA0];
extern u8 D_37F1A0[0x12860];
extern u8 D_3A0350[0x12FA0];
extern u8 D_3B32F0[0xD260];

extern u8 _bankSegmentRom[0x9970];
extern u8 _tableSegmentRom[0x1A6990];
extern u8 _bank2SegmentRom[0xBD90];
extern u8 _table2SegmentRom[];


extern u8 D_8020C820[];

#define SEGMENT_SIZE(segment) ((u32)&segment[sizeof(segment)] - (u32)segment)

// Use this for ROMCOPY involving curSegmentSize
#define ROMCOPY(segment, vram) curSegmentSize = SEGMENT_SIZE(segment); \
            D_800A82D8 = (vram);\
            romCopy(segment, D_800A82D8, curSegmentSize)

#endif
