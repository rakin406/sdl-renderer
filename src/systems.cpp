#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
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

void System::updatePlayer(entt::registry &registry)
{
    // Get registry components
    auto view = registry.view<const std::string, Position>();

    // Filter out entity tags and update only the player
    view.each(
        // Loop components
        [this, &registry](const auto entity, const auto &tag, auto &pos)
        {
            // Check if tag matches player tag
            if (tag == PLAYER_TAG)
            {
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
        });
}

// TODO: Finish this
void System::updateEnemies(entt::registry &registry)
{
    // Loop over all enemy IDs
    // for (const auto &e : enemies)
    // {
    //     // Get enemy entity position
    //     auto &pos = this->registry.get<Position>(e);
    //
    //     // Copy const enemy position
    //     Position enemyPos = pos;
    // }
}
