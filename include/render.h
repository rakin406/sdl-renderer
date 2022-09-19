#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "components.h"

struct EnemyBox
{
    SDL_Rect enemy;
    size size;
    position position;
};

void drawEnemyBox(struct EnemyBox &enemy, SDL_Renderer *renderer);
void drawEnemyBoxSDL(entt::registry &registry);

bool initializeSDL();
void clearScreen();
void updateScreen();
void destroySDL();
SDL_Renderer *getRenderer();

#endif
