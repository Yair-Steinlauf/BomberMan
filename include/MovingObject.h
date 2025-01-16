#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
public:
	virtual void move() =0;
protected:
	MovingObject();
	MovingObject(const sf::Vector2f& location);
	float m_speed;
	sf::Vector2f diffMove(sf::Time deltaTime) const;
};