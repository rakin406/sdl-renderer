#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SDL2/SDL.h>

#include "utils.h"

// Radius type alias
using Radius = int32_t;

// Position component with x and y axis fields
using Position = struct
{
    int x;
    int y;
};

// Size component with width and height fields
using Size = struct
{
    int width;
    int height;
};

// Player component
struct Player
{
    Circle circle;
    Position center;
    Radius radius;
};

// Enemy component
struct Enemy
{
    SDL_Rect box;
    Position position;
    Size size;
};

#endif
