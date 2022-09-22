#include <entt/entt.hpp>
#include <random>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/renderer.h"
#include "../include/systems.h"
#include "../include/window.h"

void setupPlayer(entt::registry *registry);
void setupEnemies(entt::registry *registry, std::mt19937 &rng);
void setup(entt::registry *registry);
void drawEntities(Renderer *renderer);
void updateEntities(System *system);

int main()
{
    // Initialize SDL window
    Window window;

    // Create ECS registry and setup entities
    entt::registry registry;
    setup(&registry);

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

        drawEntities(&renderer);

        // Don't update entities if game is over
        if (!system.isGameOver())
        {
            updateEntities(&system);
        }

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}

void setupPlayer(entt::registry *registry)
{
    // Create player entity and set default player entity position at the center
    // of the screen.
    auto player = registry->create();
    registry->emplace<Tag>(player, Tag::Player); // Player tag
    registry->emplace<Position>(player, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void setupEnemies(entt::registry *registry, std::mt19937 &rng)
{
    // Create enemy entities
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        auto enemy = registry->create();
        registry->emplace<Tag>(enemy, Tag::Enemy); // Enemy tag

        // Generate random position
        std::uniform_int_distribution<int> posX(0, SCREEN_WIDTH);
        std::uniform_int_distribution<int> posY(0, SCREEN_HEIGHT);

        // Set enemy position
        registry->emplace<Position>(enemy, posX(rng), posY(rng));
    }
}

void setup(entt::registry *registry)
{
    // This is for random number generation
    std::random_device dev;
    std::mt19937 rng(dev());

    setupPlayer(registry);
    setupEnemies(registry, rng);
}

void drawEntities(Renderer *renderer)
{
    renderer->drawPlayer();
    renderer->drawEnemies();
}

void updateEntities(System *system)
{
    system->updatePlayer();
    system->updateEnemies();
}
