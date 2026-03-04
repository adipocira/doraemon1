#include "synsetpan.h"
#include "audio/synthInternals.h"

extern s32 D_800ABCD0;

void alSynSetPan(ALSynth *synth, ALVoice *v, u8 pan)
{
    ALParam  *update;
    ALFilter *f;

    if (v->pvoice) {

        /*
         * get new update struct from the free list
         */
        update = __allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * set offset and pan data
         */
        update->delta  = synth->paramSamples + v->pvoice->offset;
        update->type   = AL_FILTER_SET_PAN;
        update->data.i = D_800ABCD0 != 0 ? pan : 64;
        update->next   = 0;

        f = v->pvoice->channelKnob;
        (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);        
    }
}