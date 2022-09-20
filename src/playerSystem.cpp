#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/utils.h"

Position getMousePosition();

PlayerSystem::PlayerSystem(entt::registry &registry, auto &playerID)
{
    // Set player entity components
    // TODO: Create player size constant
    registry.assign<Circle>(playerID);

    // TODO: Clean this part
    registry.assign<PlayerRadius>(playerID, SCREEN_WIDTH / 2);
    registry.get<Circle>(playerID).radius =
        registry.get<PlayerRadius>(playerID);

    registry.assign<PlayerPosition>(playerID, SCREEN_WIDTH / 2,
                                    SCREEN_HEIGHT / 2);
}

void PlayerSystem::update(entt::registry &registry, auto &playerID)
{
    Circle &player = registry.get<Circle>(playerID);

    // Set entity position
    player.centerX = getMousePosition().x;
    player.centerY = getMousePosition().y;
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
