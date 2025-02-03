#include "Wall.h"

Wall::Wall()
	:StaticObject()

{
}

Wall::Wall(const sf::Vector2f& location, float scaler)
	:StaticObject(location, scaler)
{
	m_sprite.setTexture(DataLoader::getP2Texture(WALL));
}



