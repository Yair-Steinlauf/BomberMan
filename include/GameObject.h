#pragma once
#include "SFML/Graphics.hpp"
#include "DataLoader.h"
class GameObject {
public:
	GameObject(enum ObjectType type, sf::Vector2f& location);
	sf::Vector2f getLocation() const;
	void setLocation(sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;
protected:
	sf::Sprite m_sprite;
};