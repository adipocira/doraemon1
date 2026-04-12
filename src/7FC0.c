#include "7FC0.h"
#include "7310.h"
#include "audio.h"
#include "playseq.h"
#include "segments.h"
#include "11DF0.h"

#include "common.h"
#include "macros.h"
#include "libc/math.h"

extern u16 D_8015A392;

void func_800073C0(s16 seq, u8 seqIdx){
    (void)"Audio Heap %d / %d \n";
    (void)"Audio Heap %d / %d %d\n";

    if(seq < D_800F08D0->seqCount && seqIdx < 2){
        seqContexts[seqIdx].unk0 = seq;
        seqContexts[seqIdx].unk4 = 2;
    }
}

void func_8000741C(u8 seqIdx){
    s32 i;
    s32 j;
    ALCSPlayer* seqp = seqContexts[seqIdx].seqPlayer;
    
    if(seqIdx < 2){
        for(i = 0, j = 0; i != 16; i++, j++){
            alCSPSetChlPan(seqp, i, seqp->chanState[j].pan);
        }
    }
}

void func_800074A8(u8 seqIdx){
    s32 i;
    s32 j;
    ALCSPlayer* seqp = seqContexts[seqIdx].seqPlayer;
    
    if(seqIdx < 2){
        for(i = 0, j = 0; i != 16; i++, j++){
            alCSPSetChlPan(seqp, i, 64);
        }
    }
}

void func_80007520(u16 arg0, u8 seqIdx){
    if(seqIdx < 2){
        seqContexts[seqIdx].unk4 = 8;
        seqContexts[seqIdx].unk1A = arg0;
        seqContexts[seqIdx].unk1C = seqContexts[seqIdx].maxSeqLength / arg0; 
        
    }
}

void func_800075A0(s16 seq, u16 arg1, u8 seqIdx){
    if(seqIdx < 2){
        func_800073C0(seq, seqIdx);
        seqContexts[seqIdx].maxSeqLength = 0;
        seqContexts[seqIdx].unk1A = arg1;
        seqContexts[seqIdx].unk1C = 0x4E20 / arg1;
    }
}

void func_80007648(u8 seqIdx){
    if(seqIdx < 2){
        seqContexts[seqIdx].unk4 = 1;
    }
}

void func_8000767C(u8 seqIdx){
    if(seqIdx < 2){
        seqContexts[seqIdx].unk4 = 5;
    }
}

void func_800076B0(u8 seqIdx){
    if(seqIdx < 2){
        seqContexts[seqIdx].unk4 = 7;
    }
}

void func_800076E4(s16 arg0, u8 seqIdx){
    if(seqIdx < 2){
        seqContexts[seqIdx].maxSeqLength = arg0; 
    }
}

