#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Types.h"
class DataLoader {
public:
	static DataLoader& Init();
	DataLoader(const DataLoader&) = delete;
	void operator=(const DataLoader&) = delete;
	static sf::Texture& getP2Texture(const enum ObjectType type);
	static sf::Font& getP2Font();
private:
	DataLoader();
	std::vector<std::pair<enum ObjectType, sf::Texture>> m_textures;
};
	static sf::Font m_font;