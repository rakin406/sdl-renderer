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

    // Getter
    SDL_Renderer *getRenderer() { return this->renderer; }

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    Circle playerCircle{};
};

#endif
