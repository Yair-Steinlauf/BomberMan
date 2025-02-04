#include "Guard.h"
#include "GameManager.h"

//----static init--------------

Guard::Guard()
	:MovingObject()
{
}

Guard::Guard(const sf::Vector2f& location, float scaler)
	:MovingObject(location,scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARD));
	m_speed = 300.0f * scaler;	
}

void Guard::update(const sf::Time& deltaTime)
{

	//int peeker = rand() % 2;
	//if (rand == 0)
		//setLocation(smartMove());
	//else
	//bool inBounds = getLocation().x > 0 || getLocation().x < WINDOW_WIDTH || getLocation().y > 0 || getLocation().y < WINDOW_HIGTH;
		//if (!GameManager::m_guardFreeze && inBounds )
			//setLocation(getLocation() + m_direction);
}

void Guard::collide(GameObject& other)
{
	other.collideWithGuard(*this);
}

void Guard::act(const sf::Time& deltaTime, const sf::Vector2f& playerLoc)
{
	//this->MovingObject::act(deltaTime);
	//TODO: func for kill first guard
	if (m_life <= 0 || GameManager::m_removeGuardGift)
	{

		m_isActive = false;
		
		if (GameManager::m_removeGuardGift) {
			GameManager::m_removeGuardGift = false;
		}
		else {
			GameManager::m_guardBombed = true;
		}
		if (m_life <= 0) {
			SoundHandle::getInstance().playSound(S_GUARDBOMBED);
		}
	}

	//TODO: add in last merge
	int peeker = rand() % 2;
	if (peeker == 0)
		setDirection(smartMove(playerLoc));
	else
		setDirection(randMove());
		m_guardMove += sf::seconds(2);
		m_direction.x = m_direction.x * deltaTime.asSeconds();
		m_direction.y = m_direction.y * deltaTime.asSeconds();
	}
	if (!GameManager::m_guardFreeze)
		this->setLocation(sf::Vector2f(getLocation().x + m_direction.x ,getLocation().y + m_direction.y ));
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


