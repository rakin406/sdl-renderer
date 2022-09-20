#include "../include/components.h"
#include "../include/constants.h"
#include "../include/entityManager.h"
#include "../include/positionRegistry.h"
#include "../include/window.h"

void setup();

int main()
{
    // Initialize SDL window
    Window window;

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

        // Update player
        player.update(registry, playerID);

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}

void setup()
{
    // Spawn player entity, and add a position component in one step
    EntityManager player;
    Position playerPosition = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    PositionRegistry playerPosRegistry;
    playerPosRegistry.set(player.createEntity(), playerPosition);
}
