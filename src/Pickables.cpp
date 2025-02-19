#include "Pickables.h"

void Pickables::collide(GameObject &other)
{
	other.collideWithPickable(*this);
}

void Pickables::collideWithPlayer(Player &player)
{
	m_isActive = false;
}

Pickables::Pickables()
	: Pickables(sf::Vector2f(0, 0), 1)
{
}

Pickables::Pickables(const sf::Vector2f &location, float scaler)
	: StaticObject(location, scaler)
{
}
