#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/utils.h"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer);

    // Draw player entity on screen
    void drawPlayer(entt::registry &registry, entt::entity &entity);

    // Draw enemy entity on screen
    void drawEnemy();

private:
    static constexpr int PLAYER_RADIUS = 40;
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
    Triangle enemyTriangle{};
};

#endif
