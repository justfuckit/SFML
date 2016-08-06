#pragma once
#include "Player.h"
#include "AssetsManager.h"
#include "GameWindow.h"
#include "GlobalVariables.h"

using namespace sf;

class Game : GameWindow
{
public:
	Game();
	~Game();

	void mainLoop();
private:
	void events();
	void drawing();

	Player player;
	ExpandedSprite s;
	GlobalVariables globalVariables;
};

