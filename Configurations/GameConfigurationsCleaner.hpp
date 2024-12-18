#ifndef GAMECONFIGURATIONSCLEANER_HPP
#define GAMECONFIGURATIONSCLEANER_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>

class GameConfigurationsCleaner
{
    public:
        GameConfigurationsCleaner();
        ~GameConfigurationsCleaner();
        void CleanUp(SDL_Window *window, SDL_GLContext context);
};

#endif