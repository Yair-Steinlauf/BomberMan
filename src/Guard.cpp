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

void Guard::act(const sf::Time& deltaTime, const sf::Vector2f& playerLoc)
{

	//TODO: func for kill first guard
	if (m_life <= 0 || GameManager::m_removeGuardGift)
	{
		m_isActive = false;
		if (GameManager::m_removeGuardGift) {
			GameManager::m_removeGuardGift = false;
		}
	}

	//TODO: add in last merge
	int peeker = rand() % 2;
	if (peeker == 0)
		setDirection(smartMove(playerLoc));
	else
		setDirection(randMove());
}

unsigned int Guard::getNumOfGuard()
{
	return m_numOfGuard;
}


Direction Guard::smartMove(const sf::Vector2f& playerLoc)
{
	sf::Vector2f direction = playerLoc - getLocation();

	if (fabs(direction.x) > fabs(direction.y)) {
		if (direction.x > 0) {
			return RIGHT;
		}
		else {
			return LEFT;
		}
	}
	else {
		if (direction.y > 0) {
			return DOWN;
		}
		else {
			return UP;
		}
	}
}


Direction Guard::randMove()
{
	int randomDirection = rand() % 4;
	return Direction(randomDirection);
}


