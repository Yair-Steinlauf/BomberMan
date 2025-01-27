#include "Guard.h"
Guard::Guard()
    :MovingObject()
{
}

Guard::Guard(const sf::Vector2f& location)
	:MovingObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARD));
	m_speed = 1.0f;
}

void Guard::update(const sf::Time& deltaTime)
{

	//int peeker = rand() % 2;
	//if (rand == 0)
		//setLocation(smartMove());
	//else
		setLocation(getLocation() + m_direction);
}

void Guard::collide(GameObject& other)
{
	other.collideWithGuard(*this);
}

void Guard::act(const sf::Time& deltaTime)
{
	setDirection(randMove());
}

sf::Vector2f Guard::smartMove()
{
    //TODO: smart move logic
	return this->getLocation();
}

Direction Guard::randMove()
{
    int randomDirection = rand() % 4; 
	return Direction(randomDirection);
}


