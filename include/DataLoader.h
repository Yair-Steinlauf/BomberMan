
#pragma once
#include <SFML/Graphics.hpp>
#include <map>  // ����� �-vector �-map
#include <iostream>
#include <string>
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
    std::map<ObjectType, sf::Texture> m_textures;  // ����� �map
    sf::Font m_font;
};