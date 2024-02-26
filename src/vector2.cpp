#include "vector2.hpp"
#include <math.h>

Vector2 Vector2::scale(float sx, float sy)
{
    x *= sx;
    y *= sy;
    return *this;
}

Vector2 Vector2::translate(int hx, int hy)
{
    x += hx;
    y += hy;
    return *this;
}

Vector2 Vector2::rotate(float angle)
{
    int px = x, py = y;
    x = px * cos(angle) - py * sin(angle);
    y = px * sin(angle) + py * cos(angle);
    return *this;
}