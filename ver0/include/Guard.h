#pragma once
#include "MovingObject.h"

class Guard : public MovingObject {
public:
	Guard(const sf::Vector2f& location);
	sf::Vector2f move(sf::Time deltaTime, const sf::Event& type)override;
};