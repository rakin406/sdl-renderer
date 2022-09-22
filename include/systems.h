#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <entt/entt.hpp>
#include <glm/vec2.hpp>

#include "components.h"

// This class handles both the player and the enemy systems
class System
{
public:
    explicit System(entt::registry *registry);

    // Update player and it's components
    void updatePlayer();

    // Update enemies and their components
    void updateEnemies();

    // Return true if game is over
    [[nodiscard]] bool isGameOver() const;

private:
    entt::registry *registry{}; // Main registry
    glm::ivec2 lastPlayerPos{}; // Last position of last player
    bool gameOver = false;      // Game over boolean
};

#endif
