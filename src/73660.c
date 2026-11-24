#include "73660.h"
#include "global.h"
#include "zzDebug.h"
#include "controller.h"
#include "386E0.h"
#include "75AE0.h"
#include "76BB0.h"
#include "78DE0.h"
#include "7B6C0.h"
#include "7FC0.h"
#include "7310.h"
#include "9320.h"
#include "B4E0.h"
#include "2DE50.h"
#include "23B20.h"
#include "zzGame.h"
#include "zzAudio.h"
#include "zzGameData.h"
#include "common.h"
#include "scheduler.h"
#include "libc/math.h"
#include "zzSegment16A070.h"

extern u8 D_800F0630;
extern u8 D_80159319;

extern u16 D_80141CAA;
extern u16 D_8015A392;
extern u16 D_802BDE40;
extern u16 D_802BDE4A;

extern f32 D_800F05B4;
extern f32 D_80159170;
extern f32 D_80159174;

extern u8 D_802BD870[];

extern u16 D_802BD234[];
extern u16 D_802BD67A[];
extern u16 D_802BD69E[];
extern u16 D_802BD6B0[];
extern u16 D_802BD6F8[];

extern s8 D_80142AB0[];

void func_80072A60(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);

	if(D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_2)){
		cdata.lives = 0;
		actor->health = 1;
		D_8015A392 &= ~DEBUG_FLAG(ZZ_DEBUG_FLAG_2);
	}
	
	func_80073B80(controllers[(s16)actor->actorVars.varC4.integer], D_80159178->unk48[(s16)actor->actorVars.varC4.integer].unk4);

	actor->unk6E = D_80159178->unk48[(s16)actor->actorVars.varC4.integer].unk4[0].maxValue * 2 +80;

	func_80073F28(idx);
	func_8007E370(actor);
	func_80074594(idx);
	func_800762B0(actor);
	func_80073E80(idx);
	func_80072EC0(actor);
	func_80077164(actor, idx);
	func_80073174(actor);

	if(D_8015A392 & DEBUG_FLAG(ZZ_DEBUG_FLAG_GODMODE)){
		if(controllers[(s16)actor->actorVars.varC4.integer]->unk0.buttonTimers[ZZ_TIMER_L_JPAD] == 1){
			func_800770FC();
		}
		if(controllers[(s16)actor->actorVars.varC4.integer]->unk0.buttonTimers[ZZ_TIMER_R_JPAD] == 1){
			actor->actorVars.varB8.shorts[0] = 11;
			actor->actorVars.varC8.uchars[3] = 3;
			actor->actorVars.varB8.uchars[2] = 0;
			actor->actorVars.varB8.uchars[3] = 0;
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 3;
		}
		if(controllers[(s16)actor->actorVars.varC4.integer]->unk0.buttonTimers[ZZ_TIMER_U_JPAD] == 1){
			actor->unk52 = 0;
			actor->unk6A = 0x10;
			actor->unk50 = actor->unk52;
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 2;
		}
		if(controllers[(s16)actor->actorVars.varC4.integer]->unk0.buttonTimers[ZZ_TIMER_D_JPAD] == 1){
			actor->unk52 = 0;
			actor->unk6A = 0x11;
			actor->actorVars.varB8.shorts[0] = 11;
			actor->actorVars.varC8.uchars[3] = 1;
			actor->actorVars.varB8.uchars[2] = 0;
			actor->actorVars.varB8.uchars[3] = 0;
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 3;
			actor->unk50 = actor->unk52;
		}
	}
	switch(actor->actorVars.varB8.shorts[0]){
		case 0:
		case 1:
		case 2:
		case 3:
		case 5:
			func_8007D310(actor);
			func_8007DB14(actor);
			func_80074EE0(actor, idx);
			break;
		case 4:
		case 8:
			func_80075BD8(actor, idx);
			func_80073B78(actor);
			break;
		case 20:
			func_8007DB14(actor);
			break;
		case 6:
			func_8007DB14(actor);
			func_80074EE0(actor, idx);
			break;
		case 9:
			func_8007D310(actor);
			func_8007DB14(actor);
			break;
		case 10:
			func_8007DB14(actor);
			break;
		case 11:
			func_80073440(actor);
			break;
		case 15:
			func_800738F4(actor);
			break;
		case 7:
			func_8007DB14(actor);
			func_80075BD8(actor, idx);
			func_80073B78(actor);
			break;
		case 12:
		case 13:
			func_8007DFF4(actor);
			func_8007E0C8(actor);
			func_80074FF8(actor, idx);
			break;
		case 21:
			func_8007E0C8(actor);
			break;
		case 14:
			func_80075E0C(actor, idx);
			break;
		case 16:
			func_8007DD6C(actor);
			func_8007DE64(actor);
			func_800750EC(actor, idx);
			break;
		case 18:
			func_80075D0C(actor, idx);
			break;
		case 22:
			func_8007DE64(actor);
			break;
	}
	
	func_80073094(actor);
	func_8007D434(actor);
	func_80072FB0(actor);

	if(D_80159319 != 0){
		D_80159319--;
	}

	cdata.unk10 = actor->pos.x;
	cdata.unk14 = actor->pos.y + (80.0f * actor->scale.y);
	cdata.unk18 = actor->pos.z;

	actor->dir.x = actor->actorVars.varAC.fp;
	actor->dir.z = actor->actorVars.varB4.fp;

	actor->actorVars.varB4.fp = 0.0f;
	actor->actorVars.varAC.fp = 0.0f;
	actor->actorVars.varB0.fp = 0.0f;
}

