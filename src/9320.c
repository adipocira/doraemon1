#include "9320.h"
#include "7FC0.h"
#include "7310.h"
#include "audio.h"
#include "playseq.h"
#include "B4E0.h"

#include "libc/math.h"
#include "global.h"
#include "common.h"

u8 D_800ABD00[][2] = {
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x03 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x32, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x04 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x32, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x32, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x32, 0x07 }, { 0x32, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x0A, 0x07 }, { 0x0A, 0x07 }, { 0x0A, 0x04 }, { 0x0A, 0x07 }, { 0x00, 0x07 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0x05 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x47 }, { 0x00, 0x07 }, { 0x00, 0x57 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x04 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x14, 0x07 }, { 0x14, 0x07 }, { 0x14, 0x07 }, { 0x14, 0x07 }, { 0x14, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x1E, 0x05 }, { 0x1E, 0x07 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0x07 }, { 0x00, 0xA7 }, { 0x1E, 0x05 }, { 0x1E, 0x05 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x14, 0x07 }, { 0x00, 0x06 }, { 0x00, 0x06 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x05 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0x07 },
    { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 }, { 0x00, 0xA7 },
    { 0x00, 0xA7 }, { 0x00, 0x07 }, { 0x14, 0x06 }, { 0x00, 0x06 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x87 },
    { 0x00, 0x06 }, { 0x00, 0x06 }, { 0x00, 0x07 }, { 0x05, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x07 },
    { 0x00, 0x07 }, { 0x00, 0x07 }, { 0x00, 0x04 }, { 0x00, 0x07 }, { 0x00, 0x57 }, { 0x00, 0x00 }, { 0x00, 0x00 },
    { 0x00, 0x00 }, { 0x00, 0x00 },
};

//todo RAD2DEG
void func_80008720(f32 x, f32 y, f32 z, s32 arg3, s32 arg4, ALPan* panPtr, s16* volPtr){
    u8 pan;
    s32 pad;
    f32 fa0_2;
    f32 xDiff;
    f32 yDiff;
    f32 zDiff;
    f32 fv1;
    f32 dist;
    
    fv1  = func_8000B038(D_800F0548.unk0 - D_800F0548.unkC, D_800F0548.unk8 - D_800F0548.unk14) * 57.32484076 /*RAD2DEG(1)*/;
    xDiff = D_800F0548.unk0 - x;
    zDiff = D_800F0548.unk8 - z;
    yDiff = D_800F0548.unk4 - y; 
    fa0_2 = func_8000B038(xDiff, zDiff) * 57.32484076 /*RAD2DEG(1)*/;
    
    if(fa0_2 < fv1){
        pan = ((360.0f + fa0_2) - fv1) * 0.7055555582f;    
    }
    else{
        pan = (u32)((fa0_2 - fv1) * 0.7055555582f);
    }
    
    pan = (u8)(pan + 0xC0) % 255;

    if(pan < 128){
        *panPtr = pan;
    }
    else{
        *panPtr = 127 - (pan % 128);
    }

    dist = sqrtf(SQ(xDiff) + SQ(zDiff));
    dist = sqrtf(SQ(dist) + SQ(yDiff));
    
    if(dist > 0.0f && dist < arg3){
        *volPtr = arg4 - (s32)((arg4 / (f32)arg3) * dist);
        
    }
    else{
        *volPtr = 0;
    }
}


