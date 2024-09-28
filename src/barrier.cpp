#include "barrier.h"


BarrierManager::BarrierManager() {

}

BarrierManager::~BarrierManager() {
	for (auto& a : barriers) {
		delete a;
	}
}

void BarrierManager::draw() {
	for (auto& barrier : barriers) {
		if (barrier != nullptr)barrier->draw();
	}
}

void BarrierManager::spawnBarriers() {
	for (int i = 0; i < 4; i++)
	{
		SDL_Rect pos = { 64 + (i * 128), 704, 0,0 };
		barriers.push_back(new Barrier(&pos, this));
	}
}

std::vector<Barrier*>& BarrierManager::getBarriers() {
	return barriers;
}


void BarrierManager::destroyBarrier(Barrier* barrier) {
	for (int i = 0; i < barriers.size(); i++)
	{
		if (barriers[i] == barrier) {
			delete barriers[i];
			barriers[i] = nullptr;
			barriers.erase(barriers.begin() + i);
			break;
		}
	}
}

//==============================

Barrier::Barrier(SDL_Rect* startPos, BarrierManager* barrierManager) {
	this->barrierManager = barrierManager;
	barrierTexture = TextureManager::loadTexture("barrier.png");
	barrierSrc = TextureManager::loadTextureRect("barrier.png");
	barrierSrc.h = barrierSrc.h / 4;
	barrierPos = { startPos->x, startPos->y, barrierSrc.w * 2,barrierSrc.h * 2 };
	barrierCollider = { startPos->x+12, startPos->y+8, 52, 24 };
}

Barrier::~Barrier() {
	SDL_DestroyTexture(barrierTexture);
	barrierTexture = nullptr;
	barrierManager = nullptr;
}

void Barrier::draw() {
	TextureManager::draw(barrierTexture, &barrierSrc, &barrierPos);
}

SDL_Rect* Barrier::getBarrierRect() {
	return &barrierCollider;
}

void Barrier::loseHealth(int damageAmount) {
	health -= damageAmount;
	if (health <= 100 && health > 75) barrierSrc.y = 0;
	if (health <= 75 && health > 50) barrierSrc.y = 16;
	if (health <= 50 && health > 25) barrierSrc.y = 32;
	if (health <= 25 && health > 0) barrierSrc.y = 48;

	if (health > 100 || health < 0) {
		barrierManager->destroyBarrier(this);
	}
}

