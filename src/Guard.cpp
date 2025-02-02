#include "Guard.h"
#include "GameManager.h"

//----static init--------------
unsigned int Guard::m_numOfGuard = 0;

Guard::Guard()
    :MovingObject()
{
}

Guard::Guard(const sf::Vector2f& location)
	:MovingObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARD));
	m_speed = 1.0f;
	m_numOfGuard++;
}

void Guard::update(const sf::Time& deltaTime)
{

	//int peeker = rand() % 2;
	//if (rand == 0)
		//setLocation(smartMove());
	//else
	if (!GameManager::m_guardFreeze)
		setLocation(getLocation() + m_direction);
}

void Guard::collide(GameObject& other)
{
	other.collideWithGuard(*this);
}

void Guard::act(const sf::Time& deltaTime)
{

	//TODO: func for kill first guard
	if (m_life <= 0 || GameManager::m_removeGuardGift)
	{
		m_isActive = false;
		if (GameManager::m_removeGuardGift) {
			GameManager::m_removeGuardGift = false;
		}
	}

		setDirection(randMove());
}

unsigned int Guard::getNumOfGuard() 
{
	return m_numOfGuard;
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


