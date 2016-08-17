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

ExpandedSprite & ExpandedSprite::operator=(const ExpandedSprite & expandedSprite)
{
	if (&expandedSprite == this)
		return *this;
	
	columns = expandedSprite.columns;
	rows = expandedSprite.rows;
	rect = expandedSprite.rect;
	unscalledPosition = expandedSprite.unscalledPosition;
	sprite = expandedSprite.sprite;
	texture = expandedSprite.texture;
	return *this;
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

Vector2i ExpandedSprite::getUnscalledSize()
{
	return Vector2i(rect.width, rect.height);
}

int ExpandedSprite::getColumns()
{
	return columns;
}

int ExpandedSprite::getRows()
{
	return rows;
}