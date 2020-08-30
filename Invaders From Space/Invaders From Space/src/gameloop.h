#pragma once
#include "macros.h"

class GameLoop {
public:

	GameLoop(Game* game);

	void input();
	void update();
	void draw();

	static bool isRunning;

private:
	Game* game;

	//	Background.
	SDL_Texture* space = nullptr;
	SDL_Rect spaceSrc;
	SDL_Rect spaceDst[9][16];

	SDL_Texture* building = nullptr;
	SDL_Rect buildingSrc;
	SDL_Rect buildingDst[9][16];

	SDL_Texture* cover = nullptr;
	SDL_Rect coverSrc;
	SDL_Rect coverDst[9][16];

	// Borders.
	SDL_Texture* border = nullptr;
	std::array<SDL_Rect, 9> borderTitleSrc;
	std::array<SDL_Rect, 9> borderTitleDst;

	std::array<SDL_Rect, 9> borderScoresSrc;
	std::array<SDL_Rect, 9> borderScoresDst;

	//	Buttons.
	ButtonManager* buttonManager;

	//	Fonts
	TTF_Font* font = nullptr;
	const char* message;
	SDL_Rect titlePos;
	SDL_Rect borderSize = { 25, 25, 526, 100 };
	SDL_Color color = { 154,217,65,255 };

};
