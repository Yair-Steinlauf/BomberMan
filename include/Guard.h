#pragma once
#include "MovingObject.h"

class Guard :public MovingObject {
public:
	Guard();
	Guard(const sf::Vector2f& location);
	void update(const sf::Time& deltaTime) override;
	void collide(GameObject& other) override;
	void act(const sf::Time& deltaTime);
	void collideWithGuard(Guard& guard) override {};
private:
	sf::Vector2f smartMove();
	Direction randMove();
};