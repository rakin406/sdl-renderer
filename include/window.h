#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <entt/entt.hpp>

#include "components.h"

void drawEnemyBox(struct EnemyBox &enemy, SDL_Renderer *renderer);
void drawEnemyBoxSDL(entt::registry &registry);

bool initializeSDL();
void clearScreen();
void updateScreen();
void destroySDL();
SDL_Renderer *getRenderer();

#endif
