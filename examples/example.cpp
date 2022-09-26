#include "../include/window.h"

#include <string>

namespace
{
// Screen constants
constexpr int kScreenWidth { 1000 };
constexpr int kScreenHeight { 750 };
} // namespace

int main()
{
    // Initialize SDL window
    Window window("Example", kScreenWidth, kScreenHeight);

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
