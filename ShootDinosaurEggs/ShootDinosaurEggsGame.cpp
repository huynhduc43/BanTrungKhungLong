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

int ShootDinosaurEggsGame::handleCollisionAll(SDL_Renderer* renderer) {
    int result = 0;

    if (this->_eggShoot.getIsFlying()) {
        //Nếu trứng bắn chạm tường trái hoặc phải
        if (this->_eggShoot.getCenter().x - Egg::EGG_WIDTH / 2 <= Object::AREA_PLAY_BORDER_LEFT) {
            //Đổi hướng trứng bắn
            cout << "Bien trai" << endl;
            /*
                _typeCollision = -1: Trứng đang bay
                _typeCollision = 0: Trứng đang ở nòng
                _typeCollision = 1: Trứng chạm biên trái
                _typeCollision = 2: Trứng chạm biên phải
                _typeCollision = 3: Trứng chạm biên trên
            */
            //this->_typeCollision = 1;
            this->_eggShoot.moveEgg(renderer, 1);
            result = 1;
        }

        //Nếu trứng bắn chạm tường phải
        else if (this->_eggShoot.getCenter().x + Egg::EGG_WIDTH / 2 >= Object::AREA_PLAY_BORDER_RIGHT) {
            //Đổi hướng trứng bắn
            //this->_typeCollision = 2;
            this->_eggShoot.moveEgg(renderer, 2);
            cout << "Bien phai" << endl;
            result = 2;
        }

        //Nếu trứng bắn chạm trứng mục tiêu
        else if (this->_eggShoot.getCenter().y - Egg::EGG_HEIGHT / 2 <= Object::AREA_PLAY_BORDER_TOP) {
            this->_eggShoot.setIsFlying(false);
            cout << "Bien tren" << endl;
            this->_eggShoot.moveEgg(renderer, 3);
            
            result = 3;
        }

        //Nếu trứng bắn không chạm bất kì đối tượng nào
        else {
            //Tiếp tục bay như bình thường.
            //_typeCollision = -1;
            this->_eggShoot.moveEgg(renderer, -1);
            //cout << "Dang bay" << endl;
            result = -1;
        }
    }

    return result;
}

void ShootDinosaurEggsGame::handleCollisionEggWithMapEggs(SDL_Renderer* renderer, int typeCollision) {
    vector<Egg> rowEggs;
    //bool stop = false;
    int left = 0;
    int right = 0;
    int row = 0;

    //Nếu chạm biên trên
    if (typeCollision == 3) {
        
    }
    else {
        for (int i = 0; i < MapEggs::NUMBER_ROW; i++) {
            rowEggs = _mapEggs.getRowEggs(i);

            for (int j = 0; j < MapEggs::NUMBER_COLUMN; j++) {
                if (rowEggs[j].getExistEgg() == 1) {

                    //Nếu trứng bắn chạm vào trứng đích
                    if (calcDistance2Point(this->_eggShoot.getCenter(), rowEggs[j].getCenter()) <= 52) {
                        //cout << "(" << i << ", " << j << ")" << endl;

                        //Nếu trứng bắn cùng màu với trứng đích
                        if (rowEggs[j].getTypeEgg() == this->_eggShoot.getTypeEgg()) {
                            cout << "Cung mau" << endl;
                            this->_eggShoot.setIsFlying(false);

                            if (this->_mapEggs.checkType(i, j, this->_eggShoot.getTypeEgg())) {
                                this->_mapEggs.loadNewEgg(this->_eggShoot.getCenter(), i, renderer, this->_eggShoot.getTypeEgg());
                            }



                        }
                        else {
                            //Nếu chạm trứng khác màu, sau đó trứng bắn dược đưa về vị trí có chạm với trứng cùng màu thì phải
                            //xử lí vỡ trứng cùng màu.
                            cout << "Khac mau" << endl;
                            this->_eggShoot.setIsFlying(false);
                            this->_mapEggs.loadNewEgg(this->_eggShoot.getCenter(), i, renderer, this->_eggShoot.getTypeEgg());
                        }

                        //Reset _eggShoot
                        this->_eggShoot.loadImgEggWithType(renderer, { Object::EGG_SHOOT_POS_X, Object::EGG_SHOOT_POS_Y, 52, 52 },
                            this->_eggShoot.randomTypeOfEgg());

                        break;
                        //stop = true;
                    }

                }

            }

        }
    }
}

void ShootDinosaurEggsGame::playGame(SDL_Renderer* renderer, SDL_Event &mainEvent) {
    int mouse_x = 0;
    int mouse_y = 0;
    int typeCollision = 0;
    bool stop = false;

    vector<Object>	_listObjects;
    _listObjects.push_back(Object::Object(renderer, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, bk0));
    _listObjects.push_back(Object::Object(renderer, { Object::AREA_PLAY_BORDER_LEFT, Object::AREA_PLAY_BORDER_TOP, Object::AREA_PLAY_WIDTH, Object::AREA_PLAY_HEIGHT }, bk1));
    _listObjects.push_back(Object::Object(renderer, { Object::AREA_MENU_BORDER_LEFT, Object::AREA_MENU_BORDER_TOP, Object::AREA_MENU_WIDTH, Object::AREA_MENU_HEIGHT }, bk2));
    _listObjects.push_back(Object::Object(renderer, { Object::CANNON_POS_X, Object::CANNON_POS_Y, Object::CANNON_WIDTH, Object::CANNON_HEIGHT }, cannon));
    
    _eggShoot.setArrow(renderer, { Object::ARROW_POS_X ,Object::ARROW_POS_Y, Object::ARROW_WIDTH, Object::ARROW_HEIGHT }, "Images//equipment//arrow.png");

    _mapEggs.readFileMapEggs("MapEggs/map0.txt");
    _mapEggs.createMapEggs(renderer);

    while (SDL_PollEvent(&mainEvent) || stop == false) {
        switch (mainEvent.type) {
        case SDL_MOUSEBUTTONDOWN: {
            
            if (mainEvent.button.button == SDL_BUTTON_LEFT) {
                this->_eggShoot.setIsFlying(true);
                //cout << "angle = " << this->_eggShoot.getAngle() << endl;
                //Khi bấm chuột trái thì mũi tên phải biến mất
                //this->_eggShoot.loadImgEggWithType(renderer, { 838, 788, 52, 52 }, this->_eggShoot.randomTypeOfEgg());
                //this->_eggShoot.moveEgg(mainEvent, -1);
                //cout << "Click" << endl;
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

        _eggShoot.changeDirectionToShoot(renderer, mainEvent);

        if (this->_eggShoot.getIsFlying()) {
            typeCollision = handleCollisionAll(renderer);
            handleCollisionEggWithMapEggs(renderer, typeCollision);
        }

        _mapEggs.showMapEggs(renderer);

        this->showBackground(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(2000 / DEFAULT_FPS);
    }

}


