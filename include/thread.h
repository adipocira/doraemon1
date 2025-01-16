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

#define DORA_THREAD_SCHED_ID 4
#define DORA_THREAD_SCHED_PRIORITY 100

extern InternalThread main_thread;
extern u8 main_stack[0x1000];
extern InternalThread idle_thread;
extern u8 idle_stack[0x540];

#endif