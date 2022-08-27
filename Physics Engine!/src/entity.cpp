#include <entity.hpp>>

void entity::diffEQSolve()
{
    this->setPosition(this->getPosition() + this->velocity);
    this->velocity += this->acceleration;
}

entity::entity(sf::Vector2f startingPos)
{
    this->setPosition(startingPos);
}

entity::entity(void)
{
    return;
    this->velocity = sf::Vector2f(0,0);
    this->acceleration = sf::Vector2f(0,0);
}

entity::entity(sf::CircleShape baseShape)
{
    this->setPosition(baseShape.getPosition());
    this->setFillColor(baseShape.getFillColor());
    this->setRadius(baseShape.getRadius());
}

entity::entity(sf::CircleShape baseShape, sf::Vector2f startingPos)
{
    this->setPosition(baseShape.getPosition());
    this->setFillColor(baseShape.getFillColor());
    this->setRadius(baseShape.getRadius());
    this->setPosition(startingPos);
}

void entity::setAccel(sf::Vector2f accel)
{
    this->acceleration = accel;
}

void entity::update(sf::Vector2f accel)
{
    this->setAccel(accel);
    this->diffEQSolve();
}

void entity::update(sf::RenderWindow& window)
{
    this->diffEQSolve();
    if(this->getPosition().y + this->getRadius() > window.getSize().y)
    {
        this->bounceVert();
    }
    if((this->getPosition().x + this->getRadius() > window.getSize().x)
    || (this->getPosition().x < 0))
    {
        this->bounceHor();
    }
}

void entity::bounceVert()
{
    this->velocity.y *= -0.9;
}

void entity::bounceHor()
{
    this->velocity.x *= -0.9;
}


void entity::setVel(sf::Vector2f initVel)
{
    this->velocity = initVel;
}