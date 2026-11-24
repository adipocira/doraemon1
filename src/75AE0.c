#include "75AE0.h"
#include "controller.h"
#include "78DE0.h"
#include "76BB0.h"
#include "7B6C0.h"
#include "23B20.h"
#include "2DE50.h"
#include "7FC0.h"
#include "7310.h"
#include "9320.h"
#include "B4E0.h"
#include "zzAudio.h"
#include "zzGameData.h"
#include "zzGame.h"
#include "libc/math.h"

extern f32 D_80159170;

extern u16 D_802BD6C2[];
extern u16 D_802BD6E6[];

extern s16 D_80154628[];

void func_80074EE0(Actor* actor, s16 idx){
	s16 v0;
	D_802BD494_struct* v1;
	u16 temp;
	
	if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1 && func_80075AF8(actor)){
		temp = actor->unk48;
		v1 = &D_802BD494[temp];
		
		if(D_80154628[idx] < v1->unk4){
			actor->actorVars.varD4.shorts[0] = v1->unk8;
			
			if(actor->actorVars.varC4.shorts[0] == 0){
				v0 = 7;
				actor->unk6A = 9;
			}
			else if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_Z_TRIG] != 0 && temp != 6){
				v0 = 4;
				actor->unk6A = 8;
			}
			else{
				v0 = 8;
				actor->unk6A = 6;
			}
			
			actor->unk52 = 0;
			actor->unk50 = actor->unk52;
			
			actor->actorVars.varB8.shorts[0] = v0;
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 1;
			
		}
	}
}

void func_80074FF8(Actor* actor, s16 idx){
	if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
		if(func_80075AF8(actor) && D_80154628[idx] < D_802BD494[actor->unk48].unk4){
			actor->actorVars.varB8.shorts[0] = 0xE;
			actor->unk6A = 0xF;
			actor->unk50 = 0;
			actor->unk52 = 0;
			
			func_800751DC(actor, idx, actor->pos.y);
			
			actor->actorVars.varA4.fp = 0.0f;
			zzAudioSoundPlaySound(D_802BD6C2[actor->unk48], 1);
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 1;
			
		}
	}
}

void func_800750EC(Actor* actor, s16 idx){
	static const s32 D_800C5D90[] = {
		0x6D702564,0x08000000,0x00000000,0x00000000,0x25640000, 0x00000000,
	};
	
	if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_B_BUTTON] == 1){
		if(func_80075AF8(actor) && D_80154628[idx] < D_802BD494[actor->unk48].unk4){
			actor->actorVars.varB8.shorts[0] = 0x12;
			actor->unk6A = 0x14;
			actor->unk52 = 0;
			actor->unk50 = actor->unk52;
			
			func_800751DC(actor, idx, actor->pos.y);
			zzAudioSoundPlaySound(D_802BD6C2[actor->unk48], 1);
			actor->actorVars.varCC.uchars[1] = -1;
			actor->actorVars.varCC.shorts[1] = 0;
			actor->actorVars.varCC.uchars[0] = 1;
			
		}
	}
}

