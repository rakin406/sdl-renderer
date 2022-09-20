#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SDL2/SDL.h>

#include "utils.h"

using Position = struct
{
    int x;
    int y;
};

using Size = struct
{
    int width;
    int height;
};

// Player position component
struct PlayerPosition
{
    Position center;
};

// Player radius component
struct PlayerRadius
{
    int32_t radius;
};

// Player component
// struct Player
// {
//     Circle circle;
//     PlayerPosition center;
//     Radius radius;
// };

// Enemy component
// struct Enemy
// {
//     SDL_Rect box;
//     Position position;
//     Size size;
// };

#endif
