#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <boost/uuid/uuid.hpp>

#include "../include/playerSystem.h"
#include "../include/utils.h"

class Window
{
public:
    Window();

    // Return true if user requests quit
    bool isQuitRequested();

    // Clear screen with background color
    void clear();

    // Draw player entity on screen
    void drawPlayer(boost::uuids::uuid entity, PlayerSystem playerSystem);

    // Update screen
    void update();

    // Kill and exit window
    void destroy();

    // Getters and setters
    SDL_Window *getWindow() { return this->window; }
    void setWindow(SDL_Window *window) { this->window = window; }
    SDL_Renderer *getRenderer() { return this->renderer; }
    void setRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }
    Circle getPlayerCircle() { return this->playerCircle; }
    void setPlayerCircle(Circle circle) { this->playerCircle = circle; }

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Circle playerCircle;
};

#endif
