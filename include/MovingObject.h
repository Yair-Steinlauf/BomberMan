#pragma once
#include "GameObject.h".

class MovingObject : public GameObject
{
public:
	virtual void update(const sf::Time &deltaTime) = 0;
	void setDirection(Direction direction);
	virtual void collideWithStatic(StaticObject &stat) override;

	unsigned int getLife() const;
	void setLife(int life);
	virtual void moveToStartPos() override;

protected:
	MovingObject();
	MovingObject(const sf::Vector2f &location, float scaler);
	float m_speed = 0;
	int m_life = 1;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	sf::Vector2f m_startPos;
};