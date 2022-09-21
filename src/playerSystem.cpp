#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/playerSystem.h"

constexpr static int SPEED = 20;

/**
 * Get current mouse position.
 *
 * @return position struct.
 */
Position getMousePosition();

void updatePlayer(entt::registry &registry, entt::entity &entity)
{
    // Get player entity position
    auto &pos = registry.get<Position>(entity);

    // Copy const player position
    Position playerPos = pos;

    // Get entity and mouse positions
    Position mousePos = getMousePosition();

    // Distance between player and mouse position
    int distanceX = std::abs(mousePos.x - playerPos.x);
    int distanceY = std::abs(mousePos.y - playerPos.y);

    // Initial player speed
    int speedX = SPEED;
    int speedY = SPEED;

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

    // Update entity position
    registry.replace<Position>(entity, playerPos);
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
