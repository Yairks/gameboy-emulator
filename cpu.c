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

unsigned short get_word() {
    printf("Getting a word\n");
    fflush(stdout);
    unsigned short pc_l = memory[pc + 1];
    unsigned short pc_h = memory[pc + 2];
    return (pc_h << 8) | pc_l;
}

// unsigned char read_byte(FILE *silver, long long unsigned *pc);

// bool interrupts = true;

// int main(void) {
//     long long unsigned pc = 0;
//     FILE *silver_file = fopen("pokesilver.gbc", "rb");    
//     unsigned char command = 0;

//     fseek(silver_file, 0, SEEK_END);
//     unsigned long long fsize = ftell(silver_file);
//     fseek(silver_file, 0, SEEK_SET);

//     unsigned char *silver = malloc(fsize + 1);
//     fread(silver, 1, fsize, silver_file);
//     fclose(silver_file);
//     silver[fsize] = 0;

//     for (int i = 0; i < 20; i++) {
//         command = silver[pc++];

//         switch (command) {
//             case 0x00:
//                 printf("NOP\n");
//                 break;
//             case 0x28:
//                 printf("Instruction JR\n");
//                 if (registers.f & ZERO_FLAG) {
//                     pc += silver[pc];
//                     printf("Jumping to 0x%llx\n", pc);
//                 }
//             case 0xC3:
//                 printf("Instruction JP\n");
//                 unsigned short jump_address = 0;
//                 jump_address = silver[pc++];
//                 jump_address |= ((short) silver[pc++]) << 8;
//                 printf("Jumping to address 0x%x\n", jump_address);
//                 pc = jump_address;
//                 break;
//             case 0xF3:
//                 printf("Instruction DI\n");
//                 interrupts = false;
//                 break;
//             case 0xFE:
//                 printf("Instruction CP\n");
//                 unsigned char immediate = silver[pc++];
//                 registers.f |= SUBTRACT_FLAG;

//                 if (registers.a == immediate)
//                     registers.f |= ZERO_FLAG;
//                 else if (((registers.a&0xF) < (immediate&0xF)))
//                     registers.f |= HALF_CARRY_FLAG;
//                 else if (registers.a < immediate)
//                     registers.f |= CARRY_FLAG;
//                 break;
//             case 0xBE:
//                 printf("Instruction CP\n");
//                 registers.f |= SUBTRACT_FLAG;

//                 if (registers.a == registers.hl)
//                     registers.f |= ZERO_FLAG;
//                 else if (((registers.a&0xF) < (registers.hl&0xF)))
//                     registers.f |= HALF_CARRY_FLAG;
//                 else if (registers.a < registers.hl)
//                     registers.f |= CARRY_FLAG;
//                 break;
//             default:
//                 printf("Undefined command 0x%x!\n", command);
//                 return 0;
//         }
        
//     }
// }

// unsigned char read_byte(FILE *silver, long long unsigned *address) {
//     unsigned char byte;
//     fread(&byte, 1, 1, silver);
//     (*pc)++;
//     return byte;
// }