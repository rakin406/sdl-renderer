#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "components.h"

class PlayerSystem
{
public:
    explicit PlayerSystem(entt::registry &registry, auto &playerID);
    void update(entt::registry &registry, auto &playerID);

private:
};

#endif
