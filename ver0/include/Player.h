#pragma once
#include "MovingObject.h"

class Player : public MovingObject {
public:
	Player(const sf::Vector2f& location);

	sf::Vector2f move(sf::Time deltaTime, const sf::Event& type);
	
private:

};