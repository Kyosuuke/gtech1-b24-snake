#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    SDL_Window* fenetre;  // Déclaration de la fenêtre

    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow("Une fenetre SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);  // Création de la fenêtre

    if (fenetre == NULL)  //gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Delay(3000);  //pause de 3 secondes

    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
    return 0;
}