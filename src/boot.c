#include "boot.h"
#include "idle.h"
#include "thread.h"
#include "misc.h"
#include "macros.h"

void bootproc(void* arg) {
    osInitialize();
    parse_args(NULL);
    osCreateThread(&idle_thread.thread, idle_thread.thread_id = DORA_THREAD_IDLE_ID, idle_entry, arg,
                   idle_thread.stackPtr = idle_stack + 0x1000, idle_thread.thread_priority = DORA_THREAD_IDLE_PRIORITY);
    osStartThread(&idle_thread.thread);
}
// fix stack pointer later
