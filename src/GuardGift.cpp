#include "GuardGift.h"

GuardGift::GuardGift()
	:GuardGift(sf::Vector2f(0, 0))
{
}

GuardGift::GuardGift(const sf::Vector2f& location)
	:Pickables(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARDGIFT));
}

void GuardGift::collide(GameObject& other)
{
	other.collideWithGuardGift(*this);
}
