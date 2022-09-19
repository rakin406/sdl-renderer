#include <SDL2/SDL.h>

#include "../include/constants.h"
#include "../include/window.h"

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);

    // Set window settings
    this->setWindow(SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                     SCREEN_HEIGHT, SDL_WINDOW_SHOWN));

    // Set renderer settings
    this->setRenderer(SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
}

// void drawEnemyBoxSDL(entt::registry &registry)
// {
//     auto spriteview = registry.view<SDL_Rect>();
//
//     for (auto et : spriteview)
//     {
//         SDL_Rect &enemy = spriteview.get(et);
//     }
// }

void Window::clear()
{
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Background RGB color
    const int R = SCREEN_COLOR[0];
    const int G = SCREEN_COLOR[1];
    const int B = SCREEN_COLOR[2];

    // Set background color
    SDL_SetRenderDrawColor(renderer, R, G, B, SDL_ALPHA_OPAQUE);

    // Clear screen
    SDL_RenderClear(renderer);
}

void Window::update() { SDL_RenderPresent(this->getRenderer()); }

void Window::destroy()
{
    SDL_DestroyRenderer(this->getRenderer());
    SDL_DestroyWindow(this->getWindow());
    SDL_Quit();
}
