#include <SDL2/SDL.h>
#include "snake.hpp"

Segment::Segment(int x, int y, Direct direction, Segment* next){
  this->x = x;
  this->y = y;
  this->direction = direction;
  this->next = next;
}

Segment* Segment::Getnext(){
    return this->next;
}

void Segment::Setnext(int x,int y, int prevdir){
    this->next = new Segment();
    this->next->x = x;
    this->next->y = y;
    this->next->direction = prevdir;
    
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
    printf("UP\n");
    head->SetDirection(UP);
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    printf("DOWN\n");
    head->SetDirection(DOWN);
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    printf("LEFT\n");
    head->SetDirection(LEFT);
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    printf("RIGHT\n");
    head->SetDirection(RIGHT);
  }
  
}

Segment* Snake::Gethead(){
    return head;
}

void Snake::Eat() {
  if(this->head->Getnext() != NULL){
        printf("test");
        this->head->Getnext()->Setnext(this->prev_tail_x,this->prev_tail_y,this->dir_prev);
    }
    else{
        this->head->Setnext(this->prev_tail_x,this->prev_tail_y,this->dir_prev);
    }
}




void Snake::move(){
  
  this->prev_tail_x =this->head->x;
    this->prev_tail_y =this->head->y;
    this->dir_prev = this->head->direction;
  
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
  SDL_Rect rect_to_draw = {head->GetX(), head->GetY(), 32, 32};
  SDL_SetRenderDrawColor(main_window_renderer, 0, 0, 0, 255);
  SDL_RenderClear(main_window_renderer);
  SDL_SetRenderDrawColor(main_window_renderer, 0, 0, 255, 255);
  SDL_RenderFillRect(main_window_renderer, &rect_to_draw);
  SDL_RenderPresent(main_window_renderer);
}
