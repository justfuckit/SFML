#include "Animation.h"


Animation::Animation(string textureName, int frames , bool loop, int fps) :
loop(loop),
timer(static_cast<unsigned int>(1000000/fps)),
expandedSprite(textureName, frames)
{
	frame = 0;
	play = loop;
}


Animation::~Animation()
{
}


bool Animation::isPlay()
{
	return play;
}

Sprite Animation::getSprite()
{
	Sprite nullSprite;
	if (play)
	{
		if (timer.elapsed())
			frame++;

		if (frame >= expandedSprite.getColumns())
		{
			frame = 0;
			if (!loop)
			{
				play = false;
				return nullSprite;
			}
		}

		return(expandedSprite.get(frame));
	}
	else
		return nullSprite;
}

void Animation::start()
{
	play = true;
	timer.restart();
}

void Animation::stop()
{
	play = false;
	frame = 0;
}

void Animation::setPosition(Vector2i position)
{
	expandedSprite.setPosition(position);
}

int Animation::getFrame()
{
	return frame;
}