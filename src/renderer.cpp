#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/renderer.h"
#include "../include/utils.h"

// TODO: Move or remove this
// Equilateral triangle side length for enemy entity
static constexpr int TRIANGLE_SIDE_LENGTH = 5;

Renderer::Renderer(SDL_Renderer *renderer) : renderer(renderer)
{
    // Set default player radius
    this->playerCircle.radius = Renderer::PLAYER_RADIUS;
}

void Renderer::drawPlayer(entt::registry &registry)
{
    // Get registry components
    auto view = registry.view<const std::string, Position>();

    // Set player circle color
    setRenderColor(this->renderer, PLAYER_COLOR);

    // Filter out entity tags and draw only the player
    view.each(
        // Loop components
        [this](const auto &tag, auto &pos)
        {
            // Check if tag matches player tag
            if (tag == PLAYER_TAG)
            {
                // Set player circle position
                this->playerCircle.centerX = pos.x;
                this->playerCircle.centerY = pos.y;

                // Draw player circle
                drawCircle(this->renderer, &this->playerCircle);
            }
        });
}

void Renderer::drawEnemies(entt::registry &registry)
{
    // Set enemy triangle color
    setRenderColor(this->renderer, ENEMY_COLOR);

    // Get enemy entity position
    // auto &pos = registry.get<Position>(entity);

    // Set enemy triangle position
    this->enemyTriangle.point1 = {100, 300};
    this->enemyTriangle.point2 = {100, 300};
    this->enemyTriangle.point3 = {300, 100};

    // Draw enemy triangle
    drawTriangle(this->renderer, &this->enemyTriangle);
}
