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

    SDL_Renderer *getRenderer() { return this->renderer; }
    void setRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }
    Circle getPlayerCircle() { return this->playerCircle; }
    void setPlayerCircle(Circle circle) { this->playerCircle = circle; }

private:
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
};

#endif
