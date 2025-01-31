#include "bitio.h"
#include "ultra64.h"

#define EOF -1

int getc(u8** file);
int putc(int ch, u8** file);
void memmove(void* dst, const void* src, s32 len);
void fatal_error(const char* fmt);


BIT_FILE bit_file;

BIT_FILE* OpenInputBitFile(u8* file) {
    bit_file.file = file;
    bit_file.rack = 0;
    bit_file.mask = 0x80;

    return &bit_file;
}

int InputBit(BIT_FILE* bit_file) {
    int value;

    if (bit_file->mask == 0x80) {
        bit_file->rack = getc((char**)bit_file->file);

        if (bit_file->rack == EOF) {
            fatal_error("Fatal error in InputBit!\n");
        }
    }

    value = bit_file->rack & bit_file->mask;
    bit_file->mask >>= 1;

    if (bit_file->mask == 0) {
        bit_file->mask = 0x80;
    }

    return (value ? 1 : 0);
}

u32 InputBits(BIT_FILE* bit_file, int bit_count) {
    u32 mask;
    u32 return_value;

    mask = 1L << (bit_count - 1);
    return_value = 0;

    while (mask != 0) {
        if (bit_file->mask == 0x80) {
            bit_file->rack = getc((char**)bit_file->file);

            if (bit_file->rack == EOF) {
                fatal_error("Fatal error in InputBit!\n");
            }
        }
        if (bit_file->rack & bit_file->mask) {
            return_value |= mask;
        }

        mask >>= 1;
        bit_file->mask >>= 1;

        if (bit_file->mask == 0) {
            bit_file->mask = 0x80;
        }
    }
    return (return_value);
}

int getc(u8** file) {
    char c = *(*file)++;

    return c;
}

int putc(int ch, u8** file) {
    char cPtr[1];

    cPtr[0] = ch;
    *(*file)++ = ch;

    return ch;
}

void memmove(void* dst, const void* src, s32 len) {
    char* s = src;
    char* d = dst;
    s32 i = 0;

    while (i < len) {
        *d++ = *s++;
        i++;
    }
}


void fatal_error(const char* fmt) {
}

