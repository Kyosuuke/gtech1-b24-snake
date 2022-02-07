#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>
#include "MainWindowsSDL.cpp" 
#include "snake.cpp"
#include "fruit.hpp"
#include "playground.hpp"

int main(void) {
    int frame_delay;
    int frame_rate_ms = 20 ;
    Uint32 frame_start;
    Direct direction = UP;
    int width = 600, height = 600;
    int square_size = 30;
    SDL_Rect r = {(width-square_size)/2, (height-square_size)/2, square_size, square_size};
    SDL_Event event; 
    MainSDLWindow* main_window = new MainSDLWindow();
    main_window->Init("Snake", width, height);
    SDL_Renderer* main_window_renderer = main_window->GetRenderer();
    bool continuePlay = true;
    Snake* s = new Snake(width/2, height/2, UP);

    do{

        frame_start = SDL_GetTicks();
        
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                //Quit the program
                continuePlay = false;
            }    
        }

        s->keyboard();
        s->move();
        s->draw(main_window_renderer);
        s->collisions();
        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0)
        SDL_Delay(frame_delay);
        
    } while (continuePlay);

    if (main_window != NULL)
        delete main_window;
    return 0;
}
