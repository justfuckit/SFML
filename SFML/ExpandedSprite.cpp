#include "ExpandedSprite.h"


ExpandedSprite::ExpandedSprite(string textureName, int columns, int rows) :
texture(AssetsManager::getTexture(textureName))
{
	rect.width = texture.getSize().x / columns;
	rect.height = texture.getSize().y / rows;
	sprite.setTexture(texture);
}


ExpandedSprite::~ExpandedSprite()
{
}


Sprite ExpandedSprite::get(int column, int row)
{
	rect.left = column * rect.width;
	rect.top = row * rect.height;
	sprite.setTextureRect(rect);
	float multiplier = static_cast<float>(GlobalVariables::getMultiplier());
	sprite.setScale(multiplier, multiplier);
	return sprite;
}


void ExpandedSprite::setPosition(Vector2i pos)
{
	double multiplier = GlobalVariables::getMultiplier();
	sprite.setPosition(Vector2f(pos.x * multiplier, pos.y * multiplier));
}


Vector2i ExpandedSprite::getSize()
{
	double multiplier = GlobalVariables::getMultiplier();
	return Vector2i(static_cast<int>(rect.width * multiplier), static_cast<int>(rect.height * multiplier));
}