#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <cmath>
#include <utility>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"

Position getMousePosition();

/**
 * Calculate the distance between two points.
 *
 * @param pos1 First position
 * @param pos2 Second position.
 */
int distance(Position pos1, Position pos2);

PlayerSystem::PlayerSystem(boost::uuids::uuid entity,
                           const PositionRegistry &positions)
{
    this->setEntity(entity);
    this->setPositions(positions);
}

void PlayerSystem::update()
{
    // Get entity and positions
    boost::uuids::uuid entity = this->getEntity();
    PositionRegistry positions = this->getPositions();

    Position position = positions.get(entity); // Get entity position
    Position mousePos = getMousePosition();    // Get mouse position
    Position difference{}; // Difference between player and mouse position

    // Move x-axis position
    if (position.x > mousePos.x)
    {
        position.x -= PLAYER_SPEED;
    }
    else
    {
        position.x += PLAYER_SPEED;
    }

    // Move y-axis position
    if (position.y > mousePos.y)
    {
        position.y -= PLAYER_SPEED;
    }
    else
    {
        position.y += PLAYER_SPEED;
    }

    positions.set(entity, position); // Set entity position to mouse position
    this->setPositions(positions);   // Update positions
}

Position getMousePosition()
{
    Position mousePos{};

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}

int distance(Position pos1, Position pos2)
{
    double value = std::sqrt(std::pow(pos2.x - pos1.x, 2) +
                             std::pow(pos2.y - pos1.y, 2) * 1);
    return static_cast<int>(value);
}
