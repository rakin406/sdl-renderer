#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include "entityManager.h"
#include "positionRegistry.h"

// Player logic
class PlayerSystem
{
public:
    EntityManager entities;
    PositionRegistry positions;

    PlayerSystem(EntityManager e, PositionRegistry p);
    void update();
};

#endif
