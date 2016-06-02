#pragma once
#include "AssetsManager.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet(int x, int y);
	~Bullet();

	void draw(RenderWindow &window);
	bool remove;

private:
	Sprite sprite;
	Vector2f position;
	Clock clock;
	Time timer; //2ms
};

