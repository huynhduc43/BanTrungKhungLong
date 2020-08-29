#pragma once
#include "SupportFunctions.h"
using namespace SDL_SupportFunc;

class Object
{
private:
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

