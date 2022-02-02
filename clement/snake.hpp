#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segment.hpp"

class Snake
{
private :
    Segment* head;
    Snake* keyboard;

public :
    typedef enum {
        UP, DOWN, LEFT, RIGHT
    } Direct;   

    void keyboard(Direct* direction);

    void move(Direct directionToMove, SDL_Rect* r);
};

