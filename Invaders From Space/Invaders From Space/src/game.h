#pragma once
#include "macros.h"

class Game {
public: 
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;

	bool init();	
	void gameplay();
	void input();
	void update();
	void draw();
	void quit();

private:
	SDL_Window* window = nullptr;
	const int WIDTH = 576;
	const int HEIGHT = 1024;
};
