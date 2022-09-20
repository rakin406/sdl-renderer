#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>

// Screen constants
constexpr char SCREEN_TITLE[] = "Avoid me";
constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 750;

// Color constants
constexpr std::array<int, 3> SCREEN_COLOR = {253, 248, 150};
constexpr std::array<int, 3> PLAYER_COLOR = {119, 221, 119};
constexpr std::array<int, 3> ENEMY_COLOR = {255, 105, 97};

// Player radius
constexpr int PLAYER_RADIUS = 40;

#endif