void func_80072EC0(Actor* actor){
	if(cdata.unk6E != 0){
		cdata.unk6E--;

		if(!cdata.unk6E){
			zzAudioSeqPlaySeq(cdata.unk74, 0);
		}
	}
	if(cdata.unk70){
		cdata.unk70--;

		if(!cdata.unk70){
			func_80038FA8();
		}
		else{
			D_80141CAA = 1;

			cdata.unk76--;

			if(cdata.unk76 < 0){
				if(cdata.unk70 >= 0xB5){
					cdata.unk76 = 20;
				}
				else{
					cdata.unk76 = 10;
				}

				cdata.unk77 ^= 1;

				if(cdata.unk77){
					zzAudioSoundPlaySound(0x9C, 0);
				}
				else{
					zzAudioSoundPlaySound(0x9D, 0);
				}
			}
		}
	}
}

void func_80072FB0(Actor* actor){
	switch(actor->actorVars.varB8.shorts[0]){
		case 0:
		case 1:
		case 2:
			if(cdata.nextstg == ZZ_GAME0_LEVEL_3_2){
				cdata.unk6C = 3;
			}
			else if(actor->actorVars.varC4.shorts[0] == 0){
				cdata.unk6C = 0;
			}
			else{
				cdata.unk6C = 3;
			}
			break;
		case 12:
			cdata.unk6C = 3;
			break;
		case 16:
			cdata.unk6C = 3;
			break;
		default:
			cdata.unk6C = 0;
			break;
	}
	if((cdata.nextstg == ZZ_GAME0_LEVEL_1_2 || cdata.nextstg == ZZ_GAME0_LEVEL_2_2 || cdata.nextstg == ZZ_GAME0_LEVEL_3_2) && cdata.unk6C == 3){
		cdata.unk6C = 2;	
	}
}

