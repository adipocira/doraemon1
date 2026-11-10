#include "7A2A0.h"
#include "zzAudio.h"
#include "zzEvents.h"
#include "common.h"
#include "libc/math.h"
#include "TexRec.h"
#include "zzGameData.h"
#include "2DE50.h"
#include "6FA0.h"
#include "386E0.h"
#include "368E0.h"
#include "7FC0.h"
#include "9320.h"
#include "23B20.h"
#include "78DE0.h"
#include "13940.h"
#include "B4E0.h"
#include "8A6C0.h"
#include "controller.h"
#include "zzFileSelect.h"

extern u8 D_800F0630;

extern s8 D_800F05A4;

extern s16 D_800F062A;

extern u8* D_801C7BC8[2];
extern u8* D_801C7F00;

extern u8 D_8015B5A8[10];
extern u8 D_8015B5B0[10];

extern u16 D_800F5FA8[];

extern Vec3f D_802BECBC[];

void func_800796A0(s16 idx){
    Actor* actor = GET_ACTOR_PTR(idx);
    Actor* actor2 = GET_ACTOR_PTR(D_80159178->unk48[cdata.unk41].unk0);
    Actor* actor3;
    Actor* actor4;
    D_802BED74_struct* v1;
    Vec3f* t0;
    u16 i;
    u16 pad;
    s16 a1;
    s16 id;
    s32 pad2;
    s32 pad3;

    switch(GET_ACTOR_PTR(idx)->status){
        case 0:
            actor->actorVars.varB0.integer = 0;

            if(cdata.item & CDATA_ITEM(ZZ_ITEM_WHAT_IF_PHONE_BOOTH)){
                actor->actorVars.varB4.integer = -1;
                actor->actorVars.varB8.integer = 0;
                actor->actorVars.varBC.integer = -1;
                actor->actorVars.varC0.integer = 15;
            }
            else if(cdata.item & CDATA_ITEM(ZZ_ITEM_BLUE_STONE_2)){
                actor->actorVars.varB4.integer = 8;
                actor->actorVars.varB8.integer = 6;
                actor->actorVars.varBC.integer = 0x3D;
                actor->actorVars.varC0.integer = 15; 
            }
            else if(cdata.item & CDATA_ITEM(ZZ_ITEM_DEEP_SEA_CREAM)){
                actor->actorVars.varB4.integer = 4;
                actor->actorVars.varB8.integer = 3;
                actor->actorVars.varBC.integer = 0x2D;
                actor->actorVars.varC0.integer = 7;
            }
            else{               
                actor->actorVars.varB4.integer = 0;
                actor->actorVars.varB8.integer = 0;
                actor->actorVars.varBC.integer = 0x22;
                actor->actorVars.varC0.integer = 0; 
            }
            if(actor->actorVars.varB4.integer != -1){
                id = func_80023644(2, ZZ_ACTORS_TORPEDO, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                actor->actorVars.varC8.integer = id;

                func_80022F20(id, func_80031254);
                func_80024874(id, actor->actorVars.varB8.integer * 0.15 + 1.0);
                    
                GET_ACTOR_PTR(id)->actorVars.varB4.integer = actor->actorVars.varB8.integer;

                D_800F0588.unk1C = D_800F0630;
                D_800F0630 = 0xC;
                
                D_800F0588.unkA2 = func_80023498(8, 0x1C2, actor->pos.x, actor->pos.y, actor->pos.z, 0.0f, 0.0f, 0.0f);
                func_80022F20(D_800F0588.unkA2, func_800064F0);

                actor3 = GET_ACTOR_PTR(D_800F0588.unkA2);
                actor3->actorVars.varA0.integer = id;
                actor3->actorVars.varA4.integer = D_80159178->unk48[cdata.unk41].unk0;

                actor3->actorVars.varB4.fp = sinf(DEG2RAD_ALT(func_8000ADE0(actor->rot.y - 135.0f))) * 220.0f;
                actor3->actorVars.varB8.fp = 25.0f;
                actor3->actorVars.varBC.fp = cosf(DEG2RAD_ALT(func_8000ADE0(actor->rot.y - 135.0f))) * 220.0f;

                D_800E6B20_setXY(28, 180);
                D_800F5FA8[0] = 0x96;

                GET_ACTOR_PTR(idx)->status = 3;
            }
            else{
                actor->actorVars.varA4.integer = 60;
                GET_ACTOR_PTR(idx)->status = 2;
            }
            for(t0 = D_802BECBC, i = 0; i < actor->actorVars.varC0.integer; i++, t0++){
                id = func_80023644(1, 0x38, t0->x, t0->y + 15.0f, t0->z, 0.0f, 0.0f, 0.0f);
                
                GET_ACTOR_PTR(id)->flags |= 2;
                GET_ACTOR_PTR(id)->scale.x =  GET_ACTOR_PTR(id)->scale.y = GET_ACTOR_PTR(id)->scale.z = 0.3f;
                GET_ACTOR_PTR(id)->unk80 = func_80038A0C;
                GET_ACTOR_PTR(id)->rot.z = 135.0f;
            }
            break;
        case 2:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer == 0){
                GET_ACTOR_PTR(idx)->status = 5;
            }
            break;
        case 3:
            if(cdata.events[cdata.nextstg] & 1){
                a1 = actor->actorVars.varB4.integer + 1;
            }
            else{
                a1 = actor->actorVars.varB4.integer;
            }
            if(func_80012D40(8, a1, 0xF1) == 0){
                actor4 = GET_ACTOR_PTR(actor->actorVars.varC8.integer);
                v1 = D_802BED74[actor->actorVars.varB8.integer];

                actor4->pos.x = v1->pos.x;
                actor4->pos.y = v1->pos.y;
                actor4->pos.z = v1->pos.z;
                actor4->rot.y = v1->rotY;
                
                actor4->status = 20;
                actor4->actorVars.varA0.integer = 0;
                actor4->actorVars.varA4.integer = 1;
                actor4->actorVars.varB4.integer = actor->actorVars.varB8.integer+1;

                func_80028D80(actor4->unk70);
                func_80023FCC(D_800F062A);
                D_800F0630 = D_800F05A4;
                
                cdata.events[cdata.nextstg] |= 1;
                GET_ACTOR_PTR(idx)->status = 5;
            }
            break;
        case 5:
            zzTexRecSubInit(1);
            
            texRecAccess(0)->posX = 144;
            texRecAccess(0)->posY = 105;
            
            texRecAccess(0)->unk8 = texRecAccess(0)->width + 144;
            texRecAccess(0)->unkA = texRecAccess(0)->height + 105;

            texRecAccess(1)->posX = 144;
            texRecAccess(1)->posY = 105;
            
            texRecAccess(1)->unk8 = texRecAccess(1)->width + 144;
            texRecAccess(1)->unkA = texRecAccess(1)->height + 105;

            texRecAccess(2)->posX = 144;
            texRecAccess(2)->posY = 105;
            
            texRecAccess(2)->unk8 = texRecAccess(2)->width + 144;
            texRecAccess(2)->unkA = texRecAccess(2)->height + 105;

            texRecAccess(3)->posX = 128;
            texRecAccess(3)->posY = 105;
            
            texRecAccess(3)->unk8 = texRecAccess(3)->width + 128;
            texRecAccess(3)->unkA = texRecAccess(3)->height + 105;

            actor->actorVars.varA8.integer = 0;
            D_800E69C0.syscalls &= ~0x1;
            
            GET_ACTOR_PTR(idx)->status = 10;
            break;
        case 10:
            actor->actorVars.varA4.integer = 1;
            actor->actorVars.varA8.integer = 1;

            GET_ACTOR_PTR(idx)->status = 20;
            break;
        case 20:
            if(actor->actorVars.varA0.integer < 594000){
                actor->actorVars.varA0.integer++;
            }

            actor4 = GET_ACTOR_PTR(actor->actorVars.varC8.integer);
            
            if(actor4->pos.z < -7950.0f){
                actor->actorVars.varB0.integer = 1;
            }
            if(actor2->pos.z < -7950.0f){
                if(actor->actorVars.varB0.integer == 0){
                    actor->actorVars.varB0.integer = 2;
                }

                func_8007957C(actor->actorVars.varA0.integer, D_8015B5A8);
                func_8007957C(cdata.raceBestTime, D_8015B5B0);

                actor->actorVars.varA8.integer = 6;
                actor2->actorVars.varE8.shorts[0] |= 2;

                if(actor->actorVars.varA0.integer < cdata.raceBestTime){
                    if(actor->actorVars.varB4.integer == -1){
                        zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_TIME_TRIAL_FINISH, 0);
                    }
                    
                    D_8015B5B0[0] = D_8015B5A8[0];
                    D_8015B5B0[1] = D_8015B5A8[1];
                    D_8015B5B0[2] = D_8015B5A8[2];
                    D_8015B5B0[3] = D_8015B5A8[3];
                    D_8015B5B0[4] = D_8015B5A8[4];
                    D_8015B5B0[5] = D_8015B5A8[5];

                    cdata.raceBestTime = actor->actorVars.varA0.integer;
                    func_8007A96C(D_8015B5A8, D_8015B5B0, 0x31);
                }
                else{
                    if(actor->actorVars.varB4.integer == -1){
                        zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_RACE_LOST, 0);
                    }
                    
                    func_8007A96C(D_8015B5A8, D_8015B5B0, 0x30);

                }
                if(actor->actorVars.varB4.integer != -1){
                    if(actor->actorVars.varB0.integer == 2){
                        zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_RACE_WIN, 0);
                    }
                    else{
                        zzAudioSoundPlaySound(ZZ_AUDIO_SOUND_RACE_LOST, 0);
                    }
                }

                GET_ACTOR_PTR(idx)->status = 99;
            }
            break;
        case 30:                
            D_800E6B20_setXY(28, 180);
                
            GET_ACTOR_PTR(idx)->status = 40;
            break;
        case 40:
            if(actor->actorVars.varB0.integer == 2){
                a1 = (s16)(actor->actorVars.varB4.integer + 2);
            }
            else{
                a1 = (s16)(actor->actorVars.varB4.integer + 3);
                actor->actorVars.varBC.integer = -1;
            }
            if(func_80012D40(8, a1, 0xF1) == 0){
                GET_ACTOR_PTR(idx)->status = 50;
            }
            
            break;
        case 50:
            if(actor->actorVars.varBC.integer != -1){
                cdata.events[cdata.nextstg] &= ~0x1;

                id = func_80023644(6, 0x81, 7341.0f, 500.0f, -7600.0f, 0.0f, 180.0f, 0.0f);
                func_80022F20(id, func_80039254);

                actor3 = GET_ACTOR_PTR(id);
                
                actor3->unk68 = actor->actorVars.varBC.integer;
                actor3->actorVars.varC8.integer = 6;
            }
            else{
                actor2->actorVars.varB8.shorts[0] = 0xF;
                actor2->actorVars.varB8.uchars[2] = 0;
            }
            
            GET_ACTOR_PTR(idx)->status = 99;
            break;
        case 99:
            break;
    }
    switch(actor->actorVars.varA8.integer){
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer == 0){
                actor->actorVars.varA4.integer = 60;
                texRecAccess(actor->actorVars.varA8.integer-1)->unk2A = 1;

                if(actor->actorVars.varA8.integer == 4){
                    zzAudioSoundPlaySound(0xBC, 0);
                    actor2->actorVars.varE8.shorts[0] &= ~0x1;
                    zzAudioSeqPlaySeq(ZZ_AUDIO_SEQ_RACE, 0);

                    actor->actorVars.varA0.integer = 0;
                }
                else{
                    zzAudioSoundPlaySound(0xBD, 0);
                }

                actor->actorVars.varA8.integer++;
            }
            else if(actor->actorVars.varA4.integer >= 30){
                if(actor->actorVars.varA4.integer == 30){
                    texRecAccess(actor->actorVars.varA8.integer-2)->unk2A = 0;
                }
                else{
                    texRecAccess(actor->actorVars.varA8.integer-2)->alpha = actor->actorVars.varA4.integer * 8 - 225;
                }
            }
            break;
        case 5:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer == 30){
                texRecAccess(actor->actorVars.varA8.integer-2)->unk2A = 0;
                D_800E69C0.syscalls |= 1;
                actor->actorVars.varA8.integer = 0;
            }
            break;
        case 6:
            zzTexRecSubInit(2);
            texRecAccess(0)->posX = 52;
            texRecAccess(0)->posY = 96;
            
            texRecAccess(0)->unk8 = texRecAccess(0)->width + 52;
            texRecAccess(0)->unkA = texRecAccess(0)->height + 96;

            texRecAccess(1)->posX = 108;
            texRecAccess(1)->posY = 96;
            
            texRecAccess(1)->unk8 = texRecAccess(1)->width + 108;
            texRecAccess(1)->unkA = texRecAccess(1)->height + 96;

            texRecAccess(2)->posX = 164;
            texRecAccess(2)->posY = 96;
            
            texRecAccess(2)->unk8 = texRecAccess(2)->width + 164;
            texRecAccess(2)->unkA = texRecAccess(2)->height + 96;

            texRecAccess(3)->posX = 220;
            texRecAccess(3)->posY = 96;
            
            texRecAccess(3)->unk8 = texRecAccess(3)->width + 220;
            texRecAccess(3)->unkA = texRecAccess(3)->height + 96;

            actor->actorVars.varA8.integer = 7;

            D_800E69C0.syscalls &= ~0x1;
            break;
        case 7:
            texRecAccess(0)->unk2A = 1;
            texRecAccess(1)->unk2A = 1;
            texRecAccess(2)->unk2A = 1;
            texRecAccess(3)->unk2A = 1;
            
            actor->actorVars.varA8.integer = 8;
            actor->actorVars.varA4.integer = 120;
            break;
        case 8:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer == 0){
                actor->actorVars.varA8.integer = 9;
                
                texRecAccess(0)->unk2A = 0;
                texRecAccess(1)->unk2A = 0;
                texRecAccess(2)->unk2A = 0;
                texRecAccess(3)->unk2A = 0;

                func_80089C90();

                actor->actorVars.varA4.integer = 10;
            }
            break;
        case 9:
            actor->actorVars.varA4.integer--;

            if(actor->actorVars.varA4.integer == 0){
                zzTexRecSubInit(3);
                
                texRecAccess(0)->posX = 96;
                texRecAccess(0)->posY = 84;
            
                texRecAccess(0)->unk8 = texRecAccess(0)->width + 96;
                texRecAccess(0)->unkA = texRecAccess(0)->height + 84;

                texRecAccess(1)->posX = 96;
                texRecAccess(1)->posY = 116;
            
                texRecAccess(1)->unk8 = texRecAccess(1)->width + 96;
                texRecAccess(1)->unkA = texRecAccess(1)->height + 116;
                
                texRecAccess(0)->unk2A = 1;
                texRecAccess(1)->unk2A = 1;

                D_800E6B20.unk29 = 0;
                D_800E6B20.unk25 = 0;
                D_800E6B20.unk24 = 0;
                D_800E6B20.unk19 = 0;
                D_800E6B20_setXY(104, 88);
                D_800E6B20.unk4 = D_801C7F00;
                D_800E6B20.unk0 = 2;
                
                actor->actorVars.varA8.integer = 10;
            }
            break;
        case 10:
            if (controllers[cdata.unk41]->unk0.buttonTimers[ZZ_TIMER_A_BUTTON] == 1){
                texRecAccess(0)->unk2A = 0;
                texRecAccess(1)->unk2A = 0;

                func_80089C90();
                
                D_800E6B20.unk0 = 0;
                D_800E6B20_sets2(75, 183, cdata.tellerSpeedDelay, 1, 0xB, 4, 5);
                actor->actorVars.varA8.integer = 0;

                if(actor->actorVars.varBC.integer == -1){
                    GET_ACTOR_PTR(idx)->status = 50;
                }
                else{
                    GET_ACTOR_PTR(idx)->status = 30;
                }
            }
            break;
    }
}

