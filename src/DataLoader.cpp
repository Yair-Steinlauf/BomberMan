// DataLoader.cpp
#include "DataLoader.h"

DataLoader& DataLoader::Init()
{
    static DataLoader instance;
    return instance;
}

sf::Texture& DataLoader::getP2Texture(const enum ObjectType type)
{
    auto& instance = Init();
    auto it = instance.m_textures.find(type);
    if (it != instance.m_textures.end())
        return it->second;
    throw std::runtime_error("Texture not found for type: " + std::to_string(static_cast<int>(type)));
}

sf::Font& DataLoader::getP2Font()
{
    auto& instance = Init();
    return instance.m_font;
}

DataLoader::DataLoader()
{
    if (!m_font.loadFromFile("font.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    const std::map<ObjectType, std::string> objectNames = {
        { PLAYER, "PLAYER" },
        { GUARD, "GUARD" },
        { DOOR, "DOOR" },
        { WALL, "WALL" },
        { STONE, "STONE" },
        { GIFT, "GIFT" },
        { KEY, "KEY"},
        {BOMB, "BOMB"},
        {EXPLODE, "EXPLODE"}
    };

    for (const auto& [type, name] : objectNames) {
        sf::Texture texture;
        if (texture.loadFromFile(name + ".png")) {
            m_textures[type] = std::move(texture);
        }
        else {
            std::cerr << "Failed to load texture: " << name << ".png" << std::endl;
        }
    }
}