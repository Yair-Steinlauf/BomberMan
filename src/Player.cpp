#include "Player.h"

Player::Player()
{
	m_sprite.setTexture(DataLoader::getP2Texture(PLAYER));
	m_speed = 50.0f;
}

Player::Player(const sf::Vector2f& location)
	:Player()
{
	this->setLocation(location);
}

void Player::move(const sf::Time& deltaTime, const sf::Event& type)
{
	sf::Vector2f newLocation = this->getLocation();
	switch (type.key.code)
	{
	case sf::Keyboard::Up:
		newLocation.y -= diffMove(deltaTime).y;
		break;
	case sf::Keyboard::Down:
		newLocation.y += diffMove(deltaTime).y;
		break;
	case sf::Keyboard::Left:
		newLocation.x -= diffMove(deltaTime).x;
		break;
	case sf::Keyboard::Right:
		newLocation.x += diffMove(deltaTime).x;
		break;
	}
	this->setLocation(newLocation);
}

