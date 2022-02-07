#include <SDL2/SDL.h>
#include "snake.hpp"
#include "MainWindowsSDL.hpp"

int square_size = 30;
int height = 600;
int width = 600;

Segment::Segment(int x, int y, Direct direction, Segment* next){
  this->x = x;
  this->y = y;
  this->direction = direction;
  this->next = next;
}

void Segment::SetDirection(Direct direction){
  this->direction = direction;
}

void Segment::AddToX(int x){
  this->x += x;
}

void Segment::AddToY(int y){
  this->y += y;
}

Direct Segment::GetDirection(){
  return direction;
}

int Segment::GetX(){
  return x;
}

int Segment::GetY(){
  return y;
}

Snake::Snake(int x, int y, Direct direction)
{
  head = new Segment(x,y,direction,NULL);
}

void Snake::keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
    head->SetDirection(UP);
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    head->SetDirection(DOWN);
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    head->SetDirection(LEFT);
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    head->SetDirection(RIGHT);
  }
}

void Snake::move(){
    switch (head->GetDirection())
    {
    case UP:
        head->AddToY(-1);
        break;
    
    case DOWN:
        head->AddToY(1);
        break;

    case LEFT:
        head->AddToX(-1);
        break;

    case RIGHT:
        head->AddToX(1);
        break;
    }
}

void Snake::draw(SDL_Renderer* main_window_renderer){
  SDL_Rect rect_to_draw = {head->GetX(), head->GetY(), 30, 30};
  SDL_SetRenderDrawColor(main_window_renderer, 0, 0, 0, 255);
  SDL_RenderClear(main_window_renderer);
  SDL_SetRenderDrawColor(main_window_renderer, 0, 0, 255, 255);
  SDL_RenderFillRect(main_window_renderer, &rect_to_draw);
  SDL_RenderPresent(main_window_renderer);
}

bool Snake::collisions(){
  if (head->GetY() + square_size <= height)
    return ;
  if (head->GetY() >= square_size + height)
    return false;
  if (head->GetX() + square_size <= height)
    return false;
  if (head->GetY() >= square_size + height)
    return false;
  return true;
  }
