#include "StaticObject.h"

StaticObject::StaticObject()
	:GameObject()
{
}

StaticObject::StaticObject(const sf::Vector2f& location)
	:GameObject(location)
{
}
