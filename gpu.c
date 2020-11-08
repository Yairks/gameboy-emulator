#include <stdio.h>
#include "graphics.h"
#include "mem.h"
#include "gpu.h"

const unsigned LX_TOTAL = 170; // Kinda arbitrary, but no one would tell me how long it really is
const unsigned LY_TOTAL = 153;
static unsigned lx;

void init_gpu(void) {
    lx = 0;
    memory[LY] = 0;
}

void perform_draw(void) {
    // if (lx == 0 && memory[LY] == 0)
    //     blank_screen();
    
    if (lx < 160 && memory[LY] < 144) {
        memory[STAT] = 2;

        unsigned display = memory[LCDC] & 0x80;
        // unsigned window_tile_map_select = memory[LCDC] & 0x40;
        // unsigned window_display = memory[LCDC] & 0x20;
        unsigned bg_window_tile_data_select = memory[LCDC] & 0x10;
        unsigned bg_tile_map_display_select = memory[LCDC] & 0x08;

        if (display) {
            unsigned bg_tile_map_select_memory;

            unsigned tile_loc_x = lx / 8 + memory[SCX];
            unsigned tile_loc_y = memory[LY] / 8 + memory[SCY];
            if (tile_loc_x > 160)
                tile_loc_x -= 160;
            if (tile_loc_y > 144)
                tile_loc_y -= 144;

            unsigned tile_loc = tile_loc_x + tile_loc_y * 32;

            if (bg_tile_map_display_select) {
                // Unsigned add -> 0x9C00-0x9FFF
                bg_tile_map_select_memory = 0x9C00;
            }
            else {
                // Signed add -> 0x9800-0x9BFF
                bg_tile_map_select_memory = 0x9800;
            }

            unsigned char tile = memory[bg_tile_map_select_memory + tile_loc];
            unsigned seek;

            if (bg_window_tile_data_select) {
                /* Unsigned add. Good, simple stuff. */
                seek = 0x8000 + tile * 16;
            }
            else { 
                /* Signed add AND different memory location. */
                if (tile & 0x80) {
                    seek = 0x9000 - ((tile & (~0x80)) * 16);
                    
                }
                else {
                    seek = 0x9000 + tile * 16;
                }
            }

            unsigned char pixels[8][8];
            for (unsigned row = 0; row < 8; row++) {
                unsigned char byte_l = memory[seek + 2 * row];
                unsigned char byte_h = memory[seek + 1 + 2 * row];

                for (unsigned col = 0; col < 8; col++) {
                    pixels[row][col] = ((byte_l >> col)&1) | (((byte_h >> col)&1) << 1);
                }
            }

            draw_pixel(pixels[memory[LY] % 8][7-lx % 8], lx, memory[LY]);
        }
    }

    else if (memory[LY] >= 144) {
        memory[STAT] = 0;
    }

    else if (lx >= 160) {
        memory[STAT] = 1;
    }

    lx++;

    if (lx >= LX_TOTAL) {
        lx = 0;
        memory[LY]++;
    }
    if (memory[LY] >= LY_TOTAL) {
        rerender_screen();
        lx = 0;
        memory[LY] = 0;
    }
}