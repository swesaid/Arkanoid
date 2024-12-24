#ifndef GAMECONFIGURATIONSCLEANER_HPP
#define GAMECONFIGURATIONSCLEANER_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <GL/glew.h>

class GameConfigurationsCleaner
{
    public:
        GameConfigurationsCleaner();
        ~GameConfigurationsCleaner();
        void CleanUp(SDL_Window *window, SDL_Renderer *& renderer);
};

#endif