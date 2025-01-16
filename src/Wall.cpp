#include "Wall.h"

Wall::Wall()
	:StaticObject()

{
}

Wall::Wall(const sf::Vector2f& location)
	:StaticObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(WALL));
}

void Wall::collide(GameObject& other)
{
	other.collideWithWall(*this);
}
