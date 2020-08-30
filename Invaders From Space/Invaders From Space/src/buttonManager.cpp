#include "buttonManager.h"

ButtonManager::ButtonManager(Game* game) {
	this->game = game;
	currentIndex = 0;
	increment = 0;
	noOfButtons = 0;
	for (auto& button : buttons) button = nullptr;
}

void ButtonManager::addButton(Button* button) {
	buttons[increment] = button;
	increment++;
}

void ButtonManager::setButtons(int noOfButtons) {
	this->noOfButtons = noOfButtons;
	for (int i = 0; i < noOfButtons; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

void ButtonManager::moveUp() {
	currentIndex--;
	if (currentIndex < 0) currentIndex = noOfButtons-1;
	for (int i = 0; i < noOfButtons; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

void ButtonManager::moveDown() {
	currentIndex++;
	if (currentIndex > noOfButtons-1) currentIndex = 0;
	for (int i = 0; i < noOfButtons; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

int ButtonManager::select() {
	return currentIndex;
}