void func_800751DC(Actor* actor, s16 arg1, f32 y){
	Actor* actor1;
	f32 dir;
	s16 v0;
	s16 s0 = actor->actorVars.varB8.shorts[0];
	s16 id;
	f32 ang = DEG2RAD_ALT(actor->rot.y);
	s16 id2;
	f32 x;
	f32 z;
	u16 actorId;
	u16 i;
	f32 fs0;

	switch(actor->unk48){
		case 0:
			v0 = func_80075FB0(actor, 20.0f, 400.0f);
			
			if(v0 < 0){
				v0 = actor->rot.y;
			}
			else{
				actor->rot.y = v0;
				if(1);
			}
			
			if(s0 == 4){
				y += 10.0;
			}
			else{
				y += 15.0;
			}
			
			x = sinf(ang);
			z = cosf(ang);
			
			id = func_80023644(4, 0x131, x * 10.0f + actor->pos.x, y, z * 10.0f + actor->pos.z, 0.0f, v0, 0.0f);
			actor1 = GET_ACTOR_PTR(id);
			break;
		case 1:
			v0 = func_80075FB0(actor, 15.0f, 600.0f);
			
			if(v0 >= 0){
				actor->rot.y = v0;
			}
			
			if(s0 == 4){
				y += 20.0;
			}
			else{
				y += 25.0;
			}
			
			x = sinf(ang);
			z = cosf(ang);
			
			id = func_80023644(4, 0x12C, x * 10.0f + actor->pos.x, y, z * 10.0f + actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			actor1 = GET_ACTOR_PTR(id);
			break;
		case 2:
			if(s0 == 4){
				y += 10.0;
				dir = D_80159170 / 2 + 6.0f;
			}
			else{
				y += 15.0;
				dir = D_80159170 / 2 + 12.0f;
			}
			
			x = sinf(ang);
			z = cosf(ang);
			
			id = func_80023644(4, 0x1C, x * 10.0f + actor->pos.x, y, z * 10.0f + actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			
			if(id >= 0){
				GET_ACTOR_PTR(id)->actorVars.varAC.integer = func_80023644(4, 0x1D, GET_ACTOR_PTR(id)->pos.x, GET_ACTOR_PTR(id)->pos.y, GET_ACTOR_PTR(id)->pos.z, 0.0f, actor->rot.y, 0.0f);
				
				func_80022F20(id, func_8002E250);
				D_801414A0[GET_ACTOR_PTR(id)->unk38]->unk50 = 2;
				D_801414A0[GET_ACTOR_PTR(id)->unk38]->unk54 = 30.0f;
				GET_ACTOR_PTR(id)->dir.y = dir;
			}
			
			actor1 = GET_ACTOR_PTR(id);
			break;
		case 3:	
			if(s0 == 4){
				y += 12.0;
			}
			else{
				y += 15.0;
			}
			
			x = sinf(ang);
			z = cosf(ang);
			
			id = func_80023644(4, 0x12C, x * 10.0f + actor->pos.x, y, z * 10.0f + actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			
			if(id >= 0){
				func_80022F20(id, func_8002E5F0);
				GET_ACTOR_PTR(id)->flags |= 8;
				func_80023FCC(GET_ACTOR_PTR(id)->unk70);
				GET_ACTOR_PTR(id)->unk70 = -1;
			}
			
			actor1 = GET_ACTOR_PTR(id);
			break;
		case 4:
			id = func_80023498(4, 0x12C, actor->pos.x, y + 20.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			
			if(id >= 0){
				func_80022F20(id, func_8002EA24);
				GET_ACTOR_PTR(id)->flags |= 0x8;
				fs0 = actor->rot.y + 45.0f;
				actorId = 0x12D;

				for(i = 0; i < 4; i++, fs0 += 90.0f, actorId++){
					id2 = func_80023644(4, actorId, actor->pos.x, y + 20.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);
					
					if(id2 >= 0){
						GET_ACTOR_PTR(id2)->actorVars.varA4.integer = arg1;
						GET_ACTOR_PTR(id2)->actorVars.varAC.fp = func_8000ADE0(fs0);
						func_80022F20(id2, func_8002E7F8);
					}
				}
			}
			
			actor1 = GET_ACTOR_PTR(id);
			break;
		case 5:
			if(s0 == 4){
				y += 20.0;
			}
			else{
				y += 25.0;
			}
			
			x = sinf(ang);
			z = cosf(ang);
			
			id = func_80023644(4, 0x132, x * 10.0f + actor->pos.x, y, z * 10.0f + actor->pos.z, 0.0f, actor->rot.y, 0.0f);
				
			func_80022F20(id, func_8002ECD0);	
			actor1 = GET_ACTOR_PTR(id);		
			break;
		case 6:
			id = func_80023498(4, 0x12C, actor->pos.x, y + 20.0f, actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			GET_ACTOR_PTR(id)->flags |= 0x8;
			func_80022F20(id, func_80078DB0);
			GET_ACTOR_PTR(id)->actorVars.varA8.integer = arg1;	
			return;
		case 7:
			ang = DEG2RAD_ALT(actor->actorVars.varDC.fp);
			
			x = sinf(ang);
			z = cosf(ang);\
			\
			id = func_80023498(4, 0x18A, x * 10.0f + actor->pos.x, y + 35.0f, z * 10.0f + actor->pos.z, 0.0f, actor->rot.y, 0.0f);
			
			func_80024874(id, 0.1f);
			func_80022F20(id, func_80078BA0);
			
			GET_ACTOR_PTR(id)->a = 0;
			GET_ACTOR_PTR(id)->actorVars.varDC.fp = actor->actorVars.varDC.fp;
			actor1 = GET_ACTOR_PTR(id);
			break;
		default:
			actor1 = GET_ACTOR_PTR(id);
			break;
	}
	
	actor1 = GET_ACTOR_PTR(id);
	actor1->actorVars.varA4.integer = arg1;
}

s32 func_80075AF8(Actor* actor){
	s32 ret;
	
	if(cdata.nextstg >= ZZ_GAME0_LEVEL_OVERWORLD_GROUND){
		return 0;
	}
	switch(actor->unk48){
		case 0:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_AIR_CANNON)){
				return TRUE;
			}
			break;
		case 1:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_SHOCKWAVE_PISTOL)){
				return TRUE;
			}
			break;
		case 2:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_DANGER_BOMB)){
				return TRUE;
			}
			break;
		case 3:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_CHAMPION_GLOVES)){
				return TRUE;
			}
			break;
		case 4:
			if(cdata.item & CDATA_ITEM(ZZ_ITEM_GENE_MICROPHONE)){
				return TRUE;
			}
			break;
		case 5:
			return TRUE;
			break;
		case 6:
			return TRUE;
			break;
		case 7:
			return TRUE;
			break;
	}
	
	return FALSE;
}

