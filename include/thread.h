#ifndef THREAD_H
#define THREAD_H

#include "ultra64.h"

typedef struct InternalThread {
    OSThread thread;
    s32 thread_id;
    s32 thread_priority;
    void* stackPtr;
} InternalThread;

#define DORA_THREAD_IDLE_ID 1
#define DORA_THREAD_IDLE_PRIORITY 0

#define DORA_THREAD_MAIN_ID 10
#define DORA_THREAD_MAIN_PRIORITY 10

#endif