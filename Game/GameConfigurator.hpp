#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

class GameConfigurator
{
    public:
        GameConfigurator();
        ~GameConfigurator();
        bool InitializeSDL(SDL_Window *window, SDL_GLContext context, int width, int height);
        bool IntializeOpenGL(int width, int height);
        
};