void func_80073094(Actor* actor){
	s16 id;
	
	if(!(sc.sc.unk284 & 7)){
		if(actor->pos.y - 16.0f < D_80159174 && D_80159174 < actor->pos.y + 16.0f){
			id = func_80023644(6, ZZ_ACTORS_WATER, actor->pos.x, D_80159174 + 16.0f, actor->pos.z, 0.0f, 0.0f, 0.0f);

			if(id >= 0){
				GET_ACTOR_PTR(id)->scale.x = 0.25f;
				GET_ACTOR_PTR(id)->scale.y = 0.25f;
				GET_ACTOR_PTR(id)->scale.z = 0.25f;

				func_80022F20(id, func_8002FCE8);
			}
		}
	}
}
void func_80073174(Actor* actor){
	D_801591C0_struct_unk4* v0 = D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4;
	s16 t0 = actor->unk6A;
	s16 a1 = actor->actorVars.varB8.shorts[0];
	s16 id;
	
	if(a1 == 2 || a1 == 1 || a1 == 0 || a1 == 3){
		if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_Z_TRIG] && actor->actorVars.varC4.shorts[0] == 1 && actor->unk48 != 6){
			if(v0->unk14 == 1){
				actor->unk6A = 4;
			}
			else{
				actor->unk6A = 3;
			}
		}
		else if(v0->unk14 == 1){
			if(v0->maxValue > 40){
				actor->actorVars.varB8.shorts[0] = 2;
				actor->unk6A = 2;
			}
			else{
				actor->actorVars.varB8.shorts[0] = 1;
				actor->unk6A = 1;
			}
		}
		else{
			actor->actorVars.varB8.shorts[0] = 0;
			actor->unk6A = 0;
		}
		if(t0 != actor->unk6A){
			actor->unk52 = 0;
			actor->unk50 = actor->unk52;
		}
	}
	if(a1 != 0xB && a1 != 0xF){
		if(actor->actorVars.varC8.shorts[0] == 1){
			if(D_80159174 <= actor->pos.y){
				actor->dir.y = 0.0f;

				if(actor->actorVars.varC4.shorts[0] == 1){
					actor->unk52 = 0;
					
					actor->actorVars.varB8.shorts[0] = 0;
					actor->actorVars.varC4.shorts[0] = 0;
					
					actor->unk6A = 0;
					actor->unk50 = actor->unk52;
					
					actor->actorVars.varA4.fp = D_80159170;
					actor->actorVars.varC8.shorts[0] = 0;
				}
				else{
					actor->actorVars.varB0.fp -= actor->pos.y - (D_80159174 - 0.001);
				}
			}
		}
		else if(actor->pos.y < D_80159174){
			actor->unk52 = 0;
			
			actor->actorVars.varB8.shorts[0] = 0xC;
			
			actor->unk6A = 0xD;
			actor->unk50 = actor->unk52;

			zzAudioSoundPlaySound(D_802BDE4A, 0);
			actor->dir.y = 0.0f;
			actor->actorVars.varA4.fp = D_80159170;
			
			actor->actorVars.varC8.shorts[0] = 1;

			if(D_80159319 == 0){
				id = func_80023498(6, ZZ_ACTORS_WATER_2, actor->pos.x, D_80159174 + 16.0f - 4.0f, actor->pos.z, 0.0f, 0.0f, 0.0f) +1 != 0;

				if(id){
					GET_ACTOR_PTR(id)->a = 180;
				}

				D_80159319 = 0x1E;
			}
		}
	}
}

