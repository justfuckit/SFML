#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Timer
{
public:
	Timer();
	Timer(unsigned int us);
	~Timer();

	void set(unsigned int us);
	bool elapsed();

private:
	Clock clock;
	Time time;
};

