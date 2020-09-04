#include "player.h"

Player::Player(Game* game, BulletManager* bulletManager) {
	this->game = game;
	this->bulletManager = bulletManager;

	playerTexture = TextureManager::loadTexture("player.png");
	playerSrc = TextureManager::loadTextureRect("player.png");
	playerSrc.w = 16;
	playerPos = { 256, 832, playerSrc.w * 4, playerSrc.h * 4 };

}

Player::~Player() {
	SDL_DestroyTexture(playerTexture);
	playerTexture = nullptr;
	game = nullptr;
}

void Player::input() {
	while (SDL_PollEvent(&Game::event) != 0)
	{
		//	TODO: Remove debug 
		if (Game::event.type == SDL_QUIT)
		{
			GameLoop::isRunning = false;
			Game::isRunning = false;
		}
		else if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_LEFT:
				velocity = -1;
				break;

			case SDLK_RIGHT:
				velocity = 1;
				break;

			case SDLK_SPACE:
				if ((SDL_GetTicks() - lastShot) > fireRateDelay)
				{
					bulletManager->shoot(playerPos.x);
					lastShot = SDL_GetTicks();
				}
				break;

#if DEBUG == 1
			case SDLK_w:
				//	Exits game
				GameLoop::isRunning = false;
				Game::isRunning = false;

				break;
			case SDLK_q:
				GameLoop::isRunning = false;
				game->menuOptions = Game::menus::mainmenu;
				break;

			case SDLK_e:
				bulletManager->offScreen();
#endif
			default:
				break;
			}
		}
		else if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_LEFT:
				velocity = 0;
				break;

			case SDLK_RIGHT:
				velocity = 0;
				break;

			case SDLK_SPACE:
				break;

			default:
				break;
			}
		}
	}
}

void Player::update() {
	playerPos.x += static_cast<int>(velocity * speed);
	if (playerPos.x <= 0) playerPos.x = 0;
	if (playerPos.x >= 512) playerPos.x = 512;

	bulletManager->update();
}

void Player::draw() {
	TextureManager::draw(playerTexture, &playerSrc, &playerPos);

	bulletManager->draw();
}

void Player::loseHealth(int damageAmount) {
	//	TODO: Clean here up.
	health -= damageAmount;
	if (health <= 0 && lives > 0) {
		loseLife(1);
		health = 5;
	}
	if (health <= 0 && lives <= 0) {
		//	Set UI
		/*ui->lives(0);
		ui->health(0);*/
		/*GameLoop::isRunning = false;;
		game->menuOptions = Game::hiscores;*/
	}
	//	Set UI
	//ui->health(health);
}

void Player::loseLife(int _livesLost) {
	lives -= _livesLost;
	//ui->lives(lives);
}

SDL_Rect* Player::getPlayerRect() {
	return &playerPos;
}

void Player::setVelocity(int velocity) {
	this->velocity = velocity;
}