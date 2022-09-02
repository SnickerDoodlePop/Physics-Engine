#include <entity.hpp>

//initial velocity
entity::entity(sf::Vector2f velInit) : velocity(velInit)
{
    srand((unsigned int)time(NULL));
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        static_cast<float>(rand() % 1920 + 1),
        static_cast<float>(rand() % 1080 + 1)
    ));
}

//default constructor
entity::entity() : velocity(sf::Vector2f(0.f, 0.f))
{
    srand((unsigned int)time(NULL));
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        (rand() % 1920 + 1),
        (rand() % 1080 + 1)
    ));
}

//accessors
void entity::setVelocity(sf::Vector2f _velocity)
{
    this->velocity = _velocity;
}

sf::Vector2f entity::getVelocity()
{
    return this->velocity;
}

//member functions
void entity::updatePhysics(sf::Vector2f acceleration)
{
    this->setPosition(this->getPosition() + this->velocity);
    this->velocity += acceleration;
}