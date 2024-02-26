#include "BLA.hpp"

void BLA::drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;

    SDL_RenderDrawPoint(renderer, x, y);

    if (dx > dy)
    {
        while (x != x2)
        {
            if (p > 0)
            {
                y += sy;
                p -= 2 * dx;
            }

            x += sx;
            p += 2 * dy;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    else
    {
        while (y != y2)
        {
            if (p > 0)
            {
                x += sx;
                p -= 2 * dy;
            }
            
            y += sy;
            p += 2 * dx;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

inline void BLA::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
