#include "Egg.h"

Egg::Egg() {
	this->_radius = EGG_WIDTH;
	this->_exist = true;
	this->_renderer = NULL;
	this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0,0,45,59 };
	cout << "Goi ham tao Egg!" << endl;
}

Egg::Egg(SDL_Renderer* render) {
	this->_renderer = render;
}

Egg::~Egg() {
	cout << "Goi ham huy Egg!" << endl;
}

void Egg::loadImgEggWithType(SDL_Renderer* renderer, SDL_Rect rect, int type) {
	this->_renderer = renderer;
	this->_type = type;

	if (this->_renderer == NULL) {
		cout << "_renderer is NULL" << endl;
		cout << "SDL_CreateRenderer: " << SDL_GetError() << endl;
	}

	this->_rect = rect;
	findCenter(this->_center, this->_rect);

	string file_path = "Images//eggs//egg" + to_string(type) + ".png";
	//cout << file_path << endl;
	this->_surface = IMG_Load(file_path.c_str());

	if (this->_surface == NULL) {
		cout << "Egg: IMG_Load: " << IMG_GetError() << endl;
	}
	else {
		this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_surface);

		if (this->_texture == NULL) {
			cout << "Egg::SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
		}
		else {
			SDL_FreeSurface(this->_surface);
		}

	}
	
	this->_texture = this->_texture;
}

int Egg::randomTypeOfEgg() {
	srand((int)time(0));
	return rand() % (5 + 1 - 0);
}

void Egg::showImage() {
	if (this->_exist) {
		SDL_RenderCopy(this->_renderer, this->_texture, NULL, &this->_rect);
	}
}