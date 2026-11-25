#include "70900.h"
#include "23B20.h"
#include "1D870.h"
#include "2DE50.h"
#include "9320.h"
#include "7FC0.h"
#include "controller.h"
#include "zzAudio.h"
#include "zzBGScreen.h"
#include "common.h"

extern s32 D_802BD61C[];

void func_8006FD00(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	D_803361C0_struct* s0 = &D_803361C0[cdata.characterNO];
	s16 id;
	D_802BDE5C_struct* s1;
	s32 pad;
	s16 i;
	u8 unk41;
	D_803361C0_struct_unk4* sp54 = &s0->unk4[D_802BD4A4[cdata.characterNO].unk0];
	
	s1 = D_802BDE5C;
	unk41 = cdata.unk41;
	
	(void)"GAME OVER .....\n";
	
	switch(GET_ACTOR_PTR(idx)->status){
		case 0:
			D_800F05B8 = 1;
			
			D_800F0548.unk0 = 0.0f;
			D_800F0548.unk4 = 0.0f;
			D_800F0548.unk14 = 0.0f;
			
			D_800F0548.unkC = D_800F0548.unk0;
	   		D_800F0548.unk10 = D_800F0548.unk4;
			D_800F0548.unk8 = 550.0f;
			
			func_80022528(4, 1, 0.0f, 0.0f, 0.0f, 255.0f, 255.0f, 255.0f);
			func_80022528(7, 1, 0.0f, 0.0f, 0.0f, 120.0f, 120.0f, 120.0f);
			
			D_80142BB8[4].unkC = 45.0f;
			D_80142BB8[4].unk10 = 45.0f;
			
			func_800226B0();
		
			D_800F5FB0.unk1C[0] = 1;
			D_800F5FB0_sets(1, 2, 1);
			
			GET_ACTOR_PTR(idx)->status = 1;
			break;
		case 1:
			if(D_800F5FB0.unk0 == 3){
				func_80089130(4);
				func_8000B120(3);
				
				if(1);
				
				D_800F3920.unk0 = 5;
				D_800F3920.unk2 = 1;
				
				id = func_80023498(0, cdata.characterNO, 32.0f, -35.0f, 380.0f, 0.0f, 0.0f, 0.0f);
				func_80022F20(id, NULL);
				
				GET_ACTOR_PTR(id)->unk44 = D_802BD61C[cdata.characterNO];
				
				(&D_801414A0[GET_ACTOR_PTR(id)->unk38])[s0->unk8]->unk48 = s0->unk0;
				(&D_801414A0[GET_ACTOR_PTR(id)->unk38])[s0->unk8]->unk4C = sp54;
				
				GET_ACTOR_PTR(id)->unk6C = (&D_802BD494[cdata.characterNO])->unkA;
				func_80074D74(GET_ACTOR_PTR(id), (&D_802BD494[cdata.characterNO])->unkE);
				 
				for(i = 0; i < 8; i++, s1++){
					id = func_80023644(1, (s16)s1->unk8, s1->x * 0.2, s1->y * 0.2 + 50.0, 0.0f, 0.0f, 0.0f, 0.0f);
					
					func_80022F20(id, func_80030ADC);
				}
				
				D_800F5FB0_sets(0xA, 1, 1);
				
				GET_ACTOR_PTR(idx)->status = 2;
			}
			break;
		case 2:
			if(!D_800F5FB0.unk0){
				zzAudioSeqSetVol(0x4E20, 0);
				zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_LEVEL_GAME_OVER, 0);
				
				GET_ACTOR_PTR(idx)->status = 50;
				actor->actorVars.varA0.integer = 240;
			}
			break;
		case 50:
			if(actor->actorVars.varA0.integer == 0){
				if(controllers[unk41]->unk0.buttonTimers[ZZ_TIMER_START_BUTTON]){
					D_800F5FB0_sets(0x3C, 2, 1);
					GET_ACTOR_PTR(idx)->status = 100;
				}
			}
			else{
				actor->actorVars.varA0.integer--;
			}
			break;
		case 100:
			if(D_800F5FB0.unk0 == 3){
				D_800E69C0.unk0 = 1;
				D_800E69C0.unk14 = 0x14;
				
				cdata.unk42 = 0;
				
				D_800E69C0.unkA = 0x64;
				
				func_8002263C(4);
				func_8002263C(7);
				func_8002267C();
				
				GET_ACTOR_PTR(idx)->status = 200;
			}
			break;
		case 200:
			break;
	}
}
