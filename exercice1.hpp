#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class MainSDLWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    MainSDLWindow();
    
    ~MainSDLWindow();

    int Init(const char *windowName, int width, int height);

    SDL_Renderer* GetRenderer(void);

    int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r,  Uint8 g , Uint8 b , Uint8  a);
};
