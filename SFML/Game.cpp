#include "Game.h"



Game::Game() :
s("background", 1, 1), //bg
fpsTimer(1000000) //fps
{
	font.loadFromFile("fonts/4114blaster.ttf");
	fpsText.setFont(font);
}


Game::~Game()
{
}

void Game::mainLoop()
{
	while (window.isOpen())
	{
		window.clear();

		globalVariables.update();
		events();
		drawing();
		collsisons();
		
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
			else if (event.key.code == Keyboard::F9)
				changeCollisionRectsDrawing();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left)
				//any action
			break;

		case Event::MouseMoved:
			int x = (int)(event.mouseMove.x * resoultionMultiplier);
			int y = (int)(event.mouseMove.y * resoultionMultiplier);
			break;
		}
	}
}

void Game::drawing()
{
	
	window.draw(s.get());//bg

	player.draw(window);
	window.draw(fpsText);
	fps++;
	if (fpsTimer.elapsed())
	{
		fpsText.setString(to_string(fps));
		fps = 0;
	}
}

void Game::collsisons()
{
}