void func_80075BD8(Actor* actor, s16 idx){
	D_801591C0_struct_unk4* temp = D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4;

	if(temp->unk14 != 0 && (actor->unk48 == 1 || actor->unk48 == 0)){
		func_8007E570(actor, 0.35f);
	}
	
	if(actor->actorVars.varD4.shorts[0] != 0){
		actor->actorVars.varD4.shorts[0]--;
		
		if(actor->actorVars.varD4.shorts[0] == 0){
			func_800751DC(actor, idx, actor->pos.y);
			
			if(actor->actorVars.varB8.shorts[0] == 7){
				zzAudioSoundPlaySound(D_802BD6E6[actor->unk48], 1);
			}
			else{
				zzAudioSoundPlaySound(D_802BD6C2[actor->unk48], 1);
			}
		}
	}
	if(D_802BD494[actor->unk48].unk6 < actor->actorVars.varBC.shorts[0]){
		func_80074EE0(actor, idx);
	}
}


void func_80075D0C(Actor* actor, s16 idx){
	D_801591C0_struct_unk4* temp = D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4;

	if(temp->unk14 != 0 && (actor->unk48 == 1 || actor->unk48 == 0)){
		func_8007E570(actor, 0.35f);
	}
	
	if(actor->actorVars.varD4.shorts[0] != 0){
		actor->actorVars.varD4.shorts[0]--;
		
		if(actor->actorVars.varD4.shorts[0] == 0){
			func_800751DC(actor, idx, actor->pos.y);
			zzAudioSoundPlaySound(D_802BD6C2[actor->unk48], 1);	
		}
	}
	if(D_802BD494[actor->unk48].unk6 < actor->actorVars.varBC.shorts[0]){
		func_800750EC(actor, idx);
	}
}

void func_80075E0C(Actor* actor, s16 idx){
	D_801591C0_struct_unk4* temp = D_80159178->unk48[actor->actorVars.varC4.shorts[1]].unk4;
	f32 fv0;

	if(temp->unk14 != 0 && (actor->unk48 == 1 || actor->unk48 == 0)){
		func_8007E570(actor, 0.35f);
	}
	
	if(actor->actorVars.varD4.shorts[0] != 0){
		actor->actorVars.varD4.shorts[0]--;
		
		if(actor->actorVars.varD4.shorts[0] == 0){
			func_800751DC(actor, idx, actor->pos.y);
			zzAudioSoundPlaySound(D_802BD6C2[actor->unk48], 1);	
		}
	}
	if(D_802BD494[actor->unk48].unk6 < actor->actorVars.varBC.shorts[0]){
		func_80074FF8(actor, idx);
	}
	
	fv0 = 0.02f;
	
	if(controllers[actor->actorVars.varC4.shorts[1]]->unk0.buttonTimers[ZZ_TIMER_Z_TRIG] != 0){
		fv0 *= 4;
	}
	
	if(actor->actorVars.varA4.fp < 6.0){
		actor->actorVars.varA4.fp += fv0;
	}
	
	actor->actorVars.varB0.fp += (actor->dir.y - actor->actorVars.varA4.fp) * actor->scale.y;
	actor->dir.y *= 0.98;
}
