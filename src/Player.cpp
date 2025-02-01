#include "Player.h"

Player::Player()
	:Player(sf::Vector2f(0,0))
{
}

Player::Player(const sf::Vector2f& location)
	:MovingObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(PLAYER));
	m_speed = 100.0f;
	m_life = 3;
	m_freezGiftTime = sf::seconds(0);
}



void Player::update(const sf::Time& deltaTime)
{
	this->setLocation(sf::Vector2f(getLocation().x + m_direction.x * deltaTime.asSeconds(),
		getLocation().y + m_direction.y * deltaTime.asSeconds()));
}

void Player::collide(GameObject& other)
{
	other.collideWithPlayer(*this); //TODO: after set all classes
}

void Player::act( const sf::Time& deltaTime)
{
}

void Player::collideWithDoor(Door& door)
{
	if (gotKey())
	{
		m_win = true;
	}
}

void Player::collideWithGuard(Guard& guard)
{
	m_life--;
	if (m_life <= 0)
		m_win = false;
}

void Player::collideWithKey(Key& key)
{
	m_Key = true;
}

void Player::collideWithGift(Gift& gift)
{
	m_life++;
}

void Player::collideWithFreezGift(FreezGift& freezGift)
{	
	m_freezGiftTime = sf::seconds(5);	
}

void Player::collideWithExtraTimeGift(ExtraTimeGift& extraTimeGift)
{
	m_isGotExtraTimeGift = true;
}

void Player::collideWithGuardGift(GuardGift& guardGift)
{
	m_score += 5;
	m_isGotGuardGift = true;
}

bool Player::gotGuardGift()
{
	if (m_isGotGuardGift) {
		m_isGotGuardGift = false;
		return true;
	}
	return false;
}

bool Player::gotExtraTimeGift()
{
	if (m_isGotExtraTimeGift) {
		m_isGotExtraTimeGift = false;
		return true;
	}
	return false;
}

sf::Time Player::gotFreezGift(sf::Time& deltaTime)
{
	m_freezGiftTime -= deltaTime;
	return m_freezGiftTime;
}

bool Player::won() const
{
	return m_win;
}

bool Player::gotKey() const
{
	return m_Key;
}

int Player::getScore()
{
	return m_score;
}

void Player::addScore(int points)
{
	m_score += points;
}

void Player::decreaseScore(int points)
{
	m_score -= points;
}

void Player::setScore(int score)
{
	m_score = score;
}

void Player::resetScore()
{
	m_score = 0;
}

