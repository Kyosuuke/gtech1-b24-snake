#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <cstdlib>
#include <SDL2/SDL.h>
#include "MainWindowsSDL.hpp"
#include "snake.hpp"

class fruit
{

public:
    
    int x;
    int y;
    fruit();

    ~fruit();
    void apple();
    void draw(SDL_Renderer*renderer);
    
};

#endif
