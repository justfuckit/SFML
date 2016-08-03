#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
#include "BinaryFile.h"
#include "BinaryFilesStructs.h"

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();
	static sf::Texture& getTexture(std::string const&);
	void load();

private:
	static sf::Texture& loadTexture(std::string const&, std::string const&);

	static AssetsManager* instance;
	std::map <std::string, sf::Texture> texture;
	std::map <std::string, std::fstream> file;
};

