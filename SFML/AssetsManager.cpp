#include "AssetsManager.h"
#include <assert.h>

AssetsManager* AssetsManager::instance = nullptr;

AssetsManager::AssetsManager()
{
	assert(instance == nullptr);
	instance = this;
}

AssetsManager::~AssetsManager()
{
}

sf::Texture& AssetsManager::loadTexture(std::string const& name, std::string const& filename)
{
	auto& texture_manager = instance->texture;
	sf::Texture& texture = texture_manager[name];
	texture.loadFromFile(filename);
	return texture;
}

sf::Texture& AssetsManager::getTexture(std::string const& name)
{
	auto& texture_manager = instance->texture;
	return texture_manager.at(name);
}

void AssetsManager::load()
{
	loadTexture("player", "graph/redship/125.png");
	loadTexture("bullet", "graph/bullet.png");
	loadTexture("bullet2", "graph/bullet2.png");

	//BinaryFile<CRHeader, CRBody> b("config");
}

