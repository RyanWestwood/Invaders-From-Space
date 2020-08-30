#pragma once
#include "macros.h"
#include "game.h"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* filename);
	static SDL_Rect loadTextureRect(const char* filename);
	// TODO: This can be a sprite sheet per char with differing dests.
	static void draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);

	static std::array<SDL_Rect, 9> nineClipSrc(int b, int w, int h);
	static std::array<SDL_Rect, 9> nineClipDst(int x, int y, int w, int h, int b);
	static void drawNine(SDL_Texture* texture, std::array<SDL_Rect, 9> src, std::array<SDL_Rect, 9> dst);

	static void clean(SDL_Texture* texture);
};
