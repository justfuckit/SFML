#pragma once
#include "Timer.h"
#include "AssetsManager.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet(int x, int y, unsigned int speed = 500); // uwa¿aæ na wartoœæ domnieman¹ w trybie debug
	~Bullet();

	void draw(RenderWindow &window);
	bool remove;


private:
	Sprite sprite;
	Vector2f position;
	Timer speedTimer;
};