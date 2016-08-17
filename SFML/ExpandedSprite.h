#pragma once
#include "AssetsManager.h"
#include "GlobalVariables.h"

using namespace sf;
using namespace std;

class ExpandedSprite
{
public:
	ExpandedSprite(string textureName, int columns = 1, int rows = 1);
	~ExpandedSprite();
	ExpandedSprite & operator=(const ExpandedSprite & expandedSprite);

	Sprite get(int column = 0, int row = 0);
	void setPosition(Vector2i pos);
	Vector2i getSize();
	Vector2i getUnscalledSize();
	int getColumns();
	int getRows();

private:
	int columns, rows;
	IntRect rect;
	Vector2i unscalledPosition;
	Sprite sprite;
	Texture &texture;

};