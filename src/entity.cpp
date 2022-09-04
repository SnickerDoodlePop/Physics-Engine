#include <entity.hpp>
#include <random>

typedef std::linear_congruential_engine<unsigned int, 48271, 0, 2147483647> minstd_rand;

//initial velocity
entity::entity(sf::Vector2f velInit) : velocity(velInit)
{
    minstd_rand randomNumber {static_cast<unsigned>(time(NULL))};
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        static_cast<float>(randomNumber() % 1920),
        static_cast<float>(randomNumber() % 1080)
    ));
}

//default constructor
entity::entity(void) : velocity(sf::Vector2f(0.f, 0.f))
{
    minstd_rand randomNumber {static_cast<unsigned>(time(NULL))};
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        static_cast<float>(randomNumber() % 1920),
        static_cast<float>(randomNumber() % 1080)
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