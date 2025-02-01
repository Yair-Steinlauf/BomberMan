#include "ExtraTimeGift.h"

ExtraTimeGift::ExtraTimeGift()
	:ExtraTimeGift(sf::Vector2f(0,0))
{
}

ExtraTimeGift::ExtraTimeGift(const sf::Vector2f& location)
	:Pickables(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(EXTRATIMEGIFT));
}

void ExtraTimeGift::collide(GameObject& other)
{
	other.collideWithExtraTimeGift(*this);
}
