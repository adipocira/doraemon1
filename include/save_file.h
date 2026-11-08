#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "ultra64.h"
#include "zzEvents.h"

typedef struct SysGameData_unk0{
    union{
        struct{
        u8* unk0;
        u8 addr;
        s32 count;
        u8 unkC[0x4];
    };
        u8 raw[0x10];
    };
}SysGameData_unk0;

typedef struct SysGameData{
    SysGameData_unk0 unk0;
    u8 characterNO;
    u16 unk12;
    u16 lives;
    u16 bells;
    u64 item;
    s32 raceBestTime;
    u8 settings;
    u16 events[ZZ_EVENT_MAX];
}SysGameData;

extern SysGameData sysGameData[4];

void func_80002BB8(void);
void func_80002BF4(void);
void func_80002C50(void);
void func_80002C70(void);
void func_80002CAC(void);
void func_80002D08(void);

#endif
