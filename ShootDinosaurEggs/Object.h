#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include "SupportFunctions.h"
#include <math.h>
#define PI 3.14159265
//using namespace SDL_SupportFunc;

class Object
{
protected:
	SDL_Renderer* _renderer;
	SDL_Surface* _surface;
	SDL_Texture* _texture;
	SDL_Rect _rect;

public:
	Object();
	Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	~Object();
public:
	void loadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	void showImage();
	void showImageWithRect(SDL_Rect rect);
	void showImageWithMouse(SDL_Event &event);
};

#endif // !OBJECT_H_


