#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	Bullet(int x, int y);
	~Bullet();

	void draw(RenderWindow &window);
	void load();
	bool remove;

private:
	Texture bulletTexture;
	Sprite bulletSprite;
	Vector2f position;
	Clock clock;
	Time timer; //2ms
};

