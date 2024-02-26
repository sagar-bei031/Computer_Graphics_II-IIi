#pragma once

class Vector2
{
public:
    int x = 0;
    int y = 0;

    Vector2 scale(float sx, float sy);

    Vector2 translate(int hx, int hy);

    Vector2 rotate(float angle);
};