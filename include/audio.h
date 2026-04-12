#ifndef AUDIO_H
#define AUDIO_H

#include "ultra64.h"
#include <PR/sched.h>

#define  TREMELO_SIN        1
#define  TREMELO_SQR        2
#define  TREMELO_DSC_SAW    3
#define  TREMELO_ASC_SAW    4
#define  VIBRATO_SIN        128
#define  VIBRATO_SQR        129
#define  VIBRATO_DSC_SAW    130
#define  VIBRATO_ASC_SAW    131

#define  OSC_HIGH   0
#define  OSC_LOW    1
#define  TWO_PI     6.2831853

#define AUDIO_PRIORITY          90

#define MAX_UPDATES             128
#define MAX_EVENTS              32
#define AUDIO_HEAP_SIZE         260000

#define MAX_VOICES              30
#define EXTRA_SAMPLES           80
#define NUM_OUTPUT_BUFFERS      3      /* Need three of these */
#define OUTPUT_RATE             22050
#define MAX_MESGS               20
#define QUIT_MSG                10

#define DMA_BUFFER_LENGTH       0x400  /* Larger buffers result in fewer DMA' but more  */
                                       /* memory being used.  */


#define NUM_ACMD_LISTS          2      /* two lists used by this example                */
#define MAX_RSP_CMDS            4096   /* max number of commands in any command list.   */
                                       /* Mainly dependent on sequences used            */

#define NUM_DMA_BUFFERS         30     /* max number of dma buffers needed.             */
                                       /* Mainly dependent on sequences and sfx's       */

#define NUM_DMA_MESSAGES        40     /* The maximum number of DMAs any one frame can  */
                                       /* have.                                         */

#define FRAME_LAG               1      /* The number of frames to keep a dma buffer.    */
                                       /* Increasing this number causes buffers to not  */
                                       /* be deleted as quickly. This results in fewer  */
                                       /* DMA's but you need more buffers.              */


#define AUDIO_STACKSIZE         0x2000

#define MAX_SEQ_LENGTH  20000

#define NUM_FIELDS      1 


typedef struct {
    u32       outputRate;
    u32       framesPerField;
    u32       unk8;
    u32       maxACMDSize;
} amConfig;


void    amCreateAudioMgr(ALSynConfig* c, OSPri priority, amConfig* amc);

extern ALHeap hp;
extern ALBankFile* bankPtr;
extern ALBankFile* bank2Ptr;

#endif
