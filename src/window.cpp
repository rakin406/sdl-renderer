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

    // Set default player size
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
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Background RGB color
    constexpr int R = SCREEN_COLOR[0];
    constexpr int G = SCREEN_COLOR[1];
    constexpr int B = SCREEN_COLOR[2];

    // Set background color
    SDL_SetRenderDrawColor(renderer, R, G, B, SDL_ALPHA_OPAQUE);

    // Clear screen
    SDL_RenderClear(renderer);
}

void Window::drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem)
{
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Player RGB color
    constexpr int R = PLAYER_COLOR[0];
    constexpr int G = PLAYER_COLOR[1];
    constexpr int B = PLAYER_COLOR[2];

    // Set player circle color
    SDL_SetRenderDrawColor(renderer, R, G, B, SDL_ALPHA_OPAQUE);

    // Get player entity position
    Position playerPos = playerSystem.positions.get(entity);

    // Set player circle position
    this->playerCircle.centerX = playerPos.x;
    this->playerCircle.centerY = playerPos.y;

    // Draw player circle
    drawCircle(renderer, &this->playerCircle);
}

void Window::update() { SDL_RenderPresent(this->getRenderer()); }

void Window::destroy()
{
    SDL_DestroyRenderer(this->getRenderer());
    SDL_DestroyWindow(this->getWindow());
    SDL_Quit();
}
