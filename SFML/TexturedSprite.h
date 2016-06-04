#pragma once
#include "AssetsManager.h"

using namespace sf;
using namespace std;

class TexturedSprite
{
public:
	TexturedSprite(string textureName, int columns, int rows);
	~TexturedSprite();

	Sprite get(int column = 0, int row = 0);
	void setPosition(Vector2f pos);
	Vector2f getSize();

private:
	IntRect rect;
	Vector2i position;
	Sprite sprite;
	Texture &texture;
};