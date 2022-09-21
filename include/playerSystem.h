#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <boost/uuid/uuid.hpp>

#include "positionRegistry.h"

// Player logic
class PlayerSystem
{
public:
    PlayerSystem(boost::uuids::uuid entity, const PositionRegistry &positions);
    void update();

    // Getters and setters
    boost::uuids::uuid getEntity() { return this->entity; }
    void setEntity(boost::uuids::uuid entity) { this->entity = entity; }

    PositionRegistry getPositions() { return this->positions; }
    void setPositions(const PositionRegistry &positions)
    {
        this->positions = positions;
    }

private:
    boost::uuids::uuid entity{};
    PositionRegistry positions{};
};

#endif
