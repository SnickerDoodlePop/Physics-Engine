#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>

#include <PHYS/entity.hpp>

/*
    Basically the game engine
*/

class game
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    void initWindow(bool usingBorder);
    


    //misc
    sf::Vector2i mousePos;
    void initVars();
    sf::Vector2f gravity;

    //entities
    std::vector<entity*> entities;

public:
    //constructor / destructor
    game(bool usingBorder);
    virtual ~game();

    //accessors
    const bool isRunning() const;

    //functions
    void updateMousePos();
    void pollEvents();
    void update();
    void render();
};