#include "11DF0.h"
#include "global.h"

OSMesg dmaMessageBuf;
OSMesgQueue dmaMessageQ;

void romCopy(const char *src, const char *dest, const int len){
    OSIoMesg dmaIoMesgBuf;
    OSMesg dummyMesg;

    osInvalDCache((void *)dest, (s32) len);
    osPiStartDma(&dmaIoMesgBuf, OS_MESG_PRI_NORMAL, OS_READ,
                 (u32)src, (void *)dest, (u32)len, &dmaMessageQ);
    (void) osRecvMesg(&dmaMessageQ, &dummyMesg, OS_MESG_BLOCK);
}

s32 func_80011264(const u32* src, const u32* dst, s32 len){
    s32 i;
    
    osInvalDCache((void*) dst, len * sizeof(u32*));

    for(i = 0; i != len; i++){
        osPiReadIo(src++, dst++);
    }

    return i;
}

u8 func_800112DC() {
    if ((D_800E69C0.unk1D[*D_800E69C0.unk1D])== 0) {
        return *D_800E69C0.unk1D; 
    }
    else{
        return 0xFF;
    }
    
}
