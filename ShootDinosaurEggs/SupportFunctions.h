#pragma once
#ifndef SUPPORTFUNCTIONS_H_
#define SUPPORTFUNCTIONS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
using namespace std;

//Các giá trị mặc định
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const int DEFAULT_FPS = 60;

static SDL_Window* g_windows = NULL;
static SDL_Surface* g_screenSurface = NULL;
static SDL_Surface* g_background = NULL;
static SDL_Texture* g_texture = NULL;
static SDL_Surface* g_surface = NULL;
static SDL_Renderer* g_renderer = NULL;

//Texture background
static SDL_Texture* g_texture1 = NULL;
static SDL_Texture* g_texture2 = NULL;
static SDL_Texture* g_texture3 = NULL;

//File path
const string bk0 = "Images//graphic//background0.png";
const string bk1 = "Images//graphic//background1_1.png";
const string bk2 = "Images//graphic//background2_0.png";
const string cannon = "Images//equipment//cannon.png";
const string egg = "Images//eggs//egg0.png";

//extern SDL_Window* g_windows;
//extern SDL_Surface* g_screenSurface;
//extern SDL_Surface* g_background;
//extern SDL_Surface* g_surface;
//extern SDL_Renderer* g_renderer;
//
//extern SDL_Texture* g_texture;
//
////Texture background
//extern SDL_Texture* g_texture1;
//extern SDL_Texture* g_texture2;
//extern SDL_Texture* g_texture3;

namespace SDL_SupportFunc {
    SDL_Texture* loadImg(SDL_Renderer* _renderer, string fileimg);
    void showImg(SDL_Renderer* render, SDL_Texture* texture, SDL_Rect destRect);
    void cleanUp();
}

//SDL_Surface* g_surface;
//SDL_Texture* g_texture;
//SDL_Rect src_rect;

#endif // !SUPPORTFUNCTIONS_H_


//#include <SDL.h>
//#include <SDL_image.h>
//#include <string>
//#include <iostream>
//using namespace std;
//
//SDL_Window* g_windows = NULL;
//SDL_Surface* gScreenSurface = NULL;
//SDL_Surface* g_background = NULL;
//
//
//SDL_Surface* _surface;
//SDL_Texture* _texture;
//SDL_Rect src_rect;
//
//SDL_Renderer* _renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
//
//void LoadImg(SDL_Renderer* _renderer, string fileimg)
//{
//    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
//    _surface = IMG_Load(fileimg.c_str());
//    if (_surface == NULL) {
//        cout <<"IMG_Load: " << IMG_GetError() << endl;
//    }
//    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
//
//    if (_texture == NULL) {
//        cout << SDL_GetError() << endl;
//    }
//}
//
//void closeAll()
//{
//    SDL_FreeSurface(g_background);
//    g_background = NULL;
//    SDL_DestroyWindow(g_windows);
//    g_windows = NULL;
//    SDL_DestroyTexture(_texture);
//    SDL_Quit();
//}
//
//bool init()
//{
//    bool success = true;
//    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
//    {
//        g_windows = SDL_CreateWindow("SDL Shoot Dinosaur Eggs", 
//                                    SDL_WINDOWPOS_UNDEFINED, 
//                                    SDL_WINDOWPOS_UNDEFINED, 
//                                    1200, 720, SDL_WINDOW_SHOWN);
//        if (g_windows != NULL)
//        {
//            gScreenSurface = SDL_GetWindowSurface(g_windows);
//        }
//    }
//    return success;
//}
//
//
//
//int main(int argc, char* argv[])
//{
//    SDL_Renderer* _renderer = NULL;
//    if (init() == true)
//    {
//        _renderer = SDL_CreateRenderer(g_windows, -1, 0);
//        Object A;
//        SDL_Rect temp;
//        temp.x = 0;
//        temp.y = 0;
//        temp.w = 1200;
//        temp.h = 720;
//        A.loadImage(_renderer, temp, "Images//test.jpg");
//        //A.showImage();
//        //LoadImg(_renderer, "Images//test.jpg");
//        //SDL_RenderCopy(_renderer, _texture, NULL, NULL);
//        //SDL_RenderPresent(_renderer);
//        //SDL_Delay(2000);
//        //SDL_SetWindowFullscreen(g_windows, SDL_WINDOW_FULLSCREEN);
//        bool is_quit = false;
//        SDL_Event g_even;
//        while (!is_quit)
//        {
//            
//            while (SDL_PollEvent(&g_even))
//            {
//                if (g_even.type == SDL_QUIT)
//                {
//                    is_quit = true;
//                    break;
//                }
//            }
//            SDL_RenderClear(_renderer);
//            A.showImage();
//            SDL_RenderPresent(_renderer);
//        }
//    }
//    SDL_DestroyRenderer(_renderer);
//    closeAll();
//    return 0;
//}