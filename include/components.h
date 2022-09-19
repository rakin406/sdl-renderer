#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SDL2/SDL.h>

#include "utils.h"

// Radius type alias
using radius = int32_t;

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
    radius radius;
};

// Enemy component
struct Enemy
{
    SDL_Rect box;
    position position;
    size size;
};

#endif
