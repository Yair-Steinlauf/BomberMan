#pragma once
#include "Pickables.h"
class LifeGift : public Pickables {
public:
	LifeGift();
	LifeGift(const sf::Vector2f& location);
	void collide(GameObject& other) override;

private:
};