#include <stdio.h>
#include "mem.h"
#include "cpu.h"
#include "opcodes.h"
#include "graphics.h"
#include "gpu.h"
#include "SDL2/SDL.h"


int main(int argc, char **argv) {
    // This file has the Gameboy bootstrap ROM. 256 bytes.
    FILE *rom = fopen("DMG_ROM.bin", "rb");
    if (rom == NULL) {
        printf("fopen failed\n");
        return 1;
    }

    fread(memory, 1, 0xFFFF, rom);
    unsigned char scrolling_graphic[] = {
        0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
        0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
        0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
    };

    for (int i = 0; i < 48; i++) {
        memory[0x104 + i] = scrolling_graphic[i];
    }

    memory[LCDC] = 0x91;
    
    fclose(rom);

    // The opcodes are a jump table that runs the instructions
    init_opcodes();
    init_display();
    init_gpu();

    pc = 0;

    printf("Bootstrap memory: \n");
    for (int i = 0; i < 400; i++) {
        printf("%x ", memory[i]);
    }

    printf("\n");

    // Execute some instructions.
    int i = 0;
    SDL_Event e;
    bool quit = false;
    while (pc < 0xFF && i < 50000000 && !quit) {
        // printf("%d ", i);
        // printf("memory[0x%x] = %x\t", pc, memory[pc]);
        // printf("stack = 0x%02x%02x\t", memory[registers.sp+1], memory[registers.sp]);
        // printf("Registers: a=%x b=%x c=%x d=%x e=%x f=%x h=%x l=%x\n", registers.a, registers.b, registers.c, registers.d, registers.e, registers.f, registers.h, registers.l);
        // printf("Flags: c=%x h=%x n=%x z=%x\n", flags.c, flags.h, flags.n, flags.z);
        run_command();
        i++;

        perform_draw();

        while (SDL_PollEvent((&e)))
            if (e.type == SDL_QUIT)
                quit = true;
    }

    printf("finished commanding\n");

    FILE *new_mem = fopen("memory.bin", "wb");
    fwrite(memory, 1, 0xFFFF, new_mem);

    quit_display();
    printf("Everything worked I guess\n");
}