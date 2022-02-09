#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <cstdlib>
#include <SDL2/SDL.h>
#include "MainWindowsSDL.hpp"
#include "snake.hpp"
#include "playground.hpp"

class Apple
{
private:
    int x;
    int y;
    Playground* playground;
public:
    Apple(Playground* playground);

    ~Apple();

    void locate();
    void draw(SDL_Renderer* renderer);

    int eat();
    int GetX();
    int GetY();
};

#endif