#pragma once
#include "StaticObject.h"

class Pickables : public StaticObject {
public:
	void collide(GameObject& other) override;
	void collideWithPlayer(Player& player) override;
protected:
	Pickables();
	Pickables(const sf::Vector2f& location);
};