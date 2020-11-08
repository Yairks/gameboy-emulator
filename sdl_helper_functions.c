#include <stdio.h>
#include "sdl_helper_functions.h"

void log_sdl_error(FILE *file, const char *msg) {
    if (file == NULL || msg == NULL)
        return;
    
    fprintf(file, "%s error: %s\n", msg, SDL_GetError());
}

/**
 * Loads a BMP image into a texture on the rendering device
 */
SDL_Texture* loadTexture(const char *filename, SDL_Renderer *ren) {
    SDL_Texture *texture;
    // Load the image
    SDL_Surface *loaded_image = SDL_LoadBMP(filename);
    // If the loading worked, convert to texture and return the texture
    if (loaded_image != NULL) {
        texture = SDL_CreateTextureFromSurface(ren, loaded_image);
        SDL_FreeSurface(loaded_image);
        // Make sure converting worked too
        if (texture == NULL)
            log_sdl_error(stdout, "CreateTextureFromSurface");
    }
    else {
        log_sdl_error(stdout, "LoadBMP");
    }

    return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
    // Set up the destination rectangle to be at the position we want
    SDL_Rect *dst = malloc(sizeof(*dst));
    dst->x = x;
    dst->y = y;
    // Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst->w, &dst->h);
    SDL_RenderCopy(ren, tex, NULL, dst);
}