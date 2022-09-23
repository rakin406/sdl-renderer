#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <array>
#include <glm/vec2.hpp>

// Entity tags
enum class Tag
{
    Player,
    Enemy
};

struct Circle
{
    glm::ivec2 centerPos;
    int radius; // Radius of the circle
};

struct Triangle
{
    std::array<glm::ivec2, 3> points;
    glm::ivec2 centerPos;
    int size;
};

#endif
