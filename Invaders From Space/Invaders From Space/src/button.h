#pragma once
#include "macros.h"
#include "buttonManager.h"

class ButtonManager;

class Button {
public:

	Button(SDL_Rect* rect, const char* message, ButtonManager* buttonManager);
	~Button();
	void clean();

	void setColor(SDL_Color color) { this->color = color; }

	void draw();

private: 
	SDL_Texture* button = nullptr;
	TTF_Font* font = nullptr;
	std::array<SDL_Rect, 9> buttonSrc;
	std::array<SDL_Rect, 9> buttonDst;
	const char* message;
	SDL_Rect textPos;
	SDL_Rect buttonSize;
	SDL_Color color = { 154,217,65,255 };
};
