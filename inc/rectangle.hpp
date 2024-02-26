#pragma once

#include "vector2.hpp"
#include <SDL2/SDL.h>

class Rectangle
{
public:
    Vector2 origin;
    Vector2 width;
    float orientation;

    Rectangle(int x, int y, int wx, int wy, float orien);

    Rectangle() = default;
    Rectangle(const Rectangle &) = default;
    Rectangle &operator=(const Rectangle &) = default;
    ~Rectangle() = default;

    Rectangle scale(float sx, float sy);

    Rectangle translate(int hx, int hy);

    Rectangle rotate(float angle);

    void render(SDL_Renderer *renderer);
};