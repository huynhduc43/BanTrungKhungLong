#include "Object.h"
Object::Object() {
	//g_renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
	//this->_renderer = g_renderer;
	this->_renderer = NULL;
	this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	cout << "Goi ham tao Object k co doi so!" << endl;
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

	cout << "Goi ham tao Object co doi so!" << endl;
}

Object::~Object() {
	if (this->_renderer != NULL) SDL_DestroyRenderer(this->_renderer);
	this->_renderer = NULL;

	if (this->_surface != NULL) SDL_FreeSurface(this->_surface);
	this->_surface = NULL;

	if (this->_texture != NULL) SDL_DestroyTexture(this->_texture);
	this->_texture = NULL;

	cout << "Goi ham huy Object!" << endl;
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
