#pragma once

#include <SDL2/SDL.h>

namespace BLA
{
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
    {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        int sx = x1 < x2 ? 1 : -1;
        int sy = y1 < y2 ? 1 : -1;

        int x = x1;
        int y = y1;

        if (dy > dx)
        {
            swap(dx, dy);
            swap(sx, sy);
            swap(x, y);
        }

        int p = 2 * dy - dx;

        for (int i = 0; i <= dx; ++i)
        {
            SDL_RenderDrawPoint(renderer, x, y);

            while (p > 0)
            {
                y += sy;
                p -= 2 * dx;
            }

            x += sx;
            p += 2 * dy;
        }
    }
};
