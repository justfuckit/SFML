#pragma once
#include <SFML\Graphics.hpp>

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();
	static sf::Texture& getTexture(std::string const&);
	static sf::Texture& setTexture(std::string const&, std::string const&);
	void load();

private:
	static AssetsManager* instance;
	std::map <std::string, sf::Texture> texture;
};

