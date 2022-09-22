#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <entt/entt.hpp>

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
    bool isGameOver() const;

private:
    const int PLAYER_RADIUS = 40;                  // Default player radius
    static constexpr int TRIANGLE_SIDE_LENGTH = 5; // Triangle length
    entt::registry *registry{};                    // Main registry
    Position lastPlayerPos{}; // Last position of last player
    bool gameOver = false;    // Game over boolean
};

#endif
