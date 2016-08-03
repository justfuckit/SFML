#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"
#include "TextureFragment.h"


using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	~Player();

	void draw(RenderWindow &window);
	void setPosition(int x, int y);
	void setPosition(Vector2i pos);
	void shoot();
	Vector2i getSize();

private:
	Vector2i position;
	vector <Bullet> bullets;

	TextureFragment textureFragment;
	Vector2i getSpeedLastPosition;
	Timer getSpeedTimer;
	int speed;
	int frame;
};

