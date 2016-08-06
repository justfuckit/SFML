#include "GameWindow.h"


GameWindow::GameWindow()
{
	cfg = ((BinaryFile<bfs::ConfigHead, bfs::EmptyBody>*)AssetsManager::getFile("config"));
	cfgHead = cfg->getHead();

	openWindow();
}

GameWindow::~GameWindow()
{
}

void GameWindow::openWindow()
{
	resoultionMultiplier = (cfgHead.fhd ? (float)1.5 : 1);

	if (cfgHead.fullscreen)
		window.create(VideoMode((int)(1280 * resoultionMultiplier), (int)(720 * resoultionMultiplier)), "Game Window", sf::Style::Fullscreen );
	else
		window.create(VideoMode((int)(1280 * resoultionMultiplier), (int)(720 * resoultionMultiplier)), "Game Window");

	window.setMouseCursorVisible(false);
}

void GameWindow::changeFullscreen()
{
	cfgHead.fullscreen = !cfgHead.fullscreen;
	cfg->setHead(cfgHead);
	cfg->save();
	window.close();
	openWindow();
}

void GameWindow::changeResoultion()
{
	cfgHead.fhd = !cfgHead.fhd;
	cfg->setHead(cfgHead);
	cfg->save();
	window.close();
	openWindow();
}