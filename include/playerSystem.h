#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <boost/uuid/uuid.hpp>

#include "positionRegistry.h"

// Player logic
class PlayerSystem
{
public:
    boost::uuids::uuid entity;
    PositionRegistry positions;

    PlayerSystem(boost::uuids::uuid entity, PositionRegistry positions);
    void update();
};

#endif
