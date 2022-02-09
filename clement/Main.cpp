#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>
#include "MainWindowsSDL.hpp" 
#include "snake.hpp"
#include "fruit.hpp"
#include "playground.hpp"

int main(void) {
    MainSDLWindow *sdlwin = new MainSDLWindow;
    int frame_rate = 20 ;
    Direct direction = UP;
    int width = 600, height = 600;
    int square_size = 20;
    SDL_Rect r = {(width-square_size)/2, (height-square_size)/2, square_size, square_size};
    SDL_Event event; 
    MainSDLWindow* main_window = new MainSDLWindow();
    main_window->Init("Snake", width, height);
    SDL_Renderer* renderer = main_window->GetRenderer();
    bool continuePlay = true;
    Apple* a = new Apple();
    Snake* s = new Snake(width/2, height/2, UP);

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

        a->locate();
        a->draw(renderer);
        s->keyboard();
        s->move();
        s->draw(renderer);
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