void func_80073440(Actor* actor){
	if(actor->actorVars.varC8.uchars[3] != 0){
		if(actor->actorVars.varB8.uchars[2] == 30U && D_800F3920.unk0 == 0){
			if(cdata.lives != 0){
				cdata.lives--;
				
				D_800E69C0.unk0 = 1;
				D_800E69C0.syscalls = 0x60;
				
				cdata.unk42 = 1;
				D_800E69C0.unk3C.uchar[0] = 1;
			}
			else{
				D_800E69C0.unk0 = 1;
				D_800E69C0.syscalls = 0x60;
				D_800E69C0.unk14 = 0x1E;
				D_800E69C0.unkA = 0x3E7;
			}
		}
		if(actor->actorVars.varB8.uchars[2] == 10){
			actor->actorVars.varB8.uchars[3]--;
			
			if(!actor->actorVars.varB8.uchars[3]){
				zzAudioSoundPlaySound(D_802BD69E[actor->unk48], 1);
				actor->actorVars.varB8.uchars[2] = 20;
				actor->actorVars.varB8.uchars[3] = D_802BD250[actor->unk48].unk1;
			}
		}
		switch (actor->actorVars.varC8.uchars[3]) {
			case 3:
				switch(actor->actorVars.varB8.uchars[2]){
					case 0:
						if(actor->actorVars.varC4.shorts[0] == 1){
							actor->unk52 = 0;
							actor->unk6A = 0xB;
						
							actor->unk50 = actor->unk52;
									
							actor->actorVars.varB8.uchars[2] = 10;
							actor->actorVars.varB8.uchars[3] = D_802BD250[actor->unk48].unk0;
						
							D_800F0588.unk1B = 1;
							D_800F0588.unk1D = 0;
							D_800F0630 = 0xB;
						}
						else{
							if(actor->dir.y >= -40.0f){
								actor->dir.y -= actor->actorVars.varA4.fp;
							}
						
							actor->actorVars.varB0.fp += actor->dir.y * actor->scale.y;
						}
						break;
					case 20:
						actor->actorVars.varB8.uchars[3]--;
					
						if(!actor->actorVars.varB8.uchars[3]){
							zzAudioSeqSetVol(0x4E20, 0);
							zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_LEVEL_DEATH, 0);
						
							D_800F0630 = 7;
							func_8000B120(3);
						
							D_800F3920.unk2 = 0x64;
							D_800F3920.unk0 = 6;
						
							actor->actorVars.varB8.uchars[2] = 30;
						}
						break;
				}
			break;
			case 1:
 				switch(actor->actorVars.varB8.uchars[2]){
					case 0:
						actor->unk52 = 0;
						actor->unk6A = 0x11;
								
						actor->unk50 = actor->unk52;
											
						actor->actorVars.varB8.uchars[2] = 10;
						actor->actorVars.varB8.uchars[3] = D_802BD250[actor->unk48].unk0;
								
						D_800F0588.unk1B = 1;
						D_800F0588.unk1D = 0;
						D_800F0630 = 0xB;
						break;
					case 20:
						actor->actorVars.varB8.uchars[3]--;
						
						if(!actor->actorVars.varB8.uchars[3]){
							zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_LEVEL_DEATH, 0);
							D_800F0630 = 7;
						
							func_8000B120(3);
								
							D_800F3920.unk2 = 0x78;
							D_800F3920.unk0 = 6;
								
							actor->actorVars.varB8.uchars[2] = 30;
						}
						break;
				}	
				if(actor->actorVars.varA4.fp < 6.0){
					actor->actorVars.varA4.fp += 0.02f;
				}
			
				actor->actorVars.varB0.fp += (actor->dir.y - actor->actorVars.varA4.fp) * actor->scale.y;
				actor->dir.y *= 0.98;
				break;
			case 2:
				switch(actor->actorVars.varB8.uchars[2]){
					case 0:
						D_800F0588.unk1B = 1;
						D_800F0588.unk1D = 0;
						D_800F0630 = 9;	
					
						zzAudioSoundPlaySound(D_802BD6F8[actor->unk48], 1);
						actor->actorVars.varB8.uchars[2] = 20;
						actor->actorVars.varB8.uchars[3] = D_802BD250[actor->unk48].unk1;
						break;
					case 20:
						actor->actorVars.varB8.uchars[3]--;
					
						if(!actor->actorVars.varB8.uchars[3]){
							zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_LEVEL_DEATH, 0);
							func_8000B120(3);
							
							D_800F3920.unk2 = 0x78;
							D_800F3920.unk0 = 6;
							
							actor->actorVars.varB8.uchars[2] = 30;
						}
						break;
				}			
				if(actor->dir.y >= -40.0f){
					actor->dir.y -= actor->actorVars.varA4.fp;
				}
							
				actor->actorVars.varB0.fp += actor->dir.y * actor->scale.y;
				break;
		}
	}
}

void func_800738F4(Actor* actor){
	if(actor->actorVars.varC4.shorts[0] == 1 || actor->actorVars.varC8.shorts[0] == 1){
		switch(actor->actorVars.varB8.uchars[2]){
			case 0:
			 	actor->unk52 = 0;
				actor->unk6A = 0x17;
								
   				actor->unk50 = actor->unk52;
											
				actor->actorVars.varCC.uchars[1] = -1;
				actor->actorVars.varCC.shorts[1] = 0;
				actor->actorVars.varCC.uchars[0] = 4;
				actor->actorVars.varB8.uchars[2] = 10;
				actor->actorVars.varB8.uchars[3] = D_802BD264[actor->unk48].unk0;
				
				D_800F0588.unk1B = 1;
				D_800F0588.unk1D = 0;
				D_800F0630 = 0xA;
				break;
			case 10:
				actor->actorVars.varB8.uchars[3]--;
				
				if(!actor->actorVars.varB8.uchars[3]){
					if(actor->unk48 == 6){
						zzAudioSoundPlaySound(D_802BD6B0[cdata.characterNO], 1);
					}
					else{
						zzAudioSoundPlaySound(D_802BD6B0[actor->unk48], 1);
					}
					
					actor->actorVars.varB8.uchars[2] = 20;
					actor->actorVars.varB8.uchars[3] = D_802BD264[actor->unk48].unk1;
				
				}
				break;
			case 20:
				actor->actorVars.varB8.uchars[3]--;
				
				if(!actor->actorVars.varB8.uchars[3]){
					zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_LEVEL_FINISH, 0);
					D_800F0630 = 7;
					
					actor->actorVars.varB8.uchars[2] = 30;
					actor->actorVars.varB8.uchars[3] = 120;
				}
				break;
			case 30:
				if(actor->actorVars.varB8.uchars[3]){
					actor->actorVars.varB8.uchars[3]--;
				
					if(!actor->actorVars.varB8.uchars[3]){
						D_800F5FB0.unk1C[0] = 0xFFFF;
						D_800F5FB0_sets(60,2,1);
					}
				}
				else if(D_800F5FB0.unk0 == 3 && func_80006924() == 0){
					actor->actorVars.varB8.uchars[2] = 40;
					cdata.unk42 = 2;
					
					D_800E69C0.unk0 = 1;
					D_800E69C0.syscalls = 0x60;
					D_800E69C0.unk14 = 0x14;
					D_800E69C0.unk3C.uchar[0] = 1;
				}
				break;
			case 40:
				break;
		}
	}
	else{
		if(actor->dir.y >= -40.0f){
			actor->dir.y -= actor->actorVars.varA4.fp;
		}
							
		actor->actorVars.varB0.fp += actor->dir.y * actor->scale.y;	
	}
}

