#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"

Position getMousePosition();

PlayerSystem::PlayerSystem(entt::registry &registry, auto &playerID)
{
    // Set player entity components
    // TODO: Create player size constant
    registry.emplace<Radius>(&playerID, SCREEN_WIDTH / 2);
    registry.emplace<Position>(&playerID, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void PlayerSystem::update(entt::registry &registry, auto &playerID)
{
    auto view = registry.view<const Position, Size>();
}

Position getMousePosition()
{
    Position mousePos;

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}
