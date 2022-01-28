#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class MainSDLWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

public:
    MainSDLWindow();
    
    ~MainSDLWindow();

    int Init(const char *windowName, int width, int height);

    SDL_Renderer* GetRenderer(void);

};
