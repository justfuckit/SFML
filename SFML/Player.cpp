#include "Player.h"



Player::Player() :
position(0, 930),
shipSprite("player", 9, 1),
fire("fire", 4, true, 10)
{
	shootPressed = false;
	shipFrame = 0;
	shipAnimationCounter = 0;
	shipAnimationSpeed = 5;

	fire.start();

	BinaryFile<CRHead, CRBody> *cr = (BinaryFile<CRHead, CRBody>*)AssetsManager::getFile("player");
	for (int i = 0; i < cr->getHead().size; i++)
		collisionRects.push_back(IntRect(cr->getBody(i).left, cr->getBody(i).top, cr->getBody(i).width, cr->getBody(i).height));
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
		if (bullets[i]->toRemove())
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

	fire.setPosition(Vector2i(position.x + 31 + shipFrame , position.y + shipSprite.getUnscalledSize().y - 10));
	window.draw(fire.getSprite());
}


void Player::shoot()
{
	if (!shootPressed)
	{
		bullets.push_back(new Bullet(position.x + 56, position.y + 30, 10));
		bullets.push_back(new Bullet(position.x + 19, position.y + 75, 10));
		bullets.push_back(new Bullet(position.x + 93, position.y + 75, 10));
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
	if (position.x < 1919 - shipSprite.getUnscalledSize().x)
		position.x += 8;
}


vector <Bullet*>* Player::getBullets()
{
	return &bullets;
}


vector<IntRect>* Player::getCollisionRects()
{
	return &collisionRects;
}


Vector2i Player::getPosition()
{
	return position;
}