#pragma once
#include "macros.h"

class MainMenu {
public:
	//TODO: change SDL_Rect to 2 std::array
	//std::array<std::array<SDL_Rect, 9>, 7> saceDst;
	MainMenu();
	~MainMenu();

	void input();
	void update();
	void draw();

	void drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]);
	void createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]);

	bool isRunning() { return running; }
	void isRunning(bool value) { running = value; }

private:
	bool running = true;

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
	std::array<std::array<SDL_Rect, 9>, 7> test;
	SDL_Rect coverDst[9][16];

	SDL_Texture* border = nullptr;
	std::array<SDL_Rect, 9> borderSrc;
	std::array<SDL_Rect, 9> borderDst;

	SDL_Texture* logo = nullptr;
	SDL_Rect logoSrc;
	SDL_Rect logoDst;

	//	Buttons

	ButtonManager buttonManager = ButtonManager();

	SDL_Rect playDst = { 138, 363, 300, 100 };
	Button play = Button(&playDst, "PLAY", &buttonManager);

	SDL_Rect hiscoresDst = { 138, 513, 300, 100 };
	Button hiscores = Button(&hiscoresDst, "HISCORES", &buttonManager);

	SDL_Rect optionsDst = { 138, 663, 300, 100 };
	Button options = Button(&optionsDst, "OPTIONS", &buttonManager);

	SDL_Rect exitDst = { 138, 813, 300, 100 };
	Button exit = Button(&exitDst, "EXIT", &buttonManager);
};