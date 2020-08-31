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

private:
	std::array<Barrier*, 4> barriers;
};

class Barrier {
public:
	Barrier(SDL_Rect* startPos);
	~Barrier();

	void draw();

private:
	SDL_Texture* barrierTexture;
	SDL_Rect barrierSrc;
	SDL_Rect barrierPos;
};