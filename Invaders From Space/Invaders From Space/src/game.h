#pragma once
#include "macros.h"
#include "mainMenu.h"
#include "hiscores.h"
#include "gameloop.h"

class Game {
public: 

	// TODO: Have an asset class with all sprites loaded in. Use static
	Game();

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;

	// TODO: Figure out how to correctly make a static enum.
	enum menus {
		mainmenu,
		gameplay,
		hiscores,
		options
	};
	menus menuOptions;

	bool init();	
	void start();

	void input();
	void update();
	void draw();

	void quit();

	//Test
	//TTF_Font* font;
	//Mix_Chunk* sfx;
	//Mix_Music* music;
	//SDL_Texture* texture;
	//SDL_Rect textureRect;

private:
	SDL_Window* window = nullptr;
	const int WIDTH = 576;
	const int HEIGHT = 1024;
};
