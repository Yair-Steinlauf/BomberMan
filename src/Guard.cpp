#include "Guard.h"
Guard::Guard()
    :MovingObject()
{
}

Guard::Guard(const sf::Vector2f& location)
	:MovingObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARD));
	m_speed = 10.0f;
}

void Guard::update(const sf::Time& deltaTime)
{

	int peeker = rand() % 2;
	//if (rand == 0)
		//setLocation(smartMove());
	//else
		setLocation(randMove());
}

sf::Vector2f Guard::smartMove()
{
    //TODO: smart move logic
	return this->getLocation();
}

sf::Vector2f Guard::randMove()
{
    int randomDirection = rand() % 4; 
    setDirection(Direction(randomDirection));
    return getLocation() + m_direction;
}


