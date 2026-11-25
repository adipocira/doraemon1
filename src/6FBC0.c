#include "6FBC0.h"
#include "zzGameData.h"
#include "76BB0.h"
#include "controller.h"
#include "15040.h"
#include "11F10.h"
#include "TexRec.h"
#include "9320.h"
#include "7FC0.h"
#include "23B20.h"
#include "save_file.h"
#include "zzEvents.h"
#include "zzAudio.h"
#include "common.h"

extern u8 D_800EEFB0[];

extern s32* D_801E3E74[];

void func_8006EFC0(s16 idx){
	static s16 D_80159130;
	static s16 D_80159132;
	static s16 D_80159134;
	static f32 D_80159138;
	static f32 D_8015913C;
	static u8 D_80159140;
	
	Actor* actor = GET_ACTOR_PTR(idx);
	Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
	s16 idx2 = D_80159178->unk48[cdata.unk41].unk0;
	s32 i;

	(void)"cdata.item(x) = %llx\n";
	
	switch(GET_ACTOR_PTR(idx)->status){
		case 0:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_ANYWHERE_DOOR)){
				if((actor2->pos.x < 510.0 && actor2->pos.x > 490.0) && (actor2->pos.z < -405.0 && actor2->pos.z > -425.0) && func_80077548() != 0){
					D_800E69C0.syscalls &= ~0x1;
					GET_ACTOR_PTR(idx)->status = 1;
				}
			}
			break;
		case 1:
			actor->actorVars.varA0.integer = D_800F5FB0.unk1;

			D_800E6B20_setXY(103, 70);
		   
			D_800E6B20.unk24 = 0;D_800E6B20.unk25 = 0;D_800E6B20.unk29 = 1;
			D_800E6B20.unk19 = 0;
			
			D_800E6B20.unk4 = *D_801E3E74;
			D_800E6B20.unk0 = 2;
			
			func_800151B4(&texRec, D_800F6010, D_800F6170, 0x58);
			
			actor->actorVars.varA4.integer = func_80015200(&texRec, D_801BB3F0.unk0);
			actor->actorVars.varA8.integer = func_80015200(&texRec, D_801BB3F0.unk5C);
			actor->actorVars.varAC.integer = func_80015200(&texRec, D_801BB3F0.unk4);
			actor->actorVars.varB0.integer = func_80015200(&texRec, D_801BB3F0.unk8);
			actor->actorVars.varB4.integer = func_80015200(&texRec, D_801BB3F0.unkC);
			
			texRecAccess(actor->actorVars.varA4.integer)->posX = 128;
			texRecAccess(actor->actorVars.varA4.integer)->posY = 98;
			
			texRecAccess(actor->actorVars.varA4.integer)->unk8 = texRecAccess(actor->actorVars.varA4.integer)->width + 128;
			texRecAccess(actor->actorVars.varA4.integer)->unkA = texRecAccess(actor->actorVars.varA4.integer)->height + 98;
			
			texRecAccess(actor->actorVars.varA4.integer)->alpha = 255;
			texRecAccess(actor->actorVars.varA4.integer)->unk28 = 0x78;
			texRecAccess(actor->actorVars.varA4.integer)->unk2A = 0;
			
			texRecAccess(actor->actorVars.varA8.integer)->posX = 132;
			texRecAccess(actor->actorVars.varA8.integer)->posY = 102;
			
			texRecAccess(actor->actorVars.varA8.integer)->unk8 = texRecAccess(actor->actorVars.varA8.integer)->width + 132;
			texRecAccess(actor->actorVars.varA8.integer)->unkA = texRecAccess(actor->actorVars.varA8.integer)->height + 102;
			
			texRecAccess(actor->actorVars.varA8.integer)->alpha = 136;
			texRecAccess(actor->actorVars.varA8.integer)->unk28 = 0x6E;
			texRecAccess(actor->actorVars.varA8.integer)->unk2A = 0;
			
			
			*texRecAccess(actor->actorVars.varAC.integer)->pal = 0xD;
			texRecAccess(actor->actorVars.varAC.integer)->posX = 96;
			texRecAccess(actor->actorVars.varAC.integer)->posY = 64;
			
			texRecAccess(actor->actorVars.varAC.integer)->unk8 = texRecAccess(actor->actorVars.varAC.integer)->width + 96;
			texRecAccess(actor->actorVars.varAC.integer)->unkA = texRecAccess(actor->actorVars.varAC.integer)->height + 64;
			
			texRecAccess(actor->actorVars.varB0.integer)->posX = 96;
			texRecAccess(actor->actorVars.varB0.integer)->posY = 96;
			
			texRecAccess(actor->actorVars.varB0.integer)->unk8 = texRecAccess(actor->actorVars.varB0.integer)->width + 96;
			texRecAccess(actor->actorVars.varB0.integer)->unkA = texRecAccess(actor->actorVars.varB0.integer)->height + 96;
			
			texRecAccess(actor->actorVars.varB4.integer)->posX = 96;
			texRecAccess(actor->actorVars.varB4.integer)->posY = 128;
			
			texRecAccess(actor->actorVars.varB4.integer)->unk8 = texRecAccess(actor->actorVars.varB4.integer)->width + 96;
			texRecAccess(actor->actorVars.varB4.integer)->unkA = texRecAccess(actor->actorVars.varB4.integer)->height + 128;
			
			texRecAccess(actor->actorVars.varAC.integer)->alpha = 136;
			texRecAccess(actor->actorVars.varB0.integer)->alpha = 136;
			texRecAccess(actor->actorVars.varB4.integer)->alpha = 136;
			
			texRecAccess(actor->actorVars.varAC.integer)->unk28 = 0xA;
			texRecAccess(actor->actorVars.varB0.integer)->unk28 = 0xA;
			texRecAccess(actor->actorVars.varB4.integer)->unk28 = 0xA;
			
			texRecAccess(actor->actorVars.varAC.integer)->unk2A = 1;
			texRecAccess(actor->actorVars.varB0.integer)->unk2A = 1;
			texRecAccess(actor->actorVars.varB4.integer)->unk2A = 1;
			
			GET_ACTOR_PTR(idx)->status = 4;
			break;
		case 4:
			if(D_800E6B20.unk0 == 1){
				texRecAccess(actor->actorVars.varA4.integer)->unk2A = 1;
				texRecAccess(actor->actorVars.varA8.integer)->unk2A = 1;

				D_80159140 = 1;
				D_80159132 = 0x10;
				D_80159134 = 98;
				D_80159138 = 0.0f;
				D_8015913C = 0.25f;
				D_80159130 = 0x10;
				
				GET_ACTOR_PTR(idx)->status = 6;
			}
			break;
		case 6:
			if(controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
				zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_OPTION_SELECT, 0);
				
				sysGameData[D_800EEFB0[0]].characterNO = cdata.characterNO+1;
				sysGameData[D_800EEFB0[0]].unk12 = 0x19;
				
				if(cdata.lives < 2){
					sysGameData[D_800EEFB0[0]].lives = 2;
				}
				else{
					sysGameData[D_800EEFB0[0]].lives = cdata.lives;
				}

				sysGameData[D_800EEFB0[0]].bells = cdata.bells;
				sysGameData[D_800EEFB0[0]].item = cdata.item;
				sysGameData[D_800EEFB0[0]].settings = cdata.settings;
				sysGameData[D_800EEFB0[0]].raceBestTime = cdata.raceBestTime;

				for(i = 0; i < ZZ_EVENT_MAX; i++){
					sysGameData[D_800EEFB0[0]].events[i] = cdata.events[i];
		   		}
				
				func_80002BB8();
				actor->actorVars.varB8.integer = 8;

				GET_ACTOR_PTR(idx)->status = 7;
			}
			else if(controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
				zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_CURSOR_MOVE, 0);

				GET_ACTOR_PTR(idx)->status = 10;
			}
			else{
				func_80011564(&D_80159130, &D_80159132, &D_8015913C, &D_80159138, &D_80159140, &D_80159134);
				
				texRecAccess(actor->actorVars.varA4.integer)->posX = 128;
				texRecAccess(actor->actorVars.varA4.integer)->posY = D_80159134;
			
				texRecAccess(actor->actorVars.varA4.integer)->unk8 = texRecAccess(actor->actorVars.varA4.integer)->width + 128;
				texRecAccess(actor->actorVars.varA4.integer)->unkA = texRecAccess(actor->actorVars.varA4.integer)->height + D_80159134;
				
				texRecAccess(actor->actorVars.varA8.integer)->posX = 128 + 4;
				texRecAccess(actor->actorVars.varA8.integer)->posY = D_80159134 + 4;
			
				texRecAccess(actor->actorVars.varA8.integer)->unk8 = texRecAccess(actor->actorVars.varA8.integer)->width + 128 + 4;
				texRecAccess(actor->actorVars.varA8.integer)->unkA = texRecAccess(actor->actorVars.varA8.integer)->height + D_80159134 + 4;
			}
			break;
		case 7:
			actor->actorVars.varB8.integer--;
			
			if(actor->actorVars.varB8.integer < 0){
				func_80002BF4();
				GET_ACTOR_PTR(idx)->status = 8;
			}
			break;
		case 8:
			if(!D_800EEFB8.unk8){
				func_80002C50();
				GET_ACTOR_PTR(idx)->status = 10;
			}
			break;
		case 10:
			actor2->flags &= ~0x4000;
			
			D_800E6B20_setXY(75, 183);
			D_800E6B20.unk0 = 0;
			D_800E6B20.unk19 = cdata.tellerSpeedDelay;
		   
			D_800E6B20.unk24 = 0xB;D_800E6B20.unk25 = 4;D_800E6B20.unk29 = 5;
			
			func_80015258(&texRec, actor->actorVars.varA4.integer);
			func_80015258(&texRec, actor->actorVars.varA8.integer);
			func_80015258(&texRec, actor->actorVars.varAC.integer);
			func_80015258(&texRec, actor->actorVars.varB0.integer);
			func_80015258(&texRec, actor->actorVars.varB4.integer);
			
			controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] = 77;
			
			D_800E69C0.syscalls |= 0x1;
			
			GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0)->flags &= ~0x4000;
			
			GET_ACTOR_PTR(idx)->status = 52;
			break;
		case 52:
			if(func_80024E0C(idx, D_80159178->unk48[cdata.unk41].unk0) > 150.0f){
				GET_ACTOR_PTR(idx)->status = 0;
			}
			break;
	}
}
