#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "ExpandedSprite.h"
#include "Animation.h"

using namespace sf;
using namespace std;

class Enemy
{
public:
	Enemy(Vector2i position, string type);
	~Enemy();

	vector<IntRect>* getCollisionRects();
	void draw(RenderWindow &window);
	Vector2i getPosition();
	bool toRemove();
	void substractHp(int hpToSubstract);
	
private:
	vector<IntRect> collisionRects;
	Vector2i position;
	ExpandedSprite sprite;
	Animation animationDestroy;
	Sound destroySound;
	enum State { NORMAL, DESTROY};
	State state;

	int toY;
	int moveDirection;
	int moveMax;
	bool remove;
	int hp;

	Font font;
	Text t;
};

