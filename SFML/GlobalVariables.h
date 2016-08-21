#pragma once
#include "AssetsManager.h"

class GlobalVariables
{
public:
	GlobalVariables();
	~GlobalVariables();

	static void update();
	static double getMultiplier();
	
private:
	static GlobalVariables* instance;
	
	double multiplier;
};