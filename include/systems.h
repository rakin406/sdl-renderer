#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <entt/entt.hpp>

// This class handles both the player and the enemy systems
class System
{
public:
    /**
     * Update player and it's components.
     *
     * @param registry The main registry of ECS.
     */
    void updatePlayer(entt::registry &registry);

    /**
     * Update enemies and their components.
     *
     * @param registry The main registry of ECS.
     */
    void updateEnemies(entt::registry &registry);

private:
    static constexpr int PLAYER_RADIUS = 40;       // Default player radius
    static constexpr int TRIANGLE_SIDE_LENGTH = 5; // Triangle length
};

#endif
