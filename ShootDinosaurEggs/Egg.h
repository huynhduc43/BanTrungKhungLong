#pragma once
#ifndef EGG_H_
#define EGG_H_

#include "SupportFunctions.h"
#include "Object.h"
//using namespace SDL_SupportFunc;

class Egg: public Object
{
private:
	/*SDL_Renderer* _renderer;
	SDL_Surface* _surface;
	SDL_Texture* _texture;
	SDL_Rect _rect;*/
public:
	Egg();
	~Egg();
public:
	void loadImgEggWithType(SDL_Renderer* renderer, SDL_Rect rect, string type);
	//void showImage();
};
#endif // !EGG_H_



