#pragma once
#include "Pickables.h"
class Gift : public Pickables {
public:
	Gift();
	Gift(const sf::Vector2f& location);
	void collide(GameObject& other) override;

private:
};