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

sf::SoundBuffer& AssetsManager::loadSoundBuffer(std::string const& name, std::string const& filename)
{
	auto& soundbuffer_manager = instance->sound;
	sf::SoundBuffer& texture = soundbuffer_manager[name];
	texture.loadFromFile(filename);
	return texture;
}

sf::SoundBuffer& AssetsManager::getSoundBuffer(std::string const& name)
{
	auto& soundbuffer_manager = instance->sound;
	return soundbuffer_manager.at(name);
}

void AssetsManager::load()
{
	loadTexture("player", "graph/redship.png");
	loadTexture("bullet", "graph/fireball_small.png");
	loadTexture("bulletdestroy", "graph/fireballdestroy_small.png");
	loadTexture("background", "graph/background3.png");
	loadTexture("fire", "graph/redfire3.png");
	loadTexture("explosion", "graph/explosion_b.png");
	loadTexture("A1", "graph/Aliens/A1.png");
	loadTexture("A2", "graph/Aliens/A2.png");
	loadTexture("A3", "graph/Aliens/A3.png");
	loadTexture("A4", "graph/Aliens/A4.png");

	loadFile<bfs::ConfigHead, bfs::EmptyBody>("config", "config");
	loadFile<bfs::CRHead, bfs::CRBody>("bullet", "cr/bullet.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("player", "cr/player.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("A1", "cr/A1.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("A2", "cr/A2.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("A3", "cr/A3.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("A4", "cr/A4.cr");
	loadFile<bfs::CRHead, bfs::CRBody>("fireball_small", "cr/fireball_small.cr");

	loadSoundBuffer("fireball_small_shoot", "sounds/laser3.ogg");
	loadSoundBuffer("fireball_small_destroy", "sounds/boom6.wav");
	loadSoundBuffer("enemy_destroy", "sounds/blast.wav");
}

