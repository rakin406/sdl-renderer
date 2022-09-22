#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/systems.h"

namespace tools
{
// TODO: Create definition for this function
bool checkCollision();

/**
 * Move towards position with a certain speed.
 *
 * @param pos1 Position one.
 * @param pos2 Position two.
 * @param speedX Speed in x-axis.
 * @param speedY Speed in y-axis.
 */
void moveTowards(Position &pos1, Position &pos2, int speedX, int speedY)
{
    // Move x-axis position
    if (pos1.x > pos2.x)
    {
        pos1.x -= speedX;
    }
    else if (pos1.x < pos2.x)
    {
        pos1.x += speedX;
    }

    // Move y-axis position
    if (pos1.y > pos2.y)
    {
        pos1.y -= speedY;
    }
    else if (pos1.y < pos2.y)
    {
        pos1.y += speedY;
    }
}

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

void System::updatePlayer()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Position>();

    // Loop components
    view.each(
        [this](const auto entity, const auto &tag, auto &pos)
        {
            // Check if tag matches player tag
            if (tag == Tag::Player)
            {
                // Copy const player position
                struct Position playerPos = pos;

                // Get entity and mouse positions
                struct Position mousePos = tools::player::getMousePosition();

                // Distance between player and mouse position
                int distanceX = std::abs(mousePos.x - playerPos.x);
                int distanceY = std::abs(mousePos.y - playerPos.y);

                // Initial player speed
                int speedX = tools::player::SPEED;
                int speedY = tools::player::SPEED;

                // Set speed as difference in distance for the final x-axis
                // movement
                if (distanceX < speedX)
                {
                    speedX = distanceX;
                }

                // y-axis final step
                if (distanceY < speedY)
                {
                    speedY = distanceY;
                }

                // Move towards cursor
                tools::moveTowards(playerPos, mousePos, speedX, speedY);

                // Update entity position
                this->registry->replace<Position>(entity, playerPos);
            }
        });
}

void System::updateEnemies()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Position>();

    // Loop components
    view.each(
        [this](const auto &tag, auto &pos)
        {
            // Check if tag matches enemy tag
            if (tag == Tag::Enemy)
            {
                // Logic
            }
        });
}
