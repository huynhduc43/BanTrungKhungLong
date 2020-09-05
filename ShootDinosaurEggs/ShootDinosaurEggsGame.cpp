#include "ShootDinosaurEggsGame.h"

ShootDinosaurEggsGame::ShootDinosaurEggsGame() {
    this->_windowsGame = NULL;
    this->_screenSurfaceGame = NULL;
    this->_backgroundGame = NULL;
    this->_textureGame = NULL;
    this->_surfaceGame = NULL;
    this->_rendererGame = NULL;
    isPlaying = true;
    
    this->_listRect.push_back(BACKGROUND);
    this->_listRect.push_back(AREA_PLAY);
    this->_listRect.push_back(MENU);
    this->_listRect.push_back(CANNON);
}

ShootDinosaurEggsGame::~ShootDinosaurEggsGame() {
    cout << "Goi ham huy Game!" << endl;
    if (_backgroundGame != NULL) SDL_FreeSurface(_backgroundGame);
    _backgroundGame = NULL;

    if (_windowsGame != NULL) SDL_DestroyWindow(_windowsGame);
    _windowsGame = NULL;

    if (_textureGame != NULL) SDL_DestroyTexture(_textureGame);
    _textureGame = NULL;

    if (_rendererGame != NULL) SDL_RenderClear(_rendererGame);
    _rendererGame = NULL;

    //============================================================================
    /*if (_texture0 != NULL) SDL_DestroyTexture(_texture0);
    _texture0 = NULL;

    if (_texture1 != NULL) SDL_DestroyTexture(_texture1);
    _texture1 = NULL;

    if (g_texture2 != NULL) SDL_DestroyTexture(_texture2);
    _texture1 = NULL;

    if (_texture3 != NULL) SDL_DestroyTexture(_texture3);
    _texture3 = NULL;*/
}

bool ShootDinosaurEggsGame::initData() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        this->_windowsGame = SDL_CreateWindow("SDL 2.0 Shoot Dinosaur Eggs",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (this->_windowsGame != NULL)
        {
            this->_screenSurfaceGame = SDL_GetWindowSurface(this->_windowsGame);
            this->_rendererGame = SDL_CreateRenderer(this->_windowsGame, -1, SDL_RENDERER_ACCELERATED);

            if (this->_rendererGame == NULL) {
                cout << "Error InitBackGround: " << SDL_GetError() << endl;
            }
        }
    }

    return success;
}

void ShootDinosaurEggsGame::initBackground() { 
    this->_listTexture.push_back(LoadImage(_rendererGame, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, bk0));
    this->_listTexture.push_back(LoadImage(_rendererGame, { Object::AREA_PLAY_BORDER_LEFT, Object::AREA_PLAY_BORDER_TOP, Object::AREA_PLAY_WIDTH, Object::AREA_PLAY_HEIGHT }, bk1));
    this->_listTexture.push_back(LoadImage(_rendererGame, { Object::AREA_MENU_BORDER_LEFT, Object::AREA_MENU_BORDER_TOP, Object::AREA_MENU_WIDTH, Object::AREA_MENU_HEIGHT }, bk2));
    this->_listTexture.push_back(LoadImage(_rendererGame, { Object::CANNON_POS_X, Object::CANNON_POS_Y, Object::CANNON_WIDTH, Object::CANNON_HEIGHT }, cannon));
 
    this->_eggShoot.setEgg(this->_rendererGame, { 838, 788, 46, 46 }, 3); 
}


void ShootDinosaurEggsGame::showBackground() {
    for (int i = 0; i < this->_listRect.size(); i++) {
        showImageWithTexture_Rect(this->_listTexture[i], this->_listRect[i]);
    }
    this->_eggShoot.showImg();
}

SDL_Texture* ShootDinosaurEggsGame::LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
    this->_rendererGame = renderer;

   // this->_rectGame = rect;
    //findCenter(this->_center, this->_rect);

    this->_surfaceGame = IMG_Load(file_path.c_str());

    if (this->_surfaceGame == NULL) {
        cout << "IMG_Load: " << IMG_GetError() << endl;
    }
    else {
        this->_textureGame = SDL_CreateTextureFromSurface(this->_rendererGame, this->_surfaceGame);

        if (this->_textureGame == NULL) {
            cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
        }
        else {
            SDL_FreeSurface(this->_surfaceGame);
        }
    }

    return _textureGame;
}

void ShootDinosaurEggsGame::showImageWithTexture_Rect(SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(this->_rendererGame, texture, NULL, &rect);
}

void ShootDinosaurEggsGame::playGame(SDL_Event &mainEvent) {
    int mouse_x = 0;
    int mouse_y = 0;
    bool stop = false;

    _arrow.loadImage(this->_rendererGame, { Object::ARROW_POS_X ,Object::ARROW_POS_Y, Object::ARROW_WIDTH, Object::ARROW_HEIGHT}, "Images//equipment//arrow.png");
    //this->_eggShoot.getEgg().setTypeEgg(0);
    //this->_eggShoot.setEgg(this->_rendererGame, { 838, 788, 46, 46 }, this->_eggShoot.getEgg().randomTypeOfEgg());
    while (SDL_PollEvent(&mainEvent) || stop == false) {
        switch (mainEvent.type) {
        case SDL_MOUSEBUTTONDOWN: {
            //mouse_x = mainEvent.motion.x - 35;
            //mouse_y = mainEvent.motion.y;
            //cout << "( " << mouse_x << ", " << mouse_y << " )" << endl;

            if (mainEvent.button.button == SDL_BUTTON_LEFT) {
                //this->_eggShoot.setEgg(this->_rendererGame, { 838, 788, 46, 46 }, this->_eggShoot.getEgg().randomTypeOfEgg());
            }

            break;
        }
        case SDL_QUIT: {
            stop = true;
            //SDL_DestroyRenderer(this->_rendererGame);
            break;
        }
        default:
            break;
        }

        SDL_RenderClear(this->_rendererGame);
        this->showBackground();
        _arrow.showImageWithMouse(mainEvent);

        SDL_RenderPresent(_rendererGame);
        SDL_Delay(2000 / DEFAULT_FPS);

    }
}
