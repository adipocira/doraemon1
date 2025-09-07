#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ultra64.h"
#include <PR/sched.h>

typedef struct InternalScheduler {
    OSSched sc;
    s32 unk288;
    volatile OSTime unk290;
    volatile OSTime unk298;
} InternalScheduler;


#endif
