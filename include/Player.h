#pragma once
#include "MovingObject.h"

class Player : public MovingObject {
public:
	Player();
	Player(const sf::Vector2f& location);
	void update(const sf::Time& deltaTime) override;
	void collide(GameObject& other) override;
private:

};