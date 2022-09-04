//just cpp things
#include <game.hpp>
#include <iostream>

//using the SFML api

int main(int argc, char const **argv)
{

    //check cmd line args
    bool usingBorder = false;
    std::vector<std::string> cmdArgs(argv, argv + argc);
    for(auto x : cmdArgs)
    {
        if(x == std::string("-b")) usingBorder = true;
    }
    
    
    //init game engine
    game* newGame = new game(usingBorder);
    

    //game loop
    while(newGame->isRunning())
    {
        newGame->update();
        newGame->render();
    }

    return 0;
}