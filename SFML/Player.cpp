#include "Player.h"



Player::Player() :

//playerFrameTimer(80000),
position(0, 900),
shipSprite("player", 9, 1)
{
	shootPressed = false;
	shipFrame = 0;
	shipAnimationCounter = 0;
	shipAnimationSpeed = 5;
	font.loadFromFile("fonts/4114blaster.ttf");
	text.setFont(font);
	text.setPosition(0, 20);
}


Player::~Player()
{
}


void Player::draw(RenderWindow &window)
{
	// Loop Variabless SetUp
	shipAnimationCounter++;
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
		if (bullets[i]->remove)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}

	for (int i = 0; i < (int)bullets.size(); i++)
		bullets[i] -> draw(window);

	// Move Animations
	if (!(turnLeft || turnRight) && shipAnimationCounter >= shipAnimationSpeed )
	{
		shipAnimationCounter = 0;

		if (shipFrame > 0)
			shipFrame--;

		if (shipFrame < 0)
			shipFrame++;
	}
	shipSprite.setPosition(position);
	window.draw(shipSprite.get(shipFrame + 4, 0));

	text.setString(to_string(bullets.size()));
	window.draw(text);

}


void Player::shoot()
{
	if (!shootPressed)
	{
		bullets.push_back(new Bullet(position.x + 56, position.y + 30, 3));
		bullets.push_back(new Bullet(position.x + 19, position.y + 75, 3));
		bullets.push_back(new Bullet(position.x + 93, position.y + 75, 3));
		shootPressed = true;
	}
}


void Player::moveLeft()
{
	if (shipAnimationCounter >= shipAnimationSpeed && shipFrame > -4)
	{
		shipAnimationCounter = 0;
		shipFrame--;
	}
	turnLeft = true;
	if (position.x > 0)
		position.x -= 8;
}


void Player::moveRight()
{
	if (shipAnimationCounter >= shipAnimationSpeed && shipFrame < 4)
	{
		shipAnimationCounter = 0;
		shipFrame++;
	}
	turnRight = true;
	if (position.x < 1919)
		position.x += 8;
}