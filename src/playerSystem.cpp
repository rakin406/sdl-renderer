#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <cmath>
#include <cstdlib>
#include <utility>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"

namespace
{
/**
 * Get current mouse position.
 *
 * @return position struct.
 */
Position getMousePosition()
{
    Position mousePos{};

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}
} // namespace

PlayerSystem::PlayerSystem(boost::uuids::uuid entity,
                           const PositionRegistry &positions)
{
    this->setEntity(entity);
    this->setPositions(positions);
}

void PlayerSystem::update()
{
    // Get entity and position registry
    boost::uuids::uuid entity = this->getEntity();
    PositionRegistry positions = this->getPositions();

    // Get entity and mouse positions
    Position playerPos = positions.get(entity);
    Position mousePos = getMousePosition();

    // Distance between player and mouse position
    int distanceX = std::abs(mousePos.x - playerPos.x);
    int distanceY = std::abs(mousePos.y - playerPos.y);

    // Initial player speed
    int speedX = PLAYER_SPEED;
    int speedY = PLAYER_SPEED;

    // Set speed as difference in distance for the final x-axis movement
    if (distanceX < speedX)
    {
        speedX = distanceX;
    }

    // y-axis final step
    if (distanceY < speedY)
    {
        speedY = distanceY;
    }

    // Move x-axis position
    if (playerPos.x > mousePos.x)
    {
        playerPos.x -= speedX;
    }
    else if (playerPos.x < mousePos.x)
    {
        playerPos.x += speedX;
    }

    // Move y-axis position
    if (playerPos.y > mousePos.y)
    {
        playerPos.y -= speedY;
    }
    else if (playerPos.y < mousePos.y)
    {
        playerPos.y += speedY;
    }

    positions.set(entity, playerPos); // Set entity position to mouse position
    this->setPositions(positions);    // Update positions
}
