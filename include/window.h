#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
    Window();

    // Get renderer context
    SDL_Renderer *getRendererContext();

    // Return true if user requests quit
    bool isQuitRequested();

    // Clear screen with background color
    void clear();

    // Update screen
    void update();

    // Kill and exit window
    void destroy();

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif
