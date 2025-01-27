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

	//TODO: decied wich method to use

		// מקבלים את גבולות האובייקטים
		sf::FloatRect bounds1 = m_sprite.getGlobalBounds();
		sf::FloatRect bounds2 = other.m_sprite.getGlobalBounds();
		
		// בדיקה אם יש חפיפה בין הגבולות
		return bounds1.intersects(bounds2);


	//sf::FloatRect myBounds = m_sprite.getGlobalBounds();
	//sf::FloatRect otherBounds = other.m_sprite.getGlobalBounds();
	//sf::FloatRect sharedArea;
	//if (myBounds.intersects(otherBounds, sharedArea))
	//{
	//	sf::Vector2f topLeft = sf::Vector2f(sharedArea.getPosition());//the topLeft of rec
	//	auto transformA = m_sprite.getInverseTransform();
	//	auto transformB = other.m_sprite.getInverseTransform();
	//	for (unsigned int x = topLeft.x; x < topLeft.x + sharedArea.width; x++)
	//	{
	//		for (unsigned int y = topLeft.y; y < topLeft.y + sharedArea.height; y++)
	//		{
	//			sf::Vector2f posA = transformA.transformPoint(x, y);
	//			sf::Vector2f posB = transformB.transformPoint(x, y);
	//			sf::Vector2u sizeA = m_sprite.getTexture()->getSize();
	//			sf::Vector2u sizeB = other.m_sprite.getTexture()->getSize();

	//			// Check bounds
	//			if (posA.x >= 0 && posA.y >= 0 && posB.x >= 0 && posB.y >= 0 &&
	//				posA.x < sizeA.x && posA.y < sizeA.y &&
	//				posB.x < sizeB.x && posB.y < sizeB.y) {
	//				// If both pixels are within bounds, we have a collision
	//				return true;
	//			}
	//		}
	//	}
	//}
	//return false;
}


GameObject::~GameObject()
{
}

void GameObject::setLocation(const sf::Vector2f& newLocation)
{
	m_sprite.setPosition(newLocation); //TODO: bound check
}
sf::Vector2f GameObject::getTopLeft() const
{
	return m_sprite.getPosition(); // returns the top-left position
}

bool GameObject::isActive() const
{
	return m_isActive;
}

sf::Vector2f GameObject::getBottomRight() const
{
	auto bottomRight = getTopLeft();
	bottomRight.x += m_sprite.getGlobalBounds().width;  // Add width for bottom-right x
	bottomRight.y += m_sprite.getGlobalBounds().height; // Add height for bottom-right y
	return bottomRight;
}

bool GameObject::isHigherThan(const GameObject& other) const
{
	sf::Vector2f objTopLeft = this->getTopLeft();
	sf::Vector2f objBottomRight = this->getBottomRight();
	sf::Vector2f wallTopLeft = other.getTopLeft();
	sf::Vector2f wallBottomRight = other.getBottomRight();

	return this->getBottomRight().y < other.getTopLeft().y;  // Check if this object is above the other
}

bool GameObject::isLeftThan(const GameObject& other) const
{
	return this->getTopLeft().x < other.getBottomRight().x;  // Check if this object is left of the other
}


//sf::Vector2f GameObject::getTopLeft()const
//{
//	return m_sprite.getPosition();
//}

//sf::Vector2f GameObject::getButtomRight()const
//{
//	auto buttomRight = getTopLeft();
//	buttomRight.x += m_sprite.getGlobalBounds().width;
//	buttomRight.y -= m_sprite.getGlobalBounds().height;
//	return buttomRight;
//}

//bool GameObject::isHigherThan(GameObject& other) const
//{
//	return this->getButtomRight().y < other.getTopLeft().y;
//}
//bool GameObject::isLeftThan(const GameObject& other) const
//{
//	return this->getButtomRight().x < other.getTopLeft().x;
//}