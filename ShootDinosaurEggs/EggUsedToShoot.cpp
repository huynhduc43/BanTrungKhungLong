#include "EggUsedToShoot.h"

EggUsedToShoot::EggUsedToShoot() {
	this->_egg.setRect({ 0,0,45,59 });
	this->_pos_x = 0;
	this->_pos_y = 0;
	this->_speed = 0;
	this->_angle = 0;
	this->_radius = 0;
	this->_texture = NULL;
	this->_renderer = NULL;
	this->_surface = NULL;
}

EggUsedToShoot::~EggUsedToShoot() {

}

void EggUsedToShoot::showImgEggWithRect(SDL_Rect &rect) {
	this->_egg.setRect(rect);
	SDL_RenderCopy(this->_renderer, this->_texture, NULL, &this->_egg.getRect());
}

void EggUsedToShoot::changeDirectionToShoot(SDL_Event& occurEvents) {

	while (true)
		if (occurEvents.type == SDL_MOUSEBUTTONDOWN) {

			if (occurEvents.button.button == SDL_BUTTON_LEFT) {

			}

		}

}
