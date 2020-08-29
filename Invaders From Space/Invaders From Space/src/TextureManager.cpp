#include "textureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filename) {
	const char* dir = "assets/sprites/";
	string path(string(dir) + string(filename));

	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr) Print("Could not load sprite");
	SDL_Texture* result = SDL_CreateTextureFromSurface(Game::renderer, surface);
	if (result == nullptr) Print("Could not create texture from surface");
	SDL_FreeSurface(surface);
	return result;
}

SDL_Rect TextureManager::loadTextureRect(const char* filename) {
	const char* dir = "assets/sprites/";
	string path(string(dir) + string(filename));

	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr) Print("Could not load surface png");
	SDL_Rect result = { 0,0, surface->w, surface->h };
	return result;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

void TextureManager::clean(SDL_Texture* texture) {
	SDL_DestroyTexture(texture);
}