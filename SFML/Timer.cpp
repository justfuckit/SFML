#include "Timer.h"


Timer::Timer()
{
}


Timer::Timer(unsigned int ms)
{
	time = milliseconds(ms);
	clock.restart();
}


Timer::~Timer()
{
}


bool Timer::elapsed()
{
	if (clock.getElapsedTime() >= time)
	{
		clock.restart();
		return true;
	}
	return false;
}


void Timer::set(unsigned int ms)
{
	time = milliseconds(ms);
}