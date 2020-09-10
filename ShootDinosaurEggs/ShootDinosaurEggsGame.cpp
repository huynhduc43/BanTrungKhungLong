#include "ShootDinosaurEggsGame.h"

ShootDinosaurEggsGame::ShootDinosaurEggsGame() {
    isPlaying = true;
    
    //this->_listRect.push_back(BACKGROUND);
    //this->_listRect.push_back(AREA_PLAY);
    //this->_listRect.push_back(MENU);
    //this->_listRect.push_back(CANNON);
}

ShootDinosaurEggsGame::~ShootDinosaurEggsGame() {
    //cout << "Goi ham huy Game!" << endl;
}

bool ShootDinosaurEggsGame::initData(SDL_Renderer*& renderer, SDL_Window* windows) {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        windows = SDL_CreateWindow("SDL 2.0 Shoot Dinosaur Eggs",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (windows != NULL)
        {
            renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
            //cout << renderer << endl;
            if (renderer == NULL) {
                cout << "Error InitBackGround: " << SDL_GetError() << endl;
            }
        }
    }

    return success;
}

void ShootDinosaurEggsGame::initBackground(SDL_Renderer* renderer) {
    this->_eggShoot.loadImgEggWithType(renderer, { Object::EGG_SHOOT_POS_X, Object::EGG_SHOOT_POS_Y, 52, 52 }, 3);
}


void ShootDinosaurEggsGame::showBackground(SDL_Renderer* renderer) {
    this->_eggShoot.showImage(renderer);
}

//SDL_Texture* ShootDinosaurEggsGame::LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
//    this->_surfaceGame = IMG_Load(file_path.c_str());
//
//    if (this->_surfaceGame == NULL) {
//        cout << "IMG_Load: " << IMG_GetError() << endl;
//    }
//    else {
//        this->_textureGame = SDL_CreateTextureFromSurface(this->_rendererGame, this->_surfaceGame);
//
//        if (this->_textureGame == NULL) {
//            cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
//        }
//        else {
//            SDL_FreeSurface(this->_surfaceGame);
//        }
//    }
//
//    return _textureGame;
//}

void ShootDinosaurEggsGame::showImageWithTexture_Rect(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void ShootDinosaurEggsGame::playGame(SDL_Renderer* renderer, SDL_Event &mainEvent) {
    int mouse_x = 0;
    int mouse_y = 0;
    bool stop = false;

    vector<Object>	_listObjects;
    _listObjects.push_back(Object::Object(renderer, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, bk0));
    _listObjects.push_back(Object::Object(renderer, { Object::AREA_PLAY_BORDER_LEFT, Object::AREA_PLAY_BORDER_TOP, Object::AREA_PLAY_WIDTH, Object::AREA_PLAY_HEIGHT }, bk1));
    _listObjects.push_back(Object::Object(renderer, { Object::AREA_MENU_BORDER_LEFT, Object::AREA_MENU_BORDER_TOP, Object::AREA_MENU_WIDTH, Object::AREA_MENU_HEIGHT }, bk2));
    _listObjects.push_back(Object::Object(renderer, { Object::CANNON_POS_X, Object::CANNON_POS_Y, Object::CANNON_WIDTH, Object::CANNON_HEIGHT }, cannon));
    
    //_arrow.loadImage(renderer, { Object::ARROW_POS_X ,Object::ARROW_POS_Y, Object::ARROW_WIDTH, Object::ARROW_HEIGHT}, "Images//equipment//arrow.png");
    _eggShoot.setArrow(renderer, { Object::ARROW_POS_X ,Object::ARROW_POS_Y, Object::ARROW_WIDTH, Object::ARROW_HEIGHT }, "Images//equipment//arrow.png");

    vector<Egg> _egg;
    _egg.push_back(Egg::Egg(renderer, { 578, 42, 52, 52 }, 0));
    _egg.push_back(Egg::Egg(renderer, { 630, 42, 52, 52 }, 1));
    //_egg.push_back(Egg::Egg(renderer, { 684, 42, 55, 55 }, 2));
   // _egg.push_back(Egg::Egg(renderer, { 741, 42, 55, 55 }, 3));
   // _egg.push_back(Egg::Egg(renderer, { 798, 42, 55, 55 }, 4));

    while (SDL_PollEvent(&mainEvent) || stop == false) {
        switch (mainEvent.type) {
        case SDL_MOUSEBUTTONDOWN: {
            
            if (mainEvent.button.button == SDL_BUTTON_LEFT) {
                this->_eggShoot.setIsFlying(true);
                cout << "angle = " << this->_eggShoot.getAngle() << endl;
                //Khi bấm chuột trái thì mũi tên phải biến mất
                //this->_eggShoot.loadImgEggWithType(renderer, { 838, 788, 52, 52 }, this->_eggShoot.randomTypeOfEgg());
                //this->_eggShoot.moveEgg(mainEvent, -1);
                cout << "Click" << endl;
            }



            break;
        }
        case SDL_QUIT: {
            stop = true;

            for (int i = 0; i < _listObjects.size(); i++) {
                _listObjects[i].free();
            }

            break;
        }
        default:
            break;
        }

        SDL_RenderClear(renderer);

        for (int i = 0; i < _listObjects.size(); i++) {
            _listObjects[i].showImage(renderer);
        }

        for (int i = 0; i < _egg.size(); i++) {
            _egg[i].showImage(renderer);
        }

        
        //_arrow.ha(renderer, mainEvent);
        _eggShoot.changeDirectionToShoot(renderer, mainEvent);

        if (this->_eggShoot.getIsFlying()) {
            this->_eggShoot.handleCollisionAll();
        }

        this->showBackground(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000 / DEFAULT_FPS);
    }

}
