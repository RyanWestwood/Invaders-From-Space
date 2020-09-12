#include "gameloop.h"

bool GameLoop::isRunning = false;

GameLoop::GameLoop(Game* game) {
	isRunning = true;
	this->game = game;

	//	Background
	space = TextureManager::loadTexture("space.png");
	spaceSrc = TextureManager::loadTextureRect("space.png");
	createLayer(9, 16, 0, spaceDst);

	building = TextureManager::loadTexture("buildings.png");
	buildingSrc = TextureManager::loadTextureRect("buildings.png");
	createLayer(9, 1, 640, buildingDst);

	cover = TextureManager::loadTexture("cover.png");
	coverSrc = TextureManager::loadTextureRect("cover.png");
	createLayer(9, 5, 704, coverDst);

	border = TextureManager::loadTexture("border.png");
	borderBannerSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderBannerDst = TextureManager::nineClipDst(25, 25, 526, 100, 3);

	//	UI. TODO: could use template take reference of variables? to make single functions
	//	Health
	//change .y for health.
	health = TextureManager::loadTexture("health.png");
	healthSrc = TextureManager::loadTextureRect("health.png"); //32, 16
	healthSrc.h = 16;
	healthDst = { 54,59, healthSrc.w * 4, healthSrc.h* 4 };

	//	Text.
	font = FontManager::loadFont("Pixel.ttf", 20);

	//	Lives
	//	change .x for lives.
	lives = TextureManager::loadTexture("player.png");
	livesSrc = TextureManager::loadTextureRect("player.png"); //16, 16
	livesSrc.w = 16;
	for (int i = 0; i < 3; i++)
	{
		livesDst[i] = { 211 + (i * 48),59, livesSrc.w * 4, livesSrc.h * 4 };
	}

	//	Enemy
	enemyManager = new EnemyManager();
	enemyManager->spawnWave();

	//	Barrier
	barrierManager = new BarrierManager();
	barrierManager->spawnBarriers();

	bulletManager = new BulletManager();
	//	Player
	player = new Player(game, bulletManager);

}

GameLoop::~GameLoop() {
	SDL_DestroyTexture(space);
	space = nullptr;
	SDL_DestroyTexture(building);
	building = nullptr;
	SDL_DestroyTexture(cover);
	cover = nullptr;
	SDL_DestroyTexture(border);
	border = nullptr;
	SDL_DestroyTexture(health);
	health = nullptr;
	TTF_CloseFont(font);
	font = nullptr;
	delete enemyManager;
	delete barrierManager;
	delete player;
}

void GameLoop::input() {

	//TODO: Remove debug s
	if (Game::event.type == SDL_QUIT)
	{
		GameLoop::isRunning = false;
		Game::isRunning = false;
	}
	player->input();
}

void GameLoop::update() {
	enemyManager->update();
	player->update();

	auto& bulletColliders(bulletManager->getBullets());
	auto& enemyColliders(enemyManager->getEnemies());
	auto& barrierColliders(barrierManager->getBarriers());

	//	TODO: Why does this not work while space is held down. but works if left/right is.
	for (auto& bullet : bulletColliders) {
		for (auto& enemy : enemyColliders) {
			if (Collision::checkCollision(*bullet->getBulletRect(), *enemy->getEnemyRect())) {
				enemyManager->enemyHit(enemy);
				bulletManager->bulletHit(bullet);
				increaseScore();
				goto br;
			}

		}
		for (auto& barrier : barrierColliders) {
			if (Collision::checkCollision(*bullet->getBulletRect(), *barrier->getBarrierRect())) {
				bulletManager->bulletHit(bullet);
				goto br;
			}
		}
	br:
		break;

	}
}

void GameLoop::draw() {
	SDL_RenderClear(Game::renderer);

	/// Background
	drawLayer(9, 16, space, spaceSrc, spaceDst);
	drawLayer(9, 1, building, buildingSrc, buildingDst);
	drawLayer(9, 7, cover, coverSrc, coverDst);
	TextureManager::drawNine(border, borderBannerSrc, borderBannerDst);

	//	UI
	TextureManager::draw(health, &healthSrc, &healthDst);
	for (int i = 0; i < 3; i++)
	{
		TextureManager::draw(lives, &livesSrc, &livesDst[i]);
	}

	FontManager::drawFont(font, healthString, 65, 42, &color);
	FontManager::drawFont(font, livesString, 255, 42, &color);
	FontManager::drawFont(font, scoreString, 419, 42, &color);
	FontManager::drawFont(font, scoreStringInt.data(), 408, 82, &color);

	//	Enemy.
	enemyManager->draw();

	//	Barrier
	barrierManager->draw();

	//	Player
	player->draw();

	//UI.

	SDL_RenderPresent(Game::renderer);
}

void GameLoop::drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			TextureManager::draw(texture, &src, &dst[x][y]);
		}
	}
}
void GameLoop::createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			dst[x][y] = { x * 64, yOffset + y * 64, 64, 64 };
		}
	}
}

void GameLoop::increaseScore(int scoreAmount) {
	score += scoreAmount;
	scoreStringInt = std::string(6 - std::to_string(score).length(), '0') + std::to_string(score);
}