#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>
#include "MainWindowsSDL.hpp" 
#include "snake.hpp"
#include "fruit.hpp"
#include "playground.hpp"

int main(void) {
    MainSDLWindow *sdlwin = new MainSDLWindow;
    int frame_rate = 100 ;
    Direct direction = UP;
    int width = 600, height = 600;
    int square_size = 20;
    SDL_Rect r = {(width-square_size)/2, (height-square_size)/2, square_size, square_size};
    SDL_Event event; 
    MainSDLWindow* main_window = new MainSDLWindow();
    main_window->Init("Snake", width, height);
    SDL_Renderer* renderer = main_window->GetRenderer();
    bool continuePlay = true;
    Playground* p = new Playground(600, 600, 20);
    Apple* a = new Apple(p);
    Snake* s = new Snake(15, 15, UP, p);

    do{

        Uint32 frame_time_start = SDL_GetTicks();
        
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                //Quit the program
                continuePlay = false;
            }    
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        a->draw(renderer);
        s->keyboard();
        continuePlay = s->move();
        s->draw(renderer);
        if (s->Gethead()->GetX() == a->GetX() && s->Gethead()->GetY() == a->GetY()){
            a->locate();
        }
        SDL_RenderPresent(renderer);

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if (frame_time_interval < frame_rate)
        {   
            SDL_Delay(frame_rate - frame_time_interval);
        }

    } while (continuePlay);

    if (main_window != NULL)
        delete main_window;
    return 0;
}
