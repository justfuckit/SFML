#include "Bullet.h"


Bullet::Bullet(int x, int y, unsigned int speed) :
bulletSprite("bullet")
{
	Bullet::position = Vector2i(x - (bulletSprite.getUnscalledSize().x / 2), y - (bulletSprite.getUnscalledSize().y / 2));
	moveSpeed = speed; 
	remove = false;

	BinaryFile<CRHead, CRBody> *cr = (BinaryFile<CRHead, CRBody>*)AssetsManager::getFile("bullet");
	for (int i = 0; i < cr->getHead().size; i++)
		collisionRects.push_back(IntRect(cr->getBody(i).left, cr->getBody(i).top, cr->getBody(i).width, cr->getBody(i).height));

}


Bullet::~Bullet()
{
}



void Bullet::draw(RenderWindow &window)
{
	position.y -= moveSpeed;
	if (position.y <= -bulletSprite.getSize().y)
		remove = true;

	bulletSprite.setPosition(position);
	window.draw(bulletSprite.get());
}


bool Bullet::toRemove(bool trueToRemoveFalseToCheck)
{ 
	if (trueToRemoveFalseToCheck)
		remove = true;
	return remove;
}


vector<IntRect>* Bullet::getCollisionRects()
{
	return &collisionRects;
}


Vector2i Bullet::getPosition()
{
	return position;
}