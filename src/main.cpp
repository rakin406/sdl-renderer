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

        // Draw player entity
        window.drawPlayer(registry, playerID);

        // Update player
        player.update(registry, playerID);

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}
