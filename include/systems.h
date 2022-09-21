#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <entt/entt.hpp>
#include <vector>

class System
{
public:
    explicit System(entt::registry *registry);

    void updatePlayer(entt::entity &entity);

    void updateEnemies(std::vector<entt::entity> &enemies);

private:
    static constexpr int PLAYER_RADIUS = 40;
    static constexpr int TRIANGLE_SIDE_LENGTH = 5;
    entt::registry *registry{};
};

#endif
