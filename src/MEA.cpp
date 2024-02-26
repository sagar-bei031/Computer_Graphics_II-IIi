#include "MEA.hpp"
#include <math.h>

void MEA::drawEllipse(SDL_Renderer *renderer, int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;
    float rx2 = rx * rx;
    float ry2 = ry * ry;
    float px = 0;
    float py = 2 * rx2 * y;
    float p;

    // Draw starting point
    renderEllipse(renderer, xc, yc, x, y);

    // Draw the first region
    p = round(ry2 - rx2 * ry + 0.25f * rx2);
    while (px < py)
    {
        ++x;
        px += 2 * ry2;

        if (p < 0)
        {
            p += ry2 + px;
        }
        else
        {
            --y;
            py -= 2 * rx2;
            p += ry2 + px - py;
        }

        renderEllipse(renderer, xc, yc, x, y);
    }

    // Draw the second region
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0)
    {
        --y;
        py -= 2 * rx2;
        if (p > 0)
        {
            p += rx2 - py;
        }
        else
        {
            ++x;
            px += 2 * ry2;
            p += rx2 - py + px;
        }

        renderEllipse(renderer, xc, yc, x, y);
    }
}

inline void MEA::renderEllipse(SDL_Renderer *renderer, int xc, int yc, int x, int y)
{
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
}