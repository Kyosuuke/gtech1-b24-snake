#include "exercice1.hpp"



int MainSDLWindow::Init(const char *windowName, int width, int height){
    this->window = SDL_CreateWindow(windowName,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width , height , SDL_WINDOW_RESIZABLE);
    return 0;
}

SDL_Renderer* MainSDLWindow::GetRenderer(void){
    return this->renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
    SDL_RENDERER_PRESENTVSYNC);
}

MainSDLWindow::MainSDLWindow(){
    printf("c'est bon");
}

MainSDLWindow::~MainSDLWindow(){
    
}

int main(void) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());//on affiche l'erreur
        return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
    }

    MainSDLWindow* main_window = new MainSDLWindow;
    main_window->Init("Snake", 600, 600);
    SDL_Renderer* main_window_renderer = main_window->GetRenderer();

    SDL_RenderDrawRect;

    SDL_Delay(3000);  //pause de 3 secondes

    SDL_Quit();  //on quitte la SDL
}
