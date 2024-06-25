#include "ultra64.h"
#include "PRInternal/piint.h"
#include "PR/os_internal_si.h"
#include "PR/os_internal_exceptions.h"
#include "PR/os_internal_regs.h"

typedef struct {
    /* 0x0 */ unsigned int inst1;
    /* 0x4 */ unsigned int inst2;
    /* 0x8 */ unsigned int inst3;
    /* 0xC */ unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble[];

extern s32 __osLeoInterrupt();

s32 __osFinalrom;
OSTime osClockRate = OS_CLOCK_RATE;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;
u32 osDDActive = 0;

void osInitialize(void){
    u32 pifdata;
    u32 clock = 0;     
    u32 leoStatus;
    u32 status;

    __osFinalrom = TRUE;
    __osSetSR(__osGetSR() | SR_CU1);
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV);

    while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata));
    while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8));

    *(__osExceptionVector *) UT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *) XUT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *) ECC_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *) E_VEC = *__osExceptionPreamble;

    osWritebackDCache((void *) UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void *) UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));

    osMapTLBRdb();
    __osPiRawReadIo(4, &clock);
    clock &= ~0xf;

    if (clock) {
        osClockRate = clock;
    }

    osClockRate = osClockRate * 3 / 4;

    if (osResetType == 0) {
        bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }

    WAIT_ON_IOBUSY(status);

    if (!((leoStatus = IO_READ(LEO_STATUS)) & LEO_STATUS_PRESENCE_MASK)) {
        osDDActive = 1;
        __osSetHWIntrRoutine(1, __osLeoInterrupt);
    } else {
        osDDActive = 0;
    }
}
 