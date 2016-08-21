#pragma once
#include "Timer.h"
#include "AssetsManager.h"
#include "ExpandedSprite.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet(int x, int y, unsigned int speed);
	~Bullet();

	void draw(RenderWindow &window);
	bool toRemove();
	vector<IntRect>* getCollisionRects();
	Vector2i getPosition();


private:
	vector<IntRect> collisionRects;
	ExpandedSprite bulletSprite;
	Vector2i position;
	int moveSpeed;
	bool remove;
};