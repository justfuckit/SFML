#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::mainLoop()
{
	while (window.isOpen())
	{
		events();

		window.clear();
		drawing();
		window.display();
	}
}



void Game::events()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;

		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
				window.close();
			else if (event.key.code == Keyboard::F11)
				changeFullscreen();
			else if (event.key.code == Keyboard::F10)
				changeResoultion();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left)
				player.shoot();
			break;

		case Event::MouseMoved:
			int x = (int)(event.mouseMove.x * resoultionMultiplier);
			int y = (int)(event.mouseMove.y * resoultionMultiplier);
			player.setPosition(x, y);
			break;
		}
	}
}

void Game::drawing()
{
	
	//s.setTexture(AssetsManager::getTexture("background"));
	//window.draw(s);
	

	player.draw(window);
}