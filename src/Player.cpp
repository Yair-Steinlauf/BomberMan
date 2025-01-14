#include "Player.h"

Player::Player(const sf::Vector2f& location)
	:MovingObject(PLAYER, location)
{
	m_health = 3;
}

sf::Vector2f Player::move(sf::Time deltaTime, const sf::Event& type)
{
	sf::Vector2f newLocation = this->getLocation();
	switch (type.key.code)
	{
	case sf::Keyboard::Up:
		newLocation.y += diffMove(deltaTime).y;
		break;
	case sf::Keyboard::Down:
		newLocation.y -= diffMove(deltaTime).y;
		break;
	case sf::Keyboard::Left:
		newLocation.x -= diffMove(deltaTime).x;
		break;
	case sf::Keyboard::Right:
		newLocation.x += diffMove(deltaTime).x;
		break;
	}
	this->setLocation(newLocation);
	return newLocation;
}