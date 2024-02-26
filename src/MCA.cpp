#include "MCA.hpp"

void MCA::drawCircle(SDL_Renderer *renderer, int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    renderCircle(renderer, xc, yc, x, y);

    while (x < y)
    {
        ++x;

        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        renderCircle(renderer, xc, yc, x, y);
    }
}

inline void MCA::renderCircle(SDL_Renderer *renderer, int xc, int yc, int x, int y)
{
    SDL_RenderDrawPoint(renderer, xc + x, yc + y); /* First I */
    SDL_RenderDrawPoint(renderer, xc + y, yc + x); /* First II */
    SDL_RenderDrawPoint(renderer, xc - x, yc + y); /* Second I */
    SDL_RenderDrawPoint(renderer, xc - y, yc + x); /* Second II */
    SDL_RenderDrawPoint(renderer, xc - x, yc - y); /* Third I */
    SDL_RenderDrawPoint(renderer, xc - y, yc - x); /* Third II */
    SDL_RenderDrawPoint(renderer, xc + x, yc - y); /* Fourth I */
    SDL_RenderDrawPoint(renderer, xc + y, yc - x); /* Fourth II */
}