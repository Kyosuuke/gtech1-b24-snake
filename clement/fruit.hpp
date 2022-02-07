#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <cstdlib>
#include <SDL2/SDL.h>
#include "MainWindowsSDL.hpp"
#include "snake.hpp"

class fruit
{
private:
    int x;
    int y;
    int rand;
public:
    fruit(int x, int y);

    ~fruit();

    int apple(int x, int y);

    const int MAX = 600, MIN = 0;
};

#endif