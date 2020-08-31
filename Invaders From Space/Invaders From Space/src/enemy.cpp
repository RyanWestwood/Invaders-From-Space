#include "enemy.h"

EnemyManager::EnemyManager() {
	for (auto& enemy : enemies) enemy = nullptr;
	left = true;
	right = false;
}

EnemyManager::~EnemyManager() {
	for (auto& enemy : enemies) delete enemy;
}

void EnemyManager::input() {

}
void EnemyManager::update() {
	if (enemies[0]->xPos() <= 0) {
		right = true;
		left = false;
	}
	if (enemies[0]->xPos() >= 128) {
		right = false;
		left = true;
	}
	for (auto& e : enemies) {
		if (e != nullptr) {
			if (left) {
				e->update(0);
			}
			else if (right) {
				e->update(1);
			}
		}
	}
}
void EnemyManager::draw() {
	for (auto& e : enemies) {
		if (e != nullptr) {
			if (SDL_GetTicks() % 1000 <= 500)
			{
				e->draw(0);
			}
			else {
				e->draw(1);
			}
		}
	}

}

//void EnemyManager::addEnemy(Enemy* enemy) {
//	enemies[enemyIndex] = enemy;
//	enemyIndex++;
//}

void EnemyManager::spawnWave() {
	int count = 0;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			SDL_Rect pos = { 64 + (x * 64), 192 + (y * 64), 64, 64 };
			enemies[count] = new Enemy(pos);
			count++;
		}
	}
}

//=============================

Enemy::Enemy(SDL_Rect startPos) {
	enemySprite = TextureManager::loadTexture("enemy.png");
	enemySrc1 = { 0,0, 16, 16 };
	enemySrc2 = { 16,0, 16, 16 };
	enemyPos = { startPos.x, startPos.y, enemySrc1.w * 4, enemySrc1.h * 4 };
}

Enemy::~Enemy() {
	SDL_DestroyTexture(enemySprite);
	enemySprite = nullptr;
}

void Enemy::input() {

}
void Enemy::update(int whichWayToMove) {
	//	0 Left, 1 Right.
	if (whichWayToMove == 0) {
		enemyPos.x -= 1;
	}
	else if (whichWayToMove == 1) {
		enemyPos.x += 1;
	}
}
void Enemy::draw(int anim) {
	if (anim == 0) {
		TextureManager::draw(enemySprite, &enemySrc1, &enemyPos);
	}
	else {
		TextureManager::draw(enemySprite, &enemySrc2, &enemyPos);
	}
}