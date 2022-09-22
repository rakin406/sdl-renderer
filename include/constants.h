#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

#include "utils.h"

// Screen constants
constexpr char SCREEN_TITLE[] = "Avoid me";
constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 750;

// Color constants
constexpr RGB SCREEN_COLOR = {253, 248, 150};
constexpr RGB PLAYER_COLOR = {119, 221, 119};
constexpr RGB ENEMY_COLOR = {255, 105, 97};

// Enemy constant
constexpr int MAX_ENEMIES = 5;

// Entity tags
const std::string PLAYER_TAG = "player";
const std::string ENEMY_TAG = "enemy";

#endif
