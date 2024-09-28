#pragma once
#include "macros.h"
#include "game.h"

class FontManager {
public:
	//	TODO: Vector 2 class.
	static TTF_Font* loadFont(const char* filename, int size);
	static void drawFont(TTF_Font* font, const char* message, int x, int y, SDL_Color* color);
	static void clean(TTF_Font* font) { TTF_CloseFont(font); }
	static SDL_Rect fontRect(TTF_Font* font, const char* message);
	
		
		//	TODO: Have multiple fonts? h1, h2, h3
};