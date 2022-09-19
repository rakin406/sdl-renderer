#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/window.h"

int main()
{
    Window window;

    entt::registry registry;

    // Create player entity
    auto playerID = registry.create();
    registry.emplace<radius>(playerID, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const auto &playerSize = registry.get<size>(playerID);
    registry.emplace<position>(playerID,
                               SCREEN_WIDTH / 2 - playerSize.width / 2,
                               SCREEN_HEIGHT / 2 - playerSize.height / 2);

    // Event loop exit flag
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
