#include "mainMenu.h"

MainMenu::MainMenu() {
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
	borderSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderDst = TextureManager::nineClipDst(25, 25, 526, 263, 3);

	logo = TextureManager::loadTexture("logo.png");
	logoSrc = TextureManager::loadTextureRect("logo.png");
	logoDst = { 50,50, 486, 213 };

	buttonManager.setButtons();
}

MainMenu::~MainMenu() {
	TextureManager::clean(space);
	space = nullptr;
	TextureManager::clean(building);
	building = nullptr;
	TextureManager::clean(cover);
	cover = nullptr;
	TextureManager::clean(border);
	border = nullptr;
	TextureManager::clean(logo);
	logo = nullptr;
}

void MainMenu::input() {
	while (SDL_PollEvent(&Game::event) != 0)
	{
		if (Game::event.type == SDL_QUIT)
		{
			isRunning(false);
		}
		else if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_UP:
				buttonManager.moveUp();
				break;

			case SDLK_DOWN:
				buttonManager.moveDown();
				break;
			case SDLK_RETURN:
				break;

			default:
				break;
			}
		}
	}
}

void MainMenu::update() {

}

void MainMenu::draw() {
	SDL_RenderClear(Game::renderer);

	drawLayer(9, 16, space, spaceSrc, spaceDst);
	drawLayer(9, 1, building, buildingSrc, buildingDst);
	drawLayer(9, 7, cover, coverSrc, coverDst);
	TextureManager::drawNine(border, borderSrc, borderDst);
	TextureManager::draw(logo, &logoSrc, &logoDst);
	
	play.draw();
	hiscores.draw();
	options.draw();
	exit.draw();

	SDL_RenderPresent(Game::renderer);
}

void MainMenu::createLayer(int width, int height, int yOffset , SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			dst[x][y] = { x * 64, yOffset+ y * 64, 64, 64 };
		}
	}
}

void MainMenu::drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src , SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			TextureManager::draw(texture, &src, &dst[x][y]);
		}
	}
}