#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/renderer.h"
#include "../include/utils.h"

Renderer::Renderer(SDL_Renderer *renderer) : renderer(renderer)
{
    // Set default player radius
    this->playerCircle.radius = Renderer::PLAYER_RADIUS;
}

void Renderer::drawPlayer(entt::registry &registry, entt::entity &entity)
{
    // Get player color
    const auto &[r, g, b] = PLAYER_COLOR;

    // Set player circle color
    SDL_SetRenderDrawColor(this->renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Get player entity position
    auto &pos = registry.get<Position>(entity);

    // Set player circle position
    this->playerCircle.centerX = pos.x;
    this->playerCircle.centerY = pos.y;

    // Draw player circle
    drawCircle(this->renderer, &this->playerCircle);
}
