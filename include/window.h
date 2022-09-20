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

    // Draw player entity on screen
    void drawPlayer(entt::registry &registry, auto &playerID);

    // Update screen
    void update();

    // Kill and exit window
    void destroy();

    // Getters and setters
    SDL_Window *getWindow() { return this->window; }
    void setWindow(SDL_Window *window) { this->window = window; }
    SDL_Renderer *getRenderer() { return this->renderer; }
    void setRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif
