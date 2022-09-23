#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include <array>
#include <glm/vec2.hpp>

struct RGB
{
    int red;
    int green;
    int blue;
};

struct Circle
{
    glm::ivec2 centerPos;
    int radius; // Radius of the circle
};

struct Triangle
{
    std::array<glm::ivec2, 3> points;
    int size;
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
