#include "SupportFunctions.h"

SDL_Texture* SDL_SupportFunc::loadImg(SDL_Renderer* _renderer, string fileimg)
{
    //IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    g_screenSurface = IMG_Load(fileimg.c_str());

    if (g_surface == NULL) {
        cout << "IMG_Load: " << IMG_GetError() << endl;
    }

    g_texture = SDL_CreateTextureFromSurface(_renderer, g_surface);

    if (g_texture == NULL) {
        cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
    }

    return g_texture;
}

void SDL_SupportFunc::showImg(SDL_Renderer* render, SDL_Texture* texture, SDL_Rect destRect) {
    SDL_RenderCopy(render, texture, NULL, &destRect);
}

void SDL_SupportFunc::cleanUp() {
    if (g_background != NULL) SDL_FreeSurface(g_background);
    g_background = NULL;

    if (g_windows != NULL) SDL_DestroyWindow(g_windows);
    g_windows = NULL;

    if(g_texture != NULL) SDL_DestroyTexture(g_texture);
    g_texture = NULL;

    if (g_renderer != NULL) SDL_RenderClear(g_renderer);
    g_renderer = NULL;

    SDL_Quit();
}
