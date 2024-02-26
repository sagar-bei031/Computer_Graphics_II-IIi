#pragma once

#include <SDL2/SDL.h>

/* Digital Differential Analyzer */
namespace DDA
{
    void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
};