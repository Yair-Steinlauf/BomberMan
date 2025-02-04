
#include "Bomb.h"


Bomb::Bomb(const sf::Vector2f& location)
    : StaticObject(location), m_stateBomb(SAFE) // מוסיפים אתחול למצב
{
    m_sprite.setTexture(DataLoader::getP2Texture(BOMB));
}

void Bomb::act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc)
{

    m_timer -= deltaTime;

    switch (m_stateBomb)
    {
    case SAFE:
        if (m_timer <= sf::seconds(1))
        {
            explode();
        }
        break;

    case DANGER:
        m_stateBomb = AFTER_EXPLOAD;
        break;

    case AFTER_EXPLOAD:
        if (m_timer <= sf::Time::Zero)
        {
            m_isActive = false;
        }
        break;
    }
}

void Bomb::collide(GameObject& other)
{
    if (m_stateBomb == DANGER)
    {
        other.collideWithBomb(*this);
    }
}

void Bomb::update(const sf::Time& deltaTime)
{}

void Bomb::explode()
{
    if (m_stateBomb != SAFE) return;

    m_sprite.setTexture(DataLoader::getP2Texture(EXPLODE));

    m_stateBomb = DANGER;
    // אפשר להוסיף כאן אפקט קול או אנימציה
    //playExplosionSound();
}

//void Bomb::updateAnimation(const sf::Time& deltaTime)
//{
//    // עדכון אנימציה בהתאם למצב
//    switch (m_stateBomb)
//    {
//    case SAFE:
//        // אנימציה של פצצה רגילה
//        break;
//    case DANGER:
//        // אנימציה של פיצוץ
//        break;
//    case AFTER_EXPLOAD:
//        // אנימציה של אחרי הפיצוץ
//        break;
//    }
//}

//void Bomb::playExplosionSound()
//{
//    // הוספת אפקט קול לפיצוץ
//    // DataLoader::playSound(EXPLOSION_SOUND);
//}