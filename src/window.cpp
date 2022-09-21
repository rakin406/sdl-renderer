#include <SDL2/SDL.h>

#include "../include/constants.h"
#include "../include/utils.h"
#include "../include/window.h"

Window::Window()
    : window(SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN)),
      renderer(SDL_CreateRenderer(
          window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
{
    SDL_Init(SDL_INIT_VIDEO);
}

bool Window::isQuitRequested()
{
    SDL_Event event;

    // Check for events
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return true;
        default:
            break;
        }
    }

    return false;
}

void Window::clear()
{
    // Set background color
    setRenderColor(this->renderer, SCREEN_COLOR);
    // Clear screen
    SDL_RenderClear(this->renderer);
}

void Window::update() { SDL_RenderPresent(this->renderer); }

void Window::destroy()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
