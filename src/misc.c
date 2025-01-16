#include "misc.h"

s32 args_d_option;

void parse_args(char* argv) {
    s32 argc = 1;
    char* buf[32];
    char** bufptr;
    char* arg;

    bufptr = &buf;

    if (argv == NULL || (*argv == 0)) {
        return;
    }

    arg = argv;

    while (*arg != 0) {
        while (*arg != 0 && *arg == ' ') {
            *arg = 0;
            arg += 1;
        }

        if (*arg != 0) {
            buf[argc] = arg;
            argc++;
        }

        while (*arg != 0 && *arg != ' ') {
            arg += 1;
        }
    }

    while (argc >= 2 && *bufptr[1] == '-') {
        switch ((bufptr[1][1])) {
            case 'd':
                args_d_option = TRUE;
                break;
        }
        argc--;
        bufptr++;
    }
}
