#include <SDL2/SDL.h>

#include "../include/constants.h"
#include "../include/render.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool initializeSDL()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    return renderer != nullptr;
}

void clearScreen()
{
    // Background RGB color
    int r = SCREEN_COLOR[0];
    int g = SCREEN_COLOR[1];
    int b = SCREEN_COLOR[2];

    // Set background color
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Clear screen
    SDL_RenderClear(renderer);
}

void updateScreen() { SDL_RenderPresent(renderer); }

void destroySDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer *getRenderer() { return renderer; }
