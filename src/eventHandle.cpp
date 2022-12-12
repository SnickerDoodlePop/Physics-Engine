#include <eventHandle.hpp>

sf::Event& eventHandler::operator()()
{
    this->parentWindow.pollEvent(this->currentEvent);
    return this->currentEvent;
}

sf::Event& eventHandler::queryEvent()
{
    return this->currentEvent;
}

eventHandler::eventHandler(sf::Window& _window) : parentWindow (_window)
{
    
}