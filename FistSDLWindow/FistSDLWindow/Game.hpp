#ifndef Game_hpp
#define Game_hpp


#include "SDL.h"
#include "SDL_Image.h"
#include <stdio.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };

	static SDL_Renderer* renderer;
	static SDL_Window* window;
private:
	int count;
	bool isRunning;

};

#endif // !Game_hpp
