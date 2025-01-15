#pragma once
#include "SFML/Graphics.hpp"
#include "DataLoader.h"
class GameObject {
public:
	GameObject(enum ObjectType type, const sf::Vector2f& location);
	sf::Vector2f getLocation() const;
	void setLocation(sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;
	virtual sf::Vector2f move(sf::Time deltaTime, const sf::Event& type) { return m_sprite.getPosition(); };
	virtual ~GameObject() = default;
protected:
	unsigned int m_health = 1;
	sf::Sprite m_sprite;
	virtual void decreaseHealth() =0;
	virtual void increaseHealth() = 0;
};