void func_80073B78(Actor* actor){
}

void func_80073B80(D_800F3940_struct* controller, D_801591C0_struct_unk4* arg1){
	s32 a2 = controller->unkB6;
	f32 r;
	s32 v0;
	s32 v02;
	s32 s0 = controller->unkB8;
	
	if(a2 == arg1->unkA && s0 == arg1->unkC){
		if(arg1->unkE < 0x3FFF){
			arg1->unkE++;
		}

	}
	else{
		arg1->unkE = 0;
	}

	arg1->unkA = a2;
	arg1->unkC = s0;

	arg1->unk0 = func_80025C48(a2, s0);

	r = (u16)arg1->unk0 % 90;

	if(r > 35.0f && r < 45.0f){
		r *= 0.004;
		r = 1.0 - r;
	}
	else if(r > 45.0f && r < 55.0f){
		r = r - 45.0f;
		r = r * 0.004 + 0.8200000000000001;
	}
	else{
		r = 1.0f;
	}

	a2 *= r;
	s0 *= r;

	arg1->valueX = a2;
	arg1->valueY = s0;

	if(a2 > 0){
		v0 = a2;
	}
	else{
		v0 = -a2;
	}
	a2 = v0;

	arg1->unk10 = a2;

	if(s0 > 0){
		v0 = s0;
	}
	else{
		v0 = -s0;
	}
	s0 = v0;

	arg1->unk12 = s0;

	if(a2 < 7 && s0 < 7){
		arg1->unk14 = 0;
	}
	else{
		arg1->unk14 = 1;
	}

	a2 *= a2;
	s0 *= s0;
	arg1->maxValue = sqrtf(a2 + s0);

	if(arg1->maxValue > 80){
		arg1->maxValue = 80;
	}

	cdata.unk0 = func_8000ADE0(arg1->unk0 + 90.0f + D_800F05B4);
}

void func_80073E80(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	u8 v1;

	if(actor->unk9C);
	
	v1 = actor->unk9C >= 300.0f ? 1 : 0;

	if(v1);
		
	if(actor->actorVars.varC8.uchars[2] != v1){
		actor->actorVars.varC8.uchars[2] = v1;
	
		func_8002439C(idx, (D_802BD870[actor->unk48*2+v1]));
		
		if(cdata.nextstg < ZZ_GAME0_LEVEL_OVERWORLD_GROUND){
			func_80076B64(idx);
		}
	}
}

