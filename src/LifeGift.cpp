#include "LifeGift.h"

LifeGift::LifeGift()
	:LifeGift(sf::Vector2f(0,0))
{
}

LifeGift::LifeGift(const sf::Vector2f& location)
	:Pickables(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(LIFEGIFT));
}

void LifeGift::collide(GameObject& other)
{
	other.collideWithLifeGift(*this);
}
