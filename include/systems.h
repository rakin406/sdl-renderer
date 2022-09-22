#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <glm/vec2.hpp>
#include <random>

#include "components.h"

// This class handles both the player and the enemy systems and rendering
class System
{
public:
    /**
     * Default constructor.
     *
     * @param registry The main registry of ECS.
     * @param renderer SDL renderer.
     */
    explicit System(entt::registry *registry, SDL_Renderer *renderer);

    // Draw player entity on screen
    void drawPlayer();

    // Draw enemy entities on screen
    void drawEnemies();

    // Update player and it's components
    void updatePlayer();

    // Update enemies and their components
    void updateEnemies();

    // Get random position
    glm::ivec2 getRandomPosition();

    // Return true if game is over
    [[nodiscard]] bool isGameOver() const;

private:
    entt::registry *registry{};       // Main registry
    glm::ivec2 lastPlayerPos{};       // Last position of last player
    bool gameOver = false;            // Game over boolean
    SDL_Renderer *renderer = nullptr; // Main renderer
    Triangle enemyTriangle{};
    std::random_device dev; // For random number generation
};

#endif
