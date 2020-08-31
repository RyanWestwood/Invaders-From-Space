#include "bullet.h"

BulletManager::BulletManager(Player* player) {
	this->player = player;
}

BulletManager::~BulletManager() {
	player = nullptr;
	for (int element = 0; element < bullets.size(); element++)
	{
		delete bullets[element];
	}
	bullets.clear();
}


void BulletManager::update() {
	if (!bullets.empty()) {
		for (auto* bullet : bullets) {
			if (bullet != nullptr) bullet->update();
		}
	}
}

void BulletManager::draw() {
	if (!bullets.empty()) {
		for (auto* bullet : bullets) {
			if (bullet != nullptr) bullet->draw();
		}
	}
}

void BulletManager::shoot() {
	bullets.insert(bullets.begin(), new Bullet(player->playerX(), this));
}

void BulletManager::offScreen() {
	if (!bullets.empty()) {
		delete bullets.back();
		bullets.back() = nullptr;
		bullets.erase(bullets.end() - 1);;
	}
}

//==================================

Bullet::Bullet(int pos, BulletManager* bulletManager) {
	this->bulletManager = bulletManager;
	bulletTexture = TextureManager::loadTexture("playerBullet.png");
	bulletSrc = TextureManager::loadTextureRect("playerBullet.png");
	bulletSrc.h = 16;
	bulletPos = { pos, 832, bulletSrc.w * 4, bulletSrc.h * 4 };
}

Bullet::~Bullet() {
	SDL_DestroyTexture(bulletTexture);
	bulletTexture = nullptr;
	bulletManager = nullptr;
}

void Bullet::update() {
	bulletPos.y -= 5;
	if (bulletPos.y < 150) {
		bulletManager->offScreen();
	}
}

void Bullet::draw() {
	TextureManager::draw(bulletTexture, &bulletSrc, &bulletPos);
}