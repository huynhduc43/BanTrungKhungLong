#include "Object.h"
#include "SupportFunctions.h"
#include "ShootDinosaurEggsGame.h"
#include "Egg.h"
using namespace SDL_SupportFunc;

//int main(int argc, char* argv[])
//{
//    ShootDinosaurEggsGame Game;
//
//    if (Game.initData() == true)
//    {
//        Game.initBackground();
//
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
//            /*if (g_renderer == NULL) {
//                cout << "show: " << SDL_GetError() << endl;
//            }*/
//
//            /*if (g_windows == NULL) {
//                cout << "g_windows: " << SDL_GetError() << endl;
//            }*/
//
//            Game.showBackground();
//            Game.showImgTest();
//            SDL_Delay(2000 / DEFAULT_FPS);
//
//        }
//    }
//    SDL_DestroyRenderer(g_renderer);
//    cleanUp();
//    return 0;
//}

int main(int argc, char* argv[])
{
    ShootDinosaurEggsGame Game;

    if (Game.initData(g_renderer, g_windows) == true)
    {
        Game.initBackground(g_renderer);
        SDL_Event g_event;
        Game.playGame(g_renderer, g_event);
    }
    SDL_DestroyRenderer(g_renderer);
    cleanUp();
    return 0;
}