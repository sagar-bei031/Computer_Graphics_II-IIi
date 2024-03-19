#include "BLA.hpp"
#include "DDA.hpp"
#include "LineClipper.hpp"
#include "MCA.hpp"
#include "MEA.hpp"
#include "rectangle.hpp"
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Computer Graphics Lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
            }
        }

        // Clear surface
        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);

        // Draw Line 1
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        DDA::drawLine(renderer, 800, 0, 960, 720);

        // Draw Line 2
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        BLA::drawLine(renderer, 800, 720, 960, 0);

        // // Draw Circle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        MCA::drawCircle(renderer, 700, 400, 200);

        // Draw Ellipse
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        MEA::drawEllipse(renderer, 600, 400, 200, 100);

        // Draw Rectangle
        Rectangle rec(50, 50, 200, 100, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        rec.render(renderer);

        // Scale Rectangle
        rec.scale(2, 2);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        rec.render(renderer);

        // Translate Rectangle
        rec.translate(0, 250);
        SDL_SetRenderDrawColor(renderer, 100, 200, 0, 255);
        rec.render(renderer);

        // Rotate Rectangle
        rec.rotate(-M_PI_4);
        SDL_SetRenderDrawColor(renderer, 0, 200, 100, 255);
        rec.render(renderer);

        int x1 = 0, y1 = 0, x2 = 960, y2 = 720;
        int x_min = 100, x_max = 860, y_min = 100, y_max = 620;

        // Draw original line to be clipped
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        BLA::drawLine(renderer, x1, y1, x2, y2);

        // Drawing Clipping Box
        SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
        SDL_Rect rr{x_min, y_min, x_max - x_min, y_max - y_min};
        SDL_RenderDrawRect(renderer, &rr);

        // Clip and Draw Line
        if (LBA::clipLine(x1, y1, x2, y2, x_min, x_max, y_min, y_max))
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            BLA::drawLine(renderer, x1, y1, x2, y2);
        }

        // Pull back buffer on to front buffer
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
