#pragma once
#include "AssetsManager.h"
#include "GlobalVariables.h"

using namespace sf;
using namespace std;

class ExpandedSprite
{
public:
	ExpandedSprite(string textureName, int columns, int rows);
	~ExpandedSprite();

	Sprite get(int column = 0, int row = 0);
	void setPosition(Vector2i pos);
	Vector2i getSize();

private:
	void updateResoultionMultiplier();
	IntRect rect;
	Vector2i position;
	Sprite sprite;
	Texture &texture;

};