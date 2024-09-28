#pragma once
#include "macros.h"

//	TODO: Make sure all parameters use pointers?
class Barrier;

class BarrierManager {
public:
	BarrierManager();
	~BarrierManager();

	void draw();
	void spawnBarriers();

	std::vector<Barrier*>& getBarriers();

	void destroyBarrier(Barrier* barrier);

private:
	std::vector<Barrier*> barriers;
};

class Barrier {
public:
	Barrier(SDL_Rect* startPos, BarrierManager* barrierManager);
	~Barrier();

	void draw();

	SDL_Rect* getBarrierRect();
	void loseHealth(int damageAmount = 5);

private:
	BarrierManager* barrierManager;

	SDL_Texture* barrierTexture;
	SDL_Rect barrierSrc;
	SDL_Rect barrierPos;

	SDL_Rect barrierCollider;

	int health = 100;
};