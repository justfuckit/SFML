#pragma once
#include "Timer.h"
#include "AssetsManager.h"
#include "ExpandedSprite.h"
#include "Animation.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet(int x, int y, unsigned int speed);
	~Bullet();

	void draw(RenderWindow &window);
	void destroy();
	bool toRemove( bool trueToRemoveFalseToCheck = false);
	vector<IntRect>* getCollisionRects();
	Vector2i getPosition();


private:
	vector<IntRect> collisionRects;
	Animation animationBullet;
	Animation animationDestroy;
	Vector2i position;
	Sound shootSound;
	Sound destroySound;
	int moveSpeed;
	bool remove;
	enum State { NORMAL, DESTROY };
	State state;
};