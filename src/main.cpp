#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/renderer.h"
#include "../include/window.h"

int main()
{
    // Initialize SDL window
    Window window;

    // Initialize renderer
    Renderer renderer(window.getRendererContext());

    // Initialize ECS registry
    entt::registry registry;

    // Create player entity and set default player entity position at the center
    // of the screen.
    auto player = registry.create();
    registry.emplace<Position>(player, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    // Initialize player system
    PlayerSystem playerSystem(player, playerPosRegistry);

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

        // Don't draw or update player if it's null
        if (!player.is_nil() || !playerSystem.getEntity().is_nil())
        {
            // Draw player entity
            renderer.drawPlayer(playerSystem);

            // Update player system
            playerSystem.update();
        }

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}
