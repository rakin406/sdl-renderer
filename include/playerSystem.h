#ifndef PLAYER_SYSTEM_H
#define PLAYER_SYSTEM_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "components.h"

class PlayerSystem
{
public:
    explicit PlayerSystem(entt::registry *registry, auto *playerID);

    // Update screen
    void update();

    // Getters and setters
    void setRadius();
    SDL_Window *getWindow() { return this->window; }
    void setWindow(SDL_Window *window) { this->window = window; }
    SDL_Renderer *getRenderer() { return this->renderer; }
    void setRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }

private:
};

#endif
