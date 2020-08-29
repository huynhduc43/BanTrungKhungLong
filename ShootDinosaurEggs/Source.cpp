#include "Object.h"
#include "SupportFunctions.h"

using namespace SDL_SupportFunc;

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        g_windows = SDL_CreateWindow("SDL Shoot Dinosaur Eggs",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        g_renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);

        if (g_windows != NULL)
        {
            g_screenSurface = SDL_GetWindowSurface(g_windows);
        }
    }
    return success;
}

int main(int argc, char* argv[])
{
    if (init() == true)
    {
        Object A;
        SDL_Rect temp {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

        A.loadImage(g_renderer, temp, "Images//test.jpg");

        bool is_quit = false;
        SDL_Event g_event;
        while (!is_quit)
        {
            while (SDL_PollEvent(&g_event))
            {
                if (g_event.type == SDL_QUIT)
                {
                    is_quit = true;
                    break;
                }
            }
            SDL_RenderClear(g_renderer);
            A.showImage();
            SDL_RenderPresent(g_renderer);
        }
    }
    SDL_DestroyRenderer(g_renderer);
    cleanUp();
    return 0;
}