#include "button.h"

Button::Button(SDL_Rect* rect, const char* message, ButtonManager* buttonManager) {
	button = TextureManager::loadTexture("button.png");
	buttonSrc = TextureManager::nineClipSrc(9, 48, 48);
	buttonDst = TextureManager::nineClipDst(rect->x, rect->y, rect->w, rect->h, 9);
	this->message = message;
	font = FontManager::loadFont("Pixel.ttf", 20);
	textPos = FontManager::fontRect(font, message);
	buttonSize = *rect;
	buttonManager->addButton(this);
}

Button::~Button() {
	//	TODO: Use this as template cleanup.
	//	only use delete when new word is allocated.
	TextureManager::clean(button);
	button = nullptr;
	FontManager::clean(font);
	font = nullptr;
}

void Button::draw() {
	TextureManager::drawNine(button, buttonSrc, buttonDst);
	FontManager::drawFont(font, message, buttonDst[0].x + ((buttonSize.w/2) - (textPos.w/2)), buttonDst[0].y + ((buttonSize.h/2) - (textPos.h/3)), &color);
}

void Button::clean() {
	SDL_DestroyTexture(button);
	TTF_CloseFont(font);
	delete message;
	button = nullptr;
	font = nullptr;
	message = nullptr;
}