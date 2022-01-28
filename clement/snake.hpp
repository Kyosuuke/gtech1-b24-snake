#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Snake
{
private :

public :
    int SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture*  texture);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
}