#include "GameObject.h"

GameObject::GameObject()
{
}
GameObject::GameObject(const sf::Vector2f &location, float scaler)
	: GameObject()
{
	m_sprite.setPosition(location);
	m_sprite.setScale(scaler, scaler);
}

void GameObject::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

sf::Vector2f GameObject::getLocation() const
{
	return m_sprite.getPosition();
}

bool GameObject::intersect(GameObject &other)
{
	sf::FloatRect bounds1 = m_sprite.getGlobalBounds();
	sf::FloatRect bounds2 = other.m_sprite.getGlobalBounds();
	return bounds1.intersects(bounds2);
}

GameObject::~GameObject()
{
}

void GameObject::setLocation(const sf::Vector2f &newLocation)
{
	sf::FloatRect screenBounds(0, 0, WINDOW_WIDTH, WINDOW_HIGTH);

	auto newSprite = m_sprite;
	newSprite.setPosition(newLocation);

	sf::FloatRect newBounds = newSprite.getGlobalBounds();
	if (screenBounds.contains(newBounds.left, newBounds.top) &&
		screenBounds.contains(newBounds.left + newBounds.width, newBounds.top + newBounds.height))
	{
		m_sprite.setPosition(newLocation);
	}
}
sf::Vector2f GameObject::getTopLeft() const
{
	return m_sprite.getPosition();
}

sf::Vector2f GameObject::getSize() const
{
	return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
}

bool GameObject::isActive() const
{
	return m_isActive;
}

void GameObject::setNoActive()
{
	m_isActive = false;
}

sf::Vector2f GameObject::getBottomRight() const
{
	auto bottomRight = getTopLeft();
	bottomRight.x += m_sprite.getGlobalBounds().width;	// Add width for bottom-right x
	bottomRight.y += m_sprite.getGlobalBounds().height; // Add height for bottom-right y
	return bottomRight;
}

bool GameObject::isHigherThan(const GameObject &other) const
{
	sf::Vector2f objTopLeft = this->getTopLeft();
	sf::Vector2f objBottomRight = this->getBottomRight();
	sf::Vector2f wallTopLeft = other.getTopLeft();
	sf::Vector2f wallBottomRight = other.getBottomRight();

	return this->getBottomRight().y < other.getTopLeft().y; // Check if this object is above the other
}

bool GameObject::isLeftThan(const GameObject &other) const
{
	return this->getTopLeft().x < other.getBottomRight().x; // Check if this object is left of the other
}