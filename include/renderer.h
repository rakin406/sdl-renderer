#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>

#include "../include/playerSystem.h"
#include "../include/utils.h"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer);

    // Draw player entity on screen
    void drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem);

private:
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
};

#endif
