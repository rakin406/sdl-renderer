#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
    Window();

    // Return true if user requests quit
    bool isQuitRequested();

    // Clear screen with background color
    void clear();

    // Update screen
    void update();

    // Kill and exit window
    void destroy();

    // Getter for renderer context
    SDL_Renderer *getRendererContext() { return this->renderer; }

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif
