#pragma once
#include "macros.h"
#include "game.h"
#include "bullet.h"

class BulletManager;

class Player {
public:
	Player(Game* game, BulletManager* bulletManager);
	~Player();

	void input();
	void update();
	void draw();

	void loseHealth(int damageAmount = 1);
	void loseLife(int livesLost);

	void setVelocity(int velocity);

	SDL_Rect* getPlayerRect();

private:
	Game* game;
	BulletManager* bulletManager;

	SDL_Texture* playerTexture;
	SDL_Rect playerSrc;
	SDL_Rect playerPos;

	int health = 5;
	int lives = 3;

	int speed = 5;
	int velocity = 0;

	//	Test
	std::list<int> temp;

	int fireRateDelay = 100;
	int lastShot = 0;


};