void func_80073F28(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	s16 ft1;
	s16 v1;
	s16 a2;
	u16 r;
	f32 ang;
	u16 unk48;
	s16 v1_3;
	s32 v1_2 = actor->actorVars.varB8.shorts[0];
	f32 fv0;
	
	v1_3 = v1_2;
	
	if(v1_2 == 0xB || v1_2 == 0xF){
		return;
	}

	if(cdata.unk6E != 0){
		if(actor->actorVars.varC0.shorts[1] != 0){
			actor->actorVars.varC0.shorts[1]--;
		}
		return;
	}
	if(actor->actorVars.varC0.shorts[1] != 0){
		actor->actorVars.varC0.shorts[1]--;
		
		if(actor->actorVars.varC0.shorts[1] == 0){
			return;
		}
	}
	else{
		//todo fix unk8
		ft1 = (((D_801591C0_struct_unk8 *)(D_80159178->unk8))[actor->actorVars.varC4.shorts[1]]).unk0;
		
		fv0 = D_802BD4A8[actor->unk48].unk0;
		
		if(ft1 == 0xFF || ft1 == 0xFE){
			if(ft1 != 0xFE){
				if(ft1 == 0xFF){
					actor->health -= 50;
					
					if(actor->health > 0){
						actor->actorVars.varA4.fp = D_80159170;
						actor->dir.y = D_80159170 / 2 + 30.0f;
						actor->actorVars.varC4.shorts[0] = 0;
					}
					unk48 = actor->unk48;
				}
			}
			else{
				actor->health -= 20 * fv0;
				
				if(actor->health > 0){
					actor->actorVars.varA4.fp = D_80159170;
					actor->dir.y = D_80159170 / 2 + 5.0f;
					actor->actorVars.varC4.shorts[0] = 0;
					
				}
				;
			}
			
			actor->actorVars.varC0.shorts[1] = 0x46;
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 2;
			
			zzAudioSoundPlaySound(D_802BD67A[actor->unk48], 1);
			
			actor->unk52 = 0;
			actor->unk6A = 0xA;
			
			actor->actorVars.varB8.shorts[0] = 0xA;
			
			actor->unk50 = actor->unk52;
		}
		else{
			a2 = D_80141CB0[idx].unk4;
			v1 = 0;
			
			if(a2 == -1){
				a2 = D_80141CB0[idx].unkA;
				v1 = 3;
			}

			if(a2 != -1){
				actor->unk52 = 0;
				actor->unk50 = actor->unk52;
				
				if((v1_3 != 6 && v1_3 != 0x14) || actor->actorVars.varC0.shorts[0] != 0 || v1 == 3){
					actor->actorVars.varC0.shorts[1] = 0x46;
					actor->actorVars.varCC.uchars[1] = -1;
					actor->actorVars.varCC.shorts[1] = 0;
					actor->actorVars.varCC.uchars[0] = 2;
			
					zzAudioSoundPlaySound(D_802BD67A[actor->unk48], 1);
					
					if(actor->health != 0){
						actor->health -= GET_ACTOR_PTR(a2)->unk66 * fv0;
					}
					if(actor->health > 0){
						r = func_80025C48((actor->pos.z - GET_ACTOR_PTR(a2)->pos.z) * 10.0f, (actor->pos.x - GET_ACTOR_PTR(a2)->pos.x) * 10.0f);
						
						ang = DEG2RAD_ALT(r);
						
						switch(actor->actorVars.varC8.shorts[0]){
							case 1:
								actor->actorVars.varC4.shorts[0] = 0;
								actor->unk6A = 0x10;
							
								actor->actorVars.varA0.fp += sinf(ang) * 800.0f;
								actor->actorVars.varA8.fp += cosf(ang) * 800.0f;
								actor->dir.y = D_80159170 / 2;

								actor->actorVars.varB8.shorts[0] = 0x15;
								
								break;
							case 0:
								actor->actorVars.varC4.shorts[0] = 0;
							
								actor->actorVars.varA0.fp += sinf(ang) * 800.0f;
								actor->actorVars.varA4.fp = D_80159170;
								actor->actorVars.varA8.fp += cosf(ang) * 800.0f;
								actor->dir.y = D_80159170 / 2 + 10.0f;
								actor->unk6A = 0xA;
								actor->actorVars.varB8.shorts[0] = 0xA;
								
								break;
							case 2:
								actor->actorVars.varA0.fp += sinf(ang) * 850.0f;
								actor->actorVars.varA8.fp += cosf(ang) * 850.0f;
								actor->unk6A = 0x15;
								actor->actorVars.varB8.shorts[0] = 0x16;
								break;
						}
					}
				}
				else{
					if(!(GET_ACTOR_PTR(a2)->unk8 & 1)){
						v1 = GET_ACTOR_PTR(a2)->health - 10;
						if(v1 < 0){
							v1 = 0;
						}
						
						GET_ACTOR_PTR(a2)->health = v1;
						
						D_80142AB0[a2] = 6;
					}
					else{
						zzAudioSoundPlaySound(0x52, 1);
					}
					
					actor->actorVars.varC0.shorts[0] = 0;
					actor->actorVars.varBC.shorts[1] = 0;
					
					actor->dir.y = D_80159170 / 2 + 16.0f;
					actor->actorVars.varA4.fp = D_80159170;
					
					
					actor->actorVars.varB8.shorts[0] = 6;
					actor->unk6A = 5;
					
					if(GET_ACTOR_PTR(a2)->unk8 & 0x80){
						actor->actorVars.varB8.shorts[0] = 0x14;
						actor->dir.y = 50.0f;
						
						zzAudioSoundPlaySound(D_802BDE40, 1U);
					}
				}
			}
		}
	}
	
	if(actor->health <= 0){
		actor->health = 0;
		
		switch(actor->actorVars.varC8.shorts[0]){
			case 0:
				actor->actorVars.varC8.uchars[3] = 3;
				break;
			case 1:
				actor->actorVars.varC8.uchars[3] = 1;
				break;
			case 2:
				actor->actorVars.varC8.uchars[3] = 2;
				break;
		}
		
		actor->actorVars.varB8.shorts[0] = 11;
		actor->actorVars.varB8.uchars[2] = 0;
		actor->actorVars.varB8.uchars[3] = 0;
		actor->actorVars.varCC.uchars[1] = -1;
		actor->actorVars.varCC.shorts[1] = 0;
		actor->actorVars.varCC.uchars[0] = 3;
	}
}

