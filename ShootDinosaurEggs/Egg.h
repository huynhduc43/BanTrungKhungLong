#pragma once
#ifndef EGG_H_
#define EGG_H_

#include "SupportFunctions.h"
#include "Object.h"
#include <time.h>
using namespace SDL_SupportFunc;

class Egg: public Object
{
private:
	int _radius;
	bool _exist;
	int _type;
public:
	static const int EGG_WIDTH = 46;
	static const int EGG_HEIGHT = 46;
public:
	Egg();
	Egg(SDL_Renderer* render);
	~Egg();
public:
	SDL_Renderer* getRender() { return this->_renderer; }
	void setRender(SDL_Renderer* render) { this->_renderer = render; }

	SDL_Surface* getSurface() { return this->_surface; }

	SDL_Texture* getTexture() { return this->_texture; }

	void setRect(SDL_Rect rect) { this->_rect = rect; }
	SDL_Rect getRect() { return this->_rect; }

	bool getExistEgg() { return this->_exist; }
	void setExistEgg(bool value) { this->_exist = value; }

	void setTypeEgg(int value) { this->_type = value; }
	int getTypeEgg(int value) { return this->_type; }
public:
	//Phát sinh trứng ngẫu nhiên
	int randomTypeOfEgg();

	//Load ảnh trứng với type (màu sắc của trứng)
	void loadImgEggWithType(SDL_Renderer* renderer, SDL_Rect rect, int type);

	void showImage();

	
};
#endif // !EGG_H_



