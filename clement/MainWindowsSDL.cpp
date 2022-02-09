#include <SDL2/SDL.h>
#include <time.h>
#include "MainWindowsSDL.hpp" 
#include "snake.hpp"

#define WINDOW_HEIGHT  600
#define WINDOW_WIDTH  600
#define SQUARE_SIZE 20

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

Apple::Apple(){
    locate();
}

void Apple::locate() 
{
    srand (time(NULL));
    this->x = rand() % WINDOW_HEIGHT;
    this->y = rand() % WINDOW_WIDTH;
}

void Apple::draw(SDL_Renderer* renderer) 
{
    SDL_Rect rect_to_draw = {this->x ,this->y , 20, 20};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect_to_draw);
    SDL_RenderPresent(renderer);
}
