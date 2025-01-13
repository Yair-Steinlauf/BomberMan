#pragma once
#include "GameObject.h"
#include "Types.h"
class StaticObject : public GameObject {
public:
	StaticObject(enum ObjectType type, sf::Vector2f& location);
};