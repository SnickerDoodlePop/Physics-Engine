#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <entity.hpp>

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
    

    entity* testEntity = new entity();

    //misc
    sf::Vector2i mousePos;
    void initVars();

    //entities
    void initEntities();

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