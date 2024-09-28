#pragma once
#include "macros.h"
#include "player.h"

class Bullet;
class Player;

class BulletManager {
public:
	BulletManager();
	~BulletManager();

	void update();
	void draw();

	void shoot(int xPos);
	void offScreen();

	std::vector<Bullet*>& getBullets();
	void bulletHit(Bullet* bullet);
	void print();


private:
	std::vector<Bullet*> bullets;

};

class Bullet {
public: 
	Bullet(int pos, BulletManager* bulletManager);
	~Bullet();

	void update();
	void draw();

	SDL_Rect* getBulletRect();

private:
	BulletManager* bulletManager;

	SDL_Texture* bulletTexture;
	SDL_Rect bulletSrc;
	SDL_Rect bulletPos;

	SDL_Rect bulletCollider;
};