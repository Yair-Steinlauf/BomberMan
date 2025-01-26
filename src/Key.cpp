#include "Key.h"

Key::Key()
	:Key(sf::Vector2f(0,0))
{
}

Key::Key(const sf::Vector2f& location)
	:Pickables(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(KEY));
}

void Key::collide(GameObject& other)
{
	other.collideWithKey(*this);
}