void func_8007A96C(u8* time1, u8* time2, u8 arg2){
    u8* v0 = D_801C7F00;
    u8* v1 = D_801C7BC8[0];
    u8* time1t;

    do{
        *v0++ = *v1++;
    }while(v1[-1] != 0xFE);

    time1t = time1;
    
    *v0++ = *time1++ + 1;
    *v0++ = *time1++ + 1;
    *v0++ = 0xBC;

    *v0++ = *time1++ + 1;
    *v0++ = *time1++ + 1;
    *v0++ = 0xBD;

    *v0++ = *time1++ + 1;
    time1t = time1++;
    *v0++ = *time1t++ + 1;
    *v0++ = 0xFE;

    v1 = D_801C7BC8[1];
    v1++;

    do{
        *v0++ = *v1++;
    }while(v1[-1] != 0xFE);
    
    *v0++ = 0xF8;
    *v0++ = arg2;
    *v0++ = *time2++ + 1;

    *v0++ = *time2++ + 1;
    *v0++ = 0xBC;
    *v0++ = *time2++ + 1;

    *v0++ = *time2++ + 1;
    *v0++ = 0xBD;
    *v0++ = *time2++ + 1;

    *v0++ = *time2++ + 1;
    *v0++ = 0xF7;
    *v0++ = 0xFF;
}

