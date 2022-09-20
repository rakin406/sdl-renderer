#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"
#include "../include/utils.h"
#include "../include/window.h"

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);

    // Set window settings
    this->setWindow(SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                     SCREEN_HEIGHT, SDL_WINDOW_SHOWN));

    // Set renderer settings
    this->setRenderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    // Set default player radius
    Circle player{};
    player.radius = PLAYER_RADIUS;
    this->setPlayerCircle(player);
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
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Get screen color
    const auto &[r, g, b] = SCREEN_COLOR;

    // Set background color
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Clear screen
    SDL_RenderClear(renderer);
}

void Window::drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem)
{
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Get player color
    const auto &[r, g, b] = PLAYER_COLOR;

    // Set player circle color
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Get player entity position
    Position playerPos = playerSystem.getPositions().get(entity);

    // Set player circle position
    Circle player = this->getPlayerCircle();
    player.centerX = playerPos.x;
    player.centerY = playerPos.y;
    this->setPlayerCircle(player);

    // Draw player circle
    drawCircle(renderer, &player);
}

void Window::update() { SDL_RenderPresent(this->getRenderer()); }

void Window::destroy()
{
    SDL_DestroyRenderer(this->getRenderer());
    SDL_DestroyWindow(this->getWindow());
    SDL_Quit();
}
