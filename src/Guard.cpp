#include "Guard.h"

Guard::Guard(const sf::Vector2f& location)
    :MovingObject(GUARD, location)
{
    m_health = 1;
}

sf::Vector2f Guard::move(sf::Time deltaTime, const sf::Event& type)
{
    //TODO: add logic
    return sf::Vector2f();
}
