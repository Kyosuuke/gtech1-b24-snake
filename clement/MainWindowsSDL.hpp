#ifndef MAINWINDOWSSDL_HPP
#define MAINWINDOWSSDL_HPP

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

    int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r,  Uint8 g , Uint8 b , Uint8  a);
    
    int SDL_SetRenderTarget(SDL_Renderer* renderer , SDL_Texture*  texture);

    void printImgOnRenderer(const char* file, SDL_Renderer* renderer, SDL_Rect pos, int angle = 0);

    int SDL_RenderDrawRects(SDL_Renderer* renderer, const SDL_Rect * rects, int count);
};

#endif