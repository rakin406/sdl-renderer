#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SDL2/SDL.h>

#include "utils.h"

// Position component with x and y axis fields
using position = struct
{
    int x;
    int y;
};

// Size component with width and height fields
using size = struct
{
    int width;
    int height;
};

// Player component
struct Player
{
    Circle circle;
    position center;
    int radius;
};

// Enemy component
struct Enemy
{
    SDL_Rect box;
    position position;
    size size;
};

#endif
