#include "Enemy.h"


Enemy::Enemy(Vector2i position, string type ):
sprite(type)
{
	Enemy::position.x = position.x;
	Enemy::position.y = -sprite.getSize().y;
	toY = position.y;

	hp = (type[1] - 48) * 5;
	moveDirection = 1;
	moveMax = 0;
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
	if (moveMax >= 100)
		moveDirection = -2;
	else if (moveMax <= -100)
		moveDirection = 2;

	if (position.y < toY)
		position.y += 2;

	if (hp <= 0)
		remove = true;

	moveMax += moveDirection;
	position.x += moveDirection;

	sprite.setPosition(position);
	t.setPosition(position.x * GlobalVariables::getMultiplier() + sprite.getSize().x, position.y * GlobalVariables::getMultiplier());
	t.setString("HP: " + to_string(hp));
	
	window.draw(t);
	window.draw(sprite.get());
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