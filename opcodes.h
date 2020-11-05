/**
 * DON'T look at opcodes.c. (Okay, maybe take a peek.)
 * This file creates two jump tables, opcodes and opcodes_ex.
 * Each of them takes in an opcode (say 0x4F) and returns a 
 * function pointer. So the CPU, which will be doing the 
 * calling, looks like opcodes[0x4F]()
 * 
 * opcodes_ex is called when the first instruction read is 0xCB.
 * That tells the CPU to read the following instruction as an
 * opcode extension.
 */

#ifndef OPCODES_H
#define OPCODES_H

// Put in an opcode, get out a function pointer!
void (*opcodes[0x100])();
void (*opcodes_ex[0x100])();

/**
 * Call before doing anything else. Yes, I know that this should
 * be done at compile time. Sue me.
 */
void init_opcodes(void);

#endif