void func_80074594(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	
	if(actor->actorVars.varB8.shorts[0] != 11 && actor->pos.y < D_801B5900[cdata.nextstg].unk0){
		actor->actorVars.varC8.uchars[3] = 2;
		actor->actorVars.varB8.shorts[0] = 11;
		actor->actorVars.varCC.uchars[1] = -1;
		actor->actorVars.varCC.shorts[1] = 0;
		actor->actorVars.varCC.uchars[0] = 3;
	}
}

void func_8007461C(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	
	func_80073B80(controllers[actor->actorVars.varC4.shorts[1]], D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4);
	
		actor->unk6E = D_80159178->unk48[(s16)actor->actorVars.varC4.integer].unk4[0].maxValue * 2 +80;

	func_80073F28(idx);
	func_8007E370(actor);
	func_80072EC0(actor);
	func_80077164(actor, idx);
	func_80073174(actor);
	
	switch(actor->actorVars.varB8.shorts[0]){
		case 0:
		case 1:
		case 2:
			func_8007D310(actor);
			func_8007DB14(actor);
			func_80074EE0(actor, idx);
			break;
		case 8:
			func_80075BD8(actor, idx);
			break;
		case 20:
			func_8007DB14(actor);
			break;
		case 6:
			func_8007DB14(actor);
			func_80074EE0(actor, idx);
			break;
		case 9:
			func_8007D310(actor);
			func_8007DB14(actor);
			break;
		case 10:
			func_8007DB14(actor);
			func_80073B78(actor);
			break;
		case 11:
			func_80073440(actor);
			break;
		case 15:
			func_800738F4(actor);
			break;
		case 7:
			func_8007DB14(actor);
			func_80075BD8(actor, idx);
			break;
		case 12:
		case 13:
		case 21:
			actor->health = 0;
			break;
	}
	
	func_80073094(actor);
	func_8007D434(actor);
	func_80072FB0(actor);
	
 	cdata.unk10 = actor->pos.x;
	cdata.unk14 = actor->pos.y + (80.0f * actor->scale.y);
	cdata.unk18 = actor->pos.z;

	actor->actorVars.varAC.fp = 0.0f;
	actor->actorVars.varB0.fp = 0.0f;
	actor->actorVars.varB4.fp = 0.0f;
}

