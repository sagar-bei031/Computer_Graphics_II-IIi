#include "BLA.hpp"

void BLA::drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    int x = x1;
    int y = y1;
    int p;

    SDL_RenderDrawPoint(renderer, x, y);

    if (dx > dy)
    {
        p = 2 * dy - dx;

        while (x != x2)
        {
            x += sx;
            p += 2 * dy;

            if (p > 0)
            {
                y += sy;
                p -= 2 * dx;
            }

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    else
    {
        p = 2 * dx - dy;
        
        while (y != y2)
        {
            y += sy;
            p += 2 * dx;

            if (p > 0)
            {
                x += sx;
                p -= 2 * dy;
            }

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
