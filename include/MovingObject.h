#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
public:
	virtual void move() =0;
protected:
	float m_speed;
	sf::Vector2f diffMove(sf::Time deltaTime) const;
};