#pragma once
#include "macros.h"
#include "enemy.h"
#include "barrier.h"
#include "player.h"
#include "bullet.h"
#include "collision.h"

class Enemy;
class EnemyManager;
class BarrierManager;
class Player;
class BulletManager;

//	TODO: use inheritance to print background?
//	TODO: move player ui to player class?
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

	void increaseScore(int scoreAmount = 5);
	void loseHealth();
	void loseLife();

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

	//	UI.
	SDL_Texture* health = nullptr;
	SDL_Rect healthSrc;
	SDL_Rect healthDst;

	SDL_Texture* lives = nullptr;
	SDL_Rect livesSrc[3];
	SDL_Rect livesDst[3];

	const char* livesString = "LIVES";
	const char* healthString = "HEALTH";
	const char* scoreString = "SCORE";
	std::string scoreStringInt = "000000";
	int score = 0;


	//	Fonts
	TTF_Font* font = nullptr;
	SDL_Rect titlePos;
	SDL_Rect borderSize = { 25, 25, 526, 100 };
	SDL_Color color = { 154,217,65,255 };

	//	Enemies
	EnemyManager* enemyManager;
	
	//	Barrier
	BarrierManager* barrierManager;

	//	Player
	Player* player;

	//	Bullets
	BulletManager* bulletManager;

	int fireRateDelay = 100;
	int lastShot = 0;


	//	DEBUG
	int healthInt = 5;
	int livesInt = 3;

};
