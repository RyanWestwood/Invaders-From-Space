#pragma once
#include "macros.h"

class SoundManager {
public:
	//TODO: Check paths work.
	//	assets/sounds/ filename.wav


	//	URGENT: FINISH TEXTUURE and FONT!
	static Mix_Music* loadMusic(const char* filename);
	static Mix_Chunk* loadSFX(const char* filename);
	static void playMusic(Mix_Music* music);
	static void playSFX(Mix_Chunk* chunk);
	static void cleanMusic(Mix_Music* music);
	static void cleanSFX(Mix_Chunk* sfx);
};
