#include "boot.h"
#include "idle.h"
#include "thread.h"
#include "3930.h"
#include "macros.h"

void bootproc(void* arg) {
    osInitialize();
    func_80002D30(NULL);
    osCreateThread(&idle_thread.thread, idle_thread.thread_id = DORA_THREAD_IDLE_ID, idle_entry, arg,
                   idle_thread.stackPtr = idle_stack + ARRAY_COUNTU(idle_stack), idle_thread.thread_priority = DORA_THREAD_IDLE_PRIORITY);
    osStartThread(&idle_thread.thread);
}
 