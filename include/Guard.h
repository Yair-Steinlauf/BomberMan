#pragma once
#include "MovingObject.h"

class Guard :public MovingObject {
public:
	Guard();
	Guard(const sf::Vector2f& location);
	void update(const sf::Time& deltaTime) override;
	//void move()override;//TODO: add deeltaTime
private:
	sf::Vector2f smartMove();
	sf::Vector2f randMove();
};