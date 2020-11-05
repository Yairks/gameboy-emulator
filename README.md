# Gameboy Emulator
I'm making a simple Gameboy emulator, because I really like low level stuff, and because it's good C practice.  
I've implemented all the CPU instructions, and they seem like they work. At least, the CPU does normal things when it runs the bootstrap ROM.  

To compile this program, run  
`gcc cpu.c opcodes.c main.c -o gameboy`  
and then run it with `./gameboy`

This code has only been tested for Linux. If you're on Mac, Windows, or (gasp) WSL, then good luck.