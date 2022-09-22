#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/systems.h"

namespace tools
{
/**
 * Check collision between player circle and enemy triangle.
 *
 * @param playerPos Player position.
 * @param enemyPos Enemy position.
 * @param playerRadius Player circle radius.
 */
bool checkCollision(const Position &playerPos, const Position &enemyPos,
                    int playerRadius)
{
    return (enemyPos.x == playerPos.x + playerRadius) ||
           (enemyPos.x == playerPos.x - playerRadius) ||
           (enemyPos.y == playerPos.y + playerRadius) ||
           (enemyPos.y == playerPos.y - playerRadius);
}

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
        [this](const auto &tag, auto &pos)
        {
            // Check if tag matches player tag
            if (tag == Tag::Player)
            {
                // Save last player position
                this->lastPlayerPos = pos;

                // Get entity and mouse positions
                struct Position mousePos = tools::player::getMousePosition();

                // Distance between player and mouse position
                int distanceX = std::abs(mousePos.x - pos.x);
                int distanceY = std::abs(mousePos.y - pos.y);

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
                tools::moveTowards(pos, mousePos, speedX, speedY);
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
                // Check if enemy position is equal to last player position
                if (pos == lastPlayerPos)
                {
                }

                // Logic
            }
        });
}
