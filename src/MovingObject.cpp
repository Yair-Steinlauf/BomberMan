#include "MovingObject.h"
#include "Wall.h"

void MovingObject::setDirection(Direction direction)
{
	switch (direction)
	{
	case UP:
		m_direction = sf::Vector2f(0, -m_speed);
		break;
	case DOWN:
		m_direction = sf::Vector2f(0, m_speed);
		break;
	case RIGHT:
		m_direction = sf::Vector2f(m_speed, 0);;
		break;
	case LEFT:
		m_direction = sf::Vector2f(-m_speed, 0);
		break;
	case DEFAULT:
		m_direction = sf::Vector2f(0, 0);
	}
}



void MovingObject::collideWithStatic(StaticObject& wall)
{
    //TODO: not good, need to improve
    //m_direction = sf::Vector2f(0, 0);  // Reset the direction initially

    // Get the top-left and bottom-right coordinates of both the object and the wall
    sf::Vector2f objTopLeft = this->getTopLeft();
    sf::Vector2f objBottomRight = this->getBottomRight();
    sf::Vector2f wallTopLeft = wall.getTopLeft();
    sf::Vector2f wallBottomRight = wall.getBottomRight();

    // Check if the object is colliding from the top
    if (objBottomRight.y > wallTopLeft.y && objTopLeft.y < wallTopLeft.y)
    {
        m_direction.y = -ImageDimension.y;  // Move the object upwards
        //this->update(sf::milliseconds(5));
    }

    // Check if the object is colliding from the bottom
    if (objTopLeft.y < wallBottomRight.y && objBottomRight.y > wallBottomRight.y)
    {
        m_direction.y = ImageDimension.y;  // Move the object downwards
        //this->update(sf::milliseconds(5));
    }

    // Check if the object is colliding from the left
    if (objBottomRight.x > wallTopLeft.x && objTopLeft.x < wallTopLeft.x)
    {
        m_direction.x = -ImageDimension.x;  // Move the object to the left
        //this->update(sf::milliseconds(5));
    }

    // Check if the object is colliding from the right
    if (objTopLeft.x < wallBottomRight.x && objBottomRight.x > wallBottomRight.x)
    {
        m_direction.x = ImageDimension.x;  // Move the object to the right
        //this->update(sf::milliseconds(5));
    }
    this->update(sf::milliseconds(50));

    m_direction = sf::Vector2f(0, 0);
}

unsigned int MovingObject::getLife() const
{
    return m_life;
}

MovingObject::MovingObject()
	:MovingObject(sf::Vector2f(0,0))
{
}

MovingObject::MovingObject(const sf::Vector2f& location)
	:GameObject(location) , m_startPos(location)
{
}

void MovingObject::moveToStartPos()
{
    setLocation(m_startPos);
}
