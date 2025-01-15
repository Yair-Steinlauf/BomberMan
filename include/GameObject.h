#pragma once
#include "SFML/Graphics.hpp"
#include "Types.h"
#include "DataLoader.h"

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation()const;

	virtual ~GameObject();
protected:
	GameObject();
	GameObject(const sf::Vector2f& location);
	void setLocation(const sf::Vector2f& newLocation);
	sf::Sprite m_sprite;

};