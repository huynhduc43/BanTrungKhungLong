#include "SupportFunctions.h"



//SDL_Texture* SDL_SupportFunc::loadImg(SDL_Renderer* _renderer, string fileimg)
//{
//    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
//    g_surface = IMG_Load(fileimg.c_str());
//
//    if (g_surface == NULL) {
//        cout << "IMG_Load: " << IMG_GetError() << endl;
//    }
//    else {
//        g_texture = SDL_CreateTextureFromSurface(_renderer, g_surface);
//        SDL_FreeSurface(g_surface);
//    }
//
//    if (g_texture == NULL) {
//        cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
//    }
//
//    return g_texture;
//}

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
    //============================================================================

    if (g_texture1 != NULL) SDL_DestroyTexture(g_texture1);
    g_texture1 = NULL;

    if (g_texture2 != NULL) SDL_DestroyTexture(g_texture2);
    g_texture1 = NULL;

    if (g_texture3 != NULL) SDL_DestroyTexture(g_texture3);
    g_texture3 = NULL;
    
    cout << "Goi ham cleanUp" << endl;
    SDL_Quit();
}

void SDL_SupportFunc::findCenter(SDL_Point& center, SDL_Rect& rect) {
    center.x = rect.x + rect.w / 2;
    center.y = rect.y + rect.h / 2;
    //rect.x = center.x - rect.w / 2;
    //rect.y = center.y - rect.h / 2;
    //cout << "center ( " << center.x << ", " << center.y << " )" << endl;
}

float SDL_SupportFunc::calcDistance2Point(SDL_Point pointA, SDL_Point pointB) {
    return sqrt(pow((pointA.x - pointB.x), 2) + pow((pointA.y - pointB.y), 2));
}
