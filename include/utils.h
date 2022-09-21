#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

struct RGB
{
    int red;
    int green;
    int blue;
};

// Custom circle type for SDL
struct Circle
{
    int centerX; // Center x-axis position
    int centerY; // Center y-axis position
    int radius;  // Radius of the circle
};

/**
 * Set color for next render.
 *
 * @param renderer SDL renderer.
 * @param color Render color.
 */
void setRenderColor(SDL_Renderer *renderer, const RGB &color);

/**
 * Draw circle on screen.
 *
 * @param renderer SDL renderer.
 * @param circle Circle structure.
 */
void drawCircle(SDL_Renderer *renderer, const Circle *circle);

#endif
