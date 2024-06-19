#include "boot.h"
#include "thread.h"
#include "idle.h"

InternalThread idle_thread;
u8 idle_stack[800]; // size to determine

void boot_proc(void* arg) {
    osInitialize();
    func_80002D30(NULL);
    osCreateThread(&idle_thread.thread, idle_thread.thread_id = DORA_THREAD_IDLE_ID, idle_entry, arg,
                   idle_thread.stackPtr = idle_stack, idle_thread.thread_priority = DORA_THREAD_IDLE_PRIORITY);
    osStartThread(&idle_thread.thread);
}
