#include <stdio.h>
#include "mem.h"
#include "cpu.h"
#include "opcodes.h"

int main(int argc, char **argv) {
    // This file has the Gameboy bootstrap ROM. 256 bytes.
    FILE *rom = fopen("DMG_ROM.bin", "rb");
    if (rom == NULL) {
        printf("fopen failed\n");
        return 1;
    }

    fread(memory, 1, 0xFFFF, rom);
    fclose(rom);

    // The opcodes are a jump table that runs the instructions
    init_opcodes();

    pc = 0;

    printf("Bootstrap memory: \n");
    for (int i = 0; i < 257; i++) {
        printf("%x ", memory[i]);
    }

    printf("\n");

    // Execute 100 instructions.
    for (int i = 0; i < 100; i++) {
        printf("memory[0x%x] = %x\t", pc, memory[pc]);
        printf("stack is 0x%02x%02x\n", stack[registers.sp-1], stack[registers.sp]);
        run_command();
    }
    printf("Everything worked I guess\n");
}