s32 func_80008A30(s16 soundId, u8 soundCtxId){
    ALSndPlayer* seqp;
    u8 id = soundCtxId;
    
    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        s16 s2;
        s16 s3;
        
        seqp = soundContexts[id].soundPlayer;

        alSndpSetSound(seqp, soundContexts[id].soundId);
        s2 = (u8)((D_800ABD00[soundContexts[id].unk4][1] & 0xF0) >> 4);
        s3 = (u8)((D_800ABD00[soundId][1] & 0xF0) >> 4);

        if((s16)alSndpGetState(seqp) == AL_PLAYING){
            s16 i;
            
            if (s3 < s2) {
                for(i = 1; i < 6; i++){
                    ALSndPlayer* s = soundContexts[i].soundPlayer;
    
                    alSndpSetSound(s, soundContexts[i].soundId);
    
                    if(alSndpGetState(s) != AL_PLAYING){
                        soundContexts[i].unk4 = soundId;
                        
                        if(!(D_800ABD00[soundId][1] & 8)){
                            soundContexts[i].unk18 = 0.5f;
                        }
                        else{
                            soundContexts[i].unk18 = 1.0f;
                        }
    
                        soundContexts[i].unkC = 2;
    
                        return i;
                    }

                }
                if (i == 6){
                    return -1;
                }
            } else {
                soundContexts[soundCtxId].unk4 = soundId;
                        
                if(!(D_800ABD00[soundId][1] & 8)){
                    soundContexts[soundCtxId].unk18 = 0.5f;
                }
                else{
                    soundContexts[soundCtxId].unk18 = 1.0f;
                }

                soundContexts[soundCtxId].unkC = 2;
            }

        }
        else{
            if (seqp && seqp);
            soundContexts[soundCtxId].unk4 = soundId;
                    
            if(!(D_800ABD00[soundId][1] & 8)){
                soundContexts[soundCtxId].unk18 = 0.5f;
            }
            else{
                soundContexts[soundCtxId].unk18 = 1.0f;
            }

            soundContexts[soundCtxId].unkC = 2;
        }
    }

    return soundCtxId;
}

void func_80008C6C(s16 soundId, u8 soundCtxId){
    s16 id;
    s16 vol;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = func_80008A30(soundId, soundCtxId)) != -1){
            vol = D_800ABD00[soundId][1] & 0x7;
            vol <<= 0xC;
            
            soundContexts[id].pan = 64;
            soundContexts[id].vol = vol + 0xFFF;
            soundContexts[id].unk2A = -1;
            soundContexts[id].unk28 = 0;
        }
    }
}

void func_80008D24(s16 soundId, u8 soundCtxId, s32 arg2, s32 arg3, f32 x, f32 y, f32 z){
    s16 id;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = func_80008A30(soundId, soundCtxId)) != -1){
            func_80008720(x, y, z, arg2, arg3, &soundContexts[id].pan, &soundContexts[id].vol);

            soundContexts[id].soundPosX = x;
            soundContexts[id].soundPosY = y;
            soundContexts[id].soundPosZ = z;
            soundContexts[id].unk28 = arg3;
            soundContexts[id].unk2C = arg2;
        }
    }
} 

void func_80008E10(s16 soundId, u8 soundCtxId, s16 actorIdx){
    s16 id;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = func_80008A30(soundId, soundCtxId)) != -1){
            soundContexts[id].unk2C = 0x1388;
            soundContexts[id].unk28 = 0x7FFF;
            
            func_80008720(GET_ACTOR_PTR(actorIdx)->pos.x, GET_ACTOR_PTR(actorIdx)->pos.y, GET_ACTOR_PTR(actorIdx)->pos.z, soundContexts[id].unk2C, soundContexts[id].unk28, &soundContexts[id].pan, &soundContexts[id].vol);
            soundContexts[id].unk2A = actorIdx;
        }
    }
}

void func_80008EFC(){
    s32 i;

    for(i = 1; i < 6; i++){
        func_80009088(0, i);
    }
}

void func_80008F40(){
    s32 i;
    s16 vol;

    for(i = 1; i < 6; i++){
        vol = D_800ABD00[soundContexts[i].unk4][1] & 0x7;
        vol <<= 0xC;
        vol += 0xFFF;
        
        func_80009088(vol, i);
    }
}

void func_80008FC4(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].unk28 = arg0;
}

void func_80008FEC(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].unk28 = arg0;
}

void func_80009014(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].unk13 = arg0;
}

void func_8000903C(f32 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].unk18 = arg0;
}

void func_80009060(s8 pan, u8 soundCtxId){
    soundContexts[soundCtxId].pan = pan;
}

void func_80009088(s16 vol, u8 soundCtxId){
    soundContexts[soundCtxId].vol = vol;
}

void func_800090B0(u8 soundCtxId){
    if(soundCtxId < 6){
        soundContexts[soundCtxId].unkC = 1;
    }
}

