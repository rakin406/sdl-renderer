#include "../include/constants.h"
#include "../include/window.h"

int main()
{
    // Initialize SDL window
    Window window;

    // Event loop run flag
    bool run = true;

    // Event loop
    while (run)
    {
        // Stop loop if user requests quit
        if (Window::isQuitRequested())
        {
            run = false;
        }

        // Clear screen with background color
        window.clear();

        // ----------Draw or update stuff here-----------

        // Update screen
        window.update();
    }

    // Quit game
    window.destroy();

    return 0;
}