void func_80007720(){
    u8 i;
    ALSeqpConfig* c;
    ALCSPlayer* seqp;
    ALCSeq* seq;
    void* dmaDataBuf;
    void* dmaMsgBuf;
    u32 len;
    
    for(i = 0; i < 2; i++){
        c = alHeapAlloc(&hp, 1, sizeof(ALSeqpConfig));
        
        c->maxVoices = MAX_VOICES;
        c->maxEvents = EVT_COUNT;
        c->maxChannels = MAX_CHANNELS;
        
        c->heap = &hp;
        
        c->initOsc = initsOsc;
        c->updateOsc = updateOsc;
        c->stopOsc = stopOsc;   

        c->debugFlags = NO_SOUND_ERR_MASK | NOTE_OFF_ERR_MASK | NO_VOICE_ERR_MASK;

        seqp = alHeapAlloc(&hp, 1, sizeof(ALCSPlayer));
        seq = alHeapAlloc(&hp, 1, sizeof(ALCSeq));
        dmaDataBuf = alHeapAlloc(&hp, 1, 0x2710);
        dmaMsgBuf = alHeapAlloc(&hp, 1, 0x18);
        
        seqContexts[i].unk0 = 0;
        seqContexts[i].unk2 = -1;
        seqContexts[i].unk4 = 0;
        seqContexts[i].seqPlayer = seqp;
        seqContexts[i].currentSequence = seq;
        seqContexts[i].dmaDataBuf = dmaDataBuf;
        seqContexts[i].maxSeqLength = 0x4E20;
        seqContexts[i].pan = 64;
        seqContexts[i].unk17 = 0;
        seqContexts[i].unk18 = 5;
        seqContexts[i].dmaMsgBuf = dmaMsgBuf;

        alCSPNew(seqp, c);
        alCSPSetBank(seqp, bankPtr->bankArray[0]);
    }

    D_800F08D0 = alHeapAlloc(&hp, 1, 4);
    romCopy(&D_7AC690, D_800F08D0, 4);
    
    len = 4+(D_800F08D0)->seqCount * sizeof(ALSeqData);
    D_800F08D0 = alHeapAlloc(&hp, 1, 4+(D_800F08D0)->seqCount * sizeof(ALSeqData));
    romCopy(&D_7AC690, D_800F08D0, len);
    alSeqFileNew(D_800F08D0, D_7AC690);
    osCreateMesgQueue(D_800F08A0, alHeapAlloc(&hp, 2, 4), ARRAY_COUNT(D_800F08A0));
}


void func_800079B0(u8 seqIdx){
    u32 offs;
    u32 len;
    s16 unk0 = seqContexts[seqIdx].unk0;

    offs = D_800F08D0->seqArray[unk0].offset;
    len = D_800F08D0->seqArray[unk0].len;
    
    if(len % 2){
        len++;
    }

    osInvalDCache(seqContexts[seqIdx].dmaDataBuf, len);
    osPiStartDma(seqContexts[seqIdx].dmaMsgBuf, OS_MESG_PRI_NORMAL, OS_READ, offs, seqContexts[seqIdx].dmaDataBuf, len, D_800F08A0);
    
    seqContexts[seqIdx].unk2 = seqContexts[seqIdx].unk0;
}

