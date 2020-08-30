#pragma once
#include "macros.h"
#include "mainMenu.h"
#include "game.h"
class Button;
class MainMenu;
class Game;

class ButtonManager {
public:
	ButtonManager(Game* game);
	void addButton(Button* button);

	void setButtons(int noOfButtons);
	void moveUp();
	void moveDown();
	int select();

	void PrintArray(int size) {
		for (int i = 0; i < size; i++)
		{
			std::cout << buttons[i] << std::endl;
 		}
	}

private:
	Game* game;
	std::array<Button*, 16> buttons;
	SDL_Color green = { 154,217,65,255 };
	SDL_Color black = { 0, 0, 0, 255 };
	int noOfButtons;
	int currentIndex;
	int increment;
};