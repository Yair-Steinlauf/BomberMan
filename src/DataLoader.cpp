#include "DataLoader.h"

DataLoader& DataLoader::getInstance()
{
	static DataLoader instance;
	return instance;
}

sf::Texture& DataLoader::getP2Texture(const enum ObjectType type)
{
	auto& instance = getInstance();
	for (auto& current : instance.m_textures)
	{
		if (type == current.first)
			return current.second;
	}
}


DataLoader::DataLoader()
{
	const std::vector<std::pair<enum ObjectType, std::string>> objectNames =
	{ { PLAYER, "Player" },
	{ GUARD, "Guard" },
	{ DOOR, "Door" },
	{ WALL, "Wall" },
	{ STONE, "Stone" } };
	for (const auto& object : objectNames)
	{
		std::pair<enum ObjectType, sf::Texture> texture;
		texture.first = object.first ;
		texture.second.loadFromFile(object.second + ".png");
		m_textures.push_back(texture);
	}
}
