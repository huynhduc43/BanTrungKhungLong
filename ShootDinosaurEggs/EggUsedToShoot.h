#pragma once
#ifndef EGG_USED_TO_SHOOT_H_
#define EGG_USED_TO_SHOOT_H_
#include "Egg.h"
class EggUsedToShoot
{
private:
	//SDL_Renderer* _renderer;
	//SDL_Surface* _surface;
	//SDL_Texture* _texture;
	//SDL_Rect _rect;

	Egg _egg;
	Object _arrow;

	//Góc nghiêng của trứng so với trục thẳng đứng.
	int _angle;

	//Tốc độ bay của quả trứng khi được bắn (khoảng cách di chuyển sau khoảng thời gian t)
	int _speed;

	//Trạng thái quả trứng khi bắn
	bool isFlying;

	int _pos_x;
	int _pos_y;
public:
	EggUsedToShoot();
	~EggUsedToShoot();
public:
	Egg getEgg() { return this->_egg; }

	void setEgg(SDL_Renderer* render, SDL_Rect rect, int type);
public:
	void showImg();

	//Hiển thị ảnh với vị trí rect
	void showImgEggWithRect(SDL_Rect rect);

	//Thay đổi hướng bắn
	void changeDirectionToShoot(SDL_Event& occurEvents);

	//Xử lý va chạm giữa trứng đạn với trứng mục tiêu
	void handleCollisionEggWithEggs();

	//Xử lý va chạm giữa trứng đạn với tường
	void handleCollisionEggWithWall();
};

#endif // !EGG_USED_TO_SHOOT_H_

