#pragma once
#include "macros.h"
#include "player.h"

class Bullet;
class Player;

class BulletManager {
public:
	BulletManager(Player* player);
	~BulletManager();

	void update();
	void draw();

	void shoot();
	void offScreen();

private:
	Player* player;
	std::vector<Bullet*> bullets;

};

class Bullet {
public: 
	Bullet(int pos, BulletManager* bulletManager);
	~Bullet();

	void update();
	void draw();

private:
	BulletManager* bulletManager;
	SDL_Texture* bulletTexture;
	SDL_Rect bulletSrc;
	SDL_Rect bulletPos;
};