#include "MEA.hpp"
#include <math.h>

void MEA::drawEllipse(SDL_Renderer *renderer, int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int px = 0;
    int py = 2 * rx2 * y;
    int p;

    // Draw starting point
    renderEllipse(renderer, xc, yc, x, y);

    // For first region
    p = round(ry2 - rx2 * ry + 0.25f * rx2);

    while (px < py)
    {
        ++x;
        px += 2 * ry2;
        p += ry2 + px;

        if (p > 0)
        {
            --y;
            py -= 2 * rx2;
            p -= py;
        }


        renderEllipse(renderer, xc, yc, x, y);
    }

    // For second region
    p = round(ry2 * (x + 0.5f) * (x + 0.5f) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);

    while (y >= 0)
    {
        --y;
        py -= 2 * rx2;
        p += rx2 - py;

        if (p < 0)
        {
            ++x;
            px += 2 * ry2;
            p += px;
        }

        renderEllipse(renderer, xc, yc, x, y);
    }
}

void MEA::renderEllipse(SDL_Renderer *renderer, int xc, int yc, int x, int y)
{
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
}