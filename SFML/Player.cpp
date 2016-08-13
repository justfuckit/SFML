#include "Player.h"



Player::Player() :
moveTimer(2000),
playerFrameTimer(80000),
position(0, 900),
shipSprite("player", 9, 1)
{
	shootPressed = false;
	playerFrame = 0;
}


Player::~Player()
{
}


void Player::draw(RenderWindow &window)
{
	turnLeft = false;
	turnRight = false;

	// Input Control
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		moveLeft();
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		moveRight();
	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		shoot();
	if (!Keyboard::isKeyPressed(Keyboard::Key::Space))
		shootPressed = false;

	// Bullets
	for (int i = 0; i < (int)bullets.size(); i++)
	{
		if (bullets[i].remove)
			bullets.erase(bullets.begin() + i);
	}

	for (int i = 0; i < (int)bullets.size(); i++)
		bullets[i].draw(window);

	// Move Animations
	if (!(turnLeft || turnRight) && playerFrameTimer.elapsed())
	{
		if (playerFrame > 0)
			playerFrame--;

		if (playerFrame < 0)
			playerFrame++;
	}
	shipSprite.setPosition(position);
	window.draw(shipSprite.get(playerFrame + 4, 0));


}


void Player::shoot()
{
	if (!shootPressed)
	{
		bullets.push_back(Bullet((int)position.x + int(shipSprite.getSize().x / 2 - 4), (int)position.y + 10, 500));
		bullets.push_back(Bullet((int)position.x + int(shipSprite.getSize().x / 2 - 50), (int)position.y + 65, 480));
		bullets.push_back(Bullet((int)position.x + int(shipSprite.getSize().x / 2 + 42), (int)position.y + 65, 480));
		shootPressed = true;
	}
}


void Player::moveLeft()
{
	if (playerFrameTimer.elapsed() && playerFrame > -4)
		playerFrame--;
	turnLeft = true;
	if (moveTimer.elapsed() && position.x > 0)
		position.x--;
}


void Player::moveRight()
{
	if (playerFrameTimer.elapsed() && playerFrame < 4)
		playerFrame++;
	turnRight = true;
	if (moveTimer.elapsed() && position.x < 1919)
		position.x++;
}