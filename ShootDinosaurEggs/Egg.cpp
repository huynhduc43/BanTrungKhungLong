#include "Egg.h"

Egg::Egg() {
	this->_radius = EGG_WIDTH;
	this->_exist = 1;
	//this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0,0,45,59 };
	//cout << "Goi ham tao Egg!" << endl;
}

Egg::Egg(SDL_Renderer*& renderer, SDL_Rect rect, int type) {
	//cout << "Call Egg = " << renderer << endl;
	this->_exist = 1;
	this->_radius = EGG_WIDTH;

	if (type <= 0) type = 1;

	this->_type = type;
	this->_rect = rect;
	findCenter(this->_center, this->_rect);
	string file_path = "Images//eggs//egg" + to_string(type) + ".png";
	SDL_Surface* _surface = IMG_Load(file_path.c_str());

	if (_surface == NULL) {
		cout << "Egg: IMG_Load: " << IMG_GetError() << endl;
	}
	else {
		this->_texture = SDL_CreateTextureFromSurface(renderer, _surface);
		//cout << "Call Egg = " << renderer << endl;
		if (this->_texture == NULL) {
			cout << "Egg::SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
		}
		else {
			SDL_FreeSurface(_surface);
		}

	}

}

Egg::~Egg() {
	//cout << "Goi ham huy Egg!" << endl;
}

void Egg::loadImgEggWithType(SDL_Renderer* renderer, SDL_Rect rect, int type) {
	this->_type = type;
	this->_rect = rect;
	this->_exist = 1;
	findCenter(this->_center, this->_rect);

	string file_path = "Images//eggs//egg" + to_string(type) + ".png";

	SDL_Surface*  _surface = IMG_Load(file_path.c_str());

	if (_surface == NULL) {
		cout << "Egg: IMG_Load: " << IMG_GetError() << endl;
	}
	else {
		this->_texture = SDL_CreateTextureFromSurface(renderer, _surface);

		if (this->_texture == NULL) {
			cout << "Egg::SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
		}
		else {
			SDL_FreeSurface(_surface);
		}

	}

}

int Egg::randomTypeOfEgg() {
	srand((int)time(0));
	return rand() % (6 + 1 - 1) + 1;
}

void Egg::showImage(SDL_Renderer* renderer) {
	if (this->_exist == 1) {
		SDL_RenderCopy(renderer, this->_texture, NULL, &this->_rect);
	}
}