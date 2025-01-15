#pragma once
#include "MovingObject.h"

class Guard :public MovingObject {
public:
	Guard();
	Guard(const sf::Vector2f& location);
	void move()override;
private:
	sf::Vector2f smartMove();
	sf::Vector2f randMove();
};