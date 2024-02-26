#pragma once

#include <SDL2/SDL.h>
#include <math.h>

/* Digital Differential Analyzer */
namespace DDA
{
    void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
    {
        float dx = x2 - x1;
        float dy = y2 - y1;
        int steps;

        if (abs(dx) > abs(dy))
        {
            steps = abs(dx);
        }
        else
        {
            steps = abs(dy);
        }

        dx /= steps;
        dy /= steps;
        
        float x = x1;
        float y = y1;

        for (int i = 0; i <= steps; ++i)
        {
            SDL_RenderDrawPoint(renderer, round(x), round(y));
            x += dx;
            y += dy;
        }
    }
};