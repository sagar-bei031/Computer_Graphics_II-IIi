#pragma once

#include <SDL2/SDL.h>

/* Bresenham's Line Drawing Algorithm */
namespace BLA
{
    void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
    
    void swap(int &a, int &b);
};
