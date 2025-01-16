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

void Guard::move()
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
    sf::Vector2f moveDirection;

    switch (randomDirection)
    {
    case UP: 
        moveDirection = sf::Vector2f(0, -m_speed);
        break;
    case DOWN:
        moveDirection = sf::Vector2f(0, m_speed);
        break;
    case LEFT: 
        moveDirection = sf::Vector2f(-m_speed, 0);
        break;
    case RIGHT: 
        moveDirection = sf::Vector2f(m_speed, 0);
        break;
    }

    return getLocation() + moveDirection;
}


