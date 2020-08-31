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

	//	Enemy
	enemyManager = new EnemyManager();
	enemyManager->spawnWave();

	//	Barrier
	barrierManager = new BarrierManager();
	barrierManager->spawnBarriers();

	//	Player
	player = new Player(game);

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
	TTF_CloseFont(font);
	font = nullptr;
	delete enemyManager;
	delete barrierManager;
	delete player;
}

void GameLoop::input() {
	player->input();
}

void GameLoop::update() {
	enemyManager->update();

	player->update();
}
void GameLoop::draw() {
	SDL_RenderClear(Game::renderer);

	/// Background
	drawLayer(9, 16, space, spaceSrc, spaceDst);
	drawLayer(9, 1, building, buildingSrc, buildingDst);
	drawLayer(9, 7, cover, coverSrc, coverDst);
	TextureManager::drawNine(border, borderBannerSrc, borderBannerDst);

	//	Enemy.
	enemyManager->draw();

	//	Barrier
	barrierManager->draw();

	//	Player
	player->draw();

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
