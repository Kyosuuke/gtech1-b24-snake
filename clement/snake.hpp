#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL2/SDL.h>
#include <string.h>
#include "MainWindowsSDL.hpp"

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

    void Tail(int x, int y, Direct direction);
    void SetDirection(Direct direction);
    void AddToX(int x);
    void AddToY(int y);    
};

class Snake
{
private :
    Segment* head;
public :
    Snake(int x, int y, Direct direction);

    ~Snake();

    bool collisions();
    void keyboard();
    void move();
    void draw(SDL_Renderer* main_window_renderer);
    
    Segment* Snake::Gethead();
    void Snake::Eat();
    
};

#endif
