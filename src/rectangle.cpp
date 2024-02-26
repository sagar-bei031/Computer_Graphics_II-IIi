#include "rectangle.hpp"
#include "BLA.hpp"

Rectangle::Rectangle(int x, int y, int wx, int wy, float orien)
    : origin{x, y}, width{wx, wy}, orientation(orien) {}

Rectangle Rectangle::scale(float sx, float sy)
{
    width.scale(sx, sy);
    return *this;
}

Rectangle Rectangle::translate(int hx, int hy)
{
    origin.translate(hx, hy);
    return *this;
}

Rectangle Rectangle::rotate(float angle)
{
    orientation += angle;
    return *this;
}

void Rectangle::render(SDL_Renderer *renderer)
{
    Vector2 v[4];
    v[0] = Vector2{0, 0};
    v[1] = Vector2{width.x, 0};
    v[2] = Vector2{0, width.y};
    v[3] = Vector2{width.x, width.y};

    for (int i = 0; i < 4; ++i)
    {
        v[i].rotate(orientation);
        v[i].translate(origin.x, origin.y);
    }

    BLA::drawLine(renderer, v[0].x, v[0].y, v[1].x, v[1].y);
    BLA::drawLine(renderer, v[0].x, v[0].y, v[2].x, v[2].y);
    BLA::drawLine(renderer, v[1].x, v[1].y, v[3].x, v[3].y);
    BLA::drawLine(renderer, v[2].x, v[2].y, v[3].x, v[3].y);
}