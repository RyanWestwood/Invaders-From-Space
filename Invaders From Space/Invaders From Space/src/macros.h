#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <iostream>

#define DEBUG 1

#if DEBUG == 1
#define Print(x) std::cout << x << std::endl
#define Print2(x, y) std::cout << x << ", " << y << std::endl
#elif DEBUG == 0
#define Print(x)
#define Print2(x,y)
#endif