#ifdef NON_MATCHING
void func_80074840(s16 idx){
	Actor* actor = GET_ACTOR_PTR(idx);
	ZZMotionInfo* info;
	ZZMotionInfo* a1;
	ZZMotionData* data;
	s16 v0;
	s16 v0_2;

	if(actor->unk52 == 0){
		info = D_80305000[actor->unk6C];
		data = info[actor->unk6A].motionData;
		v0_2 = actor->unk50++;

		if((u32)actor < (u32)GET_ACTOR_PTR(5) && v0_2 == 0){
			actor->actorVars.varBC.shorts[0] = 0;
		}

		data += v0_2;

		v0 = data->unk0;
		
		if(v0 == -2){
			actor->unk52 = 0;
			actor->unk50--;
		}
		else{
			if(v0 != -3){
				if(v0 != -1){
					a1 = &info[actor->unk6A];
				}
				else{
					v0 = data->unk2;
					actor->unk50 = v0+1;
					if(1);
					data = &data[v0]; a1 = &info[actor->unk6A];
				}
			}
			else{
				actor->actorVars.varB8.shorts[0] = data->unk2;
				actor->unk6A = data[1].unk0;
				v0 = data[1].unk2;
				
				a1 = &info[actor->unk6A];
				data = a1->motionData;
				
				actor->unk50 = v0+1;
				data = &data[v0];
			}
			if(a1->unk4 == 1){
				v0 = actor->unk6E;

				if(v0 == 0){
					v0 = 1;
				}

				actor->unk52 = (data->unk2 * 128.0f) / v0;
			}
			else{
				actor->unk52 = data->unk2;
			}

			func_80074A44(actor, data->unk0);

			if(actor->unk52 == 0){
				func_80074C38(actor);
			}
		}
	}
	else{
		actor->unk52--;

		if((u32)actor < (u32)GET_ACTOR_PTR(5)){
			actor->actorVars.varBC.shorts[0]++;
		}
	}
	if(actor->unk52 != 0){
		func_80074C38(actor);
	}
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/73660/func_80074840.s") 
#endif

#ifdef NON_MATCHING
void func_80074A44(Actor* actor, s16 idx){
	s16 a2 = actor->unk52;
	D_803050E4_struct* s1;
	s16 sp3E;
	s16 s4;
	s16 i;
	D_801414A0_ptr_struct* s0;
	f32 r;
	
	if(a2 == 0){
		a2 = 1;
	}

	s1 = D_803050E4[actor->unk6C][idx];
	s4 = actor->unk3C;
   
	if(actor->unk48 < 6 && sp3E == D_802BD234[actor->unk48]){
		s4--;
	}
	else if(actor->unk48 == 7){
		s4 = 0x13;
	}
	
	for(i = 0; i < s4; s1++,i++){
		s0 = (&D_801414A0[actor->unk38])[i];
		
		s0->unk330 = (s1->unk0 - s0->unk24) / a2;
		s0->unk334 = (s1->unk2 - s0->unk28) / a2;
		s0->unk338 = (s1->unk4 - s0->unk2C) / a2;
		
		r = func_8000ADE0(s0->unk30);
		
		s0->unk30 = r;
		s0->unk33C = func_80074E68(r, s1->unk6) / a2;
		
		r = func_8000ADE0(s0->unk34);
		
		s0->unk34 = r;
		s0->unk340 = func_80074E68(r, s1->unk8) / a2;
		
		r = func_8000ADE0(s0->unk38);
		
		s0->unk38 = r;
		s0->unk344 = func_80074E68(r, s1->unkA) / a2;
		
	}
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/73660/func_80074A44.s") 
#endif

void func_80074C38(Actor* actor){
	s16 i;
	D_801414A0_ptr_struct* s0;
	
	for(i = 0; i < actor->unk3C; i++){
		s0 = (&D_801414A0[actor->unk38])[i];
		
		s0->unk24 += s0->unk330;
		s0->unk28 += s0->unk334;
		s0->unk2C += s0->unk338;
		
		s0->unk30 = func_8000ADE0(s0->unk30 + s0->unk33C);
		s0->unk34 = func_8000ADE0(s0->unk34 + s0->unk340);
		s0->unk38 = func_8000ADE0(s0->unk38 + s0->unk344);
	}
}

void func_80074D24(Actor *actor) {
	ZZMotionInfo* info;
	ZZMotionData* data;
	u16 idx;
	
	info = D_80305000[actor->unk6C];
	data = info[actor->unk6A].motionData;
	idx = data[actor->unk50].unk0;
	
	func_80074D74(actor, idx);
}

#ifdef NON_MATCHING
void func_80074D74(Actor* actor, u16 idx){
	D_803050E4_struct* v0 = D_803050E4[actor->unk6C][idx];
	D_801414A0_ptr_struct* a1;
	u16 i;
	
	for(i = 0; i < actor->unk3C; i++, v0++){
		a1 = (&D_801414A0[actor->unk38])[i];
		
		a1->unk24 = v0->unk0;
		a1->unk2C = v0->unk2;
		a1->unk30 = v0->unk4;
		a1->unk34 = v0->unk6;
		a1->unk38 = v0->unk8;
	}
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/73660/func_80074D74.s") 
#endif

#ifdef NON_MATCHING
f32 func_80074E68(f32 arg0, f32 arg1){
	f32 fv0 = arg1 - arg0;
	f32 fv1;
	
	if(arg0 < arg1){
		fv1 = fv0;
	}
	else{
		fv1 = -fv0;
	}
	
	if(fv1 > 180.0f){
		if(fv1 > 0.0f){
			fv1 -= 360.0f;
		}
		else{
			fv1 += 360.0f;
		}
	}
	
	return fv1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/73660/func_80074E68.s") 
#endif
