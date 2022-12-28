#pragma once
#include <SFML/Window.hpp>

class eventHandler
{
private:
    sf::Window& parentWindow;
    sf::Event currentEvent;

public:
    sf::Event& queryEvent();
    sf::Event& operator()();
    
    eventHandler(sf::Window&);
    
};