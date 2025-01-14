#pragma once
#include "GameObject.h"
#include "Types.h"
class StaticObject : public GameObject {
public:
	
	sf::Vector2f move(sf::Time deltaTime, const sf::Event& type) override;
};