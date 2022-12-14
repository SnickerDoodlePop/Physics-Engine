#include <PHYS/game.hpp>
#include <iostream>
#include <ctime>
#include <random>

//window
void game::initWindow(bool usingBorder)
{
    this->videoMode.height = 1080;
    this->videoMode.width = 1920;
    this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "game engine!", usingBorder ? sf::Style::Default : sf::Style::None);
    this->window->setFramerateLimit(144);
}


void game::initVars()
{
    this->window = nullptr;
    this->gravity = sf::Vector2f(0,0.1);
    for(int iterator {0}; iterator < 5; iterator++)
    {
        this->entities.push_back(new entity{sf::Vector2f(8,0)});
    }
}

//constructor / destructor
game::game(bool usingBorder)
{
    this->initVars();
    this->initWindow(usingBorder);
}

game::~game()
{
    delete this->window;
}

//accessors
const bool game::isRunning() const
{
    return this->window->isOpen();
}

//public member functions
void game::updateMousePos()
{
    this->mousePos = sf::Mouse::getPosition(*(this->window));
    //std::cout << this->mousePos.x << " " << this->mousePos.y << std::endl;
}

void game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                    break;
                }
                if(event.key.code == sf::Keyboard::E){
                    //spawn an entity!
                }
    
            default:
                break;
        }
    }
}

void game::update()
{
    for(auto _entity: this->entities)
    {
        _entity->updatePhysics(game::gravity);
        _entity->updateCollisions(*(this->window));
    }
    this->pollEvents();
    this->updateMousePos();
}

void game::render()
{
    this->window->clear(sf::Color::White);
    for(auto _entity: this->entities)
    {
        this->window->draw(*_entity);
    }
    this->window->display();
}