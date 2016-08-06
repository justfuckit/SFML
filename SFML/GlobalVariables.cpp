#include "GlobalVariables.h"
#include <assert.h>

GlobalVariables* GlobalVariables::instance = nullptr;

GlobalVariables::GlobalVariables()
{
	assert(instance == nullptr);
	instance = this;
	update();
}


GlobalVariables::~GlobalVariables()
{
}


double GlobalVariables::getMultiplier()
{
	return instance->multiplier;
}


void GlobalVariables::update()
{
	double &multi = instance->multiplier;
	bfs::ConfigHead	config = ((BinaryFile<bfs::ConfigHead, bfs::EmptyBody>*)AssetsManager::getFile("config"))->getHead();
	if (config.fhd)
		multi = 1;
	else
		multi = 0.666666;
}
