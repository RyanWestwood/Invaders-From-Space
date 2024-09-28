#pragma once
#include "macros.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "game.h"
#include "button.h"
#include "buttonManager.h"

class Button;
class ButtonManager;
class Game;

class Hiscores {
public:

	Hiscores(Game* game);

	void input();
	void draw();
	void update() {};

	static bool isRunning;

	void getFile();
	void setFile();
	void createFile();

	void setScores();

	void createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]);
	void drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]);

	~Hiscores();

private:
	Game* game;
	int scores[11];
	const char* scoreFile = "assets/txt/scores.txt";

	//	Background 
	//	9,	16.
	// 8
	SDL_Texture* space = nullptr;
	SDL_Rect spaceSrc;
	SDL_Rect spaceDst[9][16];

	// 1
	SDL_Texture* building = nullptr;
	SDL_Rect buildingSrc;
	SDL_Rect buildingDst[9][16];

	// 7 
	SDL_Texture* cover = nullptr;
	SDL_Rect coverSrc;
	std::array<std::array<SDL_Rect, 9>, 7> test;
	SDL_Rect coverDst[9][16];

	// Borders
	SDL_Texture* border = nullptr;
	std::array<SDL_Rect, 9> borderTitleSrc;
	std::array<SDL_Rect, 9> borderTitleDst;

	std::array<SDL_Rect, 9> borderScoresSrc;
	std::array<SDL_Rect, 9> borderScoresDst;

	//	Buttons
	ButtonManager* buttonManager;

	SDL_Rect enterDst;
	Button* enter;

	//	Fonts
	TTF_Font* font = nullptr;
	const char* message;
	SDL_Rect titlePos;
	SDL_Rect borderSize = { 25, 25, 526, 100 };
	SDL_Color color = { 154,217,65,255 };

	std::array<std::string, 10> scoreText;
	std::array<SDL_Rect, 10> scoreTextPos;
};
