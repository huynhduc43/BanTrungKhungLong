#include "ShootDinosaurEggsGame.h"

ShootDinosaurEggsGame::ShootDinosaurEggsGame() {
    this->_windows = NULL;
    this->_screenSurface = NULL;
    this->_background = NULL;
    this->_texture = NULL;
    this->_surface = NULL;
    this->_renderer = NULL;
    
    //Texture background
    this->_texture0 = NULL;
    this->_texture1 = NULL;
    this->_texture2 = NULL;
    this->_texture3 = NULL;
}

ShootDinosaurEggsGame::~ShootDinosaurEggsGame() {
    cout << "Goi ham huy Game!" << endl;
    if (_background != NULL) SDL_FreeSurface(_background);
    g_background = NULL;

    if (_windows != NULL) SDL_DestroyWindow(_windows);
    g_windows = NULL;

    if (_texture != NULL) SDL_DestroyTexture(_texture);
    g_texture = NULL;

    if (g_renderer != NULL) SDL_RenderClear(_renderer);
    _renderer = NULL;

    //============================================================================
    if (_texture0 != NULL) SDL_DestroyTexture(_texture0);
    _texture0 = NULL;

    if (_texture1 != NULL) SDL_DestroyTexture(_texture1);
    _texture1 = NULL;

    if (g_texture2 != NULL) SDL_DestroyTexture(_texture2);
    _texture1 = NULL;

    if (_texture3 != NULL) SDL_DestroyTexture(_texture3);
    _texture3 = NULL;
}

void ShootDinosaurEggsGame::initBackground() {
    _renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);

    _texture0 = LoadImage(_renderer, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, bk0);
    _texture1 = LoadImage(_renderer, { 565, 42, 584, 875 }, bk1);
    _texture2 = LoadImage(_renderer, { 130, 42, 442, 875 }, bk2);
    _texture3 = LoadImage(_renderer, { 800, 820, 140, 123 }, cannon);
    this->_egg.loadImgEggWithType(this->_renderer, { 565, 42, 50, 70 }, "0");
}

bool ShootDinosaurEggsGame::initData() {
    bool success = true;
    
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        g_windows = SDL_CreateWindow("SDL 2.0 Shoot Dinosaur Eggs",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (g_windows != NULL)
        {
            g_screenSurface = SDL_GetWindowSurface(g_windows);
        }
    }

    return success;
}

void ShootDinosaurEggsGame::showBackground() {
    this->showImageWithRect(_texture0, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
    this->showImageWithRect(_texture1, { 565, 42, 584, 875 });
    this->showImageWithRect(_texture2, { 130, 42, 442, 875 });
    this->showImageWithRect(_texture3, { 800, 820, 140, 123 });
    //this->_egg.showImage();
    SDL_RenderPresent(_renderer);
    //SDL_Delay(1000 / DEFAULT_FPS);
}

SDL_Texture* ShootDinosaurEggsGame::LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
    this->_renderer = renderer;
    this->_rect = rect;
    this->_surface = IMG_Load(file_path.c_str());

    if (this->_surface == NULL) {
        cout << "IMG_Load: " << IMG_GetError() << endl;
    }
    else {
        this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_surface);

        if (this->_texture == NULL) {
            cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
        }
        else {
            SDL_FreeSurface(this->_surface);
        }
    }

    return _texture;
}

void ShootDinosaurEggsGame::showImageWithRect(SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(this->_renderer, texture, NULL, &rect);
}

void ShootDinosaurEggsGame::showImgTest() {
    //cout << "Called showImgTest" << endl;
    _egg.showImage();
    //this->showImageWithRect(_texture3, { 800, 820, 140, 123 });
    SDL_RenderPresent(_renderer);
    //SDL_Delay(1000 / DEFAULT_FPS);
}
