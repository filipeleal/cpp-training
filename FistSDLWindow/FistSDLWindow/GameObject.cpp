#include "GameObject.h"
#include "TextureManager.h"



GameObject::GameObject(const char* textureSheet, int x, int y, int speed) {
	objTexture = TextureManager::LoadTexture(textureSheet);

	ydir = 1;
	xdir = 1;
	GameObject::speed = speed;

	xpos = x;
	ypos = y;
}

void GameObject::Update() {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 32;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

	int wh, ww;
	SDL_GetWindowSize(Game::window, &ww, &wh);

	if (xpos > ww - destRect.w || xpos < 0 - srcRect.w)
		xdir *= -1;

	if (ypos > wh - srcRect.h || ypos < 0)
		ydir *= -1;

	xpos += 1 * xdir * speed;
	ypos += 1 * ydir * speed;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}