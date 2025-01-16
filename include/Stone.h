#pragma once
#include "StaticObject.h"

class Stone : public StaticObject {
public:
	Stone();
	Stone(const sf::Vector2f& location);
	virtual void collide(GameObject& other) override;
};