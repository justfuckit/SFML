#include "Player.h"



Player::Player()
:position(0, 0)
{
	
	sprite.setTexture(AssetsManager::getTexture("player"));
}


Player::~Player()
{
}


void Player::draw(RenderWindow &window)
{
	for (int i = 0; i < (int)bullets.size(); i++)
	{
		if (bullets[i].remove)
			bullets.erase(bullets.begin() + i);
	}

	for (int i = 0; i < (int)bullets.size(); i++)
		bullets[i].draw(window);

	sprite.setPosition(position);
	window.draw(sprite);
}


void Player::setPosition(int x, int y)
{
	setPosition(Vector2f((float)x, (float)y));
}


void Player::setPosition(Vector2f pos)
{
	position = pos;
}


Vector2f Player::getSize()
{
	return Vector2f((float)sprite.getTextureRect().width, (float)sprite.getTextureRect().height);
}


void Player::shoot()
{
	bullets.push_back(Bullet((int)position.x + int(sprite.getTextureRect().width / 2), (int)position.y));
}