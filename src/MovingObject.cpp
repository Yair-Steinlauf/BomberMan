#include "MovingObject.h"
#include "MovingObject.h"


MovingObject::MovingObject()
	:GameObject()
{
}

MovingObject::MovingObject(const sf::Vector2f& location)
	:GameObject(location)
{
}

sf::Vector2f MovingObject::diffMove(sf::Time deltaTime) const
{
	float moveX = deltaTime.asSeconds() * m_speed;
	float moveY = deltaTime.asSeconds() * m_speed;
	return sf::Vector2f(moveX, moveY);
}