void func_800090E4(){
    ALSndPlayer* sndp;
    ALSndpConfig c;
    s32 i;

    c.maxSounds = 6;
    c.maxEvents = EVT_COUNT;
    c.heap = &hp;
 
    D_800F08D4 = bank2Ptr->bankArray[0];
    D_800F08D8 = D_800F08D4->instArray[0];
    D_800F08DC = D_800F08D8->soundArray[0];
    
    sndp = alHeapAlloc(&hp, 1, sizeof(ALSndPlayer));
    alSndpNew(sndp, &c);
 
    for(i = 0; i < 6; i++){
        soundContexts[i].soundPlayer = sndp;
        soundContexts[i].unk4 = 0;
        soundContexts[i].unk6 = 0;
        soundContexts[i].soundId = alSndpAllocate(sndp, D_800F08DC);
        soundContexts[i].unkC = 0;
        soundContexts[i].vol = 0x7FFF;
        soundContexts[i].pan = 64;
        soundContexts[i].unk13 = 0;
        soundContexts[i].unk14 = 5;
        soundContexts[i].unk18 = 0.5f;
        soundContexts[i].soundPosX = 0.0f;
        soundContexts[i].soundPosY = 0.0f;
        soundContexts[i].soundPosZ = 0.0f;
        soundContexts[i].unk2A = -1;
        soundContexts[i].unk28 = 0;
    }
}


void func_80009240(){
    s16 vol;
    ALPan pan;
    u8 i;
    ALSndPlayer* sndp;
    ALInstrument* ins;
    
    for(i = 0; i < 6; i++){
        sndp = soundContexts[i].soundPlayer;

        alSndpSetSound(sndp, soundContexts[i].soundId);
        alSndpSetFXMix(sndp, soundContexts[i].unk13 + D_800ABD00[soundContexts[i].unk4][0]);
        alSndpSetPitch(sndp, soundContexts[i].unk18);

        if(alSndpGetState(sndp) == AL_PLAYING){
            if(soundContexts[i].unk2A != -1){
                func_80008720(GET_ACTOR_PTR(soundContexts[i].unk2A)->pos.x, GET_ACTOR_PTR(soundContexts[i].unk2A)->pos.y, GET_ACTOR_PTR(soundContexts[i].unk2A)->pos.z, soundContexts[i].unk2C, soundContexts[i].unk28, &pan, &vol);
                alSndpSetPan(sndp, pan);
                alSndpSetVol(sndp, vol);
            }
            else{
                if(soundContexts[i].unk28 != 0){
                    func_80008720(soundContexts[i].soundPosX, soundContexts[i].soundPosY, soundContexts[i].soundPosZ, soundContexts[i].unk2C, soundContexts[i].unk28, &pan, &vol);
                    alSndpSetPan(sndp, pan);
                    alSndpSetVol(sndp, vol);
                }
                else{
                    alSndpSetPan(sndp, soundContexts[i].pan);
                    alSndpSetVol(sndp, soundContexts[i].vol);                    
                }
            }
        }
        switch(soundContexts[i].unkC){
            case 0:
                break;
            case 1:
                alSndpStop(sndp);
                soundContexts[i].unkC = 0;
                break;
            case 2:
                alSndpStop(sndp);
                soundContexts[i].unkC = 3;
            case 3:
                if(alSndpGetState(sndp) == AL_STOPPED){
                    alSndpDeallocate(sndp, soundContexts[i].soundId);
                    D_800F08DC = ((ALInstrument*)((((ALInstrument**)D_800F08D8) + soundContexts[i].unk4)))->soundArray[0,0];
                    soundContexts[i].soundId = alSndpAllocate(sndp, D_800F08DC);

                    alSndpSetSound(sndp, soundContexts[i].soundId);
                    alSndpSetVol(sndp, soundContexts[i].vol);
                    alSndpSetPan(sndp, soundContexts[i].pan);
                    alSndpPlay(sndp);

                    soundContexts[i].unkC = 0;
                    soundContexts[i].unk6 = soundContexts[i].unk4;
                }
                break;
        }
    }
}
