#include "thread.h"

InternalThread idle_thread;
u8 pad[0x1000];
InternalThread main_thread;
u8 main_stack[0x1000];
InternalThread controller_thread;
u8 controller_stack[0x1000];
u8 D_800DFA20[0x3C80];
u8 idle_stack[0x540]; 
