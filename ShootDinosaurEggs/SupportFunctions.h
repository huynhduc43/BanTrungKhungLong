﻿#pragma once
#ifndef SUPPORTFUNCTIONS_H_
#define SUPPORTFUNCTIONS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <math.h>
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

    void findCenter(SDL_Point& pos, SDL_Rect& rect);
    float calcDistance2Point(SDL_Point pointA, SDL_Point pointB);
}

//SDL_Surface* g_surface;
//SDL_Texture* g_texture;
//SDL_Rect src_rect;

#endif // !SUPPORTFUNCTIONS_H_