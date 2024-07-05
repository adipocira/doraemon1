#include "PR/os_internal_regs.h"
#include "PRInternal/osint.h"
#include "macros.h"
#include "ultra64.h"

__OSEventState __osEventStateTab[OS_NUM_EVENTS] ALIGNED(8);

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg) {
  register u32 saveMask;
  __OSEventState *es;

  saveMask = __osDisableInt();

  es = &__osEventStateTab[event];

  es->messageQueue = mq;
  es->message = msg;

  __osRestoreInt(saveMask);
}
