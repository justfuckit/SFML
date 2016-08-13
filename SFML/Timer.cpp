#include "Timer.h"


Timer::Timer()
{
}


Timer::Timer(unsigned int us)
{
	time = microseconds(us);
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
	time = microseconds(ms);
}


void Timer::restart()
{
	clock.restart();
}