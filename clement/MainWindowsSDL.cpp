#include <SDL2/SDL.h>
#include "MainWindowsSDL.hpp" 
#include "snake.hpp"

int MainSDLWindow::Init(const char* windowName, int width, int height)
{
    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    this->window = SDL_CreateWindow(windowName,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_MINIMIZED);
    if(window == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
  return 0; 
}

SDL_Renderer* MainSDLWindow::GetRenderer(void){
    return this->renderer;
}

MainSDLWindow::MainSDLWindow(){
    window = NULL;
    renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();  //on quitte la SDL
}

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
        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0)
        SDL_Delay(frame_delay);
        
    } while (continuePlay);

    if (main_window != NULL)
        delete main_window;
    return 0;
}
