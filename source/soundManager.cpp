#include "soundManager.h"

Mix_Music* SoundManager::loadMusic(const char* filename) {
	const char* dir = "assets/sounds/";
	string path(string(dir) + string(filename));
	Mix_Music* result = Mix_LoadMUS(path.c_str());
	if (result == nullptr) Print2("Could not load music!", Mix_GetError());
	return result;
}

void SoundManager::playMusic(Mix_Music* music) {
	if (Mix_PlayingMusic() == 0) Mix_PlayMusic(music, -1);
}

Mix_Chunk* SoundManager::loadSFX(const char* filename) {
	const char* dir = "assets/sounds/";
	string path(string(dir) + string(filename));
	Mix_Chunk* result = Mix_LoadWAV(path.c_str());
	if (result == nullptr) Print2("Could not load SFX!", Mix_GetError());
	return result;
}

void SoundManager::playSFX(Mix_Chunk* chunk) {
	Mix_PlayChannel(-1, chunk, 0);
}

void SoundManager::cleanMusic(Mix_Music* music) {
	Mix_FreeMusic(music);
}

void SoundManager::cleanSFX(Mix_Chunk* chunk) {
	Mix_FreeChunk(chunk);
}