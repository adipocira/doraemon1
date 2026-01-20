#include "11F10.h"
#include "bitio.h"

void ExpandFile(struct TREE* tree, struct BIT_FILE* input, u8* output);

u32 seed;

s32 func_80011310(OSMesgQueue* mq){
    s32 i;
    u32 start;
    
    for(i = 0; i < 10; i++){
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    start = osGetCount();
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    
    return osGetCount() - start;
}

f32 func_8001139C(OSMesgQueue* mq){
    s32 i;
    u32 start;
    u32 end;
    f64 temp;
    f64 temp1;
    
    for(i = 0; i < 10; i++){
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    start = osGetCount();
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    end = osGetCount();

    if(osTvType == OS_TV_PAL){
        temp = (f32)(end - start) * 21.48;
        temp1 = temp / 1000.0;
    }
    else{
        temp = (end - start) * 21.91;
        temp1 = temp / 1000.0;        
    }

    return temp1;
}

u32 func_800114B0(void){
    seed = seed * 0x41C64E6D + 0x3039;

    return seed >> 0x10; 
}

void func_800114DC(u32 s){
    switch(s){
        case 0:
            seed = 0;
            break;
        case 1:
            seed = osGetCount();
            break;
        default:
            seed = s;
            break;
    }
}

u32 func_80011528(s32 s){
    if(s == 0){
        return func_800114B0();
    }
    else{
        func_800114DC(s);
        return func_800114B0();
    }
}

void func_80011564(s16* arg0, s16* arg1, f32* arg2, f32* arg3, u8* arg4, s16* arg5){
    *arg1-=1;

    if(*arg1 < 0){
        if(*arg4 != 0){
            *arg3 = -(*arg2*(f32) (*arg0 - 1));
        }
        else{
            *arg3 = 0.0f;
        }

        *arg4 ^= 1;
        *arg1 = *arg0;
    }
    else{
        *arg5 += (s16)*arg3;
        *arg3 += *arg2;
    }
}

void func_80011610(struct TREE* tree, u8* name, u8* out){
    ExpandFile(tree, OpenInputBitFile(name), out);
}
