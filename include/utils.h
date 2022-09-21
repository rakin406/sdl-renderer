#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#include "components.h"

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

// Custom triangle type for SDL
struct Triangle
{
    Position point1;
    Position point2;
    Position point3;
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

/**
 * Draw triangle on screen.
 *
 * @param renderer SDL renderer.
 * @param triangle Triangle structure.
 */
void drawTriangle(SDL_Renderer *renderer, const Triangle *triangle);

#endif
