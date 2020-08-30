#pragma once
#include "macros.h"
#include "buttonManager.h"
#include "game.h"
class Button;
class ButtonManager;
class Game;


class MainMenu {
public:
	//TODO: change SDL_Rect to 2 std::array
	//std::array<std::array<SDL_Rect, 9>, 7> saceDst;
	MainMenu(Game* game);

	~MainMenu();

	void input();
	void update();
	void draw();

	void drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]);
	void createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]);

	static bool isRunning;

private:

	Game* game;
	enum menuIndex {
		playScreen,
		hiscoresScreen,
		optionsScreen,
		exitScreen
	};
	menuIndex test;
	//	Width height in tiles.
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
	//std::array<std::array<SDL_Rect, 9>, 7> test;
	SDL_Rect coverDst[9][16];

	SDL_Texture* border = nullptr;
	std::array<SDL_Rect, 9> borderSrc;
	std::array<SDL_Rect, 9> borderDst;

	SDL_Texture* logo = nullptr;
	SDL_Rect logoSrc;
	SDL_Rect logoDst;

	//	Buttons

	ButtonManager* buttonManager;

	SDL_Rect playDst;
	Button* play;

	SDL_Rect hiscoresDst;
	Button* hiscores;

	SDL_Rect optionsDst;
	Button* options;

	SDL_Rect exitDst;
	Button* exit;
};