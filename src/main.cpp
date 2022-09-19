#include "SDL2/SDL.h"

#include "../include/constants.h"
#include "../include/render.h"

int main()
{
    initializeSDL();

    // Declare rect of square
    SDL_Rect squareRect;

    // Square dimensions: Half of the min(SCREEN_WIDTH, SCREEN_HEIGHT)
    squareRect.w = SCREEN_WIDTH / 2;
    squareRect.h = SCREEN_HEIGHT / 2;

    // Square position: In the middle of the screen
    squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

    // Event loop exit flag
    bool run = true;

    // Event loop
    while (run)
    {
        SDL_Event event;

        // Wait indefinitely for the next available event
        SDL_WaitEvent(&event);

        // User requests quit
        if (event.type == SDL_QUIT)
        {
            run = false;
        }

        // Clear screen with background color
        clearScreen();

        // Set renderer color red to draw the square
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

        // Draw filled square
        SDL_RenderFillRect(renderer, &squareRect);

        updateScreen();
    }

    // Quit game
    destroySDL();

    return 0;
}
