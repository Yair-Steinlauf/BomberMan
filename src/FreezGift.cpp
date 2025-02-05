#include "FreezGift.h"

FreezGift::FreezGift()
	:FreezGift(sf::Vector2f(0, 0),1)
{
}

FreezGift::FreezGift(const sf::Vector2f& location, float scaler)
	:Pickables(location, scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(FREEZGIFT));
}

void FreezGift::collide(GameObject& other)
{
	other.collideWithFreezGift(*this);
}
