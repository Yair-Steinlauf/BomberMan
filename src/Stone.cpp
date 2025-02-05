#include "Stone.h"

Stone::Stone()
	: StaticObject()

{
}

Stone::Stone(const sf::Vector2f &location, float scaler)
	: StaticObject(location, scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(STONE));
}

void Stone::collideWithBomb(Bomb &bomb)
{
	m_isActive = false;
}
