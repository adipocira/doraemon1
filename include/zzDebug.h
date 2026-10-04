#ifndef ZZ_DEBUG_H
#define ZZ_DEBUG_H

#include "ultra64.h"

#define DEBUG_FLAG(x) (1 << (x))

typedef enum DebugFlags{
	ZZ_DEBUG_FLAG_GODMODE = 0,
	ZZ_DEBUG_FLAG_INFO = 1,
	ZZ_DEBUG_FLAG_2 = 2,
	ZZ_DEBUG_FLAG_MG = 3,
	ZZ_DEBUG_FLAG_SOUND = 4,
	ZZ_DEBUG_FLAG_5 = 5,
	ZZ_DEBUG_FLAG_6 = 6,
}ZZDebugModes;

#endif
