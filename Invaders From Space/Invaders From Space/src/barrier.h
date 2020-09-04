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

private:
	std::vector<Barrier*> barriers;
};

class Barrier {
public:
	Barrier(SDL_Rect* startPos);
	~Barrier();

	void draw();

	SDL_Rect* getBarrierRect();

private:
	SDL_Texture* barrierTexture;
	SDL_Rect barrierSrc;
	SDL_Rect barrierPos;

	SDL_Rect barrierCollider;

};