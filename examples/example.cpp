#include "../include/window.h"

#include <string>

namespace
{
// Screen constants
constexpr int SCREEN_WIDTH { 1000 };
constexpr int SCREEN_HEIGHT { 750 };
} // namespace

int main()
{
    // Initialize SDL window
    Window window("Example", SCREEN_WIDTH, SCREEN_HEIGHT);

    // Event loop run flag
    bool run { true };

    // Event loop
    while (run)
    {
        // Stop loop if user requests quit
        if (window.isQuitRequested())
        {
            run = false;
        }

        // Clear screen with background color which is white by default
        window.clear();

        // ----------Draw or update stuff here-----------

        // Update screen
        window.update();
    }

    // Quit window
    window.destroy();

    return 0;
}
