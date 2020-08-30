#include "gameloop.h"

bool GameLoop::isRunning = false;

GameLoop::GameLoop(Game* game) {
	isRunning = true;
	this->game = game;
}

void GameLoop::input() {

}
void GameLoop::update() {

}
void GameLoop::draw() {

}