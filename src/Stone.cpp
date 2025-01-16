#include "Stone.h"

Stone::Stone()
	:StaticObject()

{
}

Stone::Stone(const sf::Vector2f& location)
	:StaticObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(STONE));
}

void Stone::collide(GameObject& other)
{
	other.collideWithStone(*this);
}

