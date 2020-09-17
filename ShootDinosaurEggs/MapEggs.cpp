#include "MapEggs.h"
MapEggs::MapEggs() {
	this->_startRow11Eggs = { Object::AREA_PLAY_BORDER_LEFT, Object::AREA_PLAY_BORDER_TOP };
	this->_startRow10Eggs = { Object::AREA_PLAY_BORDER_LEFT - Egg::EGG_WIDTH / 2, Object::AREA_PLAY_BORDER_TOP + 46};
}

MapEggs::~MapEggs() {
	for (int i = 0; i < NUMBER_ROW; i++) {
		this->_mapEggs[i].clear();
	}
}

void MapEggs::readFileMapEggs(string file_path) {
	ifstream file_open(file_path);

	if (file_open.fail()) {
		cout << "Khong the mo file" << endl;
		return;
	}

	for (int i = 0; i < NUMBER_ROW; i++) {
			
		for (int j = 0; j < NUMBER_COLUMN; j++) {
			file_open >> this->_mapData[i][j];
		}
		
	}

	file_open.close();
}

void MapEggs::createMapEggs(SDL_Renderer* renderer) {
	int pos_x_11 = 0;
	int pos_x_10 = 0;
	int pos_y = this->_startRow11Eggs.y;

	for (int i = 0; i < NUMBER_ROW; i++) {

		if (i % 2 == 0) {
			int pos_x_11 = this->_startRow11Eggs.x;

			for (int j = 0; j < NUMBER_COLUMN; j++) {
				this->_mapEggs[i].push_back(Egg::Egg(renderer, { pos_x_11, pos_y, Egg::EGG_WIDTH, Egg::EGG_WIDTH }, this->_mapData[i][j]));

				if (this->_mapData[i][j] <= 0) {
					this->_mapEggs[i][j].setExistEgg(0);
				}

				pos_x_11 += 52;
			}

		}
		else {
			pos_x_10 = this->_startRow10Eggs.x;

			for (int j = 0; j < NUMBER_COLUMN; j++) {
				this->_mapEggs[i].push_back(Egg::Egg(renderer, { pos_x_10, pos_y, Egg::EGG_WIDTH, Egg::EGG_WIDTH }, this->_mapData[i][j]));

				if (this->_mapData[i][j] <= 0) {
					this->_mapEggs[i][j].setExistEgg(0);
				}

				pos_x_10 += 52;
			}
		}
		
		pos_y += 46;
	}
}

void MapEggs::showMapEggs(SDL_Renderer* renderer) {
	for (int i = 0; i < NUMBER_ROW; i++) {

		for (int j = 0; j < NUMBER_COLUMN; j++) {
			this->_mapEggs[i][j].showImage(renderer);
		}

	}
}

//void MapEggs::handleCollision(EggUsedToShoot eggShoot, SDL_Renderer* renderer) {
//	SDL_Rect temp;
//
//	for (int i = 0; i < NUMBER_ROW; i++) {
//
//		for (int j = 0; j < NUMBER_COLUMN; j++) {
//			if (this->_mapEggs[i][j].getExistEgg() == 1) {
//
//				if ((eggShoot.getRect().x + eggShoot.getPosX()) >= this->_mapEggs[i][j].getRect().x
//					&& (eggShoot.getRect().y + eggShoot.getPosY()) >= this->_mapEggs[i][j].getRect().y) {
//					temp = this->_mapEggs[i][j].getRect();
//					this->_mapEggs[i][j].loadImgEggWithType(renderer, temp, this->_mapEggs[i][j].getTypeEgg());
//				}
//
//			}
//			
//		}
//
//	}
//}

void MapEggs::loadNewEgg(SDL_Point eggShoot, int row, SDL_Renderer* renderer, int type) {
	int j = 0;
	int left = 0;
	int right = 0;
	if ((row + 1)> NUMBER_COLUMN) {
		cout << "Game Over" << endl;
		return;
	}

	if (eggShoot.y >= _mapEggs[row + 1][5].getRect().y) {
		row++;
		cout << "Da cong" << endl;
	}
	else {
		//row;
		cout << "Khong cong" << endl;
	}

	if (row % 2 == 0) {
		j = 0;
	}
	else {
		j = 1;
	}

	for (j; j < NUMBER_COLUMN - 1; j++) {
		left = abs(eggShoot.x - _mapEggs[row][j].getCenter().x);
		right = abs(eggShoot.x - _mapEggs[row][j + 1].getCenter().x);

		if (left <= 51 && right <= 51) {
			if (left <= right) {
				this->_mapEggs[row][j].loadImgEggWithType(renderer, _mapEggs[row][j].getRect(), type);

			}
			else {
				this->_mapEggs[row][j + 1].loadImgEggWithType(renderer, _mapEggs[row][j + 1].getRect(), type);
			}
			break;
		}
	}

}

