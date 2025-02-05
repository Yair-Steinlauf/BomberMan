#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall();
	Wall(const sf::Vector2f &location, float scaler);
};