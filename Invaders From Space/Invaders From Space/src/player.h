#pragma once
#include "macros.h"
#include "game.h"
#include "bullet.h"

class BulletManager;

class Player {
public:
	Player(Game* game);
	~Player();

	void input();
	void update();
	void draw();

	void loseHealth(int damageAmount = 1);
	void loseLife(int livesLost);

	int playerX() { return static_cast<int>(playerPos.x); }

private:
	Game* game;

	SDL_Texture* playerTexture;
	SDL_Rect playerSrc;
	SDL_Rect playerPos;

	int health = 5;
	int lives = 3;

	int speed = 5;
	int velocity = 0;

	BulletManager* bulletManager;


	//	Test
	std::list<int> temp;

	int fireRateDelay = 400;
	int lastShot = 0;


};