#include "9320.h"
#include "7FC0.h"
#include "7310.h"
#include "audio.h"
#include "playseq.h"
#include "B4E0.h"

#include "libc/math.h"
#include "global.h"
#include "common.h"

u8 audioSoundProps[][2] = {
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_3 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 50, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_4 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 50, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 50, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 50, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 50, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 10, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 10, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 10, ZZ_AUDIO_SOUND_VOL_PROP_4 },
    { 10, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_5 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_4) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_5) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_4 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 30, ZZ_AUDIO_SOUND_VOL_PROP_5 },
    { 30, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 30, ZZ_AUDIO_SOUND_VOL_PROP_5 },
    { 30, ZZ_AUDIO_SOUND_VOL_PROP_5 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_5 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_10) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 20, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_8) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_6 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { ZZ_AUDIO_SOUND_VOL_PROP_5, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_4 },
    { 0, ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, ZZ_SEQ_PROPS_PRIORITY_SET(ZZ_AUDIO_SOUND_PRIORITY_PROP_5) | ZZ_AUDIO_SOUND_VOL_PROP_MAX },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

//todo RAD2DEG
void zzAudioSoundCalcValues(f32 x, f32 y, f32 z, s32 maxDist, s32 maxVol, ALPan* panPtr, s16* volPtr){
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
    
    if(dist > 0.0f && dist < maxDist){
        *volPtr = maxVol - (s32)((maxVol / (f32)maxDist) * dist);
        
    }
    else{
        *volPtr = 0;
    }
}

s32 zzAudioSoundPlaySoundImpl(s16 soundId, u8 soundCtxId){
    ALSndPlayer* seqp;
    u8 id = soundCtxId;
    
    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        s16 currentSoundPrio;
        s16 nextSoundPrio;
        
        seqp = soundContexts[id].soundPlayer;

        alSndpSetSound(seqp, soundContexts[id].soundId);
		
        currentSoundPrio = (u8)((audioSoundProps[soundContexts[id].sound][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_PRIORITY) >> 4);
        nextSoundPrio = (u8)((audioSoundProps[soundId][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_PRIORITY) >> 4);

        if((s16)alSndpGetState(seqp) == AL_PLAYING){
            s16 i;
            
            if (nextSoundPrio < currentSoundPrio) {
                for(i = 1; i < 6; i++){
                    ALSndPlayer* s = soundContexts[i].soundPlayer;
    
                    alSndpSetSound(s, soundContexts[i].soundId);
    
                    if(alSndpGetState(s) != AL_PLAYING){
                        soundContexts[i].sound = soundId;
                        
                        if(!(audioSoundProps[soundId][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_PITCH)){
                            soundContexts[i].pitch = 0.5f;
                        }
                        else{
                            soundContexts[i].pitch = 1.0f;
                        }
    
                        soundContexts[i].status = 2;
    
                        return i;
                    }

                }
                if (i == 6){
                    return -1;
                }
            } else {
                soundContexts[soundCtxId].sound = soundId;
                        
                if(!(audioSoundProps[soundId][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_PITCH)){
                    soundContexts[soundCtxId].pitch = 0.5f;
                }
                else{
                    soundContexts[soundCtxId].pitch = 1.0f;
                }

                soundContexts[soundCtxId].status = 2;
            }

        }
        else{
            if (seqp && seqp);
            soundContexts[soundCtxId].sound = soundId;
                    
            if(!(audioSoundProps[soundId][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_PITCH)){
                soundContexts[soundCtxId].pitch = 0.5f;
            }
            else{
                soundContexts[soundCtxId].pitch = 1.0f;
            }

            soundContexts[soundCtxId].status = 2;
        }
    }

    return soundCtxId;
}

void zzAudioSoundPlaySound(s16 soundId, u8 soundCtxId){
    s16 id;
    s16 vol;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = zzAudioSoundPlaySoundImpl(soundId, soundCtxId)) != -1){
            vol = audioSoundProps[soundId][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_VOL;
            vol <<= 0xC;
            
            soundContexts[id].pan = 64;
            soundContexts[id].vol = vol + 0xFFF;
            soundContexts[id].actorId = -1;
            soundContexts[id].maxVol = 0;
        }
    }
}

void zzAudioSoundPlaySoundAt(s16 soundId, u8 soundCtxId, s32 maxDist, s32 maxVol, f32 x, f32 y, f32 z){
    s16 id;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = zzAudioSoundPlaySoundImpl(soundId, soundCtxId)) != -1){
            zzAudioSoundCalcValues(x, y, z, maxDist, maxVol, &soundContexts[id].pan, &soundContexts[id].vol);

            soundContexts[id].soundPosX = x;
            soundContexts[id].soundPosY = y;
            soundContexts[id].soundPosZ = z;
            soundContexts[id].maxVol = maxVol;
            soundContexts[id].maxDist = maxDist;
        }
    }
} 

void zzAudioSoundPlaySoundActor(s16 soundId, u8 soundCtxId, s16 actorIdx){
    s16 id;

    if(soundId < D_800F08D8->soundCount && soundCtxId < 6){
        if((id = zzAudioSoundPlaySoundImpl(soundId, soundCtxId)) != -1){
            soundContexts[id].maxDist = 5000;
            soundContexts[id].maxVol = 0x7FFF;
            
            zzAudioSoundCalcValues(GET_ACTOR_PTR(actorIdx)->pos.x, GET_ACTOR_PTR(actorIdx)->pos.y, GET_ACTOR_PTR(actorIdx)->pos.z, soundContexts[id].maxDist, soundContexts[id].maxVol, &soundContexts[id].pan, &soundContexts[id].vol);
            soundContexts[id].actorId = actorIdx;
        }
    }
}

