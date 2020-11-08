#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cpu.h"
#include "mem.h"
#include "opcodes.h"
#include "graphics.h"

void run_command(void) {
    unsigned char command = memory[pc];

    if (command == 0xcb) {
        pc++;
        command = memory[pc];
        // printf("About to execute extended opcode %x\n", memory[pc]);
        opcodes_ex[command]();
    }

    else {
        opcodes[command]();
    }

    pc++;
}

unsigned char get_immediate(void) {
    return memory[pc + 1];
}

/**
 * Gameboy is little endian, which is unfortunate,
 * because that's a really annoying format.
 * 
 * Returns two bytes (16 bits (one word)).
 */
unsigned short get_word(void) {
    // printf("Getting a word\n");
    unsigned short pc_l = memory[pc + 1];
    unsigned short pc_h = memory[pc + 2];
    // printf("pc_l %x pc_h %x return %x\n", pc_l, pc_h, (pc_h << 8) | pc_l);

    return (pc_h << 8) | pc_l;
}