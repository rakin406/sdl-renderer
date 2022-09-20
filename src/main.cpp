#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/window.h"

int main()
{
    // Initialize SDL window
    Window window;

    // Initialize entity manager
    entt::registry registry;

    // Create player entity
    auto playerID = registry.create();

    // Initialize player system
    PlayerSystem player(registry, playerID);

    // Event loop run flag
    bool run = true;

    // Event loop
    while (run)
    {
        // Stop loop if user requests quit
        if (window.isQuitRequested())
        {
            run = false;
        }

        // Clear screen with background color
        window.clear();

        // Set renderer color red to draw the square
        // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

        // Draw filled square
        // SDL_RenderFillRect(renderer, &squareRect);

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}
