#pragma once
#include "macros.h"
#include "soundManager.h"
#include "textureManager.h"
#include "fontManager.h"

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

	//Test
	TTF_Font* font;
	Mix_Chunk* sfx;
	Mix_Music* music;
	SDL_Texture* texture;
	SDL_Rect textureRect;

private:
	SDL_Window* window = nullptr;
	const int WIDTH = 576;
	const int HEIGHT = 1024;
};
