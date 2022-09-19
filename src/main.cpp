#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/render.h"

int main()
{
    initializeSDL();

    entt::registry registry;

    // Create enemy box entity
    auto enemy = registry.create();
    auto view = registry.view<Enemy>();
    registry.emplace<size>(enemy, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const auto &entitySize = registry.get<size>(enemy);
    registry.emplace<position>(enemy, SCREEN_WIDTH / 2 - entitySize.width / 2,
                               SCREEN_HEIGHT / 2 - entitySize.height / 2);

    // Event loop exit flag
    bool run = true;

    // Event loop
    while (run)
    {
        SDL_Event event;

        // Wait indefinitely for the next available event
        SDL_WaitEvent(&event);

        // User requests quit
        if (event.type == SDL_QUIT)
        {
            run = false;
        }

        // Clear screen with background color
        clearScreen();

        // Set renderer color red to draw the square
        // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

        // Draw filled square
        // SDL_RenderFillRect(renderer, &squareRect);

        updateScreen();
    }

    // Quit game
    destroySDL();

    return 0;
}
