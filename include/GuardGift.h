#pragma once
#include "Pickables.h"
class GuardGift : public Pickables {
public:
	GuardGift();
	GuardGift(const sf::Vector2f& location);
	void collide(GameObject& other) override;

private:
};