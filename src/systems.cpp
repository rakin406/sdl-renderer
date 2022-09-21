#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/systems.h"

namespace tools
{
bool checkCollision();

namespace player
{

constexpr int SPEED = 20;

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

} // namespace player
} // namespace tools

System::System(entt::registry *registry) : registry(registry) {}

void System::updatePlayer(entt::entity &entity)
{
    // Get player entity position
    auto &pos = this->registry->get<Position>(entity);

    // Copy const player position
    Position playerPos = pos;

    // Get entity and mouse positions
    Position mousePos = tools::player::getMousePosition();

    // Distance between player and mouse position
    int distanceX = std::abs(mousePos.x - playerPos.x);
    int distanceY = std::abs(mousePos.y - playerPos.y);

    // Initial player speed
    int speedX = tools::player::SPEED;
    int speedY = tools::player::SPEED;

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
    this->registry->replace<Position>(entity, playerPos);
}
