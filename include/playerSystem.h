#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <boost/uuid/uuid.hpp>

#include "positionRegistry.h"

// Player logic
class PlayerSystem
{
public:
    PlayerSystem(boost::uuids::uuid entity, PositionRegistry positions);
    void update();

    // Getters
    boost::uuids::uuid getEntity() { return this->entity; }
    PositionRegistry getPositions() { return this->positions; }

private:
    boost::uuids::uuid entity{};
    PositionRegistry positions{};
};

#endif
