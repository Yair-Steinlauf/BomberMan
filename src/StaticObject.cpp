#include "StaticObject.h"

void StaticObject::collide(GameObject& other)
{
	other.collideWithStatic(*this);
}

StaticObject::StaticObject()
	:StaticObject(sf::Vector2f(0, 0))
{
}

StaticObject::StaticObject(const sf::Vector2f& location)
	:GameObject(location)
{
}
