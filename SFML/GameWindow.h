#pragma once
#include <SFML\Graphics.hpp>
#include "AssetsManager.h"

using namespace sf;

class GameWindow
{
public:
	GameWindow();
	~GameWindow();
	
	void changeResoultion();
	void changeFullscreen();

	
protected:
	RenderWindow window;
	
	//config
	BinaryFile <bfs::ConfigHead, bfs::EmptyBody>* cfg;
	bfs::ConfigHead cfgHead;
	float resoultionMultiplier;
	void openWindow();
};

