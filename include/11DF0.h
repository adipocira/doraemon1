#ifndef _11DF0_H
#define _11DF0_H

#include "ultra64.h"

extern OSMesgQueue dmaMessageQ;

void romCopy(const char *src, const char *dest, const int len);
s32 func_80011264(const u32* src, const u32* dst, s32 len);
u8 func_800112DC(void);


#endif
