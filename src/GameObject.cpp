#include "GameObject.h"

GameObject::GameObject()
{
	m_sprite.setScale(ImageScale, ImageScale);
}
GameObject::GameObject(const sf::Vector2f& location)
	:GameObject()
{
	m_sprite.setPosition(location);
	
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Vector2f GameObject::getLocation() const
{
	return m_sprite.getPosition();
}

GameObject::~GameObject()
{
}

void GameObject::setLocation(const sf::Vector2f& newLocation)
{
	m_sprite.setPosition(newLocation); //TODO: bound check
}
