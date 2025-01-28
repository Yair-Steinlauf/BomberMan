#include "DataLoader.h"

DataLoader& DataLoader::Init()
{
	static DataLoader instance;
	return instance;
}

sf::Texture& DataLoader::getP2Texture(const enum ObjectType type)
{
	auto& instance = Init();
	for (auto& current : instance.m_textures)
	{
		if (type == current.first)
			return current.second;
	}
}

sf::Font& DataLoader::getP2Font()
{
	auto& instance = Init();

	return instance.m_font;
}


DataLoader::DataLoader()
{
	/*m_font.loadFromFile("font.ttf");
	*/
	// Load font from file, assuming font.ttf is in the project directory
	if (!m_font.loadFromFile("font.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
		// Handle error loading font, possibly throw exception or set default font
	}
	const std::vector<std::pair<enum ObjectType, std::string>> objectNames =
	{	{ PLAYER, "PLAYER" } ,
		{ GUARD, "GUARD" },
		{ DOOR, "DOOR" },
		{ WALL, "WALL" },
		{ STONE, "STONE" },
		{GIFT , "GIFT"},
		{KEY, "KEY"}};
	for (const auto& object : objectNames)
	{
		std::pair<enum ObjectType, sf::Texture> texture;
		texture.first = object.first;
		texture.second.loadFromFile(object.second + ".png");
		m_textures.push_back(texture);
	}
}
