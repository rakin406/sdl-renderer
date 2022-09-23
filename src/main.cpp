#include <array>
#include <entt/entt.hpp>
#include <glm/vec2.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/systems.h"
#include "../include/window.h"

constexpr int TRIANGLE_SIZE = 40; // For enemies
constexpr int MAX_ENEMIES = 5;

// These functions are for initializing entities and are out of main loop
void setupPlayer(entt::registry *registry);
void setupEnemies(entt::registry *registry, System &system);

// These functions go inside the main loop
void drawEntities(System *system);
void updateEntities(System *system);

int main()
{
    // Initialize SDL window
    Window window;

    // Create ECS registry and setup entities
    entt::registry registry;

    // Initialize ECS systems
    System system(&registry, window.getRendererContext());

    setupPlayer(&registry);          // Initialize player entity
    setupEnemies(&registry, system); // Initialize enemy entities

    // Event loop run flag
    bool run = true;

    // Event loop
    while (run)
    {
        // Stop loop if user requests quit
        if (Window::isQuitRequested())
        {
            run = false;
        }

        // Clear screen with background color
        window.clear();

        drawEntities(&system);

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

    // Get center screen position
    glm::ivec2 screenCenter = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    // Set initial position
    registry->emplace<Circle>(player, screenCenter, PLAYER_RADIUS);
}

void setupEnemies(entt::registry *registry, System &system)
{
    // Create enemy entities
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        auto enemy = registry->create();
        registry->emplace<Tag>(enemy, Tag::Enemy); // Enemy tag
        std::array<glm::ivec2, 3> blankPoints = {};
        registry->emplace<Triangle>(enemy, blankPoints,
                                    system.getRandomPosition(), TRIANGLE_SIZE);
    }
}

void drawEntities(System *system)
{
    system->drawPlayer();
    system->drawEnemies();
}

void updateEntities(System *system)
{
    system->updatePlayer();
    system->updateEnemies();
}
