#include "Object.h"
#include "SupportFunctions.h"
#include "ShootDinosaurEggsGame.h"
#include "Egg.h"
using namespace SDL_SupportFunc;

//bool init()
//{
//    bool success = true;
//
//    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
//    {
//        g_windows = SDL_CreateWindow("SDL Shoot Dinosaur Eggs",
//                                    SDL_WINDOWPOS_UNDEFINED,
//                                    SDL_WINDOWPOS_UNDEFINED,
//                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//
//        g_renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
//
//        if (g_windows != NULL)
//        {
//            g_screenSurface = SDL_GetWindowSurface(g_windows);
//        }
//    }
//
//    return success;
//}
//
//int main(int argc, char* argv[])
//{
//    if (init() == true)
//    {
//        //Object A;
//        SDL_Rect temp {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
//
//        //A.loadImage(g_renderer, temp, "Images//test.jpg");
//        g_texture = loadImg(g_renderer, "Images//graphic//background.png");
//        SDL_Texture* g_object = loadImg(g_renderer, "Images//egg0.png");
//        bool is_quit = false;
//        SDL_Event g_event;
//        while (!is_quit)
//        {
//            while (SDL_PollEvent(&g_event))
//            {
//                if (g_event.type == SDL_QUIT)
//                {
//                    is_quit = true;
//                    break;
//                }
//            }
//
//            SDL_RenderClear(g_renderer);
//            //A.showImage();
//            showImg(g_renderer, g_texture, temp);
//            showImg(g_renderer, g_object, {0,0,50,50});
//            SDL_RenderPresent(g_renderer);
//        }
//    }
//    SDL_DestroyRenderer(g_renderer);
//    cleanUp();
//    return 0;
//}

//SDL_Window* g_windows = NULL;
//SDL_Surface* g_screenSurface = NULL;
//SDL_Surface* g_background = NULL;
//SDL_Texture* g_texture = NULL;
//SDL_Surface* g_surface = NULL;
//SDL_Renderer* g_renderer = NULL;
//
////Texture background
//SDL_Texture* g_texture1 = NULL;
//SDL_Texture* g_texture2 = NULL;
//SDL_Texture* g_texture3 = NULL;


int main(int argc, char* argv[])
{
    ShootDinosaurEggsGame Game;

    if (Game.initData() == true)
    {
        Game.initBackground();

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
            /*if (g_renderer == NULL) {
                cout << "show: " << SDL_GetError() << endl;
            }*/

            /*if (g_windows == NULL) {
                cout << "g_windows: " << SDL_GetError() << endl;
            }*/

            Game.showBackground();
            Game.showImgTest();
            SDL_Delay(2000 / DEFAULT_FPS);

        }
    }
    SDL_DestroyRenderer(g_renderer);
    cleanUp();
    return 0;
}