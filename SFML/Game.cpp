#include "Game.h"



Game::Game()
{
	window.create(VideoMode(1920, 1080), "Game Window", Style::Fullscreen);
	window.setMouseCursorVisible(false);

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
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left)
				player.shoot();
			break;

		case Event::MouseMoved:
			// ustalenie pozycji gracza
			int maxX = int(window.getSize().x - player.getSize().x);
			int maxY = int(window.getSize().y - player.getSize().y);
			int x = event.mouseMove.x;
			int y = event.mouseMove.y;

			if (x > maxX)
				x = maxX;
			if (y > maxY)
				y = maxY;
			
			player.setPosition(x, y);

			break;
		}
	}
}

void Game::drawing()
{
	player.draw(window);
}