#pragma once
#include "GameObject.h"

class StaticObject : public GameObject {
protected:
	StaticObject();
	StaticObject(const sf::Vector2f& location);

};