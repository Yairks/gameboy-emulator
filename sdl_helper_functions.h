#ifndef SDL_HELPER_FUNCTIONS_H
#define SDL_HELPER_FUNCTIONS_H

#include <stdio.h>
#include <SDL2/SDL.h>

void log_sdl_error(FILE *file, const char *msg);

/**
 * Loads a BMP image into a texture on the rendering device
 */
SDL_Texture* loadTexture(const char *filename, SDL_Renderer *ren);

/**
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
 * the texture's width and height.
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

#endif