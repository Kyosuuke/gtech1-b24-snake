#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL2/SDL.h>
#include <string.h>
#include "MainWindowsSDL.hpp"
#include "playground.hpp"

typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direct;   
class Segment
{
private:
    Segment* next;
    int x;
    int y;
    Direct direction;

public:
    Segment(int x, int y, Direct direction, Segment* next);

    ~Segment();

    Direct GetDirection();
    int GetX();
    int GetY();

    void SetDirection(Direct direction);
    void AddToX(int x);
    void AddToY(int y);    
};

class Snake
{
private :
    Segment* head;
    Segment* tail;
    Playground* playground;
public :
    Snake(int x, int y, Direct direction, Playground* playground);

    ~Snake();

    void keyboard();
    bool move();
    void draw(SDL_Renderer* main_window_renderer);
};

#endif