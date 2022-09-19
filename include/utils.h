#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

/**
 * Draw circle on screen.
 *
 * @param renderer SDL renderer.
 * @param centerX Center x-axis position of circle.
 * @param centerY Center y-axis position of circle.
 * @param radius Radius of circle.
 */
void drawCircle(SDL_Renderer *renderer, int32_t centerX, int32_t centerY,
                int32_t radius);

#endif
