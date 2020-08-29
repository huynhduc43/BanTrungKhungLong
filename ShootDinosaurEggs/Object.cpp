#include "Object.h"
Object::Object() {
	this->_renderer = NULL;
	this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}
Object::Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
	this->_texture = NULL;
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
}

Object::~Object() {
	if (this->_renderer != NULL) SDL_DestroyRenderer(this->_renderer);
	this->_renderer = NULL;

	if (this->_surface != NULL) SDL_FreeSurface(this->_surface);
	this->_surface = NULL;

	if (this->_texture != NULL) SDL_DestroyTexture(this->_texture);
	this->_texture = NULL;
}

void Object::loadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
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
}

void Object::showImage() {
	SDL_RenderCopy(this->_renderer, this->_texture, NULL, &this->_rect);
}
