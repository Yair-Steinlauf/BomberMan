#include "MovingObject.h"
#include "MovingObject.h"


sf::Vector2f MovingObject::diffMove(sf::Time deltaTime) const
{
	float moveX = deltaTime.asSeconds() * m_speed;
	float moveY = deltaTime.asSeconds() * m_speed;
	return sf::Vector2f(moveX, moveY);
}