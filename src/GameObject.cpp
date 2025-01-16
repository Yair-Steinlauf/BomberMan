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

bool GameObject::intersect(GameObject& other)
{
	sf::FloatRect myBounds = m_sprite.getGlobalBounds();
	sf::FloatRect otherBounds = other.m_sprite.getGlobalBounds();
	sf::FloatRect sharedArea;
	if (myBounds.intersects(otherBounds, sharedArea));
	{
		sf::Vector2f topLeft = sf::Vector2f(sharedArea.getPosition());//the topLeft of rec
		for (unsigned int x = topLeft.x; x < topLeft.x + sharedArea.width; x++)
		{
			for (unsigned int y = topLeft.y; y < topLeft.y + sharedArea.height; y++)
			{
				sf::Vector2f posA = m_sprite.getInverseTransform().transformPoint(x, y);
				sf::Vector2f posB = other.m_sprite.getInverseTransform().transformPoint(x, y);
				sf::Vector2u sizeA = m_sprite.getTexture()->getSize();
				sf::Vector2u sizeB = other.m_sprite.getTexture()->getSize();

				// Check bounds
				if (posA.x >= 0 && posA.y >= 0 && posB.x >= 0 && posB.y >= 0 &&
					posA.x < sizeA.x && posA.y < sizeA.y &&
					posB.x < sizeB.x && posB.y < sizeB.y) {
					// If both pixels are within bounds, we have a collision
					return true;
				}
			}
		}
	}
	return false;
}


GameObject::~GameObject()
{
}

void GameObject::setLocation(const sf::Vector2f& newLocation)
{
	m_sprite.setPosition(newLocation); //TODO: bound check
}
