#pragma once
#ifndef SHOOTDINOSAUREGGSGAME_H_
#define SHOOTDINOSAUREGGSGAME_H_
#include "Object.h"
#include "Egg.h"
#include "SupportFunctions.h"
#include "EggUsedToShoot.h"
using namespace SDL_SupportFunc;

class ShootDinosaurEggsGame : public Object
{
private:
	bool isPlaying;
	EggUsedToShoot _eggShoot;
public:
	SDL_Window* _windows;
	SDL_Surface* _screenSurface;
	SDL_Surface* _background;
	SDL_Texture* _texture;
	SDL_Surface* _surface;
	SDL_Renderer* _renderer;

	//Texture background
	SDL_Texture* _texture0;
	SDL_Texture* _texture1;
	SDL_Texture* _texture2;
	SDL_Texture* _texture3;

public:
	ShootDinosaurEggsGame();
	~ShootDinosaurEggsGame();
public:
	void initBackground();
	bool initData();
	void showBackground();

	SDL_Texture* LoadImage(SDL_Renderer* renderer, SDL_Rect rect, string file_path);
	void showImageWithRect(SDL_Texture* texture, SDL_Rect rect);

	void showImgTest();

	void playGame(SDL_Event& mainEvent);
};
#endif // !SHOOTDINOSAUREGGSGAME_H_



