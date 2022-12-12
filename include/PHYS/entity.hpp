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
    entity(sf::Vector2f);
    entity(void);  
    
    void setVelocity(sf::Vector2f);
    sf::Vector2f getVelocity();
    sf::Vector2f getVelNorm();

    void updatePhysics(sf::Vector2f);
    
    void updateCollisions(sf::RenderWindow&);

};