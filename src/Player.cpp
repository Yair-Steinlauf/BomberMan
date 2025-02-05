#include "Player.h"

Player::Player()
	:Player(sf::Vector2f(0,0), 1)
{
}

Player::Player(const sf::Vector2f& location, float scaler)
	:MovingObject(location, scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(PLAYER));	
	m_speed = 700.0f * scaler; 

	m_life = 3;
	m_freezGiftTime = sf::seconds(0);
}



void Player::update(const sf::Time& deltaTime)
{
	//if (m_collidWithBomb) {
	//	m_life--;
	//	m_collidWithBomb = false;
	//}if (m_collidWithGuard) {
	//	m_life--;
	//	m_collidWithGuard = false;
	//}
	if (m_life <= 0)
		m_win = false;
}

void Player::collide(GameObject& other)
{
	other.collideWithPlayer(*this); //TODO: after set all classes
}

void Player::act(const sf::Time& deltaTime, const sf::Vector2f& playerLoc)
{

	m_direction.x = m_direction.x * deltaTime.asSeconds();
	m_direction.y = m_direction.y * deltaTime.asSeconds();
	this->setLocation(sf::Vector2f(getLocation().x + m_direction.x,
		getLocation().y + m_direction.y));
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
	SoundHandle::getInstance().playSound(S_COLLID_GUARD);
	m_collidWithGuard = true;
}

void Player::collideWithKey(Key& key)
{
	SoundHandle::getInstance().playSound(S_KEY);
	m_Key = true;
}

void Player::collideWithLifeGift(LifeGift& lifeGift)
{
	SoundHandle::getInstance().playSound(S_GIFT);
	m_life++;
}

void Player::collideWithFreezGift(FreezGift& freezGift)
{	
	SoundHandle::getInstance().playSound(S_GIFT);
	m_freezGiftTime = sf::seconds(5);	
}

void Player::collideWithExtraTimeGift(ExtraTimeGift& extraTimeGift)
{
	SoundHandle::getInstance().playSound(S_GIFT);
	m_isGotExtraTimeGift = true;
}

void Player::collideWithBomb(Bomb& bomb)
{
	m_collidWithBomb = true;
}

void Player::collideWithGuardGift(GuardGift& guardGift)
{
	SoundHandle::getInstance().playSound(S_GIFT);
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

bool Player::gotCollidWithGuard()
{
	if (m_collidWithGuard) {
		m_life--;
		m_collidWithGuard = false;
		return true;
	}
	return false;
}

bool Player::gotCollidWithBomb()
{
	if (m_collidWithBomb) {
		m_life--;
		m_collidWithBomb = false;
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

