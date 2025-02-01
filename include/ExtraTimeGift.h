#pragma once
#include "Pickables.h"
class ExtraTimeGift : public Pickables {
public:
	ExtraTimeGift();
	ExtraTimeGift(const sf::Vector2f& location);
	void collide(GameObject& other) override;

private:
};