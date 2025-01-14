#include "MovingObject.h"

MovingObject::MovingObject(enum ObjectType type, const sf::Vector2f& location)
	:GameObject(type, location), m_speed(DefaultSpeed)
{}


sf::Vector2f MovingObject::diffMove(sf::Time deltaTime) const
{
    float moveX = deltaTime.asSeconds() * m_speed;
    float moveY = deltaTime.asSeconds() * m_speed; 
    return sf::Vector2f(moveX, moveY);
}

void MovingObject::increaseHealth()
{
    m_health++;
}

void MovingObject::decreaseHealth()
{
    m_health--;
    if (m_health == 0)
    {
        delete this;
    }
}

void MovingObject::setSpeed(const float newSpeed)
{
	m_speed = newSpeed;
}
