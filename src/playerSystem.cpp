#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <utility>

#include "../include/components.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"

Position getMousePosition();

PlayerSystem::PlayerSystem(boost::uuids::uuid entity,
                           PositionRegistry positions)
    : entity(entity), positions(std::move(positions))
{
}

void PlayerSystem::update()
{
    // TODO: Do smooth movement by tweening maths or something
    Position currentPos = this->positions.get(this->entity);
    // Set entity position to mouse position
    this->positions.set(this->entity, getMousePosition());
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
