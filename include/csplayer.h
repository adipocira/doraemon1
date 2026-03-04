#ifndef _csplayer_H
#define _csplayer_H

#include "ultra64.h"

void alCSPNew(ALCSPlayer *seqp, ALSeqpConfig *c);
ALMicroTime __CSPVoiceHandler(void *node);
void __CSPPostNextSeqEvent(ALCSPlayer *seqp);
void __CSPHandleNextSeqEvent(ALCSPlayer *seqp);
void __CSPHandleMIDIMsg(ALCSPlayer *seqp, ALEvent *event);
void __CSPHandleMetaMsg(ALCSPlayer *seqp, ALEvent *event);
void  __CSPRepostEvent(ALEventQueue *evtq, ALEventListItem *item);
void __setUsptFromTempo (ALCSPlayer *seqp, f32 tempo);

#endif
