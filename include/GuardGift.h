#pragma once
#include "Pickables.h"
class GuardGift : public Pickables {
public:
	GuardGift();
	GuardGift(const sf::Vector2f& location, float scaler);
	void collide(GameObject& other) override;

private:
};