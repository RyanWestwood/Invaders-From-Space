#include "hiscores.h"

bool Hiscores::isRunning = false;

Hiscores::Hiscores(Game* game) {
	this->game = game;
	isRunning = true;
	getFile();
	scores[10] = 25;
	std::sort(scores, scores + 11, std::greater<>());
	setFile();

	//	Background
	isRunning = true;
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
	borderTitleSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderTitleDst = TextureManager::nineClipDst(25, 25, 526, 100, 3);

	borderScoresSrc = TextureManager::nineClipSrc(3, 48, 48);
	borderScoresDst = TextureManager::nineClipDst(25, 150, 526, 724, 3);

	//	Buttons
	buttonManager = new ButtonManager(game);

	enterDst = { 25, 899, 526, 100 };
	enter = new Button(&enterDst, "ENTER", buttonManager);

	buttonManager->setButtons(1);

	//	Text
	font = FontManager::loadFont("Pixel.ttf", 40);
	message = "HI-SCORES";
	titlePos = FontManager::fontRect(font, message);
	setScores();
}

Hiscores::~Hiscores() {
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
	delete buttonManager;
	delete enter;
	game = nullptr;
}

void Hiscores::setFile() {
	std::ofstream myfile(scoreFile);
	if (myfile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			myfile << scores[i] << std::endl;
		}
		myfile.close();
	}
	else Print("Unable to set file");
}

void Hiscores::createFile() {
	std::ofstream myfile(scoreFile);
	if (myfile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			myfile << i << std::endl;
		}
		myfile.close();
	}
	else Print("Unable to create file");
}

void Hiscores::getFile() {
	string line;
	std::ifstream myfile(scoreFile);
	if (myfile.fail()) {
		createFile();
	}
	else if (myfile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			getline(myfile, line);
			scores[i] = stoi(line);
		}
		myfile.close();
	}
	else {
		Print("Unable to get file");
	}
}

void Hiscores::draw() {
	SDL_RenderClear(Game::renderer);

	drawLayer(9, 16, space, spaceSrc, spaceDst);
	drawLayer(9, 1, building, buildingSrc, buildingDst);
	drawLayer(9, 7, cover, coverSrc, coverDst);
	TextureManager::drawNine(border, borderTitleSrc, borderTitleDst);
	TextureManager::drawNine(border, borderScoresSrc, borderScoresDst);

	FontManager::drawFont(font, message, borderTitleDst[0].x + ((borderSize.w / 2) - (titlePos.w / 2)),
		borderTitleDst[0].y + ((borderSize.h / 2) - (titlePos.h / 3)), &color);

	for (int i = 0; i < 10; i++)
	{
		FontManager::drawFont(font, scoreText[i].c_str(), borderScoresDst[0].x + ((borderSize.w / 2) - (scoreTextPos[i].w / 2)),
			borderScoresDst[0].y + ((borderSize.h / 2) - (scoreTextPos[i].h / 3)) +(i * 65 + 19), &color);
	}

	enter->draw();

	SDL_RenderPresent(Game::renderer);
}

void Hiscores::setScores() {
	for (int i = 0; i < 10; i++)
	{
		scoreText[i] = "PLAYER " + std::to_string(i) + ": " + std::to_string(scores[i]);
		scoreTextPos[i] = FontManager::fontRect(font, scoreText[i].c_str());
	}
}

void Hiscores::createLayer(int width, int height, int yOffset, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			dst[x][y] = { x * 64, yOffset + y * 64, 64, 64 };
		}
	}
}

void Hiscores::drawLayer(int width, int height, SDL_Texture* texture, SDL_Rect src, SDL_Rect dst[9][16]) {
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			TextureManager::draw(texture, &src, &dst[x][y]);
		}
	}
}

void Hiscores::input() {
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
				Hiscores::isRunning = false;
				game->menuOptions = Game::menus::mainmenu;
				break;
			default:
				break;
			}
		}
	}
}