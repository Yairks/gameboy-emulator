#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef enum {
    BLACK = 0,
    DARK_GRAY = 1,
    LIGHT_GRAY = 2,
    WHITE = 3
} Colors;

extern const Colors colors[4];

void init_display(void);
void blank_screen(void);
void draw_pixel(Colors color, unsigned x, unsigned y);
void quit_display(void);
void rerender_screen(void);

#endif