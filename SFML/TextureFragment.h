#pragma once
#include "AssetsManager.h"

using namespace sf;
using namespace std;

class TextureFragment
{
public:
	TextureFragment(string textureName, int columns, int rows);
	~TextureFragment();

	Sprite get(int column = 0, int row = 0);
	void setPosition(Vector2i pos);
	Vector2i getSize();

private:
	IntRect rect;
	Vector2i position;
	Sprite sprite;
	Texture &texture;
};