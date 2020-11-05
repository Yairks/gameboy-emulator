#ifndef CPU_H
#define CPU_H

#include <stdbool.h>

struct Registers {
    struct {
        union {
            struct{
                unsigned char f;
                unsigned char a;
            };
            unsigned short af;
        };
    };

    struct {
        union {
            struct {
                unsigned char c;
                unsigned char b;
            };
            unsigned short bc;
        };
    };

    struct {
        union {
            struct {
                unsigned char e;
                unsigned char d;
            };
            unsigned short de;
        };
    };

    struct {
        union {
            struct {
                unsigned char l;
                unsigned char h;
            };
            unsigned short hl;
        };
    };

    unsigned short sp;
    // unsigned short pc;
} registers;

struct Flags {
    bool z;
    bool n;
    bool c;
    bool h;
} flags;

bool interrupts_enabled;

unsigned int pc;

void run_command();
unsigned char get_immediate();
unsigned short get_word();

#endif