
#include "Bomb.h"


Bomb::Bomb(const sf::Vector2f& location, float scaler)
    : StaticObject(location, scaler), m_stateBomb(SAFE) // מוסיפים אתחול למצב
{
    m_sprite.setTexture(DataLoader::getP2Texture(BOMB));
    //m_sprite.setScale(scaler, scaler);
}

Bomb::Bomb(const sf::Vector2f& location, float scaler, bool visible)
    :Bomb(location, scaler)
{
    if (!visible)
    {
        m_sprite.setColor(sf::Color(255, 255, 255, 0));
    }
}

void Bomb::act(const sf::Time& deltaTime)
{

    m_timer -= deltaTime;

    switch (m_stateBomb)
    {
    case SAFE:
        if (m_timer <= sf::seconds(0.5))
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
    m_sprite.setTexture(DataLoader::getP2Texture(EXPLODED));
    m_sprite.setColor(sf::Color(255, 255, 255, 255));
    m_stateBomb = DANGER;    
    SoundHandle::getInstance().playSound(S_EXPLODE);
}

