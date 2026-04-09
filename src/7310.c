#include "7310.h"
#include "audio.h"
#include "playseq.h"
#include "segments.h"
#include "macros.h"

#include "common.h"

#define PRINTF      rmonPrintf

SeqContext seqContexts[2];
OSMesgQueue D_800F08A0[2];
ALSeqFile* D_800F08D0;
u8 D_800F08D8[0x8];
SoundContext soundContexts[6];

extern u16 D_8015A392;

void alEvtqPrintEvtQueue(ALEventQueue *evtq) 
{
    s32 count1 = 0;
    s32 count2 = 0;
    ALLink *node;
    ALEventListItem *item;
    
    /* count free events */
    for (node = evtq->freeList.next; node != 0; node= node->next) {
        count1++;
    }

    PRINTF("----- Allocated Events -----\n");
    for (node = evtq->allocList.next; node != 0; node= node->next) {
        item = (ALEventListItem *)node;
        
        PRINTF("\tdelta: %d\ttype %d\n", item->delta, item->evt.type);
        count2++;
    }
    PRINTF("\n");

    PRINTF("free  events\t %d\n", count1);
    PRINTF("alloc events\t %d\n", count2);
    PRINTF("total events\t %d\n", count1 + count2);
}

void
alEvtqPrintAllocEvts(ALEventQueue *evtq) 
{
    ALLink *node;
    ALEventListItem *item;
    ALMicroTime itemTime = 0;
    char str[32];

    PRINTF("----- Allocated Events -----\n");
    for (node = evtq->allocList.next; node != 0; node= node->next)
    {
        item = (ALEventListItem *)node;
        itemTime += item->delta;

        PRINTF("\tdelta: %d\tabs: %d\t", item->delta, itemTime);

	switch (item->evt.type)
	{
	    case AL_NOTE_END_EVT:
	        PRINTF("NOTE_END\tvox: %x\n", item->evt.msg.note.voice);
	    break;

	    case AL_SEQP_MIDI_EVT:
		PRINTF("SEQP_MIDI\t%s\n", MidiStatus2Str(item->evt.msg.midi.status & AL_MIDI_StatusMask, str));
	    break;

	    case AL_SEQP_PRIORITY_EVT:
		PRINTF("SEQP_PRIORITY\n");
	    break;

	    default:
	        PRINTF("type: %d\n", item->evt.type);
	    break;
	}

    }
    PRINTF("\n");

}

s16 func_80006924(){
    u16 i;
    u16 ret = 0;

    (void)"chk !%d\n";

    for(i = 0; i < ARRAY_COUNT(seqContexts); i++){
        ALCSPlayer* seqPlyPtr = seqContexts[i].seqPlayer;

        if((seqPlyPtr)->state != AL_STOPPED){
            alCSPStop(seqPlyPtr);
            ret++;
        }
    }
    
    for(i = 0; i < ARRAY_COUNT(soundContexts); i++){
        ALSndPlayer* soundPlyPtr = soundContexts[i].soundPlayer;

        if(alSndpGetState(soundPlyPtr) != AL_STOPPED){
            alSndpStop(soundPlyPtr);
            ret++;
        }
    }
    return ret;
}

char *
MidiStatus2Str (char status, char *str)
{
    switch (status)
    {
        case AL_MIDI_NoteOn:
	    sprintf(str, "note on");
	break;

        case AL_MIDI_NoteOff:
	    sprintf(str, "note off");
	break;

        default:
	    sprintf(str, "status:%d", status);
	break;
    }

    return str;
}
