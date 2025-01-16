#include "MovingObject.h"


void MovingObject::setDirection(Direction direction)
{
	switch (direction)
	{
	case UP:
		m_direction = sf::Vector2f(0, -m_speed);
		break;
	case DOWN:
		m_direction = sf::Vector2f(0, m_speed);
		break;
	case RIGHT:
		m_direction = sf::Vector2f(m_speed, 0);;
		break;
	case LEFT:
		m_direction = sf::Vector2f(-m_speed, 0);
		break;
	case DEFAULT:
		m_direction = sf::Vector2f(0, 0);
	}
}

MovingObject::MovingObject()
	:MovingObject(sf::Vector2f(0,0))
{
}

MovingObject::MovingObject(const sf::Vector2f& location)
	:GameObject(location)
{
}
