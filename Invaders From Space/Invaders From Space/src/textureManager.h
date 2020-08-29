#pragma once
#include "macros.h"
#include "game.h"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* filename);
	static SDL_Rect loadTextureRect(const char* filename);
	//This can be a sprite sheet per char with differing dests.
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
	static void clean(SDL_Texture* texture);
};
