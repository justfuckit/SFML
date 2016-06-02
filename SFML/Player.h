#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bullet.h"
#include "AssetsManager.h"


using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	~Player();

	void draw(RenderWindow &window);
	void setPosition(int x, int y);
	void setPosition(Vector2f pos);
	void shoot();
	Vector2f getSize();

private:
	Vector2f position;
	Sprite sprite;
	vector <Bullet> bullets;
};

