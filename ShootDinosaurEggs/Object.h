#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include "SupportFunctions.h"
#include <math.h>
#define PI 3.14159265
using namespace SDL_SupportFunc;

class Object
{
protected:
	SDL_Renderer* _renderer;
	SDL_Surface* _surface;
	SDL_Texture* _texture;
	SDL_Rect _rect;

	SDL_Point _center;
public:
	//Khu vực chơi
	static const int AREA_PLAY_WIDTH = 578;
	static const int AREA_PLAY_HEIGHT = 876;
	static const int AREA_PLAY_BORDER_LEFT = 572;
	static const int AREA_PLAY_BORDER_RIGHT = 0;
	static const int AREA_PLAY_BORDER_TOP = 42;
	static const int AREA_PLAY_BORDER_BOTTOM = 42;

	//Khu vực menu game
	static const int AREA_MENU_WIDTH = 442;
	static const int AREA_MENU_HEIGHT = 876;
	static const int AREA_MENU_BORDER_LEFT = 130;
	static const int AREA_MENU_BORDER_RIGHT = 572;
	static const int AREA_MENU_BORDER_TOP = 42;
	static const int AREA_MENU_BORDER_BOTTOM = 42;

	//Mũi tên chỉ hướng
	static const int ARROW_WIDTH = 60;
	static const int ARROW_HEIGHT = 140;
	static const int ARROW_POS_X = 831;
	static const int ARROW_POS_Y = 650;

	//Đại bác
	static const int CANNON_WIDTH = 140;
	static const int CANNON_HEIGHT = 124;
	static const int CANNON_POS_X = 791;
	static const int CANNON_POS_Y = 800;
public:
	Object();
	Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	~Object();
public:
	SDL_Point getCenter() { return this->_center; }
public:
	void loadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	void showImage();
	void showImageWithRect(SDL_Rect rect);
	void showImageWithMouse(SDL_Event &event);
};
#endif // !OBJECT_H_