void zzAudioSoundSetVolZero(){
    s32 i;

    for(i = 1; i < 6; i++){
        zzAudioSoundSetVol(0, i);
    }
}

void zzAudioSoundSetVolFromProps(){
    s32 i;
    s16 vol;

    for(i = 1; i < 6; i++){
        vol = audioSoundProps[soundContexts[i].sound][ZZ_SEQ_PROPS_DATA] & ZZ_SEQ_PROPS_VOL;
        vol <<= 0xC;
        vol += 0xFFF;
        
        zzAudioSoundSetVol(vol, i);
    }
}

void zzAudioSoundSetMaxVol0(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].maxVol = arg0;
}

void zzAudioSoundSetMaxVol1(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].maxVol = arg0;
}

void zzAudioSoundSetMix(s16 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].baseMix = arg0;
}

void zzAudioSoundSetPitch(f32 arg0, u8 soundCtxId){
    soundContexts[soundCtxId].pitch = arg0;
}

void zzAudioSoundSetPan(s8 pan, u8 soundCtxId){
    soundContexts[soundCtxId].pan = pan;
}

void zzAudioSoundSetVol(s16 vol, u8 soundCtxId){
    soundContexts[soundCtxId].vol = vol;
}

void func_800090B0(u8 soundCtxId){
    if(soundCtxId < 6){
        soundContexts[soundCtxId].status = 1;
    }
}

void zzAudioSoundInitSound(){
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
        soundContexts[i].sound = 0;
        soundContexts[i].unk6 = 0;
        soundContexts[i].soundId = alSndpAllocate(sndp, D_800F08DC);
        soundContexts[i].status = 0;
        soundContexts[i].vol = 0x7FFF;
        soundContexts[i].pan = 64;
        soundContexts[i].baseMix = 0;
        soundContexts[i].unk14 = 5;
        soundContexts[i].pitch = 0.5f;
        soundContexts[i].soundPosX = 0.0f;
        soundContexts[i].soundPosY = 0.0f;
        soundContexts[i].soundPosZ = 0.0f;
        soundContexts[i].actorId = -1;
        soundContexts[i].maxVol = 0;
    }
}

void zzAudioSoundProc(){
    s16 vol;
    ALPan pan;
    u8 i;
    ALSndPlayer* sndp;
    ALInstrument* ins;
    
    for(i = 0; i < 6; i++){
        sndp = soundContexts[i].soundPlayer;

        alSndpSetSound(sndp, soundContexts[i].soundId);
        alSndpSetFXMix(sndp, soundContexts[i].baseMix + audioSoundProps[soundContexts[i].sound][ZZ_SEQ_PROPS_EFFECTS]);
        alSndpSetPitch(sndp, soundContexts[i].pitch);

        if(alSndpGetState(sndp) == AL_PLAYING){
            if(soundContexts[i].actorId != -1){
                zzAudioSoundCalcValues(GET_ACTOR_PTR(soundContexts[i].actorId)->pos.x, GET_ACTOR_PTR(soundContexts[i].actorId)->pos.y, GET_ACTOR_PTR(soundContexts[i].actorId)->pos.z, soundContexts[i].maxDist, soundContexts[i].maxVol, &pan, &vol);
                alSndpSetPan(sndp, pan);
                alSndpSetVol(sndp, vol);
            }
            else{
                if(soundContexts[i].maxVol != 0){
                    zzAudioSoundCalcValues(soundContexts[i].soundPosX, soundContexts[i].soundPosY, soundContexts[i].soundPosZ, soundContexts[i].maxDist, soundContexts[i].maxVol, &pan, &vol);
                    alSndpSetPan(sndp, pan);
                    alSndpSetVol(sndp, vol);
                }
                else{
                    alSndpSetPan(sndp, soundContexts[i].pan);
                    alSndpSetVol(sndp, soundContexts[i].vol);                    
                }
            }
        }
        switch(soundContexts[i].status){
            case 0:
                break;
            case 1:
                alSndpStop(sndp);
                soundContexts[i].status = 0;
                break;
            case 2:
                alSndpStop(sndp);
                soundContexts[i].status = 3;
            case 3:
                if(alSndpGetState(sndp) == AL_STOPPED){
                    alSndpDeallocate(sndp, soundContexts[i].soundId);
                    D_800F08DC = ((ALInstrument*)((((ALInstrument**)D_800F08D8) + soundContexts[i].sound)))->soundArray[0,0];
                    soundContexts[i].soundId = alSndpAllocate(sndp, D_800F08DC);

                    alSndpSetSound(sndp, soundContexts[i].soundId);
                    alSndpSetVol(sndp, soundContexts[i].vol);
                    alSndpSetPan(sndp, soundContexts[i].pan);
                    alSndpPlay(sndp);

                    soundContexts[i].status = 0;
                    soundContexts[i].unk6 = soundContexts[i].sound;
                }
                break;
        }
    }
}
