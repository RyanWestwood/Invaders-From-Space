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
		barriers[i] = new Barrier(&pos);
	}
}

//==============================

Barrier::Barrier(SDL_Rect* startPos) {
	barrierTexture = TextureManager::loadTexture("barrier.png");
	barrierSrc = TextureManager::loadTextureRect("barrier.png");
	barrierSrc.h = barrierSrc.h / 4;
	barrierPos = { startPos->x, startPos->y, barrierSrc.w * 2,barrierSrc.h * 2 };
}

Barrier::~Barrier() {
	SDL_DestroyTexture(barrierTexture);
	barrierTexture = nullptr;
}

void Barrier::draw() {
	TextureManager::draw(barrierTexture, &barrierSrc, &barrierPos);
}