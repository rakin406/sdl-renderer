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

    // Wait indefinitely for the next available event
    SDL_WaitEvent(&event);

    // Return boolean
    return event.type == SDL_QUIT;
}

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

void Window::drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem)
{
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Player RGB color
    const int R = PLAYER_COLOR[0];
    const int G = PLAYER_COLOR[1];
    const int B = PLAYER_COLOR[2];

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
