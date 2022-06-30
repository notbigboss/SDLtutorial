
#include "Game.h"
#include "Log.h"
#include <iostream>

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "[ALERT] Everything alright! Subsystems Initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "[ALERT] Window Created!" << std::endl;
		}
		else {
			std::cout << "[WARNING] Window has not worked properly" << std::endl;
		}


		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "[ALERT] Renderer Created!" << std::endl;
		}
		else
		{
			std::cout << "[WARNING] Renderer has not worked properly" << std::endl;
		}
		isRunning = true;

	}
	else {
		std::cout << "[WARNING] game::init has not worked properly!" << std::endl;
		isRunning = false;
	}
};

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		default:
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
	}

}

void Game::update() {
	cnt++;
	std::cout << "[ALERT] The counter is at " << cnt/60 << "!" << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	// render pipeline
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "[ALERT] Game cleaned!" << std::endl;
}

