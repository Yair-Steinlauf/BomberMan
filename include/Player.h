#pragma once
#include "MovingObject.h"

class Player : public MovingObject {
public:
	Player();
	Player(const sf::Vector2f& location);
	void move(const sf::Time& deltaTime, const sf::Event& type);
	void move() {};
private:

};