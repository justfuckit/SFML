#include "Bullet.h"


Bullet::Bullet(int x, int y, unsigned int speed) :
bulletSprite("bullet")
{
	Bullet::position = Vector2i(x - (bulletSprite.getUnscalledSize().x / 2), y - (bulletSprite.getUnscalledSize().y / 2));
	moveSpeed = speed; 
	remove = false;
}


Bullet::~Bullet()
{
}



void Bullet::draw(RenderWindow &window)
{
	position.y -= moveSpeed;
	if (position.y <= -bulletSprite.getSize().y)
		remove = true;

	bulletSprite.setPosition(position);
	window.draw(bulletSprite.get());
}