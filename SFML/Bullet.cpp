#include "Bullet.h"


Bullet::Bullet(int x, int y, unsigned int speed) :
animationBullet("bullet", 34, true, 30),
animationDestroy("bulletdestroy", 11, false, 30)
{
	Bullet::position = Vector2i(x - (animationBullet.getSprite().getTextureRect().width / 2), y - (animationBullet.getSprite().getTextureRect().height / 2));
	moveSpeed = speed; 
	remove = false;
	state = NORMAL;

	BinaryFile<CRHead, CRBody> *cr = (BinaryFile<CRHead, CRBody>*)AssetsManager::getFile("fireball_small");
	for (int i = 0; i < cr->getHead().size; i++)
		collisionRects.push_back(IntRect(cr->getBody(i).left, cr->getBody(i).top, cr->getBody(i).width, cr->getBody(i).height));


	shootSound.setBuffer(AssetsManager::getSoundBuffer("fireball_small_shoot"));
	destroySound.setBuffer(AssetsManager::getSoundBuffer("fireball_small_destroy"));

	shootSound.play();
}


Bullet::~Bullet()
{
}



void Bullet::draw(RenderWindow &window)
{
	if (state == NORMAL)
	{
		position.y -= moveSpeed;
		if (position.y <= -animationBullet.getSprite().getTextureRect().height * GlobalVariables::getMultiplier())
			remove = true;

		animationBullet.setPosition(position);
		window.draw(animationBullet.getSprite());
	}
	else if (state == DESTROY)
	{
		window.draw(animationDestroy.getSprite());
		if (!animationDestroy.isPlay())
			remove = true;
	}
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


void Bullet::destroy()
{
	state = DESTROY;
	animationDestroy.setPosition(Vector2i(position.x - 16, position.y - 56));
	animationDestroy.start();
	collisionRects.clear();
	destroySound.play();
}