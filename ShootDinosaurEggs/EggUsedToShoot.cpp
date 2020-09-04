#include "EggUsedToShoot.h"

EggUsedToShoot::EggUsedToShoot() {
	cout << "Goi ham tao EggUsedToShoot!" << endl;
	this->_egg.setRect({ 0,0,46,46 });
	this->_pos_x = 0;
	this->_pos_y = 0;
	this->_speed = 0;
	this->_angle = 0;
	//this->_texture = NULL;
	//this->_renderer = NULL;
	//this->_surface = NULL;
}

EggUsedToShoot::~EggUsedToShoot() {
	cout << "Goi ham huy EggUsedToShoot!" << endl;
}

void EggUsedToShoot::showImgEggWithRect(SDL_Rect rect) {
	this->_egg.setRect(rect);
	SDL_RenderCopy(_egg.getRender(), _egg.getTexture(), NULL, &this->_egg.getRect());
}

void EggUsedToShoot::changeDirectionToShoot(SDL_Event& occurEvents) {

	while (true)
		if (occurEvents.type == SDL_MOUSEBUTTONDOWN) {

			if (occurEvents.button.button == SDL_BUTTON_LEFT) {

			}

		}

}

void EggUsedToShoot::handleCollisionEggWithWall() {
	//Nếu trứng bắn chạm tường bên trái
	if (this->_egg.getCenter().x - Egg::EGG_WIDTH == Object::AREA_PLAY_WIDTH) {

	}
	else if (this->_egg.getCenter().x + Egg::EGG_WIDTH == Object::AREA_PLAY_WIDTH) {

	}
}

void EggUsedToShoot::getEggCopyConstructor(Egg& egg) {
	egg.setRender(this->_egg.getRender());
}

void EggUsedToShoot::showImg() {
	//findCenter(this->_egg.c)
	SDL_RenderCopy(_egg.getRender(), _egg.getTexture(), NULL, &this->_egg.getRect());
}