#pragma once
#include "StaticObject.h"

class Stone : public StaticObject {
public:
	Stone();
	Stone(const sf::Vector2f& location, float scaler);
	void collideWithBomb(Bomb& bomb);
};