#include "idle.h"
#include "thread.h"

InternalThread main_thread;
u8 main_stack[800];

void main_entry(void*);

void idle_entry(void* arg){
    Idle_StartPI();
    osCreateThread(&main_thread.thread, main_thread.thread_id = DORA_THREAD_MAIN_ID, main_entry, NULL,
                   main_thread.stackPtr = main_stack - 0x800, main_thread.thread_priority = DORA_THREAD_MAIN_PRIORITY);
    osStartThread(&main_thread.thread);
    osSetThreadPri(NULL,DORA_THREAD_IDLE_PRIORITY);

    while(TRUE){
        
    };
}

void main_entry(void* arg){
    main_entry_sub();
}


void main_entry_sub(){

    D_800E69C0_struct* ptr = &D_800E69C0;

    ptr->unkA = 0x63;
    createScheduler(&sched, D_800E6268, DORA_THREAD_SCHED_PRIORITY ,D_800A82D0[3],1);
    D_800E6268 = osScGetCmdQ(&sched);
    func_800065B0();
    func_80007720();
    func_800090E4();

    if(func_80001C38(&D_800E3FA8,&D_800E3FC0, 1, &D_800F3970, &D_800E6270, &D_800E6468, 1, 1) == -1){
        ptr->unkA = 2000;
        ptr->unk8 = 2000;
    }

    osCreateThread(&controller_thread.thread, controller_thread.thread_id = DORA_THREAD_CONTROLLER_ID, func_800016D0, &D_800E6270,
               controller_thread.stackPtr = controller_stack - 800, controller_thread.thread_priority = DORA_THREAD_CONTROLLER_PRIORITY);
    osStartThread(&controller_thread);
    D_800CA210 = 0;

    if(D_800EEFB8.unk0 != 0){
        u16 old;
        s32 arg;
        D_800EEFB8.unk4 = 0;
        D_800EEFB8.unk1 = 1;
        D_800EEFB8.unk8 = 1;

        old = ptr->unk8;
        ptr->unk8 = 2000;
        arg = 1;
        osCreateThread(&D_800EDDF0_thread.thread, D_800EDDF0_thread.thread_id = 44, func_80002470, &arg,
               D_800EDDF0_thread.stackPtr = D_800EDDF0_stack - 800, D_800EDDF0_thread.thread_priority = 20);
        osStartThread(&D_800EDDF0_thread);

        while(D_800EEFB8.unk8 != 0);

        if(D_800EEFB8.unk4 != 0){
            D_800EEFB8.unk4 = 2000;
        }
        D_800EEFB8.unk8 = old;
        D_800E6270 = 0;
    }
    else{
        ptr->unkA = 2000;
    }

    if (ptr->unkA == 2000) {
        D_800F3958.unk50 = func_8000ACD0;
    } else {
        D_800F3958.unk50 = func_8000A980;
    }

    osCreateThread(&D_800DFA20_thread.thread, D_800DFA20_thread.thread_id = 20, func_80001EF0, &D_800E6270,
               D_800DFA20_thread.stackPtr = D_800DFA20_stack - 800, D_800DFA20_thread.thread_priority = 70);
    osStartThread(&D_800DFA20_thread);
}