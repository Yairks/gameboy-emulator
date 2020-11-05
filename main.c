#include <stdio.h>
#include "mem.h"
#include "cpu.h"
#include "opcodes.h"

int main(int argc, char **argv) {
    printf("Hello!\n");
    FILE *rom = fopen("pokesilver.gbc", "rb");
    if (rom == NULL) {
        printf("fopen failed\n");
        return 1;
    }

    // fseek(rom, 0, SEEK_END);
    // unsigned fsize = ftell(rom);
    // fseek(rom, 0, SEEK_SET);
    fread(memory, 1, 0xFFFF, rom);
    fclose(rom);

    init_opcodes();

    pc = 0;
    printf("Some of the memory: \n");
    for (int i = 0; i < 257; i++) {
        printf("%x ", memory[i]);
    }

    printf("\n");

    for (int i = 0; i < 10000; i++) {
        printf("memory[0x%x] = %x\t", pc, memory[pc]);
        printf("stack is 0x%02x%02x\n", stack[registers.sp-1], stack[registers.sp]);
        run_command();
    }
    printf("Everything worked I guess\n");

    printf("Some of the memory: \n");
    for (int i = 0; i < 257; i++) {
        printf("%x ", memory[i]);
    }

    printf("\n");
}