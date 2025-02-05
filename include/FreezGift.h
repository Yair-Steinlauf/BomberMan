#pragma once
#include "Pickables.h"
class FreezGift : public Pickables
{
public:
	FreezGift();
	FreezGift(const sf::Vector2f &location, float scaler);
	void collide(GameObject &other) override;

private:
};