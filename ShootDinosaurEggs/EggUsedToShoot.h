#pragma once
#ifndef EGG_USED_TO_SHOOT_H_
#define EGG_USED_TO_SHOOT_H_
#include "Egg.h"
#include <vector>
#include <iostream>
using namespace std;
class EggUsedToShoot: public Egg
{
private:
	Object _arrow;

	//Góc nghiêng của trứng 
	// - So với trục thẳng đứng: Khi trứng ở nòng đại bác.
	// - So với trục nằm ngang: Khi trứng chạm tường trái hoặc phải.
	double _angle;

	//Tốc độ bay của quả trứng khi được bắn (khoảng cách di chuyển sau khoảng thời gian t)
	int _speed;

	//Trạng thái quả trứng khi bắn
		// - True: Nếu đã nhấp chuột trái
		// - False: Nếu chưa nhấp chuột trái
	bool _isFlying;

	double _pos_x;
	double _pos_y;

	double _mouse_x;
	double _mouse_y;

	int _typeCollision;
public:
	EggUsedToShoot();
	~EggUsedToShoot();
public:
	//Egg getEgg() { return this->_egg; }

	void setEgg(SDL_Renderer* render, SDL_Rect rect, int type);

	void setArrow(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	Object getArrow() { return _arrow; }

	bool getIsFlying() { return this->_isFlying; }
	void setIsFlying(bool value) { this->_isFlying = value; }

	double getAngle() { return this->_angle; }
public:
	//Hiển thị ảnh với vị trí rect
	//void showImgEggWithRect(SDL_Rect rect);

	//Thay đổi hướng bắn
	void changeDirectionToShoot(SDL_Renderer* renderer, SDL_Event& occurEvents);

	//Di chuyển quả trứng
	void moveEgg(int typeCollision);

	//Xử lý chung các va chạm trong game;
	void handleCollisionAll();

	//Xử lý va chạm giữa trứng đạn với trứng mục tiêu
	void handleCollisionEggWithEggs();

	//Xử lý va chạm giữa trứng đạn với tường
	void handleCollisionEggWithWall();

	bool isCollisionWithEggs(Egg eggShoot, vector<Egg> eggs);
};

#endif // !EGG_USED_TO_SHOOT_H_

