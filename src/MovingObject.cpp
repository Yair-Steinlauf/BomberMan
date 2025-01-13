#include "MovingObject.h"

sf::Vector2f MovingObject::move(float deltaTime, sf::Event type)
{
	sf::Vector2f diff(0.0f, 0.0f);
	sf::Vector2f newLocation = m_sprite.getPosition();
	switch (type.key.code)
	{
	case sf::Keyboard::Up:
		newLocation.y += deltaTime * m_speed.y;
		break;
	case sf::Keyboard::Down:
		newLocation.y -= deltaTime * m_speed.y;
		break;
	case sf::Keyboard::Left:
		newLocation.x -= deltaTime * m_speed.x;
		break;
	case sf::Keyboard::Right:
		newLocation.x += deltaTime * m_speed.x;
		break;
	}
	this->setLocation(newLocation);
	return newLocation;
}

void MovingObject::setSpeed(const sf::Vector2f newSpeed)
{
	m_speed = newSpeed;
}
