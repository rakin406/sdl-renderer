#include <entt/entt.hpp>
#include <string>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/renderer.h"
#include "../include/systems.h"
#include "../include/window.h"

void setupEntities(entt::registry *registry);

int main()
{
    // Initialize SDL window
    Window window;

    // Create ECS registry and setup entities
    entt::registry registry;
    setupEntities(&registry);

    // Initialize renderer
    Renderer renderer(window.getRendererContext(), &registry);

    // Initialize ECS systems
    System system(&registry);

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

        // Draw entities
        renderer.drawPlayer();
        renderer.drawEnemies();

        // Update systems
        system.updatePlayer();
        system.updateEnemies();

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}

void setupEntities(entt::registry *registry)
{
    // Create player entity and set default player entity position at the center
    // of the screen.
    auto player = registry->create();
    registry->emplace<std::string>(player, "player"); // Player tag
    registry->emplace<Position>(player, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    // Create enemy entities
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        auto enemy = registry->create();
        registry->emplace<std::string>(enemy, "enemy"); // Enemy tag
    }
}
