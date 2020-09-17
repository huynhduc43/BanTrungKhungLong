#include "Object.h"
Object::Object() {
	//this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	this->_center = { 0,0 };
	//cout << "Goi ham tao Object k co doi so!" << endl;
}

Object::Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
	this->_rect = rect;
	findCenter(this->_center, rect);

	SDL_Surface* _surface = IMG_Load(file_path.c_str());
	
	if (_surface == NULL) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
	}
	else {
		this->_texture = SDL_CreateTextureFromSurface(renderer, _surface);
		//cout << this->_texture << endl;
		if (this->_texture == NULL) {
			cout << "Object Constructor::SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
		}
		else {
			SDL_FreeSurface(_surface);
			cout << "Da free surface" << endl;
		}
	}

	//cout << "Goi ham tao Object co doi so!" << endl;
	//cout << SDL_GetError() << endl;
}

Object::~Object() {
	//free();
	/*if (this->_texture != NULL) {
		cout << this->_texture << endl;
	}*/
	
}

void Object::loadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
	this->_rect = rect;
	findCenter(this->_center, this->_rect);
	SDL_Surface* _surface = IMG_Load(file_path.c_str());

	if (_surface == NULL) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
	}
	else {
		this->_texture = SDL_CreateTextureFromSurface(renderer, _surface);

		if (this->_texture == NULL) {
			cout << "Object loadImage::SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;
		}
		else {
			SDL_FreeSurface(_surface);
			_surface = NULL;
		}
	}
}

void Object::showImage(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, this->_texture, NULL, &this->_rect);
}

void Object::showImageWithRect(SDL_Renderer* renderer, SDL_Rect rect) {
	this->_rect.x = rect.x + rect.w / 2;
	this->_rect.y = rect.y + rect.h / 2;

	SDL_RenderCopy(renderer, this->_texture, NULL, &this->_rect);
}

void Object::showImageWithMouse(SDL_Renderer* renderer, SDL_Event& event) {
	double angle = 0;
	double mouse_x = event.motion.x;
	double mouse_y = event.motion.y;

	if (mouse_y > this->_center.y) {
		mouse_y = this->_center.y;
	}

	//cout << "this->_center.x = " << this->_center.x << endl;
	double x = abs(this->_center.x - mouse_x);
	double y = abs(this->_center.y - mouse_y);

	angle = atan(x / y);
	angle = (angle * 180) / PI;

	if (angle > 85) {
		angle = 85;
	}

	//cout << "( " << x << ", " << y << ")" << ", goc = " << angle << endl;
	if (mouse_x < this->_center.x) {
		angle = -angle;
	}

	if(mouse_x < 578 - 2 || mouse_x > 1150 + 2 || mouse_y < 42 - 2) angle = 0;

	SDL_RenderCopyEx(renderer, this->_texture, NULL, &this->_rect, angle, NULL, SDL_FLIP_NONE);
}

void Object::free() {
	cout << "Call free()" << endl;

	if (this->_texture != NULL) SDL_DestroyTexture(this->_texture);
	this->_texture = NULL;
	
}