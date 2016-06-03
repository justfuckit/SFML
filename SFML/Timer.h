#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Timer
{
public:
	Timer();
	Timer(unsigned int ms);
	~Timer();

	void set(unsigned int ms);
	bool elapsed();

private:
	Clock clock;
	Time time;
};