bool MapEggs::checkType(int row, int column, int type) {
	bool result = false;
	vector<SDL_Point> posEgg;
	vector<SDL_Point> setExistEgg;
	SDL_Point element;

	posEgg.push_back({ row, column });
	setExistEgg.push_back({ row, column });

	while (posEgg.size() != 0) {
		element = posEgg.back();
		posEgg.pop_back();
		cout << element.x << ", " << element.y << endl;
		this->_mapEggs[element.x][element.y].setExistEgg(0);

		//Trứng bên trái
		if (element.x - 1 >= 0 && this->_mapEggs[element.x - 1][element.y].getExistEgg() == 1 
			&& this->_mapEggs[element.x - 1][element.y].getTypeEgg() == type) {
			posEgg.push_back({ element.x - 1, element.y });
			setExistEgg.push_back({ element.x - 1, element.y });
		}

		//Trứng bên phải
		if (element.x + 1 < NUMBER_ROW  && this->_mapEggs[element.x + 1][element.y].getExistEgg() == 1 
			&& this->_mapEggs[element.x + 1][element.y].getTypeEgg() == type) {
			posEgg.push_back({ element.x + 1, element.y });
			setExistEgg.push_back({ element.x + 1, element.y });
		}

		//Trứng góc trên bên trái
		if (element.y - 1 >= 0 && this->_mapEggs[element.x][element.y - 1].getExistEgg() == 1 
			&& this->_mapEggs[element.x][element.y - 1].getTypeEgg() == type) {
			posEgg.push_back({ element.x, element.y - 1 });
			setExistEgg.push_back({ element.x, element.y - 1 });
		}

		//Trứng góc trên bên phải
		if ((element.x + 1 < NUMBER_ROW && element.y - 1 >= 0) && this->_mapEggs[element.x + 1][element.y - 1].getExistEgg() == 1
			&& this->_mapEggs[element.x + 1][element.y - 1].getTypeEgg() == type) {
			posEgg.push_back({ element.x + 1, element.y - 1 });
			setExistEgg.push_back({ element.x + 1, element.y - 1 });
		}       

		//Trứng góc dưới bên trái
		if (element.y + 1 < NUMBER_COLUMN && this->_mapEggs[element.x][element.y + 1].getExistEgg() == 1
			&& this->_mapEggs[element.x][element.y + 1].getTypeEgg() == type) {
			posEgg.push_back({ element.x, element.y + 1 });
			setExistEgg.push_back({ element.x, element.y + 1 });
		}

		//Trứng góc dưới bên phải
		if ((element.x + 1 < NUMBER_ROW && element.y + 1 < NUMBER_COLUMN) && this->_mapEggs[element.x + 1][element.y + 1].getExistEgg() == 1
			&& this->_mapEggs[element.x + 1][element.y + 1].getTypeEgg() == type) {
			posEgg.push_back({ element.x + 1, element.y + 1});
			setExistEgg.push_back({ element.x + 1, element.y + 1 });
		}
	}

	if (setExistEgg.size() < 2) {
		//cout << "xoa trung" << endl;
		while (setExistEgg.size() != 0) {
			element = setExistEgg.back();
			this->_mapEggs[element.x][element.y].setExistEgg(1);
			setExistEgg.pop_back();  
		}
		result = true;
	}

	//Xóa trứng k có điểm tựa
	for (int i = 1; i < NUMBER_ROW; i++) {
		cout << "Xoa trung k diem tua" << endl;
		if (i % 2 == 0) {

			for (int j = 0; j < NUMBER_COLUMN; j++) {

				if (this->_mapEggs[i][j].getExistEgg() == 1) {

					if (this->_mapEggs[i - 1][j].getExistEgg() == 0
						&& (j + 1 >= NUMBER_COLUMN || this->_mapEggs[i - 1][j + 1].getExistEgg() == 0)) {
						this->_mapEggs[i][j].setExistEgg(0);
					}

				}

			}

		}
		else {
			for (int j = 0; j < NUMBER_COLUMN; j++) {

				if (this->_mapEggs[i][j].getExistEgg() == 1) {
				
					if ((j - 1 < 0 || this->_mapEggs[i - 1][j - 1].getExistEgg() == 0)
						&& this->_mapEggs[i - 1][j].getExistEgg() == 0) {
						this->_mapEggs[i][j].setExistEgg(0);
					}

				}

			}
		}
		
	}

	//Nếu trứng chạm biên trên khi không còn trứng

	return result;
}