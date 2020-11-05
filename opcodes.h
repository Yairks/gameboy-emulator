#ifndef OPCODES_H
#define OPCODES_H

// Put in an opcode, get out a function pointer!
void (*opcodes[0xFFF])();
void (*opcodes_ex[0xFFF])();

void init_opcodes(void);

#endif