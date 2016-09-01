#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
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
	static void* getFile(std::string const&);
	static sf::SoundBuffer& getSoundBuffer(std::string const&);
	void load();

private:
	static sf::Texture& loadTexture(std::string const&, std::string const&);
	template <class head, class body> static void* loadFile(std::string const&, std::string const&);
	static sf::SoundBuffer& loadSoundBuffer(std::string const&, std::string const&);

	static AssetsManager* instance;
	std::map <std::string, sf::Texture> texture;
	std::map <std::string, void*> file;
	std::map <std::string, sf::SoundBuffer> sound;
};

