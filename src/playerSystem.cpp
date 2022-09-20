#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <utility>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"
#include "../include/utils.h"

Position getMousePosition();

PlayerSystem::PlayerSystem(EntityManager e, PositionRegistry p)
    : entities(std::move(e)), positions(std::move(p))
{
}

void PlayerSystem::update() {}

Position getMousePosition()
{
    Position mousePos;

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}
