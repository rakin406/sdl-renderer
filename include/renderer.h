#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "../include/utils.h"

class Renderer
{
public:
    /**
     * Default constructor.
     *
     * @param renderer SDL renderer.
     * @param registry The main registry of ECS.
     */
    explicit Renderer(SDL_Renderer *renderer, entt::registry *registry);

    // Draw player entity on screen.
    void drawPlayer();

    // Draw enemy entities on screen.
    void drawEnemies();

private:
    static constexpr int PLAYER_RADIUS = 40;
    SDL_Renderer *renderer = nullptr;
    entt::registry *registry{};
    Circle playerCircle{};
    Triangle enemyTriangle{};
};

#endif
