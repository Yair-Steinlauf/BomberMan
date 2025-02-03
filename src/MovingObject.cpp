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
    setLocation(sf::Vector2f(getLocation().x - m_direction.x,
        getLocation().y -m_direction.y));
}

void MovingObject::collideWithBomb(Bomb& bomb)
{
    m_life--;
}

unsigned int MovingObject::getLife() const
{
    return m_life;
}


MovingObject::MovingObject()
	:MovingObject(sf::Vector2f(0,0), 1)
{
}

MovingObject::MovingObject(const sf::Vector2f& location, float scaler)
	:GameObject(location, scaler) , m_startPos(location)
{
}



void MovingObject::moveToStartPos()
{
    setLocation(m_startPos);
}
