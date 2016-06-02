#include "Bullet.h"


Bullet::Bullet(int x, int y)
:position(0, 0)
{
	sprite.setTexture(AssetsManager::getTexture("bullet"));
	clock.restart();
	timer = milliseconds(2);
	position = Vector2f((float)x, (float)y);
	remove = false;
}


Bullet::~Bullet()
{
}


void Bullet::draw(RenderWindow &window)
{
	if (clock.getElapsedTime() >= timer)
	{
		position.y--;
		clock.restart();
		if (position.y <= 0)
			remove = true;
	}
	sprite.setPosition(position);
	window.draw(sprite);
}