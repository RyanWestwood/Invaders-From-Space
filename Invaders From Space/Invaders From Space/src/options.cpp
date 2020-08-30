#include "options.h"

bool Options::isRunning = false;

Options::Options(Game* game) {
	Options::isRunning = true;
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

	//	Borders
	border = TextureManager::loadTexture("border.png");
	borderTitleSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderTitleDst = TextureManager::nineClipDst(25, 25, 526, 100, 3);

	borderScoresSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderScoresDst = TextureManager::nineClipDst(25, 150, 526, 724, 3);

	//	Buttons
	buttonManager = new ButtonManager(game);

	enterDst = { 25, 899, 526, 100 };
	enter = new Button(&enterDst, "ENTER", buttonManager);

	buttonManager->setButtons(1);

	//	Fonts
	font = FontManager::loadFont("Pixel.ttf", 40);
	message = "OPTIONS";
	titlePos = FontManager::fontRect(font, message);
}

Options::~Options() {
	SDL_DestroyTexture(space);
	SDL_DestroyTexture(building);
	SDL_DestroyTexture(cover);
	SDL_DestroyTexture(border);
	TTF_CloseFont(font);
	delete buttonManager;
	delete enter;
}

void Options::input() {
	while (SDL_PollEvent(&Game::event) != 0)
	{
		if (Game::event.type == SDL_QUIT)
		{
			isRunning = false;
			Game::isRunning = false;
		}
		else if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_RETURN:
				Options::isRunning = false;
				game->menuOptions = Game::menus::mainmenu;
				break;
			default:
				break;
			}
		}
	}
}
void Options::update() {

}
void Options::draw() {
	SDL_RenderClear(Game::renderer);

	drawLayer(9, 16, space, spaceSrc, spaceDst);
	drawLayer(9, 1, building, buildingSrc, buildingDst);
	drawLayer(9, 7, cover, coverSrc, coverDst);
	TextureManager::drawNine(border, borderTitleSrc, borderTitleDst);
	TextureManager::drawNine(border, borderScoresSrc, borderScoresDst);

	enter->draw();

	FontManager::drawFont(font, message, borderTitleDst[0].x + ((borderSize.w / 2) - (titlePos.w / 2)),
		borderTitleDst[0].y + ((borderSize.h / 2) - (titlePos.h / 3)), &color);

	SDL_RenderPresent(Game::renderer);
}

void Options::drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			TextureManager::draw(texture, &src, &dst[x][y]);
		}
	}
}
void Options::createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			dst[x][y] = { x * 64, yOffset + y * 64, 64, 64 };
		}
	}
}