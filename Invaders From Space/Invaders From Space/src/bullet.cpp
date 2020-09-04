#include "bullet.h"

BulletManager::BulletManager() {
}

BulletManager::~BulletManager() {
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

void BulletManager::shoot(int xPos) {
	bullets.insert(bullets.begin(), new Bullet(xPos, this));
}

void BulletManager::offScreen() {
	if (!bullets.empty()) {
		delete bullets.back();
		bullets.back() = nullptr;
		bullets.erase(bullets.end() - 1);;
	}
}

std::vector<Bullet*>& BulletManager::getBullets() {
	return bullets;
}

void BulletManager::bulletHit(Bullet* item)
{
	//print();
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i] == item) {
			delete bullets[i];
			bullets[i] = nullptr;
			bullets.erase(bullets.begin() + i);
			break;
		}
	}
	//print();
}

//==================================

Bullet::Bullet(int pos, BulletManager* bulletManager) {
	this->bulletManager = bulletManager;
	bulletTexture = TextureManager::loadTexture("playerBullet.png");
	bulletSrc = TextureManager::loadTextureRect("playerBullet.png");
	bulletSrc.h = 16;
	bulletPos = { pos, 832, bulletSrc.w * 4, bulletSrc.h * 4 };
	bulletCollider = { pos + 28, 832 + 12, 4, 24 };
}

Bullet::~Bullet() {
	SDL_DestroyTexture(bulletTexture);
	bulletTexture = nullptr;
	bulletManager = nullptr;
}

void Bullet::update() {
	bulletPos.y -= 10;
	bulletCollider.y -= 10;
	if (bulletPos.y < 110) {
		bulletManager->offScreen();
	}
}

void Bullet::draw() {
	TextureManager::draw(bulletTexture, &bulletSrc, &bulletPos);
}

SDL_Rect* Bullet::getBulletRect() {
	return &bulletCollider;
}

