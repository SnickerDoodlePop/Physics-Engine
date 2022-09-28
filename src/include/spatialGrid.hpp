#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <entity.hpp>
#include <game.hpp>

class spatialGrid
{
private:
    sf::Vector2f size {};
    sf::Vector2f position {};
    std::vector<std::vector<spatialGrid>> subGrids {4};

public:
    spatialGrid(sf::RenderWindow&);
    virtual ~spatialGrid();
    void update(sf::RenderWindow&);
};