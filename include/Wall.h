#pragma once
#include "StaticObject.h"

class Wall: public StaticObject {
public:
	Wall();
	/*void collide(GameObject& other) override;
	void collideWithWa(Guard& guard) override {};*/
	Wall(const sf::Vector2f& location, float scaler);
};