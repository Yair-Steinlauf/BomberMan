#include "Gift.h"

Gift::Gift()
	:Gift(sf::Vector2f(0,0))
{
}

Gift::Gift(const sf::Vector2f& location)
	:Pickables(location)
{
	m_sprite.setTexture(DataLoader::getP2Texture(GIFT));
}

void Gift::collide(GameObject& other)
{
	other.collideWithGift(*this);
}
