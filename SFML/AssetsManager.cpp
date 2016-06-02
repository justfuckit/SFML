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

sf::Texture& AssetsManager::setTexture(std::string const& filename, std::string const& name)
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