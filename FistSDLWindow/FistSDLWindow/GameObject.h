#pragma once
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* textureSheet, int x, int y, int speed);
	~GameObject();

	void Update();
	void Render();

private:

	int xpos;
	int ypos;
	int ydir, xdir, speed;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};