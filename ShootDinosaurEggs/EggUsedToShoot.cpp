#include "EggUsedToShoot.h"

EggUsedToShoot::EggUsedToShoot() {
	//cout << "Goi ham tao EggUsedToShoot!" << endl;
	this->_pos_x = 0;
	this->_pos_y = 0;
	this->_speed = 12;
	this->_angle = 0;
	this->_typeCollision = 0;
	this->_mouse_x = 0;
	this->_mouse_y = 0;
	this->_isFlying = false;
}

EggUsedToShoot::~EggUsedToShoot() {
	//cout << "Goi ham huy EggUsedToShoot!" << endl;
}

//void EggUsedToShoot::showImgEggWithRect(SDL_Rect rect) {
//	this->_egg.setRect(rect);
//	SDL_RenderCopy(_egg.getRender(), _egg.getTexture(), NULL, &this->_egg.getRect());
//}

void EggUsedToShoot::changeDirectionToShoot(SDL_Renderer* renderer, SDL_Event& occurEvents) {
	if (this->_isFlying == false) {

		this->_mouse_x = occurEvents.motion.x;
		this->_mouse_y = occurEvents.motion.y;

		if (_mouse_y > this->_arrow.getCenter().y) {
			_mouse_y = this->_arrow.getCenter().y;
		}

		double x = abs(this->_arrow.getCenter().x - _mouse_x);
		double y = abs(this->_arrow.getCenter().y - _mouse_y);

		if (y == 0) {

			if (_mouse_x < this->_arrow.getCenter().x) {
				_angle = - (Object::ANGLE_MAX * PI) / 180;
				//cout << "Left" << endl;
			}
			else {
				_angle = (Object::ANGLE_MAX * PI) / 180;
				//cout << "Right" << endl;
			}

		}
		else {
			_angle = atan(x / y);

			//Phạm vi góc bắn [-85, 85]
			if (_angle > (Object::ANGLE_MAX * PI) / 180) {
				_angle = (Object::ANGLE_MAX * PI) / 180;
			}

			if (_mouse_x < this->_arrow.getCenter().x) {
				_angle = - _angle;
			}

		}

		if (_mouse_x < Object::AREA_PLAY_BORDER_LEFT - 2 || _mouse_x > Object::AREA_PLAY_BORDER_RIGHT + 2
			|| _mouse_y < Object::AREA_PLAY_BORDER_TOP - 2) {
			_angle = 0;
		}

		//cout << "angle0 = " << _angle << endl;
		this->_pos_x = sin(_angle) * this->_speed;
		this->_pos_y = - abs(cos(_angle) * this->_speed);

		SDL_RenderCopyEx(renderer, this->_arrow.getTexture(), NULL, &this->_arrow.getRect(), (_angle * 180) / PI, NULL, SDL_FLIP_NONE);
	}
	
}

void EggUsedToShoot::handleCollisionEggWithWall() {
	//Nếu trứng bắn chạm tường bên trái
	if (this->_center.x - Egg::EGG_WIDTH <= Object::AREA_PLAY_BORDER_LEFT) {

	}
	//Nếu trứng bắn chạm tường bên phải
	else if (this->_center.x + Egg::EGG_WIDTH >= Object::AREA_PLAY_BORDER_RIGHT) {

	}
}

void EggUsedToShoot::setEgg(SDL_Renderer* render, SDL_Rect rect, int type) {
	this->_rect = rect;
	loadImgEggWithType(render, rect, type);
}

//void EggUsedToShoot::handleCollisionAll() {
//	if (this->_isFlying) {
//		//Nếu trứng bắn chạm tường trái hoặc phải
//		if (this->_center.x - Egg::EGG_WIDTH / 2 <= Object::AREA_PLAY_BORDER_LEFT) {
//			//Đổi hướng trứng bắn
//			cout << "Bien trai" << endl;
//			/*
//				_typeCollision = -1: Trứng đang bay
//				_typeCollision = 0: Trứng đang ở nòng
//				_typeCollision = 1: Trứng chạm biên trái
//				_typeCollision = 2: Trứng chạm biên phải
//				_typeCollision = 3: Trứng chạm biên trên
//			*/
//			this->_typeCollision = 1;
//			this->moveEgg(this->_typeCollision);
//		}
//
//		//Nếu trứng bắn chạm tường phải
//		else if (this->_center.x + Egg::EGG_WIDTH / 2 >= Object::AREA_PLAY_BORDER_RIGHT) {
//			//Đổi hướng trứng bắn
//			this->_typeCollision = 2;
//			this->moveEgg(this->_typeCollision);
//			cout << "Bien phai" << endl;
//		}
//
//		//Nếu trứng bắn chạm trứng mục tiêu
//		else if (this->_center.y - Egg::EGG_HEIGHT / 2 <= Object::AREA_PLAY_BORDER_TOP) {
//			this->_isFlying = false;
//			cout << "Bien tren" << endl;
//			//Nếu xung quanh có trứng (Trứng vừa chạm trứng)
//				//Xử lý vỡ trứng cùng màu || khác màu với trứng bắn
//				//Tạo trứng bắn mới.
//
//			//Nếu cạnh trên không có trứng 
//				//Nếu Tâm trứng bắn trùng vị trí trong bản đồ mục tiêu
//					//Hiển thị trứng mục tiêu giống trứng bắn tại vị trí này.
//					//Tạo trứng bắn mới.
//
//		}
//
//		//Nếu trứng bắn không chạm bất kì đối tượng nào
//		else {
//			//Tiếp tục bay như bình thường.
//			_typeCollision = -1;
//			this->moveEgg(this->_typeCollision);
//			//cout << "Dang bay" << endl;
//		}
//	}
//}

void EggUsedToShoot::moveEgg(SDL_Renderer* renderer, int typeCollision) {	
	switch (typeCollision) {
	case -1:
		
		break;
	case 0:
		cout << "Dang o nong cannon!" << endl;
		break;
	case 1:
		this->_pos_x = - this->_pos_x;
		break;
	case 2:
		this->_pos_x = - this->_pos_x;
		break;
	case 3:
		//Reset _eggShoot
		loadImgEggWithType(renderer, { Object::EGG_SHOOT_POS_X, Object::EGG_SHOOT_POS_Y, 52, 52 }, randomTypeOfEgg());

		break;
	default:
		break;

	}

	this->_rect.x = (int)this->_pos_x + this->_rect.x;
	this->_rect.y = (int)this->_pos_y + this->_rect.y;
	//cout << "(" << this->_rect.x << ", " << this->_rect.y << ")" << endl;
	findCenter(this->_center, this->_rect);
	//cout << "center: " << this->_center.x << ", " << this->_center.y << endl;
	//cout << "move: " << this->_rect.x << ", " << this->_rect.y << endl;

}

void EggUsedToShoot::setArrow(SDL_Renderer* renderer, SDL_Rect rect, string file_path) {
	this->_arrow.loadImage(renderer, rect, file_path);
}

//void EggUsedToShoot::handleCollisionEggWithEggs(MapEggs mapEggs) {
//
//}