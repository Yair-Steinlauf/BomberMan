#include "StaticObject.h"

void StaticObject::collide(GameObject &other)
{
	other.collideWithStatic(*this);
}

StaticObject::StaticObject()
	: StaticObject(sf::Vector2f(0, 0), 1)
{
}

StaticObject::StaticObject(const sf::Vector2f &location, float scaler)
	: GameObject(location, scaler)
{
}
