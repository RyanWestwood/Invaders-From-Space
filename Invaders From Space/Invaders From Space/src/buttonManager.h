#pragma once
#include "macros.h"
#include "mainMenu.h"
class Button;
class MainMenu;

class ButtonManager {
public:

	ButtonManager();
	void addButton(Button* button);

	void setButtons();
	void moveUp();
	void moveDown();
	void select();

	void PrintArray(int size) {
		for (int i = 0; i < size; i++)
		{
			std::cout << buttons[i] << std::endl;
 		}
	}

private:
	std::array<Button*, 64> buttons;
	SDL_Color green = { 154,217,65,255 };
	SDL_Color black = { 0, 0, 0, 255 };
	enum menuIndex {
		play, 
		hiscores, 
		options, 
		exit
	};
	int currentIndex;
};