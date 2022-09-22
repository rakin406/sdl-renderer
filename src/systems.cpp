#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/systems.h"

namespace
{
constexpr int PLAYER_SPEED = 20;
constexpr int ENEMY_SPEED = PLAYER_SPEED + 10;

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
 * Move towards target position with a certain speed.
 *
 * @param pos Source position.
 * @param target Target position.
 * @param speedX Speed in x-axis.
 * @param speedY Speed in y-axis.
 */
void moveTowards(Position &pos, Position &target, int speedX, int speedY)
{
    // Move x-axis position
    if (pos.x > target.x)
    {
        pos.x -= speedX;
    }
    else if (pos.x < target.x)
    {
        pos.x += speedX;
    }

    // Move y-axis position
    if (pos.y > target.y)
    {
        pos.y -= speedY;
    }
    else if (pos.y < target.y)
    {
        pos.y += speedY;
    }
}

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
                struct Position mousePos = getMousePosition();

                // Distance between player and mouse position
                int distanceX = std::abs(mousePos.x - pos.x);
                int distanceY = std::abs(mousePos.y - pos.y);

                // Initial player speed
                int speedX = PLAYER_SPEED;
                int speedY = PLAYER_SPEED;

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
                moveTowards(pos, mousePos, speedX, speedY);
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
                // Check if enemy collides with player entity
                if (checkCollision(this->lastPlayerPos, pos, PLAYER_RADIUS))
                {
                    this->gameOver = true; // Game over
                }
                // Otherwise continue moving
                else
                {
                    // Move enemy towards player
                    moveTowards(pos, this->lastPlayerPos, ENEMY_SPEED,
                                ENEMY_SPEED);
                }
            }
        });
}

bool System::isGameOver() const { return this->gameOver; }
