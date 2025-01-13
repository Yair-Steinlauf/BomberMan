#include "GameObject.h"


GameObject::GameObject(enum ObjectType type, sf::Vector2f& location)
{
	m_sprite.setPosition(location);
	m_sprite.setTexture(DataLoader::getP2Texture(type));
}

sf::Vector2f GameObject::getLocation() const
{
	return m_sprite.getPosition();
}

void GameObject::setLocation(sf::Vector2f& location)
{
	m_sprite.setPosition(location);//TODO: bounds check
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
