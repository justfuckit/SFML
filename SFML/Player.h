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
	void moveLeft();
	void moveRight();

private:
	Vector2i position;
	vector <Bullet> bullets;

	ExpandedSprite expandedSprite;
	Vector2i getSpeedLastPosition;
	Timer getSpeedTimer;
	Timer moveTimer;
	int speed;
	int frame;
};

