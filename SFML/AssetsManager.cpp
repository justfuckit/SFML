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

template <class head, class body> void* AssetsManager::loadFile(std::string const& name, std::string const& fileName)
{
	auto& file_manager = instance->file;
	file_manager[name] = new BinaryFile<head, body>(fileName);
	return (&instance->file)->at(name);
}

void* AssetsManager::getFile(std::string const& name)
{
	return (&instance->file)->at(name);
}

void AssetsManager::load()
{
	loadTexture("player", "graph/redship.png");
	loadTexture("bullet", "graph/bullet.png");
	loadTexture("background", "graph/background.png");

	loadFile<bfs::ConfigHead, bfs::EmptyBody>("config", "config");	
}

