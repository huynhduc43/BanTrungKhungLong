#pragma once
#ifndef MAP_EGGS_H_
#define MAP_EGGS_H_
#include "SupportFunctions.h"
#include "Egg.h"
#include "EggUsedToShoot.h"
#include <fstream>
#include <vector>
using namespace SDL_SupportFunc;

class MapEggs
{
public:
	static const int NUMBER_ROW = 14;
	static const int NUMBER_COLUMN = 11;
private:
	vector<Egg>	_mapEggs[NUMBER_ROW];
	int _mapData[NUMBER_ROW][NUMBER_COLUMN];
	SDL_Point _startRow11Eggs;
	SDL_Point _startRow10Eggs;
public:
	MapEggs();
	~MapEggs();
	void setExistEggOfMap(int row, int column, int value) { this->_mapEggs[row][column].setExistEgg(value); }
	SDL_Point getCenter(int x, int y) {
		return this->_mapEggs[x][y].getCenter();
	}
public:
	void readFileMapEggs(string file_path);
	void createMapEggs(SDL_Renderer* renderer);
	void showMapEggs(SDL_Renderer* renderer);
	vector<Egg> getRowEggs(int row) { return _mapEggs[row]; }
	void loadNewEgg(SDL_Point eggShoot, int row, SDL_Renderer* renderer, int type);
	bool checkType(int row, int column, int type);
	//void handleCollision(EggUsedToShoot eggShoot, SDL_Renderer* renderer);
};


#endif // !MAP_EGGS_H_


