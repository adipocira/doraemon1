#include "audio.h"
#include "segments.h"

extern u8 audioHeap[AUDIO_HEAP_SIZE];

ALHeap hp;
ALBankFile    *bankPtr;
ALBankFile    *bank2Ptr;
ALSynConfig c;


void initAudio(void) 
{
    u32           len;
    amConfig      amc; 
    
    alHeapInit(&hp, audioHeap, sizeof(audioHeap));    

    /*
     * Load the bank file from ROM
     */
    len = SEGMENT_SIZE(_bankSegmentRom);
    bankPtr = alHeapAlloc(&hp, 1, len);
    romCopy(_bankSegmentRom, (char *)bankPtr, len);
    
    alBnkfNew(bankPtr, (u8 *) _tableSegmentRom);

    /*
     * Load the bank file from ROM
     */
    len = SEGMENT_SIZE(_bank2SegmentRom);
    bank2Ptr = alHeapAlloc(&hp, 1, len);
    romCopy(_bank2SegmentRom, (char *)bank2Ptr, len);
    
    alBnkfNew(bank2Ptr, (u8 *) _table2SegmentRom);

    /*
     * Create the Audio Manager
     */
    c.maxVVoices = MAX_VOICES;
    c.maxPVoices = MAX_VOICES;
    c.maxUpdates = MAX_UPDATES;
    c.dmaproc    = 0;                  /* audio mgr will fill this in */
    c.fxType	 = AL_FX_SMALLROOM;
    c.outputRate = 0;                  /* audio mgr will fill this in */
    c.heap       = &hp;
    
    amc.outputRate = OUTPUT_RATE;
    amc.framesPerField = NUM_FIELDS;
    amc.maxACMDSize = MAX_RSP_CMDS;
 
    amCreateAudioMgr(&c, AUDIO_PRIORITY, &amc);
}
