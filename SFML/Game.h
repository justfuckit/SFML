#pragma once
#include "Player.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void mainLoop();
private:
	void events();
	void drawing();

	RenderWindow window;
	Player player;
};

