#include "StaticObject.h"

sf::Vector2f StaticObject::move(sf::Time deltaTime, const sf::Event& type)
{
    return this->getLocation();
}
