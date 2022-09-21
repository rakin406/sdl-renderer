#include <SDL2/SDL.h>

#include "../include/utils.h"

void setRenderColor(SDL_Renderer *renderer, const RGB &color)
{
    const auto &[r, g, b] = color;
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
}

void drawCircle(SDL_Renderer *renderer, const Circle *circle)
{
    // Get circle properties
    int centerX = circle->centerX;
    int centerY = circle->centerY;
    int radius = circle->radius;

    for (int w = 0; w < radius * 2; ++w)
    {
        for (int h = 0; h < radius * 2; ++h)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}
