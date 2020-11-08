#include <stdbool.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_timer.h" 
#include "SDL2/SDL_video.h"
#include "sdl_helper_functions.h"
#include "graphics.h"

const int SCALE = 3;
const int SCREEN_WIDTH = 160 * SCALE;
const int SCREEN_HEIGHT = 144 * SCALE;
const Colors colors[4] = { WHITE, LIGHT_GRAY, DARK_GRAY, BLACK };

static SDL_Window *win;
static SDL_Renderer *ren;
static SDL_Texture *background;

void blank_screen(void) {
        //First clear the renderer
        SDL_RenderClear(ren);
        int b_w, b_h;
        SDL_QueryTexture(background, NULL, NULL, &b_w, &b_h);
        renderTexture(background, ren, 0, 0);
}

void draw_pixel(Colors color, unsigned x, unsigned y) {
    unsigned display_color = 64 * color - 1;
    SDL_SetRenderDrawColor(ren, display_color, display_color, display_color, 255);

    for (int row = 0; row < SCALE; row++) {
        for (int col = 0; col < SCALE; col++) {
            SDL_RenderDrawPoint(ren, x * SCALE + col, y * SCALE + row);
        }
    }
}

void rerender_screen(void) {
    SDL_RenderPresent(ren);
}

void init_display(void) {
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { 
        log_sdl_error(stdout, "SDL_Init");
        return;
    }

    win = SDL_CreateWindow("Hello World!", 
                                        100, 
                                        100, 
                                        SCREEN_WIDTH, 
                                        SCREEN_HEIGHT, 
                                        SDL_WINDOW_SHOWN);
    if (win == NULL) {
        log_sdl_error(stdout, "CreateWindow");
        SDL_Quit();
        return;
    }

    ren = SDL_CreateRenderer(win, 
                                            -1, 
                                            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        log_sdl_error(stdout, "CreateRenderer");
        SDL_Quit();
        return;
    }

    char *background_src = "/home/yair/Documents/fall-2020/throwaway/sdl_practice/blank_background.bmp";
    background = loadTexture(background_src, ren);
    if (background == NULL) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_DestroyTexture(background);
        log_sdl_error(stdout, "LoadBMP");
        SDL_Quit();
        return;
    }

    blank_screen();
}

void quit_display(void) {
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}