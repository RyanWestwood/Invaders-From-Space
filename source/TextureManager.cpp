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

void TextureManager::draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
	SDL_RenderCopy(Game::renderer, texture, src, dest);
}


void TextureManager::clean(SDL_Texture* texture) {
	SDL_DestroyTexture(texture);
}

std::array<SDL_Rect, 9> TextureManager::nineClipSrc(int border, int width, int height) {
	std::array<SDL_Rect, 9> borderClip;

	borderClip[0] = { 0, 0, border, border };
	borderClip[1] = { border, 0, width - (2 * border), border };
	borderClip[2] = { width - border, 0, border, border };

	borderClip[3] = { 0, border, border, height - (2 * border) };
	borderClip[4] = { border,border, width - (2 * border),height - (2 * border) };
	borderClip[5] = { width - border, border, border, height - (2 * border) };

	borderClip[6] = { 0, height - border, border, border };
	borderClip[7] = { border, height - border, width - (2 * border), border };
	borderClip[8] = { width - border, height - border, border, border };

	return borderClip;
}

std::array<SDL_Rect, 9> TextureManager::nineClipDst(int x, int y, int width, int height, int border) {
	std::array<SDL_Rect, 9> borderPos;

	borderPos[0] = { x,y,border,border };
	borderPos[1] = { x + border,y,width - (2 * border),border };
	borderPos[2] = { x + (width - border), y, border, border };

	borderPos[3] = { x, y + border, border, height - (2 * border) };
	borderPos[4] = { x + border, y + border, width - (2 * border), height - (2 * border) };
	borderPos[5] = { x + (width - border),y + border, border, height - (2 * border) };

	borderPos[6] = { x, y + (height - border), border, border };
	borderPos[7] = { x + border,y + (height - border), width - (2 * border),border };
	borderPos[8] = { x + (width - border), y + (height - border), border, border };

	return borderPos;
}

void TextureManager::drawNine(SDL_Texture* texture, std::array<SDL_Rect, 9> src, std::array<SDL_Rect, 9> dst) {
	for (int i = 0; i < 9; i++)
	{
		TextureManager::draw(texture, &src[i], &dst[i]);
	}
}