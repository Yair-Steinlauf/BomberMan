#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door();
	Door(const sf::Vector2f &location, float scaler);
	void collide(GameObject &other) override;
};