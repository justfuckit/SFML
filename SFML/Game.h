#pragma once
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "AssetsManager.h"
#include "GameWindow.h"
#include "GlobalVariables.h"
#include "Animation.h"
#include "Collisions.h"
#include "Enemy.h"

using namespace sf;

class Game : GameWindow, Collisions
{
public:
	Game();
	~Game();

	void mainLoop();
private:
	void events();
	void drawing();
	void collsisons();

	Player player;
	vector<Enemy*> enemy;
	GlobalVariables globalVariables;
	ExpandedSprite s; //bg
	Timer fpsTimer;
	int fps;
	Text fpsText;
	Font font;
};

