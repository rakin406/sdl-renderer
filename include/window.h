#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <array>
#include <glm/vec2.hpp>

#include "constants.h"

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

constexpr char SCREEN_TITLE[] = "Avoid me";
constexpr RGB SCREEN_COLOR = {253, 248, 150};

class Window
{
public:
    Window()
    {
        SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                         SDL_WINDOW_SHOWN);
        SDL_CreateRenderer(
            window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        SDL_Init(SDL_INIT_VIDEO);
    }

    // Get renderer context
    [[nodiscard]] SDL_Renderer *getRendererContext() const
    {
        return this->renderer;
    }

    // Return true if user requests quit
    bool isQuitRequested()
    {
        SDL_Event event;

        // Check for events
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                return true;
            }

            if (event.type == SDL_KEYDOWN)
            {
                // Quit on Escape
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return true;
                }
            }
        }

        return false;
    }

    // Clear screen with background color
    void clear()
    {
        // Set background color
        setRenderColor(this->renderer, SCREEN_COLOR);
        // Clear screen
        SDL_RenderClear(this->renderer);
    }

    /**
     * Set color for next render.
     *
     * @param renderer SDL renderer.
     * @param color Render color.
     */
    void setRenderColor(SDL_Renderer *renderer, const RGB &color)
    {
        const auto &[r, g, b] = color;
        SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    }

    /**
     * Draw circle on screen.
     *
     * @param renderer SDL renderer.
     * @param circle Circle structure.
     */
    void drawCircle(SDL_Renderer *renderer, const Circle *circle)
    {
        // Get circle properties
        glm::ivec2 centerPos = circle->centerPos;
        int radius = circle->radius;

        for (int w = 0; w < radius * 2; ++w)
        {
            for (int h = 0; h < radius * 2; ++h)
            {
                int dx = radius - w; // horizontal offset
                int dy = radius - h; // vertical offset
                if ((dx * dx + dy * dy) <= (radius * radius))
                {
                    SDL_RenderDrawPoint(renderer, centerPos.x + dx,
                                        centerPos.y + dy);
                }
            }
        }
    }

    /**
     * Draw triangle on screen.
     *
     * @param renderer SDL renderer.
     * @param triangle Triangle structure.
     */
    void drawTriangle(SDL_Renderer *renderer, const Triangle *triangle)
    {
        // Get triangle properties
        glm::ivec2 point1 = triangle->points[0];
        glm::ivec2 point2 = triangle->points[1];
        glm::ivec2 point3 = triangle->points[2];

        // TODO: Fill the triangle with color
        // Draw line up to points
        SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
        SDL_RenderDrawLine(renderer, point2.x, point2.y, point3.x, point3.y);
        SDL_RenderDrawLine(renderer, point3.x, point3.y, point1.x, point1.y);
    }

    // Update screen
    void update() { SDL_RenderPresent(this->renderer); }

    // Kill and exit window
    void destroy()
    {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif
