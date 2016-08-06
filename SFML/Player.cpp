#include "Player.h"



Player::Player():
position(0, 900),
getSpeedTimer(100000),
expandedSprite("player", 9, 1)
{
	frame = 4;
	moveTimer.set(1000);
}


Player::~Player()
{
}


void Player::draw(RenderWindow &window)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		moveLeft();

	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		moveRight();

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

	expandedSprite.setPosition(position);
	window.draw(expandedSprite.get(frame, 0));
}


void Player::shoot()
{
	bullets.push_back(Bullet((int)position.x + int(expandedSprite.getSize().x / 2 - 4), (int)position.y + 10, 500));
	bullets.push_back(Bullet((int)position.x + int(expandedSprite.getSize().x / 2 - 50), (int)position.y + 65, 480));
	bullets.push_back(Bullet((int)position.x + int(expandedSprite.getSize().x / 2 + 42), (int)position.y + 65, 480));
}


void Player::moveLeft()
{
	if (moveTimer.elapsed() && position.x > 0)
		position.x--;
}


void Player::moveRight()
{
	if (moveTimer.elapsed() && position.x < 1919)
		position.x++;
}