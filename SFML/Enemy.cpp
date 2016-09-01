#include "Enemy.h"


Enemy::Enemy(Vector2i position, string type) :
sprite(type),
animationDestroy("explosion", 30, false, 45)
{
	Enemy::position.x = position.x;
	Enemy::position.y = -sprite.getSize().y;
	toY = position.y;
	hp = (type[1] - 48) * 5;
	moveDirection = 1;
	moveMax = 0;

	state = NORMAL;
	destroySound.setBuffer(AssetsManager::getSoundBuffer("enemy_destroy"));

	BinaryFile<CRHead, CRBody> *cr = (BinaryFile<CRHead, CRBody>*)AssetsManager::getFile(type);
	for (int i = 0; i < cr->getHead().size; i++)
		collisionRects.push_back(IntRect(cr->getBody(i).left, cr->getBody(i).top, cr->getBody(i).width, cr->getBody(i).height));

	font.loadFromFile("fonts/4114blaster.ttf");
	t.setFont(font);
	t.setScale(0.7, 0.7);
}


Enemy::~Enemy()
{
}


void Enemy::draw(RenderWindow &window)
{
	if (state == NORMAL)
	{
		if (hp <= 0)
		{
			state = DESTROY;
			collisionRects.clear();
			animationDestroy.setPosition(Vector2i(position.x - 100, position.y - 57));
			animationDestroy.start();
			destroySound.play();
		}
		else
		{

			if (moveMax >= 100)
				moveDirection = -2;
			else if (moveMax <= -100)
				moveDirection = 2;

			if (position.y < toY)
				position.y += 2;

			moveMax += moveDirection;
			position.x += moveDirection;

			sprite.setPosition(position);
			t.setPosition(position.x * GlobalVariables::getMultiplier() + sprite.getSize().x, position.y * GlobalVariables::getMultiplier());
			t.setString("HP: " + to_string(hp));

			window.draw(t);
			window.draw(sprite.get());
		}
	}
	else if (state == DESTROY)
	{
		if (animationDestroy.getFrame() < 10)
			window.draw(sprite.get());

		window.draw(animationDestroy.getSprite());

		if (!animationDestroy.isPlay())
			remove = true;
	}
}


Vector2i Enemy::getPosition()
{
	return position;
}


vector<IntRect>* Enemy::getCollisionRects()
{
	return &collisionRects;
}


bool Enemy::toRemove()
{
	return remove;
}


void Enemy::substractHp(int hpToSubstract)
{
	hp -= hpToSubstract;
}