#pragma once
#include "macros.h"

class Enemy;

class EnemyManager {
public:
	EnemyManager();
	~EnemyManager();

	void input();
	void update();
	void draw();

	//void addEnemy(Enemy* enemy);
	void spawnWave();
private:
	//	7, 5
	int enemyIndex = 0;
	std::array<Enemy*, 35> enemies;

	//	TODO: make this spawn different sprites and anim.
	//std::array<SDL_Texture*, 10> sprites;

	bool left, right;

};

class Enemy {
public:
	Enemy(SDL_Rect startPos);
	~Enemy();

	void input();
	void update(int whichWayToMove);
	void draw(int anim);

	int xPos() { return enemyPos.x; }

private:
	SDL_Texture* enemySprite;
	SDL_Rect enemySrc1;
	SDL_Rect enemySrc2;
	//	Have a seperate box collider?
	SDL_Rect enemyPos;
};