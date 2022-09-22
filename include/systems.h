#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <entt/entt.hpp>

// This class handles both the player and the enemy systems
class System
{
public:
    explicit System(entt::registry *registry);

    // Update player and it's components.
    void updatePlayer();

    // Update enemies and their components.
    void updateEnemies();

private:
    static constexpr int PLAYER_RADIUS = 40;       // Default player radius
    static constexpr int TRIANGLE_SIDE_LENGTH = 5; // Triangle length
    entt::registry *registry{};
};

#endif
