#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/utils.h"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer);

    /**
     * Draw player entity on screen.
     *
     * @param registry The main registry of ECS.
     */
    void drawPlayer(entt::registry &registry);

    /**
     * Draw enemy entities on screen.
     *
     * @param registry The main registry of ECS.
     */
    void drawEnemies(entt::registry &registry);

private:
    static constexpr int PLAYER_RADIUS = 40;
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
    Triangle enemyTriangle{};
};

#endif
