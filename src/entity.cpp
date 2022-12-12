#include <PHYS/entity.hpp>
#include <random>
#include <cmath>

unsigned int iterateSpawnTime = 0;

//declaring special functor to generate pseudo-random numbers
typedef std::linear_congruential_engine<unsigned int, 48271, 0, 2147483647> minstd_rand;

//spawn with initial velocity
entity::entity(sf::Vector2f velInit) : velocity(velInit)
{
    //using a functor lmao
    minstd_rand randomNumber {static_cast<unsigned>(time(NULL)) + iterateSpawnTime};
    iterateSpawnTime++;
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        static_cast<float>(randomNumber() % 1920),
        static_cast<float>(randomNumber() % 1080)
    ));
}

//default constructor / spawn stationary
entity::entity(void) : velocity(sf::Vector2f(0.f, 0.f))
{
    //using a functor lmao
    minstd_rand randomNumber {static_cast<unsigned>(time(NULL)) + iterateSpawnTime};
    iterateSpawnTime++;
    this->setFillColor(sf::Color::Black);
    this->setRadius(50.f);
    this->setPosition(sf::Vector2f
    (
        static_cast<float>(randomNumber() % (1920 - (int)this->getRadius())),
        static_cast<float>(randomNumber() % (1080 - (int)this->getRadius()))
    ));
}

//velocity setter
void entity::setVelocity(sf::Vector2f _velocity)
{
    this->velocity = _velocity;
}

//velocity getter
sf::Vector2f entity::getVelocity()
{
    return this->velocity;
}

//returns the unit velocity vector
sf::Vector2f entity::getVelNorm()
{
    float mag = std::sqrt((this->velocity.x * this->velocity.x) + (this->velocity.y * this->velocity.y));
    return sf::Vector2f((this->velocity.x)/mag, (this->velocity.y)/mag);

}

//step time forward and set new position
void entity::updatePhysics(sf::Vector2f _acceleration)
{
    this->setPosition(this->getPosition() + this->velocity);
    this->velocity += _acceleration;
} 

//detects collision with walls and adjusts velocity accordingly
void entity::updateCollisions(sf::RenderWindow& _window)
{
    sf::Vector2f currentPos = this->getPosition();
    float boundingRadius = 2*(this->getRadius());
    sf::Vector2u windowSize = _window.getSize();

    if(currentPos.y + boundingRadius > windowSize.y)
    {
        this->setPosition(currentPos.x, windowSize.y - boundingRadius);
        this->setVelocity(sf::Vector2f(this->velocity.x, this->velocity.y * -0.9));
    }
    if(currentPos.y < 0)
    {
        this->setPosition(currentPos.x, 0);
        this->setVelocity(sf::Vector2f(this->velocity.x, this->velocity.y * -0.9));
    }
    if(currentPos.x + boundingRadius > windowSize.x)
    {
        this->setPosition(windowSize.x - boundingRadius, currentPos.y);
        this->setVelocity(sf::Vector2f(this->velocity.x * -0.9, this->velocity.y));
    }
    if(currentPos.x < 0)
    {
        this->setPosition(0, currentPos.y);
        this->setVelocity(sf::Vector2f(this->velocity.x * -0.9, this->velocity.y));
    }
}