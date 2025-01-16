#include "Player.h"

Player::Player()
	:MovingObject()
{
}

Player::Player(const sf::Vector2f& location)
	:MovingObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(PLAYER));
	m_speed = 100.0f;
}



void Player::update(const sf::Time& deltaTime)
{
	this->setLocation(sf::Vector2f(getLocation().x + m_direction.x * deltaTime.asSeconds(),
		getLocation().y + m_direction.y * deltaTime.asSeconds()));
}

