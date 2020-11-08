#ifndef MEM_H
#define MEM_H

/**
 * Register for reading joy pad info and determining system type 
 */
#define P1 0xFF00 
#define P15 0x20
#define P14 0x10
#define P13 0x08
#define P12 0x04
#define P11 0x02
#define P10 0x01

/**
 * Serial transfer data
 */
#define SB 0xFF01
#define SC 0xFF02

/**
 * Divider Register (R/W)
 * Incremented 16384 times a second.
 */
#define DIV 0xFF04

/**
 * Timer counter
 */
#define TIMA 0xFF05

/**
 * Timer Modulo
 */
#define TMA 0xFF06

/**
 * Timer Control
 */
#define TAC 0xFF07

/**
 * Interrupt Flag
 */
#define IF 0xFF0F

/**
 * Sound Mode 1 register, sweep register
 */
#define NR_10 0xFF10

/**
 * Sound Mode 1 register, sound length/wave pattern duty
 */
#define NR_11 0xFF11

/**
 * Sound Mode 1 register, Envelope
 */
#define NR_12 0xFF12

/**
 * Sound Mode 1 register, Frequency lo
 */
#define NR_13 0xFF13

/**
 * Sound Mode 1 register, Frequency hi
 */
#define NR_14 0xFF14

/**
 * Sound Mode 2 register, sound length/wave pattern duty
 */
#define NR_21 0xFF16

/**
 * Sound Mode 2 register, Envelope
 */
#define NR_22 0xFF17

/**
 * Sound Mode 2 register, Frequency lo
 */
#define NR_23 0xFF18

/**
 * Sound Mode 2 register, Frequency hi
 */
#define NR_24 0xFF19

/**
 * Sound Mode 3 register, sound on/off
 */
#define NR_30 0xFF1A

/**
 * Sound Mode 3 register, sound length
 */
#define NR_31 0xFF1B

/**
 * Sound Mode 3 register, Select output
 */
#define NR_32 0xFF1C

/**
 * Sound Mode 3 register, Frequency's lower data
 */
#define NR_33 0xFF1D

/**
 * Sound Mode 3 register, Frequency's higher data
 */
#define NR_34 0xFF20

/**
 * Sound Mode 4 register, sound length
 */
#define NR_41 0xFF21

/**
 * Sound Mode 4 register, Select output
 */
#define NR_42 0xFF22

/**
 * Sound Mode 4 register, Frequency's lower data
 */
#define NR_43 0xFF23

/**
 * Sound Mode 4 register, Frequency's higher data
 */
#define NR_44 0xFF24

/**
 * Selection of Sound output terminal
 */
#define NR_51 0xFF25

/**
 * Sound on/off
 */
#define NR_52 0xFF26

/**
 * Waveform storage for arbitrary sound data
 * This points to 16 unsigned chars, from FF30 to FF35.
 * The data is stored as 32 4-bit samples.
 */
#define WAVE_PATTERN_RAM 0xFF30

/**
 * LCD Control
 */
#define LCDC                            0xFF40
#define LCD_CONTROL_OPERATION           0x80
#define WINDOW_TILE_MAP_DISPLAY_SELECT  0x40
#define WINDOW_DISPLAY                  0x20
#define BG_WINDOW_TILE_DATA_SELECT      0x10
#define BG_TILE_MAP_DISPLAY_SELECT      0x08
#define OBJ_SIZE                        0x04
#define OBJ_DISPLAY                     0x02
#define BG_WINDOW_DISPLAY               0x01

/**
 * LCDC Status
 */
#define STAT 0xFF41

/**
 * Scroll Y
 */
#define SCY 0xFF42

/**
 * Scroll X
 */
#define SCX 0xFF43

/**
 * LCDC Y-Coordinate
 */
#define LY 0xFF44

/**
 * LY Compare
 */
#define LYC 0xFF45

/**
 * DMA Transfer and Start Address
 */
#define DMA 0xFF45

/**
 * BG and Window Palette Data
 */
#define BGP 0xFF47

/**
 * Object Palette 0 Data
 */
#define OBP0 0xFF48

/**
 * Object Palette 1 Data
 */
#define OBP1 0xFF49

/**
 * Window Y Position
 */
#define WY 0xFF4A

/**
 * Window X Position
 */
#define WX 0xFF4B

/**
 * Interrupt Enable
 */
#define IE 0xFFFF

unsigned char memory[0xFFFF];



#endif