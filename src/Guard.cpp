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

void Guard::act(const sf::Time& deltaTime)
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
	}
	m_guardMove -= deltaTime;
	if (m_guardMove <= sf::seconds(0)) {
		setDirection(randMove());
		m_guardMove += sf::seconds(2);
		m_direction.x = m_direction.x * deltaTime.asSeconds();
		m_direction.y = m_direction.y * deltaTime.asSeconds();
	}
	if (!GameManager::m_guardFreeze)
		this->setLocation(sf::Vector2f(getLocation().x + m_direction.x ,getLocation().y + m_direction.y ));
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


