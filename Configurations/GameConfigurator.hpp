#ifndef GAMECONFIGURATOR_HPP
#define GAMECONFIGURATOR_HPP


#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

class GameConfigurator
{
    public:
        GameConfigurator();
        ~GameConfigurator();

        bool InitializeSDL(SDL_Window *window, SDL_GLContext context, int width, int height);
        bool IntializeOpenGL(SDL_Window *window, SDL_GLContext context, int width, int height);
        bool IsConfigured(SDL_Window *window, SDL_GLContext context, int width, int height);
};

#endif