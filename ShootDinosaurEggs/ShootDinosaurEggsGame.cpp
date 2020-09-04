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
    _texture1 = LoadImage(_renderer, { AREA_PLAY_BORDER_LEFT, AREA_PLAY_BORDER_TOP, AREA_PLAY_WIDTH, AREA_PLAY_HEIGHT }, bk1);
    _texture2 = LoadImage(_renderer, { AREA_MENU_BORDER_LEFT, AREA_MENU_BORDER_TOP, AREA_MENU_WIDTH, AREA_MENU_HEIGHT }, bk2);
    _texture3 = LoadImage(_renderer, { CANNON_POS_X, CANNON_POS_Y, CANNON_WIDTH, CANNON_HEIGHT }, cannon);
    //this->_egg.loadImgEggWithType(this->_renderer, { 572, 42, 45, 59 }, 3);
    //this->_egg.loadImgEggWithType(this->_renderer, { 822, 788, 46, 46 }, 0);
    this->_eggShoot.setEgg(this->_renderer, { 838, 788, 46, 46 }, 0);
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
    this->showImageWithRect(_texture3, { 791, 800, 140, 124 });
    this->_eggShoot.showImg();


}

SDL_Texture* ShootDinosaurEggsGame::LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
    this->_renderer = renderer;

    this->_rect = rect;
    findCenter(this->_center, this->_rect);

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
    findCenter(this->_center, rect);
    //rect.x = this->_center.x + rect.w / 2;
    SDL_RenderCopy(this->_renderer, texture, NULL, &rect);
}

void ShootDinosaurEggsGame::showImgTest() {
    //_egg.showImage();
}

void ShootDinosaurEggsGame::playGame(SDL_Event &mainEvent) {
    int mouse_x = 0;
    int mouse_y = 0;
    bool stop = false;

    Object arrow;
    arrow.loadImage(this->_renderer, { Object::ARROW_POS_X ,Object::ARROW_POS_Y, Object::ARROW_WIDTH, Object::ARROW_HEIGHT}, "Images//equipment//arrow.png");
    while (SDL_PollEvent(&mainEvent) || stop == false) {
        switch (mainEvent.type) {
        case SDL_MOUSEBUTTONDOWN: {
            //mouse_x = mainEvent.motion.x - 35;
            //mouse_y = mainEvent.motion.y;
            //cout << "( " << mouse_x << ", " << mouse_y << " )" << endl;

            if (mainEvent.button.button == SDL_BUTTON_LEFT) {
                //this->_eggShoot.setEgg(this->_renderer, { 822, 788, 46, 46 }, this->_eggShoot.getEgg().randomTypeOfEgg());
            }

            break;
        }
        case SDL_QUIT: {
            stop = true;
            break;
        }
        default:
            break;
        }

        SDL_RenderClear(this->_renderer);

        this->showBackground();
        //this->showImgTest()
        arrow.showImageWithMouse(mainEvent);
        SDL_RenderPresent(_renderer);
        SDL_Delay(2000 / DEFAULT_FPS);

    }
}
