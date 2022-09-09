#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class entity : public sf::CircleShape
{
private:
    sf::Vector2f velocity;

public:
    //constructors / destructor
    entity(sf::Vector2f); //initial velocity
    entity(void); //default constructor  
    
    //accessors
    void setVelocity(sf::Vector2f);
    sf::Vector2f getVelocity();
    sf::Vector2f getVelNorm();
    
    //member functions
    void updatePhysics(sf::Vector2f);
    

    //collisions

    void checkCollision(sf::RenderWindow&); //, std::vector<entity*>);

    void bounceVert();
    void bounceHor();

};