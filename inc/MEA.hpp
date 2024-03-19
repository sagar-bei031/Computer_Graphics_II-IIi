#pragma once

#include <SDL2/SDL.h>

/* Mid-Point Ellipse Drawing Algorithm */
namespace MEA
{
    void drawEllipse(SDL_Renderer *renderer, int xc, int yc, int rx, int ry);

    void renderEllipse(SDL_Renderer *renderer, int xc, int yc, int x, int y);
};