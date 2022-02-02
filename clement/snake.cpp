#include <SDL2/SDL.h>
#include "snake.hpp"

#define sizeHead = 20

void Snake::keyboard(Direct* direction) {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
    printf("UP\n");
    *direction = UP;
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    printf("DOWN\n");
    *direction = DOWN;
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    printf("LEFT\n");
    *direction = LEFT;
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    printf("RIGHT\n");
    *direction = RIGHT; 
  }
}


void Snake::move(Direct directionToMove, SDL_Rect* r){
    switch (directionToMove)
    {
    case UP:
        r->y -= 1;
        break;
    
    case DOWN:
        r->y += 1;
        break;

    case LEFT:
        r->x -= 1;
        break;

    case RIGHT:
        r->x += 1;
        break;
    }
}
