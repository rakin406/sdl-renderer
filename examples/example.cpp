#include "../include/window.h"

#include <string>

namespace
{
// Screen constants
constexpr int SCREEN_WIDTH{ 1000 };
constexpr int SCREEN_HEIGHT{ 750 };
} // namespace

int main()
{
    Window window("Example", SCREEN_WIDTH, SCREEN_HEIGHT);
    bool run{ true };

    while (run)
    {
        if (window.isQuitRequested())
        {
            run = false;
        }

        // Clear screen with background color which is white by default
        window.clear();

        // ----------Draw or update stuff here-----------

        window.update();
    }

    window.destroy();

    return 0;
}
