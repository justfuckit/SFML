#include "TexturedSprite.h"


TexturedSprite::TexturedSprite(string textureName, int columns, int rows) :
texture(AssetsManager::getTexture(textureName))
{
	rect.width = texture.getSize().x / columns;
	rect.height = texture.getSize().y / rows;
	sprite.setTexture(texture);
}


TexturedSprite::~TexturedSprite()
{
}


Sprite TexturedSprite::get(int column, int row)
{
	rect.left = column * rect.width;
	rect.top = row * rect.height;
	sprite.setTextureRect(rect);
	return sprite;
}


void TexturedSprite::setPosition(Vector2i pos)
{
	sprite.setPosition(Vector2f(pos));
}


Vector2i TexturedSprite::getSize()
{
	return Vector2i(rect.width, rect.height);
}