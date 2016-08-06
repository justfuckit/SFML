#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"
#include "ExpandedSprite.h"


using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	~Player();

	void draw(RenderWindow &window);
	void shoot();
	void setPosition(int x, int y);

private:
	Vector2i position;
	vector <Bullet> bullets;

	ExpandedSprite expandedSprite;
	Vector2i getSpeedLastPosition;
	Timer getSpeedTimer;
	int speed;
	int frame;
};

