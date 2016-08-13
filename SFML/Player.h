#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"
#include "ExpandedSprite.h"
#include "Animation.h"


using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	~Player();

	void draw(RenderWindow &window);


private:
	void shoot();
	void moveLeft();
	void moveRight();

	Vector2i position;
	vector <Bullet> bullets;
	ExpandedSprite shipSprite;

	bool turnLeft;
	bool turnRight;
	bool shootPressed;
	int playerFrame; // LEFT -4 ... 4 RIGHT
	Timer moveTimer;
	Timer playerFrameTimer;
};

