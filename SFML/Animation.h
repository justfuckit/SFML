#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ExpandedSprite.h"
#include "Timer.h"

using namespace std;
using namespace sf;

class Animation
{
public:
	Animation(string textureName, int frames, int row, bool loop, int fps);
	~Animation();

	bool isPlay();
	Sprite getSprite();
	void start();
	void stop();
	void setPosition(Vector2i position);
	//void pause();

private:
	bool loop;
	bool play;
	int frame;
	int row;
	Timer timer;
	ExpandedSprite expandedSprite;

};

