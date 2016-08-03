#include "Player.h"



Player::Player():
position(0, 0),
getSpeedTimer(100000),
textureFragment("player", 9, 1)
{
	frame = 4;
}


Player::~Player()
{
}


void Player::draw(RenderWindow &window)
{
	if (getSpeedTimer.elapsed())
	{
		speed = int(getSpeedLastPosition.x - position.x) * -10;
		getSpeedLastPosition = position;
		frame = (speed / 100) + 4;
		if (frame > 8)
			frame = 8;
		if (frame < 0)
			frame = 0;
	}

	for (int i = 0; i < (int)bullets.size(); i++)
	{
		if (bullets[i].remove)
			bullets.erase(bullets.begin() + i);
	}

	for (int i = 0; i < (int)bullets.size(); i++)
		bullets[i].draw(window);

	textureFragment.setPosition(position);
	window.draw(textureFragment.get(frame, 0));
}


void Player::setPosition(int x, int y)
{
	setPosition(Vector2i(x, y));
}


void Player::setPosition(Vector2i pos)
{
	position = pos;
}


Vector2i Player::getSize()
{
	return textureFragment.getSize();
}


void Player::shoot()
{
	bullets.push_back(Bullet((int)position.x + int(textureFragment.getSize().x / 2 - 4), (int)position.y + 10, 500));
	bullets.push_back(Bullet((int)position.x + int(textureFragment.getSize().x / 2 - 50), (int)position.y + 65, 480));
	bullets.push_back(Bullet((int)position.x + int(textureFragment.getSize().x / 2 + 42), (int)position.y + 65, 480));
}