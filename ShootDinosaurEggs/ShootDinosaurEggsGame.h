#pragma once
#ifndef SHOOTDINOSAUREGGSGAME_H_
#define SHOOTDINOSAUREGGSGAME_H_
#include "Object.h"
#include "Egg.h"
#include "SupportFunctions.h"
#include "EggUsedToShoot.h"
#include "MapEggs.h"
#include <vector>
using namespace SDL_SupportFunc;

class ShootDinosaurEggsGame
{
private:
	bool isPlaying;
	//vector<SDL_Texture*> _listTexture;
	//vector<SDL_Rect> _listRect;

	MapEggs _mapEggs;

	EggUsedToShoot _eggShoot;
	Object _arrow;
	
	Object temp;

	//SDL_Window* _windowsGame;
	//SDL_Surface* _screenSurfaceGame;
	//SDL_Surface* _backgroundGame;
	//SDL_Texture* _textureGame;
	//SDL_Surface* _surfaceGame;
	//SDL_Renderer* _rendererGame;
	//SDL_Rect _rectGame;

public:
	const SDL_Rect BACKGROUND = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	const SDL_Rect MENU = { Object::AREA_MENU_BORDER_LEFT, Object::AREA_MENU_BORDER_TOP, Object::AREA_MENU_WIDTH, Object::AREA_MENU_HEIGHT };
	const SDL_Rect AREA_PLAY = { Object::AREA_PLAY_BORDER_LEFT, Object::AREA_PLAY_BORDER_TOP, Object::AREA_PLAY_WIDTH, Object::AREA_PLAY_HEIGHT };
	const SDL_Rect CANNON = { Object::CANNON_POS_X, Object::CANNON_POS_Y, Object::CANNON_WIDTH, Object::CANNON_HEIGHT };

public:
	ShootDinosaurEggsGame();
	~ShootDinosaurEggsGame();
public:
	void initBackground(SDL_Renderer* renderer);
	bool initData(SDL_Renderer*& renderer, SDL_Window* window);
	void showBackground(SDL_Renderer* renderer);

	//SDL_Texture* LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	void showImageWithTexture_Rect(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);
	
	int handleCollisionAll(SDL_Renderer* renderer);

	void handleCollisionEggWithMapEggs(SDL_Renderer* renderer, int typeCollision);

	void playGame(SDL_Renderer* renderer, SDL_Event& mainEvent);
};
#endif // !SHOOTDINOSAUREGGSGAME_H_



