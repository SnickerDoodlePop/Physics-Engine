#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class entity : public sf::CircleShape
{
private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    void diffEQSolve();

public:
    entity(sf::Vector2f);
    entity(void);
    entity(sf::CircleShape);
    entity(sf::CircleShape, sf::Vector2f);
    
    void setVel(sf::Vector2f);
    
    void setAccel(sf::Vector2f);
    
    void update(sf::Vector2f);
    void update(sf::RenderWindow&);
    void bounceVert();
    void bounceHor();
};