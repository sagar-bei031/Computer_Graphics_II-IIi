#pragma once

#include <SDL2/SDL.h>

/* Mid-Point Circle Drawing Algorithm */
namespace MCA
{
    void drawCircle(SDL_Renderer *renderer, int xc, int yc, int r);

    inline void renderCircle(SDL_Renderer *renderer, int xc, int yc, int x, int y);
};