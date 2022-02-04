#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SDL2/SDL.h>
#include "MainWindowsSDL.hpp"
#include "snake.hpp"

class food
{
private:
    int x;
    int y;
    
public:
    food();

    ~food();
};

#endif