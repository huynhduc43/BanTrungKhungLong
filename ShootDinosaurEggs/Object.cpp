#include "Object.h"
Object::Object() {
	//g_renderer = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
	//this->_renderer = g_renderer;
	//this->_renderer = NULL;
	this->_surface = NULL;
	this->_texture = NULL;
	this->_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	this->_center = { 0,0 };
	cout << "Goi ham tao Object k co doi so!" << endl;
}
Object::Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
	this->_texture = NULL;
	this->_renderer = renderer;
	this->_rect = rect;
	this->_surface = IMG_Load(file_path.c_str());
	
	this->_center.x = this->_rect.x + this->_rect.w/2;
	this->_center.y = this->_rect.y + this->_rect.h/2;

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
}

void Object::showImage() {
	//this->_rect.x = this->_center.x;
	//this->_rect.y = this->_center.y;
	cout << "	Error: " << SDL_GetError() << endl;
	SDL_RenderCopy(this->_renderer, this->_texture, NULL, &this->_rect);
}

void Object::showImageWithRect(SDL_Rect rect) {
	this->_rect.x = rect.x + rect.w / 2;
	this->_rect.y = rect.y + rect.h / 2;

	SDL_RenderCopy(this->_renderer, this->_texture, NULL, &this->_rect);
}

void Object::showImageWithMouse(SDL_Event& event) {

	double angle = 0;
	double mouse_x = event.motion.x;
	double mouse_y = event.motion.y;

	if (mouse_y > 725) {
		mouse_y = 775;
	}

	double x = abs(865 - mouse_x);
	double y = abs(850 - 80 - mouse_y);

	angle = atan(x / y);
	angle = (angle * 180) / PI;

	if (angle > 85) {
		angle = 85;
	}

	//cout << "( " << x << ", " << y << ")" << ", goc = " << angle << endl;
	if (mouse_x < 865) {
		angle = -angle;
	}

	//SDL_Point* center = new SDL_Point { 865 ,800 };

	SDL_RenderCopyEx(this->_renderer, this->_texture, NULL, &this->_rect, angle, NULL, SDL_FLIP_NONE);
	//delete center;
}