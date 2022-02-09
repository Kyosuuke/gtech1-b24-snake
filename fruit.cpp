#include <time.h>
#include <SDL2/SDL.h>
#include "fruit.hpp"
#include "MainWindowsSDL.hpp"
#include "snake.hpp"

#define FRUIT_SIZE 20
#define HEIGHT 600
#define WIDTH 600
#define RAND

Apple::Apple(Playground* playground){
    this->playground = playground;
    locate();
}

int Apple::GetX(){
    return x;
}

int Apple::GetY(){
    return y;
}

void Apple::locate() 
{
    srand (time(NULL));
    this->x = rand() % playground->GetNumbOfCol();
    this->y = rand() % playground->GetNumbOfRow();
}

void Apple::draw(SDL_Renderer* renderer) 
{
    SDL_Rect rect_to_draw = {this->x*playground->GetSquareSize() ,this->y*playground->GetSquareSize() , 20, 20};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect_to_draw);
}

