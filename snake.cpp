#include <SDL2/SDL.h>
#include "snake.hpp"
#include "MainWindowsSDL.hpp"
#include "fruit.hpp"

int square_size = 20;
int height = 600;
int width = 600;
int number = width/square_size;

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

Segment* Segment::Getnext(){
  return next;
}

void Segment::SetNext(Segment* next){
  this->next = next;
}

Snake::Snake(int x, int y, Direct direction, Playground* playground)
{
  this->playground = playground;
  head = new Segment(x,y,direction,NULL);
}

Segment* Snake::Gethead(){
  return head;
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

bool Snake::move(){
  
    switch (head->GetDirection())
    {
    case UP:
        head->AddToY(-1);
        if(head->GetY() <= 0){
          return false;
        }
        break;
    
    case DOWN:
        head->AddToY(1);
        if(head->GetY() >= playground->GetNumbOfRow()-1){
          return false;
        }
        break;

    case LEFT:
        head->AddToX(-1);
        if(head->GetX() <= 0){
          return false;
        }
        break;

    case RIGHT:
        head->AddToX(1);
        if(head->GetX() >= playground->GetNumbOfCol()-1){
          return false;
        }
        break;
    }

    return true;
}

void Snake::draw(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect rect_to_draw = {head->GetX()*playground->GetSquareSize(), head->GetY()*playground->GetSquareSize(), 20, 20};
    SDL_RenderFillRect(renderer, &rect_to_draw);
}

