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
	//SDL_Surface* _surface;
	SDL_Texture* _texture;
	SDL_Rect _rect;
	SDL_Point _center;
public:
	//Khu vực chơi
	static const int AREA_PLAY_WIDTH = 572;
	static const int AREA_PLAY_HEIGHT = 876;
	static const int AREA_PLAY_BORDER_LEFT = 578;
	static const int AREA_PLAY_BORDER_RIGHT = 1150;
	static const int AREA_PLAY_BORDER_TOP = 42;
	static const int AREA_PLAY_BORDER_BOTTOM = 42;

	//Khu vực menu game
	static const int AREA_MENU_WIDTH = 448;
	static const int AREA_MENU_HEIGHT = 876;
	static const int AREA_MENU_BORDER_LEFT = 130;
	static const int AREA_MENU_BORDER_RIGHT = 578;//Chưa trừ viền
	static const int AREA_MENU_BORDER_TOP = 42;
	static const int AREA_MENU_BORDER_BOTTOM = 42;


	//Mũi tên chỉ hướng
	static const int ARROW_WIDTH = 60;
	static const int ARROW_HEIGHT = 140;
	static const int ARROW_POS_X = 834;
	static const int ARROW_POS_Y = 744;

	//Tâm quay của mũi tên
	const SDL_Point ARROW_CENTER = { 864,814 };

	//Đại bác
	static const int CANNON_WIDTH = 140;
	static const int CANNON_HEIGHT = 124;
	static const int CANNON_POS_X = 794;
	static const int CANNON_POS_Y = 803;

	//Vị trí của quả trứng bắn
	static const int EGG_SHOOT_POS_X = 838;
	static const int EGG_SHOOT_POS_Y = 788;

	//Tâm quả trứng bắn
	const SDL_Point EGGSHOOT_CENTER = { 864, 814 };

	//Góc giới hạn
	static const int ANGLE_MAX = 80;
public:
	Object();
	Object(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	~Object();
public:
	SDL_Point getCenter() { return this->_center; }

	SDL_Texture* getTexture() { return this->_texture; }
	SDL_Rect getRect() { return this->_rect; }
public:
	void loadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	void showImage(SDL_Renderer* renderer);
	void showImageWithRect(SDL_Renderer* renderer, SDL_Rect rect);
	void showImageWithMouse(SDL_Renderer* renderer, SDL_Event &event);
	void free();
};
#endif // !OBJECT_H_


