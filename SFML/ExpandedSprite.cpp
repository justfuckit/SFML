#include "ExpandedSprite.h"


ExpandedSprite::ExpandedSprite(string textureName, int columns, int rows) :
texture(AssetsManager::getTexture(textureName)),
columns(columns),
rows(rows)
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
	float multiplier = static_cast<float>(GlobalVariables::getMultiplier());
	sprite.setPosition(Vector2f(unscalledPosition.x * multiplier, unscalledPosition.y * multiplier));

	rect.left = column * rect.width;
	rect.top = row * rect.height;
	sprite.setTextureRect(rect);
	sprite.setScale(multiplier, multiplier);
	return sprite;
}


void ExpandedSprite::setPosition(Vector2i pos)
{
	unscalledPosition = pos;
}


Vector2i ExpandedSprite::getSize()
{
	double multiplier = GlobalVariables::getMultiplier();
	return Vector2i(static_cast<int>(rect.width * multiplier), static_cast<int>(rect.height * multiplier));
}

int ExpandedSprite::getColumns()
{
	return columns;
}

int ExpandedSprite::getRows()
{
	return rows;
}