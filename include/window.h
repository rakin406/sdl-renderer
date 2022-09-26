#ifndef WINDOW_H
#define WINDOW_H

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <array>
#include <string_view>

struct Circle
{
    glm::ivec2 centerPos;
    int radius;
};

struct Triangle
{
    std::array<glm::ivec2, 3> points;
    int size;
};

class Window
{
public:
    /**
     * @brief Default constructor for Window.
     *
     * @param title Window title.
     * @param width Window width.
     * @param height Window height.
     */
    Window(std::string_view title, int width, int height)
    {
        SDL_CreateWindow(title.data(), SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, width, height,
                         SDL_WINDOW_SHOWN);

        SDL_CreateRenderer(m_pWindow, -1,
                           SDL_RENDERER_ACCELERATED |
                               SDL_RENDERER_PRESENTVSYNC);

        SDL_Init(SDL_INIT_VIDEO);
    }

    /**
     * @brief Get renderer context.
     *
     * @return SDL_Renderer*
     */
    [[nodiscard]] SDL_Renderer *getRendererContext() const
    {
        return m_pRenderer;
    }

    /**
     * @brief Return true if user requests quit. For use in main loop.
     *
     * @return boolean.
     */
    bool isQuitRequested()
    {
        SDL_Event event {};

        // Check for events
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                return true;
            }

            if (event.type == SDL_KEYDOWN)
            {
                // Detect quit on Escape
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return true;
                }
            }
        }

        return false;
    }

    // FIX: Screen color is transparent
    /**
     * @brief Clear screen with background color. Default is white.
     *
     * @param red Default = 255
     * @param green Default = 255
     * @param blue Default = 255
     */
    void clear(Uint8 red = 255, Uint8 green = 255, Uint8 blue = 255)
    {
        // Set background color
        setRenderColor(red, green, blue);
        // Clear screen
        SDL_RenderClear(m_pRenderer);
    }

    /**
     * @brief Set color for next render. Default is black.
     *
     * @param red Default = 0
     * @param green Default = 0
     * @param blue Default = 0
     */
    void setRenderColor(Uint8 red = 0, Uint8 green = 0, Uint8 blue = 0)
    {
        SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, SDL_ALPHA_OPAQUE);
    }

    /**
     * @brief Draw circle on screen.
     *
     * @param circle Circle structure.
     */
    void drawCircle(const Circle &circle)
    {
        // Get circle properties
        glm::ivec2 centerPos { circle.centerPos };
        int radius { circle.radius };

        for (int w { 0 }; w < radius * 2; ++w)
        {
            for (int h { 0 }; h < radius * 2; ++h)
            {
                int dx = radius - w; // horizontal offset
                int dy = radius - h; // vertical offset
                if ((dx * dx + dy * dy) <= (radius * radius))
                {
                    SDL_RenderDrawPoint(m_pRenderer, centerPos.x + dx,
                                        centerPos.y + dy);
                }
            }
        }
    }

    /**
     * @brief Draw triangle on screen.
     *
     * @param triangle Triangle structure.
     */
    void drawTriangle(const Triangle &triangle)
    {
        glm::ivec2 point1 { triangle.points[0] };
        glm::ivec2 point2 { triangle.points[1] };
        glm::ivec2 point3 { triangle.points[2] };

        // TODO: Fill the triangle with color
        // Draw line up to points
        SDL_RenderDrawLine(m_pRenderer, point1.x, point1.y, point2.x, point2.y);
        SDL_RenderDrawLine(m_pRenderer, point2.x, point2.y, point3.x, point3.y);
        SDL_RenderDrawLine(m_pRenderer, point3.x, point3.y, point1.x, point1.y);
    }

    /**
     * @brief Update screen.
     */
    void update() { SDL_RenderPresent(m_pRenderer); }

    /**
     * @brief Kill and exit window.
     */
    void destroy()
    {
        SDL_DestroyRenderer(m_pRenderer);
        SDL_DestroyWindow(m_pWindow);
        SDL_Quit();
    }

private:
    SDL_Window *m_pWindow { nullptr };
    SDL_Renderer *m_pRenderer { nullptr };
};

#endif
