#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"
#include "../include/renderer.h"
#include "../include/utils.h"

Renderer::Renderer(SDL_Renderer *renderer) { this->setRenderer(renderer); }

void Renderer::drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem)
{
    // Get renderer
    SDL_Renderer *renderer = this->getRenderer();

    // Get player color
    const auto &[r, g, b] = PLAYER_COLOR;

    // Set player circle color
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    // Get player entity position
    Position playerPos = playerSystem.getPositions().get(entity);

    // Set player circle position
    // TODO: Remove circle
    Circle player = this->getPlayerCircle();
    player.centerX = playerPos.x;
    player.centerY = playerPos.y;
    this->setPlayerCircle(player);

    // Draw player circle
    drawCircle(renderer, &player);
}
