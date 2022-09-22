#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <glm/vec2.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/renderer.h"
#include "../include/utils.h"

// TODO: Move or remove this
// Equilateral triangle side length for enemy entity
constexpr int TRIANGLE_SIDE_LENGTH = 5;

Renderer::Renderer(SDL_Renderer *renderer, entt::registry *registry)
    : renderer(renderer), registry(registry)
{
    // Set default player radius
    this->playerCircle.radius = PLAYER_RADIUS;
}

void Renderer::drawPlayer()
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
void Renderer::drawEnemies()
{
    // Get registry components
    auto view = this->registry->view<const Tag, glm::ivec2>();

    // Set enemy triangle color
    setRenderColor(this->renderer, ENEMY_COLOR);

    // Loop components
    view.each(
        [this](const auto &tag, auto &pos)
        {
            // Check if tag matches enemy tag
            if (tag == Tag::Enemy)
            {
                // TODO: Finish this
                // Set enemy triangle position
                this->enemyTriangle.points[0] = {100, 300};
                this->enemyTriangle.points[1] = {100, 300};
                this->enemyTriangle.points[2] = {300, 100};

                // Draw enemy triangle
                drawTriangle(this->renderer, &this->enemyTriangle);
            }
        });
}
