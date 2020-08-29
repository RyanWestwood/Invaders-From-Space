#include "game.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::isRunning = false;

bool Game::init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		Print2("SDL could not be init! SDL Error: ", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) {
			Print("Warning: Linear texture filterint not enabled!");
		}
		window = SDL_CreateWindow("Invaders From Space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			Print2("Window could not be created! SDL Error: ", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				Print2("Renderer could not be created! SDL Error: ", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(renderer, 1, 16, 76, 255);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					Print2("SDL_image could not init! SDL_image error: ", IMG_GetError());
					success = false;
				}
			}
		}
	}
	if (TTF_Init() < 0) {
		Print2("SDL_TTF could not init! SDL_TTF error: ", TTF_GetError());
		success = false;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		Print2("SDL_Mix could not init! SDL_Mix error: ", Mix_GetError());
		success = false;
	}
	isRunning = true;
	return success;
}

void Game::gameplay() {
	while (isRunning) {
		input();
		update();
		draw();
	}
	quit();
}

void Game::input() {
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {
	//	Update transforms here.
}

void Game::draw() {
	SDL_RenderClear(renderer);

	//	Bunch of rendercopyex here.

	SDL_RenderPresent(renderer);
}

void Game::quit() {
	//TODO: Clean up clean all fonts, sounds and textures.
	// Sound::Clean
	// Texture::Clean
	// Font::Clean


	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}