#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* player2;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;

Game::Game(){
}

Game::~Game() {

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!..." << std::endl;

		int flags = 0;
		if (fullscreen)
			flags = SDL_WINDOW_FULLSCREEN;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		
		count = 0;

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/mario.png",  0, 0, 2);
	player2 = new GameObject("assets/mario.png", 600,0, 4);
	map = new Map();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	count++;

	player->Update();
	player2->Update();

	std::cout << count << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	
	map->DrawMap();
	player->Render();
	player2->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
