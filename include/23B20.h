#ifndef _23B20_H
#define _23B20_H

#include "ultra64.h"
#include "actor.h"

void func_80022F20(s16 idx, ActorUnk80Func arg1);
void func_80022F48(s16 idx, s16 arg1);
void func_80022F7C(s32* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80023468(s32* arg0);
s16 func_80023498(u16 arg0, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16 func_80023644(u16 arg0, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16 func_800238B0(s16 idx, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16 func_80023A58(s16 idx, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16 func_80023C04(s16 idx);
void func_80023FCC(s16 idx);
void func_800240CC(s16 idx);
void func_80024158(s16 idx, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_80024198(s16 idx, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_800242C0(s16 idx, s16 arg1);
void func_800242F0(s16 idx, u16 arg1, u16 arg2);
void func_80024348(s16 idx, u16 arg1);
void func_8002439C(s16 idx, u16 arg1);
void func_8002443C(s16 idx, u16 arg1, f32 x, f32 y, f32 z);
void func_800244C4(s16 idx, u16 arg1);
void func_8002454C(s16 idx, u16 arg1, u16 arg2, u16 arg3, f32 x, f32 y, f32 z);
void func_800246AC(s16 idx, u16 arg1, u16 arg2, u16 arg3);
void func_800247E8(s16 idx, u16 arg1, f32 arg2);
void func_80024874(s16 idx, f32 arg0);
void func_800248A4(s16 idx, f32 x, f32 y, f32 z);
s16 func_800248E0(s16 idx, s16 arg1);
s16 func_80024970(u16 idx, u16 arg1);
s16 func_800249E4(u16 idx, u16 arg1, s16 arg2, f32 dist);
s16 func_80024B50(u16 idx, s16 arg1, f32 dist);
s16 func_80024CA0(u16 idx, s16 arg1, f32 dist);
f32 func_80024E0C(s16 id1, s16 id2);
f32 func_80024EA4(s16 idx, f32 x, f32 y, f32 z);
void func_80024F20(s16 idx, f32 arg1);
void func_80024FC8(s16 idx, f32 arg1, f32 arg2);
void func_8002507C(s16 idx);
void func_800250CC(s16 idx);
void func_8002510C(s16 idx);
void func_8002513C(Actor* actor);
void func_8002524C(s16 idx, f32 arg1, f32 arg2, f32 arg3);
s32 func_80025288(s16 id1, s16 id2);
f32 func_80025374(s16 idx, f32 arg1, f32 arg2);
s16 func_800253B0(s16 id1, s16 id2);
void func_80025454(Actor* actor1, Actor* actor2, f32 arg1);
void func_800255AC(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3);
void func_80025638(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3, f32 arg4);
void func_800256CC(Actor* actor, f32 x, f32 z, f32 arg3);
void func_80025820(Actor* actor, f32 arg1, f32 arg2);
void func_8002592C(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3);
void func_800259B4(Actor* actor, f32 arg1, f32 arg2, f32 arg3);
void func_80025A44(Actor* actor1, Actor* actor2, f32 arg2, f32 arg3);
void func_80025AF4(Actor* actor);
void func_80025B90(Actor* actor, f32 arg1, f32 arg2, f32 arg3);
u16 func_80025C48(s32 arg0, s32 arg1);
void func_80025E14(f32* x, f32* y, f32* z);
void func_80025EB8();
void func_80025F18(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80025FE8(s16 id1, s16 id2, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
void func_80026380();
void func_80026410();
void func_8002646C(s16 id1, s16 id2, f32 arg2);
void func_8002675C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);
void func_80026878(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s32 arg9);
void func_800269EC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s32 arg9, s32 arg10, s32 arg11);
void func_80026B88(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12);
void func_80026D50(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15);
s32 func_80026F58(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80027014(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);


#endif
