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
	int _exist;
	int _type;
public:
	static const int EGG_WIDTH = 52;
	static const int EGG_HEIGHT = 52;
public:
	Egg();
	Egg(SDL_Renderer*& renderer, SDL_Rect rect, int type);
	~Egg();
public:
	//SDL_Surface* getSurface() { return this->_surface; }
	//SDL_Texture* getTexture() { return this->_texture; }

	void setRect(SDL_Rect rect) { this->_rect = rect; }
	SDL_Rect getRect() { return this->_rect; }

	int getExistEgg() { return this->_exist; }
	void setExistEgg(int value) { this->_exist = value; }

	void setTypeEgg(int value) { this->_type = value; }
	int getTypeEgg() { return this->_type; }
public:
	//Phát sinh trứng ngẫu nhiên
	int randomTypeOfEgg();

	//Load ảnh trứng với type (màu sắc của trứng)
	void loadImgEggWithType(SDL_Renderer* renderer, SDL_Rect rect, int type);

	void showImage(SDL_Renderer* renderer);

	
};
#endif // !EGG_H_



