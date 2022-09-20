#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>

// Screen constants
const char SCREEN_TITLE[] = "Avoid me";
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 750;

// Color constants
const std::array<int, 3> SCREEN_COLOR = {253, 248, 150};
const std::array<int, 3> PLAYER_COLOR = {119, 221, 119};
const std::array<int, 3> ENEMY_COLOR = {255, 105, 97};

// Player radius
const int PLAYER_RADIUS = 5;

#endif
