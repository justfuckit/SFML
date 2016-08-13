#include "Bullet.h"


Bullet::Bullet(int x, int y, unsigned int speed) :
position(0, 0)
{
	speedTimer.set(1000000/speed);
	sprite.setTexture(AssetsManager::getTexture("bullet"));
	position = Vector2f((float)x, (float)y);
	remove = false;
}


Bullet::~Bullet()
{
}


void Bullet::draw(RenderWindow &window)
{
	if (speedTimer.elapsed())
	{
		position.y--;
		if (position.y <= -10) //do poprawy
			remove = true;
	}
	sprite.setPosition(position);
	window.draw(sprite);
}