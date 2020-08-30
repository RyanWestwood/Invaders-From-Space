#include "buttonManager.h"

ButtonManager::ButtonManager() {
	//	TODO: Make enter do things.
	currentIndex = 0;
}

void ButtonManager::addButton(Button* button) {
	static int increment = 0;
	buttons[increment] = button;
	increment++;
}

void ButtonManager::setButtons() {
	for (int i = 0; i < 4; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

void ButtonManager::moveUp() {
	currentIndex--;
	if (currentIndex < 0) currentIndex = 3;
	for (int i = 0; i < 4; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

void ButtonManager::moveDown() {
	currentIndex++;
	if (currentIndex > 3) currentIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		buttons[i]->setColor(black);
	}
	buttons[currentIndex]->setColor(green);
}

void ButtonManager::select() {
	switch (currentIndex)
	{
	case play:
		break;
	case hiscores:
		break;
	case options:
		break;
	case exit:
		MainMenu::isRunning = false;
		Game::isRunning = false;
		break;
	default:
		break;
	}
}