#include "Door.h"

Door::Door()
	:StaticObject()
{
}

Door::Door(const sf::Vector2f& location)
	:StaticObject(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(DOOR));
}

void Door::collide(GameObject& other)
{
}
