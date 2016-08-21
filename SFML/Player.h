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
	vector <Bullet*>* getBullets();
	vector<IntRect>* getCollisionRects();
	Vector2i getPosition();
	void setPosition(int x, int y);


private:
	void shoot();
	void moveLeft();
	void moveRight();

	Vector2i position;
	vector <Bullet*> bullets;
	vector<IntRect> collisionRects;
	ExpandedSprite shipSprite;
	Animation fire;

	bool turnLeft;
	bool turnRight;
	bool shootPressed;
	int shipFrame; // LEFT -4 ... 4 RIGHT
	int shipAnimationCounter;
	int shipAnimationSpeed;
};

