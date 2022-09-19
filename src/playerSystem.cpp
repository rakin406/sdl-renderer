#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/components.h"
#include "../include/constants.h"
#include "../include/playerSystem.h"

PlayerSystem::PlayerSystem(entt::registry *registry, auto *playerID)
{
    // Set player entity components
    // TODO: Create player size constant
    registry->emplace<radius>(&playerID, SCREEN_WIDTH / 2);
    registry->emplace<position>(&playerID, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
