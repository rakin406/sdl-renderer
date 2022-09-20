#include <boost/uuid/uuid.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/entityManager.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"
#include "../include/window.h"

int main()
{
    // Initialize SDL window
    Window window;

    // Initialize entities
    EntityManager entities;

    // Set default player entity position at the center of the screen
    Position playerPosition = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    PositionRegistry playerPosRegistry;
    boost::uuids::uuid player = entities.createEntity();
    playerPosRegistry.set(player, playerPosition);

    // Initialize player system
    PlayerSystem playerSystem(entities, playerPosRegistry);

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
        window.drawPlayer(player, playerPosRegistry);

        // Update player system
        playerSystem.update();

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}
