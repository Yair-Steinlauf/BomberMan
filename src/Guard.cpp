#include "Guard.h"
#include "GameManager.h"

//----static init--------------
enum Difficulty Guard::m_difficulty = Difficulty::Low;

Guard::Guard()
	:MovingObject()
{
}

Guard::Guard(const sf::Vector2f& location, float scaler)
	:MovingObject(location,scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARD));
	m_speed = 200.f * scaler;	
}


void Guard::collideWithBomb(Bomb& bomb)
{
	m_life--;

}
void Guard::collide(GameObject& other)
{
	other.collideWithGuard(*this);
}

void Guard::update(const sf::Time& deltaTime)
{
	if (m_life <= 0 || GameManager::m_removeGuardGift)
	{

		m_isActive = false;
		increaseDifficulty();
		updateToDiffLevel();
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
}

void Guard::act(const sf::Time& deltaTime, const sf::Vector2f& playerLoc)
{
	//this->MovingObject::act(deltaTime);
	//TODO: func for kill first guard
	updateToDiffLevel();
	m_guardMove -= deltaTime;
		int peeker = 0 ;
	if (m_guardMove <= sf::seconds(0)) {
		peeker = rand() % Difficulty::Pro;
		m_guardMove += sf::seconds(1/(float)m_difficulty);
	}
		if (peeker <= m_difficulty )
			setDirection(smartMove(playerLoc));
		else
			setDirection(randMove());
		m_direction.x = m_direction.x * deltaTime.asSeconds();
		m_direction.y = m_direction.y * deltaTime.asSeconds();
	if (!GameManager::m_guardFreeze)
		this->setLocation(sf::Vector2f(getLocation().x + m_direction.x, getLocation().y + m_direction.y));

}


void Guard::increaseDifficulty()
{
	switch (m_difficulty)
	{
	case Low: m_difficulty = Mid;
		break;
	case Mid: m_difficulty = High;
		break;
	case High: m_difficulty = Pro;
		break;
	}
}

void Guard::updateToDiffLevel()
{
	switch (m_difficulty)
	{
	case Low:
		break;
	case Mid:
		m_speed += 0.f;
		break;
	case High:
		m_speed += 0.f;
		break;
	case Pro:
		m_speed += 0.f;
		break;
	default:
		break;
	}
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


