#include "Game.h"

int main()
{
	AssetsManager assetsManager;
	assetsManager.load();

	Game game;
	game.mainLoop();
	return 0;
}