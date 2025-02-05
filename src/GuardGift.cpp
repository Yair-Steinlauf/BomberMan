#include "GuardGift.h"

GuardGift::GuardGift()
	: GuardGift(sf::Vector2f(0, 0), 1)
{
}

GuardGift::GuardGift(const sf::Vector2f &location, float scaler)
	: Pickables(location, scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GUARDGIFT));
}

void GuardGift::collide(GameObject &other)
{
	other.collideWithGuardGift(*this);
}
