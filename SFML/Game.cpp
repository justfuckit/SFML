#include "Game.h"



Game::Game() :
s("background", 1, 1), //bg
fpsTimer(1000000) //fps
{
	srand(time(NULL));
	font.loadFromFile("fonts/4114blaster.ttf");
	fpsText.setFont(font);

	for (int i = 0; i < 8; i++)
		enemy.push_back(new Enemy(Vector2i((std::rand() % 1720) + 100, (std::rand() % 830) + 0), "A" + to_string((std::rand() % 4) + 1)));

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


	for (int i = 0; i < (int)enemy.size(); i++)
	{
		if (enemy[i]->toRemove())
		{
			delete enemy[i];
			enemy.erase(enemy.begin() + i);
			enemy.push_back(new Enemy(Vector2i((std::rand() % 1720) + 100, (std::rand() % 830) + 0), "A" + to_string((std::rand() % 4) + 1)));
		}
	}

	for (int i = 0; i < (signed)enemy.size(); i++)
		enemy[i]->draw(window);

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
	vector<Bullet*>* bullets = player.getBullets();
	for (int i = 0; i < (signed)enemy.size(); i++)
	{
		for (int j = 0; j < (signed)bullets->size(); j++)
		{
			if (checkCollision(enemy[i]->getPosition(), enemy[i]->getCollisionRects(),
				bullets->at(j)->getPosition(), bullets->at(j)->getCollisionRects(), window))
			{
				enemy[i]->substractHp(1);
				bullets->at(j)->destroy();
			}
		}
	}
}