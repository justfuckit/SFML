#include "Player.h"



Player::Player():
position(0, 0)
{
	frame = 4;
	Texture &texture = AssetsManager::getTexture("player");
	sprite.setTexture(texture);
	spriteRect.height = texture.getSize().y;
	spriteRect.width = texture.getSize().x / 9;
	spriteRect.top = 0;
	spriteRect.left = texture.getSize().x / 9 * frame;
	getSpeedTimer.set(100);
	
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
		spriteRect.left = spriteRect.width * frame;
		sprite.setTextureRect(spriteRect);
	}

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
	bullets.push_back(Bullet((int)position.x + int(sprite.getTextureRect().width / 2 - 4), (int)position.y + 10));
	bullets.push_back(Bullet((int)position.x + int(sprite.getTextureRect().width / 2 - 50), (int)position.y + 65));
	bullets.push_back(Bullet((int)position.x + int(sprite.getTextureRect().width / 2 + 42), (int)position.y + 65));
}