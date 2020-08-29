#include "macros.h"
#include "game.h"
#include "test.h"

int main(int argc, char* args[])
{
	Game game = Game();
	if (!game.init()) {
		Print("Failed to init SDL subsystems!");
		return 1;
	}
	game.gameplay();

	return 0;
}


