#ifndef SEGMENTS_H
#define SEGMENTS_H

#include "ultra64.h"

#include "zzSegment16A070.h"

extern u8* D_800A82D8;
extern u8* D_800A82DC;
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

extern u8 D_126480[0x43BF0];
extern u8 D_16A070[0x2DF10];
extern u8 D_197F80[0x7CAB0];
extern u8 D_214A30[0x2500];
extern u8 D_2EF5C0[0x91B0];
extern u8 D_2F8770[0x7270];
extern u8 D_2FF9E0[0x2B50];
extern u8 D_302530[0xAFB0];
extern u8 D_30D4E0[0xD1B0];
extern u8 D_31A690[0xF710];

extern u8 D_354270[0x14090];
extern u8 D_368300[0x16EA0];
extern u8 D_37F1A0[0x12860];
extern u8 D_3A0350[0x12FA0];
extern u8 D_3B32F0[0xD260];
extern u8 D_3C0550[0xCF60];
extern u8 D_3CD4B0[0xC690];
extern u8 D_3FB080[0x7E0];
extern u8 D_3FB860[0x200];

extern u8 _bankSegmentRom[0x9970];
extern u8 _tableSegmentRom[0x1A6990];
extern u8 _bank2SegmentRom[0xBD90];
extern u8 _table2SegmentRom[];

extern u8 D_801CED20[];
extern u8 D_801D5B20[];
extern u8 D_801DB800[];
extern u8 D_801DD780[];
extern u8 D_801EB320[];
extern u8 D_801F5320[];
extern u8 D_801FCB20[];
extern u8 D_80224820[];
extern u8 D_8020C820[];
extern u8 D_802BD000[];
extern u8 D_80335000[];

#define D_16A070_VRAM ((u8*)D_80305000)

#define SEGMENT_SIZE(segment) ((u32)&segment[sizeof(segment)] - (u32)segment)

// Use this for ROMCOPY involving curSegmentSize
#define ROMCOPY(segment, vram) curSegmentSize = SEGMENT_SIZE(segment); \
            D_800A82D8 = (vram);\
            romCopy(segment, D_800A82D8, curSegmentSize)

#endif
