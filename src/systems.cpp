#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>
#include <glm/vec2.hpp>
#include <random>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/systems.h"
#include "../include/utils.h"

namespace
{
constexpr RGB PLAYER_COLOR = {119, 221, 119};
constexpr RGB ENEMY_COLOR = {255, 105, 97};
constexpr int PLAYER_SPEED = 20;
constexpr int ENEMY_SPEED = PLAYER_SPEED + 10;

/**
 * Check collision between player circle and enemy triangle.
 *
 * @param playerPos Player position.
 * @param enemyPos Enemy position.
 * @param playerRadius Player circle radius.
 */
bool checkCollision(const glm::ivec2 &playerPos, const glm::ivec2 &enemyPos,
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
void moveTowards(glm::ivec2 &pos, glm::ivec2 &target, int speedX, int speedY)
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
glm::ivec2 getMousePosition()
{
    glm::ivec2 mousePos{};

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}

} // namespace

System::System(entt::registry *registry, SDL_Renderer *renderer)
    : registry(registry), renderer(renderer)
{
}

void System::drawPlayer()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Circle>();

    // Set player circle color
    setRenderColor(this->renderer, PLAYER_COLOR);

    // Loop components
    view.each(
        [this](const auto &tag, const auto &circle)
        {
            // Check if tag matches player tag
            if (tag == Tag::Player)
            {
                // Draw player circle
                drawCircle(this->renderer, &circle);
            }
        });
}

// TODO: Finish this method
void System::drawEnemies()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Triangle>();

    // Set enemy triangle color
    setRenderColor(this->renderer, ENEMY_COLOR);

    // Loop components
    view.each(
        [this](const auto &tag, auto &triangle)
        {
            // Check if tag matches enemy tag
            if (tag == Tag::Enemy)
            {
                // Set enemy triangle position
                triangle.points[0] = {triangle.centerPos.x - triangle.size,
                                      triangle.centerPos.y + triangle.size};
                triangle.points[1] = {triangle.centerPos.x,
                                      triangle.centerPos.y - triangle.size};
                triangle.points[2] = {triangle.centerPos.x + triangle.size,
                                      triangle.centerPos.y + triangle.size};

                // Draw enemy triangle
                drawTriangle(this->renderer, &this->enemyTriangle);
            }
        });
}

void System::updatePlayer()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Circle>();

    // Loop components
    view.each(
        [this](const auto &tag, auto &circle)
        {
            // Check if tag matches player tag
            if (tag == Tag::Player)
            {
                // Get circle position
                glm::ivec2 playerPos = circle.centerPos;

                // Save last player position
                this->lastPlayerPos = playerPos;

                // Get entity and mouse positions
                glm::ivec2 mousePos = getMousePosition();

                // Distance between player and mouse position
                int distanceX = std::abs(mousePos.x - playerPos.x);
                int distanceY = std::abs(mousePos.y - playerPos.y);

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
                moveTowards(circle.centerPos, mousePos, speedX, speedY);
            }
        });
}

void System::updateEnemies()
{
    // Get registry components
    auto view = this->registry->view<const Tag, Triangle>();

    // Loop components
    view.each(
        [this](const auto &tag, auto &triangle)
        {
            // Check if tag matches enemy tag
            if (tag == Tag::Enemy)
            {
                // 3 triangle points
                for (int i = 0; i < 3; ++i)
                {

                    // Check if enemy collides with player entity
                    if (checkCollision(this->lastPlayerPos, triangle.points[i],
                                       PLAYER_RADIUS))
                    {
                        this->gameOver = true; // Game over
                    }
                    // Otherwise continue moving
                    else
                    {
                        // TODO: Instead of moving towards the player. Save the
                        // last player position and POINT the triangle angle
                        // towards the player and move STRAIGHT until the end of
                        // screen size. Move enemy towards player
                        moveTowards(triangle.centerPos, this->lastPlayerPos,
                                    ENEMY_SPEED, ENEMY_SPEED);
                    }

                    // TODO: Refactor this
                    if (triangle.points[i].x == 0 ||
                        triangle.points[i].x == SCREEN_WIDTH ||
                        triangle.points[i].y == 0 ||
                        triangle.points[i].y == SCREEN_HEIGHT)
                    {
                        // Reset position
                        triangle.centerPos = this->getRandomPosition();
                    }
                }
            }
        });
}

glm::ivec2 System::getRandomPosition()
{
    // Get random generator
    std::mt19937 rng(this->dev());

    // Generate random position
    std::uniform_int_distribution<int> randomPosX(0, SCREEN_WIDTH);
    std::uniform_int_distribution<int> randomPosY(0, SCREEN_HEIGHT);

    // Store position
    glm::ivec2 position = {randomPosX(rng), randomPosY(rng)};

    return position;
}

bool System::isGameOver() const { return this->gameOver; }
