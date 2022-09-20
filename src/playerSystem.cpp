#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>
#include <utility>

#include "../include/components.h"
#include "../include/playerSystem.h"
#include "../include/positionRegistry.h"

PlayerSystem::PlayerSystem(boost::uuids::uuid entity,
                           PositionRegistry positions)
    : entity(entity), positions(std::move(positions))
{
}

Position PlayerSystem::getMousePosition()
{
    Position mousePos;

    // Make sure we have the latest mouse state.
    SDL_PumpEvents();

    // Get mouse position
    SDL_GetMouseState(&mousePos.x, &mousePos.y);

    return mousePos;
}

void PlayerSystem::update()
{
    Position position = this->positions.get(this->entity);
    Position mousePos = this->getMousePosition();

    // Move x-axis position
    if (position.x > mousePos.x)
    {
        position.x -= 1;
    }
    else
    {
        position.x += 1;
    }

    // Move y-axis position
    if (position.y > mousePos.y)
    {
        position.y -= 1;
    }
    else
    {
        position.y += 1;
    }

    // Set entity position to mouse position
    this->positions.set(this->entity, position);
}