void func_80007A68(){
    u8 i;
    u8 j;
    OSMesg msg = NULL;
    ALCSeqMarker m;
    ALCSPlayer* seqp;
    
    static s32 D_800ABCF0 = 0;
    
    seqp = seqContexts[0].seqPlayer;
    
    if(D_8015A392 & 0x10 && D_800F3944->unk34 != 0){
        alEvtqPrintAllocEvts(&seqp->evtq);
        func_80007520(0x100, 0);
        D_800ABCF0 = 0;
    }
    if(D_8015A392 & 0x10 && D_800F3944->unk3C != 0 && seqContexts[0].unk4 == 0 && D_800ABCF0 == 0){
        func_800075A0(0, 0x100, 0);
        D_800ABCF0 = 1;
    }

    for(i = 0; i < 2; i++){
        
        seqp = seqContexts[i].seqPlayer;

        alCSPSetVol(seqp, seqContexts[i].maxSeqLength);

        switch(seqContexts[i].unk4){

            case 8:
                if(seqp->state == AL_PLAYING){
                    if(seqContexts[i].unk1A){
                        seqContexts[i].unk1A--;
                        seqContexts[i].maxSeqLength -= seqContexts[i].unk1C;
                    }
                    if(!seqContexts[i].unk1A){
                        alCSPStop(seqp);
                        seqContexts[i].unk4 = 0;
                    }
                }
                else{
                    seqContexts[i].unk1A = 0;
                    seqContexts[i].unk4 = 0;
                    seqContexts[i].maxSeqLength = 0x4E20;
                }
                break;
            case 9:
                if(seqp->state == AL_PLAYING){
                    if(seqContexts[i].unk1A){
                        seqContexts[i].unk1A--;
                        seqContexts[i].maxSeqLength += seqContexts[i].unk1C;

                        if(seqContexts[i].maxSeqLength > 0x7FFF){
                            seqContexts[i].maxSeqLength = 0x7FFF;
                        }
                    }
                    if(!seqContexts[i].unk1A){
                        seqContexts[i].unk4 = 0;
                    }
                }
                break;
            case 1:
                alCSPStop(seqp);
                seqContexts[i].unk4 = 0;
                break;            
            case 5:
                alCSPStop(seqp);
                seqContexts[i].unk4 = 6;
                break;
            case 7:
                alCSPPlay(seqp);
                seqContexts[i].unk4 = 0;
                break; 
            case 2:
                if(seqp->state != AL_STOPPED){
                    alCSPStop(seqp);
                    seqContexts[i].unk4 = 3;
                }
                else if(seqContexts[i].unk0 != seqContexts[i].unk2){
                    func_800079B0(i);
                    seqContexts[i].unk4 = 4;
                }
                else{
                    alCSeqNewMarker(seqContexts[i].currentSequence, &m, 0U);
                    alCSeqSetLoc(seqContexts[i].currentSequence, &m);
                    alCSPPlay(seqp);

                    if(seqContexts[i].unk1A){
                        seqContexts[i].unk4 = 9;
                    }
                    else{
                        seqContexts[i].unk4 = 0;
                    }
                }
                break;
            case 3:
                if(seqp->state == AL_STOPPED){
                    if(seqContexts[i].unk0 != seqContexts[i].unk2){
                        func_800079B0(i);
                        seqContexts[i].unk4 = 4;
                    }
                    else{
                        alCSeqNewMarker(seqContexts[i].currentSequence, &m, 0U);
                        alCSeqSetLoc(seqContexts[i].currentSequence, &m);
                        alCSPPlay(seqp);

                        if(seqContexts[i].unk1A){
                            seqContexts[i].unk4 = 9;
                        }
                        else{
                            seqContexts[i].unk4 = 0;
                        }
                    }
                }
                break;
            case 4:
                for(j = 0; j < 2; j++){
                    if(osRecvMesg(D_800F08A0, &msg, OS_MESG_NOBLOCK) != -1){
                        if(msg == seqContexts[i].dmaMsgBuf){
                            alCSeqNew(seqContexts[i].currentSequence, seqContexts[i].dmaDataBuf);
                            alCSPSetSeq(seqp, seqContexts[i].currentSequence);
                            alCSPPlay(seqp);

                            if(seqContexts[i].unk1A){
                                seqContexts[i].unk4 = 9;
                            }
                            else{
                                seqContexts[i].unk4 = 0;
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                break;
            case 0:
                break; 
        }
    }
}

f32 _depth2Cents(u8 depth)
{
    f32     x = 1.03099303;
    f32     cents = 1.0;

    while(depth)
    {
        if(depth & 1)
            cents *= x;
        x *= x;
        depth >>= 1;
    }

    return(cents);
}

ALMicroTime initsOsc(void** oscState,f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay){
    oscData* statePtr;
    ALMicroTime deltaTime = 0;
    
    if(freeOscStateList){
        statePtr = freeOscStateList;
        freeOscStateList = freeOscStateList->next;
        statePtr->type = oscType;
        *oscState = statePtr;
        deltaTime = oscDelay * 0x4000;

        switch(oscType) /* set the initVal */
        {
            case TREMELO_SIN:
                statePtr->curCount = 0;
                statePtr->maxCount = 259-oscRate; /* gives values 4-259 */
                statePtr->data.tsin.halfdepth = oscDepth >> 1;
                statePtr->data.tsin.baseVol = AL_VOL_FULL - statePtr->data.tsin.halfdepth;
                *initVal = (f32)statePtr->data.tsin.baseVol;
                break;

            case TREMELO_SQR:
                statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                statePtr->data.tsqr.loVal = AL_VOL_FULL-oscDepth;
                statePtr->data.tsqr.hiVal = AL_VOL_FULL;
                statePtr->data.tsqr.curVal = AL_VOL_FULL;
                *initVal = (f32)AL_VOL_FULL;
                break;

            case TREMELO_DSC_SAW:
                statePtr->maxCount = 256-oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;

            case TREMELO_ASC_SAW: 
                statePtr->maxCount = 256-oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL - oscDepth;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;           

            case VIBRATO_SIN:
                statePtr->data.vsin.depthcents = _depth2Cents(oscDepth);
                statePtr->curCount = 0;
                statePtr->maxCount = 259-oscRate; /* gives values 4-259 */
                *initVal = 1.0f; /* start at unity pitch */
                break;

            case VIBRATO_SQR:
                {
                    s32     cents;
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    statePtr->stateFlags = OSC_HIGH;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vsqr.loRatio = alCents2Ratio(-cents);
                    statePtr->data.vsqr.hiRatio = alCents2Ratio(cents);
                    *initVal = statePtr->data.vsqr.hiRatio;
                }
                break;
                    
            case VIBRATO_DSC_SAW:
                {
                    s32     cents;
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vdsaw.hicents = cents;
                    statePtr->data.vdsaw.centsrange = 2 * cents;
                    *initVal = alCents2Ratio(statePtr->data.vdsaw.hicents);
                }
                break;
                
            case VIBRATO_ASC_SAW:
                {
                    s32     cents;
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vasaw.locents = -cents;
                    statePtr->data.vasaw.centsrange = 2 * cents;
                    *initVal = alCents2Ratio(statePtr->data.vasaw.locents);
                }
                break;

        }
    }
    return(deltaTime);  /* if there are no oscStates, return zero, but if
                           oscState was available, return delay in usecs */
}

ALMicroTime updateOsc(void* oscState, f32* updateVal)
{
    f32             tmpFlt;
    oscData         *statePtr = (oscData*)oscState;
    ALMicroTime     deltaTime = AL_USEC_PER_FRAME; /* in this example callback every */
                                              /* frame, but could be at any interval */

    switch(statePtr->type)   /* perform update calculations */
    {
        case TREMELO_SIN:
            statePtr->curCount++;
            if(statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt*TWO_PI);
            tmpFlt = tmpFlt * (f32)statePtr->data.tsin.halfdepth;
            *updateVal = (f32)statePtr->data.tsin.baseVol + tmpFlt;
            break;

        case TREMELO_SQR:
            if(statePtr->stateFlags == OSC_HIGH)
            {
                *updateVal = (f32)statePtr->data.tsqr.loVal;
                statePtr->stateFlags = OSC_LOW;
            }
            else
            {
                *updateVal = (f32)statePtr->data.tsqr.hiVal;
                statePtr->stateFlags = OSC_HIGH;
            }
            deltaTime *= statePtr->maxCount;
            break;
            
        case TREMELO_DSC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol - tmpFlt;
            break;
            
        case TREMELO_ASC_SAW: 
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol + tmpFlt;
            break;

        case VIBRATO_SIN:
            /* calculate a sin value (from -1 to 1) and multiply it by depthcents.
               Then convert cents to ratio. */

            statePtr->curCount++;
            if(statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt*TWO_PI) * statePtr->data.vsin.depthcents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
            
        case VIBRATO_SQR:
            if(statePtr->stateFlags == OSC_HIGH)
            {
                statePtr->stateFlags = OSC_LOW;
                *updateVal = statePtr->data.vsqr.loRatio;
            }
            else
            {
                statePtr->stateFlags = OSC_HIGH;
                *updateVal = statePtr->data.vsqr.hiRatio;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case VIBRATO_DSC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vdsaw.centsrange;
            tmpFlt = (f32)statePtr->data.vdsaw.hicents - tmpFlt;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
            
        case VIBRATO_ASC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vasaw.centsrange;
            tmpFlt += (f32)statePtr->data.vasaw.locents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
    }
    
    return(deltaTime);
}


void stopOsc(void* oscState)
{
    ((oscData*)oscState)->next = freeOscStateList;
    freeOscStateList = (oscData*)oscState;
}
