#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <cmath>
#include <iostream>
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

/**
 * Calculate the distance between two points.
 *
 * @param pos1 First position
 * @param pos2 Second position.
 * @return distance as integer.
 */
int getDistance(Position pos1, Position pos2)
{
    double value = std::hypot(pos2.x - pos1.x, pos2.y - pos1.y);
    return static_cast<int>(value);
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
    // Get entity and positions
    boost::uuids::uuid entity = this->getEntity();
    PositionRegistry positions = this->getPositions();

    Position playerPos = positions.get(entity); // Get entity position
    Position mousePos = getMousePosition();     // Get mouse position

    // Distance between player and mouse position
    int distance = getDistance(playerPos, mousePos);
    std::cout << "Distance: " << distance << "\n"; // debugging

    // Initial player speed
    int speed = PLAYER_SPEED;

    // Set speed as difference in distance for the final step
    if (distance < speed)
    {
        speed = distance;
    }

    // Move x-axis position
    if (playerPos.x > mousePos.x)
    {
        playerPos.x -= speed;
    }
    else if (playerPos.x < mousePos.x)
    {
        playerPos.x += speed;
    }

    // Move y-axis position
    if (playerPos.y > mousePos.y)
    {
        playerPos.y -= speed;
    }
    else if (playerPos.y < mousePos.y)
    {
        playerPos.y += speed;
    }

    positions.set(entity, playerPos); // Set entity position to mouse position
    this->setPositions(positions);    // Update positions
}
