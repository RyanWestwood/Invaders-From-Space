#include "fontManager.h"

TTF_Font* FontManager::loadFont(const char* filename, int size) {
	const char* dir = "assets/fonts/";
	string path(string(dir) + string(filename));
	TTF_Font* result = TTF_OpenFont(path.c_str(), size);
	if (result == nullptr) Print2("Could not load font!", TTF_GetError());
	return result;
}

void FontManager::drawFont(TTF_Font* font, const char* message, int x, int y) {
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Color color = { 154,217,65,255 };
	surface = TTF_RenderText_Solid(font, message, color);
	if (surface == nullptr) Print2("could not Render text", 1);
	texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_Rect rect = { x, y, surface->w, surface->h };

	SDL_FreeSurface(surface);
	SDL_RenderCopy(Game::renderer, texture, 0, &rect);
	SDL_DestroyTexture(texture);
}
