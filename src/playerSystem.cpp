#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <utility>

#include "../include/components.h"
#include "../include/playerSystem.h"

Position getMousePosition();

PlayerSystem::PlayerSystem(EntityManager e, PositionRegistry p)
    : entities(std::move(e)), positions(std::move(p))
{
}

void PlayerSystem::update()
{
    // Loop all entities
    for (const auto &[key, val] : this->entities.getAll())
    {
        // Set entity position to mouse position
        this->positions.set(key, getMousePosition());
    }
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
