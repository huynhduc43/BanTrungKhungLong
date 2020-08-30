#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include "SupportFunctions.h"
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
};

#endif // !OBJECT_H_


