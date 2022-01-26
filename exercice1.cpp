#include "exercice1.hpp"

int MainSDLWindow::Init(const char* windowName, int width, int height)
{
    this->window = SDL_CreateWindow(windowName,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width , height , SDL_WINDOW_RESIZABLE);
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
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();  //on quitte la SDL

    SDL_Delay(3000);//pause de 3 secondes
    
}

int main(void) {
    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
{
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    return EXIT_FAILURE;
}
    //Make sure the program waits for a quit
    MainSDLWindow* main_window = new MainSDLWindow;
    main_window->Init("Snake", 600, 600);
    SDL_Renderer* main_window_renderer = main_window->GetRenderer();
    while (true){
        SDL_SetRenderDrawColor(main_window_renderer, 0, 0, 0, 255);
        SDL_RenderClear(main_window_renderer);
        SDL_RenderDrawRect;
        SDL_Quit();
        return 0;
    } 
}