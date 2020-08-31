#pragma once
#include "macros.h"
#include "enemy.h"
#include "barrier.h"
#include "player.h"

class Enemy;
class EnemyManager;
class BarrierManager;
class Player;


class GameLoop {
public:

	GameLoop(Game* game);
	~GameLoop();

	void input();
	void update();

	void draw();
	void createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]);
	void drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]);

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
	std::array<SDL_Rect, 9> borderBannerSrc;
	std::array<SDL_Rect, 9> borderBannerDst;

	//	Fonts
	TTF_Font* font = nullptr;
	const char* message;
	SDL_Rect titlePos;
	SDL_Rect borderSize = { 25, 25, 526, 100 };
	SDL_Color color = { 154,217,65,255 };

	//	Enemies
	EnemyManager* enemyManager;
	
	//	Barrier
	BarrierManager* barrierManager;

	//	Player
	Player* player;

};
