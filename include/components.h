#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SDL2/SDL.h>

// Size component with width and height fields
using size = struct
{
    int width;
    int height;
};

// Position component with x and y axis fields
using position = struct
{
    int x;
    int y;
};

// Enemy component
struct Enemy
{
    SDL_Rect box;
    size size;
    position position;
};

#endif
