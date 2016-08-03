#include "TextureFragment.h"


TextureFragment::TextureFragment(string textureName, int columns, int rows) :
texture(AssetsManager::getTexture(textureName))
{
	rect.width = texture.getSize().x / columns;
	rect.height = texture.getSize().y / rows;
	sprite.setTexture(texture);
}


TextureFragment::~TextureFragment()
{
}


Sprite TextureFragment::get(int column, int row)
{
	rect.left = column * rect.width;
	rect.top = row * rect.height;
	sprite.setTextureRect(rect);
	return sprite;
}


void TextureFragment::setPosition(Vector2i pos)
{
	sprite.setPosition(Vector2f(pos));
}


Vector2i TextureFragment::getSize()
{
	return Vector2i(rect.width, rect.height);
}