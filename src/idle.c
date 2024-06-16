#include "idle.h"
#include "thread.h"

InternalThread main_thread;
u8 main_stack[800];

void main_entry(void*);

void idle_entry(void* arg){
    Idle_StartPI();
    osCreateThread(&main_thread.thread, main_thread.thread_id = DORA_THREAD_MAIN_ID, main_entry, NULL,
                   main_thread.stackPtr = main_stack, main_thread.thread_priority = DORA_THREAD_MAIN_PRIORITY);
    osStartThread(&main_thread.thread);
    osSetThreadPri(NULL,DORA_THREAD_IDLE_PRIORITY);

    while(TRUE){
        
    };
}

void main_entry(void* arg){
    main_entry_sub();
}


void main_entry_sub(){

}