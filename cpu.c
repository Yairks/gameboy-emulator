#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "mem.h"
#include "opcodes.h"
#include <stdbool.h>

void run_command() {
    unsigned char command = memory[pc];

    if (command == 0xcb) {
        pc++;
        command = memory[pc];
        printf("About to execute extended opcode %x\n", memory[pc]);
        fflush(stdout);
        opcodes_ex[command]();
    }

    else {
        opcodes[command]();
    }

    pc++;
}

unsigned char get_immediate() {
    return memory[pc + 1];
}

/**
 * Gameboy is little endian, which is unfortunate,
 * because that's a really annoying format.
 * 
 * Returns two bytes (16 bits (one word)).
 */
unsigned short get_word() {
    printf("Getting a word\n");
    fflush(stdout);
    unsigned short pc_l = memory[pc + 1];
    unsigned short pc_h = memory[pc + 2];
    return (pc_h << 8) | pc_l;
}