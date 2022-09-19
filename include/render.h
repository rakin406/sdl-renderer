#ifndef RENDER_H
#define RENDER_H

#include "SDL2/SDL.h"

struct SDL_Window;
struct SDL_Renderer;

bool initializeSDL();
void clearScreen();
void updateScreen();
void destroySDL();
SDL_Renderer *getRenderer();

#endif
