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
//void MovingObject::collideWithWall(Wall& wall)
//{
//    // Reset direction first
//    sf::Vector2f objTopLeft = this->getTopLeft();
//    sf::Vector2f objBottomRight = this->getBottomRight();
//    sf::Vector2f wallTopLeft = wall.getTopLeft();
//    sf::Vector2f wallBottomRight = wall.getBottomRight();
//
//    // Check for collisions in the X-axis first (left-right)
//    if (objBottomRight.x > wallTopLeft.x && objTopLeft.x < wallTopLeft.x) {
//        m_direction.x = 0; // Stop moving to the left
//        // Move the object just outside the wall on the X-axis
//        objTopLeft.x = wallTopLeft.x - (objBottomRight.x - objTopLeft.x);
//    }
//    else if (objTopLeft.x < wallBottomRight.x && objBottomRight.x > wallBottomRight.x) {
//        m_direction.x = 0; // Stop moving to the right
//        // Move the object just outside the wall on the X-axis
//        objTopLeft.x = wallBottomRight.x;
//    }
//
//    // Check for collisions in the Y-axis (up-down)
//    if (objBottomRight.y > wallTopLeft.y && objTopLeft.y < wallTopLeft.y) {
//        m_direction.y = 0; // Stop moving up
//        // Move the object just outside the wall on the Y-axis
//        objTopLeft.y = wallTopLeft.y - (objBottomRight.y - objTopLeft.y);
//    }
//    else if (objTopLeft.y < wallBottomRight.y && objBottomRight.y > wallBottomRight.y) {
//        m_direction.y = 0; // Stop moving down
//        // Move the object just outside the wall on the Y-axis
//        objTopLeft.y = wallBottomRight.y;
//    }
//
//    // Update the object location after adjusting for the collision
//    this->setLocation(objTopLeft);
//    //this->update(sf::milliseconds(1));
////m_direction = sf::Vector2f(0, 0);
//}


void MovingObject::collideWithStatic(StaticObject& wall)
{
    m_direction = sf::Vector2f(0, 0);  // Reset the direction initially

    // Get the top-left and bottom-right coordinates of both the object and the wall
    sf::Vector2f objTopLeft = this->getTopLeft();
    sf::Vector2f objBottomRight = this->getBottomRight();
    sf::Vector2f wallTopLeft = wall.getTopLeft();
    sf::Vector2f wallBottomRight = wall.getBottomRight();

    // Check if the object is colliding from the top
    if (objBottomRight.y > wallTopLeft.y && objTopLeft.y < wallTopLeft.y)
    {
        m_direction.y = -ImageDimension.y;  // Move the object upwards
    }
    this->update(sf::milliseconds(5));

    // Check if the object is colliding from the bottom
    if (objTopLeft.y < wallBottomRight.y && objBottomRight.y > wallBottomRight.y)
    {
        m_direction.y = ImageDimension.y;  // Move the object downwards
    }
    this->update(sf::milliseconds(5));

    // Check if the object is colliding from the left
    if (objBottomRight.x > wallTopLeft.x && objTopLeft.x < wallTopLeft.x)
    {
        m_direction.x = -ImageDimension.x;  // Move the object to the left
    }
    this->update(sf::milliseconds(5));

    // Check if the object is colliding from the right
    if (objTopLeft.x < wallBottomRight.x && objBottomRight.x > wallBottomRight.x)
    {
        m_direction.x = ImageDimension.x;  // Move the object to the right
    }
    this->update(sf::milliseconds(5));
    m_direction = sf::Vector2f(0, 0);
}

MovingObject::MovingObject()
	:MovingObject(sf::Vector2f(0,0))
{
}

MovingObject::MovingObject(const sf::Vector2f& location)
	:GameObject(location)
{
}
