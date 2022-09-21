#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"
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

    // Set default player radius
    this->playerCircle.radius = PLAYER_RADIUS;
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
    // Get screen color
    const auto &[r, g, b] = SCREEN_COLOR;

    // Set background color
    SDL_SetRenderDrawColor(this->renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Clear screen
    SDL_RenderClear(this->renderer);
}

void Window::drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem)
{
    // Get player color
    const auto &[r, g, b] = PLAYER_COLOR;

    // Set player circle color
    SDL_SetRenderDrawColor(this->renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Get player entity position
    Position playerPos = playerSystem.getPositions().get(entity);

    // Set player circle position
    this->playerCircle.centerX = playerPos.x;
    this->playerCircle.centerY = playerPos.y;

    // Draw player circle
    drawCircle(this->renderer, &this->playerCircle);
}

void Window::update() { SDL_RenderPresent(this->renderer); }

void Window::destroy()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
