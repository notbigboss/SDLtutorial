#pragma once
#include "SDL.h"
class Game{
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };
private:

	bool isRunning;
	int cnt = 0;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

