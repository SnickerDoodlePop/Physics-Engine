#include <entity.hpp>
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

//accessors
void entity::setVelocity(sf::Vector2f _velocity)
{
    this->velocity = _velocity;
}

sf::Vector2f entity::getVelocity()
{
    return this->velocity;
}

sf::Vector2f entity::getVelNorm()
{
    float mag = std::sqrt((this->velocity.x * this->velocity.x) + (this->velocity.y * this->velocity.y));
    return sf::Vector2f((this->velocity.x)/mag, (this->velocity.y)/mag);

}

//member functions
void entity::updatePhysics(sf::Vector2f _acceleration)
{
    this->setPosition(this->getPosition() + this->velocity);
    this->velocity += _acceleration;
} 

    //collisions
void entity::checkCollision(sf::RenderWindow& _window)//, std::vector<entity*>);
{
    if(this->getPosition().y + 2*(this->getRadius()) > _window.getSize().y || this->getPosition().y < 0)
    {
        bounceVert();
    }
    if(this->getPosition().x + 2*(this->getRadius()) > _window.getSize().x || this->getPosition().x < 0)
    {
        bounceHor();
    }
    /*
        todo: set ball position to equal bounds!!! 
    */
} 

void entity::bounceVert()
{
    this->velocity = sf::Vector2f(this->velocity.x, this->velocity.y * -1.f);
}

void entity::bounceHor()
{
    this->velocity = sf::Vector2f(this->velocity.x * -1, this->velocity.y);
}