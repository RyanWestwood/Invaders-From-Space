#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <string>

#include <iostream>

#include "soundManager.h"
#include "fontManager.h"
#include "textureManager.h"
#include "button.h"

using std::string;

#define DEBUG 1

#if DEBUG == 1
#define Print(x) std::cout << x << std::endl
#define Print2(x, y) std::cout << x << ", " << y << std::endl
#elif DEBUG == 0
#define Print(x)
#define Print2(x,y)
#endif
