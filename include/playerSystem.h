#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <boost/uuid/uuid.hpp>

#include "positionRegistry.h"

// Player logic
class PlayerSystem
{
public:
    // TODO: Make these variables private and create getters and setters for
    // them.
    boost::uuids::uuid entity;
    PositionRegistry positions;
    Position lastMousePosition;

    PlayerSystem(boost::uuids::uuid entity, PositionRegistry positions);
    Position getMousePosition();
    void update();
};

#endif
