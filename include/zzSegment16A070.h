#ifndef ZZ_SEGMENT_16A070_H
#define ZZ_SEGMENT_16A070_H

#include "ultra64.h"

typedef struct MotionData{
	s16 unk0;
	s16 unk2;
}ZZMotionData;

typedef struct MotionInfo{
	ZZMotionData* motionData;
	s16 unk4;
}ZZMotionInfo;

typedef struct D_803050E4_struct{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
}D_803050E4_struct;

extern D_803050E4_struct** D_803050E4[];

extern ZZMotionInfo* D_80305000[];

#endif
