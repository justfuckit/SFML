#include "Player.h"



Player::Player()
:position(0, 0)
{
	if (!playerTexture.loadFromFile("statek.png"))
		exit(-1);
	playerSprite.setTexture(playerTexture);
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

	playerSprite.setPosition(position);
	window.draw(playerSprite);
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
	return Vector2f((float)playerSprite.getTextureRect().width, (float)playerSprite.getTextureRect().height);
}


void Player::shoot()
{
	bullets.push_back(Bullet((int)position.x + int(playerSprite.getTextureRect().width / 2), (int)position.y));
	bullets[bullets.size() - 1].load();
}