#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

#include "../include/utils.h"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer);

    // Draw player entity on screen
    void drawPlayer();

private:
    constexpr static int PLAYER_RADIUS = 40;
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